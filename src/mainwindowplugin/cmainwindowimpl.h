#ifndef CMAINWINDOWIMPL_H
#define CMAINWINDOWIMPL_H

#include <QObject>
#include "cservice.h"

class Widget;


class CMainWindowImpl : public QObject, public CMainWindowService
{
    Q_OBJECT
    Q_INTERFACES(CMainWindowService)

public:
    CMainWindowImpl(QObject *parent = nullptr);
    ~CMainWindowImpl() Q_DECL_OVERRIDE;

    void ServiceTrackerCallBack(CService *service) Q_DECL_OVERRIDE;
    ServiceType GetServiceType() Q_DECL_OVERRIDE;
    QMainWindow *GetMainWindow() Q_DECL_OVERRIDE;
    void ShowWidget() Q_DECL_OVERRIDE;

private:
    Widget *m_pWidget;
};

#endif // CMAINWINDOWIMPL_H
