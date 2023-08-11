#include "MainWindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(800,640);
    w.setWindowTitle("Телефонный справочник");
    w.setWindowIcon(QIcon(":/icons/icons/phone.svg"));
    w.show();
    return a.exec();
}
