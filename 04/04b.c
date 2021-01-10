#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

char
in_range(char* field, int low_year, int high_year);

char
right_height(char* field);

char
right_hair(char* field);

char
right_eye(char* field);

char
right_id(char* field);

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
    }

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
            printf("\n%3i | %s | %3i\t", blank_line, validity, count);
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
    //blank_line ++;
    printf("%3i | %s | %3i\n", blank_line, validity, count);
    fclose(passports);

    printf("final count: %i\n", count);
    printf("total lines: %i\n", all_lines);


/*
    printf("valid 2002\t%c\n", in_range("2002", 1920, 2002));
    printf("invalid 2003\t%c\n", in_range("2003", 1920, 2002));
    printf("valid 60in\t%c\n", right_height("60in"));
    printf("valid 190cm\t%c\n", right_height("190cm"));
    printf("invalid 190in\t%c\n", right_height("190in"));
    printf("invalid 190\t%c\n", right_height("190"));
    printf("valid #123abc\t%c\n", right_hair("#123abc"));
    printf("invalid #123abz\t%c\n", right_hair("#123abz"));
    printf("invalid 123abc\t%c\n", right_hair("123abc"));
    printf("valid brn\t%c\n", right_eye("brn"));
    printf("valid wat\t%c\n", right_eye("wat"));
    printf("valid 000000001\t%c\n", right_id("000000001"));
    printf("invalid 0123456789\t%c\n", right_id("0123456789"));
*/
    
}


void
check_field(char* validity, char* buffer)
{
    char* field;

    while((field = strtok_r(buffer, " ", &buffer)))
    {
        if(field[strlen(field) - 1] == '\n')
            field[strlen(field) - 1] = '\0';
        printf("\t%s", &field[4]);
        if(strncmp(field, "byr:", 4) == 0)
        {
            validity[byr] = in_range(&field[4], 1920, 2002);
        }
        if(strncmp(field, "iyr:", 4) == 0)
        {
            validity[iyr] = in_range(&field[4], 2010, 2020);
        }
        if(strncmp(field, "eyr:", 4) == 0)
        {
            validity[eyr] = in_range(&field[4], 2020, 2030);
        }
        if(strncmp(field, "hgt:", 4) == 0)
        {
            validity[hgt] = right_height(&field[4]);
        }
        if(strncmp(field, "hcl:", 4) == 0)
        {
            validity[hcl] = right_hair(&field[4]);
        }
        if(strncmp(field, "ecl:", 4) == 0)
        {
            validity[ecl] = right_eye(&field[4]);
        }
        if(strncmp(field, "pid:", 4) == 0)
        {
            validity[pid] = right_id(&field[4]);
        }
        if(strncmp(field, "cid:", 4) == 0)
        {
            validity[cid] = '1';
        }
    }
}

char
in_range(char* field, int low_year, int high_year)
{
    int year;

    year = atoi(field);

    return ((year >= low_year) && (year <= high_year)) + '0';
}

char
right_height(char* field)
{
    int height;

    height = atoi(field);

    if((field[strlen(field)-2] == 'c') && (field[strlen(field)-1] == 'm') && (height >= 150) && (height <= 193))
    {
        return '1';
    }
    if((field[strlen(field)-2] == 'i') && (field[strlen(field)-1] == 'n') && (height >= 59) && (height <= 76))
    {
        return '1';
    }
    else
    {
        return '0';
    }
}

char
right_hair(char* field)
{
    int i;

    if(field[0] != '#' || strlen(field) != 7)
    {
        return '0';
    }
    else
    {
        for(i = 1; i <= 6; i ++)
        { 
            if(!((field[i] >= '0' && field[i] <= '9') || (field[i] >= 'a' && field[i] <= 'f')))
            {
                return '0';
            }
        }
        return '1';
    }
}

char
right_eye(char* field)
{
    return((strcmp(field, "amb") == 0) || (strcmp(field, "blu") == 0) || 
            (strcmp(field, "brn") == 0) || (strcmp(field, "gry") == 0) ||
            (strcmp(field, "grn") == 0) || (strcmp(field, "hzl") == 0) ||
            (strcmp(field, "oth") == 0)) + '0';
}

char
right_id(char* field)
{
    int i;

    if(strlen(field) != 9)
    {
        return '0';
    }
    else
    {
        for(i = 0; i < 9; i ++)
        {
            if(!isdigit(field[i]))
                return '0';
        }
        return '1';
    }
}
