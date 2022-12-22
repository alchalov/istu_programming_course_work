#include "dialogstudentbyunassignedtask.h"
#include "ui_dialogstudentbyunassignedtask.h"

namespace alchalov {

DialogStudentByUnassignedTask::DialogStudentByUnassignedTask(QWidget *parent, const QList<StudentTasks>& _studentTasksList) :
    QDialog(parent),
    ui(new Ui::DialogStudentByUnassignedTask)
{
    ui->setupUi(this);
}

DialogStudentByUnassignedTask::~DialogStudentByUnassignedTask()
{
    delete ui;
}

} // namespace alchalov
