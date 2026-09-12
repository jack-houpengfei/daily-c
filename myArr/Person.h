#pragma once
#include <iostream>
#include <string.h>


class Person{

    public:
        Person(){

        }

    Person(std::string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    
    std::string m_Name;
    int m_Age;
};