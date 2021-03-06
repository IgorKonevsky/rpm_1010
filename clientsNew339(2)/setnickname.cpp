
#include "setnickname.h"
#include "ui_setnickname.h"

SetNickName::SetNickName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetNickName)
{
    ui->setupUi(this);
}

SetNickName::~SetNickName()
{
    delete ui;
}


void SetNickName::on_pushButton_clicked()
{
    hostIP = ui->HostIpLine->text();
    hostPort = ui->hostPort->text();
    nickName = ui->NicknameLine->text();
    accept();
}
