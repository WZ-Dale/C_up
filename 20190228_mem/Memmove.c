#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

void* Memmove(void* dest, const void* src, size_t num){
  assert(dest != NULL);
  assert(src != NULL);
  char* pdest = (char*)dest;
  char* psrc = (char*)src;
  if(psrc <= pdest && pdest < psrc + num){
  //缓冲区重叠,需特殊处理,从后往前拷贝
  //size_t i = num -1;      //size_t本来就大于0,存在问题 
  //long i = num -1;        //long在不同的系统下字节数不同 
  int64_t i = num -1; 
  for( ; i >=0; --i ){
    pdest[i] = psrc[i];
    } 
  }
  else{
    memcpy(dest, src, num);
  }
  size_t i = 0;
  for(; i < num; ++i){
    pdest[i] = psrc[i];
  }
  return dest;
}

int main(){
  char arr1[4] = {1, 2, 3, 4};
  char arr2[4] = {0};
  Memmove(arr2, arr1, 16);
  int i = 0;
  for(; i < 4; ++i){
    printf("%d\n", arr2[i]);
  }
  return 0;
}
