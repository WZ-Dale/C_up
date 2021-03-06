#include <stdio.h>
#include <assert.h>
#include <stdint.h>

char* Strcat(char* destination, const char* source){
  assert(destination != NULL);
  assert(source != NULL);
  int64_t i = 0;
  for( ; destination[i] != '\0'; ++i );
  int64_t j = 0;
  for( ; source[j] != '\0'; ++j, ++i){
    destination[i] = source[j];
  }
  destination[i] = '\0';
  return destination;
}

int main(){
  char str[1024] = "abcd";
  char str1[] = "efgh";

  printf("%s\n",Strcat(str, str1));
  return 0;
}
