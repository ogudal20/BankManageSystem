#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILENAME "loginDetails.txt"
char buffer[255];

/* Create Account*/
typedef struct{
    char *firstname;
    char *lastname;
    char *address;
    char *password;
    int mobileNum;
    int dateOfBirth;
    int accountNum;
    int sortCode;
} userAccount;


/* Login Account */
typedef struct{
    char *userName;
    char *password;
} Login;


int mainMenu(void);
void login();
void createAccount(userAccount *userDetails);
void changeUserDets(userAccount *userDetails);
float deposit(int balance);
float withdraw(int balance);
void viewCustomerBankInfo(userAccount *account);
int editCustomerBankInfo(userAccount *customDetails);
int delCustomerBankInfo(userAccount *customDetails);


int main(void){
    
    int choice;

    printf("---Bᴀɴᴋ Mᴀɴᴀɢᴇᴍᴇɴᴛ Sʏsᴛᴇᴍ---\n");

    do{
        choice = mainMenu();
        FILE *fp;
        fp = fopen(FILENAME, "r");
        
        if(!fp){
            printf("Error opening file!");
            return -1;
        }
        
        /*
            fscanf(fp, "%s", username);
           // fgets(password, sizeof(buffer), fp);
            if(strcmp(username, myUsername) == 0){
                printf("Correct!\n");
                break;    
            }else{
                printf("Wrong!\n");
                continue;
            }

        }while(!feof(fp));
          
        */
        
        switch(choice){
            case 1:
                login();
                break;
            case 2:
           //     createAccount(userAccount *userDetails);
                break;
            default:
                exit(0);
                break;
        }
        

    }while(choice != 3);
        
    return 0;
}

int mainMenu(){

    char userChoice[10];

    printf("1 - Login\n");
    printf("2 - Create Account\n");
    printf("3 - Exit\n");
    printf("Enter a option\n");

    fgets(userChoice, 10,  stdin);
    int choice = atoi(userChoice);

    if(choice == 1){ return choice; }
    else if(choice == 2){ return choice;}
    else{ choice;}

}
 
//Get the login details and store in a file.
void login(){


    FILE *loginDetails;
    char userNameFile[100];
    char passwordFile[100];

    loginDetails = fopen("loginDetails.txt", "r");

    Login *loginAccount = malloc(sizeof(*loginAccount));
    loginAccount->userName = malloc(sizeof(*loginAccount->userName));
    loginAccount->password = malloc(sizeof(*loginAccount->password));

    printf("Enter in UserName: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", loginAccount->userName);

    printf("Enter in PassWord: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", loginAccount->password);
    
    //Check to see if the credntials are correct.
    while(!feof(loginDetails)){
        fscanf(loginDetails, "%s %s",userNameFile, passwordFile);
        if((strcmp(userNameFile, loginAccount->userName)) == 0 && (strcmp(passwordFile, loginAccount->password)) == 0){
            printf("Thanks For Banking with Us!\n");
            break;
        }

    }

    free(loginAccount);
    free(loginAccount->userName);
    free(loginAccount->password);

    return;
}





