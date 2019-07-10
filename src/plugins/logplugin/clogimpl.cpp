#include "clogimpl.h"
#include "widget.h"

#include <QAction>
#include <QIcon>
#include <QDebug>

CLogImpl::CLogImpl(QObject *parent) :
    QObject (parent)
{
    m_pWidget = new Widget;
}

CLogImpl::~CLogImpl()
{
    if (m_pWidget != nullptr)
    {
        delete m_pWidget;
        m_pWidget = nullptr;
    }
}

QWidget *CLogImpl::GetWidget()
{
    return m_pWidget;
}

QIcon *CLogImpl::GetIcon()
{
    static QIcon icon(":/icons/log");
    return &icon;
}

QString CLogImpl::GetText()
{
    return tr("日志信息");
}

void CLogImpl::ShowWidget(bool modal)
{
    m_pWidget->show();
}




