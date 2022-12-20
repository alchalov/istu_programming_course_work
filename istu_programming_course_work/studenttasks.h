#ifndef STUDENTTASKS_H
#define STUDENTTASKS_H

#include <QString>

namespace alchalov {

// датакласс - информация о студенте и выданых ему заданиях
class StudentTasks
{
public:
    StudentTasks();
    StudentTasks(const QString, // номер зачётки
                 const QString, // фамилия И.О.
                 const QString, // вариант
                 const QString, // статус задания 1
                 const QString, // оценка за задание 1
                 const QString, // статус задания 2
                 const QString, // оценка за задание 2
                 const QString, // статус задания 3
                 const QString); // оценка за задание 3
    // сеттеры
    void setRecordNumber(const QString);
    void setStudentName(const QString);
    void setVariantNumber(const QString);
    void setTask1Status(const QString);
    void setTask2Status(const QString);
    void setTask3Status(const QString);
    void setTask1Score(const QString);
    void setTask2Score(const QString);
    void setTask3Score(const QString);

    // геттеры
    QString getRecordNumber();
    QString getVariantNumber();
    QString getStudentName();
    QString getTask1Status();
    QString getTask2Status();
    QString getTask3Status();
    QString getTask1Score();
    QString getTask2Score();
    QString getTask3Score();

    // методы
    QString sumScores(); // подсчёт суммы очков

private:
    // аттрибуты класса (поля для хранения данных)
    QString recordNumber;
    QString studentName;
    QString variantNumber;
    QString task1Status;
    QString task1Score;
    QString task2Status;
    QString task2Score;
    QString task3Status;
    QString task3Score;

};

} // namespace alchalov

#endif // STUDENTTASKS_H
