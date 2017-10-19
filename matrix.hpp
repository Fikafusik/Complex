
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

class matrix {
private:
    int** m;
public:
    matrix();
    matrix(int, int);
    
    matrix & operator*=(const matrix &rm);
};

#endif