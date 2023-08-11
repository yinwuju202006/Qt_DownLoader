#ifndef DOWNLOADERDATASTRUCT_H
#define DOWNLOADERDATASTRUCT_H
#include<iostream>
struct RemoteSiteInfo
{
    RemoteSiteInfo()
    {
        totalFileSize = 0;
        isSupportResume = false;
    }
    unsigned long long totalFileSize;
    bool isSupportResume;

};

struct FileTotalInfo
{
    FileTotalInfo()
    {
        nFileTotalSize = 0;
        nThreadCnt = 1;
    }
    unsigned long long nFileTotalSize;
    unsigned char nThreadCnt;

    FileTotalInfo& operator=(const FileTotalInfo& info)
    {
        if(this == &info)
        {
            return *this;
        }
        this->nFileTotalSize = info.nFileTotalSize;
        this->nThreadCnt = info.nThreadCnt;
        return *this;
    }
};

struct DownBlockInfo
{
    DownBlockInfo()
    {
        nStartPos = 0;
        nBlockTotalSize = 0;
        nDownLoadedSize = 0;
    }

   DownBlockInfo& operator= (const DownBlockInfo& info)
   {
       if(this == & info)
       {
           return *this;
       }
       this->nBlockTotalSize = info.nBlockTotalSize;
       this->nStartPos = info.nStartPos;
       this->nDownLoadedSize = info.nDownLoadedSize;
       return *this;
   }
    unsigned long long nStartPos;
    unsigned long long nBlockTotalSize;
    unsigned long long nDownLoadedSize;
};

#endif // DOWNLOADERDATASTRUCT_H
