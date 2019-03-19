#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <labyrinth.h>
#include <widget.h>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool clicked;

private slots:
    void on_width_box_valueChanged(int arg1);

    void on_height_box_valueChanged(int arg1);

    void on_random_yes_pressed();

    void on_random_no_pressed();

    void on_start_x_box_valueChanged(int arg1);

    void on_start_y_box_valueChanged(int arg1);

    void on_goal_x_box_valueChanged(int arg1);

    void on_goal_y_box_valueChanged(int arg1);

    void on_show_button_clicked();

private:
    Ui::MainWindow *ui;
    int width;
    int height;
    bool random;
    int start_x;
    int start_y;
    int goal_x;
    int goal_y;
};

#endif // MAINWINDOW_H
