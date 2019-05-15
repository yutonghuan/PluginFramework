#ifndef CLOGIMPL_H
#define CLOGIMPL_H

#include <QObject>
#include "cservice.h"

class Widget;
class QAction;

class CLogImpl : public QObject, public CActionService, public CWidgetService
{
    Q_OBJECT
    Q_INTERFACES(CActionService)
    Q_INTERFACES(CWidgetService)

public:
    CLogImpl(QObject *parent = nullptr);
    ~CLogImpl();

    void ServiceTrackerCallBack(CService *service);
    ServiceType GetServiceType();
    QAction *GetAction();
    QWidget *GetWidget();
    void ShowWidget();

private:
    Widget *m_pWidget;

    QAction *m_pAction;
};

#endif // CLOGIMPL_H
