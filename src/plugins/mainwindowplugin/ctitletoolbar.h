#ifndef CTITLETOOLBAR_H
#define CTITLETOOLBAR_H

#include <QToolBar>
#include <QPaintEvent>

class QToolButton;
class QVBoxLayout;
class QButtonGroup;

class CTitleToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit CTitleToolBar(QWidget *parent = nullptr);

    void AddToolButton(QToolButton *toolButton);

protected:
    void paintEvent(QPaintEvent *event);

signals:
    void SigButtonClicked(int id);


public slots:

private:
    QVBoxLayout *m_pToolButtonLayout;

    QButtonGroup *m_pButtonGroup;
};

#endif // CTITLETOOLBAR_H
