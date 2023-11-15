//Program Zodiak (Modul 2 no. 1)

#include <stdio.h>
#include <string.h>

int tanggal=0;
int bulan_in=0;
char *bulan_out;
int tahun=0;
char *range_tgl;

void nama_program(){
	printf("==================================================================\n");
	printf("=                        PROGRAM  ZODIAK                         =\n");
	printf("==================================================================\n");
}

void pilih_zodiak(int tgl, int bln, int thn){
	char *zodiak;
	
	if(bln==3 && tgl>=21 || bln==4 && tgl<=19){
		zodiak = "Aries";
	}else if(bln==4 && tgl>=20 || bln==5 && tgl<=20){
		zodiak = "Taurus";
	}else if(bln==5 && tgl>=21 || bln==6 && tgl<=20){
		zodiak = "Gemini";
	}else if(bln==6 && tgl>=21 || bln==7 && tgl<=22){
		zodiak = "Cancer";
	}else if(bln==7 && tgl>=23 || bln==8 && tgl<=22){
		zodiak = "Leo";
	}else if(bln==8 && tgl>=23 || bln==9 && tgl<=22){
		zodiak = "Virgo";
	}else if(bln==9 && tgl>=23 || bln==10 && tgl<=22){
		zodiak = "Libra";
	}else if(bln==10 && tgl>=23 || bln==11 && tgl<=21){
		zodiak = "Scorpio";
	}else if(bln==11 && tgl>=22 || bln==12 && tgl<=21){
		zodiak = "Sagitarius";
	}else if(bln==12 && tgl>=22 || bln==1 && tgl<=19){
		zodiak = "Capricorn";
	}else if(bln==1 && tgl>=20 || bln==2 && tgl<=18){
		zodiak = "Aquarius";
	}else if(bln==2 && tgl>=19 || bln==3 && tgl<=20){
		zodiak = "Pisces";
	}
	system("cls");
	nama_program();
	printf("=\n= Tanggal lahir : %d %s %d\n", tgl, bulan_out, thn);
	printf("=\n= Zodiak Anda adalah %s\n", zodiak);
}

void input_tahun(){
	printf("=\n= Masukkan tahun lahir          : ");
	tahun=validasi_tahun();
}

int validasi_tahun(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! TAHUN HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input_tahun();
	}else if(angka<=0){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! MASUKKAN TAHUN YANG BENAR!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input_tahun();
	}else{
		return angka;
	}
}
/*
void cek_tahun(int thn){
	if((thn%4==0 && thn%100!=0) || (thn%4==0 && thn%100==0 && thn%400==0)){
		range_tgl="(1-29)";
	}else{
		range_tgl="(1-28)";
	}
}*/

void input_bulan(){
	printf("=\n= Masukkan bulan lahir (1-12)   : ");
	bulan_in=validasi_bulan();
}

int validasi_bulan(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! BULAN HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input_bulan();
	}else if(angka<=0 || angka>12){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! MASUKKAN BULAN SESUAI RANGE!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input_bulan();
	}else{
		return angka;
	}
}

void input_tanggal(int bln, int thn){	
	if(bln==2){
		if((thn%4==0 && thn%100!=0) || (thn%4==0 && thn%100==0 && thn%400==0)){
			range_tgl="(1-29)";
		}else{
			range_tgl="(1-28)";
		}
	}else if(bln==1 || bln==3 || bln==5 || bln == 7 || bln == 8 || bln == 10 || bln == 12){
		range_tgl="(1-31)";
	}else{
		range_tgl="(1-30)";
	}
	
	printf("=\n= Masukkan tanggal lahir %s : ", range_tgl);
	tanggal=validasi_tanggal();
}

