#include <QCoreApplication>
#include <QSharedPointer>
#include <QDebug>

#include "PluginFramework/ctkPluginFramework.h"
#include "PluginFramework/ctkPluginFrameworkFactory.h"
#include "PluginFramework/ctkPluginException.h"
#include "PluginFramework/ctkPluginContext.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ctkPluginFrameworkFactory frameworkFactory;
    QSharedPointer<ctkPluginFramework> framework = frameworkFactory.getFramework();

    try
    {
        //初始化并启动插件框架
        framework->init();
        framework->start();
        qDebug()<<"Plugin Framework start...";
    }
    catch (const ctkPluginException &e)
    {
        qDebug()<<"Failed to initialize the plugin framework:"<<e.what();
        return -1;
    }

    //获取插件上下文
    ctkPluginContext *context = framework->getPluginContext();

    return a.exec();
}
