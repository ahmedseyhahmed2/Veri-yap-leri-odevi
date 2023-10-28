#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ögrenci bilgilerini temsil eden yapi (struct)
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    int indeks;
    struct Ogrenci* sonraki;
};

// Yeni ögrenci olusturmak için kullanilan fonksiyon
struct Ogrenci* yeniOgrenciOlustur(int numara, char isim[50], int yas, int indeks) {
    struct Ogrenci* yeni_ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeni_ogrenci->numara = numara;
    strcpy(yeni_ogrenci->isim, isim);
    yeni_ogrenci->yas = yas;
    yeni_ogrenci->indeks = indeks;
    yeni_ogrenci->sonraki = NULL;
    return yeni_ogrenci;
}

// Liste üzerinde dolasan ve ekrana yazan fonksiyon
void listeDolasVeYaz(struct Ogrenci* baslangic) {
    int indeks = 1;
    struct Ogrenci* simdiki = baslangic;
    
    while (simdiki != NULL) {
        printf("%d- %s %d %d\n", indeks, simdiki->isim, simdiki->yas, simdiki->indeks);
        indeks++;
        simdiki = simdiki->sonraki;
    }
}

int main() {
    // Ögrenci listesinin baslangici
    struct Ogrenci* baslangic = NULL;

    // Ögrenci eklemek için örnek veriler
    baslangic = yeniOgrenciOlustur(201, "Saliha", 27, 1);
    baslangic->sonraki = yeniOgrenciOlustur(203, "Ece", 19, 2);

    // Liste üzerinde dolas ve yaz
    listeDolasVeYaz(baslangic);

    return 0;
}
