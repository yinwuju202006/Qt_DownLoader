#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include<QFile>

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = nullptr);

signals:

public slots:
public:
    static QString genFileName(const QString& downUrl,const QString& saveDir);
    bool fileExist(const QString& fileFullPath);
    //creat a null file inclde the whole data and the base struct size
    static bool createNullFile(const QString& strFileName,const char& threadCnt,const unsigned long long & nFileTotalDataSize);
public:
    QString getFlleName() const;
    void setFileName(const QString& fileName);
private:
    QFile m_strQFile;
};

#endif // FILEMANAGER_H
