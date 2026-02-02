#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btn_ = new QPushButton("some_text", this);
    connect(btn_, SIGNAL(clicked()), this, SLOT(on_bt_addiction_clicked()));
}

MainWindow::~MainWindow()
{
    delete btn_;
    delete ui;
}

void MainWindow::on_bt_addiction_clicked()
{
    QString qa = ui->arg1->text();
    int a = qa.toInt();
    QString qb = ui->arg2->text();
    int b = qb.toInt();
    int c = a + b;
    QString qc = QString::number(c);
    ui->result->setText(qc);
}


void MainWindow::on_arg1_textChanged(const QString &arg1)
{
    qInfo() << arg1;
}

