#include "update_userbymanager.h"
#include "ui_update_userbymanager.h"

update_userBymanager::update_userBymanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_userBymanager)
{
    ui->setupUi(this);
}

update_userBymanager::~update_userBymanager()
{
    delete ui;
}
