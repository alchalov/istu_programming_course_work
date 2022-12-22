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
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYVARIANTANDSUMSCORE_H
