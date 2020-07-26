#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QSize size, QObject *parent)
    : QGraphicsScene(QRectF(QPoint(0, 0), size), parent),
      coreEngine(QSharedPointer<CoreEngine>(new CoreEngine(size))),
      timer(QSharedPointer<QTimer>(new QTimer))
{
    addItem(coreEngine.data());
    connect(timer.data(), &QTimer::timeout, coreEngine.data(), &CoreEngine::updateSelf);
}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    timer->start(1000 / 60);
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
    timer->stop();
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

void MainWindow::handleDrawTypeChanged(DrawType &dt) {
    coreEngine->setDrawType(dt);
}

