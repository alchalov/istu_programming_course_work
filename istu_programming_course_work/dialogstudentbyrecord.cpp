#include "dialogstudentbyrecord.h"
#include "ui_dialogstudentbyrecord.h"

namespace alchalov {


DialogStudentByRecord::DialogStudentByRecord(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByRecord)
{
    ui->setupUi(this);

    // Создаём валидатор проверки на ввод номера зачётной книжки
    // с помощью регулярного выражения
    QRegExp regExp("[0-9]{8}"); // номер зачётки должен иметь 8 цифр
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    studentTaskLlist = _studentTasksList;
}

DialogStudentByRecord::~DialogStudentByRecord()
{
    delete ui;
}

void DialogStudentByRecord::on_lineEdit_textChanged()
{
    ui->findButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

void DialogStudentByRecord::on_findButton_clicked()
{
    QString text = "";
    QString find = "";

    find = ui->lineEdit->text();

    // Ищем студента с номером зачётки и выводим информацию о нём
    foreach(studentTasks, studentTaskLlist){
        if (studentTasks.getRecordNumber() == find)
        {
            text.append("Номер зачётки: " + studentTasks.getRecordNumber() + "\n");
            text.append("Фамилия И.О.: " + studentTasks.getStudentName() + "\n");
            text.append("Номер варианта: " + studentTasks.getVariantNumber() + "\n");
            if(studentTasks.getTask1Status() == "0")
            {
                text.append("Задание 1: не выдано \n");
            }
            else
            {
                text.append("Задание 1: выдано \n");
            }
            if(studentTasks.getTask1Score() == "0")
            {
                text.append("Задание 1: не оценено \n");
            }
            else
            {
                text.append("Задание 1: оценено на " + studentTasks.getTask1Score() + "\n");
            }
            if(studentTasks.getTask2Status() == "0")
            {
                text.append("Задание 2: не выдано \n");
            }
            else
            {
                text.append("Задание 2: выдано \n");
            }
            if(studentTasks.getTask2Score() == "0")
            {
                text.append("Задание 2: не оценено \n");
            }
            else
            {
                text.append("Задание 2: оценено на " + studentTasks.getTask2Score() + "\n");
            }
            if(studentTasks.getTask3Status() == "0")
            {
                text.append("Задание 3: не выдано \n");
            }
            else
            {
                text.append("Задание 3: выдано \n");
            }
            if(studentTasks.getTask3Score() == "0")
            {
                text.append("Задание 3: не оценено \n");
            }
            else
            {
                text.append("Задание 3: оценено на " + studentTasks.getTask3Score() + "\n");
            }

            break;
        }
    }

    if(text == "") text.append("Студент не найден!");
    ui->infoLabel->setText(text);
}

} // namespace alchalov

