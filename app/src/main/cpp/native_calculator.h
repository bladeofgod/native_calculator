//
// Created by 45010 on 2021/6/14.
//

#ifndef NATIVECALCULATORDEMO_NATIVE_CALCULATOR_H
#define NATIVECALCULATORDEMO_NATIVE_CALCULATOR_H
#include "calculate_exception.h"

enum OperationSymbol{
    None,
    ADD,
    REDUCE,
    MULTIPLY,
    DIVIDE
};

class Calculator{
private:
    OperationSymbol operationSymbol = None;
    double firstNum;
    double secondNum;
public:
    Calculator(): firstNum(0.0),secondNum(0.0){}
    Calculator(double a,double b);

    void setFirstNum(double a);

    void setSecondNum(double b);

    void setOperationSymbol(OperationSymbol symbol);

    bool checkOperationExist();

    double doCalculate() throw (CalculateException);

    void resetStatus();

};


#endif //NATIVECALCULATORDEMO_NATIVE_CALCULATOR_H
