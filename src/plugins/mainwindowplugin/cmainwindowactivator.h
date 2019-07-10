#ifndef CMAINWINDOWACTIVATOR_H
#define CMAINWINDOWACTIVATOR_H

#include "PluginFramework/ctkPluginActivator.h"

class CMainWindowImpl;

class CMainWindowActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "CMainWindowActivator")

public:
    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);

private:
    CMainWindowImpl *m_pImpl;
    ctkServiceRegistration m_Registration;
};

#endif // CMAINWINDOWACTIVATOR_H
