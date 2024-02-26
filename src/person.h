
#include <string>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person {
    public:
        Person();
        Person(const Person& p);
        // Person(char *_fName,char *_lName);
        Person(char *_fName,char *_lName,const string& address);
        Person& operator=(const Person& p);
        virtual void init(char *_fName,char *_lName);
        const string& getAddress() const;

    virtual ~Person();
    friend ostream& operator<<(ostream &os, const Person& p) ;
    // void addOne(int a){
    //     a++;
    //     cout << "addOne by value a=" << a << endl;
    // }
    void addOne(int& a){
        a++;
        cout << "addOne by ref a=" << a << endl;
    }

    protected: 
        char *fName;
        char*lName;
        int age;
        const string address;

    private:

};
#endif