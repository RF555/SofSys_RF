#include "NumClass.h"

//Recursive

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstroenRec(int n, int pow);
int countDigitNum(int n);
int myPow(int a, int b);

int myPow(int a, int b);

int isArmstrong(int n){
    int count=countDigitNum(n);
    int sum =isArmstrongRec(n,count);
    if(sum==n){
        return 1;
    }else{
        return 0;
    }
}

int isArmstrongRec(int num, int pow){
    int modN,sum=0;
    if(num>0){
        modN=num%10;
        sum=sum+myPow(modN,pow)+isArmstrongRec((num/10),pow);
        return sum;
    }else{
        return 0;
    }
}

/* will return if a number is a palindrome */
int isPalindrome(int n){

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
