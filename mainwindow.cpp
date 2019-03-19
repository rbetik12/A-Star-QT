#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    width = 0;
    height = 0;
    ui->start_x_box->setMinimum(1);
    ui->start_y_box->setMinimum(1);
    ui->goal_x_box->setMinimum(1);
    ui->goal_y_box->setMinimum(1);
    ui->width_box->setMaximum(100);
    ui->height_box->setMaximum(100);
    random = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_width_box_valueChanged(int arg1)
{
    width = arg1;
    ui->start_x_box->setMaximum(width - 2);
    ui->goal_x_box->setMaximum(width - 2);
}

void MainWindow::on_height_box_valueChanged(int arg1)
{
    height = arg1;
    ui->start_y_box->setMaximum(height - 2);
    ui->goal_y_box->setMaximum(height - 2);
}

void MainWindow::on_random_yes_pressed()
{
    random = true;

    ui->start_x_box->setEnabled(false);
    ui->start_y_box->setEnabled(false);

    ui->goal_x_box->setEnabled(false);
    ui->goal_y_box->setEnabled(false);
}

void MainWindow::on_random_no_pressed()
{
    random = false;
    ui->start_x_box->setEnabled(true);
    ui->start_y_box->setEnabled(true);
    ui->start_x_box->setMaximum(width - 2);
    ui->start_y_box->setMaximum(height - 2);
    ui->start_x_box->setMinimum(1);
    ui->start_y_box->setMinimum(1);

    ui->goal_x_box->setEnabled(true);
    ui->goal_y_box->setEnabled(true);
    ui->goal_x_box->setMaximum(width - 2);
    ui->goal_y_box->setMaximum(height - 2);
    ui->goal_x_box->setMinimum(1);
    ui->goal_y_box->setMinimum(1);
}

void MainWindow::on_start_x_box_valueChanged(int arg1)
{
    start_x = arg1;
}

void MainWindow::on_start_y_box_valueChanged(int arg1)
{
    start_y = arg1;
}

void MainWindow::on_goal_x_box_valueChanged(int arg1)
{
    goal_x = arg1;
}

void MainWindow::on_goal_y_box_valueChanged(int arg1)
{
    goal_y = arg1;
}

void MainWindow::on_show_button_clicked()
{
    if ((goal_x <= 0 || goal_y <= 0 || start_x <= 0 || start_y <= 0 || width <= 0 || height <= 0) && random == false){
        QMessageBox::warning(this, "Size error", "Are you sure that all sizes are properly initialized?");
    }
    else{
        int cellSize = 0;
        if (width * height <= 1000 * 1000 && width * height > 500 * 500)
           cellSize = 10;
        else if (width * height <= 500 * 500 && width * height > 250 * 250)
           cellSize = 10;
        else cellSize = 10;
        Labyrinth lab(width, height, random, start_x, start_y, goal_x, goal_y);
        if (lab.findWay()){
            lab.drawWay();
            Widget *w = new Widget(cellSize, width, height, lab.getLabyrinth());
            w->show();
        }
        else{
           QMessageBox::critical(this, "A* message", "A* didn't find the path");
       }
   }
}
