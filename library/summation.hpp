#ifndef SUMMATION_HPP
#define SUMMATION_HPP

#include "procedure.hpp"

template < typename Item, typename Range = Item >
class Summation : public Procedure<Item>
{
    protected:
        Range *_result;
        bool _inref;

        Summation(){ _inref = true; _result = new Range; }
        Summation(Range *r){ _inref = false; _result = r; }
        void init() {}
        void body(const Item& e){ if(cond(e)) add(e); }
        virtual void add(const Item& e) = 0;
        virtual bool cond(const Item& e) const { return true;}
    public:
        Range result() { return *_result; }
        ~Summation(){ if(_inref) delete _result;}
};

#endif
