#include "CalendarWindow.h"
#include "ShiftData.h"
#include "ScheduleDelegate.h"
#include "DayEditorDialog.h"
#include "EmployeeManager.h"
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QDateEdit>
#include <QTableWidget>
#include <QTextStream>
#include <random>
#include <QFile>
#include <QSet>

CalendarWindow::CalendarWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowIcon(QIcon(":/app_icon.ico"));
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *topBar = new QHBoxLayout();

    topBar->setContentsMargins(8, 0, 8, 0);
    topBar->setSpacing(5);
    QString btnStyle =
        "QPushButton {"
        "   background-color: white;"
        "   border: 1px solid #CCCCCC;"
        "   border-radius: 3px;"
        "   font-weight: bold;"
        "   font-size: 11pt;"
        "   color: #555555;"
        "   padding: 0px;"
        "}"
        "QPushButton:hover { background-color: #F5F5F5; }"
        "QPushButton:pressed { background-color: #E0E0E0; }"
        "QPushButton:focus { outline: none; }";

    QPushButton *menuBtn = new QPushButton("☰");
    menuBtn->setFixedSize(30, 26);
    menuBtn->setFocusPolicy(Qt::NoFocus);
    menuBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   border: none;"
        "   font-size: 15pt;"
        "   color: #555555;"
        "   border-radius: 3px;"
        "   padding-bottom: 2px;"
        "}"
        "QPushButton:hover { background-color: rgba(0,0,0,0.05); }"

        "QPushButton::menu-indicator {"
        "   image: none;"
        "   width: 0px;"
        "}"
    );

    QMenu *mainMenu = new QMenu(this);
    QAction *actSave = mainMenu->addAction("💾 儲存排班");
    QAction *actLoad = mainMenu->addAction("📂 讀取排班");
    mainMenu->addSeparator();
    QAction *actEmp = mainMenu->addAction("👥 員工管理");
    mainMenu->addSeparator();
    QAction *actAuto = mainMenu->addAction("⚙️ 自動排班");
    menuBtn->setMenu(mainMenu);

    topBar->addWidget(menuBtn);

    topBar->addSpacing(5);
    QLabel *labelDate = new QLabel("📅");
    labelDate->setStyleSheet("color: #333333; font-size: 11pt;");
    topBar->addWidget(labelDate);

    monthPicker = new QDateEdit(QDate::currentDate());
    monthPicker->setDisplayFormat("yyyy-MM");
    monthPicker->setReadOnly(true);
    monthPicker->setFocusPolicy(Qt::NoFocus);
    monthPicker->setButtonSymbols(QAbstractSpinBox::NoButtons);
    monthPicker->setAttribute(Qt::WA_TransparentForMouseEvents);

    monthPicker->setStyleSheet(
        "QDateEdit {"
        "   background-color: white;"
        "   border: 1px solid #CCCCCC;"
        "   border-radius: 3px;"
        "   padding-left: 2px;"
        "   color: #333333;"
        "   font-size: 11pt;"
        "   font-weight: bold;"
        "}"
        "QDateEdit::drop-down { border: none; width: 18px; }"
        "QDateEdit::down-arrow { width: 10px; height: 10px; }"
    );
    topBar->addWidget(monthPicker);

    QPushButton *prevBtn = new QPushButton("◀");
    QPushButton *nextBtn = new QPushButton("▶");

    prevBtn->setFixedSize(26, 26);
    nextBtn->setFixedSize(26, 26);

    prevBtn->setFocusPolicy(Qt::NoFocus);
    nextBtn->setFocusPolicy(Qt::NoFocus);
    prevBtn->setStyleSheet(btnStyle);
    nextBtn->setStyleSheet(btnStyle);

    topBar->addWidget(prevBtn);
    topBar->addWidget(nextBtn);

    // ★★★ 新增：清空本月按鈕 ★★★
    QPushButton *clearMonthBtn = new QPushButton("🗑️ 清空本月");
    clearMonthBtn->setFixedSize(90, 26);
    clearMonthBtn->setFocusPolicy(Qt::NoFocus);
    clearMonthBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #F44336;" // 紅色
        "   color: white;"
        "   border: none;"
        "   border-radius: 3px;"
        "   font-weight: bold;"
        "   font-size: 10pt;"
        "}"
        "QPushButton:hover { background-color: #D32F2F; }"
        "QPushButton:pressed { background-color: #B71C1C; }"
    );
    QPushButton *checkBtn = new QPushButton(" ⚠ 檢查合規");
    checkBtn->setFixedSize(90, 26);
    checkBtn->setFocusPolicy(Qt::NoFocus);
    checkBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #FF9800;" // 橘色警告色
        "   color: white;"
        "   border: none;"
        "   border-radius: 3px;"
        "   font-weight: bold;"
        "   font-size: 10pt;"
        "   font-color: #FFFFFF;"
        "}"
        "QPushButton:hover { background-color: #F57C00; }"
        "QPushButton:pressed { background-color: #EF6C00; }"
    );
    // 在 CalendarWindow 建構子中...

    // ... (原本的檢查按鈕) ...

    // ★★★ 新增：上一步按鈕 ★★★
    QPushButton *undoBtn = new QPushButton("↩️ 上一步");
    undoBtn->setFixedSize(90, 26);
    undoBtn->setFocusPolicy(Qt::NoFocus);
    // 設定樣式 (稍微不同色以示區別，例如紫色或灰色)
    undoBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #607D8B;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 3px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover { background-color: #546E7A; }"
        "QPushButton:pressed { background-color: #455A64; }"
    );
    topBar->addWidget(undoBtn);
    connect(undoBtn, &QPushButton::clicked, this, &CalendarWindow::undoLastAction);
    topBar->addWidget(checkBtn);
    connect(checkBtn, &QPushButton::clicked, this, &CalendarWindow::checkScheduleCompliance);
    topBar->addWidget(clearMonthBtn);
    connect(clearMonthBtn, &QPushButton::clicked, this, &CalendarWindow::clearCurrentMonthSchedule);

    topBar->addStretch();
    mainLayout->addLayout(topBar);

    calendarTable = new QTableWidget(6, 7);
    mainLayout->addWidget(calendarTable);
    calendarTable->setSelectionMode(QAbstractItemView::NoSelection);
    calendarTable->setFocusPolicy(Qt::NoFocus);
    calendarTable->setItemDelegate(new ScheduleDelegate(this));

    QStringList weekDays = {"週一", "週二", "週三", "週四", "週五", "週六", "週日"};
    calendarTable->setHorizontalHeaderLabels(weekDays);
    calendarTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    calendarTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    calendarTable->verticalHeader()->setVisible(false);
    calendarTable->setStyleSheet(
        "QTableWidget {"
        "   gridline-color: black;"
        "   border: 1px solid black;"
        "   outline: 0;"
        "}"
        "QTableWidget::item:focus { border: none; outline: none; }"
        "QHeaderView::section {"
        "   background-color: #E0E0E0;"
        "   color: black;"
        "   border: 1px solid black;"
        "   font-weight: bold;"
        "}"
    );

    connect(actSave, &QAction::triggered, this, &CalendarWindow::saveDataTxt);
    connect(actLoad, &QAction::triggered, this, &CalendarWindow::loadDataTxt);
    connect(actEmp, &QAction::triggered, [this](){
        EmployeeManagerDialog dlg(this);
        dlg.exec();
        refreshCalendar();
    });
    connect(actAuto, &QAction::triggered, this, &CalendarWindow::showAutoScheduleOptions);

    connect(monthPicker, &QDateEdit::dateChanged, this, [this](QDate){
        refreshCalendar();
    });

    connect(prevBtn, &QPushButton::clicked, [this](){
        monthPicker->setDate(monthPicker->date().addMonths(-1));
    });
    connect(nextBtn, &QPushButton::clicked, [this](){
        monthPicker->setDate(monthPicker->date().addMonths(1));
    });

    connect(calendarTable, &QTableWidget::cellClicked, [this](int row, int col){
        QTableWidgetItem *item = calendarTable->item(row, col);
        if (item) {
            QDate date = item->data(Qt::UserRole).toDate();
            if (date.isValid()) {
                DayEditorDialog dialog(date, this);
                if (dialog.exec() == QDialog::Accepted) {
                    recordUndo();
                    globalScheduleData[date] = dialog.getResult();
                    refreshCalendar();
                }
            }
        }
    });

    loadEmployees();
    loadRoles();
    loadDataTxt(true);

    refreshCalendar();
    resize(1200, 720);
}

