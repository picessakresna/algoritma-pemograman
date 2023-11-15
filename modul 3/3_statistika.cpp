// I Putu Agus Putra Negara
// 2105551044
// Kelompok 9
// Modul 3 no.3

#include <stdio.h>
#include <math.h>
#include <windows.h>

void pembatas(){
    char pembatas[] = "---------------------------------------------------------\n";
    printf("%s", pembatas);
}

void clear(){
    system("cls || clear");
}

int validasi_integer() {
    int bilangan;
    char ch;

    scanf("%d%c", &bilangan, &ch);

    if(ch != '\n' || bilangan < 0){
        printf("\n\nInput yang dimasukkan tidak berupa angka!\n", bilangan, ch);

        pembatas();
        printf("\nMasukkan Banyak Bilangan yang Ingin Di Input : ");

        fflush(stdin);
        validasi_integer();
        
    }else{
        return bilangan;
    }
}

void sort_array(int banyak_data, int input_nilai[]){
    int i;
    int key;
    int j;

    for(i = 1 ; i < banyak_data ; i++){
        key = input_nilai[i];
        j = i-1;

        while(j >= 0 && input_nilai[j] > key){
            input_nilai[j+1] = input_nilai[j];
            j = j-1;
        }
        input_nilai[j+1] = key;
    }
}

void print_array(int banyak_data, int input_nilai[]){
    int i;
    int *data = &banyak_data;
    int *nilai = input_nilai;

    printf("{ ");

    for (i = 0; i < *data; i++){
        printf("%d ", nilai[i]);
    }

    printf("}\n");
}

void rumus_mean(int banyak_data, int input_nilai[]){
    float mean;
    float *nilai_mean = &mean;
    int *data = &banyak_data;
    int *nilai = input_nilai;

    for(int i = 0 ; i < *data ; i++){
        *nilai_mean = *nilai_mean + nilai[i];
    }

    *nilai_mean = *nilai_mean / banyak_data;

    printf("Nilai Mean Dari Bilangan yang Di Input Adalah : %.2f\n", mean);
}

void rumus_median(int banyak_data, int input_nilai[]){
    int i;
    float median;
    float *nilai_median = &median;
    int *data = &banyak_data;
    int *nilai = input_nilai;

    i = ((*data + 1) / 2);

    if(*data % 2 == 0){
        *nilai_median = (nilai[i-1] + nilai[i]);
        *nilai_median = *nilai_median / 2;

    }else{
        *nilai_median = nilai[i-1];
    }

    printf("Nilai Median = %.2f", median);
}

void rumus_modus(int banyak_data, int input_nilai[]){
    int nilai_bilangan;
    int bilangan_sementara;
    int modus;
    int i;
    int j;
    int jumlah_nilai_bilangan = 0;

    int *nilai_modus = &modus;
    int *data = &banyak_data;
    int *nilai = input_nilai;

    for(i=0 ; i < *data ; i++){
        nilai_bilangan = nilai[i];
        bilangan_sementara = 0;

        for(j = 0 ; j < *data ; j++){
            if(nilai_bilangan == input_nilai[j]){
                bilangan_sementara = bilangan_sementara + 1;
            }
        }

        if(bilangan_sementara > jumlah_nilai_bilangan){
            jumlah_nilai_bilangan = bilangan_sementara;
            *nilai_modus = nilai[i];
        }
    }
    
    printf("\nNilai yang paling sering muncul (modus) adalah : %d sebanyak %d kali\n", modus, jumlah_nilai_bilangan);
}

int main(){
    int i;
    int banyak_data;
    int no_bilangan = 0;
    int *data = &banyak_data;

    clear();

    printf("\n\n\t\t\tSTATISTIKA\n\n");
    pembatas();

    printf("Masukkan Banyak Bilangan yang Ingin Di Input : ");
    banyak_data = validasi_integer();

    int input_nilai[*data];

    clear();

    printf("\n\n\t\t\tSTATISTIKA\n\n");
    pembatas();

    for(i = 0 ; i < *data ; i++){
        no_bilangan++;

        printf("Masukkan Bilangan Ke-%d : ", no_bilangan);
        input_nilai[i] = validasi_integer();

        printf("\n");
    }

    pembatas();

    printf("Bilangan Sebelum Sorting\n");
    print_array(banyak_data, input_nilai);

    printf("\nBilangan Setelah Sorting\n");
    sort_array(banyak_data, input_nilai);
    print_array(banyak_data, input_nilai);

    pembatas();

    rumus_mean(banyak_data, input_nilai);
    rumus_median(banyak_data, input_nilai);
    rumus_modus(banyak_data, input_nilai);

    pembatas();
    return 0;
}
