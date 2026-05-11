#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <meteo/control_room.hpp>
#include <meteo/types.hpp>
#include <meteo/formats.hpp>
#include <meteo/utils.hpp>
#include <memory>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList headers{"id", "temp", "humidity", "wind_vel", "description"};

    ui->meteo_table->setColumnCount(headers.size()); // Указываем число колонок
    ui->meteo_table->setShowGrid(true);
    ui->meteo_table->setHorizontalHeaderLabels(headers);

    timer_ = std::make_unique<QTimer>(this);
    connect(timer_.get(), &QTimer::timeout, this, &MainWindow::on_bt_poll_clicked);
    timer_->start(1000);

    try {
        meteo::ControlRoom::Params params;
        params.meteostations = meteo::read_configuration("config.json");

        room_ = std::make_unique<meteo::ControlRoom>(params);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception!" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_poll_clicked()
{
    try {
        const auto infos = room_->run_once();

        ui->pb_baltiisk->setValue(24);

        int i = 0;
        for (const auto info : infos) {
            std::cout << info << std::endl;
            ui->meteo_table->insertRow(i);
            ui->meteo_table->setItem(i,0, new QTableWidgetItem(QString::number(info.id)));
            ui->meteo_table->setItem(i,1, new QTableWidgetItem(QString::number(info.temp)));
            ui->meteo_table->setItem(i,2, new QTableWidgetItem(QString::number(info.humidity)));
            ui->meteo_table->setItem(i,3, new QTableWidgetItem(QString::number(info.wind_velocity)));
            ui->meteo_table->setItem(i,4, new QTableWidgetItem(QString::number(info.datetime.year)));
            ++i;
        }
        ui->meteo_table->resizeColumnsToContents();

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception!" << std::endl;
    }
}

