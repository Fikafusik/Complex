
#include "complex.hpp"

complex::complex() {
    this->re = 0;
    this->im = 0;
}

complex::complex(double real, double imaginary) {
    this->re = real;
    this->im = imaginary;
}

complex::complex(const complex &c) {
    this->re = c.re;
    this->im = c.im;
}

complex complex::conjugate() {
    return complex(this->re, -this->im);
}

const complex & complex::operator =(const complex &rc) {
    this->re = rc.re;
    this->im = rc.im;
    return *this;
}

const complex & complex::operator+=(const complex &rc) {
    this->re += rc.re;
    this->im += rc.im;
    return *this;
}

const complex & complex::operator-=(const complex &rc) {
    this->re -= rc.re;
    this->im -= rc.im;
    return *this;
}

const complex & complex::operator*=(const complex &rc) {
    this->re = this->re * rc.re - this->im * rc.im;
    this->im = this->im * rc.re + this->re * rc.im;
    return *this;
}

const complex & complex::operator/=(const complex &rc) {
    // TODO: sqr(a) = a * a; (need new header for math function)
    double m = rc.re * rc.re + rc.im * rc.im;
    // TODO: if (m == 0) return error("Dividing by zero");
    this->re = (this->re * rc.re + this->im * rc.im) / m;
    this->im = (this->im * rc.re - this->re * rc.im) / m;
    return *this;
}

complex operator+(const complex &c) {
    return complex(c.re, c.im);
}

complex operator-(const complex &c) {
    return complex(-c.re, -c.im);
}

complex operator+(const complex &lc, const complex &rc) {
    return complex(lc.re + rc.re, lc.im + rc.im);
}

complex operator-(const complex &lc, const complex &rc) {
    return complex(lc.re - rc.re, lc.im - rc.im);
}

complex operator*(const complex &lc, const complex &rc) {
    return complex(lc.re * rc.re - lc.im * rc.im, lc.im * rc.re + lc.re * rc.im);
}