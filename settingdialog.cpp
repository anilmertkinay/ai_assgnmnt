#include "settingdialog.hpp"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent,int newPointSize, int pointSize, int linesize, int node) :
    QDialog(parent), m_newPointSize(newPointSize), m_pointSize(pointSize), m_lineSize(linesize), m_node(node),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Ayarlar");
    ui->m_lineEditNewPointSize->setText(QString::number(m_newPointSize));
    ui->m_lineEditPointSize->setText(QString::number(m_pointSize));
    ui->m_lineEditLineSize->setText(QString::number(m_lineSize));
    ui->m_lineEditNode->setText(QString::number(m_node));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::on_m_pushButtonSave_clicked(bool )
{
    if(ui->m_lineEditLineSize->text() == "")
        return;
    if(ui->m_lineEditNewPointSize->text() == "")
        return;
    if(ui->m_lineEditNode->text() == "")
        return;
    if(ui->m_lineEditPointSize->text() == "")
        return;

    done(QDialog::Accepted);
}

void SettingDialog::on_m_pushButtonExit_clicked(bool )
{
    done(QDialog::Rejected);
}

int SettingDialog::newPointSize()
{
    return ui->m_lineEditNewPointSize->text().toInt();
}

int SettingDialog::pointSize()
{
    return ui->m_lineEditPointSize->text().toInt();
}

int SettingDialog::lineSize()
{
    return ui->m_lineEditLineSize->text().toInt();
}

int SettingDialog::node()
{
    return ui->m_lineEditNode->text().toInt();
}
