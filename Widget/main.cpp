#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Helper helper;
    Widget w(&helper);
    w.show();

    return a.exec();
}
