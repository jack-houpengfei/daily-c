#include <iostream>
#include "myArray.h"
#include "Person.h"

using namespace std;

void printArr(MyArray<int>& arr){
    for(int i = 0; i < arr.getArrSize(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printPersonArr(MyArray<Person>& arr){
    for(int i = 0; i < arr.getArrSize(); i++){
        cout << "姓名:" << arr[i].m_Name << " 年龄:" << arr[i].m_Age << endl;
    }
}


void test01(){
    MyArray<int> arr1(10);

    MyArray<int> arr3(100);
    arr3 = arr1;//拷贝赋值

    for(int i = 0; i < 10; i++){
        arr1.push_Back(i);
    }
    cout << "arr1打印输出为:" << endl;
    printArr(arr1);

    cout << "arr1的大小为:";
    cout << arr1.getArrSize() << endl;
    cout << "arr1的容量为:";
    cout << arr1.getArrCapacity() << endl;

    MyArray<int> arr2(arr1);//拷贝构造
    cout << "arr2打印输出为:" << endl;
    printArr(arr2);

    arr2.pop_Back();
    cout << "尾删后:" << endl;
    cout << "arr2打印输出为:" << endl;
    printArr(arr2);
    cout << "arr2的大小为:";
    cout << arr2.getArrSize() << endl;
    cout << "arr2的容量为:";
    cout << arr2.getArrCapacity() << endl;
}

void test02(){
    MyArray<Person> arr(10);
    Person p1("张三", 18);
    Person p2("李四", 20);
    Person p3("王五", 22);

    //尾插
    arr.push_Back(p1);
    arr.push_Back(p2);
    arr.push_Back(p3);

    //打印数组
    printPersonArr(arr);
    //打印容量和大小
    cout << "arr的大小为:";
    cout << arr.getArrSize() << endl;
    cout << "arr的容量为:";
    cout << arr.getArrCapacity() << endl;

}

int main() {
    test01();
    test02();
    return 0;
}
