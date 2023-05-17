#ifndef NORMALCALPAGE_H
#define NORMALCALPAGE_H

#include <QWidget>

namespace Ui {
class NormalCalculatorPage;
}

class NormalCalculatorPage : public QWidget
{
    Q_OBJECT

public:
    explicit NormalCalculatorPage(QWidget *parent = nullptr);
    ~NormalCalculatorPage();

private slots:
    void on_opInv_pressed();



private:
    Ui::NormalCalculatorPage *ui;
    void updateHisLabel(QString);
    // 重载按键事件
    void keyPressEvent(QKeyEvent *event)override;
    // 重载resize
    void resizeEvent(QResizeEvent *event)override;
    void calResult();

signals:
    void updateHistoryPage(QString willupdate);
};

#endif // NORMALCALPAGE_H
