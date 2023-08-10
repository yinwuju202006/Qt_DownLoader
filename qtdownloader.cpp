#include<QDir>
#include<QUrl>
#include<QFileDialog>
#include<QMessageBox>
#include<QThread>
#include<QDebug>
#include "qtdownloader.h"
#include "ui_qtdownloader.h"

QtDownLoader::QtDownLoader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtDownLoader)
{
    ui->setupUi(this);
    initParamAndPath();
    initSignal();
}

QtDownLoader::~QtDownLoader()
{
    subThread->quit();
    subThread->wait();
    subThread->deleteLater();

    manager->deleteLater();
    delete ui;
}

void QtDownLoader::on_btn_download_clicked()
{
    if(!checkParamValid())
    {
        QMessageBox::information(this,"提示","参数异常，请检查");
        return;
    }
    //传递参数，开始线程
    QString strUrl = ui->ledit_url->text().trimmed();
    QString strPath = ui->ledit_path->text().trimmed();
    int nThreadCnt = ui->spinBox->value();
    emit startDownLoad(strUrl,strPath,nThreadCnt);
}

void QtDownLoader::on_btn_path_clicked()
{
    QString strPathSelect = QFileDialog::getExistingDirectory(this,"选择保存路径");
    if(strPathSelect.isEmpty())
    {
        return;
    }

    ui->ledit_path->setText(strPathSelect);
}

void QtDownLoader::initParamAndPath()
{
    QString strTempPath = QDir::tempPath();
    ui->ledit_path->setText(strTempPath);
}

void QtDownLoader::initSignal()
{
    manager = new DownManage();
    subThread = new QThread();

    manager->moveToThread(subThread);
    subThread->start();

    connect(this,&QtDownLoader::startDownLoad,manager,&DownManage::downloadWork);
}

bool QtDownLoader::checkParamValid()
{
    QString strUrl = ui->ledit_url->text().trimmed();
    if(strUrl.isEmpty())
    {
        return false;
    }

    QUrl url = QUrl::fromUserInput(strUrl);
    if(!url.isValid())
    {
        return false;
    }
    //路径检测
    QString strPath = ui->ledit_path->text().trimmed();
    if(strPath.isEmpty())
    {
        return false;
    }

    QDir dir(strPath);
    if(!dir.exists())
    {
        return false;
    }

    return true;
}

