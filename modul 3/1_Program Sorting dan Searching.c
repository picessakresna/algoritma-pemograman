#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void InsertionSort(int bil[], int y);
void BubbleSort(int bil[], int y);
void QuickSort(int bil[], int min, int max);
void TimeSort(int bil[], int y);
void TimeSearch(int bil[], int y);
void OpsiSorting();
void OpsiSearching();
void keluar();
void delete_buffer();
void reset();

int SequentialSearch(int bil[], int y, int findnum);
int BinarySearch(int bil[], int min, int max, int findnum);

double validation();

int main(){
	int Opsi;

	printf("---------------------------------------------\n");
	printf("---- Program Operasi Sorting & Searching ----\n");
	printf("---------------------------------------------\n\n");

	printf("Silahkan memilih operasi data\n");
	printf("1. Sorting\n");
	printf("2. Searching\n");	
	printf("3. Keluar\n");
	printf("---------------------------------------------\n");	
	printf("\nOpsi: ");
	Opsi = validation();
	
	if(Opsi==1){
		OpsiSorting();
	}else if(Opsi==2){
		OpsiSearching();		
	}else if(Opsi==3){
		system("cls");
		keluar();		
	}else{
		printf("ivalid inoput, silahkan masukan input dengan benar!\n");
		getch();
		system("cls");		
		main();		
	}
}

void OpsiSorting(){
	int opsi, x, y;
	
	printf("---------------------------------------------\n");	
	printf("                MENU SORTING                 \n");
	printf("---------------------------------------------\n");		
	printf("Silahkan memilih banyak data\n");
	printf("1. 1000\n");
	printf("2. 16000\n");	
	printf("3. 64000\n");
	printf("4. Keluar\n");
	printf("---------------------------------------------\n");	
	printf("\nOpsi :");		
	opsi = validation();
	
	if(opsi>0 && opsi<4){
		if(opsi==1){
			int bil[1000];
			
            system("cls");
            y = sizeof(bil) / sizeof(bil[0]);
            srand((unsigned) time(NULL));
			
			for (x=0; x<y; x++){
				bil[x] = rand();
			}
			TimeSort(bil, y);			
		}else if(opsi==2){
			int bil[16000];
			
            system("cls");
            y = sizeof(bil) / sizeof(bil[0]);
            srand((unsigned) time(NULL));
			
			for (x=0; x<y; x++){
				bil[x] = rand();
			}
			TimeSort(bil, y);			
		}else{
			int bil[64000];
			
            system("cls");
            y = sizeof(bil) / sizeof(bil[0]);
            srand((unsigned) time(NULL));
			
			for (x=0; x<y; x++){
				bil[x] = rand();
			}
			TimeSort(bil, y);				
		}				
	}else if(opsi==4){
		system("cls");
		main();
	}else{
		printf("invalid input, silahkan masukan input dengan benar!\n");
		getch();
		system("cls");		
		OpsiSorting();			
	}
	
	system("pause");
	system("cls");
	reset();
}

void InsertionSort(int bil[], int y){
	int a, b, smt;
	
	for(a=1; a<y; a++){
		smt = bil[a];
		b = a-1;
		while(b >= 0 && bil[b] > smt){
			bil[b+1] = bil[b];
			b--;
		}
		bil[b+1] = smt;
	}
}

void BubbleSort(int bil[], int y){
	int a, b, smt;
	
	for(a=0; a<y-1; a++){
		for(b=0; b<y-a-1; b++){
			if(bil[b] > bil[b+1]){
				smt = bil[b];
				bil[b] = bil[b+1];
				bil[b+1] = smt;
			}
		}
	}	
}

void QuickSort(int bil[], int min, int max){
	int a, b, smt, temp;
	
	if(min<max){
		smt = min;
		a = min;
		b = max;
		
		while(a < b){
			while(bil[a] <= bil[smt] && a < max){
				a++;
			}
			while(bil[b] > bil[smt]){
				b--;
			}
			if (a < b){
				temp = bil[a];
				bil[a] = bil[b];
				bil[b] = temp;
			}	
		}
	
		temp = bil[smt];
		bil[smt] = bil[b];
		bil[b] = temp;
		QuickSort(bil, min, b-1);	
		QuickSort(bil, b+1, max);	
	}	
}

void TimeSort(int bil[], int y){
	int a, b;
	clock_t time;
	float timeneed[2];
	
	time = clock();
	InsertionSort(bil, y);
	time = clock() - time;
	timeneed[0] = (float)(time) / CLOCKS_PER_SEC;
	
	time = clock();
	BubbleSort(bil, y);
	time = clock() - time;
	timeneed[1] = (float)(time) / CLOCKS_PER_SEC;
	
	time = clock();
	QuickSort(bil, 0, y-1);
	time = clock() - time;
	timeneed[2] = (float)(time) / CLOCKS_PER_SEC;		
	
	for (a=0; a<y; a++){
		printf("\t");
		for (b=0; b<=5; b++){
			printf("%d ", bil[a]);
		}
		printf("\n");
	}
	
	printf("\n---------------------------------------------\n");
	printf("          HASIL WAKTU YANG DIBUTUHKAN          \n");
	printf("\n---------------------------------------------\n");
	printf("Metode Insertion Sort	= %f \n", timeneed[0]);		
	printf("Metode Bubble Sort	= %f \n", timeneed[1]);		
	printf("Metode Quick Sort	= %f \n", timeneed[2]);
	printf("\n---------------------------------------------\n\n");
	
	if(timeneed[0] <= timeneed[1] && timeneed[0] <= timeneed[2]){
		printf("Waktu Insertion Sort lebih cepat dari Bubble Sort dan Quick Sort\n");
	}
	else if(timeneed[1] <= timeneed[0] && timeneed[1] <= timeneed[2]){
		printf("Waktu Bubble Sort lebih cepat dari Insertion Sort dan Quick Sort\n");
	}
	else{
		printf("Waktu Quick Sort lebih cepat dari Insertion Sort dan Bubble Sort\n");
	}
	reset();
}

