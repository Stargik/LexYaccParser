#include<stdio.h>
#include<string.h>

int main() {
    int x = 0;
    if(x > 5) {
        x = 1;
    } else {
        int y = 5;
    }
    for(int i=0; i<10; i++) {
        printf("Hello World!");
        x = x + 1;
    }
    for(int k=0; k<10; k++) {
        printf("Hello World!");
        x = x - 1;
    }
    while(x<10) {
        printf("Hello World!");
        x = x + 1;
    }
}

