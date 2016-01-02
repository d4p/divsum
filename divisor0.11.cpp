#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

//#define NOT_SPOJ

using namespace std;
FILE *f;

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

inline int find_div_sqrt_sum(int number){
    int sum = 1;
    double gg=sqrt(number);
    for(int i=2; i<=gg; i++) {
        if(number % i == 0){
            sum+=i;
            if (number/i > gg)
                sum+= number/i;
        }
    }
    //printf("%d\n", sum);
    char buf[11];
    buf[10] = '\n';
    int i = 9;
    while (sum)
    {
        buf[i--] = sum % 10 + '0';
        sum /= 10;
    }
    while (buf[i] != '\n')
        putchar(buf[++i]);
}

int main(int argc, char *argv[])
{
    int count = 0;
#ifdef NOT_SPOJ
    f = fopen("input2.txt","r");
    fscanf(f,"%d\n", &count);
#else
    scanf("%d\n", &count);
#endif
    while (count--){
        int number = 0;
#ifdef NOT_SPOJ
        fscanf(f,"%d\n",&number);
#else
        //scanf("%d\n",&number);
        char c = 0;
        c = getchar();
        while (c != '\n' && c != EOF){
            number = number *10 + c - '0';
            c = getchar();
        }
        if (number != 0 && c == EOF){
            return 0;
        }
#endif
        if(number == 1)
            printf("0\n");
        else{
            find_div_sqrt_sum(number);
        }
    }
    return 0;
}
