#ifndef DIALOGSTUDENTBYVARIANTANDSUMSCORE_H
#define DIALOGSTUDENTBYVARIANTANDSUMSCORE_H

#include <QDialog>
#include <QRegExpValidator>
#include <QList>
#include "studenttasks.h"

namespace Ui {
class DialogStudentByVariantAndSumScore;
}

namespace alchalov {

class DialogStudentByVariantAndSumScore : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStudentByVariantAndSumScore(QWidget *parent = nullptr, const QList<StudentTasks>& = {});
    ~DialogStudentByVariantAndSumScore();

private:
    Ui::DialogStudentByVariantAndSumScore *ui;
    QList<StudentTasks> studentTaskLlist;
    StudentTasks studentTasks;
    bool statusTextChanged();

private slots:
    void on_lineEditVariant_textChanged();
    void on_lineEditSum_textChanged();
    void on_findButton_clicked();
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYVARIANTANDSUMSCORE_H
