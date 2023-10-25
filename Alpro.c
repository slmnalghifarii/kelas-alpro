#include <stdio.h>

int main() {

    float berat, tinggi, bmi;
    printf("Masukkan berat badan (kg): ");
    scanf("%f", &berat);

    // Meminta input tinggi badan dalam meter
    printf("Masukkan tinggi badan (m): ");
    scanf("%f", &tinggi);

    tinggi = tinggi / 100;
    bmi = berat / (tinggi * tinggi);

    // Menampilkan hasil BMI
    printf("BMI Anda: %.2f\n", bmi);

    // Menampilkan kategori BMI
    if (bmi < 18.5) {
        printf("Kategori BMI: Kurang berat badan\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Kategori BMI: Normal\n");
    } else if (bmi >= 25 && bmi < 29.9) {
        printf("Kategori BMI: Kelebihan berat badan\n");
    } else {
        printf("Kategori BMI: Obesitas\n");
    }

    return 0;
}
