#include <iostream>

union IP{
	struct{
		char d1;
		char d2;
		char d3;
		char d4;
	}b;
	uint32_t a;
}ip;

int main(){
	ip.a = 0x1;
	printf("%d.%d.%d.%d\n", ip.b.d1, ip.b.d3, ip.b.d3, ip.b.d4);
	return 0;
}