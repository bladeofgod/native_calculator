//
// Created by 45010 on 2021/6/14.
//

#include <string>

#ifndef NATIVECALCULATORDEMO_CALCULATE_EXCEPTION_H
#define NATIVECALCULATORDEMO_CALCULATE_EXCEPTION_H


class CalculateException : public std::exception{
public:
    std::string msg;
    CalculateException():msg("none define exception"){}
    CalculateException(std::string msg) {
        this->msg = msg;
    }
};

#endif //NATIVECALCULATORDEMO_CALCULATE_EXCEPTION_H
