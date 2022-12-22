#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogstudentbyrecord.h"
#include "dialogstudentbytask.h"
#include "dialogstudentbyvariantandsumscore.h"
#include "dialogstudentbyunassignedtask.h"
#include "dialogabout.h"

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
                                               <<"Номер\nзачётки"
                                               <<"Фамилия И.О."
                                               <<"Номер\nварианта"
                                               <<"Задание 1"
                                               <<"Оценка 1"
                                               <<"Задание 2"
                                               <<"Оценка 2"
                                               <<"Задание 3"
                                               <<"Оценка 3");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // инициализируем пустую задачу
    studentTasks = StudentTasks();
    addTableLine(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()   // Открытие файла
{
    // для того что бы узнать имя файла, используем стандартный диалог выбора файла (QFileDialog)
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Открыть файл базы данных"),
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

            // заполняем считанную из файла запись о студенте в объект класса
            studentTasks = StudentTasks(
                            string[0], // заносим номер зачётки студента
                            string[1], // заносим фамили И.О.
                            string[2], // заносим номер варианта
                            string[3], // статус задания 1
                            string[4], // оценка за задание 1
                            string[5], // статус задания 2
                            string[6], // оценка за задание 2
                            string[7], // статус задания 3
                            string[8] // оценка за заданние 3
                    );

            // добавляем объект к списку студентов
            studentTasksList += studentTasks;

            // вносим строку в таблицу
            addTableLine(i);


            i++;                                         // добавляем номер строки для следующей записи
        }

        if(stream.status()!= QTextStream::Ok)           // если не удалось считать файл
        {
            QMessageBox::warning(this, "Ошибка", "Ошибка чтения файла");
        }

         file.close();                                  // закрываем файл
    }
}

void MainWindow::on_actionStudentInfoByRecord_triggered()
{
    DialogStudentByRecord dialog(this, studentTasksList);
    dialog.exec();
}

void MainWindow::on_actionStudentsCurrentTask_triggered()
{
    DialogStudentByTask dialog(this, studentTasksList);
    dialog.exec();
}

void MainWindow::on_actionStudentsVariantAndScoreSum_triggered()
{
    DialogStudentByVariantAndSumScore dialog(this, studentTasksList);
    dialog.exec();
}

void MainWindow::on_actionStudentsUnassignedTask_triggered()
{
    DialogStudentByUnassignedTask dialog(this, studentTasksList);
    dialog.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout about;
    about.exec();
}

void MainWindow::addTableLine(int lineNumber)
{
    item = new QTableWidgetItem(studentTasks.getRecordNumber());
    ui->tableWidget->setItem(lineNumber,0,item);

    item = new QTableWidgetItem(studentTasks.getStudentName());
    ui->tableWidget->setItem(lineNumber,1,item);

    item = new QTableWidgetItem(studentTasks.getVariantNumber());
    ui->tableWidget->setItem(lineNumber,2,item);

    item = new QTableWidgetItem(studentTasks.getTask1Status());
    ui->tableWidget->setItem(lineNumber,3,item);

    item = new QTableWidgetItem(studentTasks.getTask1Score());
    ui->tableWidget->setItem(lineNumber,4,item);

    item = new QTableWidgetItem(studentTasks.getTask2Status());
    ui->tableWidget->setItem(lineNumber,5,item);

    item = new QTableWidgetItem(studentTasks.getTask2Score());
    ui->tableWidget->setItem(lineNumber,6,item);

    item = new QTableWidgetItem(studentTasks.getTask3Status());
    ui->tableWidget->setItem(lineNumber,7,item);

    item = new QTableWidgetItem(studentTasks.getTask3Status());
    ui->tableWidget->setItem(lineNumber,8,item);

    item = new QTableWidgetItem(studentTasks.sumScores());
    ui->tableWidget->setItem(lineNumber,9,item);
}


} // namespace alchalov
