#include "NumClass.h"

int factorial(int n);

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
        int sqr=sqrt(n);
        int i=0;
        int ans=1;
        while (i<sqr)
        // while (i<n)
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
    int sumOfFact=0;
    int N=n;
    while(N!=0){
        int NmodTen=N%10;
        N=N/10;
        int factOfMod=factorial(NmodTen);
        sumOfFact=sumOfFact+factOfMod;
    }
    return sumOfFact;
}

int factorial(int n);{
    if(n==0 or n==1){
        return 1;
    }else {
        int fact=1;
        while(n!=1){
            fact=fact*n;
            n--;
        }
        return fact;
    }
}