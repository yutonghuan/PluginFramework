#include "cmainwindowactivator.h"
#include "cmainwindowimpl.h"
#include "cservicetracker.h"
#include "PluginFramework/service/event/ctkEventAdmin.h"


void CMainWindowActivator::start(ctkPluginContext *context)
{
    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 1);
    properties.insert("name", "mainwindow");


    m_pImpl = new CMainWindowImpl;
    m_Registration = context->registerService<CMainWindowService>(m_pImpl, properties);

    //开启服务跟踪器
    m_pTracker = new CServiceTracker(context, m_pImpl);
    m_pTracker->open();
}

void CMainWindowActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    m_Registration.unregister();

    //关闭服务跟踪器
    m_pTracker->close();
}
