#include "ProgrammerCalPage.h"
#include "ui_ProgrammerCalPage.h"

#include "CalEngine/ExpressionCalculation/ProgrammerExpressionCalculation.h"

ProgrammerCalPage::ProgrammerCalPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgrammerCalPage)
{
    ui->setupUi(this);

    ui->tabWidget2->setTabText(0, "输入十进制数字");
    ui->tabWidget2->setTabText(1, "获取结果");

    // 连接按钮
    //connect(this, SIGNAL(updateHistoryPage(QString)),this->window(), SLOT(updateHistoryPage(QString)) );
    // 在构造函数中直接使用lambda表达式连接，代码清晰简短
    connect(ui->num0, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("0",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num1, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("1",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num2, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("2",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num3, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("3",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num4, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("4",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num5, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("5",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num6, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("6",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num7, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("7",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

    connect(ui->num8, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("8",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });

    connect(ui->num9, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("9",pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();});

//    connect(ui->opDot, &QPushButton::clicked,[=](){
//        int32_t pos=ui->displayCur->cursorPosition();
//        ui->displayCur->insertExpression(".",pos);
//        ui->displayCur->setFocus();
//        ui->displayCur->setCursorPosition(pos+1);
//    });


    connect(ui->BtnBin, &QPushButton::clicked, [=](){
        ui->tabWidget2->setTabText(0, "输入二进制数字");
        ui->opClear->click();

        CalEngine::type = 0; // 二进制模式
        ui->num0->setEnabled(1);
        ui->num1->setEnabled(1);
        ui->num2->setDisabled(1);
        ui->num3->setDisabled(1);
        ui->num4->setDisabled(1);
        ui->num5->setDisabled(1);
        ui->num6->setDisabled(1);
        ui->num7->setDisabled(1);
        ui->num8->setDisabled(1);
        ui->num9->setDisabled(1);
        ui->opA->setDisabled(1);
        ui->opB->setDisabled(1);
        ui->opC->setDisabled(1);
        ui->opD->setDisabled(1);
        ui->opE->setDisabled(1);
        ui->opF->setDisabled(1);
    });

    connect(ui->BtnDec, &QPushButton::clicked, [=](){
        ui->tabWidget2->setTabText(0, "输入八进制数字");
        ui->opClear->click();

        CalEngine::type = 1;

        ui->num0->setEnabled(1);
        ui->num1->setEnabled(1);
        ui->num2->setEnabled(1);
        ui->num3->setEnabled(1);
        ui->num4->setEnabled(1);
        ui->num5->setEnabled(1);
        ui->num6->setEnabled(1);
        ui->num7->setEnabled(1);
        ui->num8->setDisabled(1);
        ui->num9->setDisabled(1);
        ui->opA->setDisabled(1);
        ui->opB->setDisabled(1);
        ui->opC->setDisabled(1);
        ui->opD->setDisabled(1);
        ui->opE->setDisabled(1);
        ui->opF->setDisabled(1);
    });

    connect(ui->BtnOct, &QPushButton::clicked, [=](){
        ui->tabWidget2->setTabText(0, "输入十进制数字");
        ui->opClear->click();

        CalEngine::type = 2;

        ui->num0->setEnabled(1);
        ui->num1->setEnabled(1);
        ui->num2->setEnabled(1);
        ui->num3->setEnabled(1);
        ui->num4->setEnabled(1);
        ui->num5->setEnabled(1);
        ui->num6->setEnabled(1);
        ui->num7->setEnabled(1);
        ui->num8->setEnabled(1);
        ui->num9->setEnabled(1);
        ui->opA->setDisabled(1);
        ui->opB->setDisabled(1);
        ui->opC->setDisabled(1);
        ui->opD->setDisabled(1);
        ui->opE->setDisabled(1);
        ui->opF->setDisabled(1);
    });

    connect(ui->BtnHex, &QPushButton::clicked, [=](){
        ui->tabWidget2->setTabText(0, "输入十六进制数字");
        ui->opClear->click();

        CalEngine::type = 3;

        ui->num0->setEnabled(1);
        ui->num1->setEnabled(1);
        ui->num2->setEnabled(1);
        ui->num3->setEnabled(1);
        ui->num4->setEnabled(1);
        ui->num5->setEnabled(1);
        ui->num6->setEnabled(1);
        ui->num7->setEnabled(1);
        ui->num8->setEnabled(1);
        ui->num9->setEnabled(1);
        ui->opA->setEnabled(1);
        ui->opB->setEnabled(1);
        ui->opC->setEnabled(1);
        ui->opD->setEnabled(1);
        ui->opE->setEnabled(1);
        ui->opF->setEnabled(1);
    });

    connect(ui->opA, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("A", pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });
    connect(ui->opB, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("B", pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });
    connect(ui->opC, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("C", pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });
    connect(ui->opD, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("D", pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });
    connect(ui->opE, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("E", pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });
    connect(ui->opF, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->insertExpression("F", pos);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos+1);
        ui->opEqual->click();
    });

    connect(ui->bckSpace, &QPushButton::clicked, [=](){
        int32_t pos=ui->displayCur->cursorPosition();
        ui->displayCur->removeExpression(pos-1,1);
        ui->displayCur->setFocus();
        ui->displayCur->setCursorPosition(pos);
        ui->opEqual->click();
    });



    connect(ui->opClear, &QPushButton::clicked, [=](){ui->displayCur->clearExpression();ui->opEqual->click();});

    // 核心操作，进制转换器
    connect(ui->opEqual, &QPushButton::clicked, [=](){
        QString bin, Bin = "     二进制:",
                dec, Dec = "     八进制:",
                oct, Oct = "     十进制:",
                hex, Hex = "     十六进制:";

        // 十进制 ， 模式
        if (CalEngine::type == 2)
        {
            int Num = ui->displayCur->text().toInt();


            bin = bin.setNum(Num, 2);
            dec = dec.setNum(Num, 8);
            oct = oct.setNum(Num, 10);
            hex = hex.setNum(Num, 16);

            bin = Bin + bin;
            dec = Dec + dec;
            oct = Oct + oct;
            hex = Hex + hex;

            ui->TextBin->setText(bin);
            ui->TextDec->setText(dec);
            ui->TextOct->setText(oct);
            ui->TextHex->setText(hex);
        }

        // 二进制
        if (CalEngine::type == 0)
        {
            int Num = ui->displayCur->text().toInt(nullptr, 2);

            bin = bin.setNum(Num, 2);
            dec = dec.setNum(Num, 8);
            oct = oct.setNum(Num, 10);
            hex = hex.setNum(Num, 16);

            bin = Bin + bin;
            dec = Dec + dec;
            oct = Oct + oct;
            hex = Hex + hex;

            ui->TextBin->setText(bin);
            ui->TextDec->setText(dec);
            ui->TextOct->setText(oct);
            ui->TextHex->setText(hex);
        }

        // 八进制
        if (CalEngine::type == 1)
        {
            int Num = ui->displayCur->text().toInt(nullptr, 8);

            bin = bin.setNum(Num, 2);
            dec = dec.setNum(Num, 8);
            oct = oct.setNum(Num, 10);
            hex = hex.setNum(Num, 16);

            bin = Bin + bin;
            dec = Dec + dec;
            oct = Oct + oct;
            hex = Hex + hex;

            ui->TextBin->setText(bin);
            ui->TextDec->setText(dec);
            ui->TextOct->setText(oct);
            ui->TextHex->setText(hex);
        }

        // 十六进制
        if (CalEngine::type == 3)
        {
            int Num = ui->displayCur->text().toInt(nullptr, 16);

            bin = bin.setNum(Num, 2);
            dec = dec.setNum(Num, 8);
            oct = oct.setNum(Num, 10);
            hex = hex.setNum(Num, 16);

            bin = Bin + bin;
            dec = Dec + dec;
            oct = Oct + oct;
            hex = Hex + hex;

            ui->TextBin->setText(bin);
            ui->TextDec->setText(dec);
            ui->TextOct->setText(oct);
            ui->TextHex->setText(hex);
        }
    });


    //    QTimer::singleShot(100,this, [=]() {connect(this,SIGNAL(updateHistoryPage(QString)),this->window(),SLOT(updateHistoryPage(QString)));});//连接历史窗口
}

ProgrammerCalPage::~ProgrammerCalPage()
{
    delete ui;
}

