#ifndef STUDENTTASKS_H
#define STUDENTTASKS_H

#include <vector>
#include <string>

#include "task.h"

namespace alchalov {

// датакласс - информация о студенте и выданых ему заданиях
class StudentTasks
{
public:
    StudentTasks();
    StudentTasks(const int, const std::string, const int, const std::vector<Task*>);

    void setRecordNumber(const int);
    void setStudentName(const std::string);
    void setVariantNumber(const int);
    void setTasks(const std::vector<Task*>);
    void setAssignStatusOfTask(const int, const bool);
    void setScoreOfTask(const int, const int);

    int getRecordNumber();
    std::string getStudentName();
    int getVariantNumber();
    bool getAssignStatusOfTask(const int);
    int getScoreOfTask(const int);

private:
    int recordNumber;
    std::string studentName;
    int variantNumber;
    std::vector<Task*> tasks;
};

} // namespace alchalov

#endif // STUDENTTASKS_H
