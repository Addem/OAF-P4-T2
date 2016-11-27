#ifndef _PROCEDURE_
#define _PROCEDURE_
#include <cstddef>
#include "enumerator.hpp"

template <typename Item>
class Procedure
{
    protected:
        Enumerator<Item> *_enor;

        Procedure():_enor(NULL){}
        virtual void init() = 0;
        virtual void body(const Item& current) = 0;
        virtual void first() {_enor->first();}
        virtual bool whileCond(const Item& current) const { return true; }
        virtual bool loopCond() const
                   { return !_enor->end() && whileCond(_enor->current()) ; }
    public:
        enum Exceptions { MissingEnumerator};
        void run();
        void addEnumerator(Enumerator<Item>* en){ _enor = en;}
        virtual ~Procedure(){}
};

template <class Item>
void Procedure<Item>::run()
{
    if(_enor==NULL) throw MissingEnumerator;
    init();
    for(first(); loopCond(); _enor->next()){
        body(_enor->current());
    }
}

#endif
