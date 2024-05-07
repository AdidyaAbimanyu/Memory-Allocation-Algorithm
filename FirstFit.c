#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Ukuran maksimum untuk array

// Fungsi untuk algoritma First Fit
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_SIZE];

    // Awalnya, setiap proses belum dialokasikan
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Untuk setiap proses, cari blok memori yang cocok
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                // Alokasikan blok j ke proses i
                allocation[i] = j;

                // Kurangi ukuran blok yang tersedia
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Cetak hasil alokasi
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);
    return 0;
}