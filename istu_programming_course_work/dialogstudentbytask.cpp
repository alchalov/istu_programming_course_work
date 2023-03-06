#include "dialogstudentbytask.h"
#include "ui_dialogstudentbytask.h"

namespace alchalov {

DialogStudentByTask::DialogStudentByTask(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByTask)
{
    ui->setupUi(this);

    // Создаём валидатор проверки на ввод номера задания
    // с помощью регулярного выражения
    QRegExp regExp("[0-9]"); //
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    studentTaskLlist = _studentTasksList;

    ui->tableWidget->clear();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // настраиваем отображения столбцов
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // устанавливаем выделение целой строки
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Устанавливаем названия столбцов
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               <<"Номер\nзачётки"
                                               <<"Фамилия И.О.   "
                                               <<"Номер\nварианта"
                                               <<"Оценка\nза\nзадание");

}

void DialogStudentByTask::on_lineEdit_textChanged()
{
    ui->findButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

void DialogStudentByTask::on_findButton_clicked()
{
    QString find = "";
    QTableWidgetItem *item;
    int lineNumber = 0;

    ui->tableWidget->clear();
    // Устанавливаем названия столбцов
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               <<"Номер\nзачётки"
                                               <<"Фамилия И.О.   "
                                               <<"Номер\nварианта"
                                               <<"Оценка\nза\nзадание");
    find = ui->lineEdit->text();

    // Ищем студентов, которые выполнили задания и заполняем таблицу
    switch (find.toInt())
    {
    case 1:
        foreach(studentTasks, studentTaskLlist)
        {
            ui->label2->setText("Студенты выполнившие задание №1");


            if (studentTasks.getTask1Status() == "1")
            {
                ui->tableWidget->setRowCount(lineNumber+1);
                item = new QTableWidgetItem(studentTasks.getRecordNumber());
                ui->tableWidget->setItem(lineNumber,0,item);
                item = new QTableWidgetItem(studentTasks.getStudentName());
                ui->tableWidget->setItem(lineNumber,1,item);
                item = new QTableWidgetItem(studentTasks.getVariantNumber());
                ui->tableWidget->setItem(lineNumber,2,item);
                item = new QTableWidgetItem(studentTasks.getTask1Score());
                ui->tableWidget->setItem(lineNumber,3,item);
                ++lineNumber;
            }
        }
        break;

    case 2:
        foreach(studentTasks, studentTaskLlist)
        {
            ui->label2->setText("Студенты выполнившие задание №2");

            if (studentTasks.getTask2Status() == "1")
            {
                ui->tableWidget->setRowCount(lineNumber+1);
                item = new QTableWidgetItem(studentTasks.getRecordNumber());
                ui->tableWidget->setItem(lineNumber,0,item);
                item = new QTableWidgetItem(studentTasks.getStudentName());
                ui->tableWidget->setItem(lineNumber,1,item);
                item = new QTableWidgetItem(studentTasks.getVariantNumber());
                ui->tableWidget->setItem(lineNumber,2,item);
                item = new QTableWidgetItem(studentTasks.getTask1Score());
                ui->tableWidget->setItem(lineNumber,3,item);
                ++lineNumber;
            }
        }
        break;
    case 3:
        foreach(studentTasks, studentTaskLlist)
        {
            ui->label2->setText("Студенты выполнившие задание №3");

            if (studentTasks.getTask3Status() == "1")
            {
                ui->tableWidget->setRowCount(lineNumber+1);
                item = new QTableWidgetItem(studentTasks.getRecordNumber());
                ui->tableWidget->setItem(lineNumber,0,item);
                item = new QTableWidgetItem(studentTasks.getStudentName());
                ui->tableWidget->setItem(lineNumber,1,item);
                item = new QTableWidgetItem(studentTasks.getVariantNumber());
                ui->tableWidget->setItem(lineNumber,2,item);
                item = new QTableWidgetItem(studentTasks.getTask1Score());
                ui->tableWidget->setItem(lineNumber,3,item);
                ++lineNumber;
            }
        }
        break;

    default:
        break;
    }
}

DialogStudentByTask::~DialogStudentByTask()
{
    delete ui;
}

} // namespace alchalov
