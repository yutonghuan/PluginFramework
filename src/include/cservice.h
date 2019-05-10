#ifndef CSERVICE_H
#define CSERVICE_H

#include <QtPlugin>

class QWidget;
class QAction;
class QMainWindow;


//所有插件的接口
class CService
{
public:
    enum ServiceType
    {
        ActionService,
        MainWindowService,
        WidgetService,
    };
    virtual ~CService(){}

    //用于服务追踪的回调函数
    virtual void ServiceTrackerCallBack(CService *service) = 0;

    //获取服务类型
    virtual ServiceType GetServiceType() = 0;
};
#define CService_iid "CService"
Q_DECLARE_INTERFACE(CService, CService_iid)


//UI相关的插件接口
class CUiService : public CService
{
public:
    virtual ~CUiService(){}

};
#define CUiService_iid "CService"
Q_DECLARE_INTERFACE(CUiService, CUiService_iid)


class CActionService : public CUiService
{
public:
    virtual ~CActionService(){}

    virtual QAction *GetAction() = 0;
};
#define CActionService_iid "CService"
Q_DECLARE_INTERFACE(CActionService, CActionService_iid)


class CMainWindowService : public CUiService
{
public:
    virtual ~CMainWindowService(){}

    virtual QMainWindow *GetMainWindow() = 0;
    virtual void ShowWidget() = 0;
};
#define CMainWindowService_iid "CService"
Q_DECLARE_INTERFACE(CMainWindowService, CMainWindowService_iid)


class CWidgetService : public CUiService
{
public:
    virtual ~CWidgetService(){}

    virtual QWidget *GetWidget() = 0;
    virtual void ShowWidget() = 0;
};
#define CWidgetService_iid "CService"
Q_DECLARE_INTERFACE(CWidgetService, CWidgetService_iid)


//IO插件相关接口
class CIoService : public CService
{
public:
    virtual ~CIoService(){}
};
#define CIoService_iid "CService"
Q_DECLARE_INTERFACE(CIoService, CIoService_iid)

#endif // CSERVICE_H



