#include <iostream>

using namespace std;

int Less(int x, int y){
    return x < y ? 1 : 0;
}
int Greater(int x, int y){
    return x > y ? 1 : 0;
}
void Swap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}
typedef int (*T)(int x, int y);
void BubbleSort(int arr[], int size, T cmp){
    for(int bound = 0; bound < size; ++bound){
        for(int cur = size - 1; cur > bound; --cur){
            if(cmp(arr[cur - 1], arr[cur]) == 0){
                Swap(&arr[cur - 1], &arr[cur]);
            }
        }
    }
}
void Print(int arr[], int size){
    for(int i = 0; i < size; ++i){
        cout << arr[i];
    }
    cout << endl;
}
//回调函数
int main(){
    int arr[10] = {4, 6, 2, 7, 9, 3, 8, 1, 0, 5};
    Print(arr, 10);
    //BubbleSort(arr, 10, Less);//升序
    BubbleSort(arr, 10, Greater);//降序
    Print(arr, 10);
    return 0;
}