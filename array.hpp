
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <class T>
class array {
private:
    T *a;
public:
    array(int);
    T & operator[](int);
    ~array();
};

template <class T>
array<T>::array(int n) {
    a = new T[n];
}

template <class T>
T & array<T>::operator[](int index) {
    return a[index];
}

template <class T>
array<T>::~array() {
    delete [] a;
}

#endif