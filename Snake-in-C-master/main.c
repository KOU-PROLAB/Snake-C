//Eyup KORURER 13.10.2017
//GNU GCC compiler ile derlenmiþtir.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //Bu kütüphane rand() fonksiyonunu kullanabilmek için eklendi.
#include <windows.h>    //BU kütüphane sleep() fonksiyonunu kullanabilmek için eklendi.
#include <conio.h>  //Bu kütüphane getch() ve kbhit() fonksiyonlarý için eklendi.

//Yýlan struct yapýsýyla yapýldý, çünkü yýlanýn parçalarýna ulaþmak kolay oluyor ve büyüme layýný bu þekilde saðlayabileceðimi düþündüm.
struct yilan
{
    int satir;  //Yýlanýn bir biriminin satýrýný tutan yer.
    int sutun;  //Yýlanýn bir biriminin sütununu tutan yer.
    struct yilan *sonraki;  //Yýlanýn en son kýsmýndan baþ kýsmýna doðru ilerlememizi saðlayan pointer.
};

//Ýlerleme iþlemini bu foksiyonla saðladým
//struct yilan* tipinde bir fonsiyon bunun sebebi yýlan büyüdüðü zaman yeni bir struct oluþturup yeni bir baþlangýç pointerý elde ediyor olmamýz.

struct yilan* ilerle(struct yilan *r,int yon,int *boy,int sayac,int *bas)

