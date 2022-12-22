#include "dialogstudentbytask.h"
#include "ui_dialogstudentbytask.h"

namespace alchalov {

DialogStudentByTask::DialogStudentByTask(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByTask)
{
    ui->setupUi(this);
}

DialogStudentByTask::~DialogStudentByTask()
{
    delete ui;
}

} // namespace alchalov
