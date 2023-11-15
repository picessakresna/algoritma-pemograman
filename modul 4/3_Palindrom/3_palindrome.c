#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int i,total_huruf;
int jumlah_huruf[256];
char temp[1000];
char kata[1000];

int main(){
	printf(" ==================================================\n");
	printf(" ==================================================\n");
	printf("|                 PROGRAM PALINDROM                |\n");
	printf("|                   KELOMPOK 9                     |\n");
	printf(" ==================================================\n");
	printf("Masukan kata : ");
	gets(kata);
	total_huruf=0;
	clear();
	validasi_inputan();

}

void validasi_inputan(){
	int test=0;
	for(i=0;(i<1000&&kata[i]!='\0');i++){
		if(kata[i]>=65&&kata[i]<=90){
			jumlah_huruf[(int)(kata[i])]++;
			total_huruf++;
			test++;
			continue;
		}
		else if(kata[i]>=97&&kata[i]<=122){
			jumlah_huruf[(int)(kata[i])]++;
			total_huruf++;
			test++;
			continue;
		}
		else if(kata[i]==32){
			jumlah_huruf[(int)(kata[i])]++;
			total_huruf++;
			continue;
		}
		else{
            system("cls");
            printf("\n");
            printf("\t\t============= ERROR ===============\n");
			printf("\t\t=== Masukan Input Berupa Huruf! ===\n");
            printf("\t\t===================================\n\n");
			fflush(stdin);
			main();
			break;
		}
	}
	if(test==0){
    system("cls");
    printf("\t\t================= ERROR =================\n");
	printf("\t\t=== Kata Tidak Dikenali Oleh Program! ===\n");
    printf("\t\t=========================================\n\n");
	main();
	}
	else{
	result();
	}
}

int ispalindrom(){
	int j=0, k=0;
	strcpy(temp, kata);
	j = strlen(temp)-1;
	for(i=0;i<=j;i++){
		if(temp[k]==32){
			while(temp[k]==32){
			k++;
			}
		}
		if(temp[j]==32){
			while(temp[j]==32){
			j--;
			}
		}
		else{
			if(temp[k]==temp[j] || temp[k]==temp[j]-32 || temp[k]==temp[j]+32){
				j--;
				k++;
				continue;
			}else {
				return 0;
			}
		}
	}
	return 1;
}

void result(){
	int palindrom=0;
	FILE *kamus;
  	kamus = fopen("kamuskata.txt","a+");
  	printf("%s (%d)", kata, total_huruf);
  	fprintf(kamus, "%s (%d)", kata, total_huruf);
  	for(i=0;i<256;i++){
  		if(jumlah_huruf[i]!=0){
  			if(i==32){
  				printf(" %s=%d ","space", jumlah_huruf[i]);
  				fprintf(kamus," %s=%d ","space", jumlah_huruf[i]);
  				continue;
			  }
			printf(" %c=%d ", i, jumlah_huruf[i]);
			fprintf(kamus," %c=%d ", i, jumlah_huruf[i]);
		  }
	  }
	palindrom=ispalindrom();
	if(palindrom){
		printf("===>Palindrom\n");
		printf("kata telah ditambahkan ke kamuskata.txt");
		fprintf(kamus,"===>Palindrom\n");
	}else{
		printf("===>Bukan Palindrom\n");
		printf("kata telah ditambahkan ke kamuskata.txt");
		fprintf(kamus,"===>Bukan Palindrom\n");
	}
	fclose(kamus);
	ulang();
}

void clear(){
    for(i=0;i<256;i++){
        jumlah_huruf[i]=0;
    }
}

int clean(){
    while(getchar() != '\n');
    return 1;
}

void ulang(){
    char pilih, check;

    printf("\n\nApakah Anda Ingin Mengulang Program?\nMasukkan Y Untuk Mengulang dan N Untuk Menutup Program.");
          do{
              printf("\n(y/n): ");
              if(((scanf("%c%c", &pilih, &check)) != 2 || check != '\n') && clean()){
                   printf("Inputan salah! Tekan Y untuk mengulang dan N untuk menutup program.\n");
              } else {
                  if(pilih == 'Y' || pilih == 'y'){
                      system("cls");
                      main();
                  break;
                  } else if(pilih == 'N' || pilih == 'n') {
                      system("cls");
                      printf("\nTerimakasih, Sampai Bertemu Lagi");
                      exit(0);
                      break;
                 } else {
                   printf("\nInputan salah! Tekan Y untuk mengulang dan N untuk menutup program.\n");
                 }
             }
        } while(1);
}
