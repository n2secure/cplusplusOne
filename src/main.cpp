#include <iostream>
#include <stdio.h>
#include <string.h>
#include "person.h"
#include "manager.h"
#include "worker.h"
#include "job.h"
#include "team.h"
#include "classA.h"
#include "person.h"
#include "qualification.h"
#include "tempClass.h"
#include "elementmap.h"
#include <memory>
#include <algorithm>
#include <iterator>

using namespace std;

// template class TempClass<Manager>;

extern void changeVector(Manager::VECTOR_STR& v);

// extern template <typename T> void printList(vector<T>& tList);

template void printList<int>(vector<int>& tList);
// template void printList<string>(vector<string>& tList);

template <typename T>
int TempClass<T>::myValue = 99; 

// bool sortFunc(const string& _a,const string& _b){
//     return _a.compare(_b);
// }

// template <typename T> void printList(vector<T> tList){
//     for (typename vector<T>::iterator it = tList.begin();
//         it != tList.end(); it++ ){
//             cout << "vactor is : " << *it << endl;
//     }
// }

shared_ptr<Qualification::VECTOR_TYPE> createQalifications(){
    Qualification::VECTOR_TYPE* vp = new vector<Qualification>();
    cout <<  "createQalifications() : new vector<Qualification>()" << endl;      
   
    shared_ptr<Qualification::VECTOR_TYPE> qv(vp);

   cout <<  "createQalifications()" << endl;      

    Qualification qua = Qualification(); 
    qua.university = "McGill";
    qua.highSchool = "One school";
    qua.tradeUnion = "no union";

    qv->push_back(qua);

    qua = Qualification();
    qua.university = "Toronto";
    qua.highSchool = "low school";
    qua.tradeUnion = "communist union";

    qv->push_back(qua);

    qua = Qualification();
    qua.university = "Queens";
    qua.highSchool = "montreal school";
    qua.tradeUnion = "auto union";

    qv->push_back(qua);

    return qv;
}

void func2(){
    map<ElementMap,string> myMap;
    ElementMap m1("a",999);
    myMap.insert(make_pair(m1,"999"));
    m1 = ElementMap("b",998);
    myMap.insert(make_pair(m1,"998"));
    m1 = ElementMap("c",997);
    myMap.insert(make_pair(m1,"997"));
    m1 = ElementMap("d",996);
    myMap.insert(make_pair(m1,"996"));
    m1 = ElementMap("e",995);
    myMap.insert(make_pair(m1,"995"));
    m1 = ElementMap("f",1);
    myMap.insert(make_pair(m1,"1"));

    for (ElementMap::MAP_TYPE_ITERATOR it = myMap.begin();
        it != myMap.end(); it++){
            cout << "elementMap is : []"<<it->first << ","
                <<it->second << "]" << endl;
        }

}

void lambdafunc(){
    int sum=0;
    auto f1 = [sum](int a){ return sum+a;};

    for (int i=0; i < 100; i++){
        sum += f1(i);
    }
    cout << "sum=" << sum << endl;

    sum=0;
    auto f2 = [&](int a){ sum+=a;};
    for (int i=0; i < 100; i++){
        f2(i);
    }
    cout << "sum=" << sum << endl;

   sum=0;
    auto f3 = [&sum](int a){ sum+=a;};
    for (int i=0; i < 100; i++){
        f3(i);
    }
    cout << "sum=" << sum << endl;
}

