#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(n) {
    if (_size > 0)
        _data = new T[_size](); // default-initialized elements
}

template <typename T>
Array<T>::Array(Array const &other) : _data(0), _size(0) {
    *this = other;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
    if (this != &other)
    {
        T *newData = 0;
        if (other._size > 0)
        {
            newData = new T[other._size];
            for (unsigned int i = 0; i < other._size; ++i)
                newData[i] = other._data[i];
        }
        delete[] _data;
        _data = newData;
        _size = other._size;
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Array index out of range");
    return _data[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Array index out of range");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif
