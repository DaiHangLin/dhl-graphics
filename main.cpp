#include "mainwindow.h"
#include "toolwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();

    QScopedPointer<ToolWindow> toolView(new ToolWindow());
    toolView->move(desktopSize.width() - 200, 100);
    toolView->show();

    QScopedPointer<QGraphicsView> view(new QGraphicsView());
    QScopedPointer<MainWindow> scene(new MainWindow(desktopSize));
    view->setRenderHint(QPainter::Antialiasing);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setScene(scene.get());
    view->resize(desktopSize);
    view->show();

    QObject::connect(toolView.get(), &ToolWindow::onDrawTypeSelected, scene.get(), &MainWindow::handleDrawTypeChanged);

    return a.exec();
}
