#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

class MainWindow : public QGraphicsScene
{
    Q_OBJECT

public:
    MainWindow(QSize size, QObject *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
