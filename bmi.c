#include <stdio.h>

int main() {
    char Jeniskelamin;
    float berat, tinggi, bmi;

   
    printf("Masukkan jenis kelamin (P untuk pria, W untuk wanita): ");
    scanf(" %c", &Jeniskelamin);

    // Menampilkan kategori BMI berdasarkan jenis kelamin
    if (Jeniskelamin == 'P') {
            printf("Masukkan berat badan (kg) : ");
            scanf("%f", &berat);
            printf("Masukkan tinggi badan (cm) :");
            scanf("%f", &tinggi);
            
    tinggi = tinggi / 100;
    bmi = berat / (tinggi * tinggi);
    // Menampilkan hasil BMI
    printf("BMI Anda: %.2f\n", bmi);

        if (bmi < 18.5) {
            printf("Kategori BMI: Kurang berat badan\n");
        } else if (bmi >= 18.5 && bmi < 24.9) {
            printf("Kategori BMI: Normal\n");
        } else if (bmi >= 25 && bmi < 29.9) {
            printf("Kategori BMI: Kelebihan berat badan\n");
        } else {
            printf("Kategori BMI: Obesitas\n");
        }
    } else if (Jeniskelamin == 'W') {
            printf("Masukkan berat badan (kg) : ");
            scanf("%f", &berat);
            printf("Masukkan tinggi badan (cm) :");
            scanf("%d", &tinggi);
            
    tinggi = tinggi / 100;
    bmi = berat / (tinggi * tinggi);
    // Menampilkan hasil BMI
    printf("BMI Anda: %.2f\n", bmi);
    
        if (bmi < 18.5) {
            printf("Kategori BMI: Kurang berat badan\n");
        } else if (bmi >= 18.5 && bmi < 23.9) {
            printf("Kategori BMI: Normal\n");
        } else if (bmi >= 24 && bmi < 28.9) {
            printf("Kategori BMI: Kelebihan berat badan\n");
        } else {
            printf("Kategori BMI: Obesitas\n");
        }
    } else {
        printf("Jenis kelamin tidak valid.\n");
    }

return 0;
}
