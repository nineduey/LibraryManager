#include "patron.h"


Patron::Patron(){

	lastName = "";
	firstName = "";
}

Patron::~Patron(){

	int i;
	for (i = 0; i < patronHistory.size(); i++){
		patronHistory[i].first = nullptr;
	}
}

bool Patron::setData( int patronID, istream& inFile){
	
	if (patronID < 1000 || patronID > 9999){
		cout << "ERROR: Patron ID " << patronID << " is not valid." << endl;
		this->patronID = -1;
		return false;
	}
	this->patronID = patronID;

	inFile.get();
	inFile >> this->lastName;
	if(lastName.size() < 1){
		cout << "ERROR: Patron's Last Name is not given." << endl;
		return false;
	}

	getline(inFile, this->firstName);
	if(firstName.size() < 1){
		cout << "ERROR: Patron's First Name is not given." << endl;
		return false;
	}

	return true;
}

void Patron::addToHistory( Item* item, string transType){

	patronHistory.push_back( make_pair(item,transType) );
}

vector<pair<Item*, string>> Patron::getHistory() const{
	
	return patronHistory;
}

bool Patron::transExists(Item* item, string transType)
{
	for(int i = 0; i < patronHistory.size(); i++){

		if(patronHistory[i].first == item && patronHistory[i].second == transType){
			return true;
		}
	}
	return false;
}

void Patron::print( ostream& out ) const{

	out << patronID << "   " << lastName << ",  " << firstName;
}

void Patron::printHistory( vector<pair<Item*, string>> historyVec ) const{
	
	if(historyVec.empty()){
		cout << "Patron has not made any valid transactions." << endl;
		return;
	}

	for(int i = 0; i < historyVec.size(); i++){
		cout << historyVec[i].second << "   ";
		cout << left << *historyVec[i].first << endl;
	} 
}

void Patron::setPatronID( int patronID ){

	this->patronID = patronID;
}

int Patron::getPatronID(){

	return this->patronID;
}

ostream& operator<<( ostream& out, const Patron& p){

	p.print( out );
	return out;
}
