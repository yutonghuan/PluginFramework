#include "ctitletoolbar.h"

#include <QPainter>
#include <QVBoxLayout>
#include <QToolButton>
#include <QLabel>
#include <QButtonGroup>

CTitleToolBar::CTitleToolBar(QWidget *parent) : QToolBar(parent)
{
    QWidget *widget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    m_pToolButtonLayout = new QVBoxLayout;
    m_pToolButtonLayout->setContentsMargins(0, 0, 0, 0);
    m_pToolButtonLayout->setSpacing(0);

    mainLayout->addLayout(m_pToolButtonLayout);
    mainLayout->addStretch();

    widget->setLayout(mainLayout);

    addWidget(widget);

    m_pButtonGroup = new QButtonGroup;
    connect(m_pButtonGroup, SIGNAL(buttonClicked(int)), this, SIGNAL(SigButtonClicked(int)));

}

void CTitleToolBar::AddToolButton(QToolButton *toolButton)
{
    static int i  = 0;
    m_pToolButtonLayout->addWidget(toolButton);
    m_pButtonGroup->addButton(toolButton, i++);
}

void CTitleToolBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/images/verticalTitle"));
}

