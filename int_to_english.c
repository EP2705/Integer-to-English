/*
Integer to English
Eliandro Pizzonia 251363956
CS 2211

this program converts any integer from 1-999 into the english word (in lower case)
*/

#include <stdio.h>

// function to convert numbers to words
void values(){ 
int user_num;

// arrays that store the english version of the ones, teens, tens, and hundreds
char *ones[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[9] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[9] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *hundreds[9] = {"one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", 
                    "seven hundred", "eight hundred", "nine hundred"};

// checking if the number is within a certain range and getting the index to locate the appropirate translation in the arrays
printf("\nPlease enter a value (1-999, 0 to quit): ");
scanf("%d", &user_num);
    
    if (user_num > 0 && user_num < 10){
        int ones_index = user_num % 10;
        printf("You entered the number %s\n", ones[ones_index -1]);
        values();
    }
    else if (user_num > 10 && user_num < 20){
        int teens_index = user_num % 10;
        printf("You entered the number %s\n", teens[teens_index -1]);
        values();
    }
    else if (user_num >= 20 && user_num < 100){
        int ones_index = user_num % 10;
        int tens_index = (user_num / 10) % 10;
            
            // if not a multiple of 10 include the ones digit
            if (user_num % 10 != 0){
                printf("You entered the number %s-%s\n", tens[tens_index - 1], ones[ones_index -1]);
                values();
            }
            else{
                printf("You entered the number %s\n", tens[tens_index - 1]);
                values(); 
            }
    }

    else if (user_num > 100 && user_num < 1000){
        int ones_index = user_num % 10;
        int tens_index = (user_num / 10) % 10;
        int hundreds_index = user_num / 100;
        
        // if not a multiple of 10 include the ones digit
        if (user_num % 10 != 0){
            
            if (tens_index == 0){
            printf("You entered the number %s and %s\n", hundreds[hundreds_index - 1], ones[ones_index - 1]);
            values();   
            } 
            
            else {
            printf("You entered the number %s and %s-%s\n", hundreds[hundreds_index - 1], 
            tens[tens_index - 1], ones[ones_index - 1]);
            values();
            }
             
        }
        else{
            if (tens_index == 0){
            printf("You entered the number %s\n", hundreds[hundreds_index - 1]);
            values();   
            }
            else{
            printf("You entered the number %s and %s\n", hundreds[hundreds_index - 1], tens[tens_index - 1]);
            values();
            }
        }
    }

    // handling special cases of the user number being 10 and 100
    else if (user_num == 10){
        printf("You entered the number %s\n", tens[0]);
        values();
    }
    else if (user_num == 100){
        printf("You entered the number %s\n", hundreds[0]);
        values();
    }
}

// main function where the program begins
int main() {
values();
return 0;
}