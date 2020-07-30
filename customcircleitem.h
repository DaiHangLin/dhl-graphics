#ifndef CUSTOMCIRCLEITEM_H
#define CUSTOMCIRCLEITEM_H

#include <QObject>
#include <QPainter>
#include <graphicsbaseobject.h>

class CustomCircleItem : public GraphicsBaseObject
{
    Q_OBJECT
public:
    explicit CustomCircleItem(PointData &pd, QGraphicsObject *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:

public slots:
};


#endif // CUSTOMCIRCLEITEM_H
