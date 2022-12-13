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

} // namespace alchalov

