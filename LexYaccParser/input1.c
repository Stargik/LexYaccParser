#include<stdio.h>
#include<string.h>

int main() {
    int a;
    int x=1;
    int y=x;
    int z=3;
    a = 2;
    x=3;
    y=10;
    z=5;
    z = y * (z - y) * z;
    if(x>5) {
        x=1;
    } else {
        int idx = 1;
    }
    for(int i=0; i<10; i++) {
        printf("Hello World!");
        x = x + 1;
    }
    for(int k=0; k<10; k++) {
        printf("Hello World!");
        x = x + 1;
    }
    while(x<10) {
        printf("Hello World!");
        x = x + 1;
    }
    return a;
}
