#include "customfreeitem.h"

CustomFreeItem::CustomFreeItem(PointData &pd, QGraphicsObject *parent) : GraphicsBaseObject(parent)
{
    pointData = pd;
    setZValue(11);
}

void CustomFreeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penSpec.color, penSpec.width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    QPainterPath path;
    QVector<QPointF> pointList = pointData.pointList;
    if (pointList.size() <= 0) {
        return;
    }
    path.moveTo(pointList[0]);
    for (int i = 1; i < pointList.size(); i ++) {
        QPointF &d1 = pointList[i - 1];
        QPointF &d2 = pointList[i];
        path.quadTo(d1, (d1 + d2) / 2);
        painter->drawPath(path);
        QPointF endPoint = path.currentPosition();
        path.clear();
        path.moveTo(endPoint);
    }
}

void CustomFreeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     QGraphicsObject::mousePressEvent(event);
}

void CustomFreeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
     QGraphicsObject::mouseMoveEvent(event);
}

void CustomFreeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
     QGraphicsObject::mouseReleaseEvent(event);
}
