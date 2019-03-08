#include <stdio.h>
#include <assert.h>
#include <stdint.h>

int Strcmp(const char* str1, const char* str2){
  assert(str1 != NULL); 
  assert(str2 != NULL);
  while(*str1 != '\0' && *str2 != '\0'){
    if(*str1 < *str2){
      return -1;
    }
    else if(*str1 > *str2){
      return 1;
    }else{              //对应字符相等,继续比较下一字符
      ++str1;
      ++str2;
    }
  }
  if(*str1 < *str2){    //str1遇到\0,str2没遇到
    return -1;
  }
  else if(*str1 > *str2){ //str1没遇到,str2遇到\0
    return 1;
  }
  else{                   //str1和石头人2同时遇到\0
    return 0;
  }
}

int main(){
  char str1[] = "abcd";
  char str2[] = "abcd";
  int ret = Strcmp(str1, str2);
  if(ret == 0){
    printf("相等\n");
  }
  else if(ret < 0){
    printf("小于\n");
  }
  else if(ret > 0){
    printf("大于\n");
  }
  return 0;
}
