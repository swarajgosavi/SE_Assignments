#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>

QImage img(500, 500, QImage::Format_RGB888);

QRgb white = qRgb(255, 255, 255);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
    drawlineDDA(50, 50, 50, 350, white);
    drawlineDDA(50, 50, 350, 50, white);
    drawlineDDA(50, 350, 350, 350, white);
    drawlineDDA(350, 50, 350, 350, white);
}

const int Left=1, Right=2, Bottom=4, Top=8, Inside=0;
const int xmin=50, xmax=350, ymin=50, ymax=350;

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
            drawlineDDA(a[0], b[0], a[ver-1], b[ver-1], white);
            ui->label->setPixmap(QPixmap::fromImage(img));
            start = false;
        }
        else{
            if(ver%2 != 0){
                drawlineDDA(a[ver], b[ver], a[ver-1], b[ver-1], white);
            }
        }
        ui->label->setPixmap(QPixmap::fromImage(img));
        ver++;
    }
}

void MainWindow::drawlineDDA(int x1, int y1, int x2, int y2,QRgb val)
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

    float x = x1;
    float y = y1;
    for(int i=0; i<step; i++){
        img.setPixel(x, y, val);
        x += x_inc;
        y += y_inc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_clicked()
{
    for(int i=1; i<ver; i+=2){
        cohen(a[i], b[i], a[i-1], b[i-1]);
    }
//    cohen(a[ver-1], b[ver-1], a[0], b[0]);
}

int MainWindow::code(int x, int y)
{
    int c = Inside;
    if(x < xmin){
        c = c | Left;
    }
    else if(x > xmax){
        c = c | Right;
    }

    if(y < ymin){
        c = c | Bottom;
    }
    else if(y > ymax){
        c = c | Top;
    }

    return c;
}

void MainWindow::cohen(int x1, int y1, int x2, int y2)
{
    int code1 = code(x1, y1);
    int code2 = code(x2, y2);
    int a=x1, b=y1, c=x2, d=y2;
    bool accept = false;

    while(true){
        if(code1 == 0 && code2 == 0){
            accept = true;
            break;
        }
        else if(code1 & code2){
            QRgb old=qRgb(0,0,0);
            drawlineDDA(a, b, c, d, old);
            break;
        }
        else{
            int codeout;
            if(code1 != 0){
                codeout = code1;
            }
            else{
                codeout = code2;
            }
            float x, y;
            if(codeout & Top){
                y = ymax;
                x = x1 + float((x2-x1)*(ymax-y1)/(y2-y1));
            }
            else if(codeout & Bottom){
                y = ymin;
                x = x1 + float((x2-x1)*(ymin-y1)/(y2-y1));
            }
            else if(codeout & Left){
                x = xmin;
                y = y1 + float((xmin-x1)*(y2-y1)/(x2-x1));
            }
            else if(codeout & Right){
                x = xmax;
                y = y1 + float((xmax-x1)*(y2-y1)/(x2-x1));
            }
            if(codeout==code1)
            {
                x1=x;
                y1=y;
                code1=code(x1,y1);
            }
            else
            {
                x2=x;
                y2=y;
                code2=code(x2,y2);
            }
        }
    }
    if(accept)
        {
            QRgb old=qRgb(0,0,0);
            drawlineDDA(a,b,c,d,old);
            QRgb ne=qRgb(255,255,255);
            drawlineDDA(x1,y1,x2,y2,ne);
        }
}
