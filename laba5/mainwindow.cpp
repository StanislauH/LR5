#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <cmath>
#include <algorithm>
#include <QDebug>
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

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter qp;
    qp.begin(this);
    QPen pen(Qt::black, 6, Qt::SolidLine);
    qp.drawLine(50, 400, 750, 400);
    qp.drawLine(400, 50, 400,750);
    qp.drawLine(400, 50, 395,55);
    qp.drawLine(400, 50, 405,55);
    qp.drawLine(750, 400, 745,395);
    qp.drawLine(750, 400, 745,405);

    qp.drawLine(75, 400, 75,394);
    qp.drawLine(100, 400, 100,394);
    qp.drawLine(125, 400, 125,394);
    qp.drawLine(150, 400, 150,394);
    qp.drawLine(175, 400, 175,394);
    qp.drawLine(200, 400, 200,394);
    qp.drawLine(225, 400, 225,394);
    qp.drawLine(250, 400, 250,394);
    qp.drawLine(275, 400, 275,394);
    qp.drawLine(300, 400, 300,394);
    qp.drawLine(325, 400, 325,394);
    qp.drawLine(350, 400, 350,394);
    qp.drawLine(375, 400, 375,394);
    qp.drawLine(400, 400, 400,394);
    qp.drawLine(425, 400, 425,394);
    qp.drawLine(450, 400, 450,394);
    qp.drawLine(475, 400, 475,394);
    qp.drawLine(500, 400, 500,394);
    qp.drawLine(525, 400, 525,394);
    qp.drawLine(550, 400, 550,394);
    qp.drawLine(575, 400, 575,394);
    qp.drawLine(600, 400, 600,394);
    qp.drawLine(625, 400, 625,394);
    qp.drawLine(650, 400, 650,394);
    qp.drawLine(675, 400, 675,394);
    qp.drawLine(700, 400, 700,394);
    qp.drawLine(725, 400, 725,394);
    qp.drawLine(400, 75, 405,75);
    qp.drawLine(400, 100, 405,100);
    qp.drawLine(400, 125, 405,125);
    qp.drawLine(400, 150, 405,150);
    qp.drawLine(400, 175, 405,175);
    qp.drawLine(400, 200, 405,200);
    qp.drawLine(400, 225, 405,225);
    qp.drawLine(400, 250, 405,250);
    qp.drawLine(400, 275, 405,275);
    qp.drawLine(400, 300, 405,300);
    qp.drawLine(400, 325, 405,325);
    qp.drawLine(400, 350, 405,350);
    qp.drawLine(400, 375, 405,375);
    qp.drawLine(400, 400, 405,400);
    qp.drawLine(400, 425, 405,425);
    qp.drawLine(400, 450, 405,450);
    qp.drawLine(400, 475, 405,475);
    qp.drawLine(400, 500, 405,500);
    qp.drawLine(400, 525, 405,525);
    qp.drawLine(400, 550, 405,550);
    qp.drawLine(400, 575, 405,575);
    qp.drawLine(400, 600, 405,600);
    qp.drawLine(400, 625, 405,625);
    qp.drawLine(400, 650, 405,650);
    qp.drawLine(400, 675, 405,675);
    qp.drawLine(400, 700, 405,700);
    qp.drawLine(400, 725, 405,725);
    qp.drawLine(400, 750, 405,750);
    if(vec.size()%2==0){
        if(!ok) {
            for(int i =0;i<vec.size();i+=2){
               qp.drawLine(vec[i].first,vec[i].second,vec[i+1].first,vec[i+1].second);
            }
        } else {
            for(int i =0;i<vec.size();i+=2){
               qp.drawLine(vec2[i].first,vec2[i].second,vec2[i+1].first,vec2[i+1].second);
            }
        }
    }
    qp.drawRect(xmin,ymin,xmax-xmin,ymax-ymin);
    qp.end();
}

