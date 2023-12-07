#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char id[6];
    int amount;
} lookup_t;

const lookup_t COLORS[] = {
    {"red", 12},
    {"green", 13},
    {"blue", 14}
};

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
        // get id
        char *token = strtok(line, " ");

        char id[5];
        strcpy(id, strtok(NULL, ":"));
        //id[strlen(id)-1] = '\0';


        token = strtok(NULL, ",;");

        printf("%s\n", id);
        while (token != NULL) {
            //printf("%s\n", token);

            // not good if COLORS array gets bigger in the future but that doesn't matter here
            int index = -1;
            for (int i = 0; i < 3; i++) {
                if (strstr(token, COLORS[i].id) != NULL) {
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

                if (COLORS[index].amount < atoi(buffer)) {
                    printf("Not Possible.\n");
                    memset(id, 0, sizeof id);
                    break;
                }
                printf("Possible.\n");
            }
            token = strtok(NULL, ",;");
        }

        if (isdigit(id[0])) {
            total+=atoi(id);
            printf("Total: %d\n", total);
        }
    }

    printf("Result: %d\n", total);

}

int main() {
    printf("Advent Of Code 2023\n");

    challenge_two("inputs/input_2");
    return 0;
}
