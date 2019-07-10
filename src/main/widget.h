#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QSharedPointer>
#include "PluginFramework/ctkServiceEvent.h"
#include "ctkDictionary.h"

class ctkPlugin;
class QToolBar;
class QVBoxLayout;
class CCentralWidget;
class CTitleToolBar;

class Widget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:
    void SigSendData(const ctkDictionary &);

public slots:
    void SlotLoadPlugins();
    void SlotUnistallPlugins();

    void SlotServiceEvent(const ctkServiceEvent &event);


private:
    void CreateMenuBar();
    void CreateToolBar();
    void CreateStatusBar();

private:
    QSharedPointer<ctkPlugin> m_pPlugin;


    CCentralWidget *m_pCentralWidget;

    CTitleToolBar *m_pTitleToolBar;
};

#endif // WIDGET_H
