#ifndef GEOSCOPEMAINWINDOW_H
#define GEOSCOPEMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GeoScopeMainWindow;
}
QT_END_NAMESPACE

class GeoScopeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GeoScopeMainWindow(QWidget *parent = nullptr);
    ~GeoScopeMainWindow();

private:
    Ui::GeoScopeMainWindow *ui;
};
#endif // GEOSCOPEMAINWINDOW_H
