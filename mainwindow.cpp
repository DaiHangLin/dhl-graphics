#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QSize size, QObject *parent)
    : QGraphicsScene(QRectF(QPoint(0, 0), size), parent),
      coreEngine(nullptr)
{
    coreEngine = new CoreEngine(size);
}

MainWindow::~MainWindow()
{
    if (coreEngine) {
        delete coreEngine;
        coreEngine = nullptr;
    }
}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    scenePress(1, event->scenePos());
    QGraphicsScene::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    sceneMove(1, event->lastScenePos(), event->scenePos());
    QGraphicsScene::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    sceneRelease(1, event->scenePos());
    QGraphicsScene::mousePressEvent(event);
}

void MainWindow::scenePress(int id, const QPointF &p)
{
    coreEngine->drawPress(id, p);
}

void MainWindow::sceneMove(int id, const QPointF &lp, const QPointF &cp)
{
    coreEngine->drawMove(id, lp, cp);
}

void MainWindow::sceneRelease(int id, const QPointF &p)
{
    coreEngine->drawRelease(id, p);
}

