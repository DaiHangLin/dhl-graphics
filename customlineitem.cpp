#include "customlineitem.h"
#include <QPainter>
#include <QDebug>

CustomLineItem::CustomLineItem(PointData &pd, QGraphicsObject *parent) : GraphicsBaseObject(parent)
{
    pointData = pd;
    setZValue(11);
}

void CustomLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rectf;
    getRealRect(&rectf);

    painter->setPen(QPen(penSpec.color, penSpec.width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(pointData.sp, pointData.cp);

    if (isSelected()) {
        painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    } else {
        painter->setPen(QPen(Qt::transparent, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter->drawRect(rectf);
}

void CustomLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mousePressEvent(event);
    if (!cusSelected) {
        return;
    }
}

void CustomLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseMoveEvent(event);
    qDebug() << "this" << this << "mouse move" << cusSelected;
    if (!cusSelected) {
        return;
    }
    QPointF scenePos = event->scenePos();
    QPointF lastScenePos = event->lastScenePos();
    setPos(pos() + scenePos - lastScenePos);
}

void CustomLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseReleaseEvent(event);
    if (!cusSelected) {
        return;
    }
}
