//modul 3 nomor 1

#include <stdio.h>
#include <stdlib.h>
#define MAKS 100

//deklarasi
int pilihan, i, j, m, n;
char opsi2;
float matriks1[MAKS][MAKS] , matriks2[MAKS][MAKS], hasil_matriks[MAKS][MAKS];

//fungsi dan prosedur
void judul();
void menu();
void perkalian_matriks();
void penjumlahan_matriks();
void transpose_matriks();
void input_data();
void keluar();

int main(){
	menu();
	return(0);
}

//validasi angka
int validIn(int *var)
{
	char buff[1024];
	char check;

	if (fgets(buff, sizeof(buff), stdin) !=NULL) {
		if (sscanf(buff, "%d %c", var, &check) ==1){
			return 1;
		}
	}
	return 0;
}

//validasi float
float validFloat(float *var){ 
	char buff[1024]; 
	char cek; 
	if(fgets(buff, sizeof(buff), stdin) !=NULL){ 
  		if(sscanf(buff, "%f %c", var, &cek) ==1){ 
   		return 1; 
  		} 
 	} 
	return 0; 
} 

//header
void judul(char *program){
	system("cls");
	printf("PROGRAM ARITMATIKA MATRIKS\n\n");	
}

void menu(){
	system("cls");
	judul("OPERASI MATRIKS");	
	printf("  1. Perkalian Matriks\n");
	printf("  2. Penjumlahan Matriks\n");
	printf("  3. Transpose Matriks\n");
	printf("  4. Exit");
	printf("\n  Masukan pilihan : ");
	fflush(stdin);	

	if (validIn(&pilihan)){
	} 
	else{
		printf("\n   invalid input");
		getch();
		menu();
	}
	if (pilihan==1){
		perkalian_matriks();
	}
	else if (pilihan==2){
		penjumlahan_matriks();
	}
	else if (pilihan==3){
		transpose_matriks();
	}
	else if (pilihan==4){
		system("cls");
		printf("\n\n\tTerimakasih Telah Menggunakan Program ini\n\n");
		sleep(2);
		exit(0);
	}
	else{
		printf("\n invalid input");
		getch();
		menu();
  	}
}

void input_data(){
	printf("  Masukan Jumlah Baris Pada Matriks	: ");
	if (validIn(&m)){
	} 
	else{
		printf("\n invalid input");
		getch();
		input_data();
	}
	printf("  Masukan Jumlah Kolom Pada Matriks	: ");
	if (validIn(&n)){
	} 
	else{
		printf("\n  invalid input");
		getch();
		input_data();
	}
}

//fungsi perkalian matriks
void perkalian_matriks(){
	system("cls");
	judul("PERKALIAN MATRIKS");
	int p, q, k;
	float jumlah = 0;
	
	printf("  Masukkan Jumlah Baris Matriks Pertama	: ");
	if (validIn(&m)){
	} 
	else{
		printf("\n  invalid input");
		getch();
		perkalian_matriks();
	}
	printf("  Masukkan Jumlah Kolom Matriks Pertama	: ");
	if (validIn(&n)){
	} 
	else{
		printf("\n  invalid input");
		getch();
		perkalian_matriks();
	}
	printf("  Masukkan Jumlah Baris Matriks Kedua	: ");
	if (validIn(&p)){
	} 
	else{
		printf("\n  invalid input");
		getch();
		perkalian_matriks();
	}
	printf("  Masukkan Jumlah Kolom Matriks Kedua	: ");
	if (validIn(&q)){
	} 
	else{
		printf("\n  invalid input");
		getch();
		perkalian_matriks();
	}
	printf("\n");
	
	//kolom m1 = baris m2
	if(n != p){
		printf("  Matriks Tidak Dapat Dikalikan Satu Sama Lain !\n");
	}
	
	else {
    	printf("\t\tMatriks Pertama\n");
    	for(i = 0; i < m; i++){
      		for(j = 0; j < n; j++){
      			printf("  Masukan matriks baris [%d] kolom [%d]	: ", i+1, j+1);
        		if(validFloat(&matriks1[i][j])){
				}
				else{
					printf("\n  invalid input\n\n");
					getch();
					perkalian_matriks();
				}
      		}
   		}
    	
		printf("\n\t\tMatriks Kedua\n");
    	for(i = 0; i < p; i++){
      		for(j = 0; j < q; j++){
      			printf("  Masukan matriks baris [%d] kolom [%d]	: ", i+1, j+1);
        		if(validFloat(&matriks2[i][j])){
					}
					else{
						printf("\n  invalid input\n\n");
						getch();
						perkalian_matriks();
				}
      		}
    	}
    	
		for(i = 0; i < m; i++){
      		for(j = 0; j < q; j++){
        		for(k = 0; k < p; k++){
          		jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        		}
        	hasil_matriks[i][j] = jumlah;
        	jumlah = 0;
      		}
    	}
		printf("\n\t  Hasil Perkalian Matriks\n");
    	for(i = 0; i < m; i++){
    		for(j = 0; j < n; j++){
        		printf("\t%.2f", hasil_matriks[i][j]);
    		}
      		printf("\n");
   		}
	}
	sleep(2);
	keluar();
}


