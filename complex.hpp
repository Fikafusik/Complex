
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

    // TODO: implementation (need sqrt(a))
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

#endif