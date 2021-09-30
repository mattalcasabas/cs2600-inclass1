/*
CS 2600
In-Class 1
Part 1: Restaurant bill

1. Generate random number. This number will be used to randomly choose an item from the menu
	a. 0 = salad, 1 = soup, 2 = sandwich, 3 = pizza
2. Ask user for tax rate as a percentage
3. Ask user for tip as a percentage (e.g. 15%)
4. Print the meal cost
5. Print the tax amount
6. Print the tip amount
7. Print the total bill
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float getTax(float subTotal, float rate) {
	return subTotal * rate;
}

float getTip(float subTotal, float tip) {
	return subTotal * tip;
}

int main() {
	int choice;
	static float mealCost, afterTax, afterTip, totalCost;
	float taxRate, tipRate;
	time_t t;
	srand ((unsigned) time (&t));
	choice = rand() % 3; // random int between 0 and 3, see 1a
	
	printf("Enter tax rate as a decimal: ");
	scanf("%f", &taxRate);
	printf("Enter tip rate as a decimal: ");
	scanf("%f", &tipRate);

	switch(choice) {
		case 0: // salad
			mealCost = 9.95;
			afterTax = getTax(mealCost, taxRate);
			afterTip = getTip(mealCost, tipRate);
			totalCost = mealCost + afterTax + afterTip;
			break;
		case 1: // soup
                        mealCost = 4.55;
                        afterTax = getTax(mealCost, taxRate);
                        afterTip = getTip(mealCost, tipRate);
                        totalCost = mealCost + afterTax + afterTip;
                        break;
		case 2: // sandwich
                        mealCost = 13.25;
                        afterTax = getTax(mealCost, taxRate);
                        afterTip = getTip(mealCost, tipRate);
                        totalCost = mealCost + afterTax + afterTip;
                        break;
		case 3: // pizza
			mealCost = 22.35;
                        afterTax = getTax(mealCost, taxRate);
                        afterTip = getTip(mealCost, tipRate);
                        totalCost = mealCost + afterTax + afterTip;
                        break;
	}

	printf("Meal cost: $%.2f\nTax amount: $%.2f\nTip amount: $%.2f\nTotal cost: $%.2f\n", mealCost, afterTax, afterTip, totalCost);

	return 0;
}
