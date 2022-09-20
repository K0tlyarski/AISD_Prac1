//
//  main.cpp
//  dz
//
//  Написать класс контейнер, в котором будет два поля: строка и вещественное число; поддерживаемые функции: сеттыеры геттеры, конструктры, оператор присваивания, оператор [ ] где в качестве индекса строка, оператор сложения
//

#include <iostream>
#include <string>
const int lengthOfName = 8;

struct couple
{
    double key;
    char name[lengthOfName];
};

class List
{
private:
    couple* array;
    int size;
    int capacity;

    void updateCapacity()
    {
        capacity += 10;
        couple* tmp = new couple[capacity];
        for (int i = 0; i < size; i++)
        {
            strncpy(tmp[i].name, array[i].name, lengthOfName);
            tmp[i].key = array[i].key;
        }
        delete[]array;
        array = tmp;
    }

public:
    List() : array(NULL), size(0), capacity(0) {} ;
    List(List& a)
    {
        size = a.size;
        capacity = a.capacity;
        array = new couple[capacity];
        for (int i = 0; i < size; i++)
        {
            strncpy(array[i].name, a.array[i].name, lengthOfName);
            array[i].key = a.array[i].key;
        }
    }
    ~List() { delete[]array; };

    void setName(int index, char* data)
    {
        if (index >= size) { throw("invalid Index"); }
        strncpy(array[index].name, data, lengthOfName);
    }
    void setKey(int index, int data)
    {
        if (index >= size) { throw("invalid Index"); }
        array[index].key = data;
    }
    char* getName(int index) const
    {
        if (index >= size) { throw("invalid Index"); }
        return array[index].name;
    }
    double getKey(int index) const
    {
        if (index >= size) { throw("invalid Index"); }
        return array[index].key;
    }

    void add(couple a)
    {

    }

    List& operator=(const List& src)
    {
        if (this == &src) return *this;
        if (capacity < src.size)
        {
            delete[]array;
            capacity = src.capacity;
            array = new couple[capacity];
        }
        size = src.size;
        for (int i = 0; i < size; i++)
        {
            strncpy(array[i].name, src.array[i].name, lengthOfName);
            array[i].key = src.array[i].key;
        }
        return *this;
    }
    double operator[](const char* name)
    {
        for (int i = 0; i < size; i++)
        {
            if (0 == strcmp(array[i].name, name)) return array[i].key;
        }
        throw("doesn't exist element with this name");
    }
    List& operator+(const List& a)
    {
        List result;
        result.size = size + a.size;
        result.capacity = capacity + a.capacity;

        result.array = new couple[result.capacity];
        for (int i = 0; i < size; i++)
        {
            strncpy(result.array[i].name, array[i].name, lengthOfName);
            result.array[i].key = array[i].key;
        }

        for (int i = size; i < a.size; i++)
        {
            strncpy(result.array[i].name, a.array[i].name, lengthOfName);
            result.array[i].key = a.array[i].key;
        }
        return result;
    }
};
