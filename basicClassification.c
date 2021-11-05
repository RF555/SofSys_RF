#include <stdio.h>
#include <math.h>
#include "basicClassification.h"

/* will return if a number is prime*/
int isPrime(int n){
    if(n==1)
    {
        return 1; //???? is 1 prime??
    }
    else if (n==2)
    {
        return 1;
    }
    else
    {
        // int sqr=sqrt(n);
        int i=0;
        int ans=1;
        // while (i<sqr)
        while (i<n)
        {
            if(n%i==0){
                return 0;
            }
        }
        return ans;
    }    
}
/*Strong number is a special number whose sum of the factorial of digits is equal to the original number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int isStrong(int n){
    

}