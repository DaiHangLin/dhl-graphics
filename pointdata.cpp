#include "pointdata.h"

PointData::PointData() : pointList(QVector<QPointF>()), drawType(Draw_Line)
{

}

void PointData::addPoint(QPointF p)
{
     pointList << p;
     cp = p;
}
