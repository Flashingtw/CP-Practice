#ifndef SHIFTDATA_H
#define SHIFTDATA_H

#include <QString>
#include <QDate>
#include <QMap>
#include <QList>

struct ShiftEntry {
    QString employeeName;
    QString location;     // "三重", "新莊", "板橋", "休假"
    QString note;
    QString Shifttime;
};

// 定義五個職位角色
enum StaffRole {
    Role_Sanchong = 0,  // 原本的 A (固定三重)
    Role_Xinzhuang,     // 原本的 B (固定新莊)
    Role_Banqiao,       // 原本的 C (固定板橋)
    Role_Floater,       // 原本的 D (主要機動 - 到處代班)
    Role_Support        // 原本的 E (輔助支援 - 幫忙三重與排休)
};

struct WeekQuota {
    QMap<QString, int> remainingRests;
    WeekQuota() {
        // 預設每人每週休2天，這裡之後會根據實際名字初始化
    }
};

extern QMap<QDate, QList<ShiftEntry>> globalScheduleData;
extern QMap<QString, QString> globalEmployeeColors;
extern QMap<StaffRole, QString> globalRoleAssignments;


QString getScheduleFilePath();
QString getEmployeeFilePath();
QString getRolesFilePath(); // 新增路徑

QColor getEmployeeColor(const QString &name);
void loadEmployees();
void saveEmployees();

// 新增：讀取與儲存職位設定
void loadRoles();
void saveRoles();

// 新增：取得某個職位現在是誰 (例如傳入 Role_Sanchong 回傳 "小明")
QString getStaffNameByRole(StaffRole role);

#endif // SHIFTDATA_H