#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include<QTime>

QImage img(500, 500, QImage::Format_RGB888);

QRgb white = qRgb(255, 255, 255);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start){
        int x = event->pos().x();
        int y = event->pos().y();
        a[ver] = x;
        b[ver] = y;

        if(event->button() == Qt::RightButton){
            drawlineDDA(a[0], b[0], a[ver-1], b[ver-1]);
            start = false;
        }
        else{
            if(ver > 0)
                drawlineDDA(a[ver], b[ver], a[ver-1], b[ver-1]);
            }
        ui->label->setPixmap(QPixmap::fromImage(img));
        ver++;
    }
}

void MainWindow::drawlineDDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) >= abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    float x_inc = dx / step;
    float y_inc = dy / step;

    float x = x1, y = y1;
    for(int i=0; i<step; i++){
        img.setPixel(x, y, white);
        x += x_inc;
        y += y_inc;
    }
}

void MainWindow::scanline()
{
    int y, ymax = 0, ymin = 500;
    float dx, dy, m[20], x[20];


    a[ver] = a[0];
    b[ver] = b[0];

    for(int i=0; i<ver; i++){
        if(ymin >= b[i]){
            ymin = b[i];
        }
        if(ymax <= b[i]){
            ymax = b[i];
        }

        dx = a[i+1] - a[i];
        dy = b[i+1] - b[i];
        if(dx == 0){
            m[i] = 0;
        }
        if(dy == 1){
            m[i] = 1;
        }
        if(dx != 0 || dy != 0){
            m[i] = dx/dy;
        }
    }

    for(y = ymax; y>ymin; y--){
        int c = 0;
        for(int i = 0; i<ver; i++){
            if((b[i]>y && b[i+1]<=y) || (b[i]<=y && b[i+1]>y)){
                x[c] = a[i] + (y - b[i]) * m[i];
                c++;
            }
        }
        for(int i=0; i<c-1; i++){
            for(int j=0; j<c-i-1; j++){
                if(x[j] > x[j+1]){
                    float t = x[j];
                    x[j] = x[j+1];
                    x[j+1] = t;
                }
            }
        }
        for(int i=0; i<c; i+=2){
            drawlineDDA(x[i], y, x[i+1], y);
            ui->label->setPixmap(QPixmap::fromImage(img));
            delay();
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    scanline();
}

void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(50);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
}

void MainWindow::on_pushButton_2_clicked()
{
    img = QImage(500, 500, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    start = true;
    ver = 0;
}

