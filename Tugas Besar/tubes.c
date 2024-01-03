#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *Regist;
FILE *DataSaldo;
FILE *DataSaldo2;
FILE *DataObat;
FILE *DataTransaksi;
FILE *DataCekout;

struct {
    char username[30], password[30];
}data;
struct {
    char nama_obat[30],tipe_obat[30];
    int harga;
}data_obat,sort[100],temp;
struct {
    char username[30];
    int saldo;
}wallet;
struct {
    char username[30],obat[30],tipeobat[30],tanggal[30];
    int total, harga;
}keranjang;

void registrasi();
void cekTopUp();
void riwayat();
void daftarObat();
void updateDataObat();
void Keranjangs();
void order();
void daftarObat_pembeli();

int main() {
    char user_unm[30],user_pass[30];
    int pilihan_login,pilihan_menu,i,c,batas=3,berjalan = 0,keluar=0;
    

    printf("1.Admin\n2.Pembeli\nlogin sebagai : "); scanf("%d",&pilihan_login); getchar();

    switch (pilihan_login)
    {
    case 1:
        while (batas > 0)
        {
            printf("Masukan Username : "); gets(data.username);
            printf("Masukan Password : "); gets(data.password);
            fflush(stdin);
            
            if(strcmp(data.username, "admin") == 0 && strcmp(data.password, "admincuy321")==0){
                printf("Anda berhasil login!!\n");
                batas = -1;
            } else {
                batas--;
                if (batas == 0)
                {
                    printf("Maaf kesempatan anda habis\n\n1. Kembali ke menu login\n2.keluar\nmasukan pilihan : ");
                    scanf("%d",&keluar); 
                    break;
                    
                } 
                printf("Maaf username atau password salah, kesempatan sisa %d lagi\n", batas);
                system("pause");
                system("cls");
            }
        }
        if (keluar == 1) {
            main();
        } else if (keluar == 2) {
            break;
        }
        fflush(stdin);
        printf("Lanjut mas");
        system("pause");
        system("cls");

        do
        {
            printf("===MENU===\n1. Tambah data obat\n2. Lihat riwayat Pembelian\n3. Daftar Obat\nmasukan pilihan menu: ");
            scanf("%d",&pilihan_menu);
            switch (pilihan_menu)
            {
            case 1:
                updateDataObat();
                break;
            case 2:
                riwayat();
                break;
            case 3:
                daftarObat();
                break;
            default:
                break;
            }
            printf("Keluar?\n1.Yes\n2.No\nmasukan pilihan :");
            scanf("%d",&keluar);
            system("cls");
            if (keluar == 1)
            {
                berjalan = 1;
            }
            
            
        } while (berjalan == 0);  
        break;


    case 2:   
        printf("Punya akun??\n1.Yes 2.No\nmasukan angka : ");scanf("%d",&c);getchar();
        if(c == 2){
            registrasi();
            system("pause");
        }
    
        while (batas > 0) {
            Regist = fopen("useracc.dat", "rb");
            printf("Masukan Username : "); gets(user_unm);
            printf("Masukan Password : "); gets(user_pass);
            while (fread(&data,sizeof(data),1,Regist) == 1) {
                if(strcmp(data.username,user_unm ) == 0 && strcmp(data.password, user_pass)==0){
                    printf("Anda berhasil login !!\n");
                    batas = -1;
                    break;
                }
                i++;
        }
        if (batas == -1) {
            system("pause");
            system("cls");
            break;
        }
            
        fclose(Regist);
        batas--;
        if (batas == 0) {
            printf("Maaf kesempatan anda habis\n\n1. Kembali ke menu login\n2.keluar\nmasukan pilihan : ");
            scanf("%d",&keluar); 
            break;                
        } 
        printf("Maaf username atau password salah, kesempatan sisa %d lagi\n", batas);
        system("pause");
        system("cls");    
        }
        if (keluar == 1) {
            main();
        } else if (keluar == 2) {
            break;
        }

        do
        {
            printf("===MENU===\n1.TopUp & Cek Saldo\n2. Beli\n3.keranjang\nmasukan pilihan menu: ");
            scanf("%d",&pilihan_menu);
            switch (pilihan_menu)
            {
            case 1:
                cekTopUp(user_unm);
                break;
            case 2:
                order();
                break;
            case 3:
                Keranjangs();
            default:
                break;
            }
            printf("Keluar?\n1.Yes\n2.No\nmasukan pilihan :");
            scanf("%d",&keluar);
            system("cls");
            if (keluar == 1)
            {
                berjalan = 1;
            }
        } while (berjalan == 0);
        
    
    default:
        break;
    }
}
void registrasi(){
    Regist = fopen("useracc.dat", "ab");
    DataSaldo = fopen("DataSaldo.dat","ab");
    printf("Masukan username : "); gets(data.username);
    printf("Masukan password : "); gets(data.password);
    strcpy(wallet.username,data.username);
    wallet.saldo = 0;

    fwrite(&data, sizeof(data),1,Regist);
    fwrite(&wallet,sizeof(wallet),1,DataSaldo);
    printf("data anda berhasil di simpan");
    fclose(Regist);
    fclose(DataSaldo);
}
void cekTopUp(){
    FILE *DataSaldo2;
    int pilihan,status;
    printf("1. TopUp\n2.Cek Saldo\nMasukan pilihan : ");
    scanf("%d",&pilihan);getchar();
    switch (pilihan) {
    case 1:
        DataSaldo = fopen("DataSaldo.dat","rb");
        DataSaldo2 = fopen("DataSaldo2.dat","wb");
        int nominal=0;
        printf("Masukan nominal : ");
        scanf("%d",&nominal);getchar();
        while (fread(&wallet,sizeof(wallet),1,DataSaldo)==1) {
            if(strcmp(wallet.username,data.username)==0){
                printf("saldo lama: %d",wallet.saldo);
                wallet.saldo+=nominal;
                printf("saldo baru: %d",wallet.saldo);
            } 
            fwrite(&wallet,sizeof(wallet),1,DataSaldo2);
        }
        fclose(DataSaldo);
        fclose(DataSaldo2);
        remove("DataSaldo.dat");
        rename("DataSaldo2.dat","DataSaldo.dat");
        break;
    case 2:
        printf("%s\n",data.username);
        DataSaldo = fopen("DataSaldo.dat","rb");
        while (fread(&wallet,sizeof(wallet),1,DataSaldo) == 1) {
            if (strcmp(wallet.username,data.username)==0){
                printf("username : %s\n",wallet.username);
                printf("Jumlah saldo anda adalah : %d\n",wallet.saldo);
            }
        }
        fclose(DataSaldo);
        break;
    }
}
void riwayat(){
    printf("Riwayat pembelian\n");
    DataTransaksi = fopen("DataTransaksi.dat","rb");
    while (fread(&keranjang,sizeof(keranjang),1,DataTransaksi)==1)
    {
        printf("Tanggal : %s\n",keranjang.tanggal);
        printf("username: %s \n",keranjang.username);
        printf("Nama Obat Obat: %s \n",keranjang.obat);
        printf("Harga Obat: %d\n",keranjang.total);
    }
    
    fclose(DataTransaksi);
}
void daftarObat(){
    DataObat = fopen("DataObat.dat","rb");

    int ukuran = 0;
    while (fread(&sort,sizeof(sort),1,DataObat)) {
        ukuran++;
    }

    for (int i=ukuran-1;i>=1;i--)
        for (int j=1;j<=i;j++) {
            if (strcmp(sort[j-1].nama_obat,sort[j].nama_obat) > 0) {
                temp=sort[j-1];
                sort[j-1] =sort[j];
                sort[j] = temp;
        }
    }
    // for(int i=0;i<ukuran;i++){
    //     printf("Nama obat : %s\t",sort[i].nama_obat);
    //     printf("Nama Tipe Obat : %s\t",sort[i].tipe_obat);
    //     printf("Nama Harga : %d\t\n",sort[i].harga);
    // }
    int pilihan;
    char cari[30];

    printf("1. Daftar semua obat\n2.Cari berdasarkan nama obat\n3.Cari berdasarkan tipe obat\nMasukan pilihan : ");
    scanf("%d",&pilihan); getchar();

    switch(pilihan){
        case 1:
            for(int i=0;i<ukuran;i++){
                printf("Nama obat : %s\t",sort[i].nama_obat);
                printf("Tipe Obat : %s\t",sort[i].tipe_obat);
                printf("Harga : %d\t\n",sort[i].harga);
            }
            break;
        case 2:
            printf("Masukan nama obat yang ingin dicari : "); gets(cari);
            for(int i=0;i<ukuran;i++){
                if(strcmp(cari,sort[i].nama_obat)==0){
                    printf("Nama obat : %s\t",sort[i].nama_obat);
                    printf("Tipe Obat : %s\t",sort[i].tipe_obat);
                    printf("Harga : %d\t\n",sort[i].harga);
                }
            }
            break;
        case 3:
            printf("Masukan tipe obat yang ingin dicari : "); gets(cari);
            for(int i=0;i<ukuran;i++){
                if(strcmp(cari,sort[i].tipe_obat)==0){
                    printf("Nama obat : %s\t",sort[i].nama_obat);
                    printf("Tipe Obat : %s\t",sort[i].tipe_obat);
                    printf("sHarga : %d\t\n",sort[i].harga);
                }
            }
            break;
        default:
            printf("Pilihan tidak ada silahkan masukan pilihan yang tepat");
            daftarObat();
    }
    fclose(DataObat);
}
void updateDataObat() {
    int x, i;
    DataObat = fopen("DataObat.dat","ab");
    printf("Masukan banyak data obat yang di input :");
    scanf("%d",&x);getchar();
    int ukuran = 0;
    

    for(i=0;i<=x;i++){
        printf("%d. Masukan nama obat : ",i+1);gets(sort[i].nama_obat);
        printf("   Masukan tipe obat : ");gets(sort[i].tipe_obat);
        printf("   Masukan Harga : ");scanf("%d",&sort[i].harga); getchar();
        fwrite(&sort,sizeof(sort),1,DataObat);
    }
    fclose(DataObat);
    printf("Data berhasil disimpan\n");
}
void order() {
    int u=1;
    daftarObat_pembeli(); fflush(stdin);
    printf("Masukan tanggal anda saat ini :"); gets(keranjang.tanggal);
    strcpy(keranjang.username,data.username);
    int status = 0;

    DataTransaksi = fopen("DataTransaksi.dat","ab");
    DataObat = fopen("DataObat.dat","rb");
    DataCekout = fopen("DataCekout.dat","ab");
    printf("Nama obat %d : ",u); gets(keranjang.obat);
    printf("Tipe obat %d : ",u); gets(keranjang.tipeobat);
    int i = 0;
    while (fread(&sort,sizeof(sort),1,DataObat))
    {
        if (strcmp(keranjang.obat,sort[i].nama_obat) == 0 && strcmp(keranjang.tipeobat,sort[i].tipe_obat) == 0)
        {
            keranjang.harga=sort[i].harga;
            fwrite(&keranjang,sizeof(keranjang),1,DataTransaksi);
            fwrite(&keranjang,sizeof(keranjang),1,DataCekout);
            printf("Obat berhasil dimasukan ke keranjang\n");
            status = 1;
            u++;
            i++;
            }
        }
    if (status == 0)
    {
        printf("Maaf nama obat atau tipe obat tidak ditemukan\nmasukan yang pada daftar\n");
    }
    fclose(DataObat);
    fclose(DataTransaksi);
    fclose(DataCekout);
}
void Keranjangs(){
    FILE *DataCekout2;
    DataCekout = fopen("DataCekout.dat","rb");
    DataCekout2 = fopen("DataCekout.dat","wb");
    int harga_cekout;
    while (fread(&keranjang,sizeof(keranjang),1,DataCekout)==1)
    {
        if(strcmp(keranjang.username,data.username)==0){
            printf("Nama Obat Obat: %s \n",keranjang.obat);
            printf("Harga Obat: %d\n",keranjang.harga);
            harga_cekout = keranjang.harga;
        } else if(strcmp(keranjang.username,data.username)!=0){
            fwrite(&keranjang,sizeof(keranjang),1,DataCekout2);
        }
    }
    int ckout;
    printf("Check out?\n[1.yes/2.no]"); scanf("%d",&ckout);
    switch (ckout)
    {
    case 1:
        DataSaldo = fopen("DataSaldo.dat","rb");
        DataSaldo2 = fopen("DataSaldo2.dat","wb");
        int nominal=0;
        while (fread(&wallet,sizeof(wallet),1,DataSaldo)==1) {
            if(strcmp(wallet.username,data.username)==0){
                printf("saldo lama: %d",wallet.saldo);
                wallet.saldo-=keranjang.harga;
                printf("saldo baru: %d",wallet.saldo);
            } 
            fwrite(&wallet,sizeof(wallet),1,DataSaldo2);
        }
        fclose(DataSaldo);
        fclose(DataSaldo2);
        remove("DataSaldo.dat");
        rename("DataSaldo2.dat","DataSaldo.dat");
        break;
    case 2:
        break;
    
    default:
        printf("PIlihan tidak ada");
        Keranjangs();
        break;
    }
    fclose(DataTransaksi);
}
void daftarObat_pembeli(){
    DataObat = fopen("DataObat.dat","rb");

    int ukuran = 0;
    while (fread(&sort,sizeof(sort),1,DataObat)) {
        ukuran++;
    }

    for (int i=ukuran-1;i>=1;i--)
        for (int j=1;j<=i;j++) {
            if (strcmp(sort[j-1].nama_obat,sort[j].nama_obat) > 0) {
                temp=sort[j-1];
                sort[j-1] =sort[j];
                sort[j] = temp;
        }
    }
    for(int i=0;i<ukuran;i++){
        printf("Nama obat : %s\t",sort[i].nama_obat);
        printf("Tipe Obat : %s\t",sort[i].tipe_obat);
        printf("Harga : %d\t\n",sort[i].harga);
    }
    fclose(DataObat); 
}
   
    