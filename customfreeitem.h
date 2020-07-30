#ifndef CUSTOMFREEITEM_H
#define CUSTOMFREEITEM_H

#include "graphicsbaseobject.h"
#include "pointdata.h"

#include <QObject>
#include <QPainter>

class CustomFreeItem : public GraphicsBaseObject
{
    Q_OBJECT
public:
    explicit CustomFreeItem(PointData &pd, QGraphicsObject *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QSizeF size;

signals:

public slots:
};

#endif // CUSTOMFREEITEM_H
