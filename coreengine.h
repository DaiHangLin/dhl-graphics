#ifndef COREENGINE_H
#define COREENGINE_H

#include "pensepc.h"
#include "tempcanvas.h"

#include <QObject>
#include <QGraphicsObject>
#include <pointdata.h>
#include <graphicsbaseobject.h>
#include <graphicsshapefactory.h>

class CoreEngine : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit CoreEngine(const QSizeF &size, QGraphicsObject *parent = nullptr);

    void drawPress(int id, const QPointF &p);
    void drawMove(int id, const QPointF &lp, const QPointF &cp);
    void drawRelease(int id, const QPointF &p);
    void setDrawType(DrawType &dt);

private:
    QSizeF size;
    PenSpec penSpc;
    DrawType dt;
    QSharedPointer<TempCanvas> tempCanvas;
    QHash<int, PointData> pointDataMap;
    GraphicsShapeFactory factory;

private:
    void addPointData(int id, const QPointF &p);
    void drawRealItem(int id);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

signals:

public slots:
    void updateSelf();
};

#endif // COREENGINE_H
