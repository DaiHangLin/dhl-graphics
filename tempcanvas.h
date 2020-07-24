#ifndef TEMPCANVAS_H
#define TEMPCANVAS_H

#include "pensepc.h"
#include "pointdata.h"

#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QSharedPointer>
#include <QGraphicsObject>

class TempCanvas : public QGraphicsObject
{
public:
    explicit TempCanvas(const QSizeF &size, PenSpec &penSpec, QGraphicsObject *parent = nullptr);

    void drawItem(PointData &pd);
    void save();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

private:
    QSizeF size;
    PenSpec penSpec;
    QSharedPointer<QPixmap> pixmap;
    QSharedPointer<QPainter> painter;

private:
    void drawLine(PointData &pd);
    void drawRectange(PointData &pd);
    void drawCircle(PointData &pd);
    void clean();

};

#endif // TEMPCANVAS_H
