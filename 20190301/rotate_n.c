#include <stdio.h>
#include <string.h>
#include <assert.h>

void rotate(const char* ch, char* ch2, int a){
  assert(ch != NULL);
  assert(ch2 != NULL);
  int i = 0;
  for (; ch[a + i] != '\0'; ++i){
    ch2[i] = ch[a + i];
  }
  strncat(ch2, ch, a);
}

int main(){
  char ch[10] = {0};
  char ch1[10] = {0};
  printf("输入第一个字符串:");
  gets(ch);
  printf("输入第二个字符串:");
  gets(ch1);
  int a = 0;
  int b = strlen(ch);
  for (; a < b; ++a){
    char ch2[10] = { 0  };       //中间存储变化
    rotate(ch, ch2, a);
    if (strcmp(ch1, ch2) == 0){
      printf("1\n");
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
