#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(MainWindow *scene, QWidget *parent) : QGraphicsView(parent),
    scene(scene)
{
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    toolView = new ToolWindow(this);
    connect(toolView, &ToolWindow::onDrawTypeSelected, scene, &MainWindow::handleDrawTypeChanged);
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{

}
