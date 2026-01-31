#include "ScheduleDelegate.h"
#include "ShiftData.h"
#include <QPainter>
#include <QDate>

ScheduleDelegate::ScheduleDelegate(QObject *parent)
    : QStyledItemDelegate(parent) {}

void ScheduleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QDate date = index.data(Qt::UserRole).toDate();
    if (!date.isValid()) return;

    painter->save();
    QRect rect = option.rect; // 這是 Qt 分配給這一格的「絕對準確」範圍

    // 1. 繪製背景 (被選取時變色，否則全白)
    if (option.state & QStyle::State_Selected)
        painter->fillRect(rect, QColor("#E3F2FD"));
    else
        painter->fillRect(rect, Qt::white);

    // 2. 畫格線 (如果你希望由 Delegate 自己掌控邊框，確保完美貼合)
    // 這樣可以確保色塊邊緣跟黑線是重疊的，不會有縫隙
    painter->setPen(QColor("#D0D0D0")); // 淺灰色邊框
    painter->drawRect(rect);


    // 3. 繪製左上角的日期數字
    int headerHeight = 16;
    painter->setPen(Qt::black);
    QFont dateFont = painter->font();
    dateFont.setPixelSize(11);
    dateFont.setBold(true);
    painter->setFont(dateFont);
    // 使用 adjusted 微調一點點，讓數字不要貼死在線框上
    painter->drawText(rect.adjusted(3, 2, -3, 0), Qt::AlignLeft | Qt::AlignTop, QString::number(date.day()));

    // 4. 繪製排班條
    if (globalScheduleData.contains(date)) {
        QList<ShiftEntry> shifts = globalScheduleData[date];
        int count = shifts.size();

        if (count > 0) {
            // 計算排班條的起始 Y 軸 (標題下方)
            int startY = rect.top() + headerHeight;

            // 計算可用總高度 (底部直接用 rect.bottom()，不留任何縫隙)
            // 注意：rect.bottom() 有時會包含邊框線，為了保險我們用 rect.height() 來算
            int totalBarHeight = (rect.bottom() - startY) + 1;
            // (+1 是因為 Qt 的座標系統 rect.bottom() = top + height - 1)

            QFont textFont = painter->font();
            // 根據格子大小動態調整字體，避免字太大
            int dynamicFontSize = (totalBarHeight / count < 16) ? 9 : 11;
            textFont.setPixelSize(dynamicFontSize);
            painter->setFont(textFont);

            for (int i = 0; i < count; ++i) {
                const auto &entry = shifts[i];

                // ... (原本計算 y1, y2, barH 的數學公式保持不變) ...
                int y1 = startY + (i * totalBarHeight) / count;
                int y2 = startY + ((i + 1) * totalBarHeight) / count;
                int barH = y2 - y1;

                // --- ★★★ 修改顏色的邏輯 ★★★ ---
                QColor bg;
                QColor textColor = Qt::white;
                QString text;

                // 判斷是否為「備註」
                if (entry.location == "備註") {
                    bg = QColor("#FFF9C4"); // 淡黃色 (像便利貼)
                    textColor = Qt::black;  // 黑字
                    text = entry.employeeName; // ★ 直接顯示內容，不用加 "- 備註"
                }
                else {
                    // 原本的員工排班邏輯
                    bg = getEmployeeColor(entry.employeeName);

                    if (entry.location == "休假") {
                        bg = QColor("#FFEBEE");
                        textColor = Qt::black;
                    }
                    // 標準顯示格式
                    text = entry.employeeName + " - " + entry.location;
                }
                // ------------------------------------

                painter->setBrush(bg);
                painter->setPen(Qt::NoPen);

                // 設定矩形 (維持上次給你的完美填滿邏輯)
                QRect barRect(rect.left(), y1, rect.width(), barH);

                // 畫底色
                painter->drawRect(barRect);

                // 畫文字
                painter->setPen(textColor);
                painter->drawText(barRect, Qt::AlignCenter, text);
            }
        }
    }
    painter->restore();
}