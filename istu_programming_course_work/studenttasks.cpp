#include "studenttasks.h"

namespace alchalov {

    // конструктор пустой записи
    StudentTasks::StudentTasks():
        recordNumber(0),
        studentName(""),
        variantNumber(0),
        tasks({new Task, new Task, new Task}){};

    // конструктор полной записи
    StudentTasks::StudentTasks(
            const int recordNumber,
            const std::string studentName,
            const int variantNumber,
            const std::vector<Task*> tasks):
        recordNumber(recordNumber),
        studentName(studentName),
        variantNumber(variantNumber),
        tasks(tasks) {};

    void StudentTasks::setRecordNumber(const int _recordNumber)
    {
        recordNumber=_recordNumber;
    }

    void StudentTasks::setStudentName(const std::string _studentName)
    {
        studentName=_studentName;
    }

    void StudentTasks::setVariantNumber(const int _variantNumber)
    {
        variantNumber = _variantNumber;
    }

    void StudentTasks::setTasks(const std::vector<Task*> _tasks)
    {
        tasks = _tasks;
    }

    void StudentTasks::setAssignStatusOfTask(const int taskNumber, const bool status)
    {
        tasks[taskNumber]->setStatus(status);
    }

    void StudentTasks::setScoreOfTask(const int taskNumber, const int score)
    {
        tasks[taskNumber]->setScore(score);
    }

    int StudentTasks::getRecordNumber()
    {
        return recordNumber;
    }

    std::string StudentTasks::getStudentName()
    {
        return studentName;
    }

    int StudentTasks::getVariantNumber()
    {
        return variantNumber;
    }

    bool StudentTasks::getTaskAssignStatus(const int taskNumber)
    {
        return tasks[taskNumber]->isAssigned();
    }


    int StudentTasks::getTaskScore(int taskNumber)
    {
         return tasks[taskNumber]->getScore();
    }

} // namespace alchalov
