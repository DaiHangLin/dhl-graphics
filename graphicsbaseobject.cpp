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

void GraphicsBaseObject::getRealRect(QRectF *rectf) const
{
    qreal x1 = qMax(pointData.sp.x(), pointData.cp.x());
    qreal x2 = qMin(pointData.sp.x(), pointData.cp.x());
    qreal y1 = qMax(pointData.sp.y(), pointData.cp.y());
    qreal y2 = qMin(pointData.sp.y(), pointData.cp.y());
    rectf->setTopLeft(QPointF(x2, y1));
    rectf->setBottomRight(QPointF(x1, y2));
    qreal aw = penSpec.width / 2;
    rectf->adjust(-aw, aw, aw, -aw);
}
