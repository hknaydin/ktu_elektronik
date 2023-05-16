#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MAGAZA_ 1000
typedef struct {
    float x;
    float y;
} Coordinate;

int main() {
    Coordinate* magazalar = NULL;
    int magazaSayisi = 0;

    FILE* dosya = fopen("koordinatlar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya okunamadı.");
        return 1;
    }

    char satir[MAX_MAGAZA_];
    while (fgets(satir, sizeof(satir), dosya)) {
        if (satir[0] != '#') { // Yorum satırını atla
            magazaSayisi++;
            Coordinate* temp = realloc(magazalar, magazaSayisi * sizeof(Coordinate));
            if (temp == NULL) {
                printf("Bellek hatasi.");
                free(magazalar);
                fclose(dosya);
                return 1;
            }
            magazalar = temp;

            sscanf(satir, "%*d.magaza %f,%f", &magazalar[magazaSayisi - 1].x, &magazalar[magazaSayisi - 1].y);
        }
    }

    fclose(dosya);

    // Kullanıcıdan kendi koordinatlarını giriş alınması
    Coordinate kullaniciKoordinat;
    printf("Kullanici koordinatini girin (x,y): \n");
    printf("x koordinati:");
    scanf("%f", &kullaniciKoordinat.x);
    printf("y koordinati:");
    scanf("%f", &kullaniciKoordinat.y);
    // Kullanıcıdan mesafe sayısı girişi alınması
    int mesafeSayisi;
    printf("Kac adet mesafe gireceksiniz? ");
    scanf("%d", &mesafeSayisi);

    // Kullanıcıdan mesafeleri giriş alınması
    float* mesafeler = malloc(mesafeSayisi * sizeof(float));
    if (mesafeler == NULL) {
        printf("Bellek hatasi.");
        free(magazalar);
        return 1;
    }

    for (int i = 0; i < mesafeSayisi; i++) {
        printf("Mesafe %d: ", i + 1);
        scanf("%f", &mesafeler[i]);
    }

    // Her bir mesafe için maksimum mağaza sayısının bulunması
    for (int i = 0; i < mesafeSayisi; i++) {
        int maksimumMagazaSayisi = 0;
        for (int j = 0; j < magazaSayisi; j++) {
            float dx = magazalar[j].x - kullaniciKoordinat.x;
            float dy = magazalar[j].y - kullaniciKoordinat.y;
            float uzaklik = sqrt(dx * dx + dy * dy);
	    printf("%d.ci Uzaklik %.2f\n", i+1, uzaklik);
            if (uzaklik <= mesafeler[i]) {
                maksimumMagazaSayisi++;
            }
        }
        printf("Mesafe %.2f icin maksimum magaza sayisi: %d\n", mesafeler[i], maksimumMagazaSayisi);
    }

    free(magazalar);
    free(mesafeler);

return 0;
}
