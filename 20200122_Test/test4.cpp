#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char ch = 'a';
    char ch1[] = "a";
    char ch2[] = {'a'};
    char ch3[] = {"a"};
    char str1[] = "abc";

    cout << sizeof(ch) << endl;
    cout << sizeof(ch1) << endl;
    cout << strlen(ch1) <<endl;
    cout << sizeof(ch2) << endl;
    cout << strlen(ch2) <<endl;
    cout << sizeof(ch3) << endl;
    cout << strlen(ch3) <<endl;
    cout << sizeof(str1) << endl;
    cout << strlen(str1) << endl; 

    return 0;
}