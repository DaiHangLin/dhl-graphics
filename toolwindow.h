#ifndef TOOLWINDOW_H
#define TOOLWINDOW_H

#include <QWidget>
#include <pointdata.h>

namespace Ui {
class ToolWindow;
}

class ToolWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ToolWindow(QWidget *parent = nullptr);
    ~ToolWindow();

private slots:
    void on_rb_line_toggled(bool checked);

    void on_rb_rect_toggled(bool checked);

    void on_rb_circle_toggled(bool checked);

    void on_rb_free_toggled(bool checked);

    void on_rb_select_toggled(bool checked);

private:
    Ui::ToolWindow *ui;

signals:
    void onDrawTypeSelected(DrawType &t);

};

#endif // TOOLWINDOW_H
