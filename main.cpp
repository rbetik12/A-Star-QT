#include "widget.h"
#include <QApplication>
#include "labyrinth.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int width = 100;
    int height = 100;
    int cellSize = 10;
    Labyrinth lab(width, height);
    if (lab.findWay()){
        lab.drawWay();
        Widget *w = new Widget(cellSize, width, height, lab.getLabyrinth());
        w->show();
    }
    else {
        a.exit();
    }
    return a.exec();
}
