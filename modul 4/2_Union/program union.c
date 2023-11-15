//modul 4 nomor 2


#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void set_nilai_kubus_struct(float );
void set_nilai_kubus_union(float);
void input_nilai_float(float *nilai, char *kalimat);
void pengulangan();
float checking_nilai_float(float *nilai);

struct kubus_struct { 
    float sisi; 
    float luas_permukaan; 
    float volume;
} kubus_dengan_struct;

union kubus_union { 
    float sisi;
    float luas_permukaan;
    float volume;
} kubus_dengan_union;

int main() { 
    system("cls");

    printf("===============================\n");
    printf("Program Menghitung Luas Kubus\n");
    printf("===============================\n");
    float sisi_kubus; 
    input_nilai_float(&sisi_kubus, "Silahkan masukkan nilai sisi ");

    set_nilai_kubus_struct(sisi_kubus);
    set_nilai_kubus_union(sisi_kubus);

    printf("===================================================");
    printf("\nUkuran memori kubus dengan struct :\t%lu byte\n", sizeof(kubus_dengan_struct));
    printf("Ukuran memori kubus dengan union  :\t%lu byte\n", sizeof(kubus_dengan_union));

    pengulangan();
    return 0;
}

float checking_nilai_float (float *nilai) {
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL) {
        if(sscanf(buff, "%f", nilai, &cek) ==1) {
            return 1 ;
        }
    }
    return 0;
}

void input_nilai_float(float *nilai, char *kalimat) {
    while(1) {
        printf("%s\n>>> ", kalimat);
        fflush(stdin);
        if(checking_nilai_float(nilai))
            break;
        printf("Input invalid!\n");
    }
}

void set_nilai_kubus_union(float nilai) { 
    printf("===================================================");
    printf("\nKubus dengan Union\n");

    kubus_dengan_union.sisi = nilai;
    printf("Sisi           :\t%.2f \n", kubus_dengan_union.sisi);
    kubus_dengan_union.luas_permukaan = 6 * (pow(kubus_dengan_union.luas_permukaan, 2)); 
    printf("Luas Permukaan :\t%.2f \n", kubus_dengan_union.luas_permukaan);
    kubus_dengan_union.volume = pow(nilai, 3);
    printf("Volume         :\t%.2f \n", kubus_dengan_union.volume);
}

void set_nilai_kubus_struct(float nilai) { 
    printf("===================================================");
    printf("\nKubus dengan Struct\n");

    kubus_dengan_struct.sisi = nilai;
    kubus_dengan_struct.luas_permukaan = 6 * (pow(nilai, 2)); 
    kubus_dengan_struct.volume = pow(kubus_dengan_struct.sisi, 3);

    printf("Sisi           :\t%.2f \n", kubus_dengan_struct.sisi);
    printf("Luas Permukaan :\t%.2f \n", kubus_dengan_struct.luas_permukaan);
    printf("Volume         :\t%.2f \n", kubus_dengan_struct.volume);
}

void pengulangan() {
    int i = 0; 
    // untuk validasi
    char pengulangan[10]; 
    // untuk pilhan mengulang
    char pilihanMengulang;

    while ( i == 0 ) { 
        printf("===================================================\n");
        printf("Apakah anda ingin mengulang program ini? (Y/T)?\n");
        // diberikan spasi didepan %c agar 
        printf(">>> ");
        fgets(pengulangan, 9, stdin)  ;

        if (strlen(pengulangan) < 1 || strlen(pengulangan) > 2) {
           printf("ERROR\n*** Silahkan Ketik antara Y/T\n");
           continue;
        };

        if (sscanf(pengulangan, "%c", &pilihanMengulang) != 1) {
            printf("ERROR\n");
        }
        
        pilihanMengulang = toupper(pilihanMengulang);
        // dari header ctype.h
        if ( pilihanMengulang == 'Y') {
            main(); 
            i = 1; 
        } else if ( pilihanMengulang == 'T') {  
            i = 1;  
            printf(" Terima Kasih telah menggunakan program ini"); 
        } else  
            printf("ERROR\n ingin kembali menghitung Y/T\n");
    }

    system("cls");
}
