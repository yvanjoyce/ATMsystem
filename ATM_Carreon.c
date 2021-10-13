/// CODE BY YVAN D' GREAT

/**
pa-edit na lang po ng file directory na meron sa usb niyo po, -> f:\\
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

/**
2 modules
- enrollment
    acct name
    acct id
    pin
    bal
- transaction
        withdraw
        deposit
        bal inquiry
        change pin
*/
int i, accID[5], n;
char lnth[200],name[200],pin[6], enteredPin[6], retPin[7], retBal[13],bal[6];
#define MAX 100000
#define limit 10000


FILE*fp;
FILE*fBal;
FILE*fpin;
FILE*newBal;
void enterAmount();
void withdraw();
void deposit();
void balInq();
void changePin();
void retrievePin();
void genAccID();
void transactionOpt();
void gotoxy(int x, int y);
void transaction();
void insertCard();
void enrollment();
void enterPin();
void design();
void transacttion();
void scn();
void addmoney();
int main(){
    design();

   gotoxy(27,15);
    printf("WELCOME TO THE PHILIPPINE NATIONAL BANK MF\n");
    gotoxy(20,17);
    printf("> > press any key to proceed with your transaction < <");
    getch();
    system("cls");
    insertCard();
}
void design(){

 printf("\n    //==---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---==\\\\ \n");
 printf("    ||  +=============================================================================+  ||\n");


printf("    ||  |\t\t         _     _________  ____    ____ \t\t              |  ||\n");
printf("    ||  |\t\t        / \\   |  _   _  ||_   \\  /   _|\t\t\t      |  ||\n");
printf("    ||  |\t\t       / _ \\  |_/ | | \\_|  |   \\/   |  \t\t\t      |  ||\n");
printf("    ||  |\t\t      / ___ \\     | |      | |\\  /| |  \t\t\t      |  ||\n");
printf("    ||  |\t\t    _/ /   \\ \\_  _| |_    _| |_\\/_| |_ \t\t\t      |  ||\n");
printf("    ||  |\t\t   |____| |____||_____|  |_____||_____|\t\t\t      |  ||\n");
printf("    ||  |.............................................................................|  ||\n");

    for(i = 0; i<20; i++){
        printf("    ||  |          \t\t\t\t\t\t\t\t      |  ||\n");
    }

  printf("    ||  +=============================================================================+  ||\n");
  printf("    \\\\==---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---=---==// \n");

}

insertCard(){
    design();
    gotoxy(35,17);
    printf("(insert your card...)");


    do{
        fp = fopen("f:\\mine\\samplee.txt","a+");
       }
       while(fp == NULL);
       scn();
        fclose(fp);
}

scn(){
    char bubu[22];
  if(fgets(lnth,200,fp)!= NULL){
      enterPin();
     //retrieved();
    }
    else{
       enrollment();
    }
}
void retrievePin(){

    system("cls");
    design();
    fpin = fopen("f:\\mine\\pincode.txt","r");
    fgets(retPin, 7,fpin);

}
void enterPin(){
    retrievePin();
    gotoxy(35,15);
    printf("Enter your 6-digit pin:");
    gotoxy(40,17);
    printf("_ _ _ _ _ _");
        for(i=0; i<6; i++){
        enteredPin[i]=getch();
        gotoxy(40+i+i,17);
        printf("*");
            }
            enteredPin[i] = '\0';

    int result = strcmp(enteredPin, retPin);
    if(result == 0){
        system("cls");
        transaction();
    }
    else{
        gotoxy(32,19);
        printf("WRONG PIN, PLEASE TRY AGAIN!");
        getch();
        system("cls");
        design();
        enterPin();
            }
}

withdraw(){

    design();

    fBal = fopen("f:\\mine\\balance.txt","r");
    fgets(retBal,13, fBal);

    /// pasali
  ///  printf("YOUR CURRENT BALANCE IS >>> %s.00 PHP",retBal);
    ///

  fseek(fBal, 0, SEEK_END);
    unsigned long lens = (unsigned long)ftell(fBal);
    if (lens > 0) {  //check if the file is empty or not.
        rewind(fBal);
        while ( !feof( fBal ) ){
           gotoxy(27,15);
            printf("YOUR CURRENT BALANCE IS >>> %s.00 PHP",retBal);

            gotoxy(23,17);
            printf("Enter the amount you need to withdraw: _ _ _ _ _");
            enterAmount();
            return 0;
        }
    }
         gotoxy(35,15);
        printf("YOU HAVE ZERO BALANCE.");
        getch();
        fclose(fBal);
        system("cls");
        transaction();
}

deposit(){
    design();
    gotoxy(33,15);
    printf("ENTER THE AMOUNT TO DEPOSIT");
    gotoxy(39,18);
    printf(">> _ _ _ _ _ _");


    addmoney();

}


addmoney(){
    int amnta,balanceea, remBala;
    char vva[20],cc[55];
    char numza[5];

    fBal = fopen("f:\\mine\\balance.txt","r");
    fgets(vva,50,fBal);
    balanceea = atoi(&vva);

    for(i=0; i<6; i++){
        gotoxy(42+i+i,18);
        numza[i] = getch();
        printf("%c", numza[i]);
        }
    amnta = atoi(&numza);

    remBala= balanceea+amnta;

    fBal = fopen("f:\\mine\\balance.txt","w");
    fprintf(fBal,"%d",remBala);

    gotoxy(38,20);
    printf("TRANSACTION DONE!");
    gotoxy(30,22);
    printf("YOUR BALANCE IS >> PhP %d.00", remBala);
    fclose(fBal);
    getch();
    system("cls");
    transaction();

}

