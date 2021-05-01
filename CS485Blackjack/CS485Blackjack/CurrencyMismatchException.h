//****************************************************************************
// File name:		CurrencyMismatchException.h
// Author:			Group 7
// Date:				4/11/21
// Class:				CS 485
// Assignment:	Assignment 4 Bank Accounts
// Purpose:			Header file for CurrencyMismatchException Class
//****************************************************************************
#pragma once

#include <exception>
#include <iostream>
#include <cstddef>

class CurrencyMismatchException : public std::exception
{
public:
  CurrencyMismatchException(int value = 0);
  CurrencyMismatchException(const CurrencyMismatchException&);

  ~CurrencyMismatchException();

  CurrencyMismatchException& operator= (CurrencyMismatchException);

  const void ourWhat() const;

private:
  int mValue;
};