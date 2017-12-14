#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPair>
#include <QVector>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_m_actionClear_triggered();
    void on_m_actionSettings_triggered();

private:
    Ui::MainWindow *ui;
    QVector<QPair<QPoint, QColor>> m_vecPoint;
    QPoint m_myPoint;
    bool m_flagClick;
    int m_pointSize;
    int m_newPointSize;
    int m_lineSize;
    int m_node;
};

#endif // MAINWINDOW_HPP
