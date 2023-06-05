#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    float dx = x2 - x1;
    float dy = y2 - y1;
    float step;
    if(abs(dx) > abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    float x_inc = dx / step;
    float y_inc = dy / step;

    int x = x1;
    int y = y1;
    for(int i=0; i<step; i++){
        img.setPixel(x, y, white);
        x += x_inc;
        y += y_inc;
    }
}

void MainWindow::drawlineBresenham(int x1, int y1, int x2, int y2)
{
    int dx, dy, p, x, y, i=0;

    dx = abs(x2- x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;

    if(dx >= dy){
        p = 2*dy - dx;
        while(i < dx){
            img.setPixel(x, y, white);
            if(p < 0){
                p += 2*dy;
            }
            else{
                p +=2* (dy - dx);
                y += sign(y2 - y1);
            }
            x += sign(x2 - x1);
            i++;
        }
    }
    else{
        p = 2*dx - dy;
        while(i < dy){
            img.setPixel(x, y, white);
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

int MainWindow::sign(int x)
{
    if(x > 0) return 1;
    else if(x < 0) return -1;
    else return 0;
}

void MainWindow::drawcircle(int xc, int yc, int radius)
{
    int x = 0, y = radius;

    int p = 3 - 2*radius;

    while(x < y){
        img.setPixel(xc+x, yc+y, white);
        img.setPixel(xc+x, yc-y, white);
        img.setPixel(xc-x, yc+y, white);
        img.setPixel(xc-x, yc-y, white);
        img.setPixel(yc+y, xc+x, white);
        img.setPixel(yc+y, xc-x, white);
        img.setPixel(yc-y, xc+x, white);
        img.setPixel(yc-y, xc-x, white);
        if(p < 0){
            p += 4*x + 6;
        }
        else{
            p += 4*(x - y) + 10;
            y -= 1;
        }
        x += 1;
    }
}


void MainWindow::on_pushButton_clicked()
{
    int x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();

    drawlineDDA(x1, y1, x2, y2);

    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    int x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();

    drawlineBresenham(x1, y1, x2, y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_3_clicked()
{
    int x, y, r;
    x = ui->textEdit_5->toPlainText().toInt();
    y = ui->textEdit_6->toPlainText().toInt();
    r = ui->textEdit_7->toPlainText().toInt();

    drawcircle(x, y, r);
    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_4_clicked()
{
    img = QImage(500, 500, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

