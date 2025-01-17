#include "GeoScopeMainWindow.h"
#include "./ui_GeoScopeMainWindow.h"

GeoScopeMainWindow::GeoScopeMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GeoScopeMainWindow)
{
    ui->setupUi(this);
}

GeoScopeMainWindow::~GeoScopeMainWindow()
{
    delete ui;
}
