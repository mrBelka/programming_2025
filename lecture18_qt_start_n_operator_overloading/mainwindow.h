#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    void on_bt_addiction_clicked();

    void on_arg1_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    size_t counter_ = 0;
    QPushButton *btn_;
};
#endif // MAINWINDOW_H
