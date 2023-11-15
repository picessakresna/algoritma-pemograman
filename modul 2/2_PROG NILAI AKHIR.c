#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void invalid ();
double input();
void reset();
void mulai();


int main(){
	mulai();
}

void invalid (){
    system("cls");
    printf("\nData Invalid\n");

}
void mulai(){
    int absensi, tgs1, tgs2, tgs3, uas, uts, quiz, nilai;

    printf("===================================\n");
	printf("||      PROGRAM NILAI AKHIR      ||\n");
	printf("===================================\n");

	printf("\nmasukkan absensi = ");
	absensi = input();

    if(absensi>15){
        system("cls");
        printf("Data absensi tidak boleh lebih dari 15!\n");
        mulai();
    }
	printf("\nnilai tugas 1 = ");
	tgs1 = input();
	printf("\nnilai tugas 2 = ");
    tgs2 = input();
	printf("\nnilai tugas 3 = ");
    tgs3 = input();
	printf("\nilai quiz = ");
    quiz = input();
	 
	if(absensi<12){
        printf("\nnilai uas = 0 \n");
        uas=0;
	}else{
        printf("\nnilai uas = ");
        uas = input();
	}
	printf("\nnilai uts = ");
    uts = input();


    nilai=(((absensi)/15)*0.05)+(((tgs1+tgs2+tgs3)/3)*0.2)+(quiz*0.15)+(uts*0.3)+(uas*0.3);

	if(nilai>=0 && nilai<45 ){
		printf("Indeks Nilai = E");
	}
	else if(nilai>=45 && nilai<50 ){
		printf("Indeks Nilai = D");
	}
	else if(nilai>=50 && nilai<55 ){
		printf("Indeks Nilai = D+");
	}
	else if(nilai>=55 && nilai<60 ){
		printf("Indeks Nilai = C");
	}
	else if(nilai>=60 && nilai<65 ){
		printf("Indeks Nilai = C+");
	}
	else if(nilai>=65 && nilai<75){
		printf("Indeks Nilai = B");
	}
	else if(nilai>=75 && nilai<80){
		printf("Indeks Nilai = B+");
	}
	else if(nilai>=80){
		printf("\nIndeks Nilai = A");
	}

	printf ("\nNilai akhir = %d \n", nilai);
    reset();
}

double input(){
	double bilangan;
	char karakter;

	if (scanf("%lf%c", &bilangan, &karakter)!= 2 || bilangan<= 0 || bilangan >100 || karakter != '\n' || karakter == ','){
		fflush(stdin);
		printf ("\nInput invalid! Masukan data dengan benar :");
		return input();
	} else{
		return bilangan;
	}
}

void reset(){
	char opt[1];

	printf ("\nApakah anda ingin kembali melakukan operasi? [Y/N] ");
	gets(opt);

	if (!(strcmp(opt, "Y")) ||! (strcmp(opt, "y"))){
		system ("cls");
		mulai();
	}
	else if (!(strcmp(opt, "N")) ||! (strcmp(opt, "n"))){
		system ("cls");
		printf ("Terima Kasih Sudah Menggunakan Program!\n\a");
		return;
	}
	else {
		system ("cls");
		printf ("Input yang anda masukan tidak valid!\n\a");
		reset();
	}
};
