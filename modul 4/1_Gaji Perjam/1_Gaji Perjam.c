//Program Gaji Perjam (Modul 4 no. 1)

#include <stdio.h>

struct input_data{
	int jam_kerja, jam_wajib, gaji_jam;
} data;

struct output_hitung{
	int jam_lembur, gaji_pokok, gaji_lembur, total_gaji;
} hitung;

void nama_program(){
	printf("==================================================================\n");
	printf("=                     PROGRAM  GAJI  PERJAM                      =\n");
	printf("==================================================================\n");
}

float validasi_jamkerja(){
    float angka;
    char huruf;
    if (scanf("%f%c",&angka,&huruf)!= 2  || huruf != '\n' || huruf == ','){
        printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! JAM KERJA HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input();
    }else if(angka<=0 || angka>24){
		printf("=\n=-----------------------------------------------------------------\n");
		printf("=\n= INPUT SALAH! MASUKKAN JAM KERJA SESUAI RANGE (1-24)!\n");
		printf("=\n=-----------------------------------------------------------------\n");
		fflush(stdin);
		input();
	}else{
        return angka;
    }
}

void input(){
	printf("=\n= Jam kerja hari ini : ");
	data.jam_kerja=validasi_jamkerja();
	
	hitung_gajiharian();
}

int hitung_gajiharian(){
	data.jam_wajib = 8;
	data.gaji_jam = 10625;
	
	hitung.gaji_pokok = data.jam_wajib * data.gaji_jam;
	hitung.jam_lembur = data.jam_kerja - data.jam_wajib;
	if(hitung.jam_lembur!=0){
		hitung.gaji_lembur = hitung.jam_lembur * hitung.gaji_pokok;
	}else{
		hitung.gaji_lembur = 0;
	}
	
	hitung.total_gaji = hitung.gaji_pokok + hitung.gaji_lembur;
}

void output(){
	system("cls");
	nama_program();
	printf("=\n= Jam kerja         : %d jam\n", data.jam_kerja);
	printf("=\n= Jam lembur        : %d jam\n", hitung.jam_lembur);
	printf("=\n= Gaji pokok        : Rp %d\n", hitung.gaji_pokok);
	printf("=\n= Gaji lembur       : Rp %d\n", hitung.gaji_lembur);
	printf("=\n= Total gaji harian : Rp %d\n", hitung.total_gaji);
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

void menu_utama(){
	int pilihan;
	
	do{
		system("cls");
		nama_program();
		input();
		output();
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
