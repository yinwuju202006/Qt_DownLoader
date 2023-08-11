#include "downblockentry.h"
#include<QThread>
#include<QDebug>

DownBlockEntry::DownBlockEntry(QObject *parent) : QObject(parent)
{
    setAutoDelete(true);
    m_netWork = nullptr;
}

DownBlockEntry::~DownBlockEntry()
{
    if(m_netWork != nullptr)
    {
        delete m_netWork;
        m_netWork = nullptr;
    }
}

void DownBlockEntry::run()
{
    if(m_netWork != nullptr)
    {
        delete m_netWork;
        m_netWork = nullptr;
    }

    m_netWork = new NetWorkManager();
    connect(this,&DownBlockEntry::notify_DownLoad_Start,m_netWork,&NetWorkManager::dataDwnLoad_Start);
    emit notify_DownLoad_Start(m_strDownUrl,m_blockInfo);

}
