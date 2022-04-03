#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10


typedef struct {
    char nama[50];      //untuk menyimpan nama mahasiswa
    int nim;            //untuk menyimpan nim mahasiswa
    char alamat[50];    //untuk menyimpan alamat mahasiswa
    float ipk;          //untuk menyimpan ipk mahasiswa

}mhs;

int main(){
    mhs p[MAX];   //untuk menyimpan data mahasiswa
    int pilihan;  //untuk pilihan nomor menu
    char ulang;   //untuk kembali/tidak ke menu
    int save = 2; //total data sekarang
    p[0] = (const mhs){"Fareed",12015,"Surabaya",4.00}; //data konstan pertama
    p[1] = (const mhs){"Jahiz",12036,"Palembang",2.00}; //data konstan kedua
    do{
        int datakosong = MAX; // slot data yang tersedia
        printf("Menu Data Mahasiswa :\n\n");
        printf("1. Lihat semua data mahasiswa.\n");
        printf("2. Masukkan 1 data mahasiswa.\n");
        printf("3. Masukkan 3 data mahasiswa.\n");
        printf("4. Lihat data mahasiswa yang memiliki IPK < 3.00\n");
        printf("5. Lihat data mahasiswa berdasarkan urutan NIM ascending\n");
        printf("6. Edit data mahasiswa\n");
        printf("0. Exit/Program Berakhir\n\n");
        printf("Pilih(sesuai nomor depan) = ");
        scanf("%d",&pilihan);
        if(pilihan == 1){
            //print semua data yang ada
            datakosong-=save;
            printf("\n       Data Mahasiswa        \n");
            printf("|        Nama          |  NIM  |    Alamat   | IPK  |\n");
            for(int i = 0;i<MAX-datakosong;i++){
                printf("| %-20s | %-5d |  %-10s | %.2f |\n",p[i].nama,p[i].nim,p[i].alamat,p[i].ipk);
                printf("-----------------------------------------------------------\n");
            }
            //setiap selesai permintaan user    , akan keluar pilihan untuk kembali ke menu atau tidak(program berakhir)
            printf("Apakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
        else if(pilihan == 2){
            //menginput data sebanyak 1x
            save+=1;
            for(int i = save-1;i<save;i++){
                printf("Input data mahasiswa ke-%d\n",i);
                printf("Input Nama      = ");
                scanf(" %[^\n]s",&p[i].nama);
                printf("Input NIM       = ");
                scanf("%d",&p[i].nim);
                printf("Input Alamat    = ");
                scanf(" %[^\n]s",&p[i].alamat);
                printf("Input IPK       = ");
                scanf("%f",&p[i].ipk);
            }
            printf("Apakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
        else if(pilihan == 3){
            //menginput data sebanyak 3x
            save+=3;
            for(int i = save-3;i<save;i++){
                printf("Input data mahasiswa ke-%d\n",i-1);
                printf("Input Nama      = ");
                scanf(" %[^\n]s",&p[i].nama);
                printf("Input NIM       = ");
                scanf("%d",&p[i].nim);
                printf("Input Alamat    = ");
                scanf(" %[^\n]s",&p[i].alamat);
                printf("Input IPK       = ");
                scanf("%f",&p[i].ipk);
            }

            printf("Apakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
        else if(pilihan == 4){
            //Print data IPK < 3.00
            datakosong-=save;
            int checking = 0; // untuk pengecekan bila tidak ada IPK < 3.00
            printf("\n       Data Mahasiswa        \n");
            for(int i = 0;i<MAX-datakosong;i++){
                if(p[i].ipk < 3){
                printf("|        Nama          |  NIM  |    Alamat   | IPK  |\n");
                printf("| %-20s | %-5d |  %-10s | %.2f |\n",p[i].nama,p[i].nim,p[i].alamat,p[i].ipk);
                printf("-----------------------------------------------------------\n");
                checking++;
                }
            }
            if(checking == 0){
                printf("Tidak ada Mahasiswa yang IPK < 3.00 \n");
            }
            printf("Apakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
        else if(pilihan == 5){
            //Sorting NIM Ascending menggunakan Insertion Sort
            datakosong-=save;
            mhs temp;
            int i,j;
            for(i = 0;i <= MAX - datakosong - 1;i++){
                j = i;
                while(j>0 && (p[j-1].nim > p[j].nim)){
                    temp   = p[j];
                    p[j]   = p[j-1];
                    p[j-1] = temp;
                    j--;
                }
            }
            //print data yang sudah di sorting
            printf("\n       Data Mahasiswa        \n");
            printf("|        Nama          |    NIM     |   Alamat   | IPK  |\n");
            for(int i = 0;i<MAX-datakosong;i++){
                printf("| %-20s | %d |  %-9s | %.2f |\n",p[i].nama,p[i].nim,p[i].alamat,p[i].ipk);
                printf("-----------------------------------------------------------\n");
            }
            printf("Apakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
        else if(pilihan == 6){
            //Menu untuk mengedit data
            datakosong-=save;
            system("cls");
            printf("\n       Data Mahasiswa        \n");
            for(int i = 0;i<MAX-datakosong;i++){
                printf("   |        Nama          |    NIM     |   Alamat   | IPK  |\n");
                printf("%d.| %-20s | %d |  %-9s | %.2f |\n",i,p[i].nama,p[i].nim,p[i].alamat,p[i].ipk);
                printf("-----------------------------------------------------------\n");
           }
            int masuk; //untuk memilih data yang ke berapa
            printf("Masukkan Nomor data yang ingin diedit = ");
            scanf("%d",&masuk);
            system("cls");
            //akan ditampilkan data yang sudah dipilih
            printf("-----------------------------\n");
            printf("Nama      = %s\n",p[masuk].nama);
            printf("NIM       = %d\n",p[masuk].nim);
            printf("Alamat    = %s\n",p[masuk].alamat);
            printf("IPK       = %.2f\n",p[masuk].ipk);
            printf("-----------------------------\n");
            //user bisa mengedit data yang sudah dipilih
            printf("Edit data mahasiswa ke-%d\n",masuk);
            printf("Input Nama      = ");
            scanf(" %[^\n]s",&p[masuk].nama);
            printf("Input NIM       = ");
            scanf("%d",&p[masuk].nim);
            printf("Input Alamat    = ");
            scanf(" %[^\n]s",&p[masuk].alamat);
            printf("Input IPK       = ");
            scanf("%f",&p[masuk].ipk);

            printf("Apakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
        else if(pilihan == 0){
            //Program berakhir/Exit
            return 0;
        }
        else{
            //Menampilkan bila user memilih nomor yang tidak tertera pada menu
            printf("Pilihan anda tidak ditemukan!!!\nApakah anda ingin kembali ke menu utama?(y/t) : ");
            scanf(" %c",&ulang);
            system("cls");
        }
    }while(ulang == 'y');

    printf("Program Berakhir!!!\nFadhlan S. J.\n1203210064\n");




    return 0;
}
