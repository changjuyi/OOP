#pragma once
// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b) {
    if(a<0){
        a*=(-1);
    }
    if(b<0){
        b*=(-1);
    }

    if(b==0){
        return a;
    }
    return gcd(b, a%b);
    /*
    while(b!=0){
        int r = a % b;
        a=b;
        b=r;
    }
    */
    
}