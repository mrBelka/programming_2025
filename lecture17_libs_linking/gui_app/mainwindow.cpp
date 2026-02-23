#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <functions.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qInfo() << mt::foo(2, 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
