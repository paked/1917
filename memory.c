//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {

    int x;
    int y;
    long total;

    x = 40;
    y = 2;

    total = add (x, y);

    printf("the sum of %d and %d is %ld\n", x, y, total);

    char c ='a';

    unsigned long ul       = 0;
    unsigned int ui        = 1;
    unsigned long long ull = 2;
    unsigned short us      = 3;

    signed long sl       = 4;
    signed int si        = 5;
    signed long long sll = 6;
    signed short ss      = 7;

    long l       = 8;
    int i        = 9;
    long long ll = 10;
    short s      = 11;

    float f = 3.1;
    double d = 3.14;

    printf("sizeof unsigned long: %ld, position: %p\n", sizeof(ul), &ul);
    printf("sizeof unsigned int: %ld\n, position %p\n", sizeof(ui), &ui);
    printf("sizeof unsigend long long: %ld, position: %p\n", sizeof(ull), &ull);
    printf("sizeof unsigned short: %ld, position: %p\n", sizeof(us), &us);

    printf("sizeof signed long: %ld, position: %p\n", sizeof(sl), &sl);
    printf("sizeof signed int: %ld, position: %p\n", sizeof(si), &si);
    printf("sizeof signed long long: %ld, position: %p\n", sizeof(sll), &sll);
    printf("sizeof signed short: %ld, position: %p\n", sizeof(ss), &ss);

    printf("sizeof long: %ld, position: %p\n", sizeof(l), &l);
    printf("sizeof int: %ld, position: %p\n", sizeof(i), &i);
    printf("sizeof long long: %ld, position: %p\n", sizeof(ll), &ll);
    printf("sizeof short: %ld, position: %p\n", sizeof(s), &s);

    printf("sizeof float: %ld, position: %p\n", sizeof(f), &f);
    printf("sizeof double: %ld, position: %p\n", sizeof(d), &d);

    // add them all together just to make use of them so the compiler
    // doesn't grumble that they are unused in the program

    double grandTotal;
    grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;

    printf ("all these things added together make %f\n", grandTotal);

    return EXIT_SUCCESS;
}

long add (int x, int y) {
    long answer;
    answer = x + y;

    return answer;
}
