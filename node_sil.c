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

// �grenci adina g�re d�g�m� silen fonksiyon
void ogrenciSil(struct Ogrenci* baslangic, char silinecekIsim[50]) {
    struct Ogrenci* simdiki = baslangic;
    struct Ogrenci* onceki = NULL;
    
    while (simdiki != NULL) {
        if (strcmp(simdiki->isim, silinecekIsim) == 0) {
            if (onceki != NULL) {
                onceki->sonraki = simdiki->sonraki;
            } else {
                // Ilk d�g�m siliniyor
                baslangic = simdiki->sonraki;
            }
            free(simdiki);
            return;
        }
        onceki = simdiki;
        simdiki = simdiki->sonraki;
    }
    
    printf("Aranan �grenci bulunamadi, silme islemi ger�eklestirilmedi.\n");
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

    // �grenci silme
    char silinecekIsim[50];
    printf("Silinecek �grencinin adini girin: ");
    scanf("%s", silinecekIsim);
    ogrenciSil(baslangic, silinecekIsim);
    
    // G�ncellenmis liste �zerinde dolas ve yaz
    printf("G�ncellenmis �grenci Listesi:\n");
    listeDolasVeYaz(baslangic);

    return 0;
}
