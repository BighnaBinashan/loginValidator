#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ESC 27;
#define F1 59;
#define F2 60;

// Defining the structure
struct credential
{
    /* data */
    char username[25];
    char password[25];
} s ;

FILE *fp;
void signup(void);
// void login(void);
int login();
void main()
{
    int response;

    while (1)
    {
        printf("\n----------Welcome to My world----------\n");

        printf("\nPress 1 to login ");
        printf("\nPress 2 to signup");
        printf("\nPress 0 to exit\n");

        scanf("%d",&response);

        switch (response)
        {
            case 1:

                for (int i = 0; i < 40; i++)
                {
                    printf("_");
                }
                login();
                break;
            case 2:

                for (int i = 0; i < 40; i++)
                {
                    printf("_");
                }
                signup();
                break;

            case 0:
                exit(0);
        }
    }
    getchar();
}

// -------Login Function--------
int login()
{
    int c, i;
    char username[25];
    char password[25];
    // char checkPassword[25] = "Bigna2019@";
    char checkPassword;
    char checkUsername;
    printf("\n-----------Login page----------\n");
    fp = fopen("data.bin","rb");
    printf("\nUsername: ");
    scanf("%s",&username);

    printf("\nPassword: ");
    scanf("%s",&password);
    
    // int result;
    // if (strcmp(password, checkPassword) == 0)
    // {
    //     result = 1;
    //     // printf("\nlogin Sucessfull\n");
    // }
    // else
    //     {
    //         result = 0;
    //         // printf("\nLogin Failed\n");
    //     }    

    

    // return result; 
        while (!feof(fp))

    {
        fread(&s, sizeof(s), 1, fp);

        checkUsername = strcmp(username, s.username);

        checkPassword = strcmp(password, s.password);

        if (checkUsername == 0 && checkPassword != 0)

        {

            printf("Invalid password!!!!!!!!!!!!");
            break;
        }

        else if (checkUsername != 0 && checkPassword == 0)
        {
            printf("\n\tInvalid Username!!!!!!!!");

            break;
        }

        else if (checkUsername == 0 && checkPassword == 0)

        {

            printf("-------Hello %s Welcome To my World-------", s.username);

            break;
        }
    }   
}

// -------signup function--------
void signup()
{
    char c;

    fp = fopen("data.bin","wb");
    printf("\n----------Fill Up the credential to signup----------");
    printf("\nSet username: ");
    scanf("%s",s.username);
    printf("Set password: ");
    scanf("%s",s.password);

    fwrite(&s, sizeof(s),1, fp);
    printf("\nInformation Saved....");
}