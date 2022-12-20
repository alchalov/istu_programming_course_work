#ifndef DIALOGSTUDENTBYRECORD_H
#define DIALOGSTUDENTBYRECORD_H

#include <QDialog>

namespace Ui {
class DialogStudentByRecord;
}

namespace alchalov {

class DialogStudentByRecord : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStudentByRecord(QWidget *parent = nullptr);
    ~DialogStudentByRecord();

private:
    Ui::DialogStudentByRecord *ui;
};

} // namespace alchalov

#endif // DIALOGSTUDENTBYRECORD_H
