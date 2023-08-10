#include<QCryptographicHash>
#include<QUrl>
#include<QFile>
#include<qdebug.h>
#include "filemanager.h"
#include"downloaderdatastruct.h"


FileManager::FileManager(QObject *parent) : QObject(parent)
{

}

QString FileManager::genFileName(const QString &downUrl, const QString &saveDir)
{
    QString strFullFileName("");
    if(downUrl.isEmpty())
    {
        return strFullFileName;
    }
    //Get the filename
    QUrl urlFileName(downUrl);
    QString strFileName = urlFileName.fileName();

    //md5 encode the fileUrl
    QString md5Str = QCryptographicHash::hash(downUrl.toLocal8Bit(),QCryptographicHash::Md5).toHex();
    if(md5Str.isEmpty())
    {
        return strFullFileName;
    }

    //the whole fullname
    strFullFileName = saveDir + "/" + md5Str + "_" + strFileName;
    return strFullFileName;
}

bool FileManager::fileExist(const QString &fileFullPath)
{
    QFile file(fileFullPath);
    return file.exists();
}

bool FileManager::createNullFile(const QString &strFileName, const char &threadCnt, const unsigned long long &nFileTotalDataSize)
{
    if(strFileName.isEmpty() || nFileTotalDataSize <= 0 )
    {
        return false;
    }
    //if exists  delete it
    QFile file(strFileName);
    if(file.exists())
    {
        file.remove();
    }

    qDebug() << "writelen is ";

    bool bOk = file.open(QIODevice::ReadWrite);
    if(!bOk)
    {
        return false;
    }

    qint64 writeLen = sizeof(FileTotalInfo) + sizeof(DownBlockInfo) * threadCnt;
    writeLen += nFileTotalDataSize;
    bOk = file.resize(writeLen);
    if(!bOk)
    {
        file.close();
        return false;
    }

    file.close();
    return true;
}

QString FileManager::getFlleName() const
{
    return m_strQFile.fileName();
}

void FileManager::setFileName(const QString &fileName)
{
    m_strQFile.setFileName(fileName);
}

