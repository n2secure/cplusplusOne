
#include <string>
#include "person.h"

#ifndef MANAGER_H
#define MANAGER_H

using namespace std;

class Manager : public Person {
    public:
        Manager();
        Manager(char *_fName,char *_lName);

    virtual ~Manager();
    friend ostream& operator<<(ostream &os, const Person& p) ;

    protected: 

    private:

};
#endif