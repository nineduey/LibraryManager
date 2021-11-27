/*
@File contents: LibraryManager.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------

#include "librarymanager.h"
#include "storage.h"
#include "hashmap.h"
#include "bookfactory.h"
#include "book.h"
#include "transaction.h"



//-----------------------------------------------------------------------------
void LibraryManager::readInventory(istream& inFile){

    Book* tempBook;
	 char bookType;
	
	 while (!inFile.eof()) {
		  inFile >> bookType;
		  tempBook = bf.createBook(bookType);
		  inFile.get();
		  tempBook.setData(inFile);
	 }
}

//-----------------------------------------------------------------------------
void LibraryManager::readCustomer(istream& inFile) {

}

//-----------------------------------------------------------------------------
void LibraryManager::readTransaction(istream& inFile) {

}
