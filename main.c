#include <stdio.h>
#include "NumClass.h"


int main(){
    int x,y=0;
    scanf("%d",&x);
    scanf("%d",&y);
    int min,max;
    if(x<=y){
        min=x;
        max=y;
    }else{
        min=y;
        max=x;
    }
    int primes[max-min];
    int armstrongs[max-min];
    int strongs[max-min];
    int palindromes[max-min];
    int iPrime=0,iArmstrong=0,iStrong=0,iPalindrome=0;
    for (int i = min; i <= max; i++){
        if(isPrime(i)==1){
            primes[iPrime]=i;
            iPrime++;
        }
        if(isArmstrong(i)==1){
            armstrongs[iArmstrong]=i;
            iArmstrong++;
        }
        if(isStrong(i)==1){
            strongs[iStrong]=i;
            iStrong++;
        }
        if(isPalindrome(i)==1){
            palindromes[iPalindrome]=i;
            iPalindrome++;
        }
    }
    printf("The Armstrong numbers are:");
    for(int i=0;i<=iArmstrong;i++){
        printf(" %d", armstrongs[i]);
    }
    printf("\nThe Palindromes are:");
    for(int i=0;i<=iPalindrome;i++){
        printf(" %d", palindromes[i]);
    }
    printf("\nThe Prime numbers are:");
    for(int i=0;i<=iPrime;i++){
        printf(" %d", primes[i]);
    }
    printf("\nThe Strong numbers are:");
    for(int i=0;i<=iStrong;i++){
        printf(" %d", strongs[i]);
    }
    return 0;
}
