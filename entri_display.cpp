#include "header.h"

void entri_staff_display(ListStaff S)
{
	int x0=13,y0=12;
	int x1=20,y1=12;
	int x2=55,y2=12;
	int i=1;
		system("cls");
		setcolor(0,7);
		gotoxy(10,0);cout<<"                                      PEMINJAMAN MOBIL PT. XXXXX                                     "<<endl;
		gotoxy(10,1);cout<<"                                                                                                     "<<endl;
		gotoxy(10,2);cout<<"                                       SUB MENU ENTRI - STAFF                                        "<<endl;
		setcolor(0,0);

		setcolor(0,15);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,6);cout<<"                                                                                                     "<<endl;
		gotoxy(10,7);cout<<"                            Ini Adalah Data Staff yang sudah di daftarkan                            "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =             NIP                 =                          NAMA                            = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;

		footer_menu_entri();
		if(IsEmpty_Staff(S))
		{
			setcolor(15,0);
			gotoxy(28,22);cout<<"Data Kosong"<<endl;
			gotoxy(75,22);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(S.First!=NULL)
			{
				setcolor(0,15);
				gotoxy(x0-3,y0);cout<<" =    =                                 =                                                          = "<<endl;
				gotoxy(x0+1,y0);cout<<i<<endl;
				gotoxy(x1,y1);cout<<S.First->Data.NIP<<endl;
				gotoxy(x2,y2);cout<<S.First->Data.Nama<<endl;
				S.First=S.First->Next;
				i++;
				y0++;
				y1++;
				y2++;
			}
		}

}

void entri_mobil_display(ListMobil M)
{
	int x0=13,y0=12;
	int x1=20,y1=12;
	int x2=55,y2=12;
	int i=1;
		system("cls");
		setcolor(0,7);
		gotoxy(10,0);cout<<"                                      PEMINJAMAN MOBIL PT. XXXXX                                     "<<endl;
		gotoxy(10,1);cout<<"                                                                                                     "<<endl;
		gotoxy(10,2);cout<<"                                       SUB MENU ENTRI - MOBIL                                        "<<endl;
		setcolor(0,0);

		setcolor(0,15);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,6);cout<<"                                                                                                     "<<endl;
		gotoxy(10,7);cout<<"                            Ini Adalah Data Staff yang sudah di daftarkan                            "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =             Merk                 =                          Plat                           = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;

		footer_menu_entri();
		if(IsEmpty_Mobil(M))
		{
			setcolor(15,0);
			gotoxy(28,22);cout<<"Data Kosong"<<endl;
			gotoxy(75,22);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(M.First!=NULL)
			{
				setcolor(0,15);
				gotoxy(x0-3,y0);cout<<" =    =                                  =                                                         = "<<endl;
				gotoxy(x0,y0);cout<<i<<endl;
				gotoxy(x1,y1);cout<<M.First->Data.Merk<<endl;
				gotoxy(x2,y2);cout<<M.First->Data.No_Plat<<endl;
				M.First=M.First->Next;
				i++;
				y0++;
				y1++;
				y2++;
			}
		}

}

void entri_pinjam_display(ListPinjam P)
{
	int x=13,y=12;
	int x0=18,y0=12;
	int x1=34,y1=12;
	int x2=55,y2=12;
	int x3=84,y3=12;
	int i=1;
		system("cls");
		setcolor(0,7);
		gotoxy(10,0);cout<<"                                      PEMINJAMAN MOBIL PT. XXXXX                                     "<<endl;
		gotoxy(10,1);cout<<"                                                                                                     "<<endl;
		gotoxy(10,2);cout<<"                                      SUB MENU ENTRI - PEMINJAMAN                                    "<<endl;
		setcolor(0,0);

		setcolor(0,15);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,6);cout<<"                                                                                                     "<<endl;
		gotoxy(10,7);cout<<"                            Ini Adalah Data Staff yang sudah di daftarkan                            "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =     NIP       =      NAMA          =       MERK MOBIL           =     NO.PLAT              = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;


		footer_menu_pinjam();
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
				setcolor(0,15);
				gotoxy(x-3,y0);cout<<"                                                                                                   = "<<endl;
				gotoxy(x-2,y);cout<<"=  "<<i<<endl;gotoxy(x+2,y);cout<<" ="<<endl;
				gotoxy(x+19,y);cout<<"="<<endl;
				gotoxy(53,y);cout<<"="<<endl;
				gotoxy(53+29,y);cout<<"="<<endl;
				gotoxy(x0+2,y0);cout<<P.First->data.NIP_Pinjam<<endl;
				gotoxy(x1+2,y1);cout<<P.First->data.Nama_Pinjam<<endl;
				gotoxy(x2+2,y2);cout<<P.First->data.Merk_Pinjam<<endl;
				gotoxy(x3+2,y3);cout<<P.First->data.No_Plat_Pinjam<<endl;
				P.First=P.First->Next;
				i++;
				y++;
				y0++;
				y1++;
				y2++;
				y3++;
			}
		}

}