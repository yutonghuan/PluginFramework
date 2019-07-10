#include "ctitletoolbar.h"

#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QLabel>
#include <QButtonGroup>
#include <QDebug>
#include <QLinearGradient>

CTitleToolBar::CTitleToolBar(ToolBarOrientation orientation, QWidget *parent)
    : QToolBar(parent), m_Orientation(orientation)
{
    m_pButtonGroup = new QButtonGroup;
    connect(m_pButtonGroup, SIGNAL(buttonClicked(int)), this, SIGNAL(SigButtonClicked(int)));

    setMovable(false);

}

void CTitleToolBar::AddToolButton(QToolButton *toolButton)
{
    toolButton->setFixedSize(77, 64);
    toolButton->setIconSize(QSize(32, 32));
    toolButton->setCheckable(true);
    toolButton->setObjectName("titleButton");
    toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    static int i  = 0;
    addWidget(toolButton);
    m_pButtonGroup->addButton(toolButton, i++);
    m_pButtonGroup->button(0)->setChecked(true);
}

void CTitleToolBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(Qt::black);
    if (m_Orientation == Vertical)
    {
        QLinearGradient gradient(0, 0, width(), 0);
        gradient.setColorAt(0, QColor(65, 65, 65, 255));
        gradient.setColorAt(1, QColor(130, 130, 130, 255));

        painter.setBrush(gradient);
        painter.drawRect(-1, -1, width(), height());
    }
    else
    {
        QLinearGradient gradient(0, 0, 0, height());
        gradient.setColorAt(0, QColor(130, 130, 130, 255));
        gradient.setColorAt(1, QColor(65, 65, 65, 255));

        painter.setBrush(gradient);
        painter.drawRect(-1, 0, width(), height()-1);
    }
}

