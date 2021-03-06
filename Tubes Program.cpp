/***************************************************************************************************
TUGAS BESAR PEMROGRAMAN KELOMPOK 17
ANGGOTA :
1. Ni Luh Yunita Ardiani (2105551025)
2. Ni Kadek Intan Diana Putri (2105551026)
JUDUL PROGRAM	: PROGRAM KASIR GANDI LAUNDRY
****************************************************************************************************/

#include <stdio.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdlib.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <string.h>		//Header yang di gunakan untuk operasi string pada bahasa C
#include <time.h>		//Header yang di gunakan untuk operasi pada bahasa C


int main ()
{

//STRUCT USER DATA PENGGUNA

	struct User
	{
    	char nama[30];
    	char email[30];
    	char username[30];
    	char password[30];
    	char alamat[30];	 
	};

// DATA ADMIN

	char nama_admin[50];
	char password_admin[50];
	char kode_admin [10];
	char admin;

//DATA PELANGGAN
	
	int tanggal;
	int berat;
	int total1;
	float total_bayar;
	float diskon;
	float bayar;
	float kembalian;
	char kategori;
	
// HARGA PAKAIAN LAUNDRY

	int jml;
	int total2 = 0;
	int kode;
	int harga [15] = {500,800,1000,1500,600,2000,2000,2500,5000,3000,3500,2000,2000,1500,3000};

//PENGULANGAN DAN PILIHAN LOGIN ADMIN

	char keluar;
	char pilih;
	
//TANGGAL

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

  	// tampilan header
	system("cls");
	printf("+----------------------------------------------------------+\n");
	printf("|                Program Kasir GandiLaundry                |\n");
	printf("+----------------------------------------------------------+\n");
	printf("|                                                          |\n");
	printf("|                      Dibuat Oleh :                       |\n");
	printf("|                                                          |\n");
	printf("|                  Ni Luh Yunita Ardiani                   |\n");
	printf("|                NiKadek Intan Diana Putri                 |\n");
	printf("|                                                          |\n");
	printf("+----------------------------------------------------------+\n");
	printf("\n\n");
	printf("| ===================== SELAMAT DATANG =================== |\n");
	printf("|               PROGRAM KASIR GANDI LAUNDRY                |\n");
	printf("| ======================================================== |\n");

	printf ("\n");
	printf ("\n");
	printf ("\n");
	printf("********************** LOGIN ADMIN **********************\n");
	kembali:
	printf(" Username : ");
	scanf("%s", nama_admin);
	printf(" Password : ");
	scanf("%s", password_admin);
	printf("=========================================================\n");
	
        if(strcmp(nama_admin,"gandi1")==0 && strcmp(password_admin,"admin1")==0){
        	strcpy(nama_admin, "Ni Luh Yunita Ardiani");
        	strcpy(kode_admin, "1");
		
		
        	printf("\n                  >>>> LOGIN BERHASIL! <<<<      \n");
		
        } else if(strcmp(nama_admin,"gandi2")==0 && strcmp(password_admin,"admin2")==0){
            strcpy(nama_admin, "Ni Kadek Intan Diana Putri");
            strcpy(kode_admin, "2");
			
            printf("                   >>>> LOGIN BERHASIL! <<<<      \n");
       }
       
       
    else
	{
    printf("Mohon maaf, Username dan Password anda Salah!\n");
    printf("Tekan Y untuk kembali atau tekan T untuk keluar : ");
		scanf("%s", &pilih);


		if (pilih== 'Y' || pilih== 'y'){
			goto kembali;
		}
		else if (pilih== 'T' || pilih== 't')
		{
			goto keluar;
		}
		}
	
	//	 Registrasi & login pelanggan
    struct User datapengguna;
    int pilihan;
    char nama[30];
    char email[30];
    char username[30];
    char password[30];
    char alamat[30];

	
   // REGISTRASI 

    void daftar();
	{
    // Membuat pointer registrasi untuk file "dataregis.txt"
    FILE *registrasi;
    // Membuka file "dataregis.txt" dengan mode append
    registrasi = fopen("dataregis","a");
    if (registrasi == NULL)
    {
    	fputs("Tidak terdapat FILE!!", stderr);
        exit(1);
    }

// input  data untuk registrasi
    menu:
    system("cls");
    printf("|==============================================|\n");
    printf("|      Selamat Datang Di Gandi Laundry         |\n");
    printf("|----------------------------------------------|\n");
    printf("================================================\n");
    printf("     Silahkan registrasi terlebih dahulu! 		\n");
    printf("------------------------------------------------\n");
    getchar();
    printf("\n Masukan Nama 		: ");
    scanf("\n%[^\n]s", & datapengguna.nama);
    printf("\n Masukan Email 		: ");
    scanf("\n%[^\n]s", & datapengguna.email);
    printf("\n Masukan Alamat 	: ");
    scanf("\n%[^\n]s", & datapengguna.alamat);
    
	    
    system("cls");
    printf("|==========================================|\n");
    printf("      Selamat Datang %s!\n",datapengguna.nama  );
    printf("|------------------------------------------|\n");
    printf("|Silahkan input username (max 10)          |\n");
    printf("|Silahkan input password (max 8)           |\n");
    printf("|==========================================|\n"); 
	
	// input username dan password yang akan digunakan
    printf("\n Masukan Username 	: ");
    scanf("\n%[^\n]s", & datapengguna.username);
    printf("\n Masukan Password 	: ");
    scanf("\n%[^\n]s", & datapengguna.password);
        
        
    fwrite(&datapengguna,sizeof(datapengguna),1,registrasi);
    //print new line agar data lain tidak berada di satu baris yang sama
    fprintf(registrasi, "\n");               
    fclose(registrasi);
    getchar();
    system ("cls");
  }
   
	
	system("cls");
	Login:
    	printf("|=============================|\n");
    	printf("|        Gandi Laundry        |\n");
    	printf("|                             |\n");
    	printf("|-----------------------------|\n");
    	printf("|       Silahkan Login        |\n");
    	printf("|                             |\n");
    	printf("|=============================|\n");
    	
        printf("\n\n Masukan Username 	: ");
        scanf("%s", &username);
        
        printf("\n Masukan Password 	: ");
        scanf("\n%s", &password);

        if (strcmp(datapengguna.username,username) == 0 && strcmp(datapengguna.password,password) == 0)
        {
          printf("\n Anda berhasil Login");
          system ("cls");
          printf("\n==========================|");
        
        }else
        {
            printf("\n Anda tidak berhasil Login\n");
            printf("\n Silahkan ENTER untuk kembali ke MENU!");
            pilihan = 0;
        	goto Login;
            
        }

       

	// Menu Laundry
	system("cls");
	printf("\n|================ PILIHAN MENU =================|\n");
	printf("|Menu Lundry : 				\t|\n");
	printf("|\t1.Kiloan 			\t|\n");
	printf("|\t2.Satuan 			\t|\n");
        printf("|===============================================|\n");
	printf("\nSilahkan Pilih Menu 	: ");
	scanf("%i", & pilih);
	
	
	if (pilih == 1)
	{
	kategori:
        printf("\n");
        printf("\n|===============================================|\n");
	printf("|Kategori Cucian :				|\n");
	printf("|\t1.Kilat					|\n");
	printf("|\t2.Express					|\n");
	printf("|\t3.Biasa					|\n");
	printf("|\t4.Setrika					|\n");
    	printf("|===============================================|\n");
	printf("\nMasukkan kategori cucian : ");
	scanf("%i", & kategori);
	
	
	system("cls");
	switch (kategori)
	{
	case (1):
		printf ("\n++----------------------------------------------++\n");
		printf ("++   	  ANDA MEMILIH KATEGORI KILAT		++\n" );
		printf ("++   	  Biaya Kategori Kilat = 15000 		++\n");
		printf ("++----------------------------------------------++\n");
		printf ("\n");
		printf ("Masukkan Berat (kg) : ");
		scanf ("%i", &berat);
		total1 = 15000 * berat;
			
			if (berat >=5)
			{
				diskon = 10000;
				total_bayar = 15000*berat-10000;
				printf ("\n");
				printf("\n                  >>>> SELAMAT ANDA MENDAPAT DISKON --> 10000 <<<<      \n");
			}
			else if (berat <5)
			{
				total_bayar = 15000*berat;
				printf ("\n");
				printf("\n                  >>>> ANDA TIDAK MENDAPATKAN DISKON <<<<      \n");
			}
				printf ("\n");
				break;
	
	case (2):
		printf ("\n++----------------------------------------------++\n");
		printf ("++   	  ANDA MEMILIH KATEGORI EXPRESS		++\n" );
		printf ("++   	  Biaya Kategori Express = 13000/kg	++\n");
		printf ("++----------------------------------------------++\n");
		printf ("\n");
		printf ("Masukkan Berat (kg) : ");
		scanf ("%i", &berat);
		total1 = 13000 * berat;
			
			if (berat >=5)
			{
				diskon = 8000;
				total_bayar = 13000*berat-8000;
				printf ("\n");
				printf("\n                  >>>> SELAMAT ANDA MENDAPAT DISKON --> 8000 <<<<      \n");
			}
			else if (berat <5)
			{
				total_bayar = 13000*berat;
				printf ("\n");
				printf("\n                  >>>> ANDA TIDAK MENDAPATKAN DISKON <<<<      \n");
			}
			printf ("\n");
			break;
			
	case (3):
		printf ("\n++----------------------------------------------++\n");
		printf ("++   	  ANDA MEMILIH KATEGORI BIASA		++\n" );
		printf ("++   	  Biaya Kategori Biasa = 10000/kg	++\n");
		printf ("++----------------------------------------------++\n");
		printf ("\n");
		printf ("Masukkan Berat (kg) : ");
		scanf ("%i", &berat);
		total1 = 10000 * berat;
			
			if (berat >=5)
			{
				diskon = 7000;
				total_bayar = 10000*berat-7000;
				printf ("\n");
				printf("\n                  >>>> SELAMAT ANDA MENDAPAT DISKON --> 7000 <<<<      \n");
			}
			else if (berat <5)
			{
				total_bayar = 10000*berat;
				printf ("\n");
				printf("\n                  >>>> ANDA TIDAK MENDAPATKAN DISKON <<<<      \n");
			}
				printf ("\n");
				break;
			
	case (4):
		printf ("\n++----------------------------------------------++\n");
		printf ("++   	  ANDA MEMILIH KATEGORI SETRIKA		++\n" );
		printf ("++   	  Biaya Kategori Setrika = 8000/kg	++\n");
		printf ("++----------------------------------------------++\n");
		printf ("\n");
		printf ("Masukkan Berat (kg) : ");
		scanf ("%i", &berat);
		total1 = 8000 * berat;
			
			if (berat >=5)
			{
				diskon = 5000;
				total_bayar = 8000*berat-5000;
				printf ("\n");
				printf("\n                  >>>> SELAMAT ANDA MENDAPAT DISKON --> 5000 <<<<      \n");
			}
			else if (berat <5)
			{
				total_bayar = 8000*berat;
				printf ("\n");
				printf("\n                  >>>> ANDA TIDAK MENDAPATKAN DISKON <<<<      \n");
			}
				printf ("\n");
				break;
			
		 }
				
			
	{
			printf ("|--------------------------------------------------------|");
			printf ("\n");
			printf ("| Total 			: %i \t\t |\n",total1);
			printf ("| Total Bayar			: %.0f \t\t |\n",total_bayar);
			printf ("|--------------------------------------------------------|\n");
			
// Rumus Bayar

			printf ("\n");
			printf ("Masukkan Jumlah Uang Anda	: ");
			scanf ("%f", &bayar);

// Rumus Kembalian

			kembalian = bayar-total_bayar;

	}



// Struk Laundry Menu 1
		
	FILE*struk;
		
	struk=fopen("riwayattransaksi","a");	

	system("cls");
	printf("|================= STRUK GANDI LAUNDRY ==================|\n");
	printf("| \t\t\t\t\t\t\t |\n");
	printf("| Nama Admin  		: %s  \t |\n", nama_admin);
	printf("| Kode Admin   		: %s  \t\t\t\t |\n", kode_admin);
	printf("| Tanggal Pembayaran	: %02d-%02d-%d  \t\t\t |\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("| \t\t\t\t\t\t\t |\n");
	printf("|--------------------------------------------------------|\n");
	printf("| \t\t\t\t\t\t\t |\n");
	printf("| Nama Pelanggan	: %s \t\t\t |\n", datapengguna.nama);
	printf("| Email Pelanggan	: %s \t\t |\n", datapengguna.email);
	printf("| Alamat Pelanggan	: %s \t\t\t |\n",datapengguna.alamat);
	printf("| \t\t\t\t\t\t\t |\n");
	printf("|------------------------------------------------------- |\n");
	printf("| \t\t\t\t\t\t\t |\n");
	printf("| Pilihan Menu 		: %i \t\t\t\t |\n", pilih);
	printf("| Kategori Cucian 	: %i \t\t\t\t |\n",kategori);
	printf("| Berat (kg)		: %i \t\t\t\t |\n",berat);
	printf("| Total			: Rp. %i \t\t\t |\n",total1);
	printf("| Total Diskon 		: Rp. %.0f \t\t\t |\n", diskon);
	printf("| Total Bayar 		: Rp. %.0f \t\t\t |\n",total_bayar);
	printf("| Bayar			: Rp. %.0f \t\t\t |\n",bayar);
	printf("| Kembalian		: Rp. %.0f \t\t\t |\n",kembalian);
	printf("|========================================================|\n");
	
		
		
// menuliskan data yang diinput ke dalam  file riwattransaksi.txt
	
	fprintf(struk,"|================= STRUK GANDI LAUNDRY ==================\n");
	fprintf(struk,"| \t\t\t\t\t\t\t \n");
	fprintf(struk,"| Nama Admin  		: %s  \t\n", nama_admin);
	fprintf(struk,"| Kode Admin   		: %s  \t\t\t\t\n", kode_admin);
	fprintf(struk,"| Tanggal Pembayaran: %02d-%02d-%d  \t\t\t\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"|-------------------------------------------------------\n");
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"| Nama Pelanggan	: %s \t\t\t\n", datapengguna.nama);
	fprintf(struk,"| Email Pelanggan	: %s \t\t\n", datapengguna.email);
	fprintf(struk,"| Alamat Pelanggan	: %s \t\t\t\n",datapengguna.alamat);
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"|-------------------------------------------------------\n");
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"| Pilihan Menu 		: %i \t\t\t\t \n", pilih);
	fprintf(struk,"| Kategori Cucian 	: %i \t\t\t\t \n",kategori);
	fprintf(struk,"| Berat (kg)	    : %i \t\t\t\t \n",berat);
	fprintf(struk,"| Total				: Rp. %i \t\t\t \n",total1);
	fprintf(struk,"| Total Diskon 		: Rp. %.0f \t\t\t \n", diskon);
	fprintf(struk,"| Total Bayar 		: Rp. %.0f \t\t\t \n",total_bayar);
	fprintf(struk,"| Bayar	     		: Rp. %.0f \t\t\t \n",bayar);
	fprintf(struk,"| Kembalian	    	: Rp. %.0f \t\t\t \n",kembalian);
	fprintf(struk,"|========================================================\n");
	
	
fclose(struk);
	
	
	printf("\n\nTekan Y untuk kembali atau tekan T untuk keluar : ");
	scanf("%s",&pilih);



		if (pilih== 'Y' || pilih== 'y')
		{
			goto kembali;
		}
		else if (pilih== 'T' || pilih== 't')
		{
			goto keluar;
		}

  
		printf("\n                  ***** TERIMAKASIH TELAH MEMPERCAYAI GANDI LAUNDRY *****      \n");
		
		}
			
	

	else if (pilih==2)	
	{
		
	system("cls");
	printf("|-------------------------------------------------|\n");
	printf("|		  ANNOUCMENT!                     |\n");
	printf("|-------------------------------------------------|\n");
   	printf("|   - Masukkan kode pakaian <spasi> jumlahnya     |\n");  
   	printf("|   - Contoh: 1 2                                 |\n");  
   	printf("|   - Ketik 0 <spasi> 0                           |\n");  
   	printf("|    jika sudah selesai                           |\n"); 
   	printf("|-------------------------------------------------|\n\n");
   	
   	kode:
	printf("\n");  
	// data pakaian laundry disimpan pada file datapakaianlaundry.txt 
	{
	FILE*data;
	char a[100];
	data=fopen("datapakaianlaundry.txt","r");
	while(!feof(data))
	{
		fgets(a,100,data);
		printf("%s",a);
	}
	
	fclose(data);
}
	printf("\n");
	printf("\n");  
   	printf("\n            >>> MASUKKAN KODE PESANAN <<<               \n");  
   	printf("++------------------------------------------------------++\n");  
   
   		do
   		{  
		printf(" Kode Pesanan : ");  
     		scanf("%d %d", &kode, &jml);    
     		total2 = total2+(harga[(kode-1)]) * jml;  
     		if (kode>15)
     		{
     			printf ("\n           >>> KODE PAKAIAN TIDAK TERSEDIA <<< \n");
     			goto kode;
			 }
   		}
   		
   		while(kode != 0 && jml !=0);
   			printf ("---------------------- +\n");  
   			printf(" TOTAL HARGA : %d\n\n", total2);  
   
   
   
// Rumus Bayar
   
	printf ("Masukkan Jumlah Uang Anda : ");
	scanf ("%f", &bayar);

// Rumus Kembalian

	kembalian = bayar-total2;


// Struk Laundry Menu 2

  	FILE*struk;
	struk=fopen("riwayattransaksi","a");
	
  	system("cls");
	
	printf("|================= STRUK GANDI LAUNDRY =================|\n");
	printf("| \t\t\t\t\t\t\t|\n");
	printf("| Nama Admin  		: %s  \t|\n", nama_admin);
	printf("| Kode Admin   		: %s  \t\t\t\t|\n", kode_admin);
	printf("| Tanggal Pembayaran	: %02d-%02d-%d  \t\t\t|\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("| \t\t\t\t\t\t\t|\n");
	printf("|-------------------------------------------------------|\n");
	printf("| \t\t\t\t\t\t\t|\n");
	printf("| Nama Pelanggan	: %s \t\t\t|\n", datapengguna.nama);
	printf("| Email Pelanggan	: %s \t\t|\n", datapengguna.email);
	printf("| Alamat Pelanggan	: %s \t\t\t|\n",datapengguna.alamat);
	printf("| \t\t\t\t\t\t\t|\n");
	printf("|-------------------------------------------------------|\n");
	printf("| \t\t\t\t\t\t\t|\n");
	printf("| Pilihan Menu 		: %i \t\t\t\t|\n", pilih);
	printf("| Total			: Rp. %i \t\t\t|\n",total2);
	printf("| Bayar			: Rp. %.0f \t\t\t|\n",bayar);
	printf("| Kembalian		: Rp. %.0f \t\t\t|\n",kembalian);
	printf("|=======================================================|\n");
	
	
	// menuliskan data yang di input ke file riwayattransaksi
	
	fprintf(struk,"|================= STRUK GANDI LAUNDRY =================\n");
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"| Nama Admin  		: %s  \t\n", nama_admin);
	fprintf(struk,"| Kode Admin   		: %s  \t\t\t\t\n", kode_admin);
	fprintf(struk,"| Tanggal Pembayaran: %02d-%02d-%d  \t\t\t\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"|-------------------------------------------------------\n");
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"| Nama Pelanggan	: %s \t\t\t\n", datapengguna.nama);
	fprintf(struk,"| Email Pelanggan	: %s \t\t\n", datapengguna.email);
	fprintf(struk,"| Alamat Pelanggan	: %s \t\t\t\n",datapengguna.alamat);
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"|-------------------------------------------------------\n");
	fprintf(struk,"| \t\t\t\t\t\t\t\n");
	fprintf(struk,"| Pilihan Menu 		: %i \t\t\t\t\n", pilih);
	fprintf(struk,"| Total				: Rp. %i \t\t\t\n",total2);
	fprintf(struk,"| Bayar				: Rp. %.0f \t\t\t\n",bayar);
	fprintf(struk,"| Kembalian			: Rp. %.0f \t\t\t\n",kembalian);
	fprintf(struk,"|=======================================================\n");
	
	fclose(struk);
	
					
	printf("\n\nTekan Y untuk kembali atau tekan T untuk keluar : ");
	scanf("%s",&pilih);

		if (pilih== 'Y' || pilih== 'y')
		{
			goto kembali;
		}
		else if (pilih== 'T' || pilih== 't')
		{
			goto keluar;
		}

 	keluar :
			
  	
	printf("\n                  ** TERIMAKASIH TELAH MEMPERCAYAI GANDI LAUNDRY **      \n");
  
   
   return 0;
}
}
}		
			
