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

        i = 1;
        char_count = 0;

        while(password_string[i] != '\n')
        {
            if(password_string[i] == current_char)
            {
                 char_count ++;
            }

            // printf("\t%c\t%c\t\%i\n", password_string[i], current_char, char_count);
            i ++;
        }
        printf("added\n");

        if((min <= char_count) && (char_count <= max))
        {
           valid_count ++;
        }
    printf("current_char: %c | min:%i | max: %i | char count: %i | valid count: %i\n\n", current_char,  min, max, char_count, valid_count);
    }


    fclose(passwords);
}

