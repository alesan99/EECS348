// Alejandro Sandoval

#include <stdio.h>
#include <stdlib.h>

#include <string.h> // use strings

#define MONTHS 12

int readSalesData(double sales[], const char *filename);
void printMonthlySalesReport(double sales[]);
void printSalesSummaryReport(double sales[]);
void printSixMonthMovingAverageReport(double sales[]);
int compareSales(const void *a, const void *b);
void printSalesReportHighestToLowest(double sales[]);

const char *monthNames[MONTHS] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

int main() {
    // File to read
    const char *filename = "code1-input.txt";

    double sales[MONTHS]; // sales data from file

    if (readSalesData(sales, filename) == 0) {
        // Monthly Sales Report
        printMonthlySalesReport(sales);
        // Sales Summary Report
        printSalesSummaryReport(sales);
        // Six-Month Moving Average Report
        printSixMonthMovingAverageReport(sales);
        // Sales Report (Highest to Lowest)
        printSalesReportHighestToLowest(sales);
    }

    return 0;
}

int readSalesData(double sales[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
		// Cannot read file
        printf("Cannot read file %s\n", filename);
        return 1;
    }

    // Read
    for (int i = 0; i < MONTHS; i++) {
        // Read each line
        fscanf(file, "%lf", &sales[i]);
    }

    fclose(file);
    return 0;
}

void printMonthlySalesReport(double sales[]) {
    // Just print sales in two columns (Month | Sales)
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        // print month and sales, with two decimal places
        printf("%s\t\t%.2f\n", monthNames[i], sales[i]);
    }
    printf("\n");
}

void printSalesSummaryReport(double sales[]) {
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

void printSixMonthMovingAverageReport(double sales[]) {
    printf("Six-Month moving average report:\n\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6;
        printf("%s-%s\t%.2f\n", monthNames[i], monthNames[i + 5], average);
    }
    printf("\n");
}

int compareSales(const void *a, const void *b) {
    double diff = *(double *)b - *(double *)a;
    return (diff > 0) - (diff < 0);
}

void printSalesReportHighestToLowest(double sales[]) {
    double sortedSales[MONTHS];
    // copy array to sort
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
    }

    qsort(sortedSales, MONTHS, sizeof(double), compareSales);

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