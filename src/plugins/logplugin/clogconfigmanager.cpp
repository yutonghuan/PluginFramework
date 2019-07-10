#include "clogconfigmanager.h"

#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/service/cm/ctkConfigurationAdmin.h"

#include <QDebug>

CLogConfigManager::CLogConfigManager(QObject *parent) : QObject(parent)
{
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
//    m_Registration = context->registerService<ctkManagedService>(this, GetDefaults());

//    ctkServiceReference ref = context->getServiceReference<ctkConfigurationAdmin>();
//    if (ref)
//    {
//        ctkConfigurationAdmin *configAdmin = context->getService<ctkConfigurationAdmin>(ref);
//        ctkConfigurationPtr config = configAdmin->getConfiguration("logplugin");

//        config->remove();

//    }
}

void CLogConfigManager::updated(const ctkDictionary &dictionary)
{
    if (dictionary.isEmpty())
    {
//        qDebug()<<__FUNCTION__<<"empty";
//        ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
//        ctkServiceReference ref = context->getServiceReference<ctkConfigurationAdmin>();
//        if (ref)
//        {
//            ctkConfigurationAdmin *configAdmin = context->getService<ctkConfigurationAdmin>(ref);
//            ctkConfigurationPtr config = configAdmin->getConfiguration("logplugin");

//            if (config->getProperties().isEmpty())
//            {
//                config->update(GetDefaults());
//            }
//        }
    }
    else
    {
        qDebug()<<__FUNCTION__<<dictionary["name"];
    }
}

ctkDictionary CLogConfigManager::GetDefaults()
{
    ctkDictionary defaults;
    defaults.insert("name", "yutonghuan hello");
    defaults.insert(ctkPluginConstants::SERVICE_PID, "logplugin");

    return defaults;
}

