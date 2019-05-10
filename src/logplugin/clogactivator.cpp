#include "clogactivator.h"
#include "clogimpl.h"

#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QMainWindow>

void CLogActivator::start(ctkPluginContext *context)
{
    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 2);
    properties.insert("type", "action");

    m_pImpl = new CLogImpl;
    m_Registration = context->registerService<CWidgetService>(m_pImpl, properties);

//    QList<ctkServiceReference> refs = context->getServiceReferences<CMainWindowService>("(&(name=mainwindow))");
//    foreach (ctkServiceReference ref, refs)
//    {
//        if (ref)
//        {
//            CMainWindowService* service = qobject_cast<CMainWindowService *>(context->getService(ref));
//            if (service != Q_NULLPTR)
//            {
//                QMainWindow *mainWindow = service->GetMainWindow();
//                if (mainWindow)
//                {
//                    QToolBar *toolBar = mainWindow->addToolBar("commonToolBar");
//                    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
//                    toolBar->addAction(m_pImpl->GetAction());
//                }
//            }

//        }
//    }
}

void CLogActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)

    //注销服务
    m_Registration.unregister();

    delete m_pImpl;
    m_pImpl = nullptr;
}
