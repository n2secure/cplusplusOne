#include <iostream>
#include <stdio.h>
#include <string.h>
#include "person.h"
#include "manager.h"
#include "worker.h"
#include "job.h"
#include "team.h"

int main(int argc, char *argv[])
{
    // char fArray[] = "clint";
    // char lArray[] = "eastwood";
    Person* person = 0;

    Team *team = new Team();

    // person = new Person(fArray,lArray);
    // team->addMember(person);

    char *ptr = new char[strlen("john")+1];
    strcpy(ptr,"john");
    char *qtr = new char[strlen("smith")+1];
    strcpy(qtr,"smith");
    person = new Manager(ptr,qtr);
    int a1 = 10;
    person->addOne(a1);
    cout << "addOne reslt a1=" << a1 << endl;
    team->addMember(person);

    ptr = new char[strlen("james")+1];
    strcpy(ptr,"james");
    qtr = new char[strlen("joyce")+1];
    strcpy(qtr,"joyce");
    person = new Manager(ptr,qtr);
    Person *personNew = new Person();
    *personNew = *person;
    Person *personNew2 = new Person(*personNew);
    team->addMember(personNew2);

    ptr = new char[strlen("paul")+1];
    strcpy(ptr,"paul");
    qtr = new char[strlen("jones")+1];
    strcpy(qtr,"jones");
    person = new Person(ptr,qtr);
    team->addMember(person);

    ptr = new char[strlen("james")+1];
    strcpy(ptr,"james");
    qtr = new char[strlen("smith")+1];
    strcpy(qtr,"smith");
    person = new Person(ptr,qtr);
    team->addMember(person);

    ptr = new char[strlen("jj")+1];
    strcpy(ptr,"jj");
    qtr = new char[strlen("cale")+1];
    strcpy(qtr,"cale");
    char *jtr = new char[strlen("musician")+1];
    strcpy(jtr,"musician");
    
    Worker *worker = new Worker(ptr,qtr,shared_ptr<Job>(new Job(jtr)));
    team->addMember(worker);

    std::cout << "hello world" << std::endl;
    // if (person){
    //      delete[] person;
    // }
    if (team){
        delete team;
    }

    return 0;
}

