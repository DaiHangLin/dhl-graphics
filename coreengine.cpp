#include "coreengine.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>

CoreEngine::CoreEngine(const QSizeF &s, QGraphicsObject *parent) :
    QGraphicsObject(parent),
    size(s)
{

}

void CoreEngine::drawPress(int id, const QPointF &p)
{
    qDebug() << __FUNCTION__ << id << p;
    QGraphicsItem *item = new QGraphicsItem(this);
}

void CoreEngine::drawMove(int id, const QPointF &lp, const QPointF &cp)
{
    qDebug() << __FUNCTION__ << id << lp << cp;
}

void CoreEngine::drawRelease(int id, const QPointF &p)
{
    qDebug() << __FUNCTION__ << id << p;
}

QRectF CoreEngine::boundingRect() const
{
   return QRectF(QPoint(0, 0), size);
}

void CoreEngine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawRect(this->boundingRect());
}
