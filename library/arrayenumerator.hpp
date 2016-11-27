#ifndef _ARRAYENUMERATOR_
#define _ARRAYENUMERATOR_

#include "enumerator.hpp"
#include <vector>

template <typename Item>
class ArrayEnumerator : public Enumerator<Item>
{
    protected:
        std::vector<Item> *_vect;
        int   _ind;

    public:
        ArrayEnumerator(std::vector<Item> *v):_vect(v) {}

        void first(){ _ind = 0;}
        void next() { ++_ind; }
        bool end()    const { return _ind>=(int)_vect->size();}
        Item current()const { return (*_vect)[_ind];}
};

#endif
