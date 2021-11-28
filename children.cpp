#include "children.h"
#include <iomanip>

// sorted by title, then author
//----------------------------------------------------------------------------
// Default Constructor
Children::Children()
{
    author = "";
}

//----------------------------------------------------------------------------
// Destructor
<<<<<<< Updated upstream
Children::~Children(){}
=======
Children::~Children() {}
>>>>>>> Stashed changes

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
//@post:
Item& Children::operator=(const Item& item) {
    const Children& aChildren = static_cast<const Children&>(item);

    this->title = aChildren.title;
    this->year = aChildren.year;
    this->author = aChildren.author;
    this->numInLib = aChildren.numInLib;

    return *this;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Children::operator==(const Item& item) {
    const Children& aChildren = static_cast<const Children&>(item);

    return (this->title == aChildren.title && this->author == aChildren.author);
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Children::operator!=(const Item& item) {
    return !this->operator==(item);
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Children::operator<(const Item& item) {
    if (this->operator==(item)) {
        return false;
    }

    const Children& aChildren = static_cast<const Children&>(item);

    if (this->title < aChildren.title) {
        return true;
    }
    else if (this->title == aChildren.title) {
        return this->author < aChildren.author;
    }
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Children::operator>(const Item& item) {
    if (this->operator==(item) || this->operator<(item)) {
        return false;
    }

    const Children& aChildren = static_cast<const Children&>(item);

    if (this->title > aChildren.title) {
        return true;
<<<<<<< Updated upstream
    } 
=======
    }
>>>>>>> Stashed changes
    else if (this->title == aChildren.title) {
        return this->author > aChildren.author;
    }
}

//----------------------------------------------------------------------------
//create() : 
//@pre:
//@post:
Item* Children::create() const {
<<<<<<< Updated upstream
	 return new Children;
=======
    return new Children;
>>>>>>> Stashed changes
}

//----------------------------------------------------------------------------
//setData(): 
//@pre:
//@post:
void Children::setData(istream& infile) {
    getline(infile, author, ',');     // input author, looks for comma terminator

    /*infile.get();
    getline( infile, authorLast, ',' );*/

    infile.get();                // get (and ignore) blank before title
    getline(infile, title, ','); // input title
    infile >> year;              // input year

    itemType = 'B';     // setting itemType -> Item class
    numInLib = 5;          // setting numer of Book copies -> Item class
    bookType = 'C';        // setting bookType -> Book class
<<<<<<< Updated upstream
    
}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Children& aChildrenBook) {
	 aChildrenBook.print(out);
	 return out;
}

//----------------------------------------------------------------------------
void Children::print(ostream& os) const {
	 cout << numInLib << "     " << author << "     " << title << "     " << year;
=======

}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Children& aChildrenBook) {
    aChildrenBook.print(out);
    return out;
>>>>>>> Stashed changes
}

//----------------------------------------------------------------------------
void Children::print(ostream& os) const {
    cout << numInLib << "     " << author << "     " << title << "     " << year;
}