CalendarWindow::~CalendarWindow() {}

// ★★★ 新增函式：清空本月排班 ★★★
void CalendarWindow::clearCurrentMonthSchedule() {

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "清空確認",
                                  "確定要清空本月份的所有排班資料嗎？\n(此動作不會立即存檔，需手動按儲存)",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }
    recordUndo();
    // 2. 執行清空邏輯 (只操作記憶體)
    QDate currentDate = monthPicker->date();
    int daysInMonth = currentDate.daysInMonth();

    for (int day = 1; day <= daysInMonth; ++day) {
        QDate targetDate(currentDate.year(), currentDate.month(), day);
        if (globalScheduleData.contains(targetDate)) {
            globalScheduleData.remove(targetDate);
        }
    }

    // 3. 刷新畫面
    refreshCalendar();


    QMessageBox::information(this, "通知", "本月資料已清空");
}

void CalendarWindow::refreshCalendar() {
    calendarTable->clearContents();

    QDate selectedDate = monthPicker->date();
    QDate firstDayOfMonth(selectedDate.year(), selectedDate.month(), 1);
    int startDayOfWeek = firstDayOfMonth.dayOfWeek();
    int offset = startDayOfWeek - 1;

    int daysInMonth = selectedDate.daysInMonth();
    int currentDay = 1;

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            int cellIndex = row * 7 + col;

            QTableWidgetItem *item = new QTableWidgetItem();

            if (cellIndex >= offset && currentDay <= daysInMonth) {
                QDate cellDate(selectedDate.year(), selectedDate.month(), currentDay);
                createDayCell(row, col, cellDate);
                currentDay++;
            } else {
                item->setFlags(Qt::NoItemFlags);
                item->setBackground(QColor("#f5f5f5"));
                calendarTable->setItem(row, col, item);
            }
        }
    }
}

