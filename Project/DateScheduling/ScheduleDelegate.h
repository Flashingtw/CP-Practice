#ifndef SCHEDULEDELEGATE_H
#define SCHEDULEDELEGATE_H

#include <QStyledItemDelegate>

class ScheduleDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit ScheduleDelegate(QObject *parent = nullptr);

    // 這是最核心的函式：負責畫出格子裡的內容
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // SCHEDULEDELEGATE_H