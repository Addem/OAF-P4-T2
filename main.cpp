#include <iostream>
#include "library/linsearch.hpp"
#include "library/summation.hpp"
#include "library/seqinfileenumerator.hpp"
#include <fstream>

struct Pair {
  std::string name;
  int payment;
  int sum;
  friend std::ostream& operator<<(std::ostream&, const &Pair);
  friend std::istream& operator>>(std::istream&, Pair&);
};

std::istream& operator>>(std::istream &f, Pair &pa) {
  f >> pa.name >> pa.payment;
  return f;
}

std::ostream& operator<<(std::ostream& o, const Pair &pa) {
  o << pa.name << "\t" << pa.sum << std::endl;
  return o;
}

class MyLinSearch : public LinSearch<Pair> {
  public:
   bool cond(const Pair &p) const { return p.sum < -100000; }
};

class PairEnumerator : public Enumerator<Pair> {
  protected:
   SeqInFileEnumerator<Pair> *_f;
   Pair _current;
   bool _end;
  public:
   PairEnumerator(const std::string &file_name_) { _f = new SeqInFileEnumerator<Pair>(file_name_); }
   ~PairEnumerator(){ delete _f; }
   void first() { _f->first(); next(); }
   void next();
   bool end() const { return _end;}
   Pair current() const { return _current; }
};

class PairSum : public Summation<Pair, int> {
  private:
   const std::string name_;
   int current_sum_;
  protected:
   void first() {}
   void init() { current_sum_ = 0; }
   bool whileCond(const Pair& e) const { return e.name == name_; }
   void add(const Pair &e ) { current_sum_ += e.payment; *_result = current_sum_; }
  public:
   PairSum( std::string &name ):
   Summation<Pair, int>(), name_(name) {}
};

void PairEnumerator::next() {
  if((_end = _f->end())) return;
  _current.name = _f->current().name;
  PairSum pr(_current.name); pr.addEnumerator(_f);
  pr.run();
  _current.sum = pr.result();
}

int main() {
  MyLinSearch pr;
  PairEnumerator t("test.txt"); pr.addEnumerator(&t);
  pr.run();
  
  if (pr.found()) std::cout << "Eredmeny: Nem" << std::endl;
  else std::cout<< "Eredmeny: Igen" << std::endl;
}
