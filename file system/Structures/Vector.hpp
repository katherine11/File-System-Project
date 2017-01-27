#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cstdio>
#include <iostream>

const size_t DEFAULT_CAPACITY = 1000;
const size_t RESIZE_UP_VALUE = 2;
const float RESIZE_DOWN_MIN_VALUE = 0.25;
const float RESIZE_DOWN_VALUE = 0.5;

template <typename T>
class Vector {

    T* container;
    size_t size;
    size_t capacity;

    void copy(const Vector &vector);
    void destroy();
    void resize(size_t newCapacity);
public:
    Vector();
    Vector(size_t capacity, size_t size = 0);
    Vector(const Vector& otherVector);
    Vector & operator=(const Vector &vector);
    ~Vector();

    void deleteElement(T element);
    void deleteElement(T* element);
    T getAt(size_t index) const;
    void pushBack(T element);
    bool containsElement(T element);
    void deleteAt(size_t index);

    template<typename E>
    friend bool operator==(const Vector<E> &vector1, const Vector<E> &vector2);
    template<typename E>
    friend bool operator!=(const Vector<E> &vector1, const Vector<E> &vector2);

    template <typename E>
    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);
    bool isEmpty() const;
    void clear();

    size_t getSize() const;
};

template<typename T>
Vector<T>::Vector()
{
    size = 0;
    capacity = DEFAULT_CAPACITY;
    container = new T[capacity];
}


template<typename T>
Vector<T>::Vector(size_t capacity, size_t size)
{
    this->size = size;
    this->capacity = capacity;
    container = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& vector)
{
    copy(vector);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vector) {
    if(this != &vector)
    {
        destroy();
        copy(vector);
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    destroy();
}

template <typename T>
void Vector<T>::resize(size_t newCapacity)
{
    T* newContainer = new T[newCapacity];
    for(int i = 0; i < size; i++) {
        newContainer[i] = container[i];
    }

    delete[] container;
    container = newContainer;
    capacity = newCapacity;
}

template <typename T>
T Vector<T>::getAt(size_t index) const
{
    if(index < 0 || index >= size)
    {
        throw "The index is out of bounds";
    }

    return container[index];
}

template <typename T>
void Vector<T>::pushBack(T element)
{
    if(size >= capacity)
    {
        resize(RESIZE_UP_VALUE * capacity);
    }
    container[size++] = element;
}


template <typename T>
void Vector<T>::deleteAt(size_t index)
{
    if(index < 0 || index >= size)
    {
        throw "The index is out of bounds";
    }

    container[index] = container[size - 1];
    size--;

    if(size < (capacity * RESIZE_DOWN_MIN_VALUE))
    {
        resize(RESIZE_DOWN_VALUE * capacity);
    }
}

template <typename  T>
void Vector<T>::deleteElement(T element) {
    for (int index = 0; index < size; ++index) {
        if(*container[index] == *element)
        {
            container[index] = container[size -1];
            size--;
            break;
        }
    }
}

template <typename T>
void Vector<T>::clear()
{
    for (int index = 0; index < size; ++index) {
        deleteAt(index);
    }
}

template<typename T>
void Vector<T>::deleteElement(T *element) {

    for (int index = 0; index < size; ++index) {
        if(*container[index] == **element)
        {
            container[index] = container[size -1];
            size--;
            break;
        }
    }
}

template <typename T>
bool Vector<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return size;
}

template <typename T>
void Vector<T>::copy(const Vector<T> &vector) {
    size = vector.size;
    capacity = vector.capacity;
    container = new T[capacity];

    for(size_t i = 0; i < size; i++)
    {
        container[i] = vector.container[i];
    }

}

template <typename T>
void Vector<T>::destroy() {

    delete [] container;
}

template<typename T>
bool operator==(const Vector<T> &vector1, const Vector<T> &vector2)  {
    if(vector1.size != vector2.size)
    {
        return false;
    }

    for (int index = 0; index < vector1.size; ++index) {
        if(vector1.getAt(index) != vector2.getAt(index))
        {
            return false;
        }
    }

    return true;
}

template<typename E>
bool operator!=(const Vector<E> &vector1, const Vector<E> &vector2)  {
    return !(vector1 == vector2);
}

template <typename T>
bool Vector<T>::containsElement(T element) {
    for (int index = 0; index < size; ++index) {
        if(*container[index] == *element)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {

    for (int index = 0; index < vector.getSize(); ++index) {
        std::cout << vector.getAt(index) << " ";
    }

    return os;
}

#endif //VECTOR_VECTOR_H

