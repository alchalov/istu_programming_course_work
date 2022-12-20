#include "dialogstudentbyrecord.h"
#include "ui_dialogstudentbyrecord.h"

namespace alchalov {
DialogStudentByRecord::DialogStudentByRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStudentByRecord)
{
    ui->setupUi(this);
}

DialogStudentByRecord::~DialogStudentByRecord()
{
    delete ui;
}

} // namespace alchalov

