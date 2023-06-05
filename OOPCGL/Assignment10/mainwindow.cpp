#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <math.h>
#include <QTime>

QImage img(500, 500, QImage::Format_RGB888);

QRgb white = qRgb(255, 255, 255);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawlineDDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, step;
    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx) >= abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    float x_inc = dx/step;
    float y_inc = dy/step;

    float x=x1, y=y1;
    for(int i=0; i<step; i++){
        img.setPixel(x, y, white);
        x += x_inc;
        y += y_inc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::koch(int x1, int y1, int x2, int y2, int it)
{
    float angle = (60 * M_PI) / 180;
    int x3 = ((2 * x1) + x2) / 3;
    int y3 = ((2 * y1) + y2) / 3;
    int x4 = ((2 * x2) + x1) / 3;
    int y4 = ((2 * y2) + y1) / 3;

    int x = x3 + ((x4 - x3) * cos(angle)) + ((y4 - y3) * sin(angle));
    int y = y3 - ((x4 - x3) * sin(angle)) + ((y4 - y3) * cos(angle));

    if(it > 0){
        koch(x1, y1, x3, y3, it-1);
        koch(x3, y3, x, y, it-1);
        koch(x, y, x4, y4, it-1);
        koch(x4, y4, x2, y2, it-1);
    }
    else{
        drawlineDDA(x1, y1, x3, y3);
        drawlineDDA(x3, y3, x, y);
        drawlineDDA(x, y, x4, y4);
        drawlineDDA(x4, y4, x2, y2);
    }
    delay();
}

void MainWindow::delay(){
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton_clicked()
{
    koch(200, 266, 100, 100, 3);
    koch(100, 100, 300, 100, 3);
    koch(300, 100, 200, 266, 3);
}

