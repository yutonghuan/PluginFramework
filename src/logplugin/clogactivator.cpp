#include "clogactivator.h"
#include "clogimpl.h"

#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QMainWindow>

void CLogActivator::start(ctkPluginContext *context)
{
    m_pImpl = new CLogImpl;
    m_WidetRegistration = context->registerService<CWidgetService>(m_pImpl);
    m_ActionRegistration = context->registerService<CActionService>(m_pImpl);

}

void CLogActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    //注销服务
    m_WidetRegistration.unregister();
    m_ActionRegistration.unregister();

    delete m_pImpl;
    m_pImpl = nullptr;
}
