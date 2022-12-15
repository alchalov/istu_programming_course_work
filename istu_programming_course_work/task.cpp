#include "task.h"

namespace alchalov {

// конструктор умолчаний - задание не выдано, задание не проверено
Task::Task(): assignedStatus(false), score(0){};

// установка статуса задания
void Task::setStatus(const bool status)
{
    assignedStatus = status;
}

// если задание не выдано, то выдать задание
void Task::assign()
{
    if (!isAssigned()){
        assignedStatus = true;
    }
};

// выставить или изменить оценку
void Task::setScore(const int assignedScore)
{
    score = assignedScore;
};

// если задание назначено, то выставить или изменить оценку
void Task::assignScore(const int assignedScore)
{
    if (isAssigned())
    {
        setScore(assignedScore);
    }
    else
    {
        // error Задача не была назначена, чтобы выставить оценку
    }
};

// вернуть статус - задание выдано? да : нет
bool Task::isAssigned()
{
    return assignedStatus;
};

// вернуть оценку
int Task::getScore()
{
    return score;
}

} // namespace alchalov
