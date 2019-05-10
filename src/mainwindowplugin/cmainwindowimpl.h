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
    CMainWindowImpl(QObject *parent = 0);
    ~CMainWindowImpl();

    QMainWindow *GetMainWindow();
    void ShowWidget();

private:
    Widget *m_pWidget;
};

#endif // CMAINWINDOWIMPL_H
