 #ifndef CSERVICE_H
#define CSERVICE_H

#include <QtPlugin>

class QWidget;
class QAction;
class QMainWindow;
class QIcon;


//所有插件的接口
class CService
{
public:
    virtual ~CService(){}
};
#define CService_iid "CService"
Q_DECLARE_INTERFACE(CService, CService_iid)


//UI相关的插件接口
class CUiService : public CService
{
public:
    virtual ~CUiService(){}

    virtual QString GetText() = 0;
    virtual QIcon *GetIcon() = 0;
    virtual void ShowWidget(bool modal = false) = 0;
};
#define CUiService_iid "CUiService"
Q_DECLARE_INTERFACE(CUiService, CUiService_iid)


class CMainWindowService : public CUiService
{
public:
    virtual ~CMainWindowService(){}

    virtual QMainWindow *GetMainWindow() = 0;
};
#define CMainWindowService_iid "CMainWindowService"
Q_DECLARE_INTERFACE(CMainWindowService, CMainWindowService_iid)


class CWidgetService : public CUiService
{
public:
    virtual ~CWidgetService(){}

    virtual QWidget *GetWidget() = 0;
};
#define CWidgetService_iid "CWidgetService"
Q_DECLARE_INTERFACE(CWidgetService, CWidgetService_iid)


//IO插件相关接口
class CIoService : public CService
{
public:
    virtual ~CIoService(){}
};
#define CIoService_iid "CIoService"
Q_DECLARE_INTERFACE(CIoService, CIoService_iid)

#endif // CSERVICE_H



