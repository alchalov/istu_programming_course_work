#include "dialogstudentbyunassignedtask.h"
#include "ui_dialogstudentbyunassignedtask.h"

namespace alchalov {

DialogStudentByUnassignedTask::DialogStudentByUnassignedTask(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByUnassignedTask)
{
    ui->setupUi(this);

    // Создаём валидатор проверки на ввод номера задания
    // с помощью регулярного выражения
    QRegExp regExp("[123]"); // номер задания 1, 2 или 3
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    studentTaskLlist = _studentTasksList;

    ui->tableWidget->clear();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // настраиваем отображения столбцов
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // устанавливаем выделение целой строки
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Устанавливаем названия столбцов
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               <<"Номер\nзачётки"
                                               <<"Фамилия И.О.   "
                                               <<"Номер\nварианта");
}


void DialogStudentByUnassignedTask::on_lineEdit_textChanged()
{
    ui->findButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

void DialogStudentByUnassignedTask::on_findButton_clicked()
{
    QString find = "";
    QTableWidgetItem *item;
    int lineNumber = 0;

    ui->tableWidget->clear();
    // Устанавливаем названия столбцов
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               <<"Номер\nзачётки"
                                               <<"Фамилия И.О.   "
                                               <<"Номер\nварианта");
    find = ui->lineEdit->text();

    switch (find.toInt())
    {
    case 1:
        foreach(studentTasks, studentTaskLlist)
        {
            ui->label2->setText("Студенты которым НЕ выдано задание №1");

            // Ищем студентов, которым НЕ выдано данное задание и заполняем таблицу
            if (studentTasks.getTask1Status() == "0")
            {
                ui->tableWidget->setRowCount(lineNumber+1);
                item = new QTableWidgetItem(studentTasks.getRecordNumber());
                ui->tableWidget->setItem(lineNumber,0,item);
                item = new QTableWidgetItem(studentTasks.getStudentName());
                ui->tableWidget->setItem(lineNumber,1,item);
                item = new QTableWidgetItem(studentTasks.getVariantNumber());
                ui->tableWidget->setItem(lineNumber,2,item);

                ++lineNumber;
            }
        }
        break;

    case 2:
        foreach(studentTasks, studentTaskLlist)
        {
            ui->label2->setText("Студенты которым НЕ выдано задание №2");

            // Ищем студентов, которым НЕ выдано данное задание и заполняем таблицу
            if (studentTasks.getTask2Status() == "0")
            {
                ui->tableWidget->setRowCount(lineNumber+1);
                item = new QTableWidgetItem(studentTasks.getRecordNumber());
                ui->tableWidget->setItem(lineNumber,0,item);
                item = new QTableWidgetItem(studentTasks.getStudentName());
                ui->tableWidget->setItem(lineNumber,1,item);
                item = new QTableWidgetItem(studentTasks.getVariantNumber());
                ui->tableWidget->setItem(lineNumber,2,item);

                ++lineNumber;
            }
        }
        break;
    case 3:
        foreach(studentTasks, studentTaskLlist)
        {
            ui->label2->setText("Студенты которым НЕ выдано задание №3");

            // Ищем студентов, которым НЕ выдано данное задание и заполняем таблицу
            if (studentTasks.getTask3Status() == "0")
            {
                ui->tableWidget->setRowCount(lineNumber+1);
                item = new QTableWidgetItem(studentTasks.getRecordNumber());
                ui->tableWidget->setItem(lineNumber,0,item);
                item = new QTableWidgetItem(studentTasks.getStudentName());
                ui->tableWidget->setItem(lineNumber,1,item);
                item = new QTableWidgetItem(studentTasks.getVariantNumber());
                ui->tableWidget->setItem(lineNumber,2,item);

                ++lineNumber;
            }
        }
        break;

    default:
        break;
    }

}

DialogStudentByUnassignedTask::~DialogStudentByUnassignedTask()
{
    delete ui;
}

} // namespace alchalov
