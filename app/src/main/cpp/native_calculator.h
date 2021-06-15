//
// Created by 45010 on 2021/6/14.
//

#ifndef NATIVECALCULATORDEMO_NATIVE_CALCULATOR_H
#define NATIVECALCULATORDEMO_NATIVE_CALCULATOR_H

#include "calculate_exception.h"
#include "operation_symbol.h"

class Calculator{
private:
    OperationSymbol operationSymbol = None;
    double firstNum;
    double secondNum;
    std::string expression;
public:
    Calculator(): firstNum(0.0),secondNum(0.0){}
    Calculator(double a,double b);

    void inputExpression(char* c);

    void setFirstNum(double a);

    void setSecondNum(double b);

    void extractNumFromExpression();

    void setOperationSymbol(OperationSymbol symbol);

    bool checkOperationExist();

    double doCalculate() throw (CalculateException);

    void resetStatus();

    bool checkInputLegal(std::string c);

    bool checkExpressionLegal();

    std::string getSymbolStr();

    std::string getExpressionStr();

};


#endif //NATIVECALCULATORDEMO_NATIVE_CALCULATOR_H
