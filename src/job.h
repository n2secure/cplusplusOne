
#include <string>
#include <memory>
#include <iostream>

#ifndef JOB_H
#define JOB_H

using namespace std;

class Job  {
    public:
        Job();
        Job(char *name);

    virtual ~Job();
    friend ostream& operator<<(ostream &os, const Job& j) ;

    protected: 

    private:
        shared_ptr<char> name;

};
#endif