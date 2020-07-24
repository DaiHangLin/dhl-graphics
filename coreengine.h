#ifndef COREENGINE_H
#define COREENGINE_H

#include "pensepc.h"
#include "tempcanvas.h"

#include <QObject>
#include <QGraphicsObject>
#include <pointdata.h>

class CoreEngine : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit CoreEngine(const QSizeF &size, QGraphicsObject *parent = nullptr);

    void drawPress(int id, const QPointF &p);
    void drawMove(int id, const QPointF &lp, const QPointF &cp);
    void drawRelease(int id, const QPointF &p);

private:
    QSizeF size;
    PenSpec penSpc;
    QSharedPointer<TempCanvas> tempCanvas;
    QHash<int, PointData> pointDataMap;

private:
    void addPointData(int id, const QPointF &p);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

signals:

public slots:
    void updateSelf();
};

#endif // COREENGINE_H
