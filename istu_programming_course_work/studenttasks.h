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
    void setName(const int);
    void setVariantNumber(const int);
    void setTasks(const std::vector<Task*>);

private:
    int recordNumber;
    std::string studentName;
    int variantNumber;
    std::vector<Task*> tasks;
};

} // namespace alchalov

#endif // STUDENTTASKS_H
