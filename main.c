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
int validate()
{

    for (i = 0; temp_name[i] != '\0'; i++) {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
              || (temp_name[i] >= 'A'
                  && temp_name[i] <= 'Z'))) {
            printf("\nPlease Enter the valid Name\n");
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        count = 0;


        for (i = 0;temp_email[i] != '\0'; i++) {
            if (temp_email[i] == '@'|| temp_email[i] == '.')
                count++;
        }
        if (count >= 2&& strlen(temp_email) >= 5) {

            if (!strcmp(temp_password1,
                        temp_password2)) {
                if (strlen(temp_password1) >= 8
                    && strlen(temp_password1) <= 12) {
                    caps = 0;
                    small = 0;
                    numbers = 0;
                    special = 0;
                    for (i = 0; temp_password1[i] != '\0';
                         i++) {
                        if (temp_password1[i] >= 'A'
                            && temp_password1[i] <= 'Z')
                            caps++;
                        else if (temp_password1[i] >= 'a'
                                 && temp_password1[i]
                                        <= 'z')
                            small++;
                        else if (temp_password1[i] >= '0'
                                 && temp_password1[i]
                                        <= '9')
                            numbers++;
                        else if (temp_password1[i] == '@'
                                 || temp_password1[i] == '&'
                                 || temp_password1[i] == '#'
                                 || temp_password1[i]
                                        == '*')
                            special++;
                    }
                    if (caps >= 1 && small >= 1
                        && numbers >= 1 && special >= 1) {

                        if (temp_age != 0 && temp_age > 0) {

                            if (strlen(temp_mobile) == 11) {
                                for (i = 0; i < 10; i++) {
                                    if (temp_mobile[i]
                                            >= '0'
                                        && temp_mobile[i]
                                               <= '10') {
                                        success = 1;
                                    }
                                    else {
                                        printf("\n\nPlease Enter Valid 11 digit mobile Number\n\n");
                                        return 0;
                                        break;
                                    }
                                }


                                if (success == 1)
                                    return 1;
                            }
                            else {
                                printf("\n\nPlease Enter the 11 digit mobile number\n");
                                return 0;
                            }
                        }
                        else {
                            printf("\n\nPlease Enter the valid age\n\n");
                            return 0;
                        }
                    }
                    else {
                        printf("\n\nPlease Enter the");
                        printf("strong password, Your ");
                        printf("password must contain ");
                        printf("atleast one uppercase, ");
                        printf("Lowercase, Number and ");
                        printf("special character\n\n");
                        return 0;
                    }
                }
                else {
                    printf("\nYour Password is very short\nLength must between 8 to 12\n\n");
                    return 0;
                }
            }
            else {
                printf("\nPassword Mismatch\n\n");
                return 0;
            }
        }
        else {
            printf("\nPlease Enter Valid E-Mail\n\n");

            return 0;
        }
    }
}

void account_check()
{
    for (i = 0; i < 100; i++) {

        if (!(strcmp(temp_email, s[i].email)
              && strcmp(temp_password1,
                        s[i].password))) {
            printf("\n\nAccount Already Existed. Please Login !!\n\n");
            main();
            break;
        }
    }

    if (i == 100) {
        strcpy(s[j].name, temp_name);
        s[j].age = temp_age;
        strcpy(s[j].password, temp_password1);
        strcpy(s[j].email, temp_email);
        strcpy(s[j].mobile, temp_mobile);
        j++;
        printf("\n\n\nAccount Successfully Created!!\n\n");
    }
}

void login()
{
    printf("\n\n**************Welcome to Login page ****************\n\n");

    printf("\tEnter Your Email: ");
    scanf("%s", temp_email);
    printf("\tEnter Your Password: ");
    scanf("%s", temp_password1);
    for (i = 0; i < 100; i++)
    {

        if (!strcmp(s[i].email, temp_email))
        {

            if (!strcmp(s[i].password, temp_password1))
            {
                printf("\n\nWelcome %s, ", s[i].name);
                printf("Your are successfully ");
                printf("logged in\n\n ");
                printf("We Provide two ways of search\n ");
                printf("1) Search By Restaurants\n ");
                printf("2) Search by Food\n ");
                printf("3)Exit\n\n");
                printf("Please Enter your choice:");
                scanf("%d", &search_choice);


                switch (search_choice)
                {
                case 1:
                {
                    search_by_restaurants();
                    break;
                }
                case 2:
                {
                    search_by_food();
                    break;
                }
                case 3:
                {
                    main();
                    return;
                }
                default:
                {
                    printf("Please Enter the valid choice\n\n ");
                    break;
                }
                }
                break;
            }
            else
            {
                printf("\n\nInvalid Password! ");
                printf("Please Enter the correct password\n\n");
                main();
                break;
            }
        }
        else
        {
            printf("\n\nAccount doesn't exist,Please signup!!\n\n ");
            main();
            break;
        }
    }
}

