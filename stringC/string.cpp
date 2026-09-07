#include "string.h"

void string::realloccate(size_t new_capacity)
{
    // Allocate new memory for the string with the specified new capacity
    // 最少分配min_capacity个字节的内存，保证字符串的最小容量
    new_capacity = (new_capacity < min_capacity) ? min_capacity : new_capacity;
    char* new_data = new char[new_capacity];

    if(size_ > 0) {
        // Copy the existing data to the new memory
        std::memcpy(new_data, data_, size_);//同时支持c字符串和二进制安全字符串，赋值时把字符串中包含的/0也复制过去
    }

    //capacity和size都不包含\0，size是实际字符串的长度，capacity是实际分配的内存大小
    //实际分配的大小是new_capacity+1，用于存储字符串结束符\0
    new_data[size_] = '\0';  // 结尾添加/0，保证字符串的正确性

    // Deallocate the old memory
    delete[] data_;

    // Update the data pointer and capacity
    data_ = new_data;
    capacity_ = new_capacity;

}

string::string(): size_(0), capacity_(min_capacity)
{
    data_ = new char[capacity_+1];  // Allocate memory for the string, including space for the null terminator
    data_[0] = '\0';  // Initialize the string as an empty string
}

string::~string()
{
    delete [] data_;  // Deallocate the memory used for the string
}

string::string(const char *str)
{
    if(nullptr == str) {
        throw std::invalid_argument("Null pointer");
    } else {
        size_ = std::strlen(str);
        capacity_ = (size_ < min_capacity) ? min_capacity : size_;//最小取15，保证字符串的最小容量
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, str, size_ + 1);  // Copy the null terminator as well
    }
}

string::string(const void *data, size_t len)
{
    if(nullptr == data) {
        throw std::invalid_argument("Null pointer");
    } else {
        size_ = len;
        capacity_ = (size_ < min_capacity) ? min_capacity : size_;//最小取15，保证字符串的最小容量
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, data, len);
        data_[size_] = '\0';//不管是c字符串还是二进制数据，结尾都加上/0，保证字符串的正确性
    }
}

string::string(const string &other):size_(other.size_), capacity_(other.capacity_)
{
    data_ = new char[capacity_ + 1];
    std::memcpy(data_, other.data_, size_ + 1);  // Copy the null terminator as well
}

//移动赋值运算符
string::string(string&& other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
{
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

//拷贝赋值运算符
string &string::operator=(const string &other)
{
    if(this != &other) {
        char* new_data = new char[other.capacity_ + 1];
        std::memcpy(new_data, other.data_, other.size_ + 1);
        delete[] data_;
        data_ = new_data;
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
    return *this;
}

void string::reserve(size_t new_capacity)
{
    if(new_capacity > capacity_) {
        realloccate(new_capacity);
    }
}

//释放多余内存
void string::shrink_to_fit()
{
    if(size_ < capacity_) {
        realloccate(size_);
    }
}

string &string::append(const char *str, size_t len)
{
    if(nullptr == str) {
        throw std::invalid_argument("Null pointer");
    }
    if(size_ + len > capacity_) {
        reserve((size_ + len)*2);  // Double the capacity to reduce the number of reallocations
    }
    std::memcpy(data_ + size_, str, len);
    size_ += len;
    data_[size_] = '\0';  // Ensure null termination
    return *this;
}

string &string::append(const char *str)
{
    if(nullptr == str) {
        throw std::invalid_argument("Null pointer");
    }
    size_t len = std::strlen(str);
    return append(str, len);
}
