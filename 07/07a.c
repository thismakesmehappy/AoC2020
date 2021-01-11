#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(){

    char buffer[512];
    int valid_bag_options;
    FILE *rules;

    valid_bag_options = 0;

    rules = fopen("input_test.txt", "r");
    if(rules == NULL){
        perror("open");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), rules)){
        printf("\t%s\n", &buffer[1]);
        printf("\t%s\n", strstr(&buffer[1], "shiny gold"));
        valid_bag_options += (strstr(&buffer[1], "shiny gold") != NULL);
    }
    fclose(rules);
    printf("\n\tTotal: %i\n", valid_bag_options);
}
