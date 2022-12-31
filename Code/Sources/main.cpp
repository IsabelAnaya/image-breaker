#include "../Headers/MainWindow.h"
#include "../Headers/Messages.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    //setup window
    QApplication a(argc, argv);
    Messages m;
    MainWindow w(m);
    w.show();

    //return window
    return a.exec();
}