enterAmount(){
    int amnt,balancee, remBal;
    char vv[20],cc[55];
    char numz[5];

    fBal = fopen("f:\\mine\\balance.txt","r");
    fgets(vv,50,fBal);
    balancee = atoi(&vv);

    for(i=0; i<5; i++){
        gotoxy(62+i+i,17);
        numz[i] = getch();
        printf("%c", numz[i]);
        }
    amnt = atoi(&numz);

    remBal= balancee-amnt;
    if(remBal == 0){
        fBal = fopen("f:\\mine\\balance.txt","w");
    }
    else{
        fBal = fopen("f:\\mine\\balance.txt","w");
        fprintf(fBal,"%d",remBal);
    }

    gotoxy(35,20);
    printf("TRANSACTION DONE!");
    gotoxy(26,22);
    printf("your remaining balance is: Php %d.00", remBal);
    fclose(fBal);

    getch();
    system("cls");
    transaction();
   }
balInq(){
    design();
    char info[100];
    char balin[10];
    fp = fopen("f:\\mine\\samplee.txt", "r");
    fgets(info,100,fp);
    gotoxy(18,15);
    puts(info);

    fBal = fopen("f:\\mine\\balance.txt", "r");
    fgets(balin, 10, fBal);
    gotoxy(35,20);
    printf("your remaining balance is:");

    gotoxy(34,22);
    printf("> >     %s.00 Php   < <", balin);
    fclose(fBal);
    getch();
    system("cls");
    transaction();
}

void transaction(){
    design();

    gotoxy(30,11);
    printf("\t\t[1] WITHDRAW");

    gotoxy(30,15);
    printf("\t\t[2] DEPOSIT");

    gotoxy(30,19);
    printf("\t\t[3] BALANCE INQUIRY");

    gotoxy(30,23);
    printf("\t\t[4] CHANGE PIN");

    gotoxy(30,27);
    printf("\t\t[5] exit");

    gotoxy(30,28);
    printf("\t\t");


    transactionOpt();
}
transactionOpt(){
    int inp = getch();
    switch(inp){

    case '1':
        system("cls");
        withdraw();
        break;

    case '2':
        system("cls");
        deposit();
        break;

    case '3':
        system("cls");
        balInq();
        break;

    case '4':
        system("cls");
        changePin();
        break;

    case '5':
        fclose(fpin);
        fclose(fp);
        fclose(fBal);
        system("exit");
        break;

    default:
        printf("invalid input!");
        system("cls");
        transaction();

    }
}

changePin(){

    char newpin[6];
    design();
    fpin = fopen("f:\\mine\\pincode.txt","w+");

    gotoxy(40,15);
    printf("ENTER NEW PIN");

    gotoxy(40,17);
    printf("_ _ _ _ _ _");

    for(i = 0; i < 6; i++){
           newpin[i] = getch();
           gotoxy(40+i+i, 17);
           printf("*");
           fprintf(fpin,"%c", newpin[i]);
    }

    fclose(fpin);
    system("cls");
    transaction();

}

void genAccID(){
    n = 5;
    time_t t;
    srand((unsigned) time(&t));
}
void enrollment(){
    system("cls");

    design();


     /**
    I've looked up on the internet and learned that the Account ID or so-called Customer ID
    is automated and not user-generated, thus, I didn't bother to write a code that asks
    the end-user to input data for the Account ID.
    **/
    gotoxy(12,12);
    genAccID();
    printf("\t\tWelcome! Your ACCOUNT ID is:");

    fprintf(fp,"ACCOUNT ID:");
    for(i =0; i<n; i++){
        accID[i] = rand() %9;
        fprintf(fp,"%d", accID[i]);
        printf("%d", accID[i]);
    }

    gotoxy(12,14);
    printf("\t\tACCOUNT NAME:");
    fgets(name, 200, stdin);
    fprintf(fp,"\t\tACCOUNT NAME: %s", name);

    gotoxy(12,16);
    printf("\t\tPIN:");
    fpin = fopen("f:\\mine\\pincode.txt","a+");
     for(i=0; i<6; i++){
        pin[i]=getch();
        printf("*");

        fprintf(fpin,"%c", pin[i]);
    }

    int balancez[6];

    gotoxy(12,18);
    printf("\t\tBALANCE:");
    gotoxy(33,18);
    printf("_ _ _ _ _ _");
    fBal = fopen("f:\\mine\\balance.txt","w");
    for(i=0; i<6; i++){
        bal[i] = getch();
        gotoxy(33+i+i,18);
        balancez[i] = atoi(&bal[i]);
        printf("%d", balancez[i]);
        fprintf(fBal, "%c", bal[i]);

    }
    fclose(fpin);
    fclose(fBal);
    fclose(fp);

    gotoxy(12,20);
    printf("\t\tSuccess!");
    gotoxy(12,22);
    printf("\t\tPress any KEY to proceed with your transaction.");
    getch();
    system("cls");
    transaction();
    printf("\n\n\n\n\n\n\n\n\n\n\n");
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
