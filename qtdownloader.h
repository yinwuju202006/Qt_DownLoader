#ifndef QTDOWNLOADER_H
#define QTDOWNLOADER_H

#include <QMainWindow>
#include<QThread>
#include"downmanage.h"

namespace Ui {
class QtDownLoader;
}

class QtDownLoader : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtDownLoader(QWidget *parent = 0);
    ~QtDownLoader();

private slots:
    void on_btn_download_clicked();

    void on_btn_path_clicked();

private:
    Ui::QtDownLoader *ui;
private:
    void initParamAndPath();
    void initSignal();
    bool checkParamValid();
private:
    QThread* subThread;
    DownManage* manager;

signals:
    void startDownLoad(const QString& srcUrl = "",const QString& saveDir = "",const qint16& threadCnt = 1);

};

#endif // QTDOWNLOADER_H
