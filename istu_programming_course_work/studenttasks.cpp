#include "studenttasks.h"

namespace alchalov {

// конструктор по умолчанию - пустая запись
StudentTasks::StudentTasks():
    recordNumber(""),
    studentName(""),
    variantNumber(""),
    task1Status(""), task1Score(""),
    task2Status(""), task2Score(""),
    task3Status(""), task3Score("")
    {};

// конструктор полной информации о студенте
StudentTasks::StudentTasks(
        const QString recordNumber,
        const QString studentName,
        const QString variantNumber,
        const QString task1Status,
        const QString task1Score,
        const QString task2Status,
        const QString task2Score,
        const QString task3Status,
        const QString task3Score):
        recordNumber(recordNumber),
        studentName(studentName),
        variantNumber(variantNumber),
        task1Status(task1Status), task1Score(task1Score),
        task2Status(task2Status), task2Score(task2Score),
        task3Status(task3Status), task3Score(task3Score)
        {};

void StudentTasks::setRecordNumber(const QString _recordNumber)
{
    recordNumber=_recordNumber;
}

void StudentTasks::setStudentName(const QString _studentName)
{
    studentName=_studentName;
}

void StudentTasks::setVariantNumber(const QString _variantNumber)
{
    variantNumber = _variantNumber;
}

void StudentTasks::setTask1Status(const QString _taskStatus)
{
    task1Status = _taskStatus;
}

void StudentTasks::setTask1Score(const QString _score)
{
    task1Score = _score;
}

void StudentTasks::setTask2Status(const QString _taskStatus)
{
    task1Status = _taskStatus;
}

void StudentTasks::setTask2Score(const QString _score)
{
    task1Score = _score;
}

void StudentTasks::setTask3Status(const QString _taskStatus)
{
    task1Status = _taskStatus;
}

void StudentTasks::setTask3Score(const QString _score)
{
    task1Score = _score;
}

QString StudentTasks::getRecordNumber()
{
    return recordNumber;
}

QString StudentTasks::getStudentName()
{
    return studentName;
}

QString StudentTasks::getVariantNumber()
{
    return variantNumber;
}

QString StudentTasks::getTask1Status()
{
    return task1Status;
}

QString StudentTasks::getTask1Score()
{
    return task1Score;
}

QString StudentTasks::getTask2Status()
{
    return task2Status;
}

QString StudentTasks::getTask2Score()
{
    return task2Score;
}

QString StudentTasks::getTask3Status()
{
    return task3Status;
}

QString StudentTasks::getTask3Score()
{
    return task3Score;
}

QString StudentTasks::sumScores(){

    int sum = getTask1Score().toInt() + getTask2Score().toInt() + getTask3Score().toInt();
    QString sumScores = QStringLiteral("%1").arg(sum);
    return sumScores;
}

} // namespace alchalov
