#include "DayEditorDialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog> // ★ 新增這行：為了跳出輸入框

DayEditorDialog::DayEditorDialog(QDate date, QWidget *parent)
    : QDialog(parent), currentDate(date)
{
    setWindowTitle(date.toString("MM/dd") + " 排班編輯");
    resize(400, 500);
    setStyleSheet("background-color: #ffffff;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *form = new QFormLayout();

    nameInput = new QComboBox();
    // globalEmployeeColors 定義在 ShiftData.h，這裡可以直接用
    nameInput->addItems(globalEmployeeColors.keys());
    nameInput->setStyleSheet("padding: 5px; border: 1px solid #ccc; border-radius: 5px;");

    statusInput = new QComboBox();
    statusInput->addItems({"休假", "三重", "新莊", "板橋"});
    statusInput->setStyleSheet("padding: 5px; border: 1px solid #ccc; border-radius: 5px;");

    form->addRow("選擇員工:", nameInput);
    form->addRow("分配地點:", statusInput);
    layout->addLayout(form);

    // --- 設定按鈕樣式 ---
    QString btnStyleBlue = "QPushButton { background-color: #2196F3; color: white; border-radius: 15px; padding: 5px 15px; font-weight: bold; font-size: 14px; } QPushButton:hover { background-color: #1976D2; }";
    QString btnStyleGreen = "QPushButton { background-color: #4CAF50; color: white; border-radius: 15px; padding: 5px 15px; font-weight: bold; font-size: 14px; } QPushButton:hover { background-color: #388E3C; }";
    QString btnStyleOrange = "QPushButton { background-color: #FF9800; color: white; border-radius: 15px; padding: 5px 15px; font-weight: bold; font-size: 14px; } QPushButton:hover { background-color: #F57C00; }";

    // --- 建立按鈕區塊 (水平排列) ---
    QHBoxLayout *btnLayout = new QHBoxLayout();

    QPushButton *addBtn = new QPushButton("➕ 加入/修改");
    addBtn->setStyleSheet(btnStyleBlue);

    // ★ 新增：備註按鈕
    QPushButton *addRemarkBtn = new QPushButton("📝 新增備註");
    addRemarkBtn->setStyleSheet(btnStyleOrange);

    btnLayout->addWidget(addBtn);
    btnLayout->addWidget(addRemarkBtn); // 把備註按鈕加進來
    layout->addLayout(btnLayout);

    // --- 列表顯示區 ---
    listWidget = new QListWidget();
    listWidget->setStyleSheet("border: 1px solid #eee; border-radius: 10px; padding: 5px;");
    layout->addWidget(new QLabel("本日已排班 (雙擊刪除):"));
    layout->addWidget(listWidget);

    // 載入當日資料
    if (globalScheduleData.contains(currentDate)) {
        tempList = globalScheduleData[currentDate];
    }
    refreshList();

    // 完成按鈕
    QPushButton *okBtn = new QPushButton("完成");
    okBtn->setStyleSheet(btnStyleGreen);
    connect(okBtn, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(okBtn);

    // --- 事件連接：加入員工 ---
    connect(addBtn, &QPushButton::clicked, [this](){
        QString name = nameInput->currentText();
        QString status = statusInput->currentText();
        if (name.isEmpty()) return;

        // 如果該員工已經在名單中，先移除舊的 (避免重複排班)
        for(int i=0; i<tempList.size(); ++i) {
            // 注意：這裡只檢查不是備註的項目，避免誤刪內容剛好跟員工同名的備註
            if(tempList[i].location != "備註" && tempList[i].employeeName == name) {
                tempList.removeAt(i);
                break;
            }
        }

        tempList.append(ShiftEntry{name, status});
        refreshList();
    });

    // --- ★ 事件連接：加入備註 ---
    connect(addRemarkBtn, &QPushButton::clicked, [this](){
        bool ok;
        QString text = QInputDialog::getText(this, "新增當日備註",
                                             "請輸入備註內容 (例如: 廠商來訪):",
                                             QLineEdit::Normal, "", &ok);
        if (ok && !text.trimmed().isEmpty()) {
            // 建立備註項目：Name存內容, Location存 "備註"
            tempList.append(ShiftEntry{text, "備註"});
            refreshList();
        }
    });

    // 雙擊刪除
    connect(listWidget, &QListWidget::itemDoubleClicked, [this](QListWidgetItem *item){
        int row = listWidget->row(item);
        if (row >= 0 && row < tempList.size()) {
            tempList.removeAt(row);
            refreshList();
        }
    });
}

QList<ShiftEntry> DayEditorDialog::getResult() const {
    return tempList;
}

void DayEditorDialog::refreshList() {
    listWidget->clear();
    for (const auto &entry : tempList) {
        QListWidgetItem *item = new QListWidgetItem();

        // ★ 針對備註做特殊顯示處理
        if (entry.location == "備註") {
            // 備註只顯示內容，不用顯示地點
            item->setText(entry.employeeName);
            // 設定為淡黃色 (便利貼風格)
            item->setBackground(QColor("#FFF9C4"));
            item->setForeground(Qt::black);
        }
        else {
            // 一般員工排班
            QString text = entry.employeeName + " - " + entry.location;
            item->setText(text);

            // 設定員工代表色
            item->setBackground(getEmployeeColor(entry.employeeName));
            item->setForeground(Qt::white);

            // 休假特別色 (淡紅底紅字)
            if (entry.location == "休假") {
                item->setBackground(QColor("#ffebee"));
                item->setForeground(Qt::red);
            }
        }

        item->setTextAlignment(Qt::AlignCenter);
        listWidget->addItem(item);
    }
}