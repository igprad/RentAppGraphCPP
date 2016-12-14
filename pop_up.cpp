#include "header.h"

void pop_up_entri_staff(ListStaff &S,Staff DataStaff,int key)
{

	setcolor(15,12);
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,33);cout<<"                                                                                                 "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	do{
		do{
				gotoxy(13,33);cout<<"        NIP Staff	: ";cin>>DataStaff.NIP;
				if(isFound_Staff(S,DataStaff.NIP))
				{
					setcolor(15,12);
					gotoxy(33,32);cout<<"                                       "<<endl;
					gotoxy(33,33);cout<<"                                       "<<endl;
					gotoxy(33,34);cout<<"        Staff Sudah Terdaftar          "<<endl;
					gotoxy(33,35);cout<<"                                       "<<endl;
					gotoxy(33,36);cout<<"                                       "<<endl;
					gotoxy(33,37);cout<<"                                       "<<endl;
				}	
		}while(isFound_Staff(S,DataStaff.NIP));
		gotoxy(33,34);cout<<"                                     "<<endl;
		gotoxy(13,35);cout<<"        NAMA	: ";cin>>DataStaff.Nama;
		setcolor(0,0);
		entri_staff(S,DataStaff);
	}while(key!=ESC&&key!=ENTER);

}

void pop_up_entri_Mobil(ListMobil &M,Mobil DataMobil,int key)
{
	
	setcolor(15,12);
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,33);cout<<"                                                                                                 "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	do{
			gotoxy(22,33);cout<<"Merk Mobil	: ";cin>>DataMobil.Merk;
			if(!CekMerkLolos(DataMobil))
			{
				gotoxy(33,32);cout<<"                                       "<<endl;
				gotoxy(33,33);cout<<"                                       "<<endl;
				gotoxy(33,34);cout<<"          Merk Mobil Salah!            "<<endl;
				gotoxy(33,35);cout<<"        Silahkan lihat Help!           "<<endl;
				gotoxy(33,36);cout<<"                                       "<<endl;
				gotoxy(33,37);cout<<"                                       "<<endl;
			}
	}while(!CekMerkLolos(DataMobil));
				gotoxy(33,34);cout<<"                                       "<<endl;
				gotoxy(33,35);cout<<"                                       "<<endl;
	do{
		gotoxy(22,33);cout<<"Merk Mobil	: "<<DataMobil.Merk<<endl;
		gotoxy(33,34);cout<<"                                       "<<endl;
		gotoxy(33,35);cout<<"                                       "<<endl;
		gotoxy(22,35);cout<<"Plat Mobil	: ";cin>>DataMobil.No_Plat;
		if(!CekPlatLolos(DataMobil.No_Plat))
		{
			gotoxy(33,32);cout<<"                                       "<<endl;
			gotoxy(33,33);cout<<"                                       "<<endl;
			gotoxy(33,34);cout<<"          Plat Mobil Salah!            "<<endl;
			gotoxy(33,35);cout<<"         Silahkan lihat Help!          "<<endl;
			gotoxy(33,36);cout<<"                                       "<<endl;
			gotoxy(33,37);cout<<"                                       "<<endl;
			getch();
		}
			else if(isFound_Mobil(M,DataMobil.No_Plat))
			{
				gotoxy(33,32);cout<<"                                       "<<endl;
				gotoxy(33,33);cout<<"                                       "<<endl;
				gotoxy(33,34);cout<<"       Mobil Sudah Terdaftar           "<<endl;
				gotoxy(33,35);cout<<"                                       "<<endl;
				gotoxy(33,36);cout<<"                                       "<<endl;
				gotoxy(33,37);cout<<"                                       "<<endl;
				getch();
			}
	}while(!CekPlatLolos(DataMobil.No_Plat)||isFound_Mobil(M,DataMobil.No_Plat));

			gotoxy(22,33);cout<<"Merk Mobil	: "<<DataMobil.Merk<<endl;
			gotoxy(33,34);cout<<"                                       "<<endl;
			gotoxy(33,35);cout<<"                                       "<<endl;
	setcolor(0,0);
	entri_mobil(M,DataMobil);
}

