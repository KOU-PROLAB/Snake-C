#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//Yılan struct yapısıyla yapıldı, şnkı yılanın parçalarına ulaşmak kolay oluyor ve büyüme layını bu şekilde sağlayabileceğimi düşündüm.
struct yilan {
    int satir;  //Yılanın bir biriminin satırını tutan yer.
    int sutun;  //Yılanın bir biriminin sıtununu tutan yer.
    struct yilan *sonraki;  //Yılanın en son kısmından baş kısmına doğru ilerlememizi sağlayan pointer.
};

//ilerleme işlemini bu foksiyonla sağladım
//struct yilan* tipinde bir fonsiyon bunun sebebi yılan büyüdüğü zaman yeni bir struct oluşturup yeni bir başlangı pointer elde ediyor olmamız.

struct yilan* ilerle(struct yilan *r, int yon, int *boy, int sayac, int *bas)

//Parametler ve açıklamaları:
//struct yilan *r=bu parametre yılanın en son birimini gsteren pointer bu değerden başlayıp baş ksımına gelinceye kadar ilerliyeceiz.
//int yon=bu parametre ile yılanın gideceği yne göre ilerleme kaydetmesini sağlıyor.
//int *boy=yılanın boyunun saklandığı yeri gsteren bi pointer, pointer olma sebebi eğer yılan büyüyorsa boyunu bellekteki gsterdiği yere erişerek değiştirmek.
//int sayac=bu değişkenin değeri main fonksiyonunda kontrol edilıyor ve haritadaki yem sayısını gsteriyor,eğer yem sayısı '0' ise yılan yemi yemiş yani büyümesi gerek demek.
//int *bas=iki boyutlu bir dizinin pointerı, burda pointer kullanılma sebebi ise yılanın baının kordinatlarını ayrı bir değişkende saklamak
{
    int i;
    struct yilan *gecici = r; //Default değeri olarak yılanın en son birimini gsteren pointer'ı atıyoruz.
    if(sayac == 1) { //Yani yem mevcutsa bir başka deyişle yılan yemi yememişse
        switch(yon) {
        case 1:   //Yani 'W' tuşuna basıldıysa yukarı yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim yukarı gidiyorsa bu satırın bir birim eksilmesi demek.
            r->satir = r->satir - 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;
            //Geçici pointerı hiç bir değişikliye uğramadığı işin mevcut yılanın en son birimini gsterir.
            return gecici;
            break;
        case 2:   //Yani 'D' tuşuna basıldıysa sağ yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim sağa gidiyorsa bu sıtunun bir birim artması demek.
            r->sutun = r->sutun + 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;
            //Geçici pointerı hiç bir değişikliye uğramadığı işin mevcut yılanın en son birimini gsterir.
            return gecici;
            break;
        case 3:    //Yani 'S' tuşuna basıldıysa aşağı yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim aşağı gidiyorsa bu satırın bir birim artması demek.
            r->satir = r->satir + 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;
            //Geçici pointerı hiç bir değişikliye uğramadığı işin mevcut yılanın en son birimini gsterir.
            return gecici;
            break;
        case 4://Yani 'A' tuşuna basıldıysa sol yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
            {
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim sola gidiyorsa bu sıtunun bir birim azalması demek.
            r->sutun = r->sutun - 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;
            //Geçici pointerı hiç bir değişikliye uğramadığı işin mevcut yılanın en son birimini gsterir.
            return gecici;
            break;
        default:
            break;
        }
    } else if(sayac == 0) { //Yem yoksa yani yılan yemi yemişse
        gecici = malloc(sizeof(struct yilan));  //Eklenecek olan yeni birim için hafızadan yer alınır ve return değeri olan gecici ye atanır.
        gecici->sonraki = r; //Son birimin bir öncesine eklenir artık yeni bir son elemanımız var.
        gecici->satir = r->satir;  //Yeni eklenen birime eski son elemanın satırı atanır.
        gecici->sutun = r->sutun;  //Yeni eklenen birime eski son elemanın sıtunu atanır.
        switch(yon) {
        case 1: //Yani 'W' tuşuna basıldıysa yukarı yınde ilerleyecektir demektir.

            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat aynı zamanda diğer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yılanın baı ilerlerken diğer kısımları sabit kalıyormuş gibi görünecek ve yılan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim yukarı gidiyorsa bu satırın bir birim azalması demek.
            r->satir = r->satir - 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;

            (*boy)++;   //Yılan yemi yediği için boyu bir birim artacaktır.
            return gecici;  //Artık gecici nin yeni değeri yılana eklenen son birimin adresi.
            break;
        case 2: //Yani 'D' tuşuna basıldıysa sağ yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat aynı zamanda diğer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yılanın baı ilerlerken diğer kısımları sabit kalıyormuş gibi görünecek ve yılan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim sağa gidiyorsa bu sıtunun bir birim artması demek.
            r->sutun = r->sutun + 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;

            (*boy)++;   //Yılan yemi yediği için boyu bir birim artacaktır.
            return gecici;  //Artık gecici nin yeni değeri yılana eklenen son birimin adresi.
            break;
        case 3: //Yani 'S' tuşuna basıldıysa aşağı yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat aynı zamanda diğer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yılanın baı ilerlerken diğer kısımları sabit kalıyormuş gibi görünecek ve yılan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim aşağı gidiyorsa bu satırın bir birim artması demek.
            r->satir = r->satir + 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;

            (*boy)++;   //Yılan yemi yediği için boyu bir birim artacaktır.
            return gecici;  //Artık gecici nin yeni değeri yılana eklenen son birimin adresi.
            break;
        case 4: //Yani 'A' tuşuna basıldıysa sol yınde ilerleyecektir demektir.
            for(i = 0; i < *boy - 1; i++)
                //En son elemandan başlayıp Baştan bir önceki elemana gidene kadar dner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat aynı zamanda diğer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yılanın baı ilerlerken diğer kısımları sabit kalıyormuş gibi görünecek ve yılan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapılan işlemlerin amacı yılanın bir sonraki birimindeki değerleri mevcut birimlere atayarak kaydırma işlemi yapmak.
                r->satir = r->sonraki->satir;
                r->sutun = r->sonraki->sutun;
                r = r->sonraki;
            }
            //Eğer yılan bir birim sola gidiyorsa bu sıtunun bir birim azalması demek.
            r->sutun = r->sutun - 1;
            bas[0] = r->satir;
            bas[1] = r->sutun;

            (*boy)++;   //Yılan yemi yediği için boyu bir birim artacaktır.
            return gecici;  //Artık gecici nin yeni değeri yılana eklenen son birimin adresi.
            break;
        default:
            break;
        }
    }
}

