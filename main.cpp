#include "mainwindow.h"
#include "toolwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <mygraphicsview.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();

    QScopedPointer<MainWindow> scene(new MainWindow(desktopSize));

    QScopedPointer<MyGraphicsView> view(new MyGraphicsView(scene.get()));

    view->resize(desktopSize);
    view->show();

    return a.exec();
}
