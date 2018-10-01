/*********************************************
Name:                Leonardo Ataide Dias
Email:               leonardo.ataide@gmail.com
Date:                23/09/2018
*********************************************/

// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
#ifndef TD_H_
#define TD_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

/*pause function*/
void ppause(void){ //Will wait until user press "Enter Key"
    
	char input = '\0'; 
	printf("Press <Enter> to continue...");
    scanf("%c", &input);
	
	   do{
		  
          input = getchar();
	
	   }while (input != '\n');
	
	system("clear");
}

/*Check input if it is a valid Integer*/
double checkValue(char* string) {

    int len = 0, i = 0, count = 0;
    double deposit = 0;

	len = strlen(string);

		for (i = 0; i < len ; i++) {

            if ((string[i] >= 48 && string[i] <= 57) || (string[i] == 46)) {

            	count ++;            				

            }
       	}

        if (len == count) {

        	deposit = atof(string);

        	return deposit;

        }else{

        	return 696969;
        }
}		

/* GETCH funcion inside <conio.h> is not included in GCC. This function acts like it*/
int getch(void)

{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

char* getPwd(void) {

	char *pass = malloc(11); //Need to use malloc to allocate string, because it is returning
    char ch;                 //a variable that immediately goes out of scope when the function
    int i = 0;               //returns.

	for (i = 0; i < 10; i++){// Printing '*' while user type password
      
      ch = getch();
      pass[i] = ch;

        if( pass[i] == 10 ){ //10 means Line Feed under ASCII TABLE, equivalent to <enter>

          pass[i] = '\0'; //To avoid garbage values inside string
          break;

        }else{

          printf("*");  

        }
    }

    return pass;
}

// (closing of the "safeguard" condition)
#endif