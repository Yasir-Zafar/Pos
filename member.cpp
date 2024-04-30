#include "member.h"
#include "ui_member.h"

member::member(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::member)
{
    ui->setupUi(this);
}

member::~member()
{
    delete ui;
}

void member::on_pushButton_clicked()
{
    close();
}


void member::on_pushButton_2_clicked()
{
    close();
}

