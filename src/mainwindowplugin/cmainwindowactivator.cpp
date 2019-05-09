#include "cmainwindowactivator.h"
#include "cmainwindowimpl.h"

void CMainWindowActivator::start(ctkPluginContext *context)
{
    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 1);
    properties.insert("name", "mainwindowplugin");

    m_pImpl = new CMainWindowImpl;
    context->registerService<CUiInterface>(m_pImpl, properties);
}

void CMainWindowActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    delete m_pImpl;
}
