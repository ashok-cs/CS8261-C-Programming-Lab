#include<stdio.h>
/* Function prototype */
void honoi(int, char, char, char);

int main()
{
        int n;
        printf("How many disk..........\n");
        scanf("%d",&n);
        honoi(n,'L','R','C');
        return 0;
}

void honoi(int n, char from, char to, char temp)
{
        if( n > 0 )
        {
                honoi(n-1, from, temp,to);
                printf("Move disk %d from %c to %c\n", n, from, to);
                honoi(n-1,temp, to, from);
        }

}
