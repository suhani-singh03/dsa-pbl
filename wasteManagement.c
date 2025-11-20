#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINS 100

typedef struct {
    int id;
    char location[50];
    int capacity;
    int current_fill;
} Bin;

Bin bins[MAX_BINS];
int bin_count = 0;

// Add a new bin
void addBin(int id, char location[], int capacity) {
    bins[bin_count].id = id;
    strcpy(bins[bin_count].location, location);
    bins[bin_count].capacity = capacity;
    bins[bin_count].current_fill = 0;
    bin_count++;
}

// Simulate random fill levels
void simulateFill() {
    for (int i = 0; i < bin_count; i++) {
        bins[i].current_fill = rand() % (bins[i].capacity + 1);
    }
}

// Display all bins
void displayBins() {
    printf("\nBin Status:\n");
    for (int i = 0; i < bin_count; i++) {
        printf("ID: %d, Location: %s, Fill: %d/%d\n",
               bins[i].id, bins[i].location, bins[i].current_fill, bins[i].capacity);
    }
}

// Check bins needing collection
void checkBins() {
    printf("\nBins needing collection:\n");
    for (int i = 0; i < bin_count; i++) {
        if (bins[i].current_fill > 0.8 * bins[i].capacity) {
            printf("ID: %d at %s is %.2f%% full\n",
                   bins[i].id, bins[i].location,
                   (float)bins[i].current_fill / bins[i].capacity * 100);
        }
    }
}

// Main function
int main() {
    addBin(1, "Sector A", 100);
    addBin(2, "Sector B", 80);
    addBin(3, "Sector C", 120);

    simulateFill();
    displayBins();
    checkBins();

    return 0;
}
