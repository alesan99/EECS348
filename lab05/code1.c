// Alejandro Sandoval

#include <stdio.h>

#define MONTHS 12

int readSalesData(double sales[], const char *filename);
void monthlySalesReport(double sales[]);
void salesSummaryReport(double sales[]);
void sixMonthMovingAverageReport(double sales[]);
void salesReportHighestToLowest(double sales[]);

const char *monthNames[MONTHS] = {
	"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

int main() {
	// File to read
	const char *filename = "code1-input.txt";

	double sales[MONTHS]; // sales data from file

	if (readSalesData(sales, filename) == 0) {
		// Monthly Sales Report
		monthlySalesReport(sales);
		// Sales Summary Report
		salesSummaryReport(sales);
		// Six-Month Moving Average Report
		sixMonthMovingAverageReport(sales);
		// Sales Report (Highest to Lowest)
		salesReportHighestToLowest(sales);
	}

	return 0;
}

int readSalesData(double sales[], const char *filename) {
	FILE *file;

	// open file
	file = fopen(filename, "r");
	if (file == NULL) {
		// Cannot read file
		printf("Cannot read file %s\n", filename);
		return 1;
	}

	// Read
	for (int i = 0; i < MONTHS; i++) {
		// Read each line. store in sales
		fscanf(file, "%lf", &sales[i]);
	}

	// close file
	fclose(file);
	return 0;
}

void monthlySalesReport(double sales[]) {
	// Just print sales in two columns (Month | Sales)
	printf("Monthly Sales Report for 2024\n\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < MONTHS; i++) {
		// print month and sales, with two decimal places
		printf("%s\t\t%.2f\n", monthNames[i], sales[i]);
	}
	printf("\n");
}

void salesSummaryReport(double sales[]) {
	printf("Sales summary report:\n\n");
	double minSale = sales[0];
	double maxSale = sales[0];
	int minMonth = 0;
	int maxMonth = 0;
	
	double sum = 0;

	for (int i = 0; i < MONTHS; i++) {
		// add to sum
		sum += sales[i];

		// Check if min
		if (sales[i] < minSale) {
			minSale = sales[i];
			minMonth = i;
		}
		// Check if max
		if (sales[i] > maxSale) {
			maxSale = sales[i];
			maxMonth = i;
		}
	}
	printf("Minimum sales: %.2f (%s)\n", minSale, monthNames[minMonth]);
	printf("Maximum sales: %.2f (%s)\n", maxSale, monthNames[maxMonth]);
	
	double average = sum / MONTHS;
	printf("Average sales: %.2f\n\n", average);
}

void sixMonthMovingAverageReport(double sales[]) {
	printf("Six-Month moving average report:\n\n");
	for (int i = 0; i <= MONTHS - 6; i++) { // first 6 months with next 6 months
		double sum = 0;
		for (int j = i; j < i + 6; j++) { // next 6 months
			sum += sales[j];
		}
		double average = sum / 6;

		// print StartMonth-EndMonth sale
		printf("%s-%s\t%.2f\n", monthNames[i], monthNames[i + 5], average);
	}
	printf("\n");
}

void salesReportHighestToLowest(double sales[]) {
	double sortedSales[MONTHS];
	// copy array to sort
	for (int i = 0; i < MONTHS; i++) {
		sortedSales[i] = sales[i];
	}

	// sort
	for (int i = 0; i < MONTHS; i++) {
		for (int j = i + 1; j < MONTHS; j++) {
			// if index i is less than index j, switch
			if (sortedSales[i] < sortedSales[j]) {
				double temp = sortedSales[i];
				sortedSales[i] = sortedSales[j];
				sortedSales[j] = temp;
			}
		}
	}

	printf("Sales report (highest to lowest):\n\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < MONTHS; i++) {
		// Find original month
		for (int j = 0; j < MONTHS; j++) {
			if (sortedSales[i] == sales[j]) {
				printf("%s\t$%.2f\n", monthNames[j], sales[j]);
				break;
			}
		}
	}
	printf("\n");
}