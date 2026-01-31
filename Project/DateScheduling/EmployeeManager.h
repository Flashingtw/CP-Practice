#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <QDialog>
#include <QListWidget>
#include <QMap>
#include <QComboBox> // 新增

class EmployeeManagerDialog : public QDialog {
    Q_OBJECT
public:
    explicit EmployeeManagerDialog(QWidget *parent = nullptr);

private:
    QListWidget *listWidget;
    // 五個職位的下拉選單
    QComboBox *comboSanchong;
    QComboBox *comboXinzhuang;
    QComboBox *comboBanqiao;
    QComboBox *comboFloater;
    QComboBox *comboSupport;

    void refreshList();
    void updateRoleCombos(); // 更新下拉選單的內容
    void saveRoleConfig();   // 儲存下拉選單的選擇
};

#endif // EMPLOYEEMANAGER_H