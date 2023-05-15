#include <stdio.h>
#include <stdlib.h>

struct dugum {  //dugumu temsil eden struct yap�s� tan�mlad�m
    int veri;
    struct dugum* sonraki;
};

struct Queue {   // kuyrugu temsil eden struct yap�s�n� tan�mlad�m
    struct dugum *on, *arka;  //kuyruk basi ve sonu olan dugum isaretcilerini tan�mlad�m
};

struct Queue* kuyrukOlustur() { //yeni kuyruk olusturmak icin kulland�m
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); //Bellekten bir Queue yap�s� ay�rd�m  ba�lang��ta ba� ve son d���m i�aret�ileri NULL olarak ayarlan�r.
    queue->on = queue->arka = NULL;  //
    return queue;
}

void siraAl(struct Queue* queue, int veri) {  // Kuyru�a bir eleman eklemek i�in kulland�m bu yap�y�
    struct dugum* yeni_dugum = (struct dugum*)malloc(sizeof(struct dugum)); //��lev, veriyi yeni bir d���m olu�turarak al�r ve d���m� kuyru�un sonuna ekler.
    yeni_dugum->veri = veri;
    yeni_dugum->sonraki = NULL;
    if (queue->arka == NULL) {  //E�er kuyruk bo�sa, ba� ve son d���m i�aret�ileri yeni d���m� g�sterir. Aksi takdirde, son d���m�n "sonraki" i�aret�isi yeni d���m� i�aret eder ve son d���m olarak g�ncellenir.
        queue->on = queue->arka = yeni_dugum;
    } else {
        queue->arka->sonraki = yeni_dugum;
        queue->arka = yeni_dugum;
    }
    printf("Deger eklendi.\n");
}

void kuyruktanCikar(struct Queue* queue) {  // Kuyruktan bir eleman silmek i�in kulland�m bu fonksiyonu . ba� d���m�n� kuyruktan ��kar�r ve ba� d���m�n�n bir sonraki d���m�n� ba� d���m� olarak g�nceller.
    if (queue->on == NULL) {  //E�er kuyruk bo�sa, bir mesaj yazd�r�l�r
        printf("Kuyruk bo�!\n");
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

void goruntule(struct Queue* queue) { // Kuyru�un i�eri�ini g�r�nt�lemek i�in kulland�m. ba� d���m�nden ba�layarak her d���m�n verisini yazd�r�r ve son d���me kadar devam eder.
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

        switch (secim) {  // kosul yap�s� kullanarak 4 secenekten birisini secme islemi yapt�m
            case 1:
                printf("Eklenecek degeri girin: ");
                scanf("%d", &veri);
                siraAl(queue, veri); //fonksiyonu cag�rd�m
                break;

            case 2:
                kuyruktanCikar(queue);//fonksiyonu cag�rd�m
                break;

            case 3:
                goruntule(queue);//fonksiyonu cag�rd�m
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