void OpsiSearching(){
	int Opsi, x, y;
	
	printf("---------------------------------------------\n");	
	printf("                 MENU SEARCHING              \n");
	printf("---------------------------------------------\n");		
	printf("Silahkan memilih banyak data\n");
	printf("1. 1000\n");
	printf("2. 16000\n");	
	printf("3. 64000\n");
	printf("4. Keluar\n");
	printf("---------------------------------------------\n");	
	printf("\nOpsi :");		
	Opsi = validation();
	
	if(Opsi>0 && Opsi<4){
		if(Opsi==1){
			int bil[1000];
			
            system("cls");
            y = sizeof(bil) / sizeof(bil[0]);
            srand((unsigned) time(NULL));
			
			for (x=0; x<y; x++){
				bil[x] = rand();
			}
			TimeSearch(bil, y);			
		}else if(Opsi==2){
			int bil[16000];
			
            system("cls");
            y = sizeof(bil) / sizeof(bil[0]);
            srand((unsigned) time(NULL));
			
			for (x=0; x<y; x++){
				bil[x] = rand();
			}
			TimeSearch(bil, y);			
		}else{
			int bil[64000];
			
            system("cls");
            y = sizeof(bil) / sizeof(bil[0]);
            srand((unsigned) time(NULL));
			
			for (x=0; x<y; x++){
				bil[x] = rand();
			}
			TimeSearch(bil, y);				
		}				
	}else if(Opsi==4){
		system("cls");
		main();
	}else{
		printf("Mohon maaf input yang anda masukan salah, silahkan masukan input dengan benar!\n");
		getch();
		system("cls");		
		OpsiSearching();			
	}
}

int SequentialSearch(int bil[], int y, int findnum){
	int a;
	
	for (a=0; a<y; a++){
		if(bil[a] == findnum){
			return a;
		}
	}
	return -1;
}

int BinarySearch(int bil[], int min, int max, int findnum){
	
	if(max >= min){
		int mid = min + (max-min)/2;
		if(bil[mid] == findnum){
			return mid;
		}
		if(bil[mid] > findnum){
			return BinarySearch(bil, min, max-1, findnum);
			return BinarySearch(bil, mid+1, max, findnum);
		}
	}
	return -1;
}

void TimeSearch(int bil[], int y){
	int a, b, findnum, ctr=0;
	clock_t time;
	double timeneed[2];
	
	QuickSort(bil, 0, y-1);
	
	for(a=0; a<y; a++){
		printf("\t");
		for(b=0; b<=5; b++){
			printf("%d ", bil[a]);
		}
		printf("\n");
	}
	printf("\n---------------------------------------------\n");		
	printf("\nMasukkan bilangan yang ingin dicari: ");
	findnum=validation();
	
	time = clock();
	SequentialSearch(bil, y, findnum);
	time = clock() - time;
	timeneed[0] = (float)(time) / CLOCKS_PER_SEC;

	time = clock();
	BinarySearch(bil, 0, y-1, findnum);
	time = clock() - time;
	timeneed[1] = (float)(time) / CLOCKS_PER_SEC;

	for(a=0; a<y; a++){
		if(bil[a] == findnum){
			printf("\n\nBilangan ditemukan pada Indeks Array Ke-%d", a+1);
			ctr++;
		}
	}
	
	if(ctr==0){
		printf("\n\nBilangan %d tidak ada pada Indeks Array!");
	}
	
	printf("\n---------------------------------------------\n");
	printf("           HASIL WAKTU YANG DIBUTUHKAN         \n");
	printf("\n---------------------------------------------\n");
	printf("Metode Sequential Search	= %f \n", timeneed[0]);		
	printf("Metode Binary Search		= %f \n", timeneed[1]);		
	printf("\n---------------------------------------------\n\n");	
	
	if(timeneed[0] <= timeneed[1]){
		printf("Waktu Sequential Search lebih cepat dari Binary Search\n");
	}
	else{
		printf("Waktu Binary Search lebih cepat dari Sequential Search\n");
	}
	reset();	
}

double validation(){

	double bilangan;
	char karakter;
	
	if(scanf("%lf%c", &bilangan, &karakter)!= 2 || bilangan <= 0 || karakter != '\n' || karakter == ','){
		delete_buffer();
		printf("Input yang anda masukan salah!, masukan angka: ");
		return validation();
	} else {
		return bilangan;
	}
}

void delete_buffer(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);	
}

void reset(){
	
	int valid_reset;
	char parameter[1];
	printf("\n\nApakah anda ingin kembali melakukan operasi? [Y/N]: ");
	gets(parameter);
	
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        main();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        keluar();
        exit(1);
    } else {
        system("cls");
        printf("Input Salah!!!\n\a");
        reset();
    }	
}

void keluar (void){
	
	int z;
	char ext[]="\n\terimakasih telah menggunakan program ini  :)";
	for(z=0; z[ext]!=0; z++){
		Sleep(50);
		printf("%c", z[ext]);
	}
}
