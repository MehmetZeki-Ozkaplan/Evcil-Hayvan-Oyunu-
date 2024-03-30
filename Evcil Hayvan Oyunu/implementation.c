#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

//'Struct' yapısını kullanarak Evcil Hayvana ait "İsim,Tür,Enerji,Mutluluk ve Duygu Durumu" verilerini tanımladım .
typedef struct {
    char tur[50];
    char ad[50];
    int enerji;
    int mutluluk;
    char duygu[50];
} EvcilHayvan;

EvcilHayvan hayvanlar[100];
int hayvanSayisi = 0;

//Kullanıcı Tarafından Girilen Verileri içerisinde Tutacak olan 'evcil_veri.txt' dosyasını oluşturacak bir fonksiyon oluşturdum.
void dosyayaKaydet() {
    FILE *file = fopen("evcil_cikti.txt", "w");
    if (!file) {
        printf("Dosya acilamadi!\n");
        return;
    }
    int i;
    for (i = 0; i < hayvanSayisi; i++) {
        fprintf(file, "%s,%s,%d,%d,%s\n", hayvanlar[i].tur, hayvanlar[i].ad, hayvanlar[i].enerji, hayvanlar[i].mutluluk, hayvanlar[i].duygu);
    }
    
    fclose(file);
}
//Verileri içerisinde tutan 'evcil_veri.txt' dosyasının içeriğini okuyacak bir fonksiyon daha oluşturdum.
void dosyadanOku() {
    FILE *file = fopen("evcil_veri.txt", "r");
    if (!file) {
        printf("Dosya acilamadi!\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%d,%d\n", hayvanlar[hayvanSayisi].tur, hayvanlar[hayvanSayisi].ad, &hayvanlar[hayvanSayisi].enerji, &hayvanlar[hayvanSayisi].mutluluk) != EOF) {
        strcpy(hayvanlar[hayvanSayisi].duygu, "Mutlu");
        hayvanSayisi++;
    }
    fclose(file);
}
//kullanıcının seçimlerinden değişecek duygu durumlarını sürekli güncelleyecek bir fonksiyon tanımladım . 
void duyguGuncelle(int index) {
    if (hayvanlar[index].enerji < 5) {
        strcpy(hayvanlar[index].duygu, "Uyuyor");
    } else if (hayvanlar[index].enerji < 20 && hayvanlar[index].mutluluk < 20) {
        strcpy(hayvanlar[index].duygu, "Aç");
    } else if (hayvanlar[index].mutluluk < 10) {
        strcpy(hayvanlar[index].duygu, "Üzgün");
    } else {
        strcpy(hayvanlar[index].duygu, "Mutlu");
    }
}
//Kullanıcının oluşturduğu evcil hayvana ait bilgileri yeniden düzenlemesini sağlayacak fonksiyonum . (2)
void hayvaniGuncelle() {
    printf("Güncellemek istediğiniz Bilgileri Giriniz\n");
    printf("Tur: ");
    scanf("%s", hayvanlar[hayvanSayisi].tur);
    printf("Ad: ");
    scanf("%s", hayvanlar[hayvanSayisi].ad);
    hayvanlar[hayvanSayisi].enerji = 60;
    hayvanlar[hayvanSayisi].mutluluk = 60;
    strcpy(hayvanlar[hayvanSayisi].duygu, "Mutlu");
    hayvanSayisi++;
    }
