#ifndef GRAPHICSBASEOBJECT_H
#define GRAPHICSBASEOBJECT_H

#include "pensepc.h"
#include "pointdata.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class GraphicsBaseObject : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit GraphicsBaseObject(QGraphicsItem *parent = nullptr);
    void setPointData(PointData &pd);
    void setPenSpec(PenSpec &ps);
    virtual QString getType();

protected:
    PenSpec penSpec;
    PointData pointData;

protected:
    QRectF boundingRect() const override;
    void getRealRect(QRectF *rectf) const;

private:
signals:

public slots:
};

#endif // GRAPHICSBASEOBJECT_H
