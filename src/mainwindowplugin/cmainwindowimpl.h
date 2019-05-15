#ifndef CMAINWINDOWIMPL_H
#define CMAINWINDOWIMPL_H

#include <QObject>
#include "cservice.h"

class Widget;
class ctkPluginContext;


class CMainWindowImpl : public QObject, public CMainWindowService
{
    Q_OBJECT
    Q_INTERFACES(CMainWindowService)

public:
    CMainWindowImpl(QObject *parent = nullptr);
    ~CMainWindowImpl();

    void ServiceTrackerCallBack(CService *service);
    ServiceType GetServiceType();
    QMainWindow *GetMainWindow();
    void ShowWidget();

private:
    Widget *m_pWidget;
};

#endif // CMAINWINDOWIMPL_H