void CalendarWindow::createDayCell(int row, int col, QDate date) {
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setData(Qt::UserRole, date);
    item->setText(QString::number(date.day()));
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    calendarTable->setItem(row, col, item);
}

void CalendarWindow::saveDataTxt() {
    saveEmployees();
    QString path = getScheduleFilePath();
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setGenerateByteOrderMark(true);
        QMapIterator<QDate, QList<ShiftEntry>> i(globalScheduleData);
        while (i.hasNext()) {
            i.next();
            QDate date = i.key();
            for(const auto& entry : i.value()) {
                out << date.toString("yyyy-MM-dd") << "|" << entry.employeeName << "|" << entry.location << "\n";
            }
        }
        file.close();
        QMessageBox::information(this, "成功", "已儲存"); // 存檔頻繁時不建議一直跳窗
    }
}

void CalendarWindow::loadDataTxt(bool silent) {
    loadEmployees();
    QString path = getScheduleFilePath();
    QFile file(path);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    globalScheduleData.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() >= 3) {
            QDate date = QDate::fromString(parts[0], "yyyy-MM-dd");
            if (date.isValid()) {
                globalScheduleData[date].append(ShiftEntry{parts[1], parts[2], ""});
            }
        }
    }
    file.close();
    refreshCalendar();
    if (!silent) {
        QMessageBox::information(this, "系統通知", "✅ 讀取成功！\n排班資料已載入完成。");
    }
}

void CalendarWindow::showAutoScheduleOptions() {
    QString pSanchong = getStaffNameByRole(Role_Sanchong);
    QString pXinzhuang = getStaffNameByRole(Role_Xinzhuang);
    QString pBanqiao = getStaffNameByRole(Role_Banqiao);
    QString pFloater = getStaffNameByRole(Role_Floater);
    QString pSupport = getStaffNameByRole(Role_Support);

    QStringList required = {pSanchong, pXinzhuang, pBanqiao, pFloater, pSupport};
    QStringList roleNames = {"固定三重", "固定新莊", "固定板橋", "機動組", "支援組"};

    for(int i = 0; i < required.size(); ++i) {
        QString name = required[i];

        if (name.isEmpty() || name == "Unknown") {
            QMessageBox::warning(this, "無法排班",
                QString("職位「%1」尚未設定人員！\n請去「員工管理」設定。").arg(roleNames[i]));
            return;
        }

        if(!globalEmployeeColors.contains(name)) {
            QMessageBox::warning(this, "無法排班",
                QString("職位「%1」設定的人員是「%2」，但在員工名單找不到此人。\n\n請去「員工管理」重新儲存設定。").arg(roleNames[i]).arg(name));
            return;
        }
    }

    bool hasManualVacation = false;
    QDate currentDate = monthPicker->date();
    int daysInMonth = currentDate.daysInMonth();

    for (int day = 1; day <= daysInMonth; ++day) {
        QDate today(currentDate.year(), currentDate.month(), day);
        if (globalScheduleData.contains(today)) {
            for (const auto &entry : globalScheduleData[today]) {
                if (entry.location == "休假") {
                    hasManualVacation = true;
                    break;
                }
            }
        }
    }

    if (hasManualVacation) {
        QMessageBox::information(this, "排休優先", "偵測到手動休假，執行週次排班");
        runWeeklyBatchSchedule();

    } else {
        QMessageBox::information(this, "規則排班", "無手動休假，執行規則排班");
        runOriginalRuleSchedule();
    }
}

