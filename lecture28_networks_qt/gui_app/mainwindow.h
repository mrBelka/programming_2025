#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <meteo/control_room.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_poll_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<meteo::ControlRoom> room_;
    std::unique_ptr<QTimer> timer_;
};
#endif // MAINWINDOW_H
