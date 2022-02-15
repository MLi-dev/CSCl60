//
// Created by Matthew Li on 2/12/22.
//
#ifndef NDIMENSION_NDIMENSION_H
#define NDIMENSION_NDIMENSION_H
#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

template<class T>
class NDimension {
private:
    int size_;
    T *arr;
public:
    NDimension();
    //pre: 0<s<10
    NDimension(int s);
    NDimension(int s, T p[]);
    int getSize() const;
    T getValByInd(int i);
    T& operator[](int index) const;
    //Needs an overloaded operator for the '[]'.
    void operator=(const NDimension<T>& t1);
    void operator+=(const NDimension<T>& t1);

};
template<class T>
NDimension<T>::NDimension() {
    size_ = 0;
    arr = nullptr;
}

template<class T>
NDimension<T>::NDimension(int s) {
    size_ = s;
    arr = new T[size_];
}

template<class T>
NDimension<T>::NDimension(int s, T p[]) {
    size_ = s;
    arr = new T[size_];
    for(int i = 0; i<s; i++) {
        arr[i] = p[i];
    }
}

template<class T>
int NDimension<T>::getSize() const{
    return size_;
}

template<class T>
T NDimension<T>::getValByInd(int i) {
    return arr[i];
}

template <class T>
T& NDimension<T>::operator[](int index) const{
  if(index>=size_) {
      cout<<"Illegal index!"<<endl;
      exit(0);
  }
  return arr[index];
}

template <class T>
void NDimension<T>::operator=(const NDimension<T>& b) {
    if(this == &b) {
        return;
    }
    delete [] arr;
    size_ = b.getSize();
    arr = new T[size_];
    for(std::size_t i = 0; i<size_; i++) {
        arr[i] = b.arr[i];
    }
}
template<class T>
void NDimension<T>::operator+=(const NDimension<T>& t1) {
    if(size_ < t1.getSize()) {
        T* temp = new T[t1.getSize()];
        for(int i = 0; i<t1.getSize(); i++) {
            temp[i] = t1.arr[i];
        }
        for(int i = 0; i<size_; i++) {
            temp[i] = arr[i] + temp[i];
        }
        delete[] arr;
        size_ = t1.getSize();
        arr = temp;
    } else {
        for(int i = 0; i<t1.getSize(); i++) {
            arr[i] = arr[i] + t1.arr[i];
        }
    }
}
template<class T>
NDimension<T> operator+(const NDimension<T>& t1, const NDimension<T>& t2) {
    NDimension<T> c;
    c+=t1;
    c+=t2;
    return c;
}
template<class T>
//Will work with strings and any numeric type. Needed to implement a '[]' operator.
bool operator==(const NDimension<T>& t1, const NDimension<T>& t2) {
    if(t1.getSize() != t2.getSize()) {
        return false;
    } else {
        bool match = true;
        int i = 0;
        while(i<t1.getSize() && match == true) {
            if(t1[i] != t2[i]) {
                match = false;
            }
            i++;
        }
        return match;
    }
}
NDimension<int> operator-(const NDimension<string>& t1, NDimension<string>& t2) {
    int* temp = new int[t1.getSize()];
    for(int i = 0; i<t1.getSize(); i++) {
        temp[i] = t1[i][0] - t2[i][0];
    }
    NDimension<int> stringdiff(t1.getSize(), temp);
    return stringdiff;
}

NDimension<int> operator-(const NDimension<int>& t1, NDimension<int>& t2) {
        int* temp = new int[t1.getSize()];
        for(int i = 0; i<t1.getSize(); i++) {
                temp[i] = t1[i]-t2[i];
        }
    NDimension<int> stringdiff(t1.getSize(), temp);
    return stringdiff;
}

template <class T>
double dist(const NDimension<T>& t1, const NDimension<T>& t2) {
    double sum = 0;
    if(t1.getSize()!=t2.getSize()) {
        return -1;
    }
    if(typeid(t1[0]) == typeid(string)) {
        NDimension<int> diffs = t1-t2;
        for(int i = 0; i<diffs.getSize(); i++) {
            sum += diffs[i];
        }
    } else {
        for(int i = 0; i<t1.getSize(); i++) {
            int intDiff = t1[i]-t2[i];
            intDiff = pow(intDiff, 2);
            sum+=intDiff;
        }
    }
    sum = sqrt(sum);
    return sum;
}


#endif //NDIMENSION_NDIMENSION_H
