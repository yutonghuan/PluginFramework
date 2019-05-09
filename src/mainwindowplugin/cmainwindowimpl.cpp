#include "cmainwindowimpl.h"


CMainWindowImpl::CMainWindowImpl(QObject *parent) :
    QObject (parent)
{
}

QString CMainWindowImpl::GetPluginName()
{
    return "mainwindowplugin";
}

QString CMainWindowImpl::GetTitle()
{
    return "MainWindow";
}

QWidget *CMainWindowImpl::GetWidget()
{
    return nullptr;
}

void CMainWindowImpl::ShowWidget()
{

}

bool CMainWindowImpl::AddToolBarAction(QAction *action)
{
    return true;
}

