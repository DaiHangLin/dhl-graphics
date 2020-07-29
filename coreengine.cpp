#include "coreengine.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>

CoreEngine::CoreEngine(const QSizeF &s, QGraphicsObject *parent) :
    QGraphicsObject(parent),
    size(s),
    penSpc(PenSpec()),
    dt(Draw_Line),
    pointDataMap(QHash<int, PointData>())
{
    setCacheMode(ItemCoordinateCache);
    tempCanvas = QSharedPointer<TempCanvas>(new TempCanvas(size, penSpc, this));
    tempCanvas->setZValue(10);
}

void CoreEngine::drawPress(int id, const QPointF &p)
{
    if (dt == Draw_None) {
        return;
    }
    if (checkHasItemSelected(p)) {
        return;
    }
    PointData &pd = pointDataMap[id];
    pd.id = id;
    pd.sp = p;
    pd.drawType = dt;
    pd.addPoint(p);
}

void CoreEngine::drawMove(int id, const QPointF &lp, const QPointF &cp)
{
    if (!pointDataMap.contains(id)) {
        return;
    }
    addPointData(id, cp);
}

void CoreEngine::drawRelease(int id, const QPointF &p)
{
    if (!pointDataMap.contains(id)) {
        return;
    }
    addPointData(id, p);
    drawRealItem(id);
    tempCanvas->clean();
    pointDataMap.remove(id);
}

void CoreEngine::addPointData(int id, const QPointF &p)
{
    PointData &pd = pointDataMap[id];
    pd.addPoint(p);
}

void CoreEngine::drawRealItem(int id)
{
    PointData &pd = pointDataMap[id];
    GraphicsBaseObject *obj = factory.drawItem(pd, this);
    if (obj) {
        obj->setPenSpec(penSpc);
    }
}

bool CoreEngine::checkHasItemSelected(const QPointF &p)
{
    QList<QGraphicsItem *> items = childItems();
    foreach(QGraphicsItem *item, items) {
        GraphicsBaseObject *obj = dynamic_cast<GraphicsBaseObject *>(item);
        if (obj && obj->isSelected()) {
            return true;
        }
    }
    return false;
}

QRectF CoreEngine::boundingRect() const
{
   return QRectF(QPoint(0, 0), size);
}

void CoreEngine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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
    update();
}

void CoreEngine::setDrawType(DrawType &t) {
    dt = t;
}

QString CoreEngine::getType()
{
   return "Engine";
}
