#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Ukuran maksimum untuk array

// Fungsi untuk algoritma Best Fit
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_SIZE];

    // Awalnya, setiap proses belum dialokasikan
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Untuk setiap proses, cari blok memori terbaik
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }

        // Jika blok ditemukan untuk proses saat ini
        if (bestIdx != -1) {
            // Alokasikan blok ke proses ini
            allocation[i] = bestIdx;

            // Kurangi ukuran blok yang tersedia
            blockSize[bestIdx] -= processSize[i];
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

    bestFit(blockSize, m, processSize, n);
    return 0;
}