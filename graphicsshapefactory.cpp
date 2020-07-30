#include "customcircleitem.h"
#include "customfreeitem.h"
#include "customrectitem.h"
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
    case Draw_Rectange: {
        CustomRectItem *rectItem = new CustomRectItem(pd, parent);
        return rectItem;
    }
    case Draw_Circle: {
        CustomCircleItem *circleItem = new CustomCircleItem(pd, parent);
        return circleItem;
    }
    case Draw_Free: {
        CustomFreeItem * freeItem = new CustomFreeItem(pd, parent);
        return freeItem;
    }
    default:
        return nullptr;
    }
}

GraphicsBaseObject *GraphicsShapeFactory::drawLine(PointData &pd, QGraphicsObject &parent)
{
    CustomLineItem *lineItem = new CustomLineItem(pd, &parent);
    return lineItem;
}
