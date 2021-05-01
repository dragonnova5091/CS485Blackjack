//****************************************************************************
// File name:	  Currency.h
// Author:			Group 7
// Date:				4/11/21
// Class:				CS 485
// Assignment:	Assignment 4 Bank Accounts
// Purpose:			Header file for Currency Class
//****************************************************************************
#pragma once

#include "CurrencyMismatchException.h"
#include <string>

enum class CurrencyType : char {
  USD,
  GBP,
  EUR,
  YEN,
};

class Currency
{
public:
  Currency();
  Currency(std::string);
  Currency(const Currency&);

  CurrencyType getCurrencyType();
  void print();
  //friend std::ostream& operator<<(std::ostream& os, CurrencyType& cType);
  //CurrencyType operator<<(CurrencyType& cType);

private:
  CurrencyType mCurrencyType;
};