#include "clogactivator.h"
#include "clogimpl.h"
#include "clogconfigmanager.h"
#include "PluginFramework/ctkPluginConstants.h"

#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QMainWindow>

void CLogActivator::start(ctkPluginContext *context)
{
    m_pImpl = new CLogImpl;

    ctkDictionary properties;
    properties.insert("serviceType", "widgetService");
    m_Registration = context->registerService<CWidgetService>(m_pImpl, properties);

    CLogConfigManager *configManager = new CLogConfigManager;

}

void CLogActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    //注销服务
    m_Registration.unregister();

    delete m_pImpl;
    m_pImpl = nullptr;
}
