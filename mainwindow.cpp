#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <algorithm>
#include <QThread>
#include <QMessageBox>
#include "settingdialog.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Yapay Zeka");
    setMouseTracking(true);
    on_m_actionClear_triggered();


    for(int i = 0; i < 30; ++i){
        QColor color{Qt::red};
        QPoint p(rand() % 200 + 50, rand() % 200 + 20);
        m_vecPoint.append(qMakePair(p, color));
    }

    for(int i = 0; i < 30; ++i){
        QColor color{Qt::blue};
        QPoint p(rand() % 200 + 250, rand() % 200 + 210);
        m_vecPoint.append(qMakePair(p, color));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    for(int i = 0; i < m_vecPoint.size(); ++ i){
        QPen newPen{m_vecPoint[i].second};
        newPen.setWidth(m_pointSize);
        painter.setPen(newPen);
        painter.drawPoint(m_vecPoint[i].first);
    }
    if(m_flagClick){
        QVector<QPair<QPoint, QColor>> vec{m_vecPoint};

        std::sort(vec.begin(), vec.end(), [this] (QPair<QPoint, QColor> p1, QPair<QPoint, QColor> p2){
            return (p1.first - m_myPoint).manhattanLength() < (p2.first - m_myPoint).manhattanLength();
        });

        int bluePointCount = 0;
        int redPointCount = 0;
        for(int i = 0; i < m_node; ++i){
            QPen linePen(vec[i].second);
            linePen.setWidth(m_lineSize);
            painter.setPen(linePen);
            painter.drawLine(m_myPoint, vec[i].first);
            if(vec[i].second == Qt::red)
                ++redPointCount;
            else if(vec[i].second == Qt::blue)
                ++bluePointCount;
        }
        QColor color;
        if ( redPointCount == bluePointCount)
            color = Qt::black;

        else if ( redPointCount > bluePointCount)
            color = Qt::red;

        else if(bluePointCount > redPointCount)
            color = Qt::blue;

        QPen myPointPen(color);
        myPointPen.setWidth(m_newPointSize);
        painter.setPen(myPointPen);
        painter.drawPoint(m_myPoint);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() <<"void mouseReleaseEvent(QMouseEvent *event)";
    m_flagClick = true;
    m_myPoint = event->pos();
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() <<"void MainWindow::mouseMoveEvent(QMouseEvent *event)";
    qDebug() << event->pos();
}

void MainWindow::on_m_actionClear_triggered()
{
    m_flagClick = false;
    m_pointSize = 4;
    m_newPointSize = 6;
    m_lineSize = 2;
    m_node = 3;
    update();
}

void MainWindow::on_m_actionSettings_triggered()
{
    SettingDialog sDialog(this, m_newPointSize, m_pointSize, m_lineSize, m_node);
    int result = sDialog.exec();
    if(result == QDialog::Rejected)
        return;

    m_pointSize = sDialog.pointSize();
    m_newPointSize = sDialog.newPointSize();
    m_lineSize = sDialog.lineSize();
    m_node = sDialog.node();
}
