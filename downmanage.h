#ifndef DOWNMANAGE_H
#define DOWNMANAGE_H

#include <QObject>
#include"networkmanager.h"
#include"downloaderdatastruct.h"
#include"downblockentry.h"
class DownManage : public QObject
{
    Q_OBJECT
public:
    explicit DownManage(QObject *parent = nullptr);
    ~DownManage();  
signals:
    void notify_getHeadInfo(const QString& url);
public slots:
    void downloadWork(const QString& srcUrl = "",const QString& saveDir = "",const qint16& threadCnt = 1);
    void receiveRemoteSiteInfo(const RemoteSiteInfo& sitInfo);
private:
    NetWorkManager* netWork;
private:
    bool m_bSupportResume;
    unsigned long long m_fileTotalSize;
private:
    char m_nThreadCnt;
    QString m_strUrl;
    QString m_strSaveDir;
    QString m_strFileName;
    DownBlockEntry* m_blockEntryPtr;
};

#endif // DOWNMANAGE_H
