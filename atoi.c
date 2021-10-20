#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define INT_UPPER_BOUND  2147483648
#define INT_LOWER_BOUND -2147483648

int myAtoi(char *s){
    long long int num = 0;
    int nums[128];
    int nums_len = 0;
    short sign_count = 0;
    short parsed_count = 0;
    bool negative = false;
    bool leading_zeroes = false;
    bool number_passed = false;
    bool number_current_prev = false;
    bool number_current = false;
    
    for(int i = 0; s[i] != 0; i++) {
        switch(s[i]) {
            case ' ':
                number_current = false;
                goto difference_recorder;
            break;

            case '+':
                negative = false;
                number_current = false;
                sign_count++;
                if(sign_count > 1) {return 0;} else {goto difference_recorder;}
            break;
            
            case '-':
                negative = true;
                number_current = false;
                sign_count++;
                if(sign_count > 1) {return 0;} else {goto difference_recorder;}
            break;
           
            case '.':
                goto convert_dec; 
            break;
                
            case '0':
                if(!number_passed) {
                    leading_zeroes = true;
                } else {
                    nums[nums_len] = 0;
                    nums_len++;
                    number_passed = true;
                    number_current = true;
                }
            break;
                
            case '1':
                nums[nums_len] = 1;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '2':
                nums[nums_len] = 2;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '3':
                nums[nums_len] = 3;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '4':
                nums[nums_len] = 4;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '5':
                nums[nums_len] = 5;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '6':
                nums[nums_len] = 6;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '7':
                nums[nums_len] = 7;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '8':
                nums[nums_len] = 8;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            case '9':
                nums[nums_len] = 9;
                nums_len++;
                number_passed = true;
                number_current = true;
            break;
                
            default:
                number_current = false;
                if(!number_passed) {
                    return 0;
                }
        }
        
        difference_recorder: 
        if(number_current != number_current_prev) {
            if(!(number_current_prev && !number_current)) {
                parsed_count++;
            }
        }
        
        number_current_prev = number_current;
        
        if(parsed_count > 1) {
            nums_len -= 1;
            goto convert_dec;
        }
        
        if(nums_len > 10) {
            return (negative) ? INT_LOWER_BOUND : INT_UPPER_BOUND - 1;
        }
    }
    
    
    convert_dec:
    nums_len--;
    for(int i = 0; nums_len >= 0; nums_len--, i++) {
        num += nums[i] * ((long long int)pow(10, nums_len));
    }
    
    if(negative) {
        num *= -1;
    }
    num = (num >= INT_UPPER_BOUND) ? INT_UPPER_BOUND - 1 : num;
    num = (num <= INT_LOWER_BOUND) ? INT_LOWER_BOUND : num;
    
    return (int)num;
}
