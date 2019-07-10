#ifndef CSTATUSWIDGET_H
#define CSTATUSWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;
class QProcess;


class CStatusWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CStatusWidget(QWidget *parent = nullptr);

signals:


private slots:
    void SlotUpdateLabel();

    void SlotReadyRead();//Linux下读取cpu和内存信息

private:
    void CreateWidget();

    void GetCpu();
    void GetMemory();
    QString GetCpuMemory();
    QString GetTime();

private:
    QLabel *m_pCpuMemoryLabel;    //雷达工作状态
    QLabel *m_pCopyRightLabel;      //版权信息
    QLabel *m_pDateLabel;           //时间信息

    int m_iCpuPercent;

    int m_iMemoryPercent;
    int m_iMemoryAll;
    int m_iMemoryUse;
    int m_iMemoryFree;

    QProcess *m_pProcess;
    int totalNew, idleNew, totalOld, idleOld;

};

#endif // CSTATUSWIDGET_H
