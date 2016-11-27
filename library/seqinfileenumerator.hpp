#ifndef _SEQINFILEENUMERATOR_
#define _SEQINFILEENUMERATOR_

#include <fstream>
#include <typeinfo>

#include "enumerator.hpp"

template <typename Item>  // Item implementálja az operator>>-t
class SeqInFileEnumerator : public Enumerator<Item>
{
    protected:
        std::ifstream f;
        Item          df;

    public:
        enum Exceptions { OPEN_ERROR };
        SeqInFileEnumerator(const std::string& str){
            f.open(str.c_str());
            if(f.fail()) throw OPEN_ERROR;
            if(typeid(Item)==typeid(char)) f.unsetf(std::ios::skipws);
        }

        void first()         { next();}
        void next()          { f >> df;}
        bool end()     const { return f.eof();}
        Item current() const { return df; }
};

#endif
