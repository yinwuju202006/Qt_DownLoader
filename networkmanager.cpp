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

void NetWorkManager::getServerInfoByHeader(const QString &downUrl)
{
    QNetworkRequest request;
    request.setUrl(QUrl(downUrl));
    reply = manager.head(request);
    connect(reply,&QNetworkReply::finished,this,&NetWorkManager::headInfoFinished);
}


