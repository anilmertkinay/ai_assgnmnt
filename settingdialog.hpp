#ifndef SETTINGDIALOG_HPP
#define SETTINGDIALOG_HPP

#include <QDialog>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent, int newPointSize, int pointSize, int linesize, int node);
    ~SettingDialog();
    int newPointSize();
    int pointSize();
    int lineSize();
    int node();

private slots:
    void on_m_pushButtonSave_clicked(bool);
    void on_m_pushButtonExit_clicked(bool);

private:
    Ui::SettingDialog *ui;
    int m_newPointSize;
    int m_pointSize;
    int m_lineSize;
    int m_node;
};

#endif // SETTINGDIALOG_HPP
