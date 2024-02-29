
#include <iostream>
#include <string>

using namespace std;

#ifndef ELEMENT_MAP
#define ELEMENT_MAP

class ElementMap{
    public:
        typedef map<ElementMap,string> MAP_TYPE;
        typedef map<ElementMap,string>::iterator MAP_TYPE_ITERATOR;
        
        ElementMap(string strVal,int intVal){
            cout << "constructor()" << endl;
            this->strVal = strVal;
            this->intVal = intVal;
        }
        ElementMap(const ElementMap& e){
            cout << "copy constructor()" << endl;
            this->strVal = e.strVal;
            this->intVal = e.intVal;
        }
        ElementMap& operator=(const ElementMap& oth)  {
            cout << "assignment operator" << endl;
            this->strVal = oth.strVal;
            this->intVal = oth.intVal;
            return *this;
        }
        bool operator<(const ElementMap& oth) const {
            if (intVal < oth.intVal){
                return true;
            } else if  (intVal > oth.intVal){
                return false;
            } else {
                if (strVal < oth.strVal){
                    return true;
                } else if (strVal > oth.strVal){
                    return false;
                } else {
                    return true;
                }
            }
        }
    friend ostream& operator<<(ostream& os, const ElementMap& e){
        cout << "elementMap strVal=" << e.strVal << " ,intVal=" << e.intVal << endl;
        return os;
    }
    protected:
    private:
        string strVal;
        int intVal;
};

#endif