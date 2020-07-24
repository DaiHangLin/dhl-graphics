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
    painter->setPen(QPen(penSpec.color, penSpec.width));
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
    QLineF line(pd.sp, pd.cp);
    painter->drawEllipse(pd.sp, line.length(), line.length());
}

void TempCanvas::drawItem(PointData &pd)
{
    pixmap->fill(Qt::transparent);
    DrawType &type = pd.drawType;
    qDebug() << "draw item";
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
    qDebug() << "======================= temp canvas paint" << *pixmap.data();
    painter->drawPixmap(0, 0, *pixmap.data());
}
