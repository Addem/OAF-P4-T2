#include <iostream>
#include "library/linsearch.hpp"
#include "library/summation.hpp"
#include <fstream>

struct Account {
    std::string account_name_;
    int value_;
};

std::ostream& operator<<(std::ostream &f, const Account &acc ) {
    f << acc.account_name_;
    f << acc.value_;
    return f;
}

class MyLinSearch : public LinSearch<Account> {
    public:
     bool cond(const Account &e) const { return e.count>=5; }
};


int main() {
    std::ifstream f("test.txt");

}
