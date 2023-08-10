#include<QDebug>
#include<QThread>
#include "downmanage.h"
#include"networkmanager.h"
#include"filemanager.h"

DownManage::DownManage(QObject *parent) : QObject(parent)
{
    m_bSupportResume = false;
    m_fileTotalSize = 0;
    m_nThreadCnt = 1;
    netWork = nullptr;
}

DownManage::~DownManage()
{
    if(netWork != nullptr)
    {
        delete netWork;
        netWork = nullptr;
    }
}

void DownManage::downloadWork(const QString &srcUrl, const QString &saveDir, const qint16 &threadCnt)
{
    m_nThreadCnt = threadCnt;
    m_strUrl = srcUrl;
    m_strSaveDir = saveDir;

    if(netWork !=  nullptr)
    {
        delete netWork;
        netWork = nullptr;
    }

    netWork = new NetWorkManager();
    connect(this,&DownManage::notify_getHeadInfo,netWork,&NetWorkManager::getServerInfoByHeader);
    connect(netWork,&NetWorkManager::notifyServerHeadInfo,this,&DownManage::receiveRemoteSiteInfo);

    emit notify_getHeadInfo(srcUrl);
}

void DownManage::receiveRemoteSiteInfo(const RemoteSiteInfo &sitInfo)
{
    //获取文件大小和是否支持断点续传
    m_bSupportResume = sitInfo.isSupportResume;
    m_fileTotalSize = sitInfo.totalFileSize;
    if(!m_bSupportResume)
    {
        m_nThreadCnt = 1;
    }

    // operate file
    //construct the file name
    QString strFullFileName = FileManager::genFileName(m_strUrl,m_strSaveDir);

    //create the null file
    bool bOk = FileManager::createNullFile(strFullFileName,m_nThreadCnt,m_fileTotalSize);
   if(!bOk)
   {
       return;
   }
   m_blockEntryPtr = new DownBlockEntry[m_nThreadCnt];
   // assign the download task
    for(int nIndex = 0;nIndex < m_nThreadCnt;nIndex++)
    {

    }

}
