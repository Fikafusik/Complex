
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

class matrix {
public:
    double **mtrx;
    int rows;
    int cols;
    void alloc_space();
    void dealloc_space();
public:
    matrix();
    matrix(int, int);
    matrix(const matrix&);

    ~matrix();

    matrix & operator=(const matrix &);

    matrix & operator*=(double);
    matrix & operator/=(double);

    matrix & operator+=(const matrix &);
    matrix & operator-=(const matrix &);
    matrix & operator*=(const matrix &);

    matrix transponse();
    // TODO:
    double tr();
    double det();
};


matrix operator*(const matrix &, double);
matrix operator*(double, const matrix &);
matrix operator/(const matrix &, double);

matrix operator+(const matrix &, const matrix &);
matrix operator-(const matrix &, const matrix &);
matrix operator*(const matrix &, const matrix &);

bool operator==(const matrix &, const matrix &);
bool operator!=(const matrix &, const matrix &);

#endif