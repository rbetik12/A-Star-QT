#include "widget.h"
#include <QApplication>
#include "labyrinth.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *window = new MainWindow();
    window->show();
    return a.exec();
}
