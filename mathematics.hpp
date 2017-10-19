
#ifndef __MATHEMATICS_HPP__
#define __MATHEMATICS_HPP__

extern const double pi;

double sqr(double);

double native_power_resursion(double, int);
double native_power_iterative(double, int);
double binary_power_recursion(double, int);
double binary_power_iterative(double, int);

double root(double, int);
double sqrt(double);
double cbrt(double);

    double log(double, double);
    
    double lg(double);
    double ln(double);
    double lb(double);

// BIG TODO BLOCK. Tolyan)0)):
double sin(double);
double cos(double);
double tan(double);
double cot(double);
double sec(double);
double csc(double);
//All is based on sin();

    double sinh(double);
    double cosh(double);
    double tanh(double);
    double coth(double);
    double sech(double);
    double csch(double);

    double arcsin(double);
    double arccos(double);
    double arctan(double);
    double arccot(double);
    double arcsec(double);
    double arccsc(double);

    double versin(double);
    double vercos(double);

    double haversin(double);
    double havercos(double);

    double coversin(double);
    double covercos(double);

    double hacoversin(double);
    double hacovercos(double);

    double exsec(double);
    double excsc(double);

#endif