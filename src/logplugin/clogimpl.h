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
    ~CLogImpl() Q_DECL_OVERRIDE;

    void ServiceTrackerCallBack(CService *service) Q_DECL_OVERRIDE;
    ServiceType GetServiceType() Q_DECL_OVERRIDE;
    QAction *GetAction() Q_DECL_OVERRIDE;
    QWidget *GetWidget() Q_DECL_OVERRIDE;
    void ShowWidget() Q_DECL_OVERRIDE;

private:
    Widget *m_pWidget;

    QAction *m_pAction;
};

#endif // CLOGIMPL_H
