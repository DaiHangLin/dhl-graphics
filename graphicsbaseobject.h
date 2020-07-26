#ifndef GRAPHICSBASEOBJECT_H
#define GRAPHICSBASEOBJECT_H

#include "pensepc.h"
#include "pointdata.h"

#include <QObject>
#include <QGraphicsItem>

class GraphicsBaseObject : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit GraphicsBaseObject(QGraphicsItem *parent = nullptr);
    void setPointData(PointData &pd);
    void setPenSpec(PenSpec &ps);
    void drawItem();

protected:
    QRectF boundingRect() const override;
    PenSpec penSpec;
    PointData pointData;

private:
    virtual QRectF getBoundingRect() const = 0;

signals:

public slots:
};

#endif // GRAPHICSBASEOBJECT_H
