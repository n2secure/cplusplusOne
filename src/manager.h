
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

template <typename T> void printList(vector<T>& tList){
    for (typename vector<T>::iterator it = tList.begin();
        it != tList.end(); it++ ){
            cout << "vactor is : " << *it << endl;
    }
}


class Manager : public Person {
    public:
        typedef map<int,string> MAP_INT_STR;
        typedef vector<string> VECTOR_STR;
        typedef shared_ptr<vector<string> > VECTOR_PTR_STR;
        typedef vector<int> VECTOR_INT;
        typedef vector<Manager> VECTOR_TYPE;
        typedef shared_ptr<vector<int> > VECTOR_PTR_INT;
        typedef const vector<string> CONST_VECTOR_STR;
        typedef vector<string>::const_iterator CONST_VECTOR_ITERATOR;

        typedef map<int,string> MAP_TYPE;
        typedef shared_ptr<map<int,string>> MAP_PTR_TYPE;

        // Manager(int _age=0);
        // Manager(char *_fName,char *_lName,int _age=0);
        Manager(char *_fName,char *_lName,
            Qualification::VECTOR_REF_TYPE qRef,
            const string& address="");
            // const int _age=0,const string& address="");

        virtual ~Manager();
        friend ostream& operator<<(ostream &os, const Person& p) ;
        int getIntVal() const {
            return this->intVal;
        }
        void setIntVal(int _i){
            this->intVal = _i;
        } 
        Qualification::VECTOR_REF_TYPE  getQualification(){
            return  qualificationList;
        }
        VECTOR_PTR_INT  getIntList(){
            return  intList;
        }
        VECTOR_PTR_STR  getSupervisors(){
            return  supervisors;
        }
        MAP_PTR_TYPE  getMap(){
            return  mMap;
        }
        int getIntVal(){
            return intVal;
        }
    protected: 
        class MySortClass {
        public:    
            bool operator()(const string& _a,const string& _b){
                return _a.compare(_b);
            }
        };
        // void  changeVector(VECTOR_STR& v);

    private:
        // const int age;
        int intVal;
        Qualification::VECTOR_REF_TYPE  qualificationList;
        VECTOR_PTR_STR  supervisors;
        VECTOR_PTR_INT intList;
        MAP_PTR_TYPE  mMap;
};

#endif