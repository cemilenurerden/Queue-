#include <stdio.h>
#include <stdlib.h>

struct dugum {  //dugumu temsil eden struct yapýsý tanýmladým
    int veri;
    struct dugum* sonraki;
};

struct Queue {   // kuyrugu temsil eden struct yapýsýný tanýmladým
    struct dugum *on, *arka;  //kuyruk basi ve sonu olan dugum isaretcilerini tanýmladým
};

struct Queue* kuyrukOlustur() { //yeni kuyruk olusturmak icin kullandým
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); //Bellekten bir Queue yapýsý ayýrdým  baþlangýçta baþ ve son düðüm iþaretçileri NULL olarak ayarlanýr.
    queue->on = queue->arka = NULL;  //
    return queue;
}

void siraAl(struct Queue* queue, int veri) {  // Kuyruða bir eleman eklemek için kullandým bu yapýyý
    struct dugum* yeni_dugum = (struct dugum*)malloc(sizeof(struct dugum)); //Ýþlev, veriyi yeni bir düðüm oluþturarak alýr ve düðümü kuyruðun sonuna ekler.
    yeni_dugum->veri = veri;
    yeni_dugum->sonraki = NULL;
    if (queue->arka == NULL) {  //Eðer kuyruk boþsa, baþ ve son düðüm iþaretçileri yeni düðümü gösterir. Aksi takdirde, son düðümün "sonraki" iþaretçisi yeni düðümü iþaret eder ve son düðüm olarak güncellenir.
        queue->on = queue->arka = yeni_dugum;
    } else {
        queue->arka->sonraki = yeni_dugum;
        queue->arka = yeni_dugum;
    }
    printf("Deger eklendi.\n");
}

void kuyruktanCikar(struct Queue* queue) {  // Kuyruktan bir eleman silmek için kullandým bu fonksiyonu . baþ düðümünü kuyruktan çýkarýr ve baþ düðümünün bir sonraki düðümünü baþ düðümü olarak günceller.
    if (queue->on == NULL) {  //Eðer kuyruk boþsa, bir mesaj yazdýrýlýr
        printf("Kuyruk boþ!\n");
        return;
    }
    struct dugum* gecici = queue->on;
    queue->on = queue->on->sonraki;
    if (queue->on == NULL) {
        queue->arka = NULL;
    }
    printf("Silinen deger: %d\n", gecici->veri);
    free(gecici);
}

void goruntule(struct Queue* queue) { // Kuyruðun içeriðini görüntülemek için kullandým. baþ düðümünden baþlayarak her düðümün verisini yazdýrýr ve son düðüme kadar devam eder.
    if (queue->on == NULL) {
        printf("Kuyruk bos!\n");
        return;
    }
    struct dugum* simdiki = queue->on;
    while (simdiki != NULL) {
        printf("%d ", simdiki->veri);
        simdiki = simdiki->sonraki;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = kuyrukOlustur();

    int secim, veri;
    while (1) {
        printf("1. Ekle\n");
        printf("2. Sil\n");
        printf("3. Goruntule\n");
        printf("4. cikis\n");
        printf("Bir secenek girin: ");
        scanf("%d", &secim);

        switch (secim) {  // kosul yapýsý kullanarak 4 secenekten birisini secme islemi yaptým
            case 1:
                printf("Eklenecek degeri girin: ");
                scanf("%d", &veri);
                siraAl(queue, veri); //fonksiyonu cagýrdým
                break;

            case 2:
                kuyruktanCikar(queue);//fonksiyonu cagýrdým
                break;

            case 3:
                goruntule(queue);//fonksiyonu cagýrdým
                break;

            case 4:
                exit(0);

            default:
                printf("Gecersiz secenek!\n");
                break;
        }
    }

    return 0;
}

