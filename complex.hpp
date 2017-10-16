
#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

class complex {
public:
    double re;
    double im;

    complex();
    complex(double, double);
    complex(const complex &);
    
    complex conjugate();

    double modulus();

    const complex & operator =(const complex &);
    const complex & operator+=(const complex &);
    const complex & operator-=(const complex &);
    const complex & operator*=(const complex &);
    const complex & operator/=(const complex &);
 
};

complex operator+(const complex &);
complex operator-(const complex &);

complex operator+(const complex &, const complex &);
complex operator-(const complex &, const complex &);
complex operator*(const complex &, const complex &);
complex operator/(const complex &, const complex &);

bool operator==(const complex &, const complex &);
bool operator!=(const complex &, const complex &);

complex arcsin(const complex &);
complex arccos(const complex &);
complex arctan(const complex &);
complex arccot(const complex &);
complex arcsec(const complex &);
complex arccsc(const complex &);

#endif