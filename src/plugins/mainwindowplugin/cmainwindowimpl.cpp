#include "cmainwindowimpl.h"
#include "widget.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"

#include <QToolBar>
#include <QDebug>
#include <QAction>

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

QMainWindow *CMainWindowImpl::GetMainWindow()
{
    return m_pWidget;
}

void CMainWindowImpl::ShowWidget(bool modal)
{
    if (modal) m_pWidget->setWindowModality(Qt::WindowModal);
    m_pWidget->showMaximized();
}

QIcon *CMainWindowImpl::GetIcon()
{
    return nullptr;
}

QString CMainWindowImpl::GetText()
{
    return tr("");
}



