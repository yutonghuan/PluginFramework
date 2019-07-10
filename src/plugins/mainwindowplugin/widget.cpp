#include "widget.h"
#include "cservice.h"
#include "cstatuswidget.h"
#include "ctitletoolbar.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkPluginException.h"
#include "PluginFramework/service/event/ctkEventAdmin.h"

#include <QPushButton>
#include <QLabel>
#include <QAction>
#include <QToolBar>
#include <QDirIterator>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QStackedWidget>
#include <QMenuBar>
#include <QToolButton>
#include <QIcon>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    :QMainWindow (parent)
{
    //菜单栏
    CreateMenuBar();

    //标题栏
    CreateToolBar();

    //主窗口
    m_pStackedWidget = new QStackedWidget;
    setCentralWidget(m_pStackedWidget);

    //状态栏
    CreateStatusBar();

    //监听服务事件
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    context->connectServiceListener(this, "SlotServiceEvent", QString("(serviceType=widgetService)"));

    connect(m_pTitleToolBar, &CTitleToolBar::SigButtonClicked, m_pStackedWidget, &QStackedWidget::setCurrentIndex);

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
        m_pPlugin->uninstall();
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

void Widget::SlotServiceEvent(const ctkServiceEvent &event)
{
    //只处理服务注册事件
    if (event.getType() != ctkServiceEvent::REGISTERED)
    {
        return;
    }
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    ctkServiceReference ref = event.getServiceReference();
    if (ref)
    {
        CWidgetService *service = context->getService<CWidgetService>(ref);
        if (service)
        {
            m_pStackedWidget->addWidget(service->GetWidget());

            QToolButton *toolButton = new QToolButton;
            toolButton->setFixedSize(80, 64);
            toolButton->setIconSize(QSize(32, 32));
            toolButton->setStyleSheet("color:white;font:bold;background:transparent");


            toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            toolButton->setText(service->GetText());
            toolButton->setIcon(*service->GetIcon());

            m_pTitleToolBar->AddToolButton(toolButton);
        }

    }
}

void Widget::CreateMenuBar()
{
    QMenuBar *menuBar = new QMenuBar;
    menuBar->setStyleSheet("background:rgb(200, 200, 200)");
    setMenuBar(menuBar);

    QAction *loadAction = new QAction(tr("加载插件"), this);
    connect(loadAction, SIGNAL(triggered()), this, SLOT(SlotLoadPlugins()));

    QAction *uninstallAction = new QAction(tr("卸载插件"), this);
    connect(uninstallAction, SIGNAL(triggered()), this, SLOT(SlotUnistallPlugins()));

    QMenu *helpMenu = menuBar->addMenu(tr("&Help"));
    helpMenu->addAction(loadAction);


}

void Widget::CreateToolBar()
{
    QToolBar *toolBar = new QToolBar;
    toolBar->setStyleSheet("border-image:url(:/images/rect)");
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setFixedHeight(32);
    toolBar->setMovable(false);

    m_pTitleToolBar = new CTitleToolBar;
    m_pTitleToolBar->setFixedWidth(80);
    addToolBar(Qt::LeftToolBarArea, m_pTitleToolBar);
}


void Widget::CreateStatusBar()
{
    QStatusBar *status = statusBar();
    status->setStyleSheet("background-color:rgb(100, 100, 100);color:white");
    status->addWidget(new CStatusWidget, 1);

}

