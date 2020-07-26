#ifndef GRAPHICSSHAPEFACTORY_H
#define GRAPHICSSHAPEFACTORY_H
#include "pointdata.h"
#include <graphicsbaseobject.h>
#include <customlineitem.h>

#include <QGraphicsObject>

class GraphicsShapeFactory
{
public:
    GraphicsShapeFactory();
    GraphicsBaseObject * drawItem(PointData &pd, QGraphicsObject *parent);

private:
    GraphicsBaseObject * drawLine(PointData &pd, QGraphicsObject &parent);

};

#endif // GRAPHICSSHAPEFACTORY_H
