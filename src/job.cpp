
#include <iostream>
#include <memory>

#include "job.h"
using namespace std;

Job::Job(){
}

Job::Job(char *name){
    this->name = shared_ptr<char>(name);
}


Job::~Job(){
}

ostream& operator<<(ostream &os, const Job& j) {
    return os << "job name=" << j.name;
}

