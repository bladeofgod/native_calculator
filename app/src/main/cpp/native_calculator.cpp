//
// Created by 45010 on 2021/6/14.
//

#include "native_calculator.h"


Calculator::Calculator(double a, double b) {
    firstNum = a;
    secondNum = b;
}

void Calculator::setFirstNum(double a) {
    firstNum = a;
}

void Calculator::setSecondNum(double b) {
    secondNum = b;
}

bool Calculator::checkOperationExist() {
    return operationSymbol != None;
}

void Calculator::setOperationSymbol(OperationSymbol symbol) {
    operationSymbol = symbol;
}

double Calculator::doCalculate() throw (CalculateException){
    switch (operationSymbol) {
        case None:
            throw CalculateException("missing operation symbol!");
        case ADD:
            return firstNum + secondNum;
        case REDUCE:
            return firstNum - secondNum;
        case MULTIPLY:
            return firstNum * secondNum;
        case DIVIDE:
            return firstNum / secondNum;
        default:
            throw CalculateException();
    }
}

void Calculator::resetStatus() {
    firstNum = 0.0;
    secondNum = 0.0;
    operationSymbol = None;
}