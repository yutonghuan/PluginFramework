#include "cmainwindowactivator.h"
#include "cmainwindowimpl.h"

#include <QDebug>


void CMainWindowActivator::start(ctkPluginContext *context)
{
    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 1);
    properties.insert("name", "mainwindow");

    m_pImpl = new CMainWindowImpl;
    context->registerService<CMainWindowService>(m_pImpl, properties);
}

void CMainWindowActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    delete m_pImpl;
}
