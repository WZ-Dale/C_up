#include <iostream>

using namespace std;

int main(){
    enum Sex{
        MALE,
        FEMALE = -2,
        UNKNOWN,
        WHAT
    };
    cout << MALE << FEMALE << UNKNOWN << WHAT << endl;

    int a = 2, b = 3;
    int arr[] = {1, a, 3};
    cout << arr[1] << endl;
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[2]);
    return 0;
}