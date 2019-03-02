#include <stdio.h>
#include <assert.h>

size_t Strlen(const char* str){
  assert(str != NULL);
  size_t count = 0;
  while(str[count] != '\0'){
    ++count;
  }
  return count;
}
int main(){
  char str[] = "abcd";
  printf("%lu\n",Strlen(str));
  return 0;
}
