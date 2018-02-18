
#ifndef __ALGORITHMS_HPP__
#define __ALGORITHMS_HPP__

template <class T> 
void swap(T &, T &);

template <class T> 
T max(T, T);

template <class T> 
T min(T, T);

template <class T>
void sort_stupid(T a[], int l, int r);

template <class T>
void sort_selection(T a[], int l, int r);


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

template <class T>
void sort_stupid(T a[], int l, int r) {
    for (int i = l + 1; i <= r; i++)
        for (int j = i; j > l; j--)
            if (a[j-1] > a[j]) swap(a[j-1], a[j]);
}

template <class T>
void sort_selection(T a[], int l, int r){
    for (int i = l; i < r; i++) {
        int min = i;
        for (int j = i + 1; j <= r; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }
}

#endif