#ifndef DAYEDITORDIALOG_H
#define DAYEDITORDIALOG_H

#include <QDialog>
#include <QDate>
#include <QComboBox>
#include <QListWidget>
#include "ShiftData.h"

class DayEditorDialog : public QDialog {
    Q_OBJECT
public:
    DayEditorDialog(QDate date, QWidget *parent = nullptr);
    QList<ShiftEntry> getResult() const;

private:
    QDate currentDate;
    QComboBox *nameInput;
    QComboBox *statusInput;
    QListWidget *listWidget;
    QList<ShiftEntry> tempList;
    void refreshList();
};

#endif // DAYEDITORDIALOG_H