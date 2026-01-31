#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QDateEdit>
#include <QDate>
#include <QStack>

// ★★★ 關鍵修改 1：加入這行，因為 WeekQuota 定義在這裡面 ★★★
#include "ShiftData.h"

// ★★★ 關鍵修改 2：把原本在這裡的 struct WeekQuota { ... }; 刪掉！ ★★★
// (因為 ShiftData.h 裡面已經有了，不能重複寫)

class CalendarWindow : public QMainWindow {
    Q_OBJECT

public:
    CalendarWindow(QWidget *parent = nullptr);
    ~CalendarWindow();

private slots:
    void refreshCalendar();
    void saveDataTxt();
    void loadDataTxt(bool silent = false);
    void showAutoScheduleOptions();
    void checkScheduleCompliance();
    void clearCurrentMonthSchedule();
    void undoLastAction();

private:
    QTableWidget *calendarTable;
    QDateEdit *monthPicker;

    void createDayCell(int row, int col, QDate date);

    // 自動排班相關的輔助函式
    void runOriginalRuleSchedule();
    void runWeeklyBatchSchedule();
    void processSingleWeek(QDate weekStart, QDate weekEnd, QDate monthStart, QMap<QString, int> &consecutiveDays);

    // 因為上面 include 了 ShiftData.h，這裡就能認得 WeekQuota 了
    QString getPersonWithMostQuota(WeekQuota &quota, QStringList candidates);

    void assignLocationsForDay(QDate date, QSet<QString> resting);
    QStack<QMap<QDate, QList<ShiftEntry>>> undoStack;

    // ★★★ 新增：紀錄歷史的輔助函式 ★★★
    void recordUndo();
};

#endif // CALENDARWINDOW_H