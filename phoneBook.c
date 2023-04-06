#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char phoneBook[20][3][50], inputString[50], empty[50];
// array layout: name/surname/phone_number
int i, loop= 1, nmContact;


// Function definition: Add contact in  a char array to store informations.
void addContact ( int contacts){
    fgets(empty, 50, stdin);
//  Program skipping first fgets() funciton to take name. So I find a solution by add extra fgets() function to take empty char.
    for (i = 0; i < contacts; i++) {
        printf("\n%d. Name: ", i+1);
        fgets(phoneBook[i][0], 50, stdin);
        printf("\n%d. Surname: ", i+1);
        fgets(phoneBook[i][1], 50, stdin);
        printf("\n%d. Phone Number: ", i+1);
        fgets(phoneBook[i][2], 50, stdin);
        nmContact++;
    }
}

// Function definition: Delete contact from phoneBook array.
void deleteContact(char paramether[50]){
    for (i = 0; i < 20; i++) {
        if (strcmp(paramether, phoneBook[i][0]) == 0) {
            *phoneBook[i][0] = '\0';
            *phoneBook[i][1] = '\0';
            *phoneBook[i][2] = '\0';
            printf("\nContact Deleted.\n");
            nmContact--;
            break;
        }
        else if (strcmp(paramether, phoneBook[i][1]) == 0) {
            *phoneBook[i][0] = '\0';
            *phoneBook[i][1] = '\0';
            *phoneBook[i][2] = '\0';
            printf("\nContact Deleted.\n");
            nmContact--;
            break;
        }
        else if (strcmp(paramether, phoneBook[i][2]) == 0){
            *phoneBook[i][0] = '\0';
            *phoneBook[i][1] = '\0';
            *phoneBook[i][2] = '\0';
            printf("\nContact Deleted.\n");
            nmContact--;
            break;
        }
        
    }
}

// Function definition: Search a contact in phoneBook. 
void searchContact(char paramether[50]){
    for (i = 0 ; i < 20; i++) {
        if (strcmp(paramether, phoneBook[i][0]) == 0) {
            printf("\nSearched Contact ==>>\n");
            printf("\nName: %s\nSurnam: %s\nPhone Number: %s",phoneBook[i][0],phoneBook[i][1],phoneBook[i][2]);
            break;
        }
        else if (strcmp(paramether, phoneBook[i][1]) == 0) {
            printf("\nSearched Contact ==>>\n");
            printf("\nName: %s\nSurnam: %s\nPhone Number: %s",phoneBook[i][0],phoneBook[i][1],phoneBook[i][2]);
            break;
        }
        else if (strcmp(paramether, phoneBook[i][2]) == 0){
            printf("\nSearched Contact ==>>\n");
            printf("\nName: %s\nSurnam: %s\nPhone Number: %s",phoneBook[i][0],phoneBook[i][1],phoneBook[i][2]);
            break;
        }
        else{
            
        }
    }
}



int main(){
    while (loop == 1) {
        printf("\nAdd Contact    => 1\nDelete Contac  => 2\nSearch Contact => 3\nShow Contacts  => 4\nExit => 0");
        printf("\nId of Command: ");
        scanf("%d", &k);
        switch (k) {
                
                
            case 0:
                printf("Exiting...\n");
                loop = 0;
                break;
            case 1:
                printf("\nNumber of Cantac(s) to Add: ");
                scanf("%d", &k);
                addContact(k);
                printf("\nContacs added.\n");
                break;
                
                
            case 2:
                fgets(empty, 50, stdin);
                printf("\nATTENTION: If contacts in phonebook you will take feedback when contact be deleted.");
                printf("\n\nName/Surname or Phone Number: ");
                fgets(inputString, 50, stdin);
                deleteContact(inputString);
                break;
                
                
            case 3:
                fgets(empty, 50, stdin);
                printf("Enter name, surname or phone number (10 digits, not start with 0 ): ");
                fgets(inputString, 50, stdin);
                searchContact(inputString);
                break;
                
                
                
            case 4:
                
                printf("\nCONTACTS\n\n");
                for (i = 0; i < nmContact; i++) {
                    printf("Name: %s\nSurname: %s\nPhone Number: %s\n",phoneBook[i][0],phoneBook[i][1],phoneBook[i][2]);
                }
                break;
                
                
                
            default:
                printf("Invalid Cammand!!!");
                break;
        }
    }
    
    
    
    
}
