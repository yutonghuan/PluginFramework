#include "widget.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkPluginException.h"
#include "PluginFramework/service/event/ctkEventAdmin.h"

#include <QAction>
#include <QToolBar>
#include <QDirIterator>
#include <QApplication>
#include <QDebug>
#include <QDir>

Widget::Widget(QWidget *parent)
    :QMainWindow (parent)
{
    QAction *loadAction = new QAction(tr("加载插件"), this);
    connect(loadAction, SIGNAL(triggered()), this, SLOT(SlotLoadPlugins()));

    QAction *uninstallAction = new QAction(tr("卸载插件"), this);
    connect(uninstallAction, SIGNAL(triggered()), this, SLOT(SlotUnistallPlugins()));

    QToolBar *toolBar =  addToolBar("toolBar");
    toolBar->addAction(loadAction);
    toolBar->addAction(uninstallAction);

    setFixedSize(600, 400);

    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    ctkServiceReference ref = context->getServiceReference<ctkEventAdmin>();
    if (ref)
    {
        ctkEventAdmin *eventAdmin = context->getService<ctkEventAdmin>(ref);
        eventAdmin->publishSignal(this, SIGNAL(SigSendData(ctkDictionary)), "hello", Qt::DirectConnection);

    }

}

void Widget::SlotLoadPlugins()
{
    QString path = QDir::currentPath() + "/plugins";
    try
    {
        // 安装插件
        m_pPlugin = ctkPluginFrameworkLauncher::getPluginContext()->installPlugin(QUrl::fromLocalFile(path + "/logplugin.dll"));
        // 启动插件
        m_pPlugin->start(ctkPlugin::START_TRANSIENT);
    }
    catch (const ctkPluginException &e)
    {
        qDebug() << "Failed to start plugin" << e.what();
    }
}
void Widget::SlotUnistallPlugins()
{
    QString path = QDir::currentPath();
    try
    {
//        m_pPlugin->stop();
//        m_pPlugin->uninstall();
//        m_pPlugin = m_pPluginContext->installPlugin(QUrl::fromLocalFile(path + "/logplugin.dll"));
//        m_pPlugin->start(ctkPlugin::START_TRANSIENT);

//        qDebug()<<m_pPlugin->getState();

    }
    catch (const ctkPluginException &e)
    {
        qDebug()<<"Failed to uninstall plugin"<<e.what();
    }

    ctkDictionary dictionary;
    dictionary["name"]="yutonghuan";

    emit SigSendData(dictionary);
}

