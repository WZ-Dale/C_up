#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(){
  //fp 就是 文件指针/文件句柄
  FILE* fp = fopen("./test.txt","r+");
  if(fp == NULL){
    //printf("%s\n",strerror(errno));
    perror("fopen");
    return 1;
  }
  printf("%p\n",fp);
  char buffer[1024] = {0};    //先搞一个缓冲区
  size_t n = fread(buffer, 1, 1024, fp);
  //把磁盘上的数据读到内存中
  printf("n = %lu\n",n);
  printf("buffer = %s\n",buffer);
  fwrite(buffer, 1, strlen(buffer),fp);
  fclose(fp);
  return 0;
}
