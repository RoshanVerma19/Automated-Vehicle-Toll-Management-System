
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME "toll_data.txt"

typedef struct {
    char vehicleNo[20];
    char type[10];
    char date[11];
    char entryTime[6];
    float toll;
} Transaction;

Transaction *records = NULL;
int count = 0;
int capacity = 0;

/* Vehicle type validation and toll rates */
float getRate(const char *type) {
    if (strcmp(type, "car") == 0) return 100.0f;
    if (strcmp(type, "truck") == 0) return 200.0f;
    if (strcmp(type, "bus") == 0) return 150.0f;
    if (strcmp(type, "bike") == 0) return 50.0f;
    return -1.0f;
}

/* Allocate memory for one new transaction */
Transaction *createTransaction(void) {
    return (Transaction *)malloc(sizeof(Transaction));
}

/* Expand the transaction array when required */
int ensureCapacity(void) {
    if (count < capacity)
        return 1;

    int newCapacity = (capacity == 0) ? 2 : capacity * 2;

    Transaction *temp = (Transaction *)realloc(
        records, newCapacity * sizeof(Transaction));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    records = temp;
    capacity = newCapacity;
    return 1;
}

/* Save a transaction to the file */
void saveTransaction(const Transaction *t) {
    FILE *fp = fopen(FILE_NAME, "a");

    if (fp == NULL) {
        printf("Warning: Could not open data file.\n");
        return;
    }

    fprintf(fp, "%s %s %s %s %.2f\n",
            t->vehicleNo, t->type, t->date,
            t->entryTime, t->toll);

    fclose(fp);
}

/* Load saved transactions at program startup */
void loadTransactions(void) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
        return;

    Transaction t;

    while (fscanf(fp, "%19s %9s %10s %5s %f",
                  t.vehicleNo, t.type, t.date,
                  t.entryTime, &t.toll) == 5) {
        if (!ensureCapacity())
            break;

        records[count++] = t;
    }

    fclose(fp);
}

/* Register a vehicle and calculate toll */
void registerVehicle(void) {
    Transaction *t = createTransaction();

    if (t == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter vehicle number (no spaces): ");
    if (scanf("%19s", t->vehicleNo) != 1) {
        free(t);
        return;
    }

    printf("Vehicle types: car, truck, bus, bike\n");
    printf("Enter vehicle type: ");
    if (scanf("%9s", t->type) != 1) {
        free(t);
        return;
    }

    /* Convert type to lowercase */
    for (int i = 0; t->type[i] != '\0'; i++) {
        if (t->type[i] >= 'A' && t->type[i] <= 'Z')
            t->type[i] = (char)(t->type[i] - 'A' + 'a');
    }

    float rate = getRate(t->type);

    if (rate < 0) {
        printf("Invalid vehicle type!\n");
        free(t);
        return;
    }

    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    if (local == NULL) {
        printf("Unable to get current time.\n");
        free(t);
        return;
    }

    strftime(t->date, sizeof(t->date), "%Y-%m-%d", local);
    strftime(t->entryTime, sizeof(t->entryTime), "%H:%M", local);

    int hour = local->tm_hour;

    /* Off-peak discount: before 6 AM or from 10 PM */
    if (hour < 6 || hour >= 22)
        t->toll = rate * 0.80f;
    else
        t->toll = rate;

    if (!ensureCapacity()) {
        free(t);
        return;
    }

    records[count++] = *t;
    saveTransaction(t);

    printf("\nVehicle registered successfully!\n");
    printf("Vehicle Number : %s\n", t->vehicleNo);
    printf("Vehicle Type   : %s\n", t->type);
    printf("Entry Date     : %s\n", t->date);
    printf("Entry Time     : %s\n", t->entryTime);
    printf("Toll Amount    : Rs. %.2f\n", t->toll);

    free(t);
}

/* Search transactions by vehicle number */
void searchVehicle(void) {
    char number[20];
    int found = 0;

    printf("Enter vehicle number to search: ");
    scanf("%19s", number);

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].vehicleNo, number) == 0) {
            printf("%s | %s | %s %s | Rs. %.2f\n",
                   records[i].vehicleNo,
                   records[i].type,
                   records[i].date,
                   records[i].entryTime,
                   records[i].toll);
            found = 1;
        }
    }

    if (!found)
        printf("No transaction found.\n");
}

/* Search transactions by date */
void searchDate(void) {
    char date[11];
    int found = 0;

    printf("Enter date (YYYY-MM-DD): ");
    if (scanf("%10s", date) != 1)
        return;

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].date, date) == 0) {
            printf("%s | %s | %s | Rs. %.2f\n",
                   records[i].vehicleNo,
                   records[i].type,
                   records[i].entryTime,
                   records[i].toll);
            found = 1;
        }
    }

    if (!found)
        printf("No transactions found for this date.\n");
}

/* Generate a daily report */
void dailyReport(void) {
    char date[11];
    int cars = 0, trucks = 0, buses = 0, bikes = 0;
    int totalVehicles = 0;
    float collection = 0.0f;

    printf("Enter report date (YYYY-MM-DD): ");
    if (scanf("%10s", date) != 1)
        return;

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].date, date) == 0) {
            totalVehicles++;
            collection += records[i].toll;

            if (strcmp(records[i].type, "car") == 0)
                cars++;
            else if (strcmp(records[i].type, "truck") == 0)
                trucks++;
            else if (strcmp(records[i].type, "bus") == 0)
                buses++;
            else if (strcmp(records[i].type, "bike") == 0)
                bikes++;
        }
    }

    printf("\n========== DAILY TOLL REPORT ==========\n");
    printf("Date           : %s\n", date);
    printf("Total Vehicles : %d\n", totalVehicles);
    printf("Cars           : %d\n", cars);
    printf("Trucks         : %d\n", trucks);
    printf("Buses          : %d\n", buses);
    printf("Bikes          : %d\n", bikes);
    printf("Total Collection: Rs. %.2f\n", collection);
    printf("=======================================\n");
}

/* Display all transactions */
void displayAll(void) {
    if (count == 0) {
        printf("No transactions available.\n");
        return;
    }

    printf("\nVehicle No | Type | Date | Time | Toll\n");

    for (int i = 0; i < count; i++) {
        printf("%s | %s | %s | %s | Rs. %.2f\n",
               records[i].vehicleNo,
               records[i].type,
               records[i].date,
               records[i].entryTime,
               records[i].toll);
    }
}

int main(void) {
    int choice;

    loadTransactions();

    do {
        printf("\n===== AUTOMATED VEHICLE TOLL SYSTEM =====\n");
        printf("1. Register Vehicle / Collect Toll\n");
        printf("2. Search by Vehicle Number\n");
        printf("3. Search by Date\n");
        printf("4. Generate Daily Report\n");
        printf("5. Display All Transactions\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                registerVehicle();
                break;
            case 2:
                searchVehicle();
                break;
            case 3:
                searchDate();
                break;
            case 4:
                dailyReport();
                break;
            case 5:
                displayAll();
                break;
            case 0:
                printf("Exiting Toll Management System.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    free(records);
    records = NULL;

    return 0;
}
