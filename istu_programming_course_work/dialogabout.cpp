#include "dialogabout.h"
#include "ui_dialogabout.h"

namespace alchalov {

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);

    ui->label->setText("<h1>Об авторе</h1>"
                       "<h2>Курсовая работа<br>по программированию</h2>"
                       "<h3>Вариант 6</h3>"
                       "<p>Выполнил: студент гр. ЭВМбз18-1</p>"
                       "<p>Александр Чалов</p>"
                       "<p>Зачётная книжка: №18150642</p>"
                      );
}

DialogAbout::~DialogAbout()
{
    delete ui;
}

} // namespace alchalov
