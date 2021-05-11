//Eyup KORURER 13.10.2017
//GNU GCC compiler ile derlenmi�tir.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //Bu k�t�phane rand() fonksiyonunu kullanabilmek i�in eklendi.
#include <windows.h>    //BU k�t�phane sleep() fonksiyonunu kullanabilmek i�in eklendi.
#include <conio.h>  //Bu k�t�phane getch() ve kbhit() fonksiyonlar� i�in eklendi.

//Y�lan struct yap�s�yla yap�ld�, ��nk� y�lan�n par�alar�na ula�mak kolay oluyor ve b�y�me lay�n� bu �ekilde sa�layabilece�imi d���nd�m.
struct yilan
{
    int satir;  //Y�lan�n bir biriminin sat�r�n� tutan yer.
    int sutun;  //Y�lan�n bir biriminin s�tununu tutan yer.
    struct yilan *sonraki;  //Y�lan�n en son k�sm�ndan ba� k�sm�na do�ru ilerlememizi sa�layan pointer.
};

//�lerleme i�lemini bu foksiyonla sa�lad�m
//struct yilan* tipinde bir fonsiyon bunun sebebi y�lan b�y�d��� zaman yeni bir struct olu�turup yeni bir ba�lang�� pointer� elde ediyor olmam�z.

struct yilan* ilerle(struct yilan *r,int yon,int *boy,int sayac,int *bas)

