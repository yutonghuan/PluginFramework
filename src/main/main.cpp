#include <QApplication>
#include <QSharedPointer>
#include <QDirIterator>
#include <QDebug>
#include <QWidget>
#include <QDir>

#include "PluginFramework/ctkPluginException.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "cservice.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 获取插件所在位置
    QString path = QApplication::applicationDirPath() + "/plugins";

    // 在插件的搜索路径列表中添加一条路径
    ctkPluginFrameworkLauncher::addSearchPath(path);

    // 设置并启动 CTK 插件框架
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");
    ctkPluginFrameworkLauncher::start("org.commontk.log");


    // 获取插件上下文
    ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginContext();

    // 启动插件
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/mainwindowplugin.dll"));
        plugin->start();
        qDebug() << "plugin start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to start plugin." << e.what();
    }

    ctkServiceReference ref = context->getServiceReference<CMainWindowService>();
    if (ref)
    {
        CMainWindowService* service = qobject_cast<CMainWindowService *>(context->getService(ref));
        if (service != Q_NULLPTR)
            service->ShowWidget();
    }


    int ret = a.exec();

    return ret;
}
