#include "customlineitem.h"
#include <QPainter>
#include <QDebug>

CustomLineItem::CustomLineItem(PointData &pd, QGraphicsObject *parent) : GraphicsBaseObject(parent)
{
    pointData = pd;
    qDebug() << "point data" << pointData.sp;
}

QRectF CustomLineItem::getBoundingRect() const
{
  return QRectF(pointData.sp, pointData.cp);
}

void CustomLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penSpec.color, penSpec.width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(pointData.sp, pointData.cp);
    qDebug() << "line item paint";
}
