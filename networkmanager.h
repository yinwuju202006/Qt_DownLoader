#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include<QNetworkAccessManager>
#include"downloaderdatastruct.h"
#include<QNetworkReply>

const QString CONTENT_LENGTH = "Content-Length";
const QString ACCEPT_RANGES = "Accept-Ranges";

class NetWorkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkManager(QObject *parent = nullptr);

signals:
    void notifyServerHeadInfo(const RemoteSiteInfo& sitInfo);
public slots:
    void getServerInfoByHeader(const QString& downUrl);
    void headInfoFinished();
    void packDataFinished();
    void packDataReadyRead();
    void packDataProgress(qint64 bytesReceived, qint64 bytesTotal);
    void packDataError(QNetworkReply::NetworkError errCode);
    void dataDwnLoad_Start(const QString& strUrl,const DownBlockInfo& blockInfo);

private:
    QNetworkAccessManager manager;
    QNetworkReply* reply;
public:

};

#endif // NETWORKMANAGER_H
