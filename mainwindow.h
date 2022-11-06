#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
    void dda(int, int, int, int);

    void on_pushButton_clicked();
    void bresenham(int, int, int, int);
    int sign(int);

    void on_pushButton_4_clicked();
    void bresenhamcircle(int, int, int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
