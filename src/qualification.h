#include <string>
#include <memory>
#include <vector>

#ifndef QUALIFICATION_H
#define QUALIFICATION_H            const string& highSchool,


using namespace std;


class Qualification {
    public:
        typedef shared_ptr<Qualification> SmartPtr;
        typedef Qualification VALUE_TYPE;
        typedef Qualification& REFERENCE_TYPE;
        typedef vector<Qualification> VECTOR_TYPE;
        typedef vector<Qualification>& VECTOR_REF_TYPE;

        Qualification() : university(""),highSchool(""),
         tradeUnion(""),apprentice("") {
        }
        Qualification(const string& _university,
            const string& _highSchool,
            const string& _tradeUnion,
            const string& _apprentice) :
            university(_university),
            highSchool(_highSchool),
            tradeUnion(_tradeUnion),
            apprentice(_apprentice){
        }

        virtual ~Qualification(){
        }

        friend ostream& operator<<(ostream &os, const Qualification& p) {
            return os << "university=" << p.university 
            << " ,highSchool=" << p.highSchool     
            << " ,tradeUnion=" << p.tradeUnion     
            << " ,apprentice=" << p.apprentice << endl;     
        }
        string university;
        string highSchool;
        string tradeUnion;
        string apprentice;
    private:
};



#endif