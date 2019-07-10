#include "ccentralwidget.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "PluginFramework/ctkPluginContext.h"
#include "cservice.h"

#include <QStackedWidget>
#include <QToolBar>
#include <QAction>
#include <QIcon>

CCentralWidget::CCentralWidget(QWidget *parent) : QMainWindow(parent)
{
    m_pStackedWidget = new QStackedWidget;
    setCentralWidget(m_pStackedWidget);

    CreateToolBar();

    //监听服务事件
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    context->connectServiceListener(this, "SlotServiceEvent", QString("(serviceType=widgetService)"));
}

void CCentralWidget::AddWidget(QWidget *widget)
{
    m_pStackedWidget->addWidget(widget);
}

void CCentralWidget::SlotSetCurrentIndex(int index)
{
    m_pStackedWidget->setCurrentIndex(index);
}

void CCentralWidget::SlotServiceEvent(const ctkServiceEvent &event)
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
            QAction *action = new QAction(m_pToolBar);
            action->setIcon(*service->GetIcon());
            action->setText(service->GetText());


            m_pToolBar->addAction(action);
        }
    }
    m_pToolBar->setVisible(true);
}

void CCentralWidget::CreateToolBar()
{
    m_pToolBar = new CTitleToolBar(CTitleToolBar::Horizontal);
    m_pToolBar->setMovable(false);
    m_pToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_pToolBar->setIconSize(QSize(24, 24));
    m_pToolBar->setFixedHeight(32);
    m_pToolBar->setStyleSheet("color:white");
    addToolBar(Qt::TopToolBarArea, m_pToolBar);
}

