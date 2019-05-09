#ifndef CMAINWINDOWIMPL_H
#define CMAINWINDOWIMPL_H

#include <QObject>
#include "cuiinterface.h"


class CMainWindowImpl : public QObject, public CUiInterface
{
    Q_OBJECT
    Q_INTERFACES(CUiInterface)

public:
    CMainWindowImpl(QObject *parent = 0);

    QString GetPluginName();
    QString GetTitle();
    QWidget *GetWidget();
    void ShowWidget();
    bool AddToolBarAction(QAction *action);
};

#endif // CMAINWINDOWIMPL_H
