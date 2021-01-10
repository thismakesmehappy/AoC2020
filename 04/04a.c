#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum
{
    byr = 0,
    iyr = 1,
    eyr = 2,
    hgt = 3,
    hcl = 4,
    ecl = 5,
    pid = 6,
    cid = 7
};

void
check_field(char* validity, char* buffer);

int
main()
{
    int count, blank_line, all_lines;
    char buffer[512];
    char validity[] = "00000000";
    FILE *passports;

    count = 0;
    blank_line = 0;
    all_lines = 0;

    passports = fopen("input.txt", "r");
    if(passports == NULL)
    {
        perror("open");
        exit(1);
    r

    while(fgets(buffer, sizeof(buffer), passports))
    {
        all_lines ++;
        if(strcmp(buffer, "\n") == 0)
        {
            blank_line ++;
            if(strncmp(validity, "1111111", 7) == 0)
            {
                count ++;
                printf("\x1B[33m");
                //printf("%i\t", blank_line);
            }
            else
            {
                printf("\x1B[0m");
            }
            printf("%3i | %s | %3i\t", blank_line, validity, count);
            if(blank_line % 8 == 0)
                printf("\n");
            strcpy(validity, "00000000");
        }
        else
        {
            check_field(validity, buffer);
        }
    }

    //if(strncmp(validity, "1111111", 7) == 0)
    //{
    //    count ++;
    //}
    blank_line ++;
    printf("%3i | %s | %3i\t", blank_line, validity, count);
    fclose(passports);

    printf("final count: %i\n", count);
    printf("total lines: %i\n", all_lines);
}


void
check_field(char* validity, char* buffer)
{
    char *field;

    while((field = strtok_r(buffer, " ", &buffer)))
    {
        if(strncmp(field, "byr:", 4) == 0)
        {
            validity[byr] = '1';
        }
        if(strncmp(field, "iyr:", 4) == 0)
        {
            validity[iyr] = '1';
        }
        if(strncmp(field, "eyr:", 4) == 0)
        {
            validity[eyr] = '1';
        }
        if(strncmp(field, "hgt:", 4) == 0)
        {
            validity[hgt] = '1';
        }
        if(strncmp(field, "hcl:", 4) == 0)
        {
            validity[hcl] = '1';
        }
        if(strncmp(field, "ecl:", 4) == 0)
        {
            validity[ecl] = '1';
        }
        if(strncmp(field, "pid:", 4) == 0)
        {
            validity[pid] = '1';
        }
        if(strncmp(field, "cid:", 4) == 0)
        {
            validity[cid] = '1';
        }
    }
}

