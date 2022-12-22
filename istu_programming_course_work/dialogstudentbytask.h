#ifndef DIALOGSTUDENTBYTASK_H
#define DIALOGSTUDENTBYTASK_H

#include <QDialog>
#include <QRegExpValidator>
#include <QList>
#include "studenttasks.h"

namespace Ui {
class DialogStudentByTask;
}

namespace alchalov {

class DialogStudentByTask : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStudentByTask(QWidget *parent = nullptr, const QList<StudentTasks>& = {});
    ~DialogStudentByTask();

private:
    Ui::DialogStudentByTask *ui;
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYTASK_H
