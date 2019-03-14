#include <stdio.h>

int main(){
  int arr[] = { 1, 2, 3, 4, 5, 6, 6, 4, 3, 2 };
  int size = sizeof(arr)/sizeof(arr[0]);        //sizeof()计算的是字节数,不是元素个数
  int count = 0;
  int i = 0, j = 0;
  for(i = 0; i < size; ++i){
    for(j = 0; j < size; ++j){
      if(arr[i] == arr[j]){
        ++count;
      }
      if(count == 2){
        break;
      }
    }
    if(count == 1){
      printf("%d\n",arr[i]);
    }
    count = 0;
  }
  return 0;
}
