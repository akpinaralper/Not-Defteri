#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOT_SAYISI 100
#define MAX_NOT_UZUNLUGU 500

// Not struct yapýsý
struct Not {
    int id;
    char metin[MAX_NOT_UZUNLUGU];
};

// Fonksiyon prototipleri
void notEkle(struct Not notlar[], int *notSayisi);
void notDuzenle(struct Not notlar[], int notSayisi);
void notSil(struct Not notlar[], int *notSayisi);
void notlariListele(struct Not notlar[], int notSayisi);

int main() {
    struct Not notlar[MAX_NOT_SAYISI];
    int notSayisi = 0;
    char secim;

    do {
        printf("\n--- Not Defteri ---\n");
        printf("1. Not Ekle\n");
        printf("2. Not Duzenle\n");
        printf("3. Not Sil\n");
        printf("4. Notlari Listele\n");
        printf("Q. Cikis\n");
        printf("Secim: ");
        scanf(" %c", &secim);

        switch (secim) {
            case '1':
                notEkle(notlar, &notSayisi);
                break;
            case '2':
                notDuzenle(notlar, notSayisi);
                break;
            case '3':
                notSil(notlar, &notSayisi);
                break;
            case '4':
                notlariListele(notlar, notSayisi);
                break;
            case 'Q':
            case 'q':
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }

    } while (secim != 'Q' && secim != 'q');

    return 0;
}

// Not eklemek için fonksiyon
void notEkle(struct Not notlar[], int *notSayisi) {
    if (*notSayisi < MAX_NOT_SAYISI) {
        struct Not yeniNot;
        printf("Notu girin (en fazla %d karakter): ", MAX_NOT_UZUNLUGU - 1);
        getchar();  // Önceki '\n' karakterini temizle
        fgets(yeniNot.metin, MAX_NOT_UZUNLUGU, stdin);

        yeniNot.id = *notSayisi + 1;
        notlar[*notSayisi] = yeniNot;
        (*notSayisi)++;

        printf("Not basariyla eklendi.\n");
    } else {
        printf("Not defteri dolu. Daha fazla not ekleyemezsiniz.\n");
    }
}

// Not düzenlemek için fonksiyon
void notDuzenle(struct Not notlar[], int notSayisi) {
    if (notSayisi > 0) {
        int id;
        printf("Duzenlemek istediginiz notun ID'sini girin: ");
        scanf("%d", &id);

        if (id > 0 && id <= notSayisi) {
            printf("Yeni notu girin (en fazla %d karakter): ", MAX_NOT_UZUNLUGU - 1);
            getchar();  // Önceki '\n' karakterini temizle
            fgets(notlar[id - 1].metin, MAX_NOT_UZUNLUGU, stdin);

            printf("Not basariyla duzenlendi.\n");
        } else {
            printf("Gecersiz ID. Lutfen tekrar deneyin.\n");
        }
    } else {
        printf("Not defteri bos. Duzenlenecek not yok.\n");
    }
}

// Not silmek için fonksiyon
void notSil(struct Not notlar[], int *notSayisi) {
	int i;
    if (*notSayisi > 0) {
        int id;
        printf("Silmek istediginiz notun ID'sini girin: ");
        scanf("%d", &id);

        if (id > 0 && id <= *notSayisi) {
            for ( i = id - 1; i < *notSayisi - 1; i++) {
                notlar[i] = notlar[i + 1];
            }

            (*notSayisi)--;
            printf("Not basariyla silindi.\n");
        } else {
            printf("Gecersiz ID. Lutfen tekrar deneyin.\n");
        }
    } else {
        printf("Not defteri bos. Silinecek not yok.\n");
    }
}

// Notlarý listelemek için fonksiyon
void notlariListele(struct Not notlar[], int notSayisi) {
	int i;
    if (notSayisi > 0) {
        printf("\n--- Notlar ---\n");
        for ( i = 0; i < notSayisi; i++) {
            printf("%d. Not:\n%s\n", notlar[i].id, notlar[i].metin);
        }
    } else {
        printf("Not defteri bos. Gosterilecek not yok.\n");
    }
}
