#include <stdio.h>
#include <string.h>

struct{
    char nama[20],nim[20], isiloker[20];
    
}x[100],temp;

int main(){
    int n, i, j;

    printf("masukkan jumlah mahasiswa: ");
    scanf("%d", &n);getchar();

    for(i=0;i<n;i++){
        printf("Masukkan nama pemilik loker %d: ", i+1);
        gets(x[i].nama);
        printf("Masukkan NIM pemilik loker %d: ", i+1);
        gets(x[i].nim);
        printf("Masukkan isi loker pemilik loker %d: ",i+1);
        gets(x[i].isiloker);
    }

    for (i=x-1;i>=1;i--){
        for (j=1;j<=i;j++){
            if (strcmp(x[j-1].nama,x[j].nama)>0){
                temp=x[j-1];
                x[j-1]=x[j];
                x[j]=temp;
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("=== Loker %d ===\n", i+1);
        printf("Pemilik : %s\n", x[i].nama);
        printf("NIM : %s\n", x[i].nim);
        printf("Isi loker : %s\n\n", x[i].isiloker);
    }
}