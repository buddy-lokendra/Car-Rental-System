#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>

struct User{
    char userid[20];
    char pwd[20];
    char name[20];
};

struct Car{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;
};

struct Customer_Car_Details{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd,ed;
};

typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;

void addAdmin();
User * getInput();
int checkUserExist(User,char *);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetail();
void availCarDetails();
char * getCarName(int);

int rentCar();

// <---- Date Validation function --->
int validDate(struct tm , struct tm);   // this function compare 1. current_date
                                        //                       2. Start_Date
                                        //                       3. End_Date

void return_car();  // this function run and check wheather current_date is equal
                    //to car_return_date or not

void returnUpdateCarCount(int);  // when car is return , it increment car count

void return_car_delete();           // this function delete custormer record when
                                    //car is returned

#endif // CAR_H_INCLUDED
