#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "car.h"

int main()
{
    int i,type,k,choice,result;
    User * usr;

    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");

    gotoxy(20,13);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    _getch();

    textcolor(YELLOW);
    addAdmin();

    while(1){
        clrscr();

        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");

        textcolor(YELLOW);
        gotoxy(1,8);
        for(i = 0 ; i < 80 ; i++){
            printf("*");
        }
        gotoxy(1,18);
        for(i = 0 ; i < 80 ; i++){
            printf("*");
        }
        gotoxy(32,10);
        printf("1. ADMIN");
        gotoxy(32,12);
        printf("2. EMPLOYEE");
        gotoxy(32,14);
        printf("3. QUIT");
        gotoxy(32,16);
        textcolor(WHITE);
        printf("Select your role : ");
        do{
            scanf("%d",&type);
            if(type == 1){
                do{
                    usr = getInput();
                    if(usr == NULL ){
                        //printf("return Null");
                        //getch();
                        k = -1;
                        break;
                    }else{
                        k = checkUserExist(*usr,"admin");
                    }
                }while(k == 0);
                if(k == -1){
                    break;
                }
                if(k == 1){
                    gotoxy(1,20);
                    textcolor(WHITE);
                    printf("Press any key to continue");
                    _getch();
                    while(1){
                        clrscr();
                        choice = adminMenu();
                        if(choice == 7){
                            break;
                        }
                        switch(choice){
                        case 1:
                            addEmployee();
                            break;
                        case 2:
                            addCarDetails();
                            break;
                        case 3:
                            viewEmployee();
                            break;
                        case 4:
                            showCarDetails();
                            break;
                        case 5:
                            clrscr();
                            result = deleteEmp();
                            gotoxy(15,14);
                            if(result == 0){
                                textcolor(LIGHTRED);
                                printf("Sorry ! No emp found for given EMP-ID");
                            }
                            else if(result == 1){
                                textcolor(LIGHTGREEN);
                                printf("Record Deleted Successfully !");
                            }
                            else if(result == 2){
                                textcolor(LIGHTRED);
                                printf("Sorry! Error in Deletion. Try Again!");
                            }
                            textcolor(WHITE);
                            printf("\n\nPress any key to go back to the main screen !");
                            getch();
                            break;
                        case 6:
                            clrscr();
                            result = deleteCarModel();
                            gotoxy(15,14);
                            if(result == 0){
                                textcolor(LIGHTRED);
                                printf("Sorry ! No car found for given CAR-ID");
                            }
                            else if(result == 1){
                                textcolor(LIGHTGREEN);
                                printf("CAR MODEL Deleted Successfully !");
                            }
                            else if(result == 2){
                                textcolor(LIGHTRED);
                                printf("Sorry! Error in Deletion. Try Again!");
                            }
                            textcolor(WHITE);
                            printf("\n\nPress any key to go back to the main screen !");
                            getch();
                            break;
                        default:{}
                        }
                    }
                    break;
                }
            }else if(type == 2){
                do{
                    usr = getInput();
                    if(usr == NULL ){
                        k = -1;
                        break;
                    }else{
                        k = checkUserExist(*usr,"emp");
                    }
                }while(k == 0);
                if(k == -1){
                    break;
                }
                if(k == 1){

                    gotoxy(1,20);
                    textcolor(WHITE);
                    printf("Press any key to continue");
                    _getch();
                    while(1){
                        clrscr();
                        choice = empMenu();
                        if(choice == 6){
                            break;
                        }



                        switch(choice){
                        case 1:
                            clrscr();

                            result = rentCar();
                            if(result == -2)
                            {
                                textcolor(LIGHTRED);
                                printf("Sorry ! All Car Booked. Try Later");
                                getch();
                            }
                            break;

                        case 2:
                            bookedCarDetail();
                            break;

                        case 3:
                            availCarDetails();
                            break;

                        case 4:
                            showCarDetails();
                            break;
                        case 5:
                            return_car();
                            break;

                        default :
                            {
                                printf("\nInvalid Choice !!!");
                                getch();
                            }

                        }

                    }
                    break;
                }
            }else if(type == 3){
                clrscr();
                textcolor(GREEN);
                gotoxy(30,12);
                printf("Thank you for using the app");
                getch();
                exit(0);

            }else{
                textcolor(RED);
                gotoxy(30,21);
                printf("Invalid Choice");
                getch();

                gotoxy(30,21);
                printf("\t\t\t\t");
                gotoxy(51,16);
                printf("\t\t\t");
                gotoxy(51,16);
            }
        }while(1);

    }
    return 0;
}
