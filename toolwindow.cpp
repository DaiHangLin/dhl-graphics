#include "toolwindow.h"
#include "ui_toolwindow.h"
#include <QDebug>

ToolWindow::ToolWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

ToolWindow::~ToolWindow()
{
    delete ui;
}

void ToolWindow::on_rb_line_toggled(bool checked)
{
    if (checked) {
        DrawType t(Draw_Line);
        emit onDrawTypeSelected(t);
    }
}

void ToolWindow::on_rb_rect_toggled(bool checked)
{
    if (checked) {
        DrawType t(Draw_Rectange);
        emit onDrawTypeSelected(t);
    }
}

void ToolWindow::on_rb_circle_toggled(bool checked)
{
    if (checked) {
        DrawType t(Draw_Circle);
        emit onDrawTypeSelected(t);
    }
}

void ToolWindow::on_rb_free_toggled(bool checked)
{
    if (checked) {
        DrawType t(Draw_Free);
        emit onDrawTypeSelected(t);
    }
}

void ToolWindow::on_rb_select_toggled(bool checked)
{
    if (checked) {
        DrawType t(Draw_None);
        emit onDrawTypeSelected(t);
    }
}
