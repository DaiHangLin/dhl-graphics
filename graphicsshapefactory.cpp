#include "graphicsshapefactory.h"
#include <QDebug>

GraphicsShapeFactory::GraphicsShapeFactory()
{

}

GraphicsBaseObject * GraphicsShapeFactory::drawItem(PointData &pd, QGraphicsObject *parent)
{
    switch (pd.drawType) {
    case Draw_Line:
        return drawLine(pd, * parent);
    default:
        break;
    }
    return nullptr;
}

GraphicsBaseObject *GraphicsShapeFactory::drawLine(PointData &pd, QGraphicsObject &parent)
{
    CustomLineItem *lineItem = new CustomLineItem(pd, &parent);
    return lineItem;
}