void pop_up_entri_pinjam(ListPinjam &P,ListStaff S,ListMobil M,string pil_entri,int entri_nip,int key)
{
	
	setcolor(15,12);
	gotoxy(12,31);cout<<"                                                                                                 "<<endl;
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,33);cout<<"                                                                                                 "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	if(IsEmpty_Mobil(M)&&IsEmpty_Staff(S))
	{	
		gotoxy(33,32);cout<<"             Daftar Mobil dan Staff masih kosong"<<endl;
		gotoxy(33,34);cout<<"  Silahkan entri data staff dan data mobil terlebih dahulu"<<endl;
		getch();
	}
		else if(IsEmpty_Mobil(M))
		{
			gotoxy(33,35);cout<<"       Belum ada mobil yang di daftarkan!"<<endl;
			getch();
		}
			else if(IsEmpty_Staff(S))
			{
				gotoxy(33,35);cout<<"       Belum ada Staff yang di daftarkan!"<<endl;
				getch();
			}

	else if(isLessData_Peminjaman(P,M))
	{
		pop_up_kurang_data();
		getch();
	}
	
	else
	{
		do{
			gotoxy(43,33);cout<<"                                             "<<endl;
			gotoxy(22,33);cout<<"Masukkan NIP staff : ";cin>>entri_nip;
			if(!isFound_Staff(S,entri_nip))
			{
				
				gotoxy(43,33);cout<<"                       Staff tidak ditemukan!"<<endl;
				getch();
				gotoxy(43,33);cout<<"                                             "<<endl;
			}
		}while(!isFound_Staff(S,entri_nip));
					
		do{
			gotoxy(22,35);cout<<"Masukkan No.Plat mobil : ";cin>>pil_entri;
			if(!isFound_Mobil(M,pil_entri))
			{
				gotoxy(43,35);cout<<"                       Mobil tidak ditemukan!"<<endl;
				getch();
				gotoxy(43,35);cout<<"                                             "<<endl;
			}
			else if(isFound_Mobil_onPinjam(P,pil_entri))
			{
				gotoxy(43,35);cout<<"                       Mobil sudah dipinjam !"<<endl;
				getch(); 
				gotoxy(43,35);cout<<"                                             "<<endl;
			}
		}while(!isFound_Mobil(M,pil_entri)||isFound_Mobil_onPinjam(P,pil_entri));
		pinjam(P,S,M,entri_nip,pil_entri);	
	}
	setcolor(0,0);
}

void pop_up_pinjam_list_tersedia(ListPinjam P,ListStaff S,ListMobil M,int key)
{
	int x0=22,y0=40;
	int x1=22,y1=43;
	setcolor(0,14);
	gotoxy(12,38);cout<<"                                                                                                 "<<endl;
	gotoxy(12,39);cout<<"                            List Staff dan Mobil Tersedia                                        "<<endl;
	gotoxy(12,40);cout<<"  Staff :                                                                                        "<<endl;
	gotoxy(12,41);cout<<"                                                                                                 "<<endl;
	gotoxy(12,42);cout<<"                                                                                                 "<<endl;
	gotoxy(12,43);cout<<"  Mobil :                                                                                        "<<endl;
	gotoxy(12,44);cout<<"                                                                                                 "<<endl;
	while(S.First!=NULL)
	{
			gotoxy(x0,y0);cout<<S.First->Data.NIP<<endl;
			x0+=9;
		S.First=S.First->Next;
	}
	while(M.First!=NULL)
	{
		if(!isFound_Mobil_onPinjam(P,M.First->Data.No_Plat))
		{
			gotoxy(x1,y1);cout<<M.First->Data.No_Plat<<endl;
			x1+=9;
		}

		M.First=M.First->Next;
	}
}


