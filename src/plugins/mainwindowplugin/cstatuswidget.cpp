#include "cstatuswidget.h"

#include <QMessageBox>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include <QProcess>

#ifdef Q_OS_WIN
#include "windows.h"
#endif

#define MB (1024 * 1024)
#define KB (1024)

CStatusWidget::CStatusWidget(QWidget *parent)
    : QWidget(parent)
{
    CreateWidget();

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(SlotUpdateLabel()));
    timer->start(1000);

    //用于linux下获取cpu和内存信息
    QProcess *m_pProcess = new QProcess;
    connect(m_pProcess, &QProcess::readyRead, this, &CStatusWidget::SlotReadyRead);
}

void CStatusWidget::SlotUpdateLabel()
{
    m_pDateLabel->setText(GetTime());
    m_pCpuMemoryLabel->setText(GetCpuMemory());
}

void CStatusWidget::SlotReadyRead()
{
    while (!m_pProcess->atEnd()) {
        QString s = QLatin1String(m_pProcess->readLine());
        if (s.startsWith("cpu")) {
            QStringList list = s.split(" ");
            idleNew = list.at(5).toInt();
            foreach (QString value, list) {
                totalNew += value.toInt();
            }

            int total = totalNew - totalOld;
            int idle = idleNew - idleOld;
            m_iCpuPercent = 100 * (total - idle) / total;
            totalOld = totalNew;
            idleOld = idleNew;
            break;
        } else if (s.startsWith("MemTotal")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_iMemoryAll = s.left(s.length() - 3).toInt() / KB;
        } else if (s.startsWith("MemFree")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_iMemoryFree = s.left(s.length() - 3).toInt() / KB;
        } else if (s.startsWith("Buffers")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_iMemoryFree += s.left(s.length() - 3).toInt() / KB;
        } else if (s.startsWith("Cached")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_iMemoryFree += s.left(s.length() - 3).toInt() / KB;
            m_iMemoryUse = m_iMemoryAll - m_iMemoryFree;
            m_iMemoryPercent = 100 * m_iMemoryUse / m_iMemoryAll;
            break;
        }
    }
}

void CStatusWidget::CreateWidget()
{
    m_pCpuMemoryLabel = new QLabel(GetCpuMemory());
    m_pCpuMemoryLabel->setFixedWidth(500);

    //时间信息
    m_pDateLabel = new QLabel(GetTime());
    m_pDateLabel->setFixedWidth(600);
    m_pDateLabel->setAlignment(Qt::AlignRight);

    //总布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_pCpuMemoryLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(m_pDateLabel);
    mainLayout->setContentsMargins(15, 2, 2, 2);
    setLayout(mainLayout);

}

void CStatusWidget::GetCpu()
{
#ifdef Q_OS_WIN
#if (QT_VERSION >= QT_VERSION_CHECK(4,8,7))

    static FILETIME preidleTime;
    static FILETIME prekernelTime;
    static FILETIME preuserTime;

    FILETIME idleTime;
    FILETIME kernelTime;
    FILETIME userTime;

    GetSystemTimes(&idleTime, &kernelTime, &userTime);

    quint64 a, b;
    int idle, kernel, user;

    a = (preidleTime.dwHighDateTime << 31) | preidleTime.dwLowDateTime;
    b = (idleTime.dwHighDateTime << 31) | idleTime.dwLowDateTime;
    idle = int(b -a);

    a = (prekernelTime.dwHighDateTime << 31) | prekernelTime.dwLowDateTime;
    b = (kernelTime.dwHighDateTime << 31) | kernelTime.dwLowDateTime;
    kernel = int(b -a);

    a = (preuserTime.dwHighDateTime << 31) | preuserTime.dwLowDateTime;
    b = (userTime.dwHighDateTime << 31) | userTime.dwLowDateTime;
    user = int(b -a);

    m_iCpuPercent = (kernel + user - idle) * 100 / (kernel + user);

    preidleTime = idleTime;
    prekernelTime = kernelTime;
    preuserTime = userTime ;

#endif
#else
    if (m_pProcess->state() == QProcess::NotRunning) {
        totalNew = idleNew = 0;
        process->start("cat /proc/stat");
    }
#endif
}

void CStatusWidget::GetMemory()
{
#ifdef Q_OS_WIN
#if (QT_VERSION >= QT_VERSION_CHECK(4,8,7))
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx(&statex);
    m_iMemoryPercent = int(statex.dwMemoryLoad);
    m_iMemoryAll = int(statex.ullTotalPhys / MB);
    m_iMemoryFree = int(statex.ullAvailPhys / MB);
    m_iMemoryUse = m_iMemoryAll - m_iMemoryFree;

#endif
#else
    if (m_pProcess->state() == QProcess::NotRunning) {
        m_pProcess->start("cat /proc/meminfo");
    }
#endif
}

QString CStatusWidget::GetCpuMemory()
{
    GetCpu();
    GetMemory();

    QString msg = tr("CPU : %1%  Memory : %2% ( used %3 MB / total %4 MB )").
                  arg(m_iCpuPercent).arg(m_iMemoryPercent).arg(m_iMemoryUse).arg(m_iMemoryAll);
    return msg;
}

QString CStatusWidget::GetTime()
{
    static int day = 0;
    static int hour = 0;
    static int minute = 0;
    static int seconds = 0;
    seconds++;
    if (seconds == 60) {
        minute++;
        seconds = 0;
    }
    if (minute == 60) {
        hour++;
        minute = 0;
    }
    if (hour == 24) {
        day++;
        hour = 0;
    }

    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString runTime = tr("Run time: %1d %2h %3m %4s  |  Current time: ").arg(day).arg(hour).arg(minute).arg(seconds);

    return runTime + currentTime;
}
