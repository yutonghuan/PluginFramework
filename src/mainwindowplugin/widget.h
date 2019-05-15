#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QSharedPointer>
#include "ctkDictionary.h"

class ctkPlugin;

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

private:
    QSharedPointer<ctkPlugin> m_pPlugin;
};

#endif // WIDGET_H
