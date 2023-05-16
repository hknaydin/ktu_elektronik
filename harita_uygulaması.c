#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Coordinate;

int main() {
    Coordinate* magazeler = NULL;
    int magazaSayisi = 0;

    FILE* dosya = fopen("koordinatlar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya okunamadı.");
        return 1;
    }

    char satir[100];
    while (fgets(satir, sizeof(satir), dosya)) {
        if (satir[0] != '#') { // Yorum satırını atla
            magazaSayisi++;
            Coordinate* temp = realloc(magazeler, magazaSayisi * sizeof(Coordinate));
            if (temp == NULL) {
                printf("Bellek hatasi.");
                free(magazeler);
                fclose(dosya);
                return 1;
            }
            magazeler = temp;

            sscanf(satir, "%*d.magaza %f,%f", &magazeler[magazaSayisi - 1].x, &magazeler[magazaSayisi - 1].y);
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
        free(magazeler);
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
            float dx = magazeler[j].x - kullaniciKoordinat.x;
            float dy = magazeler[j].y - kullaniciKoordinat.y;
            float uzaklik = sqrt(dx * dx + dy * dy);
	    printf("%d.ci Uzaklik %.2f\n", i+1, uzaklik);
            if (uzaklik <= mesafeler[i]) {
                maksimumMagazaSayisi++;
            }
        }
        printf("Mesafe %.2f icin maksimum magaza sayisi: %d\n", mesafeler[i], maksimumMagazaSayisi);
    }

    free(magazeler);
    free(mesafeler);

return 0;
}