//Parametler ve açýklamalarý:
//struct yilan *r=bu parametre yýlanýn en son birimini gösteren pointer bu deðerden baþlayýp baþ ksýmýna gelinceye kadar ilerliyeceðiz.
//int yon=bu parametre ile yýlanýn gideceði yöne göre ilerleme kaydetmesini saðlýyor.
//int *boy=yýlanýn boyunun saklandýðý yeri gösteren bi pointer, pointer olma sebebi eðer yýlan büyüyorsa boyunu bellekteki gösterdiði yere eriþerek deðiþtirmek.
//int sayac=bu deðiþkenin deðeri main fonksiyonunda kontrol edilþyor ve haritadaki yem sayýsýný gösteriyor,eðer yem sayýsý '0' ise yýlan yemi yemiþ yani büyümesi gerek demek.
//int *bas=iki boyutlu bir dizinin pointerý, burda pointer kullanýlma sebebi ise yýlanýn baþýnýn kordinatlarýný ayrý bir deðiþkende saklamak
{
    int i;
    struct yilan *gecici=r; //Default deðeri olarak yýlanýn en son birimini gösteren pointer'ý atýyoruz.
    if(sayac==1)//Yani yem mevcutsa bir baþka deyiþle yýlan yemi yememiþse
    {
        switch (yon)
        {
        case 1:   //Yani 'W' tuþuna basýldýysa yukarý yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim yukarý gidiyorsa bu satýrýn bir birim eksilmesi demek.
            r->satir=r->satir-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Geçici pointerý hiç bir deðiþikliðe uðramadýðý için mevcut yýlanýn en son birimini gösterir.
            return gecici;
            break;
        case 2:   //Yani 'D' tuþuna basýldýysa sað yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim saða gidiyorsa bu sütunun bir birim artmasý demek.
            r->sutun=r->sutun+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Geçici pointerý hiç bir deðiþikliðe uðramadýðý için mevcut yýlanýn en son birimini gösterir.
            return gecici;
            break;
        case 3:    //Yani 'S' tuþuna basýldýysa aþaðý yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim aþaðý gidiyorsa bu satýrýn bir birim artmasý demek.
            r->satir=r->satir+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Geçici pointerý hiç bir deðiþikliðe uðramadýðý için mevcut yýlanýn en son birimini gösterir.
            return gecici;
            break;
        case 4://Yani 'A' tuþuna basýldýysa sol yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
            {
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim sola gidiyorsa bu sütunun bir birim azalmasý demek.
            r->sutun=r->sutun-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Geçici pointerý hiç bir deðiþikliðe uðramadýðý için mevcut yýlanýn en son birimini gösterir.
            return gecici;
            break;
        default:
            break;
        }
    }
    else if(sayac==0) //Yem yoksa yani yýlan yemi yemiþse
    {
        gecici=malloc(sizeof(struct yilan));    //Eklenecek olan yeni birim için hafýzadan yer alýnýr ve return deðeri olan gecici ye atanýr.
        gecici->sonraki=r;  //Son birimin bir öncesine eklenir artýk yeni bir son elemanýmýz var.
        gecici->satir=r->satir;    //Yeni eklenen birime eski son elemanýn satýrý atanýr.
        gecici->sutun=r->sutun;    //Yeni eklenen birime eski son elemanýn sütunu atanýr.
        switch (yon)
        {
        case 1: //Yani 'W' tuþuna basýldýysa yukarý yönde ilerleyecektir demektir.

            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat ayný zamanda diðer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yýlanýn baþý ilerlerken diðer kýsýmlarý sabit kalýyormuþ gibi görünecek ve yýlan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim yukarý gidiyorsa bu satýrýn bir birim azalmasý demek.
            r->satir=r->satir-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Yýlan yemi yediði için boyu bir birim artacaktýr.
            return gecici;  //Artýk gecici nin yeni deðeri yýlana eklenen son birimin adresi.
            break;
        case 2: //Yani 'D' tuþuna basýldýysa sað yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat ayný zamanda diðer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yýlanýn baþý ilerlerken diðer kýsýmlarý sabit kalýyormuþ gibi görünecek ve yýlan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim saða gidiyorsa bu sütunun bir birim artmasý demek.
            r->sutun=r->sutun+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Yýlan yemi yediði için boyu bir birim artacaktýr.
            return gecici;  //Artýk gecici nin yeni deðeri yýlana eklenen son birimin adresi.
            break;
        case 3: //Yani 'S' tuþuna basýldýysa aþaðý yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat ayný zamanda diðer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yýlanýn baþý ilerlerken diðer kýsýmlarý sabit kalýyormuþ gibi görünecek ve yýlan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim aþaðý gidiyorsa bu satýrýn bir birim artmasý demek.
            r->satir=r->satir+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Yýlan yemi yediði için boyu bir birim artacaktýr.
            return gecici;  //Artýk gecici nin yeni deðeri yýlana eklenen son birimin adresi.
            break;
        case 4: //Yani 'A' tuþuna basýldýysa sol yönde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan baþlayýp Baþtan bir önceki elemana gidene kadar döner.
                /* Yeni eklenen birim hiç hareket ettirilmeyecektir fakat ayný zamanda diðer elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede yýlanýn baþý ilerlerken diðer kýsýmlarý sabit kalýyormuþ gibi görünecek ve yýlan bir birim büyüyecektir. */
            {
                //Bu bloktaki yapýlan iþlemlerin amacý yýlanýn bir sonraki birimindeki deðerleri mevcut birimlere atayarak kaydýrma iþlemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //Eðer yýlan bir birim sola gidiyorsa bu sütunun bir birim azalmasý demek.
            r->sutun=r->sutun-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Yýlan yemi yediði için boyu bir birim artacaktýr.
            return gecici;  //Artýk gecici nin yeni deðeri yýlana eklenen son birimin adresi.
            break;
        default:
            break;
        }
    }
}


//Oyun alanýna yem koymaya yarayan fonksiyon.
//Tek parametre alýyor o da oyun alanýný temsil eden fonksiyon.
void yem(int (*oyun)[30])
{
    int yemek,satir,sutun;
    do
    {
        yemek=rand() % 900;   //rand() fonksiyonu sayesinde 0-899 arasýnda rastgele sayýlar üretiyoruz.
        sutun=(yemek%30)-1;   //Bu ürettiðimiz sayýnýn 30'a bölümünden kalaný sutun'a
        satir=(yemek/30)-1;   //Bölüm kýsmýný da satir'a atýyoruz.
    }
    while(oyun[satir][sutun]!=0);   //Elde ettiðimiz satýr sütunu oyun alanýnda kontrol ediyoruz orasý duvar mý diye.
    oyun[satir][sutun]=100;    //Eðer koþul saðlanýyorsa oraya 100 atýyoruz.
    //NOT:Haritada herbir durumun bir deðeri var 100 bunlardan sadece birisi.
}


//yazdir fonksiyonu mevcut durumu ekrana basmaya yarayan foksiyon.
void yazdir(struct yilan *y,struct yilan *yi,int (*oyun)[30],int boy,int *bas,int *bitis,int skor)

//Parametreler ve açýklamalarý:
//struct yilan *y=struct yilan tipindeki pointer sayesinde yýlanýn yerini bulup oraya deðer atamak için kullanýlýyor.
//struct yilan *yi=struct yilan tipindeki pointer sayesinde y pointerýnýn yýlanýn en sonuna tekrardan dönmesi saðlanýyor.
//int (*oyun)[30]=Oyun haritasýný bu pointer sayesinde kullanacaðýz.
//int boy=yýlanýn sonundan baþýna giderken kullandýðýmýz döngülerde döngünün kaç defa döneceðini belirliyor.
//int *bas=Yýlanýn baþýnýn koordinatlarýný tutan dizinin pointerý.
//int *bitis=bitis deðiþkeni oyunun bitip bitmemesi gerektðine karar verir eðer 1'se oyun biter 0'sa oyun devam eder.
//int skor =Skoru ekrana basabilmemiz için yediðimiz yem sayýsýný tutan bir sayaç.
{
    int i,j;

    for(i=0; i<boy-1; i++)
        //Yýlanýn sonundan baþlayýp baþýndan bir önceki elemana kadar döndürür.
    {
        //Eðer yýlanýn bedeninin bir parçasýysa 10 deðeri atýyoruz.
        oyun[y->satir][y->sutun]=10;
        //Eðer yýlanýn bir parçasý baþa eþitse bitis 1'e eþitlenir.Yani oyun bitecektir.
        if(y->satir==bas[0] && y->sutun==bas[1])
        {
            *bitis=1;
        }
        y=y->sonraki;
    }
    //Eðer yýlanýn baþýysa 11 deðerini atýyoruz.
    oyun[y->satir][y->sutun]=11;
    //Eðer baþýn koordinatlarý duvarlara eþitse yani dýþ çepere çarpýlmýþsa bitis 1'eþitlenir, yani oyun bitecektir.
    if(bas[0]==0 || bas[0]==29 || bas[1]==0 || bas[1]==29)
    {
        *bitis=1;
    }
    //Ekrana basmamýzý saðlayan döngü
    for(i=0; i<30; i++)
    {
        for(j=0; j<30; j++)
        {
            //UYARI:Döngüde karakterleri ikiþer defa basmaktaki amaç ascii tablosundaki karakterlerin boyunun eninin 2 katý olmasý.
            //Eðer oyun alaný 1'e eþitse burasý dýþ çeper demektir.
            if(oyun[i][j]==1)
            {
                //Ascii de 219 deðeri olan karkteri ekrana basar.
                printf("%c%c",219,219);
            }
            //Eðer oyun alaný 100'e eþitse burada yem var demektir.
            else if(oyun[i][j]==100)
            {
                //Ascii de 254 deðeri olan karkteri ekrana basar.
                printf("%c ",254);
            }
            //Eðer oyun alaný 0'a eþitse burada hiç birþey yok demektir.
            else if(oyun[i][j]==0)
            {
                //Bu alanda hiç birþey yoktur iki boþluk karakteri konur.
                printf("  ");
            }
            //Eðer oyun alaný 10'a eþitse burada yýlanýn bedeni var demektir.
            else if(oyun[i][j]==10)
            {
                //Ascii de 177 deðeri olan karkteri ekrana basar.
                printf("%c%c",177,177);
            }
            //Eðer oyun alaný 11'a eþitse burada yýlanýn baþý var demektir.
            else if(oyun[i][j]==11)
            {
                //Ascii de 232 deðeri olan karkteri ekrana basar.
                printf("%c%c",232,232);
            }
            //Oyun alanýyýn sað üst küþesine skoru basar.
            if(i==0 && j==29)
            {
                printf("SCORE=%d",skor*5);
            }
        }
        printf("\n");
    }
    //Yýlanýn sonuna tekrar dönüp yýlanýn olduðu yerdeki deðerleri 0'a eþitlenmeli.
    //Bunun için y=yi iþlemi yapýlýr.
    y=yi;
    for(i=0; i<boy-1; i++)
    {
        oyun[y->satir][y->sutun]=0;
        y=y->sonraki;
    }
    oyun[y->satir][y->sutun]=0;
}


int main()
{
    srand(time(NULL));
    int oyun[30][30]; //Oyun alanýný tercihe baðlý olarak 30x30 büyüklüðünde oluþturdum.
    int i,j,boy=3,satir,sutun,sayac=1,bitis=0,yedigi_yem=0; //Deðiþkenlerin neden tanýmlandýðýný kullandýðým alanlarda anlayacaksýnýzdýr.
    char yon=100,eski_yon=100; //Bir baþlangýç deðeri olarak 100 atama sebebim yýlanýn oyun baþlangýcýnda sað tarafa doðru hareket etmeseni istemem.
    for(i=0; i<30; i++) //Oyun alanýn dýþ çeperini belirtmek için 1 deðerini atadým.
    {
        for(j=0; j<30; j++)
        {
            if(i==0 || j==0 || i==29 || j==29)
            {
                oyun[i][j]=1;
            }
            else
            {
                oyun[i][j]=0;
            }
        }
    }
    struct yilan *ilan; //Yýlanýn ilk elemaný yani kuyruðunu gösteren pointer.
    struct yilan *root; //ilan pointerýnýn yedeði.
    ilan=malloc(sizeof(struct yilan)); //Ýlk elemana hafýzadan yer alýrýz.
    ilan->satir=9; // Yýlan yapýsýnýn Özelleði olan satir'a bir baþlangýç deðeri atarýz.
    ilan->sutun=7; // Yýlan yapýsýnýn Özelleði olan sutun'a bir baþlangýç deðeri atarýz.
    root=ilan;  //Yedek pointer'a atama yaparýz.
    ilan->sonraki=malloc(sizeof(struct yilan)); //Yýlanýn gövde kýsmýna hafýzadan yer ayýrýrýz.
    ilan->sonraki->satir=9; //Yýlanýn gövde kýsmýna baþlangýç deðeri atarýz.
    ilan->sonraki->sutun=8;
    ilan->sonraki->sonraki=malloc(sizeof(struct yilan)); //Yýlanýn baþ kýsmýna hafýzadan yer ayýrýrýz.
    ilan->sonraki->sonraki->satir=9; //Yýlanýn baþ kýsmýna baþlangýç deðeri atarýz.
    ilan->sonraki->sonraki->sutun=9;
    ilan->sonraki->sonraki->sonraki=NULL;
    int bas[2]= {9,9}; //Baþ kýsmýnýn tutduðu deðerleri özellikle ayrý bir dizede saklarýz.Sebebi ise sadece ekrana basarken oranýn baþ kýsmý olduðnu bilerek daha rahat ekrana basmak.
    yem(oyun); //Oyun alanýna rastgele yem atýlmasý için yem fonksiyonu çaðrýlýr.
    printf("OYUNA BASLAMAK ICIN HERHANGI BIR TUSA BASIN!!!");
    getch(); //Oyuna baþlayabilmek için getch fonksiyonun herhangi bir tuþa basdýktan sonra enter'a basmadan okumasý özelleðini kullandým.
    do
    {

        if (1)//Bu kýsma geldiði sürece bu süreci uygulamasýn için koþul bloðunun içine 1 yazdým.
        {
            Sleep(100); //sleep fonksiyonu sayesinde 100 milisaniye oyun akýþý engelleniyor.Bu fonksiyonu kullanmamýzdaki amaç Bilgisayarý eðer yavaþlatmazsak oyunun çok hýzlý akacaðý ve oynanamaz hal alamsý.
            if (kbhit()) //kbhit fonksiyonunu kullanmamýzdaki amaç kullanýcýnýn bir tuþa basýp basmadýðýný tespit etmek eðer basmazsa yýlanýn eski yönünde devam etmesini saðlamak.
            {

                yon =getch(); //Eðer tuþa basýlýrsa bubu saklamak için yon'e atarýz.
            }
        }




        if(yon==87 || yon==119) //Eðer 'w' veya 'W' ya basýlmýþsa yani yukarý yönde gidilmesi isteniyorsa,
        {
            if(eski_yon==83 || eski_yon==115) //Fakat eski yönü aþaðý tarafa doðruysa,
            {
                yon=eski_yon; //Eski yönü yeni yöne atarýz çünkü yýlan kendi içinden geçemez.
            }
        }
        else if(yon==68 || yon==100) //Eðer 'd' veya 'D' ya basýlmýþsa yani sað tarafa gidilmesi isteniyorsa,
        {
            if(eski_yon==97 || eski_yon==65) //Fakat eski yönü sol tarafa doðruysa,
            {
                yon=eski_yon; //Eski yönü yeni yöne atarýz çünkü yýlan kendi içinden geçemez.
            }
        }
        else if(yon==83 || yon==115) //Eðer 's' veya 'S' ya basýlmýþsa yani aþaðý yönde gidilmesi isteniyorsa,
        {
            if(eski_yon==87 || eski_yon==119) //Fakat eski yönü yukarý tarafa doðruysa,
            {
                yon=eski_yon; //Eski yönü yeni yöne atarýz çünkü yýlan kendi içinden geçemez.
            }
        }
        else if(yon==65 || yon==97) //Eðer 'a' veya 'A' ya basýlmýþsa yani sol tarafa gidilmesi isteniyorsa,
        {
            if(eski_yon==68 || eski_yon==100) //Fakat eski yönü sað tarafa doðruysa,
            {
                yon=eski_yon; //Eski yönü yeni yöne atarýz çünkü yýlan kendi içinden geçemez.
            }
        }
        if(yon!=87 && yon!=119 && yon!=68 && yon!=100 && yon!=83 && yon!=115 && yon!=65 && yon!=97) //Bu blok eðer tuþa basýlmazsa eski yönde devam etmesi için yazýlmýþtýr.
        {
            yon=eski_yon; //Veya "w,a,s,d" den baþka tuþa basýlmýþsa önemsememesi için yazýlmýþtýr.
        }

        // ilerle fonksiyonu yýlanýn yön doðrultusunda ilerlemesini saðlar.
        if(yon== 87 || yon==119) //Eðer 'w' ya basýlmýþsa ilerle fonksiyonuna 1 parametresini göndeririz.
        {
            root=ilerle(root,1,&boy,sayac,bas); //1 burda yukarý yönü temsil eder.
        }
        else if(yon==100 || yon==68) //Eðer 'd' ye basýlmýþsa ilerle fonksiyonuna 2 parametresini göndeririz.
        {
            root=ilerle(root,2,&boy,sayac,bas); //2 burda yukarý yönü temsil eder.
        }
        else if(yon==115 || yon==83) //Eðer 's' e basýlmýþsa ilerle fonksiyonuna 3 parametresini göndeririz.
        {
            root=ilerle(root,3,&boy,sayac,bas); //3 burda yukarý yönü temsil eder.
        }
        else if(yon==97 || yon==65) //Eðer 'a' ya basýlmýþsa ilerle fonksiyonuna 4 parametresini göndeririz.
        {
            root=ilerle(root,4,&boy,sayac,bas); //4 burda yukarý yönü temsil eder.
        }
        eski_yon=yon; //Artýk ilerlediðimiz yön eski yönümüz olduðuna göre.
        ilan=root; //"root" ilerle fonksiyonundan döndüðünde yýlanýn kuyruðunu gösteriyor olacak fakat "ilan" hiçbir deðiþikliðe uðramadýðý için yýlanýn gövdesini gösterecek.
        system("CLS");//Konsoldaki yazýlan tüm verileri silmeye yarayan fonksiyon. Haritadaki ilerlemeyi göstermek için tüm verileri sileriz.
        yazdir(root,ilan,oyun,boy,bas,&bitis,yedigi_yem); //Ve yeni halini ekrana basarýz.
        sayac=0; //Eðer sayac 0'a eþitse yýlan yemiþ demektir. Böyle deðiþkeni tutmaktaki amaç yýlan eðer yemi yemiþse oyun alanýna yeni bir yem atmak ve skor'u hesaplayabilmek için.
        for(i=0; i<30; i++) //Oyun alanýnýn tamamýný dolaþarak yemin olup olmadýðýný kontrol eden yapý.
        {
            for(j=0; j<30; j++)
            {
                if(oyun[i][j]==100)
                    sayac++; // Eðer matrisin deðeri 100 ise yani yem varsa orda sayac 1 artar.
            }
        }
        if(sayac==0) // sayac 0'a eþitse yani oyun alanýnda hiç yem yoksa,
        {
            yedigi_yem++; //Yediði yem sayýsý 1 arttýrýlýr.
            yem(oyun); //Ve oyun alanýna yeni bir yem atýlmasý için yem fonksiyonu çaðrýlýr.
        }

    }
    while(bitis==0); //Oyunun bitip bitmemesi gerektiðini kontrol eden deðiþken, illerle fonksiyonu içinde pointer yardýmýyla deðeri deðiþtirilebiliyor.
    printf("OYUN  BITTI!!!   SKOR:%d\a",yedigi_yem*5); //OYUN  BITTI!!!
    return 0;
}
