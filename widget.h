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
    explicit Widget(int cellSize, int width, int height, node** maps, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    node** map;
private:
    int cellSize;
    int width;
    int height;

};

#endif // WIDGET_H
