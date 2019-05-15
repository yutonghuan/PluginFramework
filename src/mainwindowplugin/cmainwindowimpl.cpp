#include "cmainwindowimpl.h"
#include "widget.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"

#include <QToolBar>
#include <QDebug>

CMainWindowImpl::CMainWindowImpl(QObject *parent) :
    QObject (parent)
{
    m_pWidget = new Widget();
}

CMainWindowImpl::~CMainWindowImpl()
{
    if (m_pWidget != nullptr)
    {
        delete m_pWidget;
        m_pWidget = nullptr;
    }
}

void CMainWindowImpl::ServiceTrackerCallBack(CService *service)
{
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    if (service->GetServiceType() == CService::ActionService)
    {
        ctkServiceReference ref = context->getServiceReference<CActionService>();
        if (ref)
        {
            CActionService *actionService = context->getService<CActionService>(ref);
            QMainWindow *mainWindow = GetMainWindow();
            if (mainWindow)
            {
                static QToolBar *toolBar = mainWindow->addToolBar("commonToolBar");
                toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
                toolBar->addAction(actionService->GetAction());
            }
        }
    }
}

CService::ServiceType CMainWindowImpl::GetServiceType()
{
    return CService::MainWindowService;
}

QMainWindow *CMainWindowImpl::GetMainWindow()
{
    return m_pWidget;
}

void CMainWindowImpl::ShowWidget()
{
    m_pWidget->show();
}


