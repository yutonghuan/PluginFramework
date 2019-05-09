#ifndef CUIINTERFACE_H
#define CUIINTERFACE_H

#include <QString>
#include <QtPlugin>

class QWidget;
class QAction;

class CUiInterface
{
public:
    virtual ~CUiInterface(){}
    virtual QString GetPluginName() = 0; //插件名称
    virtual QString GetTitle() = 0;      //插件标题
    virtual QWidget *GetWidget() = 0;    //获取窗口
    virtual void ShowWidget() = 0;       //显示窗口
    virtual bool AddToolBarAction(QAction *action) = 0;//工具栏添加action


};

#define CUiInterface_iid "CUiInterface"
Q_DECLARE_INTERFACE(CUiInterface, CUiInterface_iid)

#endif // CUIINTERFACE_H
