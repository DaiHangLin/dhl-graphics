#ifndef COREENGINE_H
#define COREENGINE_H

#include <QObject>
#include <QGraphicsObject>

class CoreEngine : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit CoreEngine(const QSizeF &size, QGraphicsObject *parent = nullptr);

    void drawPress(int id, const QPointF &p);
    void drawMove(int id, const QPointF &lp, const QPointF &cp);
    void drawRelease(int id, const QPointF &p);

private:
    QSizeF size;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

signals:

public slots:
};

#endif // COREENGINE_H
