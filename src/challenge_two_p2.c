#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char id[6];
    int amount;
} lookup_t;



void challenge_two(char file_path[]) {
    FILE *p_file;

    p_file = fopen(file_path, "r");

    if (p_file == NULL) {
        printf("CHALLENGE TWO: Could not read input file\n");
        return;
    }


    int total = 0;
    char line[300];
    while (fgets(line, 300, p_file) != NULL) {
        if (strlen(line) < 4) {
            // workarond for an empty line
            break;
        }

        //remove first part of string
        char *token = strtok(line, ":");


        lookup_t colors[3] = {
            {"red", 0},
            {"green", 0},
            {"blue", 0}
        };

        token = strtok(NULL, ",;");
        while (token != NULL) {

            // just realized how strange it is looping through that and then breaking out
            // idc because this is just a random coding challenge
            int index = -1;

            // not good if COLORS array gets bigger in the future but that doesn't matter here
            for (int i = 0; i < 3; i++) {
                if (strstr(token, colors[i].id) != NULL) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {

                char buffer[5];
                memset(buffer, 0, sizeof buffer);

                size_t size = strlen(token);
                for (int i = 0; i < size; i++) 
                    if (isdigit(token[i])) 
                        buffer[strlen(buffer)] = token[i];

                int amount = atoi(buffer);
                if (colors[index].amount < amount)
                    colors[index].amount = amount;
            }
            token = strtok(NULL, ",;");
        }



        int result = colors[0].amount * colors[1].amount * colors[2].amount;

        total+=result;
        printf("Total: %d\n", total);
    }

    printf("Result: %d\n", total);

}

int main() {
    printf("Advent Of Code 2023\n");

    challenge_two("inputs/input_2");
    return 0;
}
