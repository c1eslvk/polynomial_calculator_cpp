#include <iostream>
#include <map>
#include <iterator>
#include <cmath>
#include "Poly.h"

using namespace std;

Poly::Poly() {}

Poly::Poly(double value) {
    entries[0] = value;
}

Poly::Poly(const Poly& other) {
    this->entries = other.entries;
}

Poly::~Poly() {}

double& Poly::operator[](int power) {
    return entries[power];
}

ostream& operator<<(ostream& os, const Poly& p) {
    if (p.entries.empty()) {
        os << "0";
    }
    else {
        long unsigned int count0 = 0;
        for (auto i = p.entries.rbegin(); i != p.entries.rend(); ++i) {
            if (i->second != 0) {
                if (i != p.entries.rbegin()) {
                    if (i->second > 0) {
                        os << " + ";
                    }
                    else {
                        os << " - ";
                    }
                } else {
                    if (i->second < 0) {
                        os << "- ";
                    }
                } 
                if (abs(i->second) != 1) {
                    os << abs(i->second);
                }
                if (i->first != 0) {
                    os << "x";
                    if (i->first != 1) {
                        os << "^" << i->first;
                    }
                }
            }
            else {
                count0++;
            }
        }
        if (count0 == p.entries.size()) {
            os << "0";
        }
    }
    return os;
}


Poly Poly::operator-() const { 
    Poly temp(*this);

    for (auto i = temp.entries.begin(); i != temp.entries.end(); ++i) {
        i->second = -(i->second);
    }

    return temp;

}

double Poly::operator()(double value) const {
    double result = 0;
    for (auto i = entries.begin(); i != entries.end(); ++i) {
        result = result + (i->second * pow(value, i->first));
    }

    return result;
}

Poly operator+(const Poly& p1, const Poly& p2) {
    Poly result(p1);

    for (auto i = p2.entries.begin(); i != p2.entries.end(); ++i) {
        if (result[i->first]) {
            result[i->first] += i->second;
        }
        else {
            result[i->first] = i->second;
        }
    }

    return result;
}

Poly operator-(const Poly& p1, const Poly& p2) {
    Poly result(p1);

    for (auto i = p2.entries.begin(); i != p2.entries.end(); ++i) {
        if (result[i->first]) {
            result[i->first] -= i->second;
        }
        else {
            result[i->first] = -(i->second);
        }
    }

    return result;    
}

Poly operator*(const Poly& p1, const Poly& p2) {
    Poly result;

    for (auto i = p1.entries.begin(); i != p1.entries.end(); ++i) {
        for (auto j = p2.entries.begin(); j != p2.entries.end(); j++) {
            result[i->first + j->first] += i->second * j->second;
        }
    }

    return result;
}