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

    void mousePressEvent(QMouseEvent *event);
    void drawlineDDA(int, int, int, int, QRgb);

private slots:
    void on_pushButton_clicked();
    int code(int, int);
    void cohen(int, int, int, int);

private:
    Ui::MainWindow *ui;
    int ver, a[50], b[50];
    bool start;
};
#endif // MAINWINDOW_H
