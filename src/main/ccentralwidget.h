#ifndef CCENTRALWIDGET_H
#define CCENTRALWIDGET_H

#include <QMainWindow>

#include "ctitletoolbar.h"
#include "PluginFramework/ctkServiceEvent.h"

class QStackedWidget;

class CCentralWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit CCentralWidget(QWidget *parent = 0);

    void AddWidget(QWidget *widget);

signals:

public slots:
    void SlotSetCurrentIndex(int index);

    void SlotServiceEvent(const ctkServiceEvent &event);

private:
    void CreateToolBar();

private:
    QStackedWidget *m_pStackedWidget;

    CTitleToolBar *m_pToolBar;
};

#endif // CCENTRALWIDGET_H
