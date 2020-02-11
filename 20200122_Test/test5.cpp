#include <iostream>
#include <string.h>
#include <errno.h>

using namespace std;

int main(){
    FILE* fp = fopen("test.txt", "r");
    printf("%d\n", errno);
    printf("%s\n", strerror(errno));
    printf("%s\n", strerror(2));
    return 0;
}