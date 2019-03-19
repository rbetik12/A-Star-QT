#include "widget.h"
#include "ui_widget.h"

Widget::Widget(int cellSize, int width, int height, node** map, QWidget *parent) :
    QWidget(parent)
{
    this->cellSize = cellSize;
    this->width = width;
    this->height = height;
    this->map = map;
    this->setGeometry(0, 0, 1000, 1000);
}


void Widget::saveImage()
{
    QPixmap pixmap(this->size());

    this->render(&pixmap);

    qDebug() << pixmap.save(QDir::currentPath() + "\\lab.png");
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor dirtyRoadColor = qRgb(255, 0, 255);

    for (int y = 0; y < height*cellSize; y+=cellSize){
        for (int x = 0; x < width*cellSize; x+=cellSize){
            if (map[x/cellSize][y/cellSize].typeOfCell == 0){

                painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
                painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 1){

                painter.setBrush(QBrush(Qt::darkYellow, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 2){

               painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
                painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 3){

                painter.setBrush(QBrush(Qt::cyan, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 4){
                painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 7){

                painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 8){

                painter.setBrush(QBrush(dirtyRoadColor, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
        }

    }

}