void pop_up_hapus_pinjam(ListPinjam &P,ListStaff S,ListMobil M,string pil_entri,int entri_nip,int key)
{
	setcolor(15,12);
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,33);cout<<"                                                                                                 "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	if(IsEmpty_Peminjaman(P))
	{
		gotoxy(33,33);cout<<"             Peminjaman masih kosong"<<endl;
		gotoxy(33,35);cout<<"  Silahkan entri data peminjaman mobil terlebih dahulu"<<endl;
	}
	else
	{
		do{
				gotoxy(43,33);cout<<"                                             "<<endl;
				gotoxy(22,33);cout<<"Masukkan NIP staff : ";cin>>entri_nip;
				if(!isFound_Staff_onPinjam(P,entri_nip))
				{
					
					gotoxy(43,33);cout<<"                       Staff tidak ditemukan!"<<endl;
					getch();
					gotoxy(43,33);cout<<"                                             "<<endl;
				}
			}while(!isFound_Staff_onPinjam(P,entri_nip));
						
			do{
				gotoxy(22,35);cout<<"Masukkan No.Plat mobil : ";cin>>pil_entri;
				if(!isFound_Mobil_onPinjam(P,pil_entri))
				{
					gotoxy(43,35);cout<<"                       Mobil tidak ditemukan!"<<endl;
					getch(); 
					gotoxy(43,35);cout<<"                                             "<<endl;
				}
			}while(!isFound_Mobil_onPinjam(P,pil_entri));
			pengembalian(P,entri_nip,pil_entri);	
	}
}

void pop_up_peminjaman_staff(ListPinjam P,int &entri_nip,int key)
{
	setcolor(15,12);
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,33);cout<<"                                                                                                 "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	if(IsEmpty_Peminjaman(P))
	{
		setcolor(15,12);
		gotoxy(33,33);cout<<"             Peminjaman masih kosong"<<endl;
		gotoxy(33,35);cout<<"  Silahkan entri data peminjaman mobil terlebih dahulu"<<endl;
	}
	else
	{
		setcolor(15,12);
		do{
				gotoxy(43,33);cout<<"                                             "<<endl;
				gotoxy(22,33);cout<<"Masukkan NIP staff : ";cin>>entri_nip;
				if(!isFound_Staff_onPinjam(P,entri_nip))
				{
					
					gotoxy(43,33);cout<<"                       Staff tidak ditemukan!"<<endl;
					getch();
					gotoxy(43,33);cout<<"                                             "<<endl;
				}
			}while(!isFound_Staff_onPinjam(P,entri_nip));
		pop_up_peminjaman_staff_display(P,entri_nip,key);
	}
}

void pop_up_peminjaman_staff_display(ListPinjam P,int entri_nip,int key)
{
	address3 pt=P.First;
	int x0=31,y0=16;
	int x=16,y=20;
	setcolor(15,12);
	gotoxy(12,16);cout<<"   STAFF PEMINJAM :                                                                              "<<endl;
	gotoxy(12,15);cout<<"                                                                                                 "<<endl;
	gotoxy(12,17);cout<<"                                                                                                 "<<endl;
	gotoxy(12,18);cout<<"   MOBIL DIPINJAM :                                                                              "<<endl;
	gotoxy(12,19);cout<<"                                                                                                 "<<endl;
	gotoxy(12,20);cout<<"                                                                                                 "<<endl;
	gotoxy(12,21);cout<<"                                                                                                 "<<endl;
	gotoxy(12,22);cout<<"                                                                                                 "<<endl;
	gotoxy(12,23);cout<<"                                                                                                 "<<endl;
	gotoxy(12,24);cout<<"                                                                                                 "<<endl;
	gotoxy(12,25);cout<<"                                                                                                 "<<endl;
	gotoxy(12,26);cout<<"                                                                                                 "<<endl;
	gotoxy(12,27);cout<<"                                                                                                 "<<endl;
	gotoxy(12,28);cout<<"                                                                                                 "<<endl;
	gotoxy(12,29);cout<<"                                                                                                 "<<endl;
	gotoxy(12,30);cout<<"                                                                                                 "<<endl;
	gotoxy(12,31);cout<<"                                                                                                 "<<endl;
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,33);cout<<"                                                                                                 "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;

	gotoxy(x0+2,y0);cout<<entri_nip<<endl;
	while(pt!=NULL)
	{
		if(pt->data.NIP_Pinjam==entri_nip)
		{
			setcolor(15,12);
			gotoxy(x,y);cout<<pt->data.No_Plat_Pinjam<<"  -  "<<pt->data.Merk_Pinjam<<endl;
			y++;
			pt=pt->Next;
		}
	}
}

