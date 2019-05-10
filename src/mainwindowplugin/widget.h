#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

class Widget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // WIDGET_H