int validasi_tanggal(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! TANGGAL HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input_tanggal(bulan_in, tahun);
	}else if(bulan_in==1 || bulan_in==3 || bulan_in==5 || bulan_in==7 || bulan_in==8 || bulan_in==10 || bulan_in==12){
		if(angka<=0 || angka>31){
			printf("=\n=-----------------------------------------------------------------\n");
			printf("=\n= INPUT SALAH! MASUKKAN TANGGAL SESUAI RANGE!\n");
			printf("=\n=-----------------------------------------------------------------\n");
			fflush(stdin);
			input_tanggal(bulan_in, tahun);
		}else{
			return angka;
		}
	}else if(bulan_in==4 || bulan_in==6 || bulan_in==9 || bulan_in==11){
		if(angka<=0 || angka>30){
			printf("=\n=-----------------------------------------------------------------\n");
			printf("=\n= INPUT SALAH! MASUKKAN TANGGAL SESUAI RANGE!\n");
			printf("=\n=-----------------------------------------------------------------\n");
			fflush(stdin);
			input_tanggal(bulan_in, tahun);
		}else{
			return angka;
		}
	}else if(bulan_in==2){
		if((tahun%4==0 && tahun%100!=0) || (tahun%4==0 && tahun%100==0 && tahun%400==0)){
			if(angka<=0 || angka>29){
				printf("=\n=-----------------------------------------------------------------\n");
				printf("=\n= INPUT SALAH! MASUKKAN TANGGAL SESUAI RANGE!\n");
				printf("=\n=-----------------------------------------------------------------\n");
				fflush(stdin);
				input_tanggal(bulan_in, tahun);
			}else{
				return angka;
			}
		}else{
			if(angka<=0 || angka>28){
				printf("=\n=-----------------------------------------------------------------\n");
				printf("=\n= INPUT SALAH! MASUKKAN TANGGAL SESUAI RANGE!\n");
				printf("=\n=-----------------------------------------------------------------\n");
				fflush(stdin);
				input_tanggal(bulan_in, tahun);
			}else{
				return angka;
			}
		}
	}else{
		return angka;
	}
}

int validasi_pilihan(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! PILIHAN HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		validasi_pilihan();
	}else if(angka<=0 || angka>2){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! MASUKKAN PILIHAN SESUAI OPSI!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		validasi_pilihan();
	}else{
		return angka;
	}
}

void cek_tgllahir(int tgl, int bln, int thn){
	int pil;
	
	if(bln==1){
		bulan_out="Januari";
	}else if(bln==2){
		bulan_out="Februari";
	}else if(bln==3){
		bulan_out="Maret";
	}else if(bln==4){
		bulan_out="April";
	}else if(bln==5){
		bulan_out="Mei";
	}else if(bln==6){
		bulan_out="Juni";
	}else if(bln==7){
		bulan_out="Juli";
	}else if(bln==8){
		bulan_out="Agustus";
	}else if(bln==9){
		bulan_out="September";
	}else if(bln==10){
		bulan_out="Oktober";
	}else if(bln==11){
		bulan_out="November";
	}else if(bln==12){
		bulan_out="Desember";
	}
	printf("=\n=-----------------------------------------------------------------\n");
	printf("=-----------------------------------------------------------------\n");
	printf("=\n= Tanggal lahir : %d %s %d\n", tgl, bulan_out, thn);
	printf("=\n=-----------------------------------------------------------------\n");
	printf("=\n= Apakah tanggal lahir sudah benar?\n");
	printf("=\n=        1. Ya      2. Tidak       \n");
	printf("=\n= Pilihan (1/2): ");
	pil = validasi_pilihan();
	
	while(pil == 2 || pil == 2){
		menu_utama();
	}
	
	pilih_zodiak(tanggal, bulan_in, tahun);
}

void menu_utama(){
	int pilihan;
	
	do{
		system("cls");
		nama_program();
		input_tahun();
		input_bulan();
		input_tanggal(bulan_in, tahun);
		cek_tgllahir(tanggal, bulan_in, tahun);
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= Ingin mengulang program?\n");
		printf("=\n=    1. Ya     2. Tidak   \n");
		printf("=\n= Pilihan (1/2): ");
		pilihan = validasi_pilihan();
	}while(pilihan == 1);
}

void keluar(){
	system("cls");
	printf("==================================================================\n");
	printf("=                         TERIMA  KASIH                          =\n");
	printf("=                 TELAH MENGGUNAKAN PROGRAM INI                  =\n");
	printf("==================================================================\n");
}

int main(){
	menu_utama();
	keluar();	
	return 0;
}
