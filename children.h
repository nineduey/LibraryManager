/*
@File contents: Children class function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef CHILDREN_H
#define CHILDREN_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Children : public Book
{

public:
    Children();
    virtual ~Children();
    virtual char returnItemType() const;
    virtual char returnItemType_Genre() const;
    virtual Item* create() const;
    virtual void setData( istream& );
    virtual void setData( string, string );
	virtual void setData( string, int, int);
    virtual void print( ostream& os ) const;
	virtual void printHeader() const;
	
    //virtual comparison operators
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

private:
    string author; // author of children book
	string const HEADER = "CHILDRENS BOOKS";
};

#endif


