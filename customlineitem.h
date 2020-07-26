#ifndef CUSTOMLINEITEM_H
#define CUSTOMLINEITEM_H

#include <QObject>
#include <graphicsbaseobject.h>

class CustomLineItem : public GraphicsBaseObject
{
    Q_OBJECT
public:
    explicit CustomLineItem(PointData &pd, QGraphicsObject *parent = nullptr);

protected:
    QRectF getBoundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

signals:

public slots:
};

#endif // CUSTOMLINEITEM_H
