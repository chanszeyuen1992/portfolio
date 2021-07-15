#include<stdio.h>
#include<math.h>

float get_dollar(void);
// This programme is to calculation how many minimun numbers of coins should the cashier return.
int main(void)
{
    float dollars = get_dollar();

    //Converts dollars to cents
    int cents = round(dollars*100);

    int cent100 = 0;
    int cent200 = 0;
    int cent500 = 0;
    int cent50 = 0;
    int cent20 = 0;
    int cent10 = 0;

    //calculate the number of different coins.
    while (cents > 0){
        if (cents >= 500){
            cent500 += 1;
            cents -= 500;
        }
         else if (cents >= 200){
            cent200 += 1;
            cents -= 200;
        }
         else if (cents >= 100){
            cent100 += 1;
            cents -= 100;
        }
        else if (cents >= 50){
            cent50 += 1;
            cents -= 50;
        }
        else if (cents >= 20){
            cent20 += 1;
            cents -= 20;
        }
        else
        {
            cent10 += 1;
            cents -= 10;
        }
    }

    //sum up the total number of coins.
    int total = cent500 + cent200 + cent100 + cent50 + cent20 + cent10;

    printf("Total: %i\n", total);
    printf("$5 coins: %i\n$2 coins: %i\n$1 coins: %i\n50 cents coins: %i\n20 cents coins: %i\n10 cents coins: %i\n ", cent500, cent200, cent100, cent50, cent20, cent10);
}

float get_dollar(void){
    float i;

    do{
        printf("Dollars owned: ");
        scanf("%f", &i);
    }while (i < 0);

    return i;
}