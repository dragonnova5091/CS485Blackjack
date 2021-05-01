//****************************************************************************
// File name:		Money.h
// Author:			Group 7
// Date:				3/19/21
// Class:				CS 485
// Assignment:	Assignment 3 Bank Accounts
// Purpose:			Header file for Money Class
//****************************************************************************
#pragma once

#include "Currency.h"

class Money
{
public:
  Money();
  Money(long long, std::string);
  Money(const Money&);
  ~Money();

  long long getAmount();
  void setAmount(long long);
  Currency getCurrency();

  Money operator= (const Money&);
  Money operator+ (const Money&);
  Money operator- (const Money&);

private:
  long long mAmount;
  Currency* mpcCurrency;
};