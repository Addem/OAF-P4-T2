#include <iostream>
#include "library/linsearch.hpp"
#include "library/counting.hpp"
#include "library/summation.hpp"
#include "library/seqinfileenumerator.hpp"
#include <fstream>

struct Pair {
  std::string name;
  int sum;
  friend std::ostream& operator<<(std::ostream&, const &Pair);
  friend std::istream& operator>>(std::istream&, Pair&);
};

std::istream& operator>>(std::istream &f, Pair &pa) {
  f >> pa.name >> pa.sum;
  return f;
}

std::ostream& operator<<(std::ostream& o, const Pair &pa) {
  o << pa.name << "\t" << pa.sum << std::endl;
  return o;
}

class MyLinSearch : public LinSearch<Pair> {
  public:
   bool cond(const Pair &p) const { return p.sum<-100000; }
};

class PairEnumerator : public Enumerator<Pair> {
  protected:
   SeqInFileEnumerator<Pair> *_f;
   Pair _current;
   bool _end;
  public:
   PairEnumerator(const Pair& str) { _f = new SeqInFileEnumerator<Pair>(str); }
   ~PairEnumerator(){ delete _f; }
   void first() { _f->first(); next(); }
   void next();
   bool end() const { return _end;}
   Pair current() const { return _current; }
};

/*class PairSum : public Summation<Pair> {
  protected:
   string _name;
   void first(){}
   void add 
   bool whileCond(const Pair& e) const { return e.name == _name; }
  public:
   PairSum(const Pair &str):
   Summation<Pair>(), _name(str){}
};*/
/*
void PairEnumerator::next() {
  if((_end = _f->end())) return;
  _current.pname = _f->current();
  PairSum pr(_current.pname); pr.addEnumerator(_f);
  pr.run();
  _current.sum = pr.result();
} */

int main() {
  MyLinSearch pr;
  //PairEnumerator t("test.txt"); pr.addEnumerator(&t);
  pr.run();
  
  if (pr.found()) std::cout << "Eredmeny: Nem" << std::endl;
  else std::cout<< "Eredmeny: Igen" << std::endl;
}
