#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Karsilastirma fonksiyonu
int compare(const void *a, const void *b) {
    return ((int)b - (int)a);
}

int main() {
    int sayilar[100];
    int i;

    // Rastgele 100 sayi üretimi
    for (i = 0; i < 100; i++) {
        sayilar[i] = rand() % 100; // 0 ile 99 arasinda rastgele sayilar üret
    }

    // Sayilari büyükten küçüge siralama
    qsort(sayilar, 100, sizeof(int), compare);

    // Siralanmis sayilari ekrana bastirma
    for (i = 0; i < 100; i++) {
        if (i != 0) {
            printf("->");
        }
        printf("%d", sayilar[i]);
    }

    return 0;
}
