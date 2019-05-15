#include "clogimpl.h"
#include "widget.h"

#include <QAction>
#include <QIcon>
#include <QDebug>

CLogImpl::CLogImpl(QObject *parent) :
    QObject (parent)
{
    m_pWidget = new Widget;

    m_pAction = new QAction(QIcon(":/icons/log"), tr("日志信息"), this);
    connect(m_pAction, &QAction::triggered, [=](){this->ShowWidget();});
}

CLogImpl::~CLogImpl()
{
    if (m_pWidget != nullptr)
    {
        delete m_pWidget;
        m_pWidget = nullptr;
    }

    if (m_pAction != nullptr)
    {
        delete m_pAction;
        m_pAction = nullptr;
    }
}

void CLogImpl::ServiceTrackerCallBack(CService *service)
{
    Q_UNUSED(service);
}

CService::ServiceType CLogImpl::GetServiceType()
{
    return CService::ActionService;
}

QAction *CLogImpl::GetAction()
{
    return m_pAction;
}

QWidget *CLogImpl::GetWidget()
{
    return m_pWidget;
}

void CLogImpl::ShowWidget()
{
    m_pWidget->show();
}



