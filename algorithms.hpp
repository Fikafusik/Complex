
#ifndef __ALGORITHMS_HPP__
#define __ALGORITHMS_HPP__

template <class T> 
void swap(T &, T &);

template <class T> 
T max(T, T);

template <class T> 
T min(T, T);

template <class T> 
void swap(T &a, T &b) {
    T t;
    t = a;
    a = b;
    b = t;
    return;
}

template <class T> 
T max (T a, T b) {
    return (a > b ? a : b);
}

template <class T> 
T min (T a, T b) {
    return (a < b ? a : b);
}

#endif