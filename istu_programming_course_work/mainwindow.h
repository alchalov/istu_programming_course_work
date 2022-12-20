#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QList>

#include "studenttasks.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace alchalov {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;    
    StudentTasks studentTasks;
    QList<StudentTasks> studentTasksList;
    QTableWidgetItem *item;

    void addTableLine(int);

private slots:
    void on_actionOpen_triggered();

    void on_actionStudentInfoByRecord_triggered();
    void on_actionStudentsCurrentTask_triggered();
    void on_actionStudentsVariantAndScoreSum_triggered();
    void on_actionStudentsUnassignedTask_triggered();

    void on_actionAbout_triggered();

};

} // namespace alchalov

#endif // MAINWINDOW_H