void CalendarWindow::runOriginalRuleSchedule() {
    QString pSanchong = getStaffNameByRole(Role_Sanchong);
    QString pXinzhuang = getStaffNameByRole(Role_Xinzhuang); // B
    QString pBanqiao = getStaffNameByRole(Role_Banqiao);     // C
    QString pFloater = getStaffNameByRole(Role_Floater);
    QString pSupport = getStaffNameByRole(Role_Support);

    QDate currentDate = monthPicker->date();
    int daysInMonth = currentDate.daysInMonth();

    // 1. 取得手動排休
    QMap<int, QSet<QString>> manualVacations;
    for (int day = 1; day <= daysInMonth; ++day) {
        QDate today(currentDate.year(), currentDate.month(), day);
        if (globalScheduleData.contains(today)) {
            for (const auto &entry : globalScheduleData[today]) {
                if (entry.location == "休假") manualVacations[day].insert(entry.employeeName);
            }
        }
    }

    // 變數初始化
    QMap<QString, int> consecutiveDays;
    QStringList allStaff = {pSanchong, pXinzhuang, pBanqiao, pFloater, pSupport};
    for(auto &s : allStaff) consecutiveDays[s] = 0;

    for (int day = 1; day <= daysInMonth; ++day) {
        QDate today(currentDate.year(), currentDate.month(), day);
        int dayOfWeek = today.dayOfWeek();

        // 這裡不需要任何切換邏輯了，因為整個月規則都一樣

        QList<ShiftEntry> shifts;
        QSet<QString> todaysRequests = manualVacations[day];
        QSet<QString> workingToday;

        auto canWork = [&](QString name) -> bool {
            if (todaysRequests.contains(name)) return false;
            if (workingToday.contains(name)) return false;

            // 回復正常的 6 天限制 (因為固定休假模式下，最多只會連上 5 天，不會超標)
            if (consecutiveDays[name] >= 6) return false;

            return true;
        };

        // --- 三重 (維持不變) ---
        QString targetTriple = pSanchong;
        if (dayOfWeek == 3) targetTriple = pSupport; // 週三 E 支援
        else if (dayOfWeek == 2) targetTriple = pFloater; // 週二 D 支援

        QString actualTriple = "";
        if (canWork(targetTriple)) actualTriple = targetTriple;
        else {
            if (targetTriple != pFloater && canWork(pFloater)) actualTriple = pFloater;
            else actualTriple = "(缺人)";
        }
        if (actualTriple != "(缺人)") workingToday.insert(actualTriple);
        shifts.append(ShiftEntry{actualTriple, "三重", ""});

        // --- 新莊 (B) ---
        // 規則：整個月都固定休「週三、週四」
        bool bIsFixedOff = false;
        if (dayOfWeek == 3 || dayOfWeek == 4) {
            bIsFixedOff = true;
        }

        QString targetXinZhuang = bIsFixedOff ? "" : pXinzhuang;
        QString actualXinZhuang = "";

        if (targetXinZhuang == pXinzhuang) {
            if (canWork(pXinzhuang)) actualXinZhuang = pXinzhuang;
            else {
                if (canWork(pFloater)) actualXinZhuang = pFloater;
                else actualXinZhuang = "(缺人)";
            }
        } else {
            // B 休假，找機動
            if (canWork(pFloater)) actualXinZhuang = pFloater;
            else actualXinZhuang = "(缺人)";
        }
        if (actualXinZhuang != "(缺人)") workingToday.insert(actualXinZhuang);
        shifts.append(ShiftEntry{actualXinZhuang, "新莊", ""});

        // --- 板橋 (C) ---
        // 規則：整個月都固定休「週五、週六」
        bool cIsFixedOff = false;
        if (dayOfWeek == 5 || dayOfWeek == 6) {
            cIsFixedOff = true;
        }

        QString targetBanqiao = cIsFixedOff ? "" : pBanqiao;
        QString actualBanqiao = "";

        if (targetBanqiao == pBanqiao) {
            if (canWork(pBanqiao)) actualBanqiao = pBanqiao;
            else {
                if (canWork(pFloater)) actualBanqiao = pFloater;
                else actualBanqiao = "(缺人)";
            }
        } else {
            // C 休假，找機動
            if (canWork(pFloater)) actualBanqiao = pFloater;
            else actualBanqiao = "(缺人)";
        }
        if (actualBanqiao != "(缺人)") workingToday.insert(actualBanqiao);
        shifts.append(ShiftEntry{actualBanqiao, "板橋", ""});

        // --- 結算 ---
        for (const QString &person : allStaff) {
            if (workingToday.contains(person)) {
                consecutiveDays[person]++;
            } else {
                consecutiveDays[person] = 0;
                if (person != pSupport) {
                    shifts.append(ShiftEntry{person, "休假", ""});
                }
            }
        }
        globalScheduleData[today] = shifts;
    }
    refreshCalendar();
}

