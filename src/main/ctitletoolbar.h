#ifndef CTITLETOOLBAR_H
#define CTITLETOOLBAR_H

#include <QToolBar>
#include <QPaintEvent>

class QToolButton;
class QBoxLayout;
class QButtonGroup;

class CTitleToolBar : public QToolBar
{
    Q_OBJECT
public:
    enum ToolBarOrientation{Vertical, Horizontal};

    CTitleToolBar(ToolBarOrientation orientation = Vertical, QWidget *parent = nullptr);

    void AddToolButton(QToolButton *toolButton);

protected:
    void paintEvent(QPaintEvent *event);

signals:
    void SigButtonClicked(int id);


public slots:

private:
    QBoxLayout *m_pToolButtonLayout;

    QButtonGroup *m_pButtonGroup;

    ToolBarOrientation m_Orientation;
};

#endif // CTITLETOOLBAR_H
