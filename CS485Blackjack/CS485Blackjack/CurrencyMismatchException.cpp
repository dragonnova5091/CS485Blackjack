//****************************************************************************
// File name:		CurrencyMismatchException.cpp
// Author:			Group 7
// Date:				4/11/21
// Class:				CS 485
// Assignment:	Assignment 4 Bank Accounts
// Purpose:			Implementation of CurrencyMismatchException.h
//****************************************************************************
#include "CurrencyMismatchException.h"


//***************************************************************************
// Constructor: CurrencyMismatchException
//
// Description: Initialize a CurrencyMismatchException
//
// Parameters:  
//
// Returned:    None
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException(int value)
{
  mValue = value;
}

//***************************************************************************
// Constructor: CurrencyMismatchException
//
// Description: Initialize a CurrencyMismatchException
//
// Parameters:  
//
// Returned:    None
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException
(const CurrencyMismatchException& cCME)
{
  mValue = cCME.mValue;
}

//***************************************************************************
// Destructor: ~CurrencyMismatchException
//
// Description: deallocate a CurrencyMismatchException
//
// Parameters:  
//
// Returned:    None
//***************************************************************************
CurrencyMismatchException::~CurrencyMismatchException()
{
}

//***************************************************************************
// Function:		operator=
//
// Description: Sets on CurrencyMismtachException object equal to another
//
// Parameters:  CurrencyMismatchException cME - the CurrencyMismatchException
//                                              object
//
// Returned:    A CurrencyMismatchException object that holds the new 
//              exception
//***************************************************************************
CurrencyMismatchException& CurrencyMismatchException::operator=
(CurrencyMismatchException cCME)
{
  mValue = cCME.mValue;
  return *this;
}

//***************************************************************************
// Function:		ourWhat
//
// Description: Currently does nothing according to assignment sheet
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
const void CurrencyMismatchException::ourWhat() const
{
}