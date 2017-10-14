#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long long int a1, a2, a3, i;
    scanf("%lld %lld %lld", &a1, &a2, &a3);
    long long int max1 = 0, max2 = 0, max3 = 0;    
    long long int arr1[a1], arr2[a2], arr3[a3];
    for(i = 0; i < a1; i++)
    {
        scanf("%lld", &arr1[i]);
        max1 = max1 + arr1[i];
    }
    for(i = 0; i < a2; i++)
    {
        scanf("%lld", &arr2[i]);
        max2 = max2 + arr2[i];
    }
    for(i = 0; i < a3; i++)
    {
        scanf("%lld", &arr3[i]);
        max3 = max3 + arr3[i];
    }
    long long int s1 = 0, s2 = 0, s3 = 0; 
    while(max1 != max2 || max2 != max3 || max1 != max3)
    {
        if((max1 > max2 && max1 > max3) || (max1 == max2 && max1 > max3) || (max1 > max2 && max1 == max3))
        {
            max1 = max1 - arr1[s1++];
        }
        else if((max2 > max1 && max2 > max3) || (max2 == max1 && max2 > max3) || (max2 > max1 && max2 == max3))
        {
            max2 = max2 - arr2[s2++];
        }
        else if((max3 > max2 && max3 > max1) || (max3 == max2 && max3 > max1) || (max3 > max2 && max3 == max1))
        {
            max3 = max3 - arr3[s3++];
        }
       
    }
    printf("%lld", max1);
    return 0;
}

