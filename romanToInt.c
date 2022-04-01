#include <string.h>

int romanToInt(char *s){
    int nums[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int result = 0;

    for(int i = 0; i < 15 && *s != '\0'; ++i) {
        switch(*s) {
            case 'I':
                nums[i] += 1;
                break;
            case 'V':
                nums[i] += 5;
                break;
            case 'X':
                nums[i] += 10;
                break;
            case 'L':
                nums[i] += 50;
                break;
            case 'C':
                nums[i] += 100;
                break;
            case 'D':
                nums[i] += 500;
                break;
            case 'M':
                nums[i] += 1000;
                break;
        }
        ++s;
    }
   
    for(int j = 0; j < 15; ++j) {
        if(nums[j] < nums[j + 1]) {
            result -= nums[j];
        } else {
            result += nums[j];
        }
    }
    
    return result;
}
