#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char word[6];
    char num;
} wordnum;

const wordnum nums[9] = {
    {"one", '1'},
    {"two", '2'},
    {"three", '3'},
    {"four", '4'},
    {"five", '5'},
    {"six", '6'},
    {"seven", '7'},
    {"eight", '8'},
    {"nine", '9'},
};


void challenge_one(char file_path[]) {

    FILE *p_file;

    p_file = fopen(file_path, "r");

    if(p_file == NULL) {
        printf("CHALLENGE ONE: Could not read input file\n");
        return;
    }


    char str[50];
    // fill str with null
    memset(str, 0, sizeof str);
    char c;
    char buffer[3] = {
        -1,
        -1,
        '\0'
    };
    int total = 0;
    while ((c = fgetc(p_file)) != EOF) {

        str[strlen(str)] = c;
        //printf("%s\n", str);
        for (int i = 0; i < 9; i++) {
            char* p_str;
            if ((p_str = strstr(str, nums[i].word)) != NULL) {
                memcpy(str, p_str, sizeof str);
                //printf("found: %s\n", nums[i].word);


                if (buffer[0] == -1) 
                    buffer[0] = nums[i].num;

                buffer[1] = nums[i].num;
                memmove(str, str+1, strlen(str));
                break;
                //printf("%s\n", str);
            }
        }


        if(isdigit(c)) {
            if (buffer[0] == -1) 
                buffer[0] = c;

            buffer[1] = c;
        }
        
        if (buffer[0] != -1 && c == '\n') {
            buffer[2] = '\0';
            printf("%s", buffer);
            total = total + atoi(buffer);
            memset(buffer, -1, sizeof buffer);
            memset(str, 0, sizeof str);
            
            printf("%c", c);
        }
    }
    
    printf("Total: %d\n", total);

    fclose(p_file);
}


int main() {
    printf("Advent Of Code 2023\n");

    challenge_one("inputs/input_1");

    return 0;
}