void CalendarWindow::runWeeklyBatchSchedule() {
    // 1. 建立復原點
    recordUndo();

    // 2. 定義時間範圍：本月第一天到最後一天
    QDate startDate = monthPicker->date();
    QDate firstDayOfMonth(startDate.year(), startDate.month(), 1);
    QDate lastDayOfMonth = firstDayOfMonth.addMonths(1).addDays(-1);

    // 3. 定義週次迭代：從「本月第一週的週一」開始，直到「包含本月最後一天的該週週日」
    //    (這樣才能確保完整的週休二日計算)
    QDate currentWeekStart = firstDayOfMonth.addDays(-(firstDayOfMonth.dayOfWeek() - 1));

    // 4. 初始化員工與連續上班狀態
    QString pA = getStaffNameByRole(Role_Sanchong);
    QString pB = getStaffNameByRole(Role_Xinzhuang);
    QString pC = getStaffNameByRole(Role_Banqiao);
    QString pD = getStaffNameByRole(Role_Floater);
    QString pE = getStaffNameByRole(Role_Support);
    QStringList allStaff = {pA, pB, pC, pD, pE};

    // 追蹤每個人目前的「連續上班天數」
    QMap<QString, int> consecutiveDays;
    for(const QString &p : allStaff) consecutiveDays[p] = 0;

    // ★ 初始化：往回查上個月底的狀態
    // 從 currentWeekStart 的前一天開始往回看，直到遇到休假
    QDate checkDate = currentWeekStart.addDays(-1);
    for(const QString &p : allStaff) {
        int days = 0;
        // 往回檢查最多 7 天 (超過 7 天都沒休假早就違規了，算 7 就好)
        for (int i = 0; i < 7; ++i) {
            QDate d = checkDate.addDays(-i);
            bool isWorking = false;
            if (globalScheduleData.contains(d)) {
                for(const auto &entry : globalScheduleData[d]) {
                    // 如果有排班且不是休假，視為上班
                    if (entry.employeeName == p && entry.location != "休假") {
                        isWorking = true;
                        break;
                    }
                }
            }
            if (isWorking) days++;
            else break; // 遇到休假或無資料停止
        }
        consecutiveDays[p] = days;
    }

    // 5. 逐週處理
    while (currentWeekStart <= lastDayOfMonth) {
        QDate currentWeekEnd = currentWeekStart.addDays(6);

        // 呼叫單週處理邏輯 (會更新 consecutiveDays)
        processSingleWeek(currentWeekStart, currentWeekEnd, firstDayOfMonth, consecutiveDays);

        // 前進下一週
        currentWeekStart = currentWeekStart.addDays(7);
    }

    refreshCalendar();
    QMessageBox::information(this, "排班完成", "已依據「做六休一」與「週休二日」規則重新排班。\n並已保留您手動設定的休假。");
}
void CalendarWindow::processSingleWeek(QDate weekStart, QDate weekEnd, QDate monthStart, QMap<QString, int> &consecutiveDays) {
    QString pA = getStaffNameByRole(Role_Sanchong);
    QString pB = getStaffNameByRole(Role_Xinzhuang);
    QString pC = getStaffNameByRole(Role_Banqiao);
    QString pD = getStaffNameByRole(Role_Floater);

    QStringList mainStaff = {pA, pB, pC, pD};

    // 1. 偵測歷史與設定模式 (保持不變)
    bool hasHistory = false;
    if (weekStart < monthStart) {
        for (QDate d = weekStart; d < monthStart; d = d.addDays(1)) {
            if (globalScheduleData.contains(d)) { hasHistory = true; break; }
        }
    }
    int validDays = 0;
    for (QDate d = weekStart; d <= weekEnd; d = d.addDays(1)) {
        if (d >= monthStart && d.month() == monthStart.month()) validDays++;
    }
    bool useStrictMode = (validDays >= 5 || hasHistory);
    int targetRestPerPerson = useStrictMode ? 2 : 1;

    // 2. 初始化與讀取手動休假 (保持不變)
    QMap<QDate, QSet<QString>> dailyRestPlan;
    QMap<QString, int> staffRestCount;
    for(const QString &p : mainStaff) staffRestCount[p] = 0;

    for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
        dailyRestPlan[date] = QSet<QString>();
        if (globalScheduleData.contains(date)) {
            for (const auto &entry : globalScheduleData[date]) {
                if (entry.location == "休假" && mainStaff.contains(entry.employeeName)) {
                    dailyRestPlan[date].insert(entry.employeeName);
                }
            }
        }
        for (const QString &p : dailyRestPlan[date]) staffRestCount[p]++;
    }

    // 3. 嚴格模式排班
    if (useStrictMode) {

        // --- (A) 決定「雙人休假日」 - ★ 修正邏輯 ---
        bool doubleDayAssigned = false;

        // 檢查手動排班是否已經有雙休
        for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
            if (dailyRestPlan[date].size() >= 2) {
                doubleDayAssigned = true;
                break;
            }
        }

        if (!doubleDayAssigned) {
            // 需要建立一個雙休日
            QDate bestDate;
            QString partner = "";
            bool attachToManualA = false; // 是否掛載在 A 的手動假上

            // 情況 1: A 還有額度，我們找一個空日子建立全新的 A+Partner
            if (staffRestCount[pA] < 2) {
                int bestScore = -1;
                for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
                    if (date < monthStart || date.month() != monthStart.month()) continue;
                    if (dailyRestPlan[date].size() > 0) continue; // 找空位

                    bool canB = (staffRestCount[pB] < 2);
                    bool canC = (staffRestCount[pC] < 2);
                    if (!canB && !canC) continue;

                    int score = consecutiveDays[pA] + (date.toJulianDay() - weekStart.toJulianDay());
                    if (score > bestScore) {
                        bestScore = score;
                        bestDate = date;
                        partner = canB ? pB : pC;
                    }
                }
            }
            // 情況 2: A 額度滿了 (手動排滿)，我們必須把 B 或 C 塞進 A 已經休假的日子
            // 否則天數會不夠用 (這就是解決 D 少休一天的關鍵)
            else {
                for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
                    // 找 A 有休假，且只有 A 一個人的日子
                    if (dailyRestPlan[date].contains(pA) && dailyRestPlan[date].size() == 1) {
                        bool canB = (staffRestCount[pB] < 2);
                        bool canC = (staffRestCount[pC] < 2);
                        if (canB) { bestDate = date; partner = pB; attachToManualA = true; break; }
                        if (canC) { bestDate = date; partner = pC; attachToManualA = true; break; }
                    }
                }
            }

            // 執行分配
            if (bestDate.isValid()) {
                if (!attachToManualA) dailyRestPlan[bestDate].insert(pA); // 如果是新日子，加入 A
                dailyRestPlan[bestDate].insert(partner); // 加入夥伴

                if (!attachToManualA) staffRestCount[pA]++;
                staffRestCount[partner]++;
                doubleDayAssigned = true;
            }
        }

        // --- (B) 填補剩下的「單人休假」 (保持不變) ---
        for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
            if (date < monthStart || date.month() != monthStart.month()) continue;
            if (dailyRestPlan[date].size() > 0) continue; // 跳過已佔用

            QString candidate = "";
            int maxFatigue = -1;

            for (const QString &p : mainStaff) {
                if (staffRestCount[p] >= 2) continue;
                int fatigue = consecutiveDays[p] + (date.toJulianDay() - weekStart.toJulianDay());
                if (fatigue > maxFatigue) {
                    maxFatigue = fatigue;
                    candidate = p;
                }
            }

            if (candidate != "") {
                dailyRestPlan[date].insert(candidate);
                staffRestCount[candidate]++;
            }
        }
    }
    else {
        // 簡易模式 (保持不變)
        for (const QString &p : mainStaff) {
            if (staffRestCount[p] >= targetRestPerPerson) continue;
            for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
                if (date < monthStart || date.month() != monthStart.month()) continue;
                if (dailyRestPlan[date].size() == 0) {
                    dailyRestPlan[date].insert(p);
                    staffRestCount[p]++;
                    break;
                }
            }
        }
    }

    // 5. 強制檢查與 6. 分配 (後續程式碼保持不變)
    QMap<QString, int> tempConsecutive = consecutiveDays;
    for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
        bool isCurrentMonth = (date >= monthStart && date.month() == monthStart.month());
        for (const QString &p : mainStaff) {
            if (dailyRestPlan[date].contains(p)) {
                tempConsecutive[p] = 0;
            } else {
                if (tempConsecutive[p] >= 6) {
                    if (isCurrentMonth) {
                        dailyRestPlan[date].insert(p);
                        tempConsecutive[p] = 0;
                    } else {
                        tempConsecutive[p]++;
                    }
                } else {
                    tempConsecutive[p]++;
                }
            }
        }
    }

    for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
        if (date >= monthStart && date.month() == monthStart.month()) {
            assignLocationsForDay(date, dailyRestPlan[date]);
        }
    }

    for (QDate date = weekStart; date <= weekEnd; date = date.addDays(1)) {
        for (const QString &p : mainStaff) {
            if (dailyRestPlan[date].contains(p)) consecutiveDays[p] = 0;
            else consecutiveDays[p]++;
        }
    }
}
void CalendarWindow::assignLocationsForDay(QDate date, QSet<QString> resting) {
    QString pA = getStaffNameByRole(Role_Sanchong);
    QString pB = getStaffNameByRole(Role_Xinzhuang);
    QString pC = getStaffNameByRole(Role_Banqiao);
    QString pD = getStaffNameByRole(Role_Floater);
    QString pE = getStaffNameByRole(Role_Support);

    QList<ShiftEntry> shifts;
    QSet<QString> assigned; // 紀錄已分配工作的人

    // 檢查是否可用 (E 永遠可用，除非手動設為休假)
    // 但注意：resting 集合目前主要包含 A,B,C,D。如果手動把 E 設休假，這裡也會擋住。
    auto isAvailable = [&](QString p) {
        return !resting.contains(p) && !assigned.contains(p);
    };

    // 1. 新莊 (優先 B -> D -> E)
    QString staffXin = "";
    if (isAvailable(pB)) staffXin = pB;
    else if (isAvailable(pD)) staffXin = pD;
    else if (isAvailable(pE)) staffXin = pE;

    if (staffXin != "") {
        shifts.append(ShiftEntry{staffXin, "新莊", ""});
        assigned.insert(staffXin);
    }

    // 2. 板橋 (優先 C -> D -> E)
    // 注意：如果 D 剛才去新莊了，這裡 assigned.contains(D) 會是 true，就會跳過找 E
    QString staffBan = "";
    if (isAvailable(pC)) staffBan = pC;
    else if (isAvailable(pD)) staffBan = pD;
    else if (isAvailable(pE)) staffBan = pE;

    if (staffBan != "") {
        shifts.append(ShiftEntry{staffBan, "板橋", ""});
        assigned.insert(staffBan);
    }

    // 3. 三重 (優先 A -> D -> E)
    QString staffSan = "";
    if (isAvailable(pA)) staffSan = pA;
    else if (isAvailable(pD)) staffSan = pD;
    else if (isAvailable(pE)) staffSan = pE;

    if (staffSan != "") {
        shifts.append(ShiftEntry{staffSan, "三重", ""});
        assigned.insert(staffSan);
    }

    // 4. 處理「主要員工」的休假顯示 (A, B, C, D)
    QStringList mainStaff = {pA, pB, pC, pD};
    for(const QString &p : mainStaff) {
        if (!assigned.contains(p)) {
            // 這些人沒工作就是休假，必須顯示
            shifts.append(ShiftEntry{p, "休假", ""});
        }
    }

    // ★★★ pE 特殊處理：如果不工作，完全不顯示 (不加 "休假" 條目) ★★★
    // 所以這裡不需要針對 pE 寫 else

    // 5. 保留當日備註
    if (globalScheduleData.contains(date)) {
        for(const auto &oldEntry : globalScheduleData[date]) {
            if (oldEntry.location == "備註") {
                shifts.append(oldEntry);
            }
        }
    }

    globalScheduleData[date] = shifts;
}
void CalendarWindow::checkScheduleCompliance() {
    QDate currentDate = monthPicker->date();
    int year = currentDate.year();
    int month = currentDate.month();
    int daysInMonth = currentDate.daysInMonth();
    QDate firstDayOfMonth(year, month, 1);
    QDate lastDayOfMonth(year, month, daysInMonth);

    QStringList errorMessages;
    QStringList allStaff = globalEmployeeColors.keys();
    QString pSupport = getStaffNameByRole(Role_Support); // 排除 E

    // ★★★ 判斷「有沒有上個月的歷史紀錄」 ★★★
    // 檢查上個月最後一天是否有資料
    bool hasHistory = globalScheduleData.contains(firstDayOfMonth.addDays(-1));

    // ==========================================
    // 1. 檢查「連續上班超過 6 天」
    // ==========================================

    // 如果有歷史紀錄，我們就往回看 6 天（抓跨月連上）
    // 如果沒有紀錄，我們只能從本月 1 號開始算，不然會誤判
    QDate checkStart = hasHistory ? firstDayOfMonth.addDays(-6) : firstDayOfMonth;
    QDate checkEnd = lastDayOfMonth;

    QMap<QString, int> consecutiveWorkDays;
    for (const QString &emp : allStaff) consecutiveWorkDays[emp] = 0;

    for (QDate date = checkStart; date <= checkEnd; date = date.addDays(1)) {
        QSet<QString> workedToday;

        if (globalScheduleData.contains(date)) {
            for (const auto &entry : globalScheduleData[date]) {
                if (entry.location != "休假" && entry.location != "備註") {
                    workedToday.insert(entry.employeeName);
                }
            }
        }

        for (const QString &emp : allStaff) {
            if (emp == pSupport) continue; // 排除 E

            if (workedToday.contains(emp)) {
                consecutiveWorkDays[emp]++;
            } else {
                consecutiveWorkDays[emp] = 0;
            }

            // 只有當日期落在「本月」才回報
            if (date.month() == month && consecutiveWorkDays[emp] >= 6) {
                errorMessages.append(QString("• %1：在 %2 已連續上班 %3 天")
                                     .arg(emp)
                                     .arg(date.toString("MM/dd"))
                                     .arg(consecutiveWorkDays[emp]));
            }
        }
    }

    // ==========================================
    // 2. 檢查「每週是否有休 2 天」
    // ==========================================

    // 找到本月第一週的「週一」
    QDate currentWeekStart = firstDayOfMonth.addDays(-(firstDayOfMonth.dayOfWeek() - 1));

    while (true) {
        QDate currentWeekEnd = currentWeekStart.addDays(6); // 週日

        // --- 迴圈終止條件 ---
        // 如果這一週的「開始日」已經跑出這個月了，就停
        if (currentWeekStart > lastDayOfMonth) break;

        // --- 條件 A：最後一週跨月 (不計入) ---
        // 如果這週的結束日已經是下個月了，就直接跳過不檢查
        if (currentWeekEnd > lastDayOfMonth) {
            // 已經到了最後跨月週，結束檢查
            break;
        }

        // --- 條件 B：第一週跨月 (若無歷史則不計入) ---
        // 如果這週的開始日是上個月，但我們標記為「無歷史」，則跳過這週
        if (currentWeekStart < firstDayOfMonth && !hasHistory) {
            currentWeekStart = currentWeekStart.addDays(7);
            continue;
        }

        // --- 開始檢查這一週 ---
        QMap<QString, int> weeklyRestCounts;
        for (const QString &emp : allStaff) weeklyRestCounts[emp] = 0;

        for (QDate date = currentWeekStart; date <= currentWeekEnd; date = date.addDays(1)) {
            if (globalScheduleData.contains(date)) {
                for (const auto &entry : globalScheduleData[date]) {
                    if (entry.location == "休假") {
                        weeklyRestCounts[entry.employeeName]++;
                    }
                }
            }
        }

        // 只要這一週有「任何一天」落在本月，且通過了上面的篩選，我們就檢查
        // (雖然上面的條件 A 已經排除了尾巴跨月，這裡主要確保邏輯嚴謹)
        bool weekOverlapsCurrentMonth = (currentWeekStart <= lastDayOfMonth && currentWeekEnd >= firstDayOfMonth);

        if (weekOverlapsCurrentMonth) {
            for (const QString &emp : allStaff) {
                if (emp == pSupport) continue; // 排除 E

                if (weeklyRestCounts[emp] < 2) {
                    errorMessages.append(QString("• %1：在週次 [%2 ~ %3] 只有 %4 天休假")
                                         .arg(emp)
                                         .arg(currentWeekStart.toString("MM/dd"))
                                         .arg(currentWeekEnd.toString("MM/dd"))
                                         .arg(weeklyRestCounts[emp]));
                }
            }
        }

        // 往下一週
        currentWeekStart = currentWeekStart.addDays(7);
    }

    // ==========================================
    // 顯示結果
    // ==========================================
    if (errorMessages.isEmpty()) {
        QMessageBox::information(this, "檢查通過", "✅ 排班符合規則！\n(已排除 E，並忽略無效跨月週)");
    } else {
        QString msg = "⚠️ 發現以下潛在問題：\n\n";
        int displayLimit = 15;
        for (int i = 0; i < qMin(errorMessages.size(), displayLimit); ++i) {
            msg += errorMessages[i] + "\n";
        }
        if (errorMessages.size() > displayLimit) {
            msg += QString("\n... 以及其他 %1 個問題").arg(errorMessages.size() - displayLimit);
        }

        QMessageBox::warning(this, "排班檢查結果", msg);
    }
}

