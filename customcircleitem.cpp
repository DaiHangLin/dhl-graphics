#include "customcircleitem.h"

CustomCircleItem::CustomCircleItem(PointData &pd, QGraphicsObject *parent) : GraphicsBaseObject(parent)
{
    pointData = pd;
    setZValue(11);
}

void CustomCircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     QRectF rectf;
    getRealRect(&rectf);

    painter->setPen(QPen(penSpec.color, penSpec.width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawEllipse(QRectF(pointData.sp, pointData.cp));

    if (isSelected()) {
        painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    } else {
        painter->setPen(QPen(Qt::transparent, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter->drawRect(rectf);

}

void CustomCircleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   QGraphicsObject::mousePressEvent(event);
}

void CustomCircleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseMoveEvent(event);
}

void CustomCircleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseReleaseEvent(event);
}