//Enerji - Mutluluk değerlerinde değişiklik yaşanması durumunda 'duyguGuncelle()' fonksiyonu ile evcil hayvanın duygu durumunu güncel tuttum .    
//Evcil hayvanın beslenmesi ile enerji seviyesine +15, mutluluk seviyesine +10 puan ekleyecek fonksiyonum . (5)
void hayvanaYemekVer(int index) {
    hayvanlar[index].enerji += 15;
    hayvanlar[index].mutluluk += 10;
    duyguGuncelle(index);
}
//Evcil hayvana su verilmesi ile enerji seviyesine +5, mutluluk seviyesine +5 puan ekleyecek fonksiyonum . (6)
void hayvanaSuVer(int index) {
    hayvanlar[index].enerji += 5;
    hayvanlar[index].mutluluk += 5;
    duyguGuncelle(index);
}
//Evcil hayvanın oynatılması ile enerji seviyesine -15, mutluluk seviyesine +15 puan ekleyecek fonksiyonum . (7)
void hayvaniOyunOynat(int index) {
    hayvanlar[index].enerji -= 15;
    hayvanlar[index].mutluluk += 15;
    duyguGuncelle(index);
}
//Evcil hayvanın temizlenmesi ile enerji seviyesine -10, mutluluk seviyesine -5 puan ekleyecek fonksiyonum . (8)
void hayvaniTemizle(int index) {
    hayvanlar[index].enerji -= 10;
    hayvanlar[index].mutluluk -= 5;
    duyguGuncelle(index);
}
//Evcil hayvanın sevilmesi ile mutluluk seviyesine +5 puan ekleyecek fonksiyonum . (9)
void hayvaniSev(int index) {
    hayvanlar[index].mutluluk += 5;
    duyguGuncelle(index);
}
//Evcil hayvanın uyutulması ile enerji seviyesine +5 ekleyecek fonksiyonum . (10)
void hayvaniUyut(int index) {
    hayvanlar[index].enerji += 5;
    duyguGuncelle(index);
}
//Evcil hayvanın ödeüllendirilmesi ile mutluluk seviyesine +10 puan ekleyecek fonksiyonum . (11)
void hayvaniOdullendir(int index) {
    hayvanlar[index].mutluluk += 10;
    duyguGuncelle(index);
}
//Kullanıcıya görüntülenecek menünün fonksiyonunu oluşturup 'main.c' dosyamda çağırdım
//'menu' fonksiyonumda bir switchcase yapısı kullanarak içerisindekullanılabilecek 'seçim' değişkemi ile bir 'index' ve 'i' değişkeni oluşturup bunları switchcase yapısında kullandım . Ayrıca switchcase yapısında süreklilik sağlamak içinde bir while döngüsü kullandım .
void menu() {
    int secim, index,i;
    char ad[50];
    while (1) {
        //Kullanıcını beğenebileceği bir arayüz oluşturmak için biraz değişiklik yapmak durumunda kaldım .
        printf("|1. Evcil Hayvanınızı Ekleyin         |\n|2. Evcil hayvanınınızı Güncelleyin   |\n|3. Evcil Verinizi Silin              |\n|4. Evcil Hayvanlarınızı Listeleyin   |\n|5. Evcil hayvanınıza Yemek Verin     |\n|6. Evcil Hayvanınıza Su Verin        |\n|7. Evcil Hayvanınız ile Oyun Oynayın |\n|8. Evcil Hayvanınızı Temizleyin      |\n|9. Evcik Hayvanınızı Sevin           |\n|10.Evcil Hayvanınızı Uyutun          |\n|11.Evcil Hayvanınızı Ödüllendirin    |\n|12.İşlemleri Kaydet ve Cik           |\n______________________________________|\nSeçmek İstediğiniz İşlem Numarasını Giriniz: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:    // (1) Kullanıcıdan evcil hayvana ait olacak 'Tür' ve 'İsim' bilgilerini alıp kayıt oluşturuyorum .  
                printf("Tur: ");
                scanf("%s", hayvanlar[hayvanSayisi].tur);
                printf("Ad: ");
                scanf("%s", hayvanlar[hayvanSayisi].ad);
                hayvanlar[hayvanSayisi].enerji = 60;
                hayvanlar[hayvanSayisi].mutluluk = 60;
                strcpy(hayvanlar[hayvanSayisi].duygu, "Mutlu");
                hayvanSayisi++;
                break;
            case 2:  
                hayvaniGuncelle();
                return;    
            case 3:    // (3) Kullanıcıdan alınan verilerin tutulduğu "evcil_veri.txt" dosyasındaki verileri sildiriyorum bu fonksiyonda 
                remove("evcil_veri.txt");
                printf("Evcil Hayvan Silindi\n ");    
                break;
            case 4:  // (4) Kullanıcıdan alınan verilerin tutulduğu "evcil_veri.txt" dosyasındaki verileri Kullanıcı karşısına getirtiyorum .
                for (i = 0; i < hayvanSayisi; i++) {
                    printf("%d. %s, %s, Enerji: %d, Mutluluk: %d, Duygu: %s\n\n", i + 1, hayvanlar[i].tur, hayvanlar[i].ad, hayvanlar[i].enerji, hayvanlar[i].mutluluk, hayvanlar[i].duygu);
                }
                break;
            case 5:
                printf("Hangi hayvana yemek vermek istersiniz? (Ad): ");
                scanf("%s", ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvanaYemekVer(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;
            case 6:
                printf("Hangi Hayvanınıza Su vermek İstersiniz (Ad): ?");
                scanf("%s",ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvanaSuVer(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;    
            case 7:
                printf("Hangi hayvanla oyun oynamak istersiniz? (Ad): ");
                scanf("%s", ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvaniOyunOynat(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;
            case 8:
                printf("Hangi hayvanı temizlemek istersiniz? (Ad): ");
                scanf("%s", ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvaniTemizle(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;
            case 9:
                printf("Hangi hayvanı sevmek istersiniz? (Ad): ");
                scanf("%s", ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvaniSev(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;
            case 10:
                printf("Hangi hayvanı uyutmak istersiniz? (Ad): ");
                scanf("%s", ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvaniUyut(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;
            case 11:
                printf("Hangi hayvanı Ödüllendirmek istersiniz? (Ad): ");
                scanf("%s", ad);
                index = -1;
                for (i = 0; i < hayvanSayisi; i++) {
                    if (strcmp(hayvanlar[i].ad, ad) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    hayvaniOdullendir(index);
                } else {
                    printf("Hayvan bulunamadi!\a\n");
                }
                break;
            case 12:   // (12) Kullanıcıdan alınan verileri "evcil_veri.txr" dosyasına kaydedip programdan çıkarıyorum .
                dosyayaKaydet();
                return;
            default:
                printf("Gecersiz secim! Lütfen Seçeneklerden Birini seçiniz \a \n");
                break;
                
                
            }
        }
    }   