#include<stdio.h>
#include<string.h>
#include<conio.h>

int acclogin()
{
    char uname[100], pass[10];
    int attempts = 0, chnc = 3;

    while(attempts < 3)
    {
        printf("\nEnter your username: ");
        scanf("%99[^\n]", uname);  
        fflush(stdin); 

        printf("\nEnter your password: ");
        int i = 0;
        while (i < 9) 
        {
            pass[i] = getch();  
            if (pass[i] == '\r') 
                break;
            printf("*"); 
            i++;
        }
        pass[i] = '\0'; 

        if (strcmp(uname, "Chetan536") == 0 && strcmp(pass, "test@123") == 0)
        {
            printf("\nLogin successful!\nWelcome %s!\n", uname);
            return 1; 
        }
        else
        {
            attempts++;
            if (attempts == 3)
            {
                printf("\n\aYour account has been blocked for 24 hours for security reasons!\n");
                return 0;
            }
            else
            {
                printf("\nWrong username or password.");
                printf("\nAfter 3 unsuccessful attempts, your account will be blocked.");
                printf("\nYou have %d chance(s) left.\n", chnc - attempts);
            }
        }
        fflush(stdin); 
    }
    return 0;
}

int atm()
{
    char pin[5]; 
    int chnc = 3, c = 0;
    
    start:
    printf("\nEnter your 4-digit ATM pin: ");
    int i = 0;
    while (i < 4) {
        pin[i] = getch(); 
        printf("*"); 
        i++;
    }
    pin[i] = '\0';
    
    if (strcmp(pin, "7699") == 0) {
        return 1; 
    } else {
        c++;
    }
    
    if (c == 3) {
        printf("\n\aYour ATM card has been blocked!\n");
        return 0;
    } else {
        printf("\n\aWrong pin! Please try again\n");
        printf("You have %d chance(s) left\n", --chnc);
        goto start;
    }
}

int main()
{
    float damt, wamt, balance = 2000;
    char ch;

    if (acclogin() == 0) return 0;
    puts("l. Login");
    puts("d. Deposit");
    puts("w. Withdraw");
    puts("b. Balance");

    start:
    printf("\nEnter your option[ ]\b\b");
    scanf(" %c", &ch);
    if (ch >= 'A' && ch <= 'Z') ch += 32;

    switch (ch)
    {
        case 'd':
            printf("Enter amount to deposit: ");
            scanf("%f", &damt);
            if (damt > 0)
            {
                printf("\n%.2f amount has been successfully deposited", damt);
                balance += damt;
            }
            else
            {
                puts("Invalid amount! Amount cannot be stored");
            }
            break;

        case 'w':
            printf("Enter amount to withdraw: ");
            scanf("%f", &wamt);
            if (wamt > 0 && wamt <= balance)
            {
                if (atm())
                {
                    printf("\n%.2f amount has been successfully withdrawn", wamt);
                    balance -= wamt;
                }
            }
            else
            {
                puts("Invalid amount! Insufficient balance!");
            }
            break;

        case 'b':
            printf("Balance = %.2f", balance);
            break;

        case 'l':
            puts("You are already logged in!");
            break;

        default:
            puts("Invalid choice/option");
            break;
    }

    goto start;
    return 0;
}

