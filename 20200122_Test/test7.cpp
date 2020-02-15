#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void Test1(){
    cout << "无符号：" << endl;
    cout << 0 << " ~ " << UINT8_MAX << endl;
    cout << 0 << " ~ " << UINT16_MAX << endl;
    cout << 0 << " ~ " << UINT32_MAX << endl;
    cout << 0 << " ~ " << UINT_MAX << endl << endl;

    cout << "有符号：" << endl;
    cout << INT8_MIN << " ~ " << INT8_MAX << endl;
    cout << INT16_MIN << " ~ " << INT16_MAX << endl;
    cout << INT32_MIN << " ~ " << INT32_MAX << endl;
    cout << INT_MIN << " ~ " << INT_MAX << endl;
}
void Test2(){
    int* p = (int*)malloc(INT_MAX*40);
    //*p = 20;
    cout << p << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    free(p);
}

int main(){
    //Test1();
    Test2();
    return 0;
}
