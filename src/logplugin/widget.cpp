#include "widget.h"
#include "PluginFramework/ctkPluginFrameworkLauncher.h"
#include "PluginFramework/ctkPluginContext.h"
#include "PluginFramework/service/event/ctkEventAdmin.h"
#include "PluginFramework/service/event/ctkEventConstants.h"

#include "Widgets/ctkSearchBox.h"
#include "Widgets/ctkColorPickerButton.h"
#include "Widgets/ctkExpandableWidget.h"
#include "Widgets/ctkErrorLogWidget.h"
#include "Widgets/ctkLanguageComboBox.h"
#include "Widgets/ctkPopupWidget.h"
#include "Widgets/ctkCollapsibleGroupBox.h"

#include <QDebug>
#include <QPainter>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC] = "hello";

    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    ctkServiceReference ref = context->getServiceReference<ctkEventAdmin>();
    if (ref)
    {
        qDebug()<<"eventadmin";
        ctkEventAdmin *eventAdmin = context->getService<ctkEventAdmin>(ref);
        eventAdmin->subscribeSlot(this, SLOT(SlotRecvData(ctkEvent)), props, Qt::DirectConnection);

    }

    QVBoxLayout *mainLayout = new QVBoxLayout;

    ctkSearchBox *searchBox = new ctkSearchBox;
    searchBox->setShowSearchIcon(true);
    ctkColorPickerButton *colorPickerBtn = new ctkColorPickerButton;
    colorPickerBtn->setDialogOptions(ctkColorPickerButton::UseCTKColorDialog);
    ctkExpandableWidget *expandableWidget = new ctkExpandableWidget;
    ctkErrorLogWidget *errorLogWidget = new ctkErrorLogWidget;
    ctkLanguageComboBox *languageComboBox = new ctkLanguageComboBox;
    ctkPopupWidget *popupWidget = new ctkPopupWidget(languageComboBox);
    ctkCollapsibleGroupBox *groupBox = new ctkCollapsibleGroupBox;


    mainLayout->addWidget(colorPickerBtn);
    mainLayout->addWidget(searchBox);
    mainLayout->addWidget(languageComboBox);
    mainLayout->addWidget(groupBox);
    //    mainLayout->addWidget(expandableWidget);
//    mainLayout->addWidget(errorLogWidget);
//    mainLayout->addWidget(popupWidget);
    setLayout(mainLayout);
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void Widget::SlotRecvData(const ctkEvent &event)
{
    qDebug()<<event.getProperty("name").toString();


}
