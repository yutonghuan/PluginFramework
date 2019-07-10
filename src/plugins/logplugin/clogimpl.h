#ifndef CLOGIMPL_H
#define CLOGIMPL_H

#include <QObject>
#include <QMetaEnum>

#include "cservice.h"

class Widget;

class CLogImpl : public QObject, public CWidgetService
{
    Q_OBJECT
    Q_INTERFACES(CWidgetService)

public:
    CLogImpl(QObject *parent = nullptr);
    ~CLogImpl();

    QWidget *GetWidget() Q_DECL_OVERRIDE;
    QIcon *GetIcon() Q_DECL_OVERRIDE;
    QString GetText() Q_DECL_OVERRIDE;
    void ShowWidget(bool modal) Q_DECL_OVERRIDE;

private:
    Widget *m_pWidget;

};


#endif // CLOGIMPL_H
