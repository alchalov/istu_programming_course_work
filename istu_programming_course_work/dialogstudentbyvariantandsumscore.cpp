#include "dialogstudentbyvariantandsumscore.h"
#include "ui_dialogstudentbyvariantandsumscore.h"

namespace alchalov {

DialogStudentByVariantAndSumScore::DialogStudentByVariantAndSumScore(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByVariantAndSumScore)
{
    ui->setupUi(this);

    // Создаём валидатор проверки на ввод суммы
    // с помощью регулярного выражения
    QRegExp regExpVariant("[1-9]{1}|[1-9][0-9]"); // номер задания соитит из одной или двух цифр
    ui->lineEditVariant->setValidator(new QRegExpValidator(regExpVariant, this));

    QRegExp regExpSum("[1-9]{1}|[1][0-5]"); // сумма баллов может быть от 1 до 15
    ui->lineEditSum->setValidator(new QRegExpValidator(regExpSum, this));

    studentTaskLlist = _studentTasksList;
}

// Функция проверяет корректно ли заполнены поля
bool DialogStudentByVariantAndSumScore::statusTextChanged()
{
    return (ui->lineEditVariant->hasAcceptableInput()) && (ui->lineEditSum->hasAcceptableInput());
}

// Функции запускающие валидацию при изменении любого поля
void DialogStudentByVariantAndSumScore::on_lineEditVariant_textChanged()
{
    ui->findButton->setEnabled(statusTextChanged());
}

void DialogStudentByVariantAndSumScore::on_lineEditSum_textChanged()
{
    ui->findButton->setEnabled(statusTextChanged());
}


void DialogStudentByVariantAndSumScore::on_findButton_clicked()
{
    ui->listWidget->clear();
    QString variant = ui->lineEditVariant->text();
    QString sum = ui->lineEditSum->text();

    foreach(studentTasks, studentTaskLlist){
        if ((studentTasks.getVariantNumber() == variant) && (studentTasks.sumScores() == sum))
        {
            QListWidgetItem *item = new QListWidgetItem(studentTasks.getStudentName() + ", сумма баллов: " + studentTasks.sumScores());
            ui->listWidget->addItem(item);
        }
    }

}


DialogStudentByVariantAndSumScore::~DialogStudentByVariantAndSumScore()
{
    delete ui;
}

} // namespace alchalov
