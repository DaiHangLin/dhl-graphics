#include "mygraphicsview.h"

#include <QApplication>
#include <QKeyEvent>

MyGraphicsView::MyGraphicsView(MainWindow *scene, QWidget *parent) : QGraphicsView(parent),
    scene(scene)
{
    setScene(scene);

    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    toolView = new ToolWindow(this);
    connect(toolView, &ToolWindow::onDrawTypeSelected, scene, &MainWindow::handleDrawTypeChanged);
}
