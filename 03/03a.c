#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main ()
{
    int count, width, position;
    FILE *field;
    char buffer[256];

    field = fopen("input.txt", "r");
    if(field == NULL)
    {
        perror("open");
        exit(1);
    }

    count = 0;
    position = 0;
    width = 0;

    while(fgets(buffer, sizeof(buffer), field) != NULL)
    {
        if(width == 0)
        {
            width = strlen(buffer) - 1;
            printf("%i\n", width);
        }

        if(buffer[position] == '#')
        {
            count ++;
        }

        printf("%s\t%c %i %i\n", buffer, buffer[position], position, count);
        position = (position + 3) % width;
    }

    printf("Count: %i\n", count);



}