//Parametler ve a��klamalar�:
//struct yilan *r=bu parametre y�lan�n en son birimini g�steren pointer bu de�erden ba�lay�p ba� ks�m�na gelinceye kadar ilerliyece�iz.
//int yon=bu parametre ile y�lan�n gidece�i y�ne g�re ilerleme kaydetmesini sa�l�yor.
//int *boy=y�lan�n boyunun sakland��� yeri g�steren bi pointer, pointer olma sebebi e�er y�lan b�y�yorsa boyunu bellekteki g�sterdi�i yere eri�erek de�i�tirmek.
//int sayac=bu de�i�kenin de�eri main fonksiyonunda kontrol edil�yor ve haritadaki yem say�s�n� g�steriyor,e�er yem say�s� '0' ise y�lan yemi yemi� yani b�y�mesi gerek demek.
//int *bas=iki boyutlu bir dizinin pointer�, burda pointer kullan�lma sebebi ise y�lan�n ba��n�n kordinatlar�n� ayr� bir de�i�kende saklamak
{
    int i;
    struct yilan *gecici=r; //Default de�eri olarak y�lan�n en son birimini g�steren pointer'� at�yoruz.
    if(sayac==1)//Yani yem mevcutsa bir ba�ka deyi�le y�lan yemi yememi�se
    {
        switch (yon)
        {
        case 1:   //Yani 'W' tu�una bas�ld�ysa yukar� y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim yukar� gidiyorsa bu sat�r�n bir birim eksilmesi demek.
            r->satir=r->satir-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Ge�ici pointer� hi� bir de�i�ikli�e u�ramad��� i�in mevcut y�lan�n en son birimini g�sterir.
            return gecici;
            break;
        case 2:   //Yani 'D' tu�una bas�ld�ysa sa� y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim sa�a gidiyorsa bu s�tunun bir birim artmas� demek.
            r->sutun=r->sutun+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Ge�ici pointer� hi� bir de�i�ikli�e u�ramad��� i�in mevcut y�lan�n en son birimini g�sterir.
            return gecici;
            break;
        case 3:    //Yani 'S' tu�una bas�ld�ysa a�a�� y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim a�a�� gidiyorsa bu sat�r�n bir birim artmas� demek.
            r->satir=r->satir+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Ge�ici pointer� hi� bir de�i�ikli�e u�ramad��� i�in mevcut y�lan�n en son birimini g�sterir.
            return gecici;
            break;
        case 4://Yani 'A' tu�una bas�ld�ysa sol y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
            {
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim sola gidiyorsa bu s�tunun bir birim azalmas� demek.
            r->sutun=r->sutun-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;
            //Ge�ici pointer� hi� bir de�i�ikli�e u�ramad��� i�in mevcut y�lan�n en son birimini g�sterir.
            return gecici;
            break;
        default:
            break;
        }
    }
    else if(sayac==0) //Yem yoksa yani y�lan yemi yemi�se
    {
        gecici=malloc(sizeof(struct yilan));    //Eklenecek olan yeni birim i�in haf�zadan yer al�n�r ve return de�eri olan gecici ye atan�r.
        gecici->sonraki=r;  //Son birimin bir �ncesine eklenir art�k yeni bir son eleman�m�z var.
        gecici->satir=r->satir;    //Yeni eklenen birime eski son eleman�n sat�r� atan�r.
        gecici->sutun=r->sutun;    //Yeni eklenen birime eski son eleman�n s�tunu atan�r.
        switch (yon)
        {
        case 1: //Yani 'W' tu�una bas�ld�ysa yukar� y�nde ilerleyecektir demektir.

            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
                /* Yeni eklenen birim hi� hareket ettirilmeyecektir fakat ayn� zamanda di�er elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede y�lan�n ba�� ilerlerken di�er k�s�mlar� sabit kal�yormu� gibi g�r�necek ve y�lan bir birim b�y�yecektir. */
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim yukar� gidiyorsa bu sat�r�n bir birim azalmas� demek.
            r->satir=r->satir-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Y�lan yemi yedi�i i�in boyu bir birim artacakt�r.
            return gecici;  //Art�k gecici nin yeni de�eri y�lana eklenen son birimin adresi.
            break;
        case 2: //Yani 'D' tu�una bas�ld�ysa sa� y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
                /* Yeni eklenen birim hi� hareket ettirilmeyecektir fakat ayn� zamanda di�er elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede y�lan�n ba�� ilerlerken di�er k�s�mlar� sabit kal�yormu� gibi g�r�necek ve y�lan bir birim b�y�yecektir. */
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim sa�a gidiyorsa bu s�tunun bir birim artmas� demek.
            r->sutun=r->sutun+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Y�lan yemi yedi�i i�in boyu bir birim artacakt�r.
            return gecici;  //Art�k gecici nin yeni de�eri y�lana eklenen son birimin adresi.
            break;
        case 3: //Yani 'S' tu�una bas�ld�ysa a�a�� y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
                /* Yeni eklenen birim hi� hareket ettirilmeyecektir fakat ayn� zamanda di�er elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede y�lan�n ba�� ilerlerken di�er k�s�mlar� sabit kal�yormu� gibi g�r�necek ve y�lan bir birim b�y�yecektir. */
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim a�a�� gidiyorsa bu sat�r�n bir birim artmas� demek.
            r->satir=r->satir+1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Y�lan yemi yedi�i i�in boyu bir birim artacakt�r.
            return gecici;  //Art�k gecici nin yeni de�eri y�lana eklenen son birimin adresi.
            break;
        case 4: //Yani 'A' tu�una bas�ld�ysa sol y�nde ilerleyecektir demektir.
            for(i=0; i<*boy-1; i++)
                //En son elemandan ba�lay�p Ba�tan bir �nceki elemana gidene kadar d�ner.
                /* Yeni eklenen birim hi� hareket ettirilmeyecektir fakat ayn� zamanda di�er elemanlar ilerleyecek bu sayede yemi yedikten
                   hemen sonraki hamlede y�lan�n ba�� ilerlerken di�er k�s�mlar� sabit kal�yormu� gibi g�r�necek ve y�lan bir birim b�y�yecektir. */
            {
                //Bu bloktaki yap�lan i�lemlerin amac� y�lan�n bir sonraki birimindeki de�erleri mevcut birimlere atayarak kayd�rma i�lemi yapmak.
                r->satir=r->sonraki->satir;
                r->sutun=r->sonraki->sutun;
                r=r->sonraki;
            }
            //E�er y�lan bir birim sola gidiyorsa bu s�tunun bir birim azalmas� demek.
            r->sutun=r->sutun-1;
            bas[0]=r->satir;
            bas[1]=r->sutun;

            (*boy)++;   //Y�lan yemi yedi�i i�in boyu bir birim artacakt�r.
            return gecici;  //Art�k gecici nin yeni de�eri y�lana eklenen son birimin adresi.
            break;
        default:
            break;
        }
    }
}


//Oyun alan�na yem koymaya yarayan fonksiyon.
//Tek parametre al�yor o da oyun alan�n� temsil eden fonksiyon.
void yem(int (*oyun)[30])
{
    int yemek,satir,sutun;
    do
    {
        yemek=rand() % 900;   //rand() fonksiyonu sayesinde 0-899 aras�nda rastgele say�lar �retiyoruz.
        sutun=(yemek%30)-1;   //Bu �retti�imiz say�n�n 30'a b�l�m�nden kalan� sutun'a
        satir=(yemek/30)-1;   //B�l�m k�sm�n� da satir'a at�yoruz.
    }
    while(oyun[satir][sutun]!=0);   //Elde etti�imiz sat�r s�tunu oyun alan�nda kontrol ediyoruz oras� duvar m� diye.
    oyun[satir][sutun]=100;    //E�er ko�ul sa�lan�yorsa oraya 100 at�yoruz.
    //NOT:Haritada herbir durumun bir de�eri var 100 bunlardan sadece birisi.
}


//yazdir fonksiyonu mevcut durumu ekrana basmaya yarayan foksiyon.
void yazdir(struct yilan *y,struct yilan *yi,int (*oyun)[30],int boy,int *bas,int *bitis,int skor)

//Parametreler ve a��klamalar�:
//struct yilan *y=struct yilan tipindeki pointer sayesinde y�lan�n yerini bulup oraya de�er atamak i�in kullan�l�yor.
//struct yilan *yi=struct yilan tipindeki pointer sayesinde y pointer�n�n y�lan�n en sonuna tekrardan d�nmesi sa�lan�yor.
//int (*oyun)[30]=Oyun haritas�n� bu pointer sayesinde kullanaca��z.
//int boy=y�lan�n sonundan ba��na giderken kulland���m�z d�ng�lerde d�ng�n�n ka� defa d�nece�ini belirliyor.
//int *bas=Y�lan�n ba��n�n koordinatlar�n� tutan dizinin pointer�.
//int *bitis=bitis de�i�keni oyunun bitip bitmemesi gerekt�ine karar verir e�er 1'se oyun biter 0'sa oyun devam eder.
//int skor =Skoru ekrana basabilmemiz i�in yedi�imiz yem say�s�n� tutan bir saya�.
{
    int i,j;

    for(i=0; i<boy-1; i++)
        //Y�lan�n sonundan ba�lay�p ba��ndan bir �nceki elemana kadar d�nd�r�r.
    {
        //E�er y�lan�n bedeninin bir par�as�ysa 10 de�eri at�yoruz.
        oyun[y->satir][y->sutun]=10;
        //E�er y�lan�n bir par�as� ba�a e�itse bitis 1'e e�itlenir.Yani oyun bitecektir.
        if(y->satir==bas[0] && y->sutun==bas[1])
        {
            *bitis=1;
        }
        y=y->sonraki;
    }
    //E�er y�lan�n ba��ysa 11 de�erini at�yoruz.
    oyun[y->satir][y->sutun]=11;
    //E�er ba��n koordinatlar� duvarlara e�itse yani d�� �epere �arp�lm��sa bitis 1'e�itlenir, yani oyun bitecektir.
    if(bas[0]==0 || bas[0]==29 || bas[1]==0 || bas[1]==29)
    {
        *bitis=1;
    }
    //Ekrana basmam�z� sa�layan d�ng�
    for(i=0; i<30; i++)
    {
        for(j=0; j<30; j++)
        {
            //UYARI:D�ng�de karakterleri iki�er defa basmaktaki ama� ascii tablosundaki karakterlerin boyunun eninin 2 kat� olmas�.
            //E�er oyun alan� 1'e e�itse buras� d�� �eper demektir.
            if(oyun[i][j]==1)
            {
                //Ascii de 219 de�eri olan karkteri ekrana basar.
                printf("%c%c",219,219);
            }
            //E�er oyun alan� 100'e e�itse burada yem var demektir.
            else if(oyun[i][j]==100)
            {
                //Ascii de 254 de�eri olan karkteri ekrana basar.
                printf("%c ",254);
            }
            //E�er oyun alan� 0'a e�itse burada hi� bir�ey yok demektir.
            else if(oyun[i][j]==0)
            {
                //Bu alanda hi� bir�ey yoktur iki bo�luk karakteri konur.
                printf("  ");
            }
            //E�er oyun alan� 10'a e�itse burada y�lan�n bedeni var demektir.
            else if(oyun[i][j]==10)
            {
                //Ascii de 177 de�eri olan karkteri ekrana basar.
                printf("%c%c",177,177);
            }
            //E�er oyun alan� 11'a e�itse burada y�lan�n ba�� var demektir.
            else if(oyun[i][j]==11)
            {
                //Ascii de 232 de�eri olan karkteri ekrana basar.
                printf("%c%c",232,232);
            }
            //Oyun alan�y�n sa� �st k��esine skoru basar.
            if(i==0 && j==29)
            {
                printf("SCORE=%d",skor*5);
            }
        }
        printf("\n");
    }
    //Y�lan�n sonuna tekrar d�n�p y�lan�n oldu�u yerdeki de�erleri 0'a e�itlenmeli.
    //Bunun i�in y=yi i�lemi yap�l�r.
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
    int oyun[30][30]; //Oyun alan�n� tercihe ba�l� olarak 30x30 b�y�kl���nde olu�turdum.
    int i,j,boy=3,satir,sutun,sayac=1,bitis=0,yedigi_yem=0; //De�i�kenlerin neden tan�mland���n� kulland���m alanlarda anlayacaks�n�zd�r.
    char yon=100,eski_yon=100; //Bir ba�lang�� de�eri olarak 100 atama sebebim y�lan�n oyun ba�lang�c�nda sa� tarafa do�ru hareket etmeseni istemem.
    for(i=0; i<30; i++) //Oyun alan�n d�� �eperini belirtmek i�in 1 de�erini atad�m.
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
    struct yilan *ilan; //Y�lan�n ilk eleman� yani kuyru�unu g�steren pointer.
    struct yilan *root; //ilan pointer�n�n yede�i.
    ilan=malloc(sizeof(struct yilan)); //�lk elemana haf�zadan yer al�r�z.
    ilan->satir=9; // Y�lan yap�s�n�n �zelle�i olan satir'a bir ba�lang�� de�eri atar�z.
    ilan->sutun=7; // Y�lan yap�s�n�n �zelle�i olan sutun'a bir ba�lang�� de�eri atar�z.
    root=ilan;  //Yedek pointer'a atama yapar�z.
    ilan->sonraki=malloc(sizeof(struct yilan)); //Y�lan�n g�vde k�sm�na haf�zadan yer ay�r�r�z.
    ilan->sonraki->satir=9; //Y�lan�n g�vde k�sm�na ba�lang�� de�eri atar�z.
    ilan->sonraki->sutun=8;
    ilan->sonraki->sonraki=malloc(sizeof(struct yilan)); //Y�lan�n ba� k�sm�na haf�zadan yer ay�r�r�z.
    ilan->sonraki->sonraki->satir=9; //Y�lan�n ba� k�sm�na ba�lang�� de�eri atar�z.
    ilan->sonraki->sonraki->sutun=9;
    ilan->sonraki->sonraki->sonraki=NULL;
    int bas[2]= {9,9}; //Ba� k�sm�n�n tutdu�u de�erleri �zellikle ayr� bir dizede saklar�z.Sebebi ise sadece ekrana basarken oran�n ba� k�sm� oldu�nu bilerek daha rahat ekrana basmak.
    yem(oyun); //Oyun alan�na rastgele yem at�lmas� i�in yem fonksiyonu �a�r�l�r.
    printf("OYUNA BASLAMAK ICIN HERHANGI BIR TUSA BASIN!!!");
    getch(); //Oyuna ba�layabilmek i�in getch fonksiyonun herhangi bir tu�a basd�ktan sonra enter'a basmadan okumas� �zelle�ini kulland�m.
    do
    {

        if (1)//Bu k�sma geldi�i s�rece bu s�reci uygulamas�n i�in ko�ul blo�unun i�ine 1 yazd�m.
        {
            Sleep(100); //sleep fonksiyonu sayesinde 100 milisaniye oyun ak��� engelleniyor.Bu fonksiyonu kullanmam�zdaki ama� Bilgisayar� e�er yava�latmazsak oyunun �ok h�zl� akaca�� ve oynanamaz hal alams�.
            if (kbhit()) //kbhit fonksiyonunu kullanmam�zdaki ama� kullan�c�n�n bir tu�a bas�p basmad���n� tespit etmek e�er basmazsa y�lan�n eski y�n�nde devam etmesini sa�lamak.
            {

                yon =getch(); //E�er tu�a bas�l�rsa bubu saklamak i�in yon'e atar�z.
            }
        }




        if(yon==87 || yon==119) //E�er 'w' veya 'W' ya bas�lm��sa yani yukar� y�nde gidilmesi isteniyorsa,
        {
            if(eski_yon==83 || eski_yon==115) //Fakat eski y�n� a�a�� tarafa do�ruysa,
            {
                yon=eski_yon; //Eski y�n� yeni y�ne atar�z ��nk� y�lan kendi i�inden ge�emez.
            }
        }
        else if(yon==68 || yon==100) //E�er 'd' veya 'D' ya bas�lm��sa yani sa� tarafa gidilmesi isteniyorsa,
        {
            if(eski_yon==97 || eski_yon==65) //Fakat eski y�n� sol tarafa do�ruysa,
            {
                yon=eski_yon; //Eski y�n� yeni y�ne atar�z ��nk� y�lan kendi i�inden ge�emez.
            }
        }
        else if(yon==83 || yon==115) //E�er 's' veya 'S' ya bas�lm��sa yani a�a�� y�nde gidilmesi isteniyorsa,
        {
            if(eski_yon==87 || eski_yon==119) //Fakat eski y�n� yukar� tarafa do�ruysa,
            {
                yon=eski_yon; //Eski y�n� yeni y�ne atar�z ��nk� y�lan kendi i�inden ge�emez.
            }
        }
        else if(yon==65 || yon==97) //E�er 'a' veya 'A' ya bas�lm��sa yani sol tarafa gidilmesi isteniyorsa,
        {
            if(eski_yon==68 || eski_yon==100) //Fakat eski y�n� sa� tarafa do�ruysa,
            {
                yon=eski_yon; //Eski y�n� yeni y�ne atar�z ��nk� y�lan kendi i�inden ge�emez.
            }
        }
        if(yon!=87 && yon!=119 && yon!=68 && yon!=100 && yon!=83 && yon!=115 && yon!=65 && yon!=97) //Bu blok e�er tu�a bas�lmazsa eski y�nde devam etmesi i�in yaz�lm��t�r.
        {
            yon=eski_yon; //Veya "w,a,s,d" den ba�ka tu�a bas�lm��sa �nemsememesi i�in yaz�lm��t�r.
        }

        // ilerle fonksiyonu y�lan�n y�n do�rultusunda ilerlemesini sa�lar.
        if(yon== 87 || yon==119) //E�er 'w' ya bas�lm��sa ilerle fonksiyonuna 1 parametresini g�ndeririz.
        {
            root=ilerle(root,1,&boy,sayac,bas); //1 burda yukar� y�n� temsil eder.
        }
        else if(yon==100 || yon==68) //E�er 'd' ye bas�lm��sa ilerle fonksiyonuna 2 parametresini g�ndeririz.
        {
            root=ilerle(root,2,&boy,sayac,bas); //2 burda yukar� y�n� temsil eder.
        }
        else if(yon==115 || yon==83) //E�er 's' e bas�lm��sa ilerle fonksiyonuna 3 parametresini g�ndeririz.
        {
            root=ilerle(root,3,&boy,sayac,bas); //3 burda yukar� y�n� temsil eder.
        }
        else if(yon==97 || yon==65) //E�er 'a' ya bas�lm��sa ilerle fonksiyonuna 4 parametresini g�ndeririz.
        {
            root=ilerle(root,4,&boy,sayac,bas); //4 burda yukar� y�n� temsil eder.
        }
        eski_yon=yon; //Art�k ilerledi�imiz y�n eski y�n�m�z oldu�una g�re.
        ilan=root; //"root" ilerle fonksiyonundan d�nd���nde y�lan�n kuyru�unu g�steriyor olacak fakat "ilan" hi�bir de�i�ikli�e u�ramad��� i�in y�lan�n g�vdesini g�sterecek.
        system("CLS");//Konsoldaki yaz�lan t�m verileri silmeye yarayan fonksiyon. Haritadaki ilerlemeyi g�stermek i�in t�m verileri sileriz.
        yazdir(root,ilan,oyun,boy,bas,&bitis,yedigi_yem); //Ve yeni halini ekrana basar�z.
        sayac=0; //E�er sayac 0'a e�itse y�lan yemi� demektir. B�yle de�i�keni tutmaktaki ama� y�lan e�er yemi yemi�se oyun alan�na yeni bir yem atmak ve skor'u hesaplayabilmek i�in.
        for(i=0; i<30; i++) //Oyun alan�n�n tamam�n� dola�arak yemin olup olmad���n� kontrol eden yap�.
        {
            for(j=0; j<30; j++)
            {
                if(oyun[i][j]==100)
                    sayac++; // E�er matrisin de�eri 100 ise yani yem varsa orda sayac 1 artar.
            }
        }
        if(sayac==0) // sayac 0'a e�itse yani oyun alan�nda hi� yem yoksa,
        {
            yedigi_yem++; //Yedi�i yem say�s� 1 artt�r�l�r.
            yem(oyun); //Ve oyun alan�na yeni bir yem at�lmas� i�in yem fonksiyonu �a�r�l�r.
        }

    }
    while(bitis==0); //Oyunun bitip bitmemesi gerekti�ini kontrol eden de�i�ken, illerle fonksiyonu i�inde pointer yard�m�yla de�eri de�i�tirilebiliyor.
    printf("OYUN  BITTI!!!   SKOR:%d\a",yedigi_yem*5); //OYUN  BITTI!!!
    return 0;
}
