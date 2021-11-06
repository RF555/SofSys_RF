#include "NumClass.h"

//Loop
int pow(int a, int b);

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int n){
    int count=0, sum=0;
    if (n==0){
        return 1;
    }else{    
        for (int i = n; i!=0; ++count){ // counts the  num of digits of n
            i=i/10;
        }
        for (int N = n; N != 0 ; N=N/10){
            int mod=N%10;
            sum=sum+myPow(mod,count);
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

}

int pow(int a, int b){
    int Pow=1;
    for (int i = 0; i < b; i++){
        Pow=Pow*Pow;
    }
    
}
