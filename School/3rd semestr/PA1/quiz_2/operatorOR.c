#include <stdio.h>

int main(void)
{
    int x = 15;

    if ( x == (15 || 24) )
    { 
        printf("%d", x);
    }
    return 1;
}