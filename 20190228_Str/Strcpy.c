#include <stdio.h>
#include <assert.h>
#include <stdint.h>

char* Strcpy(char* destination, const char* source){
  assert(destination != NULL);
  assert(source != NULL);
  int64_t i = 0;
  for( ; source[i] != '\0'; ++i){
    destination[i] = source[i];
  }
  destination[i] = '\0';
  return destination;
}

int main(){
  char str[1024] = "abcd";
  char str1[] = "efgh";
  printf("%s\n",Strcpy(str,str1));
  return 0;
}
