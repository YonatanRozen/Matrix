//
// Created by yonat on 6/30/2022.
//

#ifndef MATRIX_EXCEPTION_H
#define MATRIX_EXCEPTION_H

#include <exception>
#include <string>

class InvalidDimensions : public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid dimensions between matrix elements!";
    }
};

#endif //MATRIX_EXCEPTION_H
