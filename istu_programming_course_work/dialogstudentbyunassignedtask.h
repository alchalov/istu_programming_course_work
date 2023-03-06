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
    QList<StudentTasks> studentTaskLlist;
    StudentTasks studentTasks;

private slots:
    void on_lineEdit_textChanged();
    void on_findButton_clicked();
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYUNASSIGNEDTASK_H
