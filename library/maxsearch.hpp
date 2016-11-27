#ifndef _MAXSEARCH_
#define _MAXSEARCH_

#include "procedure.hpp"


template <typename Value> // Value implementálja: operator<, operator>
class Greater{
    public:
        bool operator()(const Value& l, const Value& r){
            return l > r;
        }
};

template <typename Value> // Value implementálja: operator<, operator>
class Less{
    public:
        bool operator()(const Value& l, const Value& r){
            return l < r;
        }
};

template <typename Item, typename Value = Item, typename Compare = Greater<Value> >
class MaxSearch : public Procedure<Item>
{
    protected:
        bool    _l;
        Item    _optelem;
        Value   _opt;
        Compare _better;

        void init(){ _l = false;}
        void body(const Item& current);

        virtual Value func(const Item& e) const = 0;
        virtual bool  cond(const Item& e) const { return true;}

    public:
        bool found()   const { return _l;}
        Value opt()    const { return _opt;}
        Item optElem() const { return _optelem;}
};

template <class Item, class Value, class Compare>
void MaxSearch<Item,Value,Compare>::body(const Item& current)
{
    Value val = func(current);
    if ( !cond(current) ) return;
    if (_l){
        if (_better(val,_opt)){
            _opt = val;
            _optelem = current;
        }
    }
    else {
        _l = true;
        _opt = val;
        _optelem = current;
    }
}

#endif
