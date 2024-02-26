
#include <iostream>
#include <utility>

#include "person.h"
#include "manager.h"
#include "team.h"
#include "qualification.h"
#include "tempClass.h"

using namespace std;


// template class TempClass<Manager>;

template <class T>
int TempClass<T>::myValue=10;

void changeVector(VECTOR_STR& v){
    cout << "change vector" << endl;
    for (VECTOR_STR::iterator it = v.begin();
            it != v.end(); it++){
          *it = *it + " new"; 
    }
}


// Manager::Manager(int _age) : age(_age){
// }

        // Manager(char *_fName,char *_lName,
        //     Qualification::VECTOR_REF_TYPE qRef,
        //     const int _age=0,const string& address="");

//Manager::Manager(char *_fName,char *_lName,const int _age) : Person(_fName,_lName),age(_age) {
Manager::Manager(char *_fName,char *_lName,
            Qualification::VECTOR_REF_TYPE qRef,
        const string& address) : Person(_fName,_lName,address),
        qualificationList(qRef),intList(new vector<int>()),
        supervisors(new vector<string>()),
        mMap(new map<int,string>())  {

    cout <<  "Manager::Manager()" << endl;      
 
}


Manager::~Manager(){
}



