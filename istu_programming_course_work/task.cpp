#include "task.h"

namespace alchalov {

    // конструктор умолчаний - задание не выдано, задание не проверено
    Task::Task(): assigned(false), score(0){};

    // если задание не выдано, то выдать задание
    void Task::assign()
    {
        if (!isAssigned()){
            assigned = true;
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
        return assigned;
    };

    // вернуть оценку
    int Task::getScore()
    {
        return score;
    }

} // namespace alchalov