void CalendarWindow::recordUndo() {
    // 把目前的資料推入堆疊
    undoStack.push(globalScheduleData);

    // (選用) 限制堆疊大小，避免記憶體無限膨脹
    // 例如只保留最近 20 步，通常夠用了
    if (undoStack.size() > 20) {
        undoStack.removeFirst(); // 移除最舊的紀錄
    }
}
void CalendarWindow::undoLastAction() {
    // 1. 先檢查有沒有紀錄可以回復
    if (undoStack.isEmpty()) {
        QMessageBox::information(this, "提示", "沒有更早的紀錄了！");
        return;
    }

    // ==========================================
    // ★★★ 新增：確認對話框 ★★★
    // ==========================================
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "確認復原",
                                  "確定要回復到上一步嗎？\n您剛才所做的變更將會消失。",
                                  QMessageBox::Yes | QMessageBox::No);

    // 如果使用者按了 "No"，就直接離開函式，不執行復原
    if (reply == QMessageBox::No) {
        return;
    }

    // 2. 執行復原邏輯
    globalScheduleData = undoStack.pop();

    // 3. 刷新畫面
    refreshCalendar();

    // (選用) 跳一個小通知說復原完成，或者保持安靜也可以
    // QMessageBox::information(this, "提示", "已回復到上一步驟。");
}