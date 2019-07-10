
#include <QApplication>
#include <QSharedPointer>
#include <QDirIterator>
#include <QDebug>
#include <QWidget>
#include <QDir>
#include <QFile>
#include <QTranslator>

#include "PluginFramework/service/cm/ctkConfigurationAdmin.h"

#include "PluginFramework/ctkPluginException.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //加载样式表
    QFile fileQss(":/qss/style.qss");
    fileQss.open(QFile::ReadOnly);
    qApp->setStyleSheet(fileQss.readAll());
    fileQss.close();

    //翻译文件
    QTranslator qtTranslator;
    qtTranslator.load(":/qm/main.qm");
    a.installTranslator(&qtTranslator);

    //获取插件所在位置
    QString path = QApplication::applicationDirPath() + "/plugins";

    //在插件的搜索路径列表中添加一条路径
    ctkPluginFrameworkLauncher::addSearchPath(path+"/service");

    //启动事件服务，用于插件之间的通信
    bool loadEventAdmmin = ctkPluginFrameworkLauncher::start("org.commontk.eventadmin", ctkPlugin::START_TRANSIENT);
    //启动配置服务，管理配置信息
    bool loadConfigAdmin = ctkPluginFrameworkLauncher::start("org.commontk.configadmin", ctkPlugin::START_TRANSIENT);
    if (!loadEventAdmmin && !loadConfigAdmin)
    {
        ctkPluginFrameworkLauncher::start();
    }

    Widget widget;

    //获取插件上下文
    ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginContext();

    //遍历路径下的所有插件
    QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
    while (itPlugin.hasNext())
    {
        QString strPlugin = itPlugin.next();
        try
        {
            //安装插件
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
            //启动插件
            plugin->start(ctkPlugin::START_TRANSIENT);
        } catch (const ctkPluginException &e)
        {
            qDebug() << e.what();
            return -1;
        }
    }

    widget.show();
    int ret = a.exec();
    return ret;
}
