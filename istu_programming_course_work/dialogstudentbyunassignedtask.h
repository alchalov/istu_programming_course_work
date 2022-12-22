#ifndef DIALOGSTUDENTBYUNASSIGNEDTASK_H
#define DIALOGSTUDENTBYUNASSIGNEDTASK_H

#include <QDialog>
#include <QRegExpValidator>
#include <QList>
#include "studenttasks.h"

namespace Ui {
class DialogStudentByUnassignedTask;
}

namespace alchalov {

class DialogStudentByUnassignedTask : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStudentByUnassignedTask(QWidget *parent = nullptr, const QList<StudentTasks>& = {});
    ~DialogStudentByUnassignedTask();

private:
    Ui::DialogStudentByUnassignedTask *ui;
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYUNASSIGNEDTASK_H
