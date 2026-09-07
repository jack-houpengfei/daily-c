#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>

class string
{
public:
    static const size_t min_capacity;  // Minimum capacity for the string


private:
    char* data_;  // Pointer to the character array
    size_t size_;  // Current size of the string
    size_t capacity_;  // Current capacity of the string

private:
    void realloccate(size_t new_capacity);  // Function to reallocate memory for the string





public:
    string();//默认构造函数
    ~string();

    string(const char* str);  // 从c风格字符串构造
    string(const void* data, size_t len);  // 从二进制数据构造
    string(const string& other);  // Copy constructor
    //noexcept表示这个函数不会抛出异常，移动构造函数通常不会抛出异常，因为它只是转移资源的所有权，而不是分配新的资源。这样可以提高性能，尤其是在容器中使用时。
    string(string&& other) noexcept;  // Move constructor,移动构造
    string& operator=(const string& other);  // Copy assignment operator

    //预分配内存
    void reserve(size_t new_capacity);  // Reserve memory for the string
    //释放多余内存
    void shrink_to_fit();  // Shrink the capacity to fit the size

    //append函数
    string& append(const char* str, size_t len);  // 二进制安全 string
    string& append(const char* str);  // c风格 string
    



};

const size_t string::min_capacity = 15;  // Initialize the minimum capacity
