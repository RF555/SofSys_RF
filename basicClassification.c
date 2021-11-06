#include "NumClass.h"

int factorial(int n);

/* will return if a number is prime*/
int int isPrime(int n){
    int ans=1;
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
        int ans=1;
        for(int i=2; i<=(n/2)+1; i++)        
        {
            if(n%i==0){
                ans = 0;
                break;
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

int factorial(int n){
    if(n==0 || n==1){
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
