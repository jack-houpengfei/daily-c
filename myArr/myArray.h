#pragma once
#include <iostream>
using namespace std;


template <typename T>
class MyArray{

    public:
        //有参构造函数
        MyArray(int capacity){
            cout << "有参构造调用" << endl;
            this->m_capacity = capacity;
            this->m_size = 0;
            this->pAddress = new T[this->m_capacity];//在堆区开辟真实数组
        }

        //拷贝构造，防止浅拷贝
        MyArray(const MyArray& arr){
            cout << "拷贝构造调用" << endl;
            this->m_capacity = arr.m_capacity;
            this->m_size = arr.m_size;
            // this->pAddress = arr.pAddress;
            this->pAddress = new T[arr.m_capacity];//在堆区开辟真实数组
            //深拷贝,将arr中的数据都拷贝过来
            for(int i = 0; i < this->m_size; i++){
                this->pAddress[i] = arr.pAddress[i];
            }
        }

        //拷贝赋值,防止浅拷贝
        MyArray& operator=(const MyArray& arr){
            cout << "拷贝赋值调用" << endl;
            //先判断原来堆区是否有数据，如果有先释放
            if(this->pAddress != nullptr){
                delete[] this->pAddress;
                this->pAddress = nullptr;
                this->m_capacity = 0;
                this->m_size = 0;
            }
            //深拷贝
            this->m_capacity = arr.m_capacity;
            this->m_size = arr.m_size;
            this->pAddress = new T[arr.m_capacity];//在堆区开辟真实数组
            for(int i = 0; i < this->m_size; i++){
                this->pAddress[i] = arr.pAddress[i];
            }
            return *this;//返回本对象本身
        }
        
        //析构函数
        ~MyArray(){
            cout << "析构函数调用" << endl;
            if(this->pAddress!= nullptr){
                delete[] this->pAddress;
                this->pAddress = nullptr;
            }
        }

    private:
        T* pAddress;//指针指向堆区开辟的真实数组
        int m_size;//数组元素个数
        int m_capacity;//数组容量

};