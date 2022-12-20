#ifndef DIALOGSTUDENTBYRECORD_H
#define DIALOGSTUDENTBYRECORD_H

#include <QDialog>
#include <QRegExpValidator>
#include <QList>
#include "studenttasks.h"

namespace Ui {
class DialogStudentByRecord;
}

namespace alchalov {

class DialogStudentByRecord : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStudentByRecord(QWidget *parent = nullptr, const QList<StudentTasks>& = {});
    ~DialogStudentByRecord();

private:
    Ui::DialogStudentByRecord *ui;
    QList<StudentTasks> studentTaskLlist;
    StudentTasks studentTasks;

private slots:
    void on_lineEdit_textChanged();
    void on_findButton_clicked();
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYRECORD_H
