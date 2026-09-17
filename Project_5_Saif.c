#include <stdio.h>
#include <string.h>


void insertInfo(int num, char brand[100][100],
                char model[100][100], char color[100][100],
                int price[100], int storage_capacity[100]) {
    for (int i = 0; i < num; i++) {
        printf("\nMobile %d:\n", i + 1);
        printf("Brand: ");
        scanf(" %[^\n]", brand[i]);
        printf("Model: ");
        scanf(" %[^\n]", model[i]);
        printf("Color: ");
        scanf(" %[^\n]", color[i]);
        printf("Storage Capacity (GB): ");
        scanf("%d", &storage_capacity[i]);
        printf("Price: ");
        scanf("%d", &price[i]);
    }
}


void showStats(int num, int price[100]) {
    int min = price[0], max = price[0], total = 0;

    for (int i = 0; i < num; i++) {
        if (price[i] < min) min = price[i];
        if (price[i] > max) max = price[i];
        total += price[i];
    }

    float avg = (float)total / num;
    printf("\nTotal Mobiles: %d\n", num);
    printf("Min Price: %d\n", min);
    printf("Max Price: %d\n", max);
    printf("Avg Price: %.2f\n", avg);
}


void searchMobile(int num, char brand[100][100],
                   char model[100][100], char color[100][100],
                    int price[100], int storage_capacity[100]) {
    char searchBrand[100];
    int found = 0;

    printf("\nEnter Brand to Search: ");
    scanf(" %[^\n]", searchBrand);
    for (int i = 0; i < num; i++) {
    if (strcmp(brand[i], searchBrand) == 0) {
    printf("\nBrand: %s\nModel: %s\nColor: %s\nPrice: %d\nStorage Capacity (GB): %d\n",
       brand[i], model[i], color[i], price[i], storage_capacity[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNot Available\n");
    }
}

int main() {
    int num;
    printf("Enter number of mobiles: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid number! Must be at least 1.\n");
        return 1;
    }

    char brand[100][100], model[100][100], color[100][100];
    int price[100], storage_capacity[100];

    insertInfo(num, brand, model, color, price, storage_capacity);
    showStats(num, price);
    searchMobile(num, brand, model, color, price, storage_capacity);

    return 0;
}
