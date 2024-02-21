
#include <string>
#include <list>
#include "person.h"
#include "worker.h"

using namespace std;

class Team {
    public:
        Team(list<Person*> pList);
        Team();
        void addMember(Person *person);
        void addMember(Worker *person);

        virtual ~Team();

    protected: 

    private:
        list<Person*> pList;

};