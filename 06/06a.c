#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(){

    char buffer[32];
    char *read_line;
    int i, yes_total;
    int yes_group[26], yes_all[26];
    FILE *answers;

    memset(yes_group, '\0', sizeof(yes_group));
    memset(yes_all, '\0', sizeof(yes_group));
    yes_total = 0;

    answers = fopen("input.txt", "r");
    if(answers == NULL){
        perror("open");
        exit(1);
    }

    do{
        read_line = fgets(buffer, sizeof(buffer), answers);
        if(strcmp(buffer, "\n") == 0 || read_line == NULL){
            for(i = 0; i < 26; i++){
                printf("%i ", yes_group[i]);
                yes_all[i] += yes_group[i];
                yes_total += yes_group[i];
            }
            printf("\n");
            memset(yes_group, '\0', sizeof(yes_group));
        }
        else {
            for(i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i ++){
                printf("%i\t%i\t%i\n", i, (buffer[i] - 'a'), yes_group[(buffer[i] - 'a')]);
                yes_group[(buffer[i] - 'a')] |=  1;
            }
        }
    }while(read_line != NULL);

    fclose(answers);
    printf("\n\tTotal: %i\n", yes_total);
}
