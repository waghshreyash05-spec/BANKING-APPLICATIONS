#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount
{
    int accNo;
    char name[50];
    float balance;
};

struct BankAccount acc[100];
int totalAccounts = 0;

// Function to create account
void createAccount()
{
    printf("\nEnter Account Number: ");
    scanf("%d", &acc[totalAccounts].accNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", acc[totalAccounts].name);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc[totalAccounts].balance);

    totalAccounts++;

    printf("\n✅ Account Created Successfully!\n");
}

// Function to deposit money
void depositMoney()
{
    int accNo, i;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for(i = 0; i < totalAccounts; i++)
    {
        if(acc[i].accNo == accNo)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            acc[i].balance += amount;

            printf("\n✅ Amount Deposited Successfully!\n");
            printf("Updated Balance = %.2f\n", acc[i].balance);
            return;
        }
    }

    printf("\n❌ Account Not Found!\n");
}

// Function to withdraw money
void withdrawMoney()
{
    int accNo, i;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for(i = 0; i < totalAccounts; i++)
    {
        if(acc[i].accNo == accNo)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if(amount > acc[i].balance)
            {
                printf("\n❌ Insufficient Balance!\n");
            }
            else
            {
                acc[i].balance -= amount;

                printf("\n✅ Withdrawal Successful!\n");
                printf("Remaining Balance = %.2f\n", acc[i].balance);
            }

            return;
        }
    }

    printf("\n❌ Account Not Found!\n");
}

// Function to check balance
void checkBalance()
{
    int accNo, i;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for(i = 0; i < totalAccounts; i++)
    {
        if(acc[i].accNo == accNo)
        {
            printf("\n===== ACCOUNT DETAILS =====\n");
            printf("Account Number : %d\n", acc[i].accNo);
            printf("Name           : %s\n", acc[i].name);
            printf("Balance        : %.2f\n", acc[i].balance);
            return;
        }
    }

    printf("\n❌ Account Not Found!\n");
}

// Function to display all accounts
void displayAccounts()
{
    int i;

    if(totalAccounts == 0)
    {
        printf("\nNo Accounts Available!\n");
        return;
    }

    printf("\n===== ALL ACCOUNTS =====\n");

    for(i = 0; i < totalAccounts; i++)
    {
        printf("\nAccount Number : %d\n", acc[i].accNo);
        printf("Name           : %s\n", acc[i].name);
        printf("Balance        : %.2f\n", acc[i].balance);
    }
}

// Main function
int main()
{
    int choice;

    while(1)
    {
        printf("\n\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                displayAccounts();
                break;

            case 6:
                printf("\nThank You for Using Banking System!\n");
                exit(0);

            default:
                printf("\n❌ Invalid Choice!\n");
        }
    }

    return 0;
}
