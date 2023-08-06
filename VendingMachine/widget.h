#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money = {0};
    void changeMoney(int x);
    void moneyChange (int, int&, int&, int&, int&);

private slots:
    void on_pb10_clicked();
    void onEnable();

    void on_lcdNumber_overflow();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_PbCoffee_clicked();

    void on_PbTee_clicked();

    void on_PbMilk_clicked();

    void on_PbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
