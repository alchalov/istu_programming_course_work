#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace alchalov {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);                  //

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // устанавливаем выделение целой строки
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // настраиваем отображения столбцов
    ui->tableWidget->setColumnCount(6);                    //устанавливаем количество столбцов в таблице
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()  <<"Маршрут" <<"Начало маршрута" <<"Конец маршрута"
                                               <<"Тип автобуса" <<"Количество автобусов" <<"Номер автобазы" );
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace alchalov
