#include <stdio.h>
#include <string.h>


struct details {
    char name[100];
    int age;
    char password[100];
    char email[100];
    char mobile[10];
};


struct restaurants {
    char restaurant[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[25];
    int first, second, third, fourth;
};

struct restaurants m[5];
struct details s[100];

void signup();


void account_check();

int validate();
void login();
void cart();
void search_by_restaurants();
void search_by_food();
void food_order(int food);


void restaurant_initialize();
void restaurants(int restaurant_choice);
int flag = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, choice;
char temp_name[100], temp_password1[100];
char temp_password2[100], temp_email[100];
char temp_mobile[100];
int temp_age, total = 0, food_choice, n;
int restaurant_choice, search_choice, confirm;
int ch, food, restaurant_id;


int main()
{
    while (1) {
        printf("\n\n********************Welcome to Foodista's Ordering System********************");
        printf("\n\n1)SIGNUP\n");
        printf("2)LOGIN\n3)EXIT\n\n");
        printf("Enter your choice (Example-1/2/3):");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            signup();
            break;
        }
        case 2: {
            login();
            break;
        }
        case 3: {
            printf("\n**********************Thank you, Happy Ordering**********************\n");
            exit(0);
            return 0;
        }
        default: {
            printf("\nPlease Enter the valid choice\n");
            break;
        }
        }
    }
}
void signup()
{
      printf("\n\n************Welcome to sign-up page*************\n");
    printf("\tEnter Your name: ");
    scanf("%s", temp_name);

    printf("\tEnter Your Age: ");
    scanf("%d", &temp_age);

    printf("\tEnter Your Email: ");
    scanf("%s", temp_email);

    printf("\tEnter Password: ");
    scanf("%s", temp_password1);

    printf("\tConfirm Password:");
    scanf("%s", temp_password2);

    printf("\nEnter Your Mobile Number: ");
    scanf("%s", temp_mobile);


    x = validate();
    if (x == 1){
        account_check();
         login();
    }
}


