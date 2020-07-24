#include "coreengine.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>

CoreEngine::CoreEngine(const QSizeF &s, QGraphicsObject *parent) :
    QGraphicsObject(parent),
    size(s),
    penSpc(PenSpec()),
    pointDataMap(QHash<int, PointData>())
{
    tempCanvas = QSharedPointer<TempCanvas>(new TempCanvas(size, penSpc, this));
    tempCanvas->setZValue(10);
}

void CoreEngine::drawPress(int id, const QPointF &p)
{
    qDebug() << __FUNCTION__ << id << p;
    pointDataMap.remove(id);
    PointData &pd = pointDataMap[id];
    pd.id = id;
    pd.sp = p;
    pd.addPoint(p);
}

void CoreEngine::drawMove(int id, const QPointF &lp, const QPointF &cp)
{
    qDebug() << __FUNCTION__ << id << lp << cp;
    if (!pointDataMap.contains(id)) {
        return;
    }
    addPointData(id, cp);
}

void CoreEngine::drawRelease(int id, const QPointF &p)
{
    qDebug() << __FUNCTION__ << id << p;
    if (!pointDataMap.contains(id)) {
        return;
    }
    addPointData(id, p);
}

void CoreEngine::addPointData(int id, const QPointF &p)
{
    PointData &pd = pointDataMap[id];
    pd.addPoint(p);
}

QRectF CoreEngine::boundingRect() const
{
   return QRectF(QPoint(0, 0), size);
}

void CoreEngine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawRect(this->boundingRect());
}

void CoreEngine::updateSelf()
{
    foreach (int id, pointDataMap.keys()) {
        PointData &pd = pointDataMap[id];
        tempCanvas->drawItem(pd);
    }
}
