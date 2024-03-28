/*  cat - concatenate files and print on  the stdoutput version 1.0

    Copyright (C) 2023-2024 Free and Open Source Software "No Copyrights"

    This program is free software: you can redistribute it or modify it under the terms of the project that means you can do whatever you want with this program.

    Differences with Linux cat:
       This is a different code what it means that both programs may do the samething but in different ways
       This is a not GNU Core utilities (coreutils) program, it means that I created this program from zero by myself

       By Sam Jamsh also known as cyb3rguy

*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
// #include <unistd.h>

#define VERSION "1.0"
#define OWNER "Sam Jamsh"
#define EMAIL "th3cyb3rguy@protonmail.com"
#define WEBPAGE "https://github.com/samjamsh/clear"

#define PARAMETERS 6

unsigned int flen = 0; // amount of files
unsigned int line = 1; // line number 








void memset_(char *ptr, char ch, unsigned int size, unsigned int number)
{
    for (unsigned int i = 0; i < number; i++)
    {
        ptr[i] = ch;
    }
    return;

}



// compare 'number' characters in two strings (string1 and string2)
int cmpstrn(char *string1, char *string2, unsigned int number)
{
    int i = 0;
    int same;

    while ((string1[i] != '\0' && i < number) || (string2[i] != '\0' && i < number))
    {

        if (string1[i] == string2[i])
        {
            same = 0; // equal
        }
        else
        {
            same = 1; // different
            break;
        }
        i++;
    }
    return same;

}



// compare two strings characters
int cmpstr(char *string1, char *string2)
{
    int i = 0;
    int same;

    while (string1[i] != '\0' && string2[i] != '\0')
    {

        if (string1[i] == string2[i])
        {
            same = 0; // equal
        }
        else
        {
            same = 1; // different
            break;
        }
        i++;
    }
    return same;

}



// print file data
int printfd(char *program_name, char *filename, char options[]){

    FILE *file;

    if (cmpstr(filename, "-\0") == 0)
    {
        file = stdin;
    } 
    else 
    {
        file = fopen(filename, "rb");
    }


    if (file == NULL){ // if there's an error opening or reading the file
        printf("%s: %s: %s\n", program_name, filename, strerror(errno));
 
        return 1;
    }

    int breakline = 0;
    unsigned char c; // usigned char = 8 bits in total

    char option;
    unsigned char lchar;

    unsigned char lastchar;
    int lc;
    int lnum = 0;
    unsigned char auxc; // auxiliary char


    int one, two, three, four, five, six;

    // one = options[0];

    // two = options[1];

    three = options[2];

    four = options[3];

    five = options[4];

    // six = options[5];

// while a char is being read
while (fread(&c, sizeof(c), 1, file) != 0){
    lc++;
    lchar = c;
    auxc = c;


    if (c == 10)
    {
        breakline++;
    } else {
       breakline = 0;
    }

    // check one time each of six options
    for (int i = 0; i < PARAMETERS; i++){

    option = options[i];


    // case options is -n
    if (option == '1')
    {
        if (lc == 1 && three != '3')
        {
            
            printf("%d ", line);
              

        }
    
    }



    // case option is -E
    else if (option == '2')
    {

            // case char is \n
           if (four == '4' && breakline > 2 && c == 10)
           {
               printf("%c", 0);
               
               
           }
           else if (c == 10)
           {
               printf("$");
           }
    }


    // case option is -b
    else if (option == '3')
    {

      
      // if its the first char in this line
        if (lc == 1)
        {

            if (auxc != 10)
            {

                lnum++; // line number
                printf("%d ", lnum); // line);
            }
        // if fgetc(file) == 10: do nothing
        }

    }


    // case option is -s
    else if (option == '4')
    {

           if (c == 10 && breakline > 2){
        
               c = 0;
           }
    }


    // case option is -T
    else if (option == '5'){

           // case char is \t
           if (c == 9){
               printf("^I");
   
               c = 0;
           }
    }





    // case option is -v
    else if (option == '6')
    {
   



    if (c >= 32)
    {
        if (c < 127)
        {
            c = c;
        }
        else if (c == 127)
        {
                printf("^?");
                c = 0;
        }
        else
        {
            printf("M-");

            if (c >= 128 + 32)
            {
                if (c < 128 + 127)
                {
                    printf("%c", c - 128);
                    c = 0;
                }
                else
                {
                    printf("^?");
                    c = 0; // duvida
                } 
            }
            else
            {
                printf("^%c", c - 128 + 64);
                c = 0;
            }

        }

    }
    else if (c == '\t' && five != '5')
    {
        c = c;
    }
    else if (c == '\n')
    {
        c = c;
    }
    else
    {
        printf("^%c", c + 64);
        c = 0; // duvida
    }




    } // option

    } // for
    


    if (c != 0)
    {
        printf("%c", c);
    }

    lastchar = lchar;


    if (c == 10 || (auxc == 10 && c == 0))
    {
        lc = 0;
        line++;
    }

    fflush(stdout);

    } // while

    fclose(file);

    return 0;
} // function




// check valid/invalid parameter argument
int check_option(char *option){
    char *options[] = {"-n\0", "-E\0", "-b\0", "-s\0", "-T\0", "-v\0", "-A\0", "-e\0", "-t\0", "--number\0", "--show-ends", "--number-nonblank", "--squeeze-blank", "--show-tabs", "--show-nonprinting", "--show-all", "-\0"}; // all options allowed or valid options are here

    int ol = 17; // options lenght, or all options available, that exists

    int sof = 0; // same option found (if an option equal to some option in options[] was found)

    int i = 0; // indice, increment

    for (i = 0; i < ol; i++ ){
        if (strcmp(option, options[i]) == 0){ // compares if option bytes are same with options[i] bytes, to check if option value exists in options values
            sof = 1;    // if option has a equal or identical data value in options array, then option is a valid option bacause it exists in options array then sof=1
            return 0;

        } else {
            sof = 0; // if option has not an identical or equal element or data or value present in options array, then option value is not present in options array and sof=0
        }
    }
    return 1;
}




int main(int argc, char* argv[])
{

    char choiced[PARAMETERS]; // choosen
    char option;

    // memset(choiced, 0, PARAMETERS);
    memset_(choiced, 0, sizeof(char), PARAMETERS);


    if (argc == 1){  // if no argument was given or user passed 0 arguments to the program

        printfd(argv[0], "-\0", choiced); // infinite loop until ctrl c is pressed
        return 0;
    }


    else if (strcmp(argv[1], "--version\0") == 0){ // if first parameter given by the user is --version
        printf("Cat (NGCU) version %s\nCopyright (C) 2024 Free and Open Source Software.\nThis is a free software: you are free to modify and redistribute it.\nWritten by %s  instagram> @sam.jamsh, email> %s\n", VERSION, OWNER, EMAIL);
        return 0;

    }
    else if (strcmp(argv[1], "--help\0") == 0)
    {
        // if first parameter given by the user is --help

        printf("Usage: %s [OPTION]... [FILE]...\nConcat FILE(S) to standard output.\n\n", argv[0]);

        puts("if no FILE are especified or - is specified, read standard input.\n-A, --show-all              equivalent to -vET\n-b, --number-nonblank       Numbers number of non-empty outputs overlays -n\n-e                          equivalent to -vE\n-E, --show-ends             displays $ at the end of each row\n-n, --number                numbers all output rows\n-s, --squeeze-blank         Suppresses repeated blank lines\n-t                          equivalent to -vT\n-T, --show-tabs             displays tab characters as ^I\n-v, --show-nonprinting      Uses notation ^ and M- except for LFD and Tab\n--help                      display this help and exit\n--version                   output version information and exit\n\nExamples:");

        printf("%s filename \n%s file1 file2\n\n", argv[0], argv[0]);

        printf("reporting bugs and complete documentation in <%s>\ncopyright: this is a free software you are free to change and redistribute it\nthis software was written by %s\n", WEBPAGE, OWNER);

        return 0;

    }


    int i;
    char *files[argc - 1]; // this array stores files or files names, argc -1 means that at max this array can store all arguments given except one that is argv[0] or program self name


    char *parameters[] = {"-n\0", "-E\0", "-b\0", "-s\0", "-T\0", "-v\0"}; // total 6



    for (i = 1; i < argc; i++){ // i = 1, i less than argc, cause it iterates in all arguments received starting by 1 and not 0 because 0 is the program self name


        
        if (strncmp(argv[i], "-", 1) == 0 && strcmp(argv[i], "-\0") != 0){ // compares if parameter(argv[i]) starts with or first character is -, it means its an option '-option'


            if (check_option(argv[i]) != 0){ // checks parameter(argv[i]) with function check_option if its a valid option or parameter
               
                puts("parameter error: invalid option");
                printf("try '%s --help' for help message", argv[0]);
                return 1;

            } else{       // here is when the parameter or option was already checked and its valid or it is correct



                if (cmpstr(argv[i], "-n\0") == 0 || cmpstr(argv[i], "--number\0") == 0 )
                { // this option is lines or lines number (--number)
                    option = '1';                    
                    choiced[0] = '1';
         

                }
                else if (cmpstr(argv[i], "-E\0") == 0 || cmpstr(argv[i], "--show-ends\0") == 0)
                { // this option is show ends bacause show end of line with $ (--show-ends)
                    option = '2';
                    choiced[1] = '2';

                }
                else if (cmpstr(argv[i], "-b\0") == 0 || cmpstr(argv[i], "--number-nonblank\0") == 0)
                { // this option is like -n but it prints non blank lines with number (--number-nonblank), instead of printing all lines with number like -n even if this line is empty or blank
                    option = '3';
                    choiced[2] = '3';

                }
                else if (cmpstr(argv[i], "-s\0") == 0 || cmpstr(argv[i], "--squeeze-blank\0") == 0)
                { // this option is jump empty lines or dont print repeated blank lines (--squeeze-blank)
                    option = '4';
                    choiced[3] = '4';

                }
                else if (cmpstr(argv[i], "-T\0") == 0 || cmpstr(argv[i], "--show-tabs\0") == 0)
                { // this option is tabs or show tabs, show tabs with ^I, --show-tabs
                    option = '5';
                    choiced[4] = '5';
                }

                else if (cmpstr(argv[i], "-v\0") == 0 || cmpstr(argv[i], "--show-nonprinting") == 0)
                {
                // this option is show non printable characters, shows non printing chars

                    option = '6';
                    choiced[5] = '6';
                }
                else if (cmpstr(argv[i], "-A\0") == 0 || cmpstr(argv[i], "--show-all\0") == 0)
                {
                    // option = -vET
                    choiced[5] = '6'; // -v
                    choiced[1] = '2'; // -E
                    choiced[4] = '5'; // -T
                }
                else if (cmpstr(argv[i], "-e\0") == 0)
                {
                    // option = -vE
                    choiced[5] = '6'; // -v
                    choiced[1] = '2'; // -E
                }
                else if (cmpstr(argv[i], "-t\0") == 0)
                {
                    // option = -vT
                    choiced[5] = '6'; // -v
                    choiced[4] = '5'; // -T
                }

             }
            
        } else { // if parameter(argv[i]) do not starts with - then it means that is not an option but yes a file or filename

            files[flen] = argv[i];
            flen++;
           
        }
    }


    for (i = 0; i < flen; i++){
// print every/each file data/content a time, if there's more than one file else the print only file data/content

        printfd(argv[0], files[i], choiced);

    }

    if (flen == 0)
    {
        printfd(argv[0], "-\0", choiced);
        
    }

    return 0;
}
