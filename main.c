#include<stdio.h>
#include<stdlib.h>
#include"./headers/menus.h"

/*
    FINAL PROJECT OF PROGRAMMING FUNDAMENTAL 
    PROJECT NAME : PLAN MY TRIP 
    <------------------------------------------------------>
    PROJECT MEMBER : 
        1) MUHAMMAD ABAS      23P-0046
        2) MUSKAN NASIR       23P-0011
        3) HAMID KHAN         23P-0044
    >------------------------------------------------------<

    PURPOSE OF CODE 
        --->       The purpose of our code is to facilitate customers in making
                      online trip reservations and generating receipts. 
                   Through our system,customers can select their desired destination,
                     transportation options, and accommodations according to available prices.
*/

////////////////////////////////////////////////MAIN///////////////////////////////////////////////////
int main(void) 
{
    int ch;
    int cho;
    int option;
  //  char input[100];
    int num;
    int i=0;
    int count=0;
    float totalCharges = 0;

    // Input is a valid integer


    //
    do 
    {
        i=0;
        char input[1];
        while(1) 
        {
            printf("-----------------------------------------------------------------------------------\n");
            printf("Enter Your Choice\n [1].Admin Access\n [2].User Access\n [3].Exit\n");
            scanf(" %s",input);
            int j=0;
            for(;j<1;j++)
            {
                if(input[j]=='\0')
                
                    break;
            }
            if(j>1)
            {
                printf("wrong input\n");
                continue;
            }
            else 
                break;
       
        }
        if(input[0] == '1') 
        {
            // There is Nothing In admin Access so we add this Feature  for Future Use 
            int adminpass = 4321;
            int n;
            printf("Enter admin password:");
            scanf("%d", &n);

            if (n == adminpass)
             {
                printf("All details are:\n");
            } else 
            {
                printf("Invalid password ");
            }
            printf("Admin access\n");
        } else if(input[0] == '2')
         {
            printf("--------------------------------------------------------------------------------\n");
            welcome();
            printf("************\n");
            printf("User Access\n");
            printf("************\n");
            printf("Enter you Info \n\n");

            char name[100];
            printf("Enter your Name \n");
            fflush(stdin); // ffflush function is typically used to flush (or clear) the output
            gets(name); // which can also print space with Name  for that purpose whihc print all name of user 
          
            FILE *fptr;
            fptr = fopen("Receipt.txt","w");
            fprintf(fptr,"\n<------------------------------------------------------------------------>\n");
            fprintf(fptr,"Name : %s \n",name);
            fclose(fptr);

            char address[100];
            printf("Enter your Address \n");
            fflush(stdin);
            gets(address);
            fptr = fopen("Receipt.txt","a");
            fprintf(fptr,"Address : %s \n",address);
            fclose(fptr);

            char cnic[14]; 
            while (1)
             {
                count=0;
                printf("Enter the CNIC: ");
                scanf(" %s",cnic);

                for(int i=0;i<13;i++)
                 {
                    if(cnic[i]!='\0') 
                    {
                        ++count;
                    }
                }

                if (count == 13) 
                {
                    fptr = fopen("Receipt.txt","a");
                    fprintf(fptr,"Cnic : %s \n",cnic);
                    fclose(fptr);
                    break;
                } else
                 {
                    printf("Invalid CNIC number. Please enter a 13-digit CNIC.\n");
                    continue;
                }
            }

            plain_my_trip();
             char input[100];
        while(1) 
        {
            printf("-----------------------------------------------------------------------------------\n");
             printf("Choose Your Destination \n");
            
            printf("Enter Your Choice \n");
          
          printf(" [1]. Swat \n [2]. Kashmir\n [3]. Muree\n [4]. Chitral\n [5]. Sakardu \n");
            scanf(" %s",input);
            int j=0;
            for(;j<3;j++)
            {
                if(input[j]=='\0')
                    break;
            
            }
            if(j>1)
            {
                printf("wrong input\n");
                
                continue;
                
            }
            else 
             {
                if(input[0]=='1'||input[0]=='2'||input[0]=='3'||input[0]=='4'||input[0]=='5')
                         break;
             }
        }
        
            if(input[0] == '1') 
            {

                fptr=fopen("Receipt.txt","a");
                fprintf(fptr,"Your Destination : Swat \n");
                fclose(fptr);
                swat_pattern();
                transport();       
                tour_guide();
                hotel_pattern();
                swatcity();
            } else if(input[0] == '2') 
            {
                kashmir_pattern();
                transport();
                tour_guide();
                kashmir();
            } else if(input[0] == '3')
            {
                muree_pattern();
                transport();
                tour_guide(); 
                
                muree();
            } else if(input[0] == '4')
            {
                chitral_pattern();
                transport();
                tour_guide();
                chitralCity();
            } else if(input[0] == '5')
            {
                skardu_pattern();
                transport();
                tour_guide();
                skardu();
            }

            printfromfile();
        }
         else if(input[0] == '3')
         {
            printf("Exit\n");
            break;
        } else {
            printf("\nInvalid choice, Enter the given number only\n");
        }
    } while(1);

    return 0;
}
