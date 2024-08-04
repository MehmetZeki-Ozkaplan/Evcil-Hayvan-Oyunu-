#include <stdio.h>
#include "interface.h"
//Arayüze ait fonksiyonları tanımladığım 'interface.h' dosyasını çağırdım.
int main() {
    //Kullanıcıyı karşılayacak olan arayüze ait fonksiyonları 'main' fonksiyonumda çağırdım .
    system("COLOR 6");
    //Arayüze ait Görsel renk atadım.,Programın başlığını atadım
    printf("-----EVCİL HAYVAN YETİŞTİRME OYUNU-----\n");
    menu();
    dosyadanOku();
    //Arayüze ait 'menu've 'dosyadanOku' dosyası ile arayüzde menüyü ve dosyayı getirtim
return 0;
}

