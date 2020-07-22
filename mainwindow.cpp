#include "mainwindow.h"

MainWindow::MainWindow(QSize size, QObject *parent)
    : QGraphicsScene(QRectF(QPoint(0, 0), size), parent)
{
}

MainWindow::~MainWindow()
{
}

