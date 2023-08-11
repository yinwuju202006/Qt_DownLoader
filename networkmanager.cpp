#include "networkmanager.h"
#include<QDebug>

NetWorkManager::NetWorkManager(QObject *parent) : QObject(parent)
{

}

void NetWorkManager::headInfoFinished()
{
    RemoteSiteInfo sitInfo;
    if(reply->hasRawHeader(QByteArray(CONTENT_LENGTH.toUtf8())))
    {
        QString strTotal(reply->rawHeader(QByteArray(CONTENT_LENGTH.toUtf8())));
        sitInfo.totalFileSize = strTotal.toULongLong();
    }

    sitInfo.isSupportResume = reply->hasRawHeader(QByteArray(ACCEPT_RANGES.toUtf8())) ? true : false;
    emit notifyServerHeadInfo(sitInfo);

}

void NetWorkManager::packDataFinished()
{
    qDebug() << "  packet finish";
}

void NetWorkManager::packDataReadyRead()
{
    qDebug() << "  packet readyRead";
//    QByteArray arrayRead = reply->readAll();
//    qDebug() << " readsize is " << arrayRead.size();
}

void NetWorkManager::packDataProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << "  packet packDataProgress";
}

void NetWorkManager::packDataError(QNetworkReply::NetworkError errCode)
{
    qDebug() << "  packet data error=====";
}

void NetWorkManager::dataDwnLoad_Start(const QString &strUrl, const DownBlockInfo &blockInfo)
{
    qDebug() << "  packet url is " << strUrl;
//    QString strRange;
//    strRange.sprintf("bytes=%d-%d",blockInfo.nStartPos + blockInfo.nDownLoadedSize,blockInfo.nStartPos + blockInfo.nBlockTotalSize);
//    qDebug() << " strRange :" << strRange;
    QNetworkRequest request;
    request.setUrl(QUrl(strUrl));
//    request.setRawHeader(QByteArray("Range"),QString("bytes=%1-%2").arg(blockInfo.nStartPos + blockInfo.nDownLoadedSize).arg(blockInfo.nStartPos + blockInfo.nBlockTotalSize).toLocal8Bit());
    request.setRawHeader(QByteArray("Range"),QString("bytes=1-").toLocal8Bit());
//    if()
    reply = manager.get(request);

    connect(reply,&QNetworkReply::finished,this,&NetWorkManager::packDataFinished);
    connect(reply,&QIODevice::readyRead,this,&NetWorkManager::packDataReadyRead);
    connect(reply,&QNetworkReply::downloadProgress,this,&NetWorkManager::packDataProgress);
//    connect(reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),this,&NetWorkManager::packDataError);
}

void NetWorkManager::getServerInfoByHeader(const QString &downUrl)
{
    QNetworkRequest request;
    request.setUrl(QUrl(downUrl));
    reply = manager.head(request);
    connect(reply,&QNetworkReply::finished,this,&NetWorkManager::headInfoFinished);
}


