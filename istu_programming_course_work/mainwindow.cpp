#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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
    ui->tableWidget->setColumnCount(9);                    //устанавливаем количество столбцов в таблице
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               <<"Номер зачётки"
                                               <<"Фамилия И.О."
                                               <<"Номер варианта"
                                               <<"Задание 1"
                                               <<"Оценка 1"
                                               <<"Задание 2"
                                               <<"Оценка 2"
                                               <<"Задание 3"
                                               <<"Оценка 3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()   // Открытие файла
{
    // для того что бы узнать имя файла, используем стандартный диалог выбора файла (QFileDialog)
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл базы данных"),
                                                    "/studentstasks",
                                                    tr("Файлы базы данных (*.data *.dat *.csv);;Все файлы (*.*)"));

    // класс QFile используется для представления файла в программе
    QFile file(fileName);                       // создаем объект файла (QFile)


    if(file.open(QIODevice::ReadOnly))          // открываем файл только для чтения (QFile)
    {
        QTextStream stream(&file);              // создаем поток для ввода/вывода (QTextStream) и связываем его с файлом
        QString str;
        int i = 0;                                      // перменная для хранения количества заполняемых строк таблицы

        while(!stream.atEnd())                          // цикл с предусловием для чтения потока, пока в нем есть данные
        {
            ui->tableWidget->setRowCount(i+1);          // добавляем строку в таблицу
            str = stream.readLine();                    // считываем данные построчно с использованием потока (QTextStream)

            QStringList string = str.split(';');        // разделяем считанную строку по символу ";" и записываем ее
                                                        // составляющие в объект класса-контейнер QStringList

            int j = string.size();                      // записываем в переменную j размер контейнера QStringList

            QTableWidgetItem *item;                     // создадиим указатель типа QTableWidgetItem для элемента таблицы

            for (int z = 0; z<j; z++)                   // цикл заполнения строки таблицы
            {
                item = new QTableWidgetItem(string[z]); // создаем элемент таблицы (тип QTableWidgetItem) и помемщаем в него данные
                                                        // составляющих строки из контейнера QStringList
                ui->tableWidget->setItem(i,z,item);     // передаем в таблицу наш элемент с указанием адреса ячейки для его отображения
            }

            i++;                                         // добавляем номер строки для следующей записи
        }

        if(stream.status()!= QTextStream::Ok)           // если не удалось считать файл
        {
            QMessageBox::warning(this, "Ошибка", "Ошибка чтения файла");
        }

         file.close();                                  // закрываем файл
    }
}

} // namespace alchalov
