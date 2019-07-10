#include "cmainwindowactivator.h"
#include "cmainwindowimpl.h"
#include "PluginFramework/service/event/ctkEventAdmin.h"


void CMainWindowActivator::start(ctkPluginContext *context)
{
    m_pImpl = new CMainWindowImpl;
    m_Registration = context->registerService<CMainWindowService>(m_pImpl);
}

void CMainWindowActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    m_Registration.unregister();
}
