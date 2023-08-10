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
};

struct DownBlockInfo
{
    DownBlockInfo()
    {
        nStartPos = 0;
        nBlockTotalSize = 0;
        nDownLoadedSize = 0;

    }
    unsigned long long nStartPos;
    unsigned long long nBlockTotalSize;
    unsigned long long nDownLoadedSize;
};

#endif // DOWNLOADERDATASTRUCT_H
