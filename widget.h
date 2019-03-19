#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QDir>
#include "labyrinth.h"
#include "util.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(int cellSize, int width, int height, node** map, QWidget *parent = nullptr);
    void saveImage();
    void paintEvent(QPaintEvent *event);
private:
    int cellSize;
    int width;
    int height;
    node** map;
};

#endif // WIDGET_H
