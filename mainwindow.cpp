#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<math.h>

QImage img(501, 501, QImage::Format_RGB888);

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


void MainWindow::on_pushButton_2_clicked()
{
    int x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    dda(x1, y1, x2, y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float dx, dy, step, xinc, yinc;
    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx)>=abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    xinc = dx/step;
    yinc = dy/step;

    int i, x, y;
    x = x1;
    y = y1;
    for(i=0; i<step; i++){
        img.setPixel(x, y, qRgb(255,255,255));
        x = x + xinc;
        y = y + yinc;
    }
}


void MainWindow::on_pushButton_clicked()
{
    int x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    bresenham(x1, y1, x2, y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::bresenham(int x1, int y1, int x2, int y2)
{
    QRgb value;
    value = qRgb(255,255,255);
    int dx, dy, x, y, p, i=0;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;
    if(dx >= dy){
        p = 2*dy - dx;
        while(i < dx){
            img.setPixel(x, y, value);
            if(p<0){
                p = p + 2*dy;
            }
            else{
                p = p + 2*(dy - dx);
                y = y + sign(y2 - y1);
            }
            x = x + sign(x2 - x1);
            i++;
        }
    }
    else{
        p = 2*dx - dy;
        while(i < dy){
            img.setPixel(x, y, value);
            if(p<0){
                p = p + 2*dx;
            }
            else{
                p = p + 2*(dx - dy);
                x = x + sign(x2 - x1);
            }
            y = y + sign(y2 - y1);
            i++;
        }
    }
}

int MainWindow::sign(int n)
{
    if(n > 0){
        return 1;
    }
    else if(n < 0){
        return -1;
    }
    else return 0;
}


void MainWindow::on_pushButton_4_clicked()
{
    int centx, centy, r;
    centx = ui->textEdit_5->toPlainText().toInt();
    centy = ui->textEdit_6->toPlainText().toInt();
    r = ui->textEdit_7->toPlainText().toInt();
    bresenhamcircle(centx, centy, r);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::bresenhamcircle(int centx, int centy, int r)
{
    int x, y, p;
    p = 3 - 2*r;

    x = 0;
    y = r;
    while(x<y){
        img.setPixel(centx + x, centy + y, qRgb(255,255,255));
        img.setPixel(centx + x, centy - y, qRgb(255,255,255));
        img.setPixel(centx - x, centy + y, qRgb(255,255,255));
        img.setPixel(centx - x, centy - y, qRgb(255,255,255));
        img.setPixel(centx + y, centy + x, qRgb(255,255,255));
        img.setPixel(centx + y, centy - x, qRgb(255,255,255));
        img.setPixel(centx - y, centy + x, qRgb(255,255,255));
        img.setPixel(centx - y, centy - x, qRgb(255,255,255));
        if(p<0) p = p + 4*x + 6;
        else{
            p = p + 4*(x-y) + 10;
            y = y - 1;
        }
        x = x + 1;
    }
}

