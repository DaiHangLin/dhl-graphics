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
    QRectF rectf;
    getRealRect(&rectf);
    return rectf;
}

void CustomLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(penSpec.color, penSpec.width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(pointData.sp, pointData.cp);
    painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawPoint(pointData.sp);
    painter->drawPoint(pointData.cp);
    QRectF rectf;
    getRealRect(&rectf);
    painter->drawRect(rectf);
}
