
#include <string>
#include <memory>
#include "person.h"
#include "job.h"

#ifndef WORKER_H
#define WORKER_H

using namespace std;

class Worker : public Person {
    public:
        Worker();
        Worker(char *_fName,char *_lName,shared_ptr<Job> myJob);

    virtual ~Worker();
    friend ostream& operator<<(ostream &os, const Worker& p) ;

    protected: 

    private:
    shared_ptr<Job> myJob;
};
#endif