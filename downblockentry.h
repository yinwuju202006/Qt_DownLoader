#ifndef DOWNBLOCKENTRY_H
#define DOWNBLOCKENTRY_H

#include <QObject>
#include<QFile>
#include"networkmanager.h"
#include"downloaderdatastruct.h"

class DownBlockEntry : public QObject
{
    Q_OBJECT
public:
    explicit DownBlockEntry(QObject *parent = nullptr);

signals:

public slots:
private:
    NetWorkManager m_netWork;
public:
    DownBlockInfo m_blockInfo;
    QFile m_fileOper;
};

#endif // DOWNBLOCKENTRY_H
