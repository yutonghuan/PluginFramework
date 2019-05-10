#include "cmainwindowimpl.h"
#include "widget.h"

#include <QToolBar>
#include <QDebug>

CMainWindowImpl::CMainWindowImpl(QObject *parent) :
    QObject (parent)
{
    m_pWidget = new Widget;
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
    if (service->GetServiceType() == CService::ActionService)
    {
        CActionService *actionService = static_cast<CActionService*>(service);
        QMainWindow *mainWindow = GetMainWindow();
        if (mainWindow)
        {
            QToolBar *toolBar = mainWindow->addToolBar("commonToolBar");
            toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            toolBar->addAction(actionService->GetAction());
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


