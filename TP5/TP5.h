#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TP5.h"

class TP5 : public QMainWindow
{
    Q_OBJECT

public:
    TP5(QWidget *parent = nullptr);
    ~TP5();

private:
    Ui::TP5Class ui;
};
