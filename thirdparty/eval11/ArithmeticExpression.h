/*
 * ArithmeticExpression.h -- This file is part of primesieve
 *
 * Copyright (C) 2011 Kim Walisch, <kim.walisch@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

/**
 * @file ArithmeticExpression.h
 * @brief This is a wrapper class for Parsifal's Arithmetic Expression
 *        Evaluator <www.parsifalsoft.com>. It is written in C and had
 *        partially been generated by their AnaGram parser.
 *
 * Their Readme files says:
 * >> evaluateExpression may be freely copied and modified.
 *
 * I have changed the variable type from double to uint64_t from
 * stdint.h. The double type has problems with integers near 2^64,
 *
 * i.e. 1e18+100 = 1000000000000000000
 *
 * My new version with uint64_t gives the correct result:
 *
 * 1e18+100 = 1000000000000000100
 *
 * @warning As I use integers for all calculations one has to be
 *          careful with divisions:
 *
 *          (10/6)*10000 = 10000
 */

#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include <stdint.h>
#include <string>
#include <sstream>
extern "C" {
#include "evaldefs.h"
}

class ArithmeticExpression
{
public:
  ArithmeticExpression();
  std::string getExpression() const;
  std::string getErrorMessage() const;
  uint64_t getResult() const;
  bool evaluate(std::string);
private:
  std::string expression_;
  std::ostringstream errorMessage_;
  uint64_t result_;
};

#endif // ARITHMETICEXPRESSION_H
