#include <stdio.h>
#include "NumClass.h"

//Recursive

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrongRec(int n, int pow);
int countDigitNum(int n);
int myPow(int a, int b);
int reverse(int n,int rev);

int isArmstrong(int n){
    int count=countDigitNum(n);
    int sum =isArmstrongRec(n,count);
    if(sum==n){
        return 1;
    }else{
        return 0;
    }
}

int isArmstrongRec(int num, int Pow){
    int modN,sum=0;
    if(num>0){
        modN=num%10;
        sum=sum+myPow(modN,Pow)+isArmstrongRec((num/10),Pow);
        return sum;
    }else{
        return 0;
    }
}

/* will return if a number is a palindrome */
int isPalindrome(int n){
    int rev= reverse(n,0);
    if(rev==n){
        return 1;
    }else{
        return 0;
    }
}

int myPow(int a, int b){
    int Pow=1;
    for (int i = 0; i < b; i++){
        Pow=Pow*a;
    }
    return Pow;
}

int countDigitNum(int n){
    int count=0;
    for (int i = n; i!=0; ++count){ // counts the  num of digits of n
            i=i/10;
        }
    return count;
}

int reverse(int n,int rev){
    if(n!=0){
        int modTen=n%10;
        rev=rev*10+modTen;
        return reverse(n/10, rev);
    }else{
        return rev;
    }
}