//Oyun alanına yem koymaya yarayan fonksiyon.
//Tek parametre alıyor o da oyun alanını temsil eden fonksiyon.
void yem(int (*oyun)[30]) {
    int yemek, satir, sutun;
    do {
        yemek = rand() % 900; //rand() fonksiyonu sayesinde 0-899 arasında rastgele sayılar ıretiyoruz.
        sutun = (yemek % 30) - 1; //Bu ırettiğimiz sayının 30'a bölümünden kalanı sutun'a
        satir = (yemek / 30) - 1; //Bölüm ksmını da satir'a atıyoruz.
    } while(oyun[satir][sutun] != 0); //Elde ettiğimiz satır sıtunu oyun alanında kontrol ediyoruz orası duvar mı diye.
    oyun[satir][sutun] = 100;  //Eğer koşul sağlanıyorsa oraya 100 atıyoruz.
    //NOT:Haritada herbir durumun bir değeri var 100 bunlardan sadece birisi.
}

//yazdir fonksiyonu mevcut durumu ekrana basmaya yarayan foksiyon.
void yazdir(struct yilan *y, struct yilan *yi, int (*oyun)[30], int boy, int *bas, int *bitis, int skor)
//Parametreler ve açıklamaları:
//struct yilan *y=struct yilan tipindeki pointer sayesinde yılanın yerini bulup oraya değer atamak için kullanılıyor.
//struct yilan *yi=struct yilan tipindeki pointer sayesinde y pointerının yılanın en sonuna tekrardan dnmeleri sağlanıyor.
//int (*oyun)[30]=Oyun haritasını bu pointer sayesinde kullanacağız.
//int boy=yılanın sonundan baına giderken kullandığımız dngülerde dngünün kaç defa dneceğini belirliyor.
//int *bas=Yılanın baının koordinatlarını tutan dizinin pointerı.
//int *bitis=bitis değişkeni oyunun bitip bitmemesi gerektine karar verir eğer 1'se oyun biter 0'sa oyun devam eder.
//int skor =Skoru ekrana basabilmemiz için yediğimiz yem sayısını tutan bir sayı.
{
    int i, j;

    for(i = 0; i < boy - 1; i++)
        //Yılanın sonundan başlayıp baından bir önceki elemana kadar dnerr.
    {
        //Eğer yılanın bedeninin bir parıasıysa 10 değeri atıyoruz.
        oyun[y->satir][y->sutun] = 10;
        //Eğer yılanın bir parıası baıa eşitse bitis 1'e eşitlenir.Yani oyun bitecektir.
        if(y->satir == bas[0] && y->sutun == bas[1]) {
            *bitis = 1;
        }
        y = y->sonraki;
    }
    //Eğer yılanın baıysa 11 değerini atıyoruz.
    oyun[y->satir][y->sutun] = 11;
    //Eğer baın koordinatları duvarlara eşitse yani dış epere arpılmışsa bitis 1'eşitlenir, yani oyun bitecektir.
    if(bas[0] == 0 || bas[0] == 29 || bas[1] == 0 || bas[1] == 29) {
        *bitis = 1;
    }
    //Ekrana basmamızı sağlayan dngü
    for(i = 0; i < 30; i++) {
        for(j = 0; j < 30; j++) {
            //UYARI:Dngüde karakterleri ikişer defa basmaktaki amaç ascii tablosundaki karakterlerin boyunun eninin 2 katı olması.
            //Eğer oyun alanı 1'e eşitse burası dış eper demektir.
            if(oyun[i][j] == 1) {
                //Ascii de 219 değeri olan karkteri ekrana basar.
                printf("%c%c", 219, 219);
            }
            //Eğer oyun alanı 100'e eşitse burada yem var demektir.
            else if(oyun[i][j] == 100) {
                //Ascii de 254 değeri olan karkteri ekrana basar.
                printf("%c ", 254);
            }
            //Eğer oyun alanı 0'a eşitse burada hiç birşey yok demektir.
            else if(oyun[i][j] == 0) {
                //Bu alanda hiç birşey yoktur iki boşluk karakteri konur.
                printf("  ");
            }
            //Eğer oyun alanı 10'a eşitse burada yılanın bedeni var demektir.
            else if(oyun[i][j] == 10) {
                //Ascii de 177 değeri olan karkteri ekrana basar.
                printf("%c%c", 177, 177);
            }
            //Eğer oyun alanı 11'a eşitse burada yılanın baı var demektir.
            else if(oyun[i][j] == 11) {
                //Ascii de 232 değeri olan karkteri ekrana basar.
                printf("%c%c", 232, 232);
            }
            //Oyun alanıyın sağıst kıesine skoru basar.
            if(i == 0 && j == 29) {
                printf("SCORE=%d", skor * 5);
            }
        }
        printf("\n");
    }
    //Yılanın sonuna tekrar dnmıp yılanın olduğu yerdeki değerleri 0'a eşitlenmeli.
    //Bunun için y=yi işlemi yapılır.
    y = yi;
    for(i = 0; i < boy - 1; i++) {
        oyun[y->satir][y->sutun] = 0;
        y = y->sonraki;
    }
    oyun[y->satir][y->sutun] = 0;
}

