#include "dialogstudentbyvariantandsumscore.h"
#include "ui_dialogstudentbyvariantandsumscore.h"

namespace alchalov {

DialogStudentByVariantAndSumScore::DialogStudentByVariantAndSumScore(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByVariantAndSumScore)
{
    ui->setupUi(this);
}

DialogStudentByVariantAndSumScore::~DialogStudentByVariantAndSumScore()
{
    delete ui;
}

} // namespace alchalov
