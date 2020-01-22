#include <iostream>
#include <stdio.h>

using namespace std;

void fun(int (*arr)[5]){
    arr[1][3] = 1;
}

int main(){
    int arr[3][5] = {0};
    cout << arr[1][3] << endl;
    fun(arr);
    cout << fun <<endl;
    printf("%p\n",fun);
    printf("%p\n",&fun);
    fun(arr);
    (*fun)(arr);
    cout << arr[1][3] << endl;
    return 0;
}
