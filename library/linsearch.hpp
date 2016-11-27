#ifndef _LINSEARCH_
#define _LINSEARCH_

#include "procedure.hpp"

template < typename Item, bool optimist = false>
class LinSearch : public Procedure<Item>
{
    protected:
        bool _l;
        Item _elem;

        void init(){ _l = optimist; }
        void body(const Item& e){ _l = cond(_elem = e); }
        bool whileCond(const Item& e) const { return optimist?_l:!_l;}

        virtual bool cond(const Item& e) const = 0;

    public:
        bool found()  const{ return _l; }
        Item elem()   const{ return _elem;}
};

#endif
