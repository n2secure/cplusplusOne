
#include <string.h>
#include <stdio.h>
#include <string>
#include "person.h"
#include "qualification.h"
#include <vector>
#include <map>
#include <algorithm>

#ifndef MANAGER_H
#define MANAGER_H

using namespace std;

typedef map<int,string> MAP_INT_STR;
typedef vector<string> VECTOR_STR;
typedef const vector<string> CONST_VECTOR_STR;
typedef vector<string>::const_iterator CONST_VECTOR_ITERATOR;

class Manager : public Person {
    public:
        Manager(int _age=0);
        Manager(char *_fName,char *_lName,int _age=0);

        virtual ~Manager();
        friend ostream& operator<<(ostream &os, const Person& p) ;
        int getIntVal() const {
            return this->intVal;
        }
        void setIntVal(int _i){
            this->intVal = _i;
        } 

    protected: 
        class MySortClass {
        public:    
            bool operator()(const string& _a,const string& _b){
                return _a.compare(_b);
            }
        };
        void  changeVector(VECTOR_STR& v);

    private:
        const int age;
        int intVal;
        vector<Qualification>  qualificationList;
        vector<string>  supervisors;
        vector<int>  intList;
        map<int,string>  mMap;
};

#endif