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


void restaurant_initialize()
{
    strcpy(m[1].restaurant, "Khana's");
    strcpy(m[1].first_food, "Sandwich");
    strcpy(m[1].second_food, "Chicken Wings");
    strcpy(m[1].third_food, "pizza");
    m[1].first = 150;
    m[1].second = 100;
    m[1].third = 95;


    strcpy(m[2].restaurant, "KFC");
    strcpy(m[2].first_food, "Burger");
    strcpy(m[2].second_food, "French Fry");
    strcpy(m[2].third_food, "Fried Chicken");
    strcpy(m[2].fourth_food,"Drinks");
    m[2].first = 200;
    m[2].second = 75;
    m[2].third = 110;
    m[2].fourth=50;


    strcpy(m[3].restaurant, "Kacchi Bhai");
    strcpy(m[3].first_food, "Chicken_Biriyani");
    strcpy(m[3].second_food, "Mutton Biriyani");
    strcpy(m[3].third_food, "Borhani");
    strcpy(m[3].fourth_food,"Drinks");
    m[3].first = 250;
    m[3].second = 280;
    m[3].third = 60;
    m[4].fourth=50;
}


void search_by_restaurants()
{
    restaurant_initialize();
    printf(""
           "\n\nPlease Choose the restaurants\n\n1) %s\n2) %s\n3) %s",m[1].restaurant,m[2].restaurant, m[3].restaurant);
    printf("\n4) Exit\n\nPlease ");
    printf("select the restaurant\t");
    scanf("%d", &restaurant_choice);
    if (restaurant_choice > 4)
    {
        printf("Please Enter the valid choice \n\n");
        search_by_restaurants();
    }
    else if (restaurant_choice == 4)
        return;
    else
        restaurants(restaurant_choice);
}


void restaurants(int restaurant_choice)
{
    total = 0;
    while (1)
    {

        printf("\n\nList of foods available");

        printf("in %s\n\n1) %s\tTK: %d\n2)",
               m[restaurant_choice].restaurant,
               m[restaurant_choice].first_food,
               m[restaurant_choice].first);

        printf("%s\tTK: %d\n3) %s\tTK: %d\n4)",
               m[restaurant_choice].second_food,
               m[restaurant_choice].second,
               m[restaurant_choice].third_food,
               m[restaurant_choice].third);

        printf("Cart\n5) Exit\n\nPlease Enter");
        printf("Your Choice\t");
        scanf("%d", &food_choice);


        if (food_choice == 1)
        {
            printf("Please Enter the ");
            printf("Count of %s\t",
                   m[restaurant_choice].first_food);
            scanf("%d", &n);
            total = total
                    + (n * m[restaurant_choice].first);
        }
        else if (food_choice == 2)
        {
            printf("Please Enter the Count");
            printf("of %s\t",
                   m[restaurant_choice].second_food);
            scanf("%d", &n);
            total = total
                    + (n * m[restaurant_choice].second);
        }
        else if (food_choice == 3)
        {
            printf("Please Enter the Count");
            printf("of %s\t",m[restaurant_choice].third_food);
            scanf("%d", &n);
            total = total
                    + (n * m[restaurant_choice].third);
        }


        else if (food_choice == 4)
        {
            cart();
        }
        else if (food_choice == 5)
        {
            search_by_restaurants();
        }
        else
        {
            printf("Please Enter the valid choice\n\n");
        }
    }
}

void search_by_food()
{
    total = 0;

    while (1) {
        printf("\n\nPlease choose the ");
        printf("food\n\n1) %s\t%d\n2) %s\t%d",
               m[1].first_food, m[1].first,
               m[1].second_food, m[1].second);

        printf("\n3) %s\t%d\n4) %s\t%d\n",
               m[1].third_food, m[1].third,
               m[2].first_food, m[2].first);

        printf("5) %s\t%d\n6) %s\t%d\n",
               m[2].second_food, m[2].second,
               m[2].third_food, m[2].third);

        printf("7) %s\t%d\n8) %s\t%d\n",
               m[3].first_food, m[3].first,
               m[3].second_food, m[3].second);

        printf("9) %s\t%d\n10) Cart\n",
               m[3].third_food,
               m[3].third);
        printf("11) Exit");
        printf("\nPlease Enter Your Choice\t");
        scanf("%d", &food);
        if (food > 10) {
            printf("Please enter the valid choice\n\n");
            search_by_food();
        }

        else if (food == 10)
            cart();
        else if (food == 11)
            return;

        else
            food_order(food);
    }
}


void food_order(int food)
{
    if (food >= 1 && food <= 3)
        restaurant_id = 1;
    else if (food >= 4 && food <= 6)
        restaurant_id = 2;
    else
        restaurant_id = 3;
    if ((food % 3) == 1) {
        printf("Please Enter the");
        printf(" Count of %s\t",
               m[restaurant_id].first_food);
        scanf("%d", &n);
        total = total + (n * m[restaurant_id].first);
    }
    else if ((food % 3) == 2) {
        printf("Please Enter the ");
        printf("Count of %s\t",
               m[restaurant_id].second_food);
        scanf("%d", &n);
        total = total + (n * m[restaurant_id].second);
    }
    else if ((food % 3) == 0) {
        printf("Please Enter the ");
        printf("Count of %s\t",
               m[restaurant_id].third_food);
        scanf("%d", &n);
        total = total + (n * m[restaurant_id].third);
    }
}


void cart()
{
    printf("\n\n\n\n*************check your Cart***************");
    printf("\nYour Total Order");
    printf("Amount is: %d\n", total);
    printf("\n\nDo You want to confirm your order (y=1/n=0):");

    scanf("%d", &ch);

    if (ch == 1) {

        printf("\n\nThank You for your order");

           printf("Your Food is on the way.");
        printf("Welcome again!!\n\n");
        return;
    }
    else if (ch == 0) {
        printf("Do You want to exit =-1");
        printf("or Go back =0");
        scanf("%d", &confirm);
        if (confirm == 1) {
            printf("\n\nOops! Your order is");
            printf("cancelled!! Exiting..");
            printf("Thank You visit again!\n");
            return;
        }
        else {
            printf("\n\nThank You\n\n");
            login();
        }
    }
    else {
        printf("\n\nPlease Enter the ");
        printf("correct choice\n\n");
        cart();
    }
}

