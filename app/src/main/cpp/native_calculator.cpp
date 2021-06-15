//
// Created by 45010 on 2021/6/14.
//

#include "native_calculator.h"

typedef std::string String;

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

void Calculator::extractNumFromExpression() {
    int symbolPos = expression.find(getSymbolStr());
    firstNum = atof(expression.substr(0,symbolPos).c_str());
    secondNum = atof(expression.substr(symbolPos+1).c_str());
}

bool Calculator::checkOperationExist() {
    return operationSymbol != None;
}

void Calculator::setOperationSymbol(OperationSymbol symbol) {
    operationSymbol = symbol;
}

double Calculator::doCalculate() throw (CalculateException){
    if(! checkOperationExist())
        throw CalculateException("expression is illegal!");

    extractNumFromExpression();

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

bool Calculator::checkExpressionLegal() {
    if(checkOperationExist()) {
        //has operation symbol
        int n = expression.find(getSymbolStr());
        //has second num
        return expression.length() > n;
    }
    return false;
}

void Calculator::resetStatus() {
    firstNum = 0.0;
    secondNum = 0.0;
    operationSymbol = None;
}

void Calculator::inputExpression(char* c) {
    if(checkInputLegal(c)) {
        expression.append(c);
    }
}

//string s is always in [0-9,+,-,*,/,.]

bool Calculator::checkInputLegal(String c) {
    bool isSymbol = c.find("+") != String::npos
            || c.find("-") != String::npos
            || c.find("x") != String::npos
            || c.find("/") != String::npos;
    bool isDot = c.find(".") != String::npos;
    if(isSymbol) {
        //input is symbol
        return operationSymbol == 0;
    } else if(isDot) {
        //input is dot
        if(operationSymbol == 0) {
            //no operation symbol
            return expression.find(c) == String::npos;
        } else {
            int n = expression.find(getSymbolStr());
            String second = expression.substr(n);
            return second.find(c) == String::npos;
        }
    } else {
        //is number
        return true;
    }

}

std::string Calculator::getSymbolStr() {
    switch (operationSymbol) {
        case None:
            return "";
        case ADD:
            return "+";
        case REDUCE:
            return "-";
        case MULTIPLY:
            return "x";
        case DIVIDE:
            return "/";
    }
}

std::string Calculator::getExpressionStr() {
    return expression;
}

