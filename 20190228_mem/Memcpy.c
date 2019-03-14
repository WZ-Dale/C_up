#include <stdio.h>
#include <assert.h>

void* Memcpy(void* dest, const void* src, size_t num){
  assert(dest != NULL);
  assert(src != NULL);
  char* pdest = (char*)dest;
  char* psrc = (char*)src;
  for(size_t i = 0; i < num; ++i){
    pdest[i] = psrc[i];
  }
  return dest;
}

int main(){
  char arr1[4] = {1, 2, 3, 4};
  char arr2[4] = {0};
  Memcpy(arr2, arr1, 16);
  for(int i = 0; i < 4; ++i){
    printf("%d\n", arr2[i]);
  }
  return 0;
}
