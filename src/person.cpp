
#include <iostream>

#include "person.h"
#include "team.h"

Person::Person(){
}

//Person::Person(char *_fName,char *_lName){
Person::Person(char *_fName,char *_lName,const string& _address) : 
    address(_address) {
    init(_fName,_lName);
}

Person::Person(const Person& p){
   cout << "copy constrtctor called" << endl;
   this->fName = p.fName;
    this->lName = p.lName;
}

Person& Person::operator=(const Person& p){
   cout << "= operator called" << endl;
   this->fName = p.fName;
    this->lName = p.lName;
    return *this;
}


void Person::init(char *_fName,char *_lName){
    this->fName = _fName;
    this->lName = _lName;
}

Person::~Person(){
    if (this->fName){
        delete  this->fName;
    }
    if (this->lName){
        delete
          this->lName;
    }
}

ostream& operator<<(ostream &os, const Person& p) {
    return os << "first=" << p.fName << " ,last=" << p.lName ;
}

