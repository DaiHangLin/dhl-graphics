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
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:

public slots:
};

#endif // CUSTOMLINEITEM_H
