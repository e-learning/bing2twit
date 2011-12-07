#include "yatotwit.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YaToTwit w;
    w.show();
    return a.exec();
}