void pop_up_help_staff()
{
	setcolor(0,14);
	gotoxy(12,31);cout<<"                                                                                                 "<<endl;
	gotoxy(12,32);cout<<"                                      HELP - STAFF                                               "<<endl;
	gotoxy(12,33);cout<<" 1. NIP Staff tidak dimulai dengan angka 0, dan hanya boleh memasukkan angka.                    "<<endl;
	gotoxy(12,34);cout<<" 2. Nama Staff tidak boleh menggunakan karakter selain karakter alfabetik(A-Z,a-z)               "<<endl;
	gotoxy(12,35);cout<<" 3. NIP harus UNIK, silahkan lihat tabel inputan yang ada untuk melihat nip yang sudah terdaftar "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	setcolor(0,0);
}

void pop_up_help_mobil()
{
	setcolor(0,14);
	gotoxy(12,31);cout<<"                                                                                                 "<<endl;
	gotoxy(12,32);cout<<"                                      HELP - MOBIL                                               "<<endl;
	gotoxy(12,33);cout<<" 1. Merk Mobil yang tersedia adalah sebagai berikut:                                             "<<endl;
	gotoxy(12,34);cout<<"    [ honda, toyota, daihatsu, nissan, suzuki, kia, mitsubishi, bmw, isuzu, datsun].             "<<endl;
	gotoxy(12,35);cout<<" 2. No. Plat harus unik, mohon cek tabel untuk melihat mobil yang sudah didaftarkan.             "<<endl;
	gotoxy(12,36);cout<<" 3. Plat Jogja,maka harus berawalan AB, diikuti dengan angka maximal 4 digit                     "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	setcolor(0,0);
}

void pop_up_help_peminjaman()
{
	setcolor(0,14);
	gotoxy(12,31);cout<<"                                                                                                 "<<endl;
	gotoxy(12,32);cout<<"                                      HELP - PEMINJAMAN                                          "<<endl;
	gotoxy(12,33);cout<<" 1. Terlebih dahulu menginputkan data mobil dan data staff, sebelum meminjam!                    "<<endl;
	gotoxy(12,34);cout<<" 2. Staff dapat meminjam mobil yang belum ada di daftar peminjaman                               "<<endl;
	gotoxy(12,35);cout<<" 3. Mobil hanya dapat satu kali dipinjam                                                         "<<endl;
	gotoxy(12,36);cout<<" 4. Staff dan mobil yang tersedia adalah sebagai berikut.                                        "<<endl;
	gotoxy(12,37);cout<<"                                                                                                 "<<endl;
	setcolor(0,0);
}

void pop_up_kosong_data()
{
	setcolor(15,12);
	gotoxy(12,33);cout<<"                                      PERINGATAN!!!                                              "<<endl;
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"                     Data Kosong ! Harap Input Data Terlebih Dahulu !                            "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	setcolor(0,0);
}

void pop_up_kurang_data()
{
	setcolor(15,12);
	gotoxy(12,33);cout<<"                                      PERINGATAN!!!                                              "<<endl;
	gotoxy(12,32);cout<<"                                                                                                 "<<endl;
	gotoxy(12,35);cout<<"              Seluruh Mobil sedang dipinjam ! Harap Input Mobil Terlebih Dahulu !                "<<endl;
	gotoxy(12,34);cout<<"                                                                                                 "<<endl;
	gotoxy(12,36);cout<<"                                                                                                 "<<endl;
	setcolor(0,0);
}

void pop_up_ketentuan_mobil()
{
	setcolor(0,14);
	gotoxy(12,38);cout<<"                                                                                                 "<<endl;
	gotoxy(12,39);cout<<"                               Ketentuan Input Data Mobil                                        "<<endl;
	gotoxy(12,40);cout<<"                                                                                                 "<<endl;
	gotoxy(12,41);cout<<"  Merk : honda, toyota, daihatsu, nissan, suzuki, kia, mitsubishi, bmw, isuzu, datsun.           "<<endl;
	gotoxy(12,42);cout<<"                                                                                                 "<<endl;
	gotoxy(12,43);cout<<"  Plat : ABxxxx atau ABxxx atau ABxx atau ABx, x=nomor:0-9.                                      "<<endl;
	gotoxy(12,44);cout<<"                                                                                                 "<<endl;
}
