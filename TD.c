/*********************************************
Name:                Leonardo Ataide Dias
Email:               leonardo.ataide@gmail.com
Date:                23/09/2018
*********************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "TD.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ####### Main Program  ########

int main(void) {

   time_t now; //Arithmetic time type
   time(&now); //Will return the current time od the system
   char answer = '\0';
   char name[40], user_input[10], password[11];
   int option = 0;
   double chequing = 250.00, saving = 0,avbl_withdraw = 0, overlimit = 0;                   

   system("clear");
   printf("\n\n");
   printf("Please, enter your first name: ");
   scanf("%s", name);
   getchar();
   printf("%s, now choose a PIN number (at least 4 digits): ", name);
   char *pwd = getPwd();
   strcpy(password, pwd);
   free(pwd);

   printf("\n\n");
   printf("Congratulations %s, as a new valued costumer, you got:\n", name);
   printf("\n\t\t * CAD$250.00 in your chequing account.\n");
   printf("\t\t * A Credit limit of CAD$1000.00\n");
   printf("\t\t * A free Saving account.\n");
   printf("\n");
   ppause();
   
   
   	do {
      
    	// Print the option list
    	printf("---==========================---\n");
  		printf("---    ======== ======       ---\n");
   		printf("---       ==    ==    =      ---\n");
   		printf("---       ==    ==    =      ---\n");
   		printf("---       ==    ==    =      ---\n");
   		printf("---       ==    ==    =      ---\n");
   		printf("---       ==    ======       ---\n");
   		printf("---==========================---\n");
   		printf("    %s\n", ctime(&now));
   		printf("\n");        
    	printf("Please, type the corresponding number:\n");
    	printf("\n");
    	printf("CHEQUING ACCOUNT ------------------------\n");
   	  	printf("1. Display Chequing Account balance\n");
      	printf("2. Deposit Money\n");
      	printf("3. Withdrawal Money\n");
      	printf("\n");
      	printf("SAVING ACCOUNT --------------------------\n");
      	printf("4. Display Saving Account balance\n");
      	printf("5. Deposit Money\n");
      	printf("6. Withdrawal Money\n");
      	printf("0. Exit\n");      	
           
      	// Capture input to option variable
      	scanf("%d",&option);
      	printf("\n");
      
        switch (option) {

        	case 0:  // Exit the program
         
        	break;

        	case 1: // Display Current Balance
          
            	printf("CURRENT CHEQUING BALANCE\n");
            	printf("========================\n");
            
            		if(chequing > 0 ){ //if the id value is positive, print it

                		printf("CAD$: +%.2lf\n", chequing);

                	
                }else{

               		 printf("CAD$: %.2lf\n", chequing);
               	}

               	printf("========================\n");
            	printf("\n");
            	ppause();

            break;

        	case 2: //Deposit Money
        		            
            	printf("DEPOSIT\n");
            	printf("========================\n");
              printf("Please, enter the amount (or type 0 to cancel): ");
            	scanf("%s", user_input);

            	 if (checkValue(user_input) == 696969) {            	
            			
            	   printf("ERROR! Please, type only numbers to make a deposit\n");
            	   printf("========================\n");
           		   printf("\n");
           		   ppause();
           		   break;            	
                }

                else if (checkValue(user_input) == 0) { 
           			         			
           			  printf("CANCELED! Returning to main menu.\n");
           			  printf("========================\n");
				      	 printf("\n");
                  ppause();
           			break;           		
                }
                else {

                  chequing += checkValue(user_input);

                }         	
            	
            	printf("SUCCESS! Your new balance is ");
            	
            		if(chequing > 0 ){ //if the id value is positive, print it

                		printf("CAD$ +%.2lf\n", chequing);

                	}else if(chequing == 0){

                		printf("CAD$ %.0lf\n", chequing);
                
                	}else{

               			printf("CAD$ %.2lf\n", chequing);
               		}

            	printf("========================\n");
            	printf("\n");
            	ppause(); 

            	printf("\n");
            
            break;

        	case 3: //Withdrawal Money

        		if (chequing == -1000){

        			printf("================================================\n");        	
            		printf("We're sorry. You have reached your credit limit.\n");
            		printf("================================================\n");
           			printf("\n");
           			ppause();
           			break;
            	} 

            	printf("WITHDRAWAL\n");
            	printf("=======================\n");
            	printf("Please, enter the amount (or type 0 to cancel): ");
            	scanf("%s", user_input);

              if (checkValue(user_input) == 696969) {             
                  
                 printf("ERROR! Please, type only numbers to make an withdrawal\n");
                 printf("=======================\n");
                 printf("\n");
                 ppause();
                 break;             
              }

            	else if (checkValue(user_input) == 0) {
            			          			
            			printf("CANCELED! Returning to main menu.\n");
            			printf("=======================\n");
						      printf("\n");						
						      ppause();
            			break;
            	}   

              else

            	  chequing -= checkValue(user_input); 

               		if(chequing < -1000){ //If the value goes under the limit

               			overlimit = chequing + 1000;

               			avbl_withdraw = checkValue(user_input) + overlimit;   

               			chequing += checkValue(user_input);           			
               			
               			printf("=======================\n");              	
               			printf("Transaction declined!\n");
               			printf("Chequing account limit has exceeded in CAD$: %.2lf\n", overlimit);
               			printf("Would you like to Withdraw CAD$: %.2lf, current available?\n", avbl_withdraw);
                    printf("(Y)es or (N)o? ");
               			getchar();
               			scanf("%c", &answer);
               			
               				if(answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N'){
               						
               					printf("Please answer using only (Y)es or (N)o? ");
               					getchar();
               					scanf("%c", &answer);
               						
               						if(answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N'){
               							printf("Do you still there? Answer using only (Y)es or (N)o? ");
               							getchar();
               							scanf("%c", &answer);
               						               						             					
               							if(answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N'){
               								printf("\n");
               								printf("ERROR! (3 wrong answers) Returning to main menu\n");
               								printf("========================\n");
               								printf("\n");
               								ppause();
               								break;
               							}
               						}	

                        getchar();
                        printf("Please enter your PIN: ");
                        char *pwd = getPwd();
                        
                          if(strcmp(pwd, password) == 0) {
                          
                            free(pwd);
                            printf("\n\nSuccess. CAD$: %.2lf was withdrawn from your account.\n", avbl_withdraw);
                            printf("\n"); 

                            chequing -= avbl_withdraw;                                                        
                          
                            ppause();
                            break;
               				    
                          }else{

                              printf("\n");
                              printf("ERROR! Wrong PIN. Returning to main menu\n");
                              printf("========================\n");
                              printf("\n");
                              ppause();
                              break;

                          }

                          
                      }

               			if(answer == 'n' || answer == 'N'){

               			printf("CANCELED! Returning to main menu.\n");
            				printf("========================\n");
							      printf("\n");						
							      ppause();
            				break;

               			}
               					
               			if(answer == 'y' || answer == 'Y'){	
               				
                      getchar();
               				printf("Please enter your PIN: ");
                      char *pwd = getPwd();
               					
                        if(strcmp(pwd, password) == 0) {
               						
                          free(pwd);
               						printf("\n\nSuccess. CAD$: %.2lf was withdrawn from your account.\n", checkValue(user_input));
                          printf("=======================\n");
               						printf("\n"); 

               						chequing -= avbl_withdraw;              							              							
               						
               						ppause();
               						break;
              						
             					}else{

                          free(pwd);
               						printf("ERROR! Wrong PIN.\n");
               						printf("Please try it again:");
               						char *pwd = getPwd();
               						
               							if(strcmp(pwd, password) != 0) {
               								
                              free(pwd);
               								printf("\n");
               								printf("ERROR! Wrong PIN.\n");
               								printf("You have 1 more attempt. Try again: ");
               								char *pwd = getPwd();               								        						
               					
		          								if(strcmp(pwd, password) != 0) {

                                  free(pwd);
                                	printf("\n");
               										printf("ERROR! (3 wrong answers) Returning to main menu\n");
               										printf("========================\n");
               										printf("\n");
               										ppause();
               										break;
               									}	
               							}
               					}

           					chequing -= avbl_withdraw;
           				}

              		}               		
        
        getchar();                                   
        printf("Please enter your PIN: ");
        char *pwd = getPwd();

					if(strcmp(pwd, password) == 0) {
             					
    					free(pwd);
              printf("\n\nSuccess. CAD$: %.2lf was withdrawn from your account.\n", checkValue(user_input));
              printf("=======================\n");
        			printf("\n");                  				
        			ppause();
               						
        			}else{

                free(pwd);
                printf("\n");
        				printf("ERROR! Wrong PIN.\n");
        				printf("Please try it again:");
               	char *pwd = getPwd();
               						
               				if(strcmp(pwd, password) != 0) {

               					free(pwd);			
               					printf("\n\n");
               					printf("ERROR! Wrong PIN.\n");
               					printf("You have 1 more attempt. Try again: ");
               					char *pwd = getPwd();             								        						
               					
		        					    if(strcmp(pwd, password) != 0) {

               					    free(pwd);				
               							printf("\n");
               							printf("==================================================\n");
               							printf("You are returning to main menu. (3 wrong attempts)\n");
               							printf("\n");
               							ppause();

               							chequing += checkValue(user_input);
               							break;
               						}	

               					chequing -= checkValue(user_input);               					
               				}

               			printf("\n\nSuccess. CAD$: %.2lf was withdrawn from your account.\n", checkValue(user_input));
                    printf("\n");
                    ppause();


               		}     

   			               		
            printf("\n");               			
        		break;

        	case 4: //Saving's Balance
                     
            	printf("CURRENT SAVING BALANCE\n");
            	printf("========================\n");
            
            		if(saving > 0 ){ //if the id value is positive, print it

                		printf("CAD$: +%.2lf\n", saving);

                }else{

               			printf("CAD$: %.2lf\n", saving);
               	}

              printf("========================\n");
            	printf("\n");
            	ppause();

            break;

        	case 5:  // Adding Money
            
            	printf("DEPOSIT\n");
            	printf("========================\n");
              printf("Please, enter the amount (or type 0 to cancel): ");
            	scanf("%s", user_input);
            	            	            	
            		if (checkValue(user_input) == 696969) {              
                  
                  printf("ERROR! Please, type only numbers to make a deposit\n");
                  printf("========================\n");
                  printf("\n");
                  ppause();
                  break;
                
                }else if (checkValue(user_input) == 0) { 
                              
                  printf("CANCELED! Returning to main menu.\n");
                  printf("========================\n");
                  printf("\n");
                  ppause();
                  break;
                
            	  }else{

                  saving += checkValue(user_input);
                }
            	            	
            	printf("SUCCESS! Your new balance is ");
            	
            		if(saving > 0 ){ //if the id value is positive, print it

                		printf("CAD$ +%.2lf\n", saving);

                	}else{

                		printf("CAD$ %.0lf\n", saving);
                                
                	}

            	printf("========================\n");
            	printf("\n");
            	ppause(); 

            	printf("\n");
            
            break;


        	case 6: //Withdraw Money

        		if (saving == 0){

        			   	printf("==========================================================\n");
            			printf("We're sorry. You do not have enough funds to be withdrawn.\n");
            			printf("==========================================================\n");
            			printf("\n");
            			ppause();
            			break;
            } 

            printf("WITHDRAWAL\n");
            printf("========================\n");            	
            printf("Please, enter the amount (or type 0 to cancel): ");
            scanf("%s", user_input);  

            	if (checkValue(user_input) == 696969) {              
                  
                  printf("ERROR! Please, type only numbers to make an withdrawal\n");
                  printf("========================\n");
                  printf("\n");
                  ppause();
                  break;
                
                }else if (checkValue(user_input) == 0) { 
                              
                  printf("CANCELED! Returning to main menu.\n");
                  printf("========================\n");
                  printf("\n");
                  ppause();
                  break;
                
                }else{

                  saving -= checkValue(user_input);
               
               		if(saving < 0){ 

               			saving += checkValue(user_input);
               		            	
						        printf("========================\n");                		            	
               			printf("Not enough funds. Your current balance is CAD$: %.2lf\n", saving);
               			printf("Would you like to try again? (Y)es or (N)o? ");
               			getchar();
               			scanf("%c", &answer);
               			

               				if(answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N'){
               						
               						printf("Please answer using only (Y)es or (N)o ?");
               						getchar();
               						scanf("%c", &answer);
               						
               					if(answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N'){
               						printf("Do you still there? Answer using only (Y)es or (N)o? ");
               						getchar();
               						scanf("%c", &answer);
               						
               					
               						if(answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N'){               							
               							printf("ERROR! (3 wrong answers) Returning to main menu\n");
               							printf("========================\n");
               							printf("\n");
               							ppause();
               							break;
               						}	
               					}
               				}
               		}
                

               		if(answer == 'n' || answer == 'N'){

               		printf("CANCELED! Returning to main menu.\n");
            			printf("========================\n");
					       	printf("\n");						
						      ppause();            			
               		break;

               		}
               			
               		if(answer == 'y' || answer == 'Y'){

               			printf("Please re-enter the amount to be withdrawn: ");
            			  scanf("%s", user_input);            			

            			  saving -= checkValue(user_input); 

               				if(saving < 0){ //

               					saving += checkValue(user_input);

               					printf("Not enough funds. Returning to main screen\n");
               					printf("========================\n");
               					printf("\n");
               					ppause();
               					break;

              				}
              		}        
                }

              	getchar();
                printf("Please enter your PIN: ");
				        char *pwd1 = getPwd();
				        printf("\n");

					if(strcmp(pwd1, password) == 0) {
               							
    					free(pwd1);
              printf("Success. CAD$: %.2lf was withdrawn from your account.\n", checkValue(user_input));
        			printf("\n");        				
        			ppause();
               						
        			}else{

        				printf("ERROR! Wrong PIN.\n");
        				printf("Please try it again:");
               			char *pwd = getPwd();
               						
               				if(strcmp(pwd, password) != 0) {
               					
                        free(pwd);
               					printf("\n");
               					printf("ERROR! Wrong PIN.\n");
               					printf("You have 1 more attempt. Try again: ");
               					char *pwd = getPwd();              								        						
               					
		        					   if(strcmp(pwd, password) != 0) {

                            free(pwd);
               							printf("\nERROR! (3 wrong answers) Returning to main menu\n");
               							printf("========================\n");
               							printf("\n");
               							ppause();
               							
               							saving += checkValue(user_input);
               							break;
               						}	

               					
               				}

                free(pwd);
               	printf("\n\nSuccess. CAD$: %.2lf was withdrawn from your account.\n", checkValue(user_input));
                printf("========================\n");
                printf("\n");
        				ppause();


               		}             	
   			               		
            	printf("\n");               			
        		
        	break;
        }                      

   	}while (option != 0);

    printf("=================================\n");
    printf("You have successfully logged out.\n");
    printf("\n");
    printf("Access: www.td.com\n");
    printf("\nOpening doors for an inclusive tomorrow\n");
    printf("\n");
    printf("THE\n");
    printf("READY\n");
    printf("COMMITMENT\n");
    printf("\n");

   return 0; 
}