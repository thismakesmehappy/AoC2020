#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main ()
{
    int valid_count, char_count, min, max, i;
    char current_char;
    char *password_string;
    char buffer[512];
    FILE *passwords;


    passwords=fopen("input.txt", "r");
    if(passwords == NULL)
    {
        perror("open");
        exit(1);
    }
    valid_count = 0;

    while(fgets(buffer, sizeof(buffer), passwords) != NULL)
    {    
        password_string = buffer;
        min = atoi(strtok_r(password_string, "-", &password_string));

        max = atoi(strtok_r(password_string, " ", &password_string));

        current_char = strtok_r(password_string, ":", &password_string)[0];

        printf("%s\n", &password_string[1]);

        if((password_string[min] != password_string[max]) && 
                ((password_string[min] == current_char) || (password_string[max] == current_char)))
        {
           valid_count ++;
        }
    printf("current_char: %c | min:%i (%c) | max: %i (%c) | char count: %i | valid count: %i\n\n", current_char,  min, password_string[min],  max, password_string[max], char_count, valid_count);
    }

printf("byeeee!!!\n");
    fclose(passwords);
}

