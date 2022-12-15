#ifndef TASK_H
#define TASK_H

namespace alchalov {

// датакласс - информация о задании (статус выдачи, оценка)
class Task
{
public:
    Task(); // создание пустого задания - не выдано, не оценено

    void setStatus(const bool);
    void assign(); // выдать задание
    void setScore(const int); // выставить оценку
    void assignScore(const int); // выставить оценку, если задание было выдано

    bool isAssigned(); // вернуть статус - задание назначено? да : нет
    int getScore(); // вернуть оценку
private:
    bool assignedStatus; // статус - задание назначена? да : нет
    int score; // оценка
};

} // namespace alchalov

#endif // TASK_H
