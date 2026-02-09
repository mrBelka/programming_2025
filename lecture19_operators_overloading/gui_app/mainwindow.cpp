#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <functions.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //ui->result->setText(QString::number(mt::foo(2, 2)));
    //mt::print("button clicked");

    std::string qa = ui->test_a->text().toStdString();
    std::string qb = ui->test_b->text().toStdString();

    mt::BigInt a(qa);
    mt::BigInt b(qb);
    mt::BigInt c = a + b;
    c.print();
    c++;

    for (BigInt i = 0; i < n; i++) {

    }

    std::string result = c.get();
    QString qresult = QString::fromStdString(result);
    ui->text_result->setText(qresult);
}

