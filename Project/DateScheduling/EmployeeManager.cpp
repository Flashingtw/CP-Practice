#include "EmployeeManager.h"
#include "ShiftData.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QInputDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QGroupBox>
#include <QGridLayout>

class QuickColorPicker : public QDialog {
public:
    QColor selectedColor;

    QuickColorPicker(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("選擇代表色");
        resize(300, 250);
        setStyleSheet("background-color: white;");

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(new QLabel("請選擇一個預設顏色，或自訂："));

        QGridLayout *grid = new QGridLayout();
        // 提供一些好看的預設色
        QStringList presets = {"#ef5350", "#ec407a", "#ab47bc", "#5c6bc0", "#42a5f5", "#26a69a", "#66bb6a", "#ffa726"};

        int row = 0, col = 0;
        for (const QString &code : presets) {
            QPushButton *btn = new QPushButton();
            btn->setFixedSize(50, 50);
            btn->setStyleSheet(QString("QPushButton { background-color: %1; border-radius: 25px; border: 2px solid white; } QPushButton:hover { border: 2px solid #333; }").arg(code));

            connect(btn, &QPushButton::clicked, [this, code](){
                selectedColor = QColor(code);
                accept();
            });

            grid->addWidget(btn, row, col);
            col++;
            if (col > 3) { col = 0; row++; }
        }
        mainLayout->addLayout(grid);

        QPushButton *customBtn = new QPushButton("🎨 自訂顏色...");
        QString style = "QPushButton { background-color: #607D8B; color: white; border-radius: 15px; padding: 5px 15px; font-weight: bold; font-size: 14px; } QPushButton:hover { background-color: #45a049; }";
        customBtn->setStyleSheet(style);

        connect(customBtn, &QPushButton::clicked, [this](){
            QColor c = QColorDialog::getColor(Qt::white, this, "自訂顏色");
            if (c.isValid()) {
                selectedColor = c;
                accept();
            }
        });
        mainLayout->addWidget(customBtn);
    }
};


EmployeeManagerDialog::EmployeeManagerDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("員工與職位管理");
    resize(500, 600);
    setStyleSheet("background-color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QGroupBox *grpList = new QGroupBox("1. 員工名單與顏色");
    QVBoxLayout *layoutList = new QVBoxLayout(grpList);

    listWidget = new QListWidget();
    listWidget->setStyleSheet("border: 1px solid #ccc; border-radius: 3px; font-size: 14px;");
    layoutList->addWidget(listWidget);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    QString btnStyle = "QPushButton { border-radius: 5px; padding: 5px; font-weight: bold; color: white;}";

    QPushButton *addBtn = new QPushButton("➕ 新增");
    addBtn->setStyleSheet(btnStyle + "QPushButton{background-color: #2196F3;}");

    QPushButton *delBtn = new QPushButton("🗑️ 刪除");
    delBtn->setStyleSheet(btnStyle + "QPushButton{background-color: #F44336;}");

    btnLayout->addWidget(addBtn);
    btnLayout->addWidget(delBtn);
    layoutList->addLayout(btnLayout);
    mainLayout->addWidget(grpList);

    // --- 中間：職位分配 ---
    QGroupBox *grpRoles = new QGroupBox("2. 職位分配設定");
    QGridLayout *gridRoles = new QGridLayout(grpRoles);

    auto createRoleRow = [&](int row, QString title, QComboBox*& combo) {
        gridRoles->addWidget(new QLabel(title), row, 0);
        combo = new QComboBox();
        gridRoles->addWidget(combo, row, 1);
    };

    createRoleRow(0, "固定三重:", comboSanchong);
    createRoleRow(1, "固定新莊:", comboXinzhuang);
    createRoleRow(2, "固定板橋:", comboBanqiao);
    createRoleRow(3, "機動代班:", comboFloater);
    createRoleRow(4, "支援輔助:", comboSupport);

    mainLayout->addWidget(grpRoles);

    QPushButton *okBtn = new QPushButton("儲存並套用");
    okBtn->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-size: 16px; padding: 10px; border-radius: 5px; }");
    mainLayout->addWidget(okBtn);

    refreshList();

    connect(addBtn, &QPushButton::clicked, [this](){
        bool ok;
        QString name = QInputDialog::getText(this, "新增員工", "輸入姓名:", QLineEdit::Normal, "", &ok);
        if (ok && !name.isEmpty()) {
            if (globalEmployeeColors.contains(name)) {
                QMessageBox::warning(this, "重複", "這名字已經有了！");
                return;
            }

            QuickColorPicker colorPicker(this);
            if (colorPicker.exec() == QDialog::Accepted) {
                globalEmployeeColors[name] = colorPicker.selectedColor.name();
                refreshList();
            }
        }
    });

    connect(delBtn, &QPushButton::clicked, [this](){
        QList<QListWidgetItem*> items = listWidget->selectedItems();
        if (!items.isEmpty()) {
            for(auto item : items) {
                QString name = item->data(Qt::UserRole).toString();
                globalEmployeeColors.remove(name);
            }
            refreshList();
        }
    });

    connect(okBtn, &QPushButton::clicked, [this](){
        saveEmployees();
        saveRoleConfig();
        accept();
    });
}

void EmployeeManagerDialog::refreshList() {
    listWidget->clear();
    QMapIterator<QString, QString> i(globalEmployeeColors);
    while (i.hasNext()) {
        i.next();
        QListWidgetItem *item = new QListWidgetItem(i.key());
        item->setBackground(QColor(i.value()));
        item->setForeground(Qt::white);
        item->setData(Qt::UserRole, i.key());
        item->setTextAlignment(Qt::AlignCenter);
        listWidget->addItem(item);
    }
    updateRoleCombos();
}

void EmployeeManagerDialog::updateRoleCombos() {
    QStringList names = globalEmployeeColors.keys();
    QList<QComboBox*> boxes = {comboSanchong, comboXinzhuang, comboBanqiao, comboFloater, comboSupport};

    QMap<StaffRole, QString> currentRoles = globalRoleAssignments;

    int idx = 0;
    for (QComboBox* box : boxes) {
        box->clear();

        box->addItem("-- 請選擇人員 --", "");

        box->addItems(names);

        StaffRole role = (StaffRole)idx;
        QString currentName = currentRoles.value(role);

        int findIdx = box->findText(currentName);
        if (findIdx != -1 && !currentName.isEmpty()) {
            box->setCurrentIndex(findIdx);
        } else {
            box->setCurrentIndex(0);
        }
        idx++;
    }
}
void EmployeeManagerDialog::saveRoleConfig() {
    auto getSelectedName = [](QComboBox* box) -> QString {
        if (box->currentIndex() <= 0) return "";
        return box->currentText();
    };

    globalRoleAssignments[Role_Sanchong] = getSelectedName(comboSanchong);
    globalRoleAssignments[Role_Xinzhuang] = getSelectedName(comboXinzhuang);
    globalRoleAssignments[Role_Banqiao] = getSelectedName(comboBanqiao);
    globalRoleAssignments[Role_Floater] = getSelectedName(comboFloater);
    globalRoleAssignments[Role_Support] = getSelectedName(comboSupport);

    saveRoles();
}