//****************************************************************************
// File name:		Currency.cpp
// Author:			Group 7
// Date:				4/11/21
// Class:				CS 485
// Assignment:	Assignment 4 Bank Accounts
// Purpose:			Implementation of Currency.h
//****************************************************************************
#include "Currency.h"
#include <iostream>

//***************************************************************************
// Constructor: Currency
//
// Description: Initialize Currency
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Currency::Currency() {
  mCurrencyType = CurrencyType::USD;
}

//***************************************************************************
// Constructor: Currency
//
// Description: Initialize Currency with the parameter
//
// Parameters:  string pType - the type of currency
//
// Returned:    None
//***************************************************************************
Currency::Currency(std::string pType) {
  if ("USD" == pType) {
    mCurrencyType = CurrencyType::USD;
  }
  else if ("GBP" == pType) {
    mCurrencyType = CurrencyType::GBP;
  }
  else if ("EUR" == pType) {
    mCurrencyType = CurrencyType::EUR;
  }
  else if ("YEN" == pType) {
    mCurrencyType = CurrencyType::YEN;
  }
  else {
    mCurrencyType = CurrencyType::USD;
    std::cout << "Invalid Currency Type\n";
  }
}

//***************************************************************************
// Constructor: Currency
//
// Description: Initialize Currency with parameter
//
// Parameters:  Currency& rcCurrency - the Currency object to be copied from
//
// Returned:    None
//***************************************************************************
Currency::Currency(const Currency& rcCurrency) {
  mCurrencyType = rcCurrency.mCurrencyType;
}

//***************************************************************************
// Function:		getCurrencyType
//
// Description: Gets the type of currency
//
// Parameters:  None
//
// Returned:    The type of currency
//***************************************************************************
CurrencyType Currency::getCurrencyType() {
  return mCurrencyType;
}

//***************************************************************************
// Function:		print
//
// Description: Prints the currency type
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Currency::print() {

  switch (mCurrencyType) {
  case CurrencyType::USD: std::cout << "USD";
    break;
  case CurrencyType::GBP: std::cout << "GBP";
    break;
  case CurrencyType::EUR: std::cout << "EUR";
    break;
  case CurrencyType::YEN: std::cout << "YEN";
    break;
  }
}