#include <stdio.h>
#include <string.h>

void displaiNilaiAkhir(int nilaiAkhir, char grade);

int calcNilai(char nama[50], int NIM, int tugas, int quiz, int UTS, int UAS) {
    int nilaiAkhir;
    char grade[15];

    printf("====PERHITUNGAN NILAI AKHIR====\n");
    printf("nama mahasiswa : "); scanf("%s", nama);
    printf("NIM : "); scanf("%d", &NIM);
    printf("nilai tugas : "); scanf("%d", &tugas);
    printf("nilai quiz : "); scanf("%d", &quiz);
    printf("nilai UTS : "); scanf("%d", &UTS);
    printf("nilai UAS : "); scanf("%d", &UAS);

    nilaiAkhir = ((tugas*0.1)+(quiz*0.2)+(UTS*0.3)+(UAS*0.4));

    if (nilaiAkhir > 90) {
       strcpy(grade, "A");
    } else if (nilaiAkhir >= 81 && nilaiAkhir <= 90) {
       strcpy(grade, "AB");
    } else if (nilaiAkhir >= 71 && nilaiAkhir <= 80) {
       strcpy(grade, "B");
    } else if (nilaiAkhir >= 61 && nilaiAkhir <= 70) {
        strcpy(grade, "BC");
    } else if (nilaiAkhir >= 51 && nilaiAkhir <= 60) {
        strcpy(grade, "C");
    } else if (nilaiAkhir >= 45 && nilaiAkhir <= 50) {
        strcpy(grade, "D");
    } else {
        strcpy(grade, "E");
    }

    printf("\n====HASIL====\n");
    printf("Nama mahasiswa : %s\n", nama);
    printf("NIM : %d\n", NIM);
    printf("Nilai tugas : %d\n", tugas);
    printf("Nilai quiz : %d\n", quiz);
    printf("Nilai UTS : %d\n", UTS);
    printf("Nilai UAS : %d\n", UAS);
    printf("Nilai Akhir : %d\n", nilaiAkhir);
    printf("Grade : %s\n", grade);

    displaiNilaiAkhir(nilaiAkhir, *grade);
}

void displaiNilaiAkhir(int nilaiAkhir, char grade) {
    printf("\n====DISPLAY NILAI AKHIR====\n");
    printf("Nilai akhir : %d\n", nilaiAkhir);
    printf("Grade : %c\n", grade);
}

int main() {
    char nama[100];
    int NIM, tugas, quiz, UTS, UAS;

    calcNilai(nama, NIM, tugas, quiz, UTS, UAS);

 return 0;
}
