#include "ShiftData.h"
#include <QTextStream>
#include <QColor>
#include <QCoreApplication>
#include <QDir>

QMap<QDate, QList<ShiftEntry>> globalScheduleData;
QMap<QString, QString> globalEmployeeColors;
QMap<StaffRole, QString> globalRoleAssignments;

QString getDataDir() {
    QString path = QCoreApplication::applicationDirPath() + "/data";

    QDir dir(path);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    return path;
}

QString getScheduleFilePath() {
    return getDataDir() + "/schedule.txt";
}

QString getEmployeesFilePath() {
    return getDataDir() + "/employees.txt";
}

QString getRolesFilePath() {
    return getDataDir() + "/roles.txt";
}

QColor getEmployeeColor(const QString &name) {
    if (globalEmployeeColors.contains(name)) {
        return QColor(globalEmployeeColors[name]);
    }
    return QColor("#78909C");
}

void loadEmployees() {
    QFile file(getEmployeesFilePath());
    globalEmployeeColors.clear();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split("|");
        if (parts.size() >= 2) {
            globalEmployeeColors[parts[0]] = parts[1];
        }
    }
    file.close();
}

void saveEmployees() {
    QFile file(getEmployeesFilePath());
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        QMapIterator<QString, QString> i(globalEmployeeColors);
        while (i.hasNext()) {
            i.next();
            out << i.key() << "|" << i.value() << "\n";
        }
        file.close();
    }
}

void loadRoles() {
    QFile file(getRolesFilePath());
    globalRoleAssignments.clear();

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            QStringList parts = line.split("|");
            if (parts.size() >= 2) {
                int roleIdx = parts[0].toInt();
                QString name = parts[1];
                globalRoleAssignments[(StaffRole)roleIdx] = name;
            }
        }
        file.close();
    }
}

void saveRoles() {
    QFile file(getRolesFilePath());
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        QMapIterator<StaffRole, QString> i(globalRoleAssignments);
        while (i.hasNext()) {
            i.next();
            out << (int)i.key() << "|" << i.value() << "\n";
        }
        file.close();
    }
}

QString getStaffNameByRole(StaffRole role) {
    if (globalRoleAssignments.contains(role)) {
        QString name = globalRoleAssignments[role];
        if (globalEmployeeColors.contains(name)) {
            return name;
        }
    }
    return "";
}