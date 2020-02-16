#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    FILE* fp = fopen("./test.txt", "a+");
    if(fp == NULL){
        perror("fopen");
        return 1;
    }

    char buf[1024] = {0};
    fread(buf, 1, 8, fp);
    cout << buf << endl;

    // char buf1[1024] = "abcd";
    // fwrite(buf1, 1, 4, fp);

    char ch = fgetc(fp);
    cout << ch << endl;

    char buf2[1024] = {0};
    fgets(buf2, 5, fp);
    for(auto& e : buf2){
        cout << e << endl;
    }

    fclose(fp);
    return 0;
}