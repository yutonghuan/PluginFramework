#ifndef CLOGACTIVATOR_H
#define CLOGACTIVATOR_H

#include "PluginFramework/ctkPluginActivator.h"

class CLogImpl;

class CLogActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "CLogActivator")

public:
    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);

private:
    CLogImpl *m_pImpl;
    ctkServiceRegistration m_ActionRegistration;
    ctkServiceRegistration m_WidetRegistration;
};

#endif // CLOGACTIVATOR_H
