//****************************************************************************
// File name:		Money.cpp
// Author:			Group 7
// Date:				3/19/21
// Class:				CS 485
// Assignment:	Assignment 3 Bank Accounts
// Purpose:			Implementation of Money.h
//****************************************************************************
#include "Money.h"

//***************************************************************************
// Constructor: Money
//
// Description: Initialize Money
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Money::Money()
{
	mAmount = 0;
	mpcCurrency = new Currency();
}

//***************************************************************************
// Constructor: Money
//
// Description: Initialize Money with parameter
//
// Parameters:  long long balance - the balance to initialize the amount
//
// Returned:    None
//***************************************************************************
Money::Money(long long balance, std::string pCurrency)
{
	mAmount = balance;
	mpcCurrency = new Currency(pCurrency);
}

//***************************************************************************
// Constructor: Money
//
// Description: Initialize Money with parameter
//
// Parameters:  Money& cMoney - the Money object to be copied from
//
// Returned:    None
//***************************************************************************
Money::Money(const Money& cMoney)
{
	mAmount = cMoney.mAmount;
	mpcCurrency = cMoney.mpcCurrency;
}

//***************************************************************************
// Destructor:  Money
//
// Description: Delete a Money object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Money::~Money() {
	//delete mpcCurrency;
	//This causes errors for some reason, so the majority of our vld erros come
		//from here
}

//***************************************************************************
// Function:		getAmount
//
// Description: Gets the amount of money
//
// Parameters:  None
//
// Returned:    The amount of money
//***************************************************************************
long long Money::getAmount()
{
	long long amount = mAmount;

	return amount;
}

//***************************************************************************
// Function:		setAmount
//
// Description: Set the amount of money 
//
// Parameters:  long long newAmount
//
// Returned:    None
//***************************************************************************
void Money::setAmount(long long newAmount)
{
	mAmount = newAmount;
}

//***************************************************************************
// Function:		getCurrencyType
//
// Description: Gets the currency type
//
// Parameters:  None
//
// Returned:    The currency type
//***************************************************************************
Currency Money::getCurrency() {
	return *mpcCurrency;
}

//***************************************************************************
// Function:		operator=
//
// Description: Sets on Money object equal to another
//
// Parameters:  Money rcMoney - the money object that will set
//
// Returned:    A money object that holds the new amount
//***************************************************************************
Money Money::operator= (const Money& rcMoney)
{
	CurrencyType cCurrTemp1 = mpcCurrency->getCurrencyType();
	CurrencyType cCurrTemp2 = rcMoney.mpcCurrency->getCurrencyType();

	try {
		if (cCurrTemp1 != cCurrTemp2) {
			throw CurrencyMismatchException();
		}
		else {
			mAmount = rcMoney.mAmount;
		}
	}
	catch (const CurrencyMismatchException& e) {
		e.ourWhat();
	}

	return *this;
}

//***************************************************************************
// Function:		operator+
//
// Description: Adds two Money objects together
//
// Parameters:  Money rcMoney - the money object to be added
//
// Returned:    A money object that holds the new amount
//***************************************************************************
Money Money::operator+ (const Money& rcMoney)
{
	CurrencyType cCurrTemp1 = mpcCurrency->getCurrencyType();
	CurrencyType cCurrTemp2 = rcMoney.mpcCurrency->getCurrencyType();

	try {
		if (cCurrTemp1 != cCurrTemp2) {
			throw CurrencyMismatchException();
		}
		else {
			mAmount += rcMoney.mAmount;
		}
	}
	catch (const CurrencyMismatchException& e) {
		e.ourWhat();
	}

	return *this;
}
//***************************************************************************
// Function:		operator-
//
// Description: Subtracts one money object from another
//
// Parameters:  Money rcMoney - the money object to be subtracted
//
// Returned:    A money object that holds the new amount
//***************************************************************************
Money Money::operator- (const Money& rcMoney)
{
	CurrencyType cCurrTemp1 = mpcCurrency->getCurrencyType();
	CurrencyType cCurrTemp2 = rcMoney.mpcCurrency->getCurrencyType();

	try {
		if (cCurrTemp1 != cCurrTemp2) {
			throw CurrencyMismatchException();
		}
		else {
			mAmount -= rcMoney.mAmount;
		}
	}
	catch (const CurrencyMismatchException& e) {
		e.ourWhat();
	}

	//mAmount -= rcMoney.mAmount;
	return *this;
}