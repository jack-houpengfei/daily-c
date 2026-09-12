#include <iostream>
#include "myArray.h"

using namespace std;

void test01(){
    MyArray<int> arr1(10);
    MyArray<int> arr2(arr1);//拷贝构造
}



int main() {
    test01();
    cout << "Hello World!" << endl;
    return 0;
}
