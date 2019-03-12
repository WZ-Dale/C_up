#include <stdio.h>
#include <string.h>

//封装函数Split,使得strtok方便使用
//返回值是切分出来的token个数
int Split(char* input, const char* split_char, char* output[]){
  int output_index = 0;
  char* p = strtok(input, split_char);
  while(p != NULL){
    output[output_index] = p;       //指针传递
    ++output_index;
    p = strtok(NULL, split_char);
  }
  return output_index;
}

int main(){
  char str[] = "ls -l /";
  char* output[10] = {0};           //定义了一个指针数组
  int n = Split(str, " ", output);
  for(int i = 0; i < n; ++i){
    printf("%s\n", output[i]);
  }
  return 0;
}
