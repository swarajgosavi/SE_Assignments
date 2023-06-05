#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <vector>
#include "vector.h"
#include <bits/stdc++.h>

using namespace std;

QImage img(500, 500, QImage::Format_RGB888);

QRgb white = qRgb(255, 255, 255);

vector<Vertex> vertics;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
    setupdrawingarea();
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

        x = -x + 250;
        y = -y + 250;

        if(event->button() == Qt::RightButton){
            drawlineDDA(vertics[ver - 1].x,
                    vertics[ver -1].y,
                    vertics[0].x,
                    vertics[0].y,
                    -1, 250);
            start = false;
        }
        else{
            vertics.push_back(Vertex(x, y));
            if(ver > 0){
                drawlineDDA(vertics[ver-1].x,
                        vertics[ver-1].y,
                        x, y, -1, 250);
            }
            ver++;
        }
    }
}

void MainWindow::drawlineDDA(int x1, int y1, int x2, int y2, int a, int b)
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
        img.setPixel((x*a)+b, (y*a)+b, white);
        x += x_inc;
        y += y_inc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::setupdrawingarea()
{
    img.fill( QColor::fromRgb( 0 , 0 , 0 ) ) ;
    drawlineDDA(250, 0, 250, 500, 1, 0);
    drawlineDDA(0, 250, 500, 250, 1, 0);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::drawpoly()
{
    for(int i=0; i<ver-1; i++){
        drawlineDDA(vertics[i].x,
                    vertics[i].y,
                    vertics[i+1].x,
                vertics[i+1].y,
                -1, 250);
    }
    drawlineDDA(vertics[ver-1].x,
                vertics[ver-1].y,
                vertics[0].x,
            vertics[0].y,
            -1, 250);

}




void MainWindow::on_pushButton_clicked()
{
    float tx = ui->textEdit->toPlainText().toFloat();
    float ty = ui->textEdit_2->toPlainText().toFloat();

    Vertex t = Vertex(-tx, ty);
    for(int i=0; i<ver; i++){
        vertics[i] = vertics[i] + t;
    }
    setupdrawingarea();
    drawpoly();
}


void MainWindow::on_pushButton_2_clicked()
{
    float sx = ui->textEdit_3->toPlainText().toFloat();
    float sy = ui->textEdit_4->toPlainText().toFloat();

    Matrix scale = Matrix();
    scale.set(0, 0, sx);
    scale.set(0, 1, 0.0);
    scale.set(1, 0, 0.0);
    scale.set(1, 1, sy);

    for(int i=0; i<ver; i++){
        vertics[i] = vertics[i] * scale;
    }
    setupdrawingarea();
    drawpoly();
}


void MainWindow::on_pushButton_3_clicked()
{
    float theta = ui->textEdit_5->toPlainText().toFloat();
    float angle = (-theta * M_PI) / 180.0;

    Matrix rotate = Matrix();

    rotate.set(0, 0, cos(angle));
    rotate.set(0, 1, sin(angle));
    rotate.set(1, 0, -sin(angle));
    rotate.set(1, 1, cos(angle));

    for(int i=0; i<ver; i++){
        vertics[i] = vertics[i] * rotate;
    }
    setupdrawingarea();
    drawpoly();
}

