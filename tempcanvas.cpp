#include "tempcanvas.h"
#include <QDebug>

TempCanvas::TempCanvas(const QSizeF &size, PenSpec &ps, QGraphicsObject *parent) :
    QGraphicsObject(parent),
    size(size),
    penSpec(ps)
{
    pixmap = QSharedPointer<QPixmap>(new QPixmap(size.toSize()));
    pixmap->fill(Qt::transparent);
    painter = QSharedPointer<QPainter>(new QPainter(pixmap.get()));
    painter->setPen(QPen(penSpec.color, penSpec.width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setRenderHints(QPainter::HighQualityAntialiasing);
}

void TempCanvas::drawLine(PointData &pd)
{
    painter->drawLine(pd.sp, pd.cp);
}

void TempCanvas::drawRectange(PointData &pd)
{
    painter->drawRect(QRectF(pd.sp, pd.cp));
}

void TempCanvas::drawCircle(PointData &pd)
{
    painter->drawEllipse(QRectF(pd.sp, pd.cp));
}

void TempCanvas::drawFree(PointData &pd)
{
   QVector<QPointF> pointList = pd.pointList;
    if (pointList.size() <= 0) {
        return;
    }
    QPainterPath path;
    path.moveTo(pointList[0]);
    for (int i = 1; i < pointList.size(); i ++) {
        QPointF &d1 = pointList[i - 1];
        QPointF &d2 = pointList[i];
        path.quadTo(d1, (d1 + d2) / 2);
        painter->drawPath(path);
        QPointF endPoint = path.currentPosition();
        path.clear();
        path.moveTo(endPoint);
    }
}

void TempCanvas::drawItem(PointData &pd)
{
    pixmap->fill(Qt::transparent);
    DrawType &type = pd.drawType;
    switch (type) {
    case Draw_Line:
        drawLine(pd);
        break;
    case Draw_Rectange:
        drawRectange(pd);
        break;
    case Draw_Circle:
        drawCircle(pd);
        break;
    case Draw_Free:
        drawFree(pd);
        break;
    default:
        qDebug() << "unsopport draw type!!!";
        break;
    }
    this->update();
}

void TempCanvas::clean()
{
    pixmap->fill(Qt::transparent);
    update();
}

void TempCanvas::save()
{
    pixmap->save("test.png");
}

QRectF TempCanvas::boundingRect() const
{
   return QRectF(QPointF(0, 0), size);
}

void TempCanvas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *pixmap.data());
}
