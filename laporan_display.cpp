#include "header.h"

void laporan_staff_display(ListStaff S,int key)
{
	int x=11,y=12;
	int x0=18,y0=12;
	int x1=34,y1=12;
	int i=1;
	address1 pt=S.First;
	address1 next=S.First;
	address1 prev=S.First;

		system("cls");
		setcolor(15,21);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                                          === LAPORAN ===                                            "<<endl;
		gotoxy(10,6);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,7);cout<<"                              Ini Adalah Data Staff yang sudah dipinjam                              "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		setcolor(0,15);
		
		setcolor(15,0);
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =             NIP                 =                          NAMA                            = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;
		setcolor(0,0);

		if(IsEmpty_Staff(S))
		{
			setcolor(15,0);
			gotoxy(23,y);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(pt!=NULL)
			{
				setcolor(15,0);
				gotoxy(x,y);cout<<"= "<<i<<endl;gotoxy(x+4,y);cout<<" ="<<endl;
				gotoxy(50,y);cout<<"="<<endl;gotoxy(109,y);cout<<"="<<endl;
				gotoxy(x0+3,y0);cout<<pt->Data.NIP<<endl;
				gotoxy(52+3,y1);cout<<pt->Data.Nama<<endl;
				gotoxy(10,y1+1);cout<<" =================================================================================================== "<<endl;
				pt=pt->Next;
				i++;
				y+=2;
				y0+=2;
				y1+=2;
			}

		}
		footer_menu_laporan_staff();
		setcolor(0,0);
}

void laporan_mobil_display(ListMobil M,int key)
{
	int kol=0,baris=0;
	int x=11,y=12;
	int x0=18,y0=12;
	int x1=34,y1=12;
	int i=1;
	address2 pt=M.First;
	address2 next=M.First;
	address2 prev=M.First;

		system("cls");
		setcolor(15,21);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                                          === LAPORAN ===                                            "<<endl;
		gotoxy(10,6);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,7);cout<<"                              Ini Adalah Data Mobil yang sudah dipinjam                              "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		setcolor(0,15);
		
		setcolor(15,0);
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =            Plat                 =                          MERK                            = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;
		setcolor(0,0);

		if(IsEmpty_Mobil(M))
		{
			setcolor(15,0);
			gotoxy(23,y);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(pt!=NULL)
			{
				setcolor(15,0);
				gotoxy(x,y);cout<<"= "<<i<<endl;gotoxy(x+4,y);cout<<" ="<<endl;
				gotoxy(50,y);cout<<"="<<endl;gotoxy(109,y);cout<<"="<<endl;
				gotoxy(x0+3,y0);cout<<pt->Data.No_Plat<<endl;
				gotoxy(52+3,y1);cout<<pt->Data.Merk<<endl;
				gotoxy(10,y1+1);cout<<" =================================================================================================== "<<endl;
				pt=pt->Next;
				i++;
				y+=2;
				y0+=2;
				y1+=2;
			}

		}
		footer_menu_laporan_mobil();
		setcolor(0,0);
}

void laporan_peminjaman_display(ListPinjam P,int key)
{
	int x=13,y=12;
	int x0=18,y0=12;
	int x1=34,y1=12;
	int x2=55,y2=12;
	int x3=84,y3=12;
	int i=1;
	address3 pt=P.First;
	address3 next=P.First;
	address3 prev=P.First;

		system("cls");
		setcolor(15,21);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                                          === LAPORAN ===                                            "<<endl;
		gotoxy(10,6);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,7);cout<<"                         Ini Adalah Data Mobil dan Staff yang sudah dipinjam                         "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		setcolor(0,15);
		
		setcolor(15,0);
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =     NIP       =      NAMA          =       MERK MOBIL           =     NO.PLAT              = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;
		setcolor(0,0);

		if(IsEmpty_Peminjaman(P))
		{
			setcolor(15,0);
			gotoxy(19,26);cout<<"Data Kosong"<<endl;
			gotoxy(36,26);cout<<"Data Kosong"<<endl;
			gotoxy(59,26);cout<<"Data Kosong"<<endl;
			gotoxy(87,26);cout<<"Data Kosong"<<endl;

		}
		else
		{
			while(P.First!=NULL)
			{
				setcolor(15,0);
				gotoxy(x-2,y);cout<<"=  "<<i<<endl;gotoxy(x+3,y);cout<<"="<<endl;
				gotoxy(34-2,y);cout<<"="<<endl;
				gotoxy(55-2,y);cout<<"="<<endl;
				gotoxy(85-3,y);cout<<"="<<endl;
				gotoxy(112-3,y);cout<<"="<<endl;
				gotoxy(x0,y0);cout<<P.First->data.NIP_Pinjam<<endl;
				gotoxy(x1+1,y1);cout<<P.First->data.Nama_Pinjam<<endl;
				gotoxy(x2,y2);cout<<P.First->data.Merk_Pinjam<<endl;
				gotoxy(x3,y3);cout<<P.First->data.No_Plat_Pinjam<<endl;
				P.First=P.First->Next;
				i++;
				y++;
				y0++;
				y1++;
				y2++;
				y3++;
			}
			gotoxy(10,y3);cout<<" =================================================================================================== "<<endl;
		}
		footer_menu_laporan_peminjaman();
		setcolor(0,0);
}

void laporan_peminjaman_jumlah(ListJumlah J,int key)
{
	int kol=0,baris=0;
	int x=11,y=12;
	int x0=18,y0=12;
	int x1=34,y1=12;
	int i=1;
	address pt=J.First;
	address next=J.First;
	address prev=J.First;

		system("cls");
		setcolor(15,21);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                                          === LAPORAN ===                                            "<<endl;
		gotoxy(10,6);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,7);cout<<"                         Ini Adalah Data Mobil dan Staff yang sudah dipinjam                         "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		setcolor(0,15);
		
		setcolor(15,0);
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =            NIP                 =                          JUMLAH                           = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;
		setcolor(0,0);


			while(pt!=NULL)
			{
				setcolor(15,0);
				gotoxy(x,y);cout<<"= "<<i<<endl;gotoxy(x+4,y);cout<<" ="<<endl;
				gotoxy(49,y);cout<<"="<<endl;gotoxy(109,y);cout<<"="<<endl;
				gotoxy(x0+3,y0);cout<<pt->Data.NIP<<endl;
				gotoxy(52+3,y1);cout<<pt->Data.jumlah<<endl;
				pt=pt->Next;
				i++;
				y++;
				y0++;
				y1++;
			}
			gotoxy(10,y1);cout<<" =================================================================================================== "<<endl;


		footer_menu_laporan_peminjaman();
		setcolor(0,0);
}