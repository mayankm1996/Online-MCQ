#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int top = -1, max = 0;
long long int a[100000], high[100000];
void push(long long int data)
{
    top++;
    a[top] = data;
}
void pushHigh(long long int data)
{
    high[top] = data;
}
void pop()
{
    --top;
}
void print()
{
    printf("%lld\n", high[top]);
}
int main() 
{
    long long int n, i, element;
    int query;
    scanf("%lld", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &query);
        if(query == 1)
        {
            scanf("%lld", &element);
            push(element);
            if(element > max)
            {
                max = element;
            }
                pushHigh(max);
        }
        if(query == 2)
        {
            pop();
            max = high[top];
        }
        if(query == 3)
        {
           print(); 
        }
    }
    return 0;
}
