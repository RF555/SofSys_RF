#include <stdio.h>
#include <math.h>
#include "NumClass.h"

//Loop
// int myPow(int a, int b);
int countDigitNum(int n);

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int n){
    int sum=0;
    int count=countDigitNum(n);
    if (n==0){
        return 1;
    }else{    

        for (int N = n; N != 0 ; N=N/10){
            int mod=N%10;
            // sum=sum+myPow(mod,count);
            sum=sum+pow(mod,count);
        }        
        if(sum==n){
            return 1;
        }else{
            return 0;
        }  
    }
}

/* will return if a number is a palindrome */
int isPalindrome(int n){
    int count=countDigitNum(n);
    char st[count];
    sprintf(st,"%d",n);
    int i=0, j=count-1, ans=1;
    if(count%2==0){ // if count is even -> no middle digit
        while (i<j){
            if(st[i]!=st[j]){
                ans=0;
                break;
            }else{
                ans=1;
            }
            i++;
            j--;
        }
    }else{
        while (i<=j){
            if(st[i]!=st[j]){
                ans=0;
                break;
            }else{
                ans=1;
            }
        i++;
        j--;
        }
    }
    return ans;
}

// int myPow(int a, int b){
//     int Pow=1;
//     for (int i = 0; i < b; i++){
//         Pow=Pow*a;
//     }
//     return Pow;
// }

int countDigitNum(int n){
    int count=0;
    for (int i = n; i!=0; ++count){ // counts the  num of digits of n
            i=i/10;
        }
    return count;
}
