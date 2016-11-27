#ifndef COUNTING_HPP
#define COUNTING_HPP

#include "summation.hpp"

template < typename Item >
class Counting : public Summation<Item, int>
{
    public:
        Counting():Summation<Item,int>(){}

    protected:

        void init()             { *Summation<Item,int>::_result = 0;}
        void add(const Item& e) { ++*Summation<Item,int>::_result;}
};

#endif
