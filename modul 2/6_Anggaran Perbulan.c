//Program Angsuran (Modul 2 no. 6)

#include <stdio.h>

int pkk_pinjaman=0;
int bunga_thn=0;
int lama_pinjam=0;
int bln;
int ang_pkk=0;
int bunga_bln=0;
int ang_bln=0;

int hitung_angpkk(int p, int t){ // p = pinjaman pokok, t = lama pinjaman
	int a = p / t; // a = angsuran pokok
	return a;
}

int hitung_bungabln(int p, int y, int a, int i){ // y = bulan ke sekian, a = angsuran pokok, i = bunga dalam setahun
	int b = ((p - ((y-1) * a)) * i * 0.01) / 12; // b = bunga per bulan	
	return b;
}

int hitung_angbln(int a, int b){ // a = angsuran pokok, b = bunga per bulan
	int c = a + b; // c = angsuran per bulan
	return c;
}

void input_pokok(){
	printf("=\n= Pokok Pinjaman        : ");
	pkk_pinjaman=validasi_pokok();
}

int validasi_pokok(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= INPUT PINJAMAN SALAH! PINJAMAN HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------------------\n");
		fflush(stdin);
		input_pokok();
	}else if(angka<=0){
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= INPUT PINJAMAN SALAH! MASUKKAN PINJAMAN YANG BENAR!\n");
		printf("=\n=-----------------------------------------------------------------------------\n");
		fflush(stdin);
		input_pokok();
	}else{
		return angka;
	}
}

void input_bunga(){
	printf("=\n= Besar Bunga (%%)       : ");
	bunga_thn=validasi_bunga();
}

int validasi_bunga(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= INPUT BUNGA SALAH! BUNGA HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------------------\n");
		fflush(stdin);
		input_bunga();
	}else if(angka<=0 || angka>100){
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= INPUT BUNGA SALAH! MASUKKAN BUNGA SESUAI RANGE (1-100)!\n");
		printf("=\n=-----------------------------------------------------------------------------\n");
		fflush(stdin);
		input_bunga();
	}else{
		return angka;
	}
}

void input_lamapinjam(){
	printf("=\n= Lama Pinjaman (bulan) : ");
	lama_pinjam=validasi_lama();
}

int validasi_lama(){
	int angka;
	char huruf;
	
	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n'){
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= INPUT LAMA PINJAMAN SALAH! LAMA PINJAMAN HARUS BERUPA ANGKA!\n");
		printf("=\n=-----------------------------------------------------------------------------\n");
		fflush(stdin);
		input_lamapinjam();
	}else if(angka<=0){
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= INPUT LAMA PINJAMAN SALAH! MASUKKAN LAMA PINJAMAN YANG BENAR!\n");
		printf("=\n=-----------------------------------------------------------------------------\n");
		fflush(stdin);
		input_lamapinjam();
	}else{
		return angka;
	}
}

void input(){
	input_pokok();
	input_bunga();
	input_lamapinjam();
}

void output(){
	int total_bunga=0;
	int total_ang=0;
	printf("=\n=-----------------------------------------------------------------------------\n");
	printf("=\n= Bulan          Bunga           Angsuran Pokok          Angsuran Per Bulan\n");
	for(bln = 1; bln <= lama_pinjam; bln++){
		ang_pkk = hitung_angpkk(pkk_pinjaman, lama_pinjam);
		bunga_bln = hitung_bungabln(pkk_pinjaman, bln, ang_pkk, bunga_thn);
		ang_bln = hitung_angbln(ang_pkk, bunga_bln);
	
		printf("=   %d          Rp. %d            Rp. %d                Rp. %d\n", bln, bunga_bln, ang_pkk, ang_bln);
		total_bunga = total_bunga + bunga_bln;
		total_ang = total_ang + ang_bln;
	}
	
	printf("=\n=\n= Total Bunga    : Rp. %d", total_bunga);
	printf("\n= Total Angsuran : Rp. %d\n", total_ang);
}

void nama_program(){
	printf("==============================================================================\n");
	printf("=                             PROGRAM  ANGSURAN                              =\n");
	printf("==============================================================================\n");
}

void keluar(){
	system("cls");
	printf("==============================================================================\n");
	printf("=                               TERIMA  KASIH                                =\n");
	printf("=                       TELAH MENGGUNAKAN PROGRAM INI                        =\n");
	printf("==============================================================================\n");
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

int main(){
	char pilihan;
	
	do{
		system("cls");
		nama_program();
		input();
		output();
		printf("=\n=-----------------------------------------------------------------------------\n");
		printf("=\n= Ingin mengulang program?\n");
		printf("=\n=    1. Ya     2. Tidak   \n");
		printf("=\n= Pilihan (1/2): ");
		pilihan = validasi_pilihan();
	}while(pilihan==1);
	
	keluar();
	
	return 0;
}
