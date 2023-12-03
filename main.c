#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void challenge_one(char file_path[]) {

    FILE *p_file;

    p_file = fopen(file_path, "r");

    if(p_file == NULL) {
        printf("CHALLENGE ONE: Could not read input file\n");
        return;
    }


    char c;
    char buffer[3];
    int total = 0;
    int printed = 0;
    while ((c = fgetc(p_file)) != EOF) {
        if(isdigit(c)) {
            if (!printed) 
                buffer[0] = c;

            buffer[1] = c;
            printed = 1;
        }
        
        if (printed && c == '\n') {
            buffer[2] = '\0';
            printf("%s", buffer);
            total = total + atoi(buffer);
            memset(buffer, 0, sizeof buffer);
            
            printed = 0;
            printf("%c", c);
        }
    }
    
    printf("Total: %d\n", total);

    fclose(p_file);
}


int main() {
    printf("Advent Of Code 2023\n");

    challenge_one("input");



    return 0;
}
