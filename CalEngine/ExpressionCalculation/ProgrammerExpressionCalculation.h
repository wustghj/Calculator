#ifndef PROGRAMMEREXPRESSIONCALCULATION_H
#define PROGRAMMEREXPRESSIONCALCULATION_H

#include "AbstractExpressionCalculation.h"
namespace CalEngine
{

    static int type = 2;

    class ProgrammerExpressionCalculation:public AbstractExpressionCalculation
    {
    private:
        QString expType;
    public:
        ProgrammerExpressionCalculation(QString inputExp,QString inputExpType);
        bool isOperator(const QString &inputalp)override;
        QString doOperation(const QString &numA,const QString &numB,const QString &opt)override;

        // 0 -> bin, 1->dec, 2->oct, 3->hex

    };
};


#endif // PROGRAMMEREXPRESSIONCALCULATION_H
