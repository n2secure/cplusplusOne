
#include <vector>

#ifndef TEMPCLASS_H
#define TEMPCLASS_H

template <typename T >
class TempClass {
private:

    typename T::VECTOR_TYPE&   tList;

public:
    TempClass(typename T::VECTOR_TYPE vt) : tList(vt) {
    }

    typename T::VECTOR_TYPE getList(){
        return tList;
    }
    void setList(typename T::VECTOR_TYPE vt){
        tList = vt;
    }
    static int myValue;
};

#endif
