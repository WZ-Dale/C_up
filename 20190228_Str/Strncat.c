#include <stdio.h>
#include <assert.h>
#include <stdint.h>

char* Strncat(char* destination, const char* source, int64_t num){
  assert(destination != NULL);
  assert(source != NULL);
  int64_t i = 0;
  for( ; destination[i] != '\0'; ++i );
  int64_t j = 0;
  for( ; j < num; ++j, ++i){
    destination[i] = source[j];
  }
  destination[i] = '\0';
  return destination;
}

int main(){
  char str[1024] = "abcd";
  char str1[] = "efgh";
  int64_t num = 3;
  printf("%s\n",Strncat(str, str1, num));
  return 0;
}
