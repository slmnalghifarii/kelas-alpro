#include <stdio.h>
#include <string.h>

struct {
    char nama_obat[30],tipe_obat[30];
    int harga;
}data_obat;

// Function to sort the array using Bubble Sort
void bubbleSort(char arr[][100], int n) {
   int i, j;
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
           if (strcmp(data_obat.nama_obat, data_obat.nama_obat) > 0) {
              swap(data_obat.nama_obat, data_obat.nama_obat);
           }
       }
   }
}

// Function to print the array
void printArray(char arr[][100], int size) {
   int i;
   for (i=0; i < size; i++)
       printf("%s ", arr[i]);
   printf("\n");
}

int main() {
    char arr[100][100];
    int n = 0;
    FILE *DataObat;

    // Open the file
    DataObat = fopen("DataObat.dat", "rb");
    if (DataObat == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    // Read the strings from the file
    while (fgets(arr[n], 100, DataObat) != NULL) {
        // Remove the newline character from the string
        arr[n][strcspn(arr[n], "\n")] = '\0';
        n++;
    }

    fclose(DataObat);

    bubbleSort(arr, n);

    printf("\nObat : \n");
    printArray(arr, n);
    
    return 0;
}
