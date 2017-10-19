
#ifndef __ALGORITHMS_HPP__
#define __ALGORITHMS_HPP__

//Initialization
template <typename T> void swap (T &, T &);
template <typename T> T max (T, T);
template <typename T> T min (T, T);

//Realization
template <typename T> void swap (T &a, T &b) {
    T t;
    t = a;
    a = b;
    b = t;
}

template <typename T> T max (T a, T b) {
    return (a > b ? a : b);
}

template <typename T> T min (T a, T b) {
    return (a < b ? a : b);
}

#endif