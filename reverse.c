#include <stdlib.h>
#include <string.h>

int reverse(int x){
    bool negative = x < 0;
    if(negative) {
        if(x == -2147483648) {
            x += 1;
        }
        x *= -1;
    }
    char xstr[52];
    sprintf(xstr, "%i", x);
    int len = strlen(xstr);
    
    // reversing stringified x
    for(int i = 0; i < len / 2; ++i) {
        int temp = xstr[i];
        xstr[i] = xstr[len - i - 1];
        xstr[len - i - 1] = temp;
    }
        
    // bound checking
    if(len >= 10) {
        char *bound = "2147483647";
        for(int j = 0; j < 10; ++j) {
            if(xstr[j] >= bound[j]) {
                if(xstr[j] > bound[j]) {
                    return 0;
                }
            } else {
                break;
            }
        }
    }
    
    // convert back to int & return
    x = atoi(xstr);
    return negative ? x * -1 : x;
}
