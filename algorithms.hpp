
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
void sort_insertion(T a[], int l, int r);

template <class T>
void sort_bubble(T a[], int l, int r);

template <class T> 
void swap(T &a, T &b) {
    T t;
    t = a;
    a = b;
    b = t;
    return;
}

template <class T> 
T max(T a, T b) {
    return (a > b ? a : b);
}

template <class T> 
T min(T a, T b) {
    return (a < b ? a : b);
}

template <class T>
// [l; r], [l; r), (l; r], (l; r)?
// is it working?
void sort_stupid(T a[], int l, int r) {
    for (int i = l + 1; i <= r; i++)
        for (int j = i; j > l; j--)
            // If T is uncomparable type?
            if (a[j - 1] > a[j]) 
                swap(a[j - 1], a[j]);
    // I don't understand, what you mean.
    /*
    [l; r)
    for (int i = l; i < r; ++i)
        for (int j = i + 1; j < r; ++j)
            if compare(a[i], a[j]) < 0 
                swap(a[i], a[j]);
    */
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

//Not working, debug later
template <class T>
void sort_insertion(T a[], int l, int r) {
    for (int i = r; i > l; i--)
        if (a[i - 1] < a[i]) 
            swap(a[i - 1], a[i]);
    for (int i = l + 2; i <= r; i++) {
        int j = i;
        T v = a[i];
        while (v < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}

#endif