#ifndef CMAINWINDOWIMPL_H
#define CMAINWINDOWIMPL_H

#include <QObject>
#include "cservice.h"
#include "PluginFramework/ctkServiceEvent.h"

class Widget;
class ctkPluginContext;


class CMainWindowImpl : public QObject, public CMainWindowService
{
    Q_OBJECT
    Q_INTERFACES(CMainWindowService)

public:
    CMainWindowImpl(QObject *parent = nullptr);
    ~CMainWindowImpl();

    void ShowWidget(bool modal = false) Q_DECL_OVERRIDE;
    QIcon *GetIcon() Q_DECL_OVERRIDE;
    QString GetText() Q_DECL_OVERRIDE;
    QMainWindow *GetMainWindow() Q_DECL_OVERRIDE;

public slots:

private:
    Widget *m_pWidget;
};

#endif // CMAINWINDOWIMPL_H
