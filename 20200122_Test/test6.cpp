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
    return 0;
}