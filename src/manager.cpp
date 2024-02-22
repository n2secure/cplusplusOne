
#include <iostream>
#include <utility>

#include "person.h"
#include "manager.h"
#include "team.h"
#include "qualification.h"

using namespace std;

Manager::Manager(int _age) : age(_age){
}

void Manager::changeVector(VECTOR_STR& v){
    cout << "change vector" << endl;
    for (VECTOR_STR::iterator it = v.begin();
            it != v.end(); it++){
          *it = *it + " new"; 
    }
}

bool sortFunc(const string& _a,const string& _b){
    return _a.compare(_b);
}

template <typename T> void printList(vector<T> tList){
    for (typename vector<T>::iterator it = tList.begin();
        it != tList.end(); it++ ){
            cout << "vactor is : " << *it << endl;
    }
}


Manager::Manager(char *_fName,char *_lName,const int _age) : Person(_fName,_lName),age(_age) {

    Qualification qua = Qualification(); 
    qua.university = "McGill";
    qua.highSchool = "One school";
    qua.tradeUnion = "no union";

    qualificationList.push_back(qua);

    qua = Qualification();
    qua.university = "Toronto";
    qua.highSchool = "low school";
    qua.tradeUnion = "communist union";

    qualificationList.push_back(qua);

    qua = Qualification();
    qua.university = "Queens";
    qua.highSchool = "montreal school";
    qua.tradeUnion = "auto union";

    qualificationList.push_back(qua);
    
    for (typename vector<Qualification>::iterator it = qualificationList.begin();
        it != qualificationList.end(); it++ ){
            cout << "university is : " << it->university << endl;
    }

    qualificationList.push_back(qua);

    //     string university;
    //     string highSchool;
    //     string tradeUnion;
    //     string apprentice;


    intList.push_back(8);
    intList.push_back(44);
    intList.push_back(7);
    intList.push_back(3);
    intList.push_back(90);
    intList.push_back(999);

    sort(intList.begin(),intList.end(),[](const int& a,const int& b){ return a <b;});
    printList(intList);

    supervisors.push_back("john");
    supervisors.push_back("doe");
    supervisors.push_back("one");
    supervisors.push_back("two");
    supervisors.push_back("jo");
    supervisors.push_back(" jay");
    supervisors.push_back("can");
    supervisors.push_back("co");
    
    // sort(supervisors.begin(),supervisors.end(),Manager::MySortClass());
    // sort(supervisors.begin(),supervisors.end(),std::string::compare);
    // sort(supervisors.begin(),supervisors.end(),sortFunc);
    sort(supervisors.begin(),supervisors.end(),[](const string& a,const string& b){ return a.compare(b);});

    printList(supervisors);

    int xVal=0;
    cout << "xVal=" << xVal << endl;
    cout << "intVal=" << intVal << endl;
    changeVector(supervisors);

    cout << "value at 2=" << supervisors[1] << endl;
    
    printList(supervisors);

    vector<string>::iterator it2 = supervisors.end();
    it2--;
    do { 
         cout << "reverse vactor is : " << *it2 << endl;
    } while ( it2-- != supervisors.begin());

    vector<string>::iterator it = find(supervisors.begin(),supervisors.end(),"one");
    if (it != supervisors.end()){
        cout << "found value=" << *it << endl;
        supervisors.erase(it);
    }    
    printList(supervisors);

    mMap.insert(make_pair<int,string>(1,"hello"));
    mMap.insert(make_pair<int,string>(2,"you"));
    mMap.insert(make_pair<int,string>(4,"me"));
    mMap.insert(make_pair<int,string>(5,"tom"));

    MAP_INT_STR::iterator itMap = mMap.find(1);
    if (itMap != mMap.end()){
        cout << "map found value=" << itMap->second << endl;
    }

     cout << "iterate over map"<< endl;

    for (MAP_INT_STR::iterator it = mMap.begin();
        it != mMap.end(); it++){
            cout << "map is : first=" << it->first << " ,second=" <<
                it->second << endl;
    }

}


Manager::~Manager(){
}



