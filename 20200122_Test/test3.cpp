#include <iostream>
#include <assert.h>

size_t Strlen(const char* str){
    if(str == NULL){
        return 0;
    }
    size_t count = 0;
    while(str[count] != '\0'){
        ++count;
    }
    return count;
}

size_t Strlen1(const char* str){
    assert(str != NULL);
    size_t count = 0;
    while(str[count] != '\0'){
        ++count;
    }
    return count;
}

int main(){
    int a[3][2] = {{0, 1}, {2, 3}, {4, 5}};
    int* p = a[0];
    printf("%d\n", p[0]);

    char str[] = "hehe";
    char* p_str = str;
    if(p_str != NULL){
        printf("%lu\n", Strlen(p_str));
        printf("%lu\n", Strlen1(p_str));
    }
}