#ifndef DIALOGSTUDENTBYTASK_H
#define DIALOGSTUDENTBYTASK_H

#include <QDialog>
#include <QRegExpValidator>
#include <QList>
#include <QTableWidget>
#include <QTableWidgetItem>
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
QList<StudentTasks> studentTaskLlist;
StudentTasks studentTasks;

private slots:
void on_lineEdit_textChanged();
void on_findButton_clicked();

};

} // namespace alchalov

#endif // DIALOGSTUDENTBYTASK_H
