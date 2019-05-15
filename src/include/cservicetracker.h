#ifndef CSERVICETRACKER_H
#define CSERVICETRACKER_H

#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/ctkServiceTracker.h"
#include "cservice.h"

#include <QDebug>

class CServiceTracker : public ctkServiceTracker<CService*>
{
public:
    CServiceTracker(ctkPluginContext *context, CService *service = nullptr)
        : ctkServiceTracker<CService*>(context), m_pListenService(service) {}
    ~CServiceTracker() Q_DECL_OVERRIDE {}

protected:
    //服务注册时自动调用
    CService *addingService(const ctkServiceReference &reference) Q_DECL_OVERRIDE
    {
        CService *service = ctkServiceTracker::addingService(reference);
        if (m_pListenService)
        {
            m_pListenService->ServiceTrackerCallBack(service);
        }
        return service;
    }

    void modifiedService(const ctkServiceReference &reference, CService *service) Q_DECL_OVERRIDE
    {
        ctkServiceTracker::modifiedService(reference, service);
        qDebug()<<"plugin updated...";
    }

    void removedService(const ctkServiceReference& reference, CService *service) Q_DECL_OVERRIDE
    {
        ctkServiceTracker::removedService(reference, service);
        qDebug()<<"plugin removed...";
    }

private:
    CService *m_pListenService;//监听服务

};

#endif // CSERVICETRACKER_H
