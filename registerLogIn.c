#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char surName[50];
    char mail[50];
    int password;
}people;
// To create person like educator or student

enum{
    Teacher = 1, Student = 2
};
// Facilitate to where is teacher or student indentation

people teachers[20];
people students[20];
// Created array to save teachers and students
// Attention: This arrays created for if someone use this code to save more than one teacher or student.

int i,j = 0, loop = 1;
// This variables defined here because of using in functions.

// Fallowing function using for register people.
void registerr(int flag){
    switch (flag) {
        case 1:
            for (i = 0; i < 20; i++) {
                if (strcmp(teachers[i].name, "") == 0) {
                    puts("Educator Name: ");
                    scanf("%s",teachers[i].name);
                    puts("Educator Surname: ");
                    scanf("%s",teachers[i].surName);
                    puts("Educator Mail: ");
                    scanf("%s",teachers[i].mail);
                    puts("Password: ");
                    scanf("%d", &teachers[i].password);
                    break;
                }

            }
            break;
        case 2:
            for (i = 0; i < 20; i++) {
                if (strcmp(students[i].name, "") == 0) {
                    puts("Student Name: ");
                    scanf("%s",students[i].name);
                    puts("Student Surname: ");
                    scanf("%s",students[i].surName);
                    puts("Student Mail: ");
                    scanf("%s",students[i].mail);
                    puts("Password: ");
                    scanf("%d", &students[i].password);
                    break;
                }

            }
            break;
            
        default:
            printf("Invalid choice");
            break;
    }

}


// Fallowing funciton using for control log in information given from user.
int logIn(char *mail, int password, int stdEdu){
    int retur = 0;
    if (stdEdu == 1) {
        if (strcmp(mail, teachers[i].mail) == 0 && teachers[i].password == password) {
            retur = 1;
        }
        else{
            retur = 0;
        }
    }
    else if (stdEdu == 2){
        if (strcmp(mail, students[i].mail) == 0 && students[i].password == password) {
            retur = 1;
        }
        else{
            retur = 0;
        }
    }
    return retur;
}

// Fallowing function takes mail and return extension of it.
char* arrangeMail(char mail[]){
    char *p;
    p = strtok(mail, " @");
    p = strtok(NULL, " @");
    return p;
}
// teacher mail => ...@teacher.edu.tr
// student mail => ...@student.edu.tr



char mailExten[30];
char mail[30];
int password;
char controlEdu[] = "teacher.edu.tr";
char controlStd[] = "student.edu.tr";
/*
 mailExten: For keep extension of mail to control
 controEdu and control Std: For keep extensions of teacher and student mails.
*/

int main(){
    puts("Mail: ");
    scanf("%s", mail);
    strcpy(mailExten, arrangeMail(mail));
    if (strcmp(mailExten, controlEdu) == 0) {
        printf("Welcome Educator. First you must register.\n");
        registerr(Teacher);
        printf("\nRegistiration is succeeded\nNow you can log in.");
        while (loop == 1) {
            puts("\nMail: ");
            scanf("%s",mail);
            puts("Password: ");
            scanf("%d", &password);
            if(logIn(mail, password, Teacher)==1){
                printf("Log in successful\n");
                loop = 0;
            }
            else{
                printf("Wrong information.");
            }
        }

    }

    else if (strcmp(mailExten, controlStd) == 0){
        printf("Welcome Student. First you must register.\n");
        registerr(Student);
        printf("\nRegistiration is succeeded\nNow you can log in.");
        while (loop == 1) {
            puts("\nMail: ");
            scanf("%s",mail);
            puts("Password: ");
            scanf("%d", &password);
            if(logIn(mail, password, Student)==1){
                printf("Log in successful\n");
                loop = 0;
            }
            else{
                printf("Wrong information.");
            }
        }

        }

}
