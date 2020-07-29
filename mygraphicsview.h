#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include "mainwindow.h"
#include "toolwindow.h"

#include <QGraphicsView>
#include <QObject>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(MainWindow *scene, QWidget *parent = nullptr);

private:
    ToolWindow *toolView;
    MainWindow *scene;

signals:

public slots:
};

#endif // MYGRAPHICSVIEW_H
