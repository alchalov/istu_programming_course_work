#ifndef TASK_H
#define TASK_H

namespace alchalov {

    // датакласс - информация о задании (статус выдачи, оценка)
    class Task
    {
    public:
        Task(); // создание пустого задания - не выдано, не оценено
        Task(int); // создание задания с оценкой - выдано, оценено

        void assign(); // выдать задание
        void setScore(int); // выставить оценку

        bool isAssigned(); // вернуть статус - задание назначено? да : нет
        int getScore(); // вернуть оценку
    private:
        bool assigned; // статус - задание назначена? да : нет
        int score; // оценка
    };

} // namespace alchalov

#endif // TASK_H
