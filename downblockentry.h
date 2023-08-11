#ifndef DOWNBLOCKENTRY_H
#define DOWNBLOCKENTRY_H

#include <QObject>
#include<QFile>
#include<QRunnable>
#include"networkmanager.h"
#include"downloaderdatastruct.h"

class DownBlockEntry : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit DownBlockEntry(QObject *parent = nullptr);
    ~DownBlockEntry();
public:
    void run() override;

signals:
    void notify_DownLoad_Start(const QString& strUrl,const DownBlockInfo& blockInfo);
public slots:
private:
    NetWorkManager* m_netWork;
public:
    DownBlockInfo m_blockInfo;
    QFile m_fileOper;
    QString m_strDownUrl;
};

#endif // DOWNBLOCKENTRY_H
