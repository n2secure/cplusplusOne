#include <iostream>

#include "person.h"
#include "team.h"

using namespace std;

Team::Team(list<Person*> pList){
    this->pList = pList;
}
Team::Team(){
}

void Team::addMember(Person *person){
    cout << "add person : " << *person << endl;
    this->pList.push_back(person);    
}
void Team::addMember(Worker *person){
    cout << "add worker : " << *person << endl;
    this->pList.push_back(person);    
}

Team::~Team(){
    cout << "Team::~Team()" << endl;
    list<Person*>::iterator itr = pList.end();
    // itr--;
    bool bContinue=true;
   while (itr-- != pList.begin()){
        Person *ptr = *itr;
        std::cout << "delete person=" << *ptr << std::endl;
        delete ptr;
        // if (itr == pList.begin()){
        //     break;
        // }
    } 
}
