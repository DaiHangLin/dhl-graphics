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
    virtual bool isSelected(QPointF &p) = 0;
    virtual QString getType();

protected:
    PenSpec penSpec;
    PointData pointData;

protected:
    QRectF boundingRect() const override;
    void getRealRect(QRectF *rectf) const;

private:
    virtual QRectF getBoundingRect() const = 0;

signals:

public slots:
};

#endif // GRAPHICSBASEOBJECT_H
