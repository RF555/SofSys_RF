#include <stdio.h>
#include <math.h>
#include "basicClassification.h"
#include "advancedClassificationLoop.h"
#include "advancedClassificationRecursion.h"

int isPrime(int n);


int main(){
    int prime=isPrime(5);
    printf("%d",prime);
    return 0;
}