int main() {
    srand(time(NULL));
    int oyun[30][30]; //Oyun alanını tercihe baılı olarak 30x30 büyüklüğünde oluşturdum.
    int i, j, boy = 3, satir, sutun, sayac = 1, bitis = 0, yedigi_yem = 0; //Değişkenlerin neden tanımlandığını kullandığım alanlarda anlayacaksınızdır.
    char yon = 100, eski_yon = 100; //Bir başlangı değeri olarak 100 atama sebebim yılanın oyun başlangıcında sağ tarafa doğru hareket etmeseni istemem.
    for(i = 0; i < 30; i++) { //Oyun alanını dış eperi belirtmek için 1 değeri atadım.
        for(j = 0; j < 30; j++) {
            if(i == 0 || j == 0 || i == 29 || j == 29) {
                oyun[i][j] = 1;
            } else {
                oyun[i][j] = 0;
            }
        }
    }
    struct yilan *ilan; //Yılanın ilk elemanı yani kuyruğunu gsteren pointer.
    struct yilan *root; //ilan pointerının yedeği.
    ilan = malloc(sizeof(struct yilan)); //ilk elemana hafızadan yer alırız.
    ilan->satir = 9; // Yılan yapısının özelleşi olan satir'a bir başlangı değeri atarız.
    ilan->sutun = 7; // Yılan yapısının özelleşi olan sutun'a bir başlangı değeri atarız.
    root = ilan; //Yedek pointer'a atama yaparız.
    ilan->sonraki = malloc(sizeof(struct yilan)); //Yılanın gvde kısmına hafızadan yer ayırırız.
    ilan->sonraki->satir = 9; //Yılanın gvde kısmına başlangı değeri atarız.
    ilan->sonraki->sutun = 8;
    ilan->sonraki->sonraki = malloc(sizeof(struct yilan)); //Yılanın baı kısmına hafızadan yer ayırırız.
    ilan->sonraki->sonraki->satir = 9; //Yılanın baı kısmına başlangı değeri atarız.
    ilan->sonraki->sonraki->sutun = 9;
    ilan->sonraki->sonraki->sonraki = NULL;
    int bas[2] = {9, 9}; //Baı kısmının tutduğu değerleri özellikle ayrı bir dizede saklarız.Sebebi ise sadece ekrana basarken oranın baı kısmı olduğunu bilerek daha rahat ekrana basmak.
    yem(oyun); //Oyun alanına rastgele yem atılması için yem fonksiyonu aırılır.
    printf("OYUNA BASLAMAK ICIN HERHANGI BIR TUSA BASIN!!!");
    getch(); //Oyuna başlayabilmek için getch fonksiyonun herhangi bir tuşa basdıktan sonra enter'a basmadan okuması özelleşini kullandım.
    do {
        if(1) { //Bu kısma geldiği sırece bu sıreci uygulamasın için koşul bloğunun içine 1 yazdım.
            Sleep(100); //sleep fonksiyonu sayesinde 100 milisaniye oyun akışı engelleniyor.Bu fonksiyonu kullanmamızdaki amaç Bilgisayarı eğer yavaşlatmazsak oyunun çok hızlı akacağı ve oynanamaz hal alamsı.
            if(kbhit()) { //kbhit fonksiyonunu kullanmamızdaki amaç kullanıcının bir tuşa basıp basmadığını tespit etmek eğer basmazsa yılanın eski yınınde devam etmesini sağlamak.

                yon = getch(); //Eğer tuşa basılırsa bubu saklamak için yon'e atarız.
            }
        }
        if(yon == 87 || yon == 119) { //Eğer 'w' veya 'W' ya basılmışsa yani yukarı yınde gidilmesi isteniyorsa,
            if(eski_yon == 83 || eski_yon == 115) { //Fakat eski yını aşağı tarafa doğruysa,
                yon = eski_yon; //Eski yını yeni yıne atarız ınkı yılan kendi iınden geçemez.
            }
        } else if(yon == 68 || yon == 100) { //Eğer 'd' veya 'D' ya basılmışsa yani sağ tarafa gidilmesi isteniyorsa,
            if(eski_yon == 97 || eski_yon == 65) { //Fakat eski yını sol tarafa doğruysa,
                yon = eski_yon; //Eski yını yeni yıne atarız ınkı yılan kendi iınden geçemez.
            }
        } else if(yon == 83 || yon == 115) { //Eğer 's' veya 'S' ya basılmışsa yani aşağı yınde gidilmesi isteniyorsa,
            if(eski_yon == 87 || eski_yon == 119) { //Fakat eski yını yukarı tarafa doğruysa,
                yon = eski_yon; //Eski yını yeni yıne atarız ınkı yılan kendi iınden geçemez.
            }
        } else if(yon == 65 || yon == 97) { //Eğer 'a' veya 'A' ya basılmışsa yani sol tarafa gidilmesi isteniyorsa,
            if(eski_yon == 68 || eski_yon == 100) { //Fakat eski yını sağ tarafa doğruysa,
                yon = eski_yon; //Eski yını yeni yıne atarız ınkı yılan kendi iınden geçemez.
            }
        }
        if(yon != 87 && yon != 119 && yon != 68 && yon != 100 && yon != 83 && yon != 115 && yon != 65 && yon != 97) { //Bu blok eğer tuşa basılmazsa eski yınde devam etmesi için yazılmıştır.
            yon = eski_yon; //Veya "w,a,s,d" den başka tuşa basılmışsa önemsememesi için yazılmıştır.
        }// ilerle fonksiyonu yılanın yın doğrultusunda ilerlemesini sağlar.
        if(yon == 87 || yon == 119) { //Eğer 'w' ya basılmışsa ilerle fonksiyonuna 1 parametresini göndeririz.
            root = ilerle(root, 1, &boy, sayac, bas); //1 burda yukarı yını temsil eder.
        } else if(yon == 100 || yon == 68) { //Eğer 'd' ye basılmışsa ilerle fonksiyonuna 2 parametresini göndeririz.
            root = ilerle(root, 2, &boy, sayac, bas); //2 burda yukarı yını temsil eder.
        } else if(yon == 115 || yon == 83) { //Eğer 's' e basılmışsa ilerle fonksiyonuna 3 parametresini göndeririz.
            root = ilerle(root, 3, &boy, sayac, bas); //3 burda yukarı yını temsil eder.
        } else if(yon == 97 || yon == 65) { //Eğer 'a' ya basılmışsa ilerle fonksiyonuna 4 parametresini göndeririz.
            root = ilerle(root, 4, &boy, sayac, bas); //4 burda yukarı yını temsil eder.
        }
        eski_yon = yon; //Artık ilerlediğimiz yın eski yınımız olduğuna göre.
        ilan = root; //"root" ilerle fonksiyonundan dnmınde yılanın kuyruğunu gsteriyor olacak fakat "ilan" hiçbir değişikliye uğramadığı için yılanın gvdesini gsterecek.
        system("CLS");//Konsoldaki yazılan tüm verileri silmeye yarayan fonksiyon. Haritadaki ilerlemeyi gstermek için tüm verileri sileriz.
        yazdir(root, ilan, oyun, boy, bas, &bitis, yedigi_yem); //Ve yeni halini ekrana basarız.
        sayac = 0; //Eğer sayac 0'a eşitse yılan yemiş demektir. Büyle değişkeni tutmaktaki amaç yılan eğer yemi yemişse oyun alanına yeni bir yem atmak ve skor'u hesaplayabilmek için.
        for(i = 0; i < 30; i++) { //Oyun alanının tamamını dolaşarak yemin olup olmadığını kontrol eden yapı.
            for(j = 0; j < 30; j++) {
                if(oyun[i][j] == 100)
                    sayac++; // Eğer matrisin değeri 100 ise yani yem varsa orda sayac 1 artar.
            }
        }
        if(sayac == 0) { // sayac 0'a eşitse yani oyun alanında hiç yem yoksa,
            yedigi_yem++; //Yediği yem sayısı 1 arttırılır.
            yem(oyun); //Ve oyun alanına yeni bir yem atılması için yem fonksiyonu aırılır.
        }

    } while(bitis == 0); //Oyunun bitip bitmemesi gerektiğini kontrol eden değişken, illerle fonksiyonu içinde pointer yardımıyla değeri değiştirilebiliyor.
    printf("OYUN  BITTI!!!   SKOR:%d\a", yedigi_yem * 5); //OYUN  BITTI!!!
    return 0;
}