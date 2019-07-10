#ifndef CLOGCONFIGMANAGER_H
#define CLOGCONFIGMANAGER_H

#include <QObject>

#include "PluginFramework/service/cm/ctkManagedService.h"
#include "PluginFramework/ctkServiceRegistration.h"

class CLogConfigManager : public QObject, public ctkManagedService
{
    Q_OBJECT
    Q_INTERFACES(ctkManagedService)

public:
    explicit CLogConfigManager(QObject *parent = nullptr);

    void updated(const ctkDictionary &dictionary);

private:
    ctkDictionary GetDefaults();

signals:

public slots:

private:
    ctkServiceRegistration m_Registration;
};

#endif // CLOGCONFIGMANAGER_H
