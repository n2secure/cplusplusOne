
#include <iostream>
#include <memory>

#include "person.h"
#include "worker.h"
#include "team.h"

Worker::Worker(){
}

// Worker::Worker(char *_fName,char *_lName,shared_ptr<Job> myJob) : 
//     Person(_fName,_lName),myJob(myJob) {
// }

Worker::Worker(char *_fName,char *_lName,shared_ptr<Job> myJob,const string& address) : 
    Person(_fName,_lName,address),myJob(myJob) {
}

ostream& operator<<(ostream &os, const Worker& w) {
     return os << "first=" << w.fName << " ,last=" << w.lName << " job : " << *w.myJob;
}

Worker::~Worker(){
}


