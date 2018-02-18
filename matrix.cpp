
#include "matrix.hpp"

void matrix::alloc_space() {
    mtrx = new double*[rows];
    for (int i = 0; i < rows; ++i) 
        mtrx[i] = new double[cols];
    return;
}

void matrix::dealloc_space() {
    for (int i = 0; i < rows; ++i)
        delete[] mtrx[i];
    delete[] mtrx;
}

matrix::matrix() : rows(1), cols(1) {
    alloc_space();
    mtrx[0][0] = 0.0;
} 

matrix::matrix(int rows, int columns) : rows(rows), cols(columns) {
    alloc_space();
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] = 0.0;
}

matrix::matrix(const matrix &m) : rows(m.rows), cols(m.cols) {
    alloc_space();
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] = m.mtrx[i][j];
}

matrix::~matrix() {
    dealloc_space();
}

matrix & matrix::operator=(const matrix &m) {
    if (this == &m)
        return *this;
    if (rows != m.rows || cols != m.cols) {
        dealloc_space();
        rows = m.rows;
        cols = m.cols;
        alloc_space();
    }
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] = m.mtrx[i][j];
    return *this;
}

matrix & matrix::operator*=(double rv) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] *= rv;
    return *this;
}

matrix & matrix::operator/=(double rv) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] /= rv;
    return *this;
}

matrix & matrix::operator+=(const matrix &rm) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] += rm.mtrx[i][j];
    return *this;
}

matrix & matrix::operator-=(const matrix &rm) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] -= rm.mtrx[i][j];
    return *this;
}

matrix & matrix::operator*=(const matrix &rm) {
    matrix m = matrix(rows, rm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            for (int k = 0; k < cols; ++k)
                m.mtrx[i][j] += mtrx[i][k] * rm.mtrx[k][j];
    return (*this = m);
}

matrix matrix::transponse() {
    matrix m = matrix(cols, rows);
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            m.mtrx[j][i] = mtrx[i][j];
    return m;
}

double matrix::tr() {
    if (rows != cols)
        return 42.0;
    double trace = 0.0;
    for (int i = 0; i < rows; ++i)
        trace += mtrx[i][i];
    return trace;
}

matrix operator*(const matrix &lm, double rv) {
    matrix m = matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] * rv;
    return m;    
}

matrix operator*(double lv, const matrix &rm) {
    matrix m = matrix(rm.rows, rm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lv * rm.mtrx[i][j];
    return m;
}

matrix operator/(const matrix &lm, double rv) {
    matrix m = matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] / rv;
    return m;    
}

matrix operator+(const matrix &lm, const matrix &rm) {
    matrix m = matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] + rm.mtrx[i][j];
    return m;
}

matrix operator-(const matrix &lm, const matrix &rm) {
    matrix m = matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] - rm.mtrx[i][j];
    return m;
}

matrix operator*(const matrix &lm, const matrix &rm) {
    matrix m = matrix(lm.rows, rm.cols);
    for (int i = 0; i < m.rows; ++i) 
        for (int j = 0; i < m.cols; ++j)
            for (int k = 0; k < m.cols; ++k)
                m.mtrx[i][j] += lm.mtrx[i][k] * rm.mtrx[k][j];
    return m;
}

bool operator==(const matrix &lm, const matrix &rm) {
    if (&lm == &rm)
        return true;
    if (lm.rows != rm.rows || lm.cols != rm.cols)
        return false;
    for (int i = 0; i < lm.rows; ++i)
        for (int j = 0; j < lm.cols; ++j)
            if (lm.mtrx[i][j] != rm.mtrx[i][j])
                return false;
    return true;
}

bool operator!=(const matrix &lm, const matrix &rm) {
    if (&lm == &rm)
        return false;
    if (lm.rows != rm.rows || lm.cols != rm.cols)
        return true;
    for (int i = 0; i < lm.rows; ++i)
        for (int j = 0; j < lm.cols; ++j)
            if (lm.mtrx[i][j] != rm.mtrx[i][j])
                return true;
    return false;
}
