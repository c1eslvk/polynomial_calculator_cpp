#include <iostream>
#include <map>
using namespace std;

class Poly {
    private:
        map<int, double> entries;

    public:
        Poly();
        Poly(double value);
        Poly(const Poly& other);
        ~Poly();
        double& operator[](int power);
        double operator()(double value) const;
        friend ostream& operator<<(ostream& os, const Poly& p);
        friend Poly operator+(const Poly& p1, const Poly& p2);
        friend Poly operator-(const Poly& p1, const Poly& p2);
        friend Poly operator*(const Poly& p1, const Poly& p2);
        Poly operator-() const;

};