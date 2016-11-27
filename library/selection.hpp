#ifndef _SELECTION_
#define _SELECTION_

#include "procedure.hpp"

template < class Item >
class Selection : public Procedure<Item> {
   protected:
       void init(){}
       virtual bool cond(const Item& e) const = 0;
       void body(const Item& e) {}
       bool loopCond() const { return !cond(Procedure<Item>::_enor->current());}
};

#endif
