#include <stdio.h>
#include <string.h>
#include <assert.h>

const char*Strchr(const char* str, int s){
  assert(str != NULL);
  while(*str != '\0' && *str != s)
  {
    ++str; 
  }
    return *str == s ? str : NULL;
}

int main ()
{
  char str[] = "This is a sample string";
  const char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch = Strchr(str,'s');
  while (pch != NULL)
  {
    printf ("found at %d\n",pch-str+1);
    pch = Strchr(pch+1,'s');
  }
  return 0;
}
