#include "qtdownloader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDownLoader w;
    w.show();

    return a.exec();
}
