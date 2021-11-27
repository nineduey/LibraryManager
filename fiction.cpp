#include "fiction.h"

Fiction::Fiction()
{
	//set default values here!

	//itemType = 'B';

	bookType = 'F';

	numInLib = 0;

	maxNumInLib = 5;

	author = "";
}

Fiction::~Fiction()
{
}

Item& Fiction::operator=( const Item& item)
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	this->title = aFiction.title;
	this->year = aFiction.year;
	this->author = aFiction.author;
	this->numInLib = aFiction.numInLib;

	return *this;
}

bool Fiction::operator==( const Item& item )
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	return (this->title == aFiction.title && this->author == aFiction.author);
}

bool Fiction::operator!=( const Item& item )
{
	return !this->operator==( item );
}

bool Fiction::operator<( const Item& item )
{
	//sorted by author, then title

	if (this->operator==( item ))
	{
		return false;
	}

	const Fiction& aFiction = static_cast<const Fiction&>(item);

	if (this->author < aFiction.author)
	{
		return true;
	}
	else if (this->author == aFiction.author)
	{
		return this->title < aFiction.title;
	}
}

bool Fiction::operator>( const Item& item )
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	if (this->operator==( aFiction ) || this->operator<( aFiction ))
	{
		return false;
	}

	if (this->author > aFiction.author)
	{
		return true;
	}
	else if (this->author == aFiction.author)
	{
		return this->title > aFiction.title;
	}
}

Item* Fiction::create() const
{
	return new Fiction;
}

void Fiction::setData( istream& infile)
{
	getline( infile, author, ',' );     // input author, looks for comma terminator

	/*infile.get();

	getline( infile, authorLast, ',' );*/

	infile.get();                     // get (and ignore) blank before title

	getline( infile, title, ',' );      // input title

	infile >> year;                   // input year

	//do we set numInLib and maxNumInLib here


}

ostream& operator<<( ostream&, const Item& item)
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	cout << aFiction.numInLib << setw(AVAILABILITY_LENGTH) <<
}
