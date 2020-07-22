#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();
    QScopedPointer<QGraphicsView> view(new QGraphicsView());
    QScopedPointer<MainWindow> scene(new MainWindow(desktopSize));
    view->setScene(scene.get());
    view->resize(desktopSize);
    view->show();

    return a.exec();
}
