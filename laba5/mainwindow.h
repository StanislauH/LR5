#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QEvent>
#include <QMainWindow>
#include <QPainter>
#include <vector>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent*) override;
public:
    MainWindow(QWidget *parent = nullptr);
    QPainter qp;
    std::vector <std::pair<int,int> > vec;
    std::vector <std::pair<int,int> > vec2;
    int x1, y1, x2, y2;
    int xmin, ymin, xmax,ymax;
    bool ok = 0;

    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
