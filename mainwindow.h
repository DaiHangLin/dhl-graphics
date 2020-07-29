#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <coreengine.h>
#include <QTimer>
#include <QDebug>
#include <qgraphicssceneevent.h>

class MainWindow : public QGraphicsScene
{
    Q_OBJECT

public:
    MainWindow(QSize size, QObject *parent = nullptr);
    ~MainWindow() override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void scenePress(int id, const QPointF &p);
    void sceneMove(int id, const QPointF &lp, const QPointF &cp);
    void sceneRelease(int id, const QPointF &p);

private:
    QSharedPointer<CoreEngine> coreEngine;
    QSharedPointer<QTimer> timer;

public slots:
    void handleDrawTypeChanged(DrawType &dt);
};
#endif // MAINWINDOW_H
