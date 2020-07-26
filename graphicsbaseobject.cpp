#include "graphicsbaseobject.h"
#include <QGraphicsItem>
#include <QPainter>

GraphicsBaseObject::GraphicsBaseObject(QGraphicsItem *parent) : QGraphicsObject(parent)
{
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsMovable,true);
}

void GraphicsBaseObject::setPointData(PointData &pd)
{
    pointData = pd;
}

void GraphicsBaseObject::setPenSpec(PenSpec &ps)
{
    penSpec = ps;
}

void GraphicsBaseObject::drawItem()
{
   update();
}

QRectF GraphicsBaseObject::boundingRect() const
{
    return getBoundingRect();
}
