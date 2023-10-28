
    
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
    // �grenci listesinin baslangici
    struct Ogrenci* baslangic = NULL;

    // �grenci eklemek i�in �rnek veriler
    baslangic = yeniOgrenciOlustur(201, "Saliha", 27, 1);
    baslangic->sonraki = yeniOgrenciOlustur(203, "Ece", 19, 2);
    baslangic->sonraki->sonraki = yeniOgrenciOlustur(205, "Abdurrahmangazi", 22, 3);

    // Liste �zerinde dolas ve yaz
    printf("T�m �grenciler:\n");
    listeDolasVeYaz(baslangic);

    // En uzun ismi bul
    enUzunIsmiBul(baslangic);

����return�0;
}