void func1(){

    char *ptr = new char[strlen("james")+1];
    strcpy(ptr,"james");
    char *qtr = new char[strlen("joyce")+1];
    strcpy(qtr,"joyce");
    shared_ptr<Qualification::VECTOR_TYPE> ptVec = createQalifications();
    std::shared_ptr<Manager> man(new Manager(ptr,qtr,*ptVec));
 
    for (typename vector<Qualification>::iterator it = man->getQualification().begin();
        it != man->getQualification().end(); it++ ){
            cout << "university is : " << it->university << endl;
    }

    //     string university;
    //     string highSchool;
    //     string tradeUnion;
    //     string apprentice;
    man->getIntList()->push_back(8);
    man->getIntList()->push_back(44);
    man->getIntList()->push_back(7);
    man->getIntList()->push_back(3);
    man->getIntList()->push_back(90);
    man->getIntList()->push_back(999);

    auto tot = count_if(man->getIntList()->begin(),man->getIntList()->end(),
        [](int num){ return num  > 100;});

    cout << "tot=" << tot << endl;

    sort(man->getIntList()->begin(),man->getIntList()->end(),[](const int& a,const int& b){ return a <b;});
    printList(*man->getIntList());

    copy(man->getIntList()->begin(),man->getIntList()->end(),
        ostream_iterator<int>(cout," ostream\n"));

    man->getSupervisors()->push_back("john");
    man->getSupervisors()->push_back("doe");
    man->getSupervisors()->push_back("one");
    man->getSupervisors()->push_back("two");
    man->getSupervisors()->push_back("jo");
    man->getSupervisors()->push_back(" jay");
    man->getSupervisors()->push_back("can");
    man->getSupervisors()->push_back("co");
    
    // sort(supervisors.begin(),supervisors.end(),Manager::MySortClass());
    // sort(supervisors.begin(),supervisors.end(),std::string::compare);
    // sort(supervisors.begin(),supervisors.end(),sortFunc);
    sort(man->getSupervisors()->begin(),man->getSupervisors()->end(),[=](const string& a,const string& b){ return a.compare(b);});

    printList(*man->getSupervisors());

    int xVal=0;
    cout << "xVal=" << xVal << endl;
    cout << "intVal=" << man-> getIntVal() << endl;
    changeVector(*man->getSupervisors());

    vector<string> v1 = *man->getSupervisors();
    cout << "value at 2=" << v1[1] << endl;
    
    printList(*man->getSupervisors());

    vector<string>::iterator it2 = man->getSupervisors()->end();
    it2--;
    do { 
         cout << "reverse vactor is : " << *it2 << endl;
    } while ( it2-- != man->getSupervisors()->begin());

    vector<string>::iterator it = find(man->getSupervisors()->begin(),man->getSupervisors()->end(),"one");
    if (it != man->getSupervisors()->end()){
        cout << "found value=" << *it << endl;
        man->getSupervisors()->erase(it);
    }    
    printList(*man->getSupervisors());

    man->getMap()->insert(make_pair<int,string>(1,"hello"));
    man->getMap()->insert(make_pair<int,string>(2,"you"));
    man->getMap()->insert(make_pair<int,string>(4,"me"));
    man->getMap()->insert(make_pair<int,string>(5,"tom"));

    MAP_INT_STR::iterator itMap = man->getMap()->find(1);
    if (itMap != man->getMap()->end()){
        cout << "map found value=" << itMap->second << endl;
    }

     cout << "iterate over map"<< endl;

    for (MAP_INT_STR::iterator it = man->getMap()->begin();
        it != man->getMap()->end(); it++){
            cout << "map is : first=" << it->first << " ,second=" <<
                it->second << endl;
    }


}



int main(int argc, char *argv[])
{
    lambdafunc();
    func2();
    func1();
    // char fArray[] = "clint";
    // char lArray[] = "eastwood";
    Person* person = 0;

    const string hello = "Hello";
    const string message =  hello+ ", world" + "!";
    const string exclam = "!";
    const string message2 = string("Hello") +  string(", world") + exclam;

    // char *strVal = hello.c_str();
    char str2[30] = "\0";
    
    // std::cout << strcpy(strVal,message.c_str())  << std::endl;
    std::cout << strcpy(str2,message.c_str())  << std::endl;

    std::cout << "hello=" << hello << std::endl;
    Team *team = new Team();

    // person = new Person(fArray,lArray);
    // team->addMember(person);

    char *ptr = new char[strlen("john")+1];
    strcpy(ptr,"john");
    char *qtr = new char[strlen("smith")+1];
    strcpy(qtr,"smith");
    person = new Manager(ptr,qtr,*createQalifications());
    int a1 = 10;
    person->addOne(a1);
    cout << "addOne reslt a1=" << a1 << endl;
    team->addMember(person);

    ptr = new char[strlen("james")+1];
    strcpy(ptr,"james");
    qtr = new char[strlen("joyce")+1];
    strcpy(qtr,"joyce");
    person = new Manager(ptr,qtr,*createQalifications());

    Manager mg(ptr,qtr,*createQalifications());
    const Manager& mRef = mg;
    mRef.getIntVal(); 

    Person *personNew = new Person();
    *personNew = *person;
    Person *personNew2 = new Person(*personNew);
    team->addMember(personNew2);

    ptr = new char[strlen("paul")+1];
    strcpy(ptr,"paul");
    qtr = new char[strlen("jones")+1];
    strcpy(qtr,"jones");
    // person = new Person(ptr,qtr);
    person = new Manager(ptr,qtr,*createQalifications(),"john harrison way");
    team->addMember(person);

    ptr = new char[strlen("james")+1];
    strcpy(ptr,"james");
    qtr = new char[strlen("smith")+1];
    strcpy(qtr,"smith");
    // person = new Person(ptr,qtr);
    person = new Person(ptr,qtr,"john harrison way");
    team->addMember(person);

    ptr = new char[strlen("jj")+1];
    strcpy(ptr,"jj");
    qtr = new char[strlen("cale")+1];
    strcpy(qtr,"cale");
    char *jtr = new char[strlen("musician")+1];
    strcpy(jtr,"musician");
    
    // Worker *worker = new Worker(ptr,qtr,shared_ptr<Job>(new Job(jtr)));
    Worker *worker = new Worker(ptr,qtr,shared_ptr<Job>(new Job(jtr)),"john harrison way");
   
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

