#include "customlineitem.h"
#include <QPainter>
#include <QDebug>

CustomLineItem::CustomLineItem(PointData &pd, QGraphicsObject *parent) : GraphicsBaseObject(parent)
{
    pointData = pd;
    setSelected(true);
}

QRectF CustomLineItem::getBoundingRect() const
{
    QRectF rectf;
    getRealRect(&rectf);
    return rectf;
//    return QRectF(0, 0, qAbs(pointData.sp.x() - pointData.cp.x()), qAbs(pointData.sp.y() - pointData.cp.y()));
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

bool CustomLineItem::isSelected(QPointF &p)
{
    QRectF rectf;
    getRealRect(&rectf);
    QRectF clickRect(QRectF(p, QSizeF(1, 1)));
    return rectf.intersects(clickRect);
}
