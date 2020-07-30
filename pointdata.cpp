#include "pointdata.h"
#include <QDebug>

PointData::PointData() : pointList(QVector<QPointF>()), drawType(Draw_Line)
{

}

void PointData::addPoint(QPointF p)
{
    pointList << p;
    cp = p;
}