// алгоритм ,барски
// выполнитть алгоритм для каждого отрезка /
// вывести обрезанные отрезки которые храняться в векторе
// 2 часьь гугл

void MainWindow::on_pushButton_clicked()
{
    x1 =QInputDialog::getInt(this, "1st point", "Enter x");
    x1 = 400 + x1;
    y1 = QInputDialog::getInt(this, "1st point", "Enter y");
    y1 = 400 - y1;
    x2 =QInputDialog::getInt(this, "2nd point", "Enter x");
    x2 = 400 + x2;
    y2 = QInputDialog::getInt(this, "2nd point", "Enter y");
    y2 = 400 - y2;
    vec.push_back({x1,y1});
    vec.push_back({x2,y2});
    qDebug() << "here - " << ok;
    ok = 0;
    update();
}

void MainWindow::on_pushButton_2_clicked()
{
    xmin =QInputDialog::getInt(this, "1st point", "Enter x");
    xmin = 400 + xmin;
    ymin = QInputDialog::getInt(this, "1st point", "Enter y");
    ymin = 400 - ymin;
    xmax =QInputDialog::getInt(this, "2nd point", "Enter x");
    xmax = 400 + xmax;
    ymax = QInputDialog::getInt(this, "2nd point", "Enter y");
    ymax = 400 - ymax;
    update();
}

float maxi(const float arr[], int n) {
    float m = 0;
    for (int i = 0; i < n; ++i)
        if (m < arr[i])
            m = arr[i];
    return m;
}

float mini(const float arr[], int n) {
    float m = 1;
    for (int i = 0; i < n; ++i)
        if (m > arr[i])
            m = arr[i];
    return m;
}

void MainWindow::on_pushButton_3_clicked()
{

    vec2.clear();
    qDebug() << x1 << " "<< y1 <<" " << x2 << " "<<y2;
    qDebug() << vec[0].first << " "<< vec[0].second <<" " << vec[1].first << " "<< vec[1].second;
    qDebug() << xmax << " "<< ymax <<" " << xmin << " "<< ymin;
    for(int i=0;i<vec.size();i+=2) {
        float p1 = -(vec[i+1].first - vec[i].first);
        float p2 = -p1;
        float p3 = -(vec[i+1].second - vec[i].second);
        float p4 = -p3;
        float q1 = vec[i].first - xmin;
        float q2 = xmax - vec[i].first;
        float q3 = vec[i].second - ymin;
        float q4 = ymax - vec[i].second;
        float posarr[5], negarr[5];
        int posind = 1, negind = 1;
        posarr[0] = 1;
        negarr[0] = 0;

        /*if ((p1 == 0 && q1 < 0) || (p3 == 0 && q3 < 0)) {
            return;
        }*/
        if (p1 != 0) {
            float r1 = q1 / p1;
            float r2 = q2 / p2;
            if (p1 < 0) {
                negarr[negind++] = r1;
                posarr[posind++] = r2;
            } else {
                negarr[negind++] = r2;
                posarr[posind++] = r1;
            }
        }
        if (p3 != 0) {
            float r3 = q3 / p3;
            float r4 = q4 / p4;
            if (p3 < 0) {
                negarr[negind++] = r3;
                posarr[posind++] = r4;
            } else {
                negarr[negind++] = r4;
                posarr[posind++] = r3;
            }
        }

        float xn1, yn1, xn2, yn2;
        float rn1, rn2;
        rn1 = maxi(negarr, negind);
        rn2 = mini(posarr, posind);

        /*if (rn1 > rn2) {
            return;
        }*/

        xn1 = vec[i].first + p2 * rn1;
        yn1 = vec[i].second + p4 * rn1;

        xn2 = vec[i].first + p2 * rn2;
        yn2 = vec[i].second + p4 * rn2;

        vec2.push_back({xn1,yn1});
        vec2.push_back({xn2,yn2});
    }
    ok = 1;

    for(auto now : vec) {
        qDebug() << now.first << " " << now.second;
    }

    update();
}
