#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �grenci bilgilerini temsil eden yapi (struct)
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    int indeks;
    struct Ogrenci* sonraki;
};

// Yeni �grenci olusturmak i�in kullanilan fonksiyon
struct Ogrenci* yeniOgrenciOlustur(int numara, char isim[50], int yas, int indeks) {
    struct Ogrenci* yeni_ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeni_ogrenci->numara = numara;
    strcpy(yeni_ogrenci->isim, isim);
    yeni_ogrenci->yas = yas;
    yeni_ogrenci->indeks = indeks;
    yeni_ogrenci->sonraki = NULL;
    return yeni_ogrenci;
}

// Liste �zerinde dolasan ve ekrana yazan fonksiyon
void listeDolasVeYaz(struct Ogrenci* baslangic) {
    int indeks = 1;
    struct Ogrenci* simdiki = baslangic;
    
    while (simdiki != NULL) {
        printf("%d- %s %d %d\n", indeks, simdiki->isim, simdiki->yas, simdiki->indeks);
        indeks++;
        simdiki = simdiki->sonraki;
    }
}

// �grenci adina g�re kayit arama fonksiyonu
void ogrenciAra(struct Ogrenci* baslangic, char arananIsim[50]) {
    struct Ogrenci* simdiki = baslangic;
    int bulundu = 0;
    
    while (simdiki != NULL) {
        if (strcmp(simdiki->isim, arananIsim) == 0) {
            printf("%d- %s %d %d\n", simdiki->indeks, simdiki->isim, simdiki->yas, simdiki->numara);
            bulundu = 1;
        }
        simdiki = simdiki->sonraki;
    }
    
    if (!bulundu) {
        printf("Aranan �grenci bulunamadi.\n");
    }
}

int main() {
    // �grenci listesinin baslangici
    struct Ogrenci* baslangic = NULL;

    // �grenci eklemek i�in �rnek veriler
    baslangic = yeniOgrenciOlustur(201, "Saliha", 27, 1);
    baslangic->sonraki = yeniOgrenciOlustur(203, "Ece", 19, 2);
    baslangic->sonraki->sonraki = yeniOgrenciOlustur(205, "Ali", 22, 3);

    // Liste �zerinde dolas ve yaz
    printf("T�m �grenciler:\n");
    listeDolasVeYaz(baslangic);

    // �grenci arama
    char arananIsim[50];
    printf("Aranan �grencinin adini girin: ");
    scanf("%s", arananIsim);
    printf("Arama Sonu�lari:\n");
    ogrenciAra(baslangic, arananIsim);

    return 0;
}
