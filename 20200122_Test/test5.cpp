#include <iostream>
#include <string.h>
#include <errno.h>

using namespace std;

int Tolower(int c){
    if(c >= 'A' && c <= 'Z'){
        c += 'a' - 'A';
    }
    return c;
}
int Toupper(int c){
    if(c >= 'a' && c <= 'z'){
        c -= 'a' - 'A';
    }
    return c;
}

int main(){
    FILE* fp = fopen("test.txt", "r");
    printf("%d\n", errno);
    printf("%s\n", strerror(errno));
    printf("%s\n", strerror(2));

    char str[] = "aBcdEFG";
    for(auto& e : str){
        //char c = tolower((int)e);
        char c = Tolower((int)e);
        cout << c;
    }
    cout << endl;
    for(auto& e : str){
        //char c = toupper((int)e);
        char c = Toupper((int)e);
        cout << c;
    }
    cout << endl;
    return 0;
}