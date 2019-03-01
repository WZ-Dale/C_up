#include <stdio.h>
#include <string.h>
#include <assert.h>

void rotate(char* ch, int a){
  assert(ch != NULL);
  char ch1[10] = {0};
  int i = 0;
  for( ; ch[a + i] != '\0'; ++i){
    ch1[i] = ch[a + i];
  }
  strncat(ch1, ch, a);
  puts(ch1); 
}

int main(){
  char ch[10] = {0};
  int a = 0;
  printf("请输入字符串: ");
  gets(ch);
  printf("左旋几个字符: ");
  scanf("%d", &a);
  rotate(ch, a);
  return 0;
}
