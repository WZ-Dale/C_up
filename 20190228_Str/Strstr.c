#include <stdio.h>
#include <assert.h>
#include <stdint.h>

const char* Strstr(const char* str1, const char* str2){
  assert(str1 != NULL); 
  assert(str2 != NULL);
  if(*str1 == '\0' || *str2 == '\0'){
    return NULL;
  }
  const char* str1_p1 = str1;
  while(*str1_p1 != '\0'){
    const char* str2_p = str2; 
    const char* str1_p2 = str1_p1;
    while(*str2_p != '\0' && *str1_p2 != '\0' 
        && *str1_p2 == *str2_p){
      ++str2_p;
      ++str1_p2;
    }
    if(*str2_p == '\0'){        //找到子字符串,返回str1_p1指向位置
      return str1_p1;
    }
    else{
      ++str1_p1;
    }
  }
  return NULL;
}

int main(){
  char str1[] = "abcdefgh";
  char str2[] = "def";
  const char* p = Strstr(str1, str2);
  printf("%p\n", str1);
  printf("%p\n", p);
  return 0;
}
