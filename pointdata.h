#ifndef POINTDATA_H
#define POINTDATA_H
#include <QPointF>
#include <QVector>

enum DrawType {
    Draw_Line,
    Draw_Rectange,
    Draw_Circle,
    Draw_Free,
};

class PointData
{
public:
    PointData();
    int id;
    QPointF sp;
    QVector<QPointF> pointList;
    QPointF cp;
    DrawType drawType;

    void addPoint(QPointF p);
};

#endif // POINTDATA_H
