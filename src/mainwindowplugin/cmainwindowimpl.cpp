#include "cmainwindowimpl.h"
#include "widget.h"

#include <QToolBar>

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

QMainWindow *CMainWindowImpl::GetMainWindow()
{
    return m_pWidget;
}

void CMainWindowImpl::ShowWidget()
{
    m_pWidget->show();
}


