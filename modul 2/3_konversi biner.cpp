#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=====================================================================
//  DEKLARASI PROSEDUR
void menu();
void konversiBiner();
void konversiDesimal();

//=====================================================================
//  VALIDASI
int validasiPilihan()
{
    int i = 0;
    int salah = 0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array = strlen(angka);

    for (i = 0; i < array; i++)
    {
        if (angka[i] >= 48 && angka[i] <= 57)
        { // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"
        }
        else
        {
            salah += 1;
        }
    }

    if (salah > 0)
    {
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        validasiPilihan();
    }
    else
    {
        val = atoi(angka);
        if (val >= 1 && val <= 3)
        {
            return val;
        }
        else
        {
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            validasiPilihan();
        }
    }
}

int inputBilangan()
{
    int i = 0;
    int salah = 0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array = strlen(angka);

    for (i = 0; i < array; i++)
    {
        if (angka[i] >= 48 && angka[i] <= 57)
        { // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"
        }
        else
        {
            salah += 1;
        }
    }

    if (salah > 0)
    {
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        inputBilangan();
    }
    else
    {
        val = atoi(angka);
        return val;
    }
}

int inputBiner()
{
    int i = 0;
    int salah = 0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array = strlen(angka);

    if (strlen(angka) > 10)
    {
        salah += 1;
    }

    for (i = 0; i < array; i++)
    {
        if (angka[i] >= 48 && angka[i] <= 49)
        { // PEMBATAS PADA ASCII DIMANA 48-49 BERNILAI "0-1"
        }
        else
        {
            salah += 1;
        }
    }

    if (salah > 0)
    {
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        inputBiner();
    }
    else
    {
        val = atoi(angka);
        return val;
    }
}

//=====================================================================
// MAIN
int main()
{
    system("COLOR F0");
    menu();
    system("pause");
    return 0;
}

//=====================================================================
// MENU
void menu()
{
    int pilih;

    printf("===================================================\n\n");
    printf("             PROGRAM KONVERSI BILANGAN             \n");
    printf("                  DESIMAL & BINER                  \n\n");
    printf("===================================================\n\n");
    printf("\t1. Mengkonversi Bilangan Desimal ke Biner\n");
    printf("\t2. Mengkonversi Bilangan Biner ke Desimal\n");
    printf("\t3. Keluar                                \n");
    printf("---------------------------------------------------\n");
    printf("Masukkan Pilihan: ");
    pilih = validasiPilihan();
    system("cls");

    switch (pilih)
    {
    case 1:
        konversiBiner();
        break;
    case 2:
        konversiDesimal();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Program error terdeteksi\n");
        break;
    }
}

void konversiBiner()
{
    int pilih;
    int angka, sisa, biner, basis;
    int desimal;

    printf("===================================================\n\n");
    printf("             PROGRAM KONVERSI BILANGAN             \n");
    printf("                  DESIMAL & BINER                  \n\n");
    printf("---------------------------------------------------\n");
    printf("             KONVERSI DESIMAL KE BINER             \n");
    printf("===================================================\n\n");
    printf("Mengkonversi Bilangan Desimal Ke Bilangan Biner\n");
    printf("Masukkan Angka: ");
    angka = inputBilangan();

    biner = 0;
    basis = 1;
    while (angka != 0)
    {
        sisa = angka % 2;
        biner = biner + sisa * basis;
        angka = angka / 2;
        basis = basis * 10;
    }
    printf("\nHasil konversi bilangan diatas adalah %d\n", biner);

    printf("\n===================================================\n");
    printf("     1.Ulangi      2.Kembali       3.Exit\n");
    printf("---------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilih = validasiPilihan();
    system("cls");

    switch (pilih)
    {
    case 1:
        konversiBiner();
        break;
    case 2:
        menu();
        break;
    default:
        exit(0);
        break;
    }
}

void konversiDesimal()
{
    int pilih;
    int angka, sisa, biner, basis;
    int desimal;

    printf("===================================================\n\n");
    printf("             PROGRAM KONVERSI BILANGAN             \n");
    printf("                  DESIMAL & BINER                  \n\n");
    printf("---------------------------------------------------\n");
    printf("             KONVERSI BINER KE DESIMAL             \n");
    printf("===================================================\n\n");

    printf("Mengkonversi Bilangan Biner ke Bilangan Desimal\n");
    printf("Masukkan Bilangan Biner: ");
    biner = inputBiner();
    desimal = 0;
    basis = 1;
    while (biner != 0)
    {
        sisa = biner % 10;
        desimal = desimal + sisa * basis;
        biner = biner / 10;
        basis = basis * 2;
    }
    printf("\nHasil konversi bilangan diatas adalah %d\n", desimal);

    printf("\n===================================================\n");
    printf("     1.Ulangi      2.Kembali       3.Exit\n");
    printf("---------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilih = validasiPilihan();
    system("cls");

    switch (pilih)
    {
    case 1:
        konversiDesimal();
        break;
    case 2:
        menu();
        break;
    default:
        exit(0);
        break;
    }
}

Deklarasi
    Len = int
        Sum = inti = int
            bilangan = int
                p = char
                    p = malloc(sizeof(char) * (4));
len = 0 i = 1 sum = 0 Deskripsi
    Read bilangan do
{
    scanf(“% c”, &p[len])
        len++
}
while (p[len -
         1] != ‘

       n’)
    p[len -
      1] = ‘

        0’;
int count = len - 2;
for (i = 0; i < len - 1; i++)
{
    if (p[i] == ‘1’ || p[i] == ‘0’)
    {
        continue;
    }
    else
    {
        Print(“Bilangan tidak valid !”) return
    }
}
for (i = 0; i < len; i++)
{
    if (p[i] == ‘1’)
    {
        sum = sum + pow(2, count)
    }
    count
 —
}
Print(hasil(sum));