void penjumlahan_matriks(){
	system("cls");
	judul("PENJUMLAHAN MATRIKS");
	
	input_data();
	printf("\n\t\tMatriks Pertama\n");
   	for(i = 0; i < m; i++){
     	for(j = 0; j < n; j++){
     		printf("  Masukan matriks baris [%d] kolom [%d]	: ", i+1, j+1);
       		if(validFloat(&matriks1[i][j])){
			}
			else{
				printf("\n invalid input\n\n");
				getch();
				penjumlahan_matriks();
			}
   		}
  	} 	
	printf("\n\t\tMatriks Kedua\n");
    for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
     		printf("  Masukan matriks baris [%d] kolom [%d]	: ", i+1, j+1);
       		if(validFloat(&matriks2[i][j])){
				}
			else{
				printf("\n  invalid input\n\n");
				getch();
				penjumlahan_matriks();
			}
      	}
    }
	
	printf("\n\t Hasil Penjumlahan Matriks \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			hasil_matriks[i][j] = matriks1[i][j] + matriks2[i][j];
			printf("\t%.2f", hasil_matriks[i][j]);
		}
		printf("\n");
	}
	sleep(2);
	keluar();
}
//
void transpose_matriks() {
	system("cls");
  int matriks[10][10], transpose[10][10], r, c;
  int i, j;
  printf("transpose matriks\n");
  printf("masukkan jumlah baris  :");
  scanf ("%d", &r);
  printf("masukkan jumlah kolom :");
  scanf("%d", &c);

  // asssigning elements to the matrix
  printf("\nmasukkan elements matriks:\n");
	for (i = 0; i < r; i++)
  	for (j = 0; j < c; j++){
    printf("masukkan elemen matriks baris ke [%d] kolom ke [%d]: ", i + 1,   j + 1);
    scanf("%d", &matriks [i] [j]);
    
  }

  printf("\nelement matriks: \n");
  for (i = 0; i < r; i++)
  for (j = 0; j < c; ++j) {
    printf("%d  ", matriks [i][j]);
    if (j == c - 1)
    printf("\n");
  }


  for (i = 0; i < r; ++i)
  for (j = 0; j < c; ++j) {
    transpose[j][i] = matriks[i][j];
  }

 
  printf("\nhasil transpose :\n");
  for (i = 0; i < c; ++i)
  for (j = 0; j < r; ++j) {
    printf("%d  ", transpose[i][j]);
    if (j == r - 1)
    printf("\n");
  }
  	sleep(2);
	keluar();
}

void keluar(){
	fflush(stdin);
	printf("\n Ingin Kembali Menghitung Matriks?(Y/T): ");
	scanf("%s", &opsi2);
	if(opsi2=='Y'||opsi2=='y'){
		system("cls");
		main();
	}
	else if(opsi2=='T'||opsi2=='t'){
		system("cls");
		printf("\nTerimakasih Telah Menggunakan Program Matriks\n\n");
		sleep(2);
	}
	else{
		printf("\n  invalid input !");
		keluar();
	}
}
