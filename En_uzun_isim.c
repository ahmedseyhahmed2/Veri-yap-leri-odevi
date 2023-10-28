
    
    while (simdiki != NULL) {
        int uzunluk = strlen(simdiki->isim);
        if (uzunluk > enUzunUzunluk) {
            enUzunUzunluk = uzunluk;
            strcpy(enUzunIsim, simdiki->isim);
        }
        simdiki = simdiki->sonraki;
    }
    
    if (enUzunUzunluk > 0) {
        printf("Listedeki en uzun isim: %s\n", enUzunIsim);
        printf("Uzunluk: %d\n", enUzunUzunluk);
    } else {
        printf("Listede isim bulunamadi.\n");
    }
}

int main() {
    // Ögrenci listesinin baslangici
    struct Ogrenci* baslangic = NULL;

    // Ögrenci eklemek için örnek veriler
    baslangic = yeniOgrenciOlustur(201, "Saliha", 27, 1);
    baslangic->sonraki = yeniOgrenciOlustur(203, "Ece", 19, 2);
    baslangic->sonraki->sonraki = yeniOgrenciOlustur(205, "Abdurrahmangazi", 22, 3);

    // Liste üzerinde dolas ve yaz
    printf("Tüm Ögrenciler:\n");
    listeDolasVeYaz(baslangic);

    // En uzun ismi bul
    enUzunIsmiBul(baslangic);

    return 0;
}

