#include "header.h"

void edit_staff_display(ListStaff &S,int key,ListPinjam P)
{
	Staff data;
	int x0=13,y0=12;
	int x1=20,y1=12;
	int x2=55,y2=12;
	int i=1;
	int kol=0,baris=0;
	address1 pt=S.First;
	address1 next=S.First;
	address1 prev=S.First;
		system("cls");
		for(kol=0;kol<120;kol++)
		{
			for(baris=0;baris<52-1;baris++)
			{
				
				gotoxy(kol,baris);
				setcolor(0,0);
				cout<<" "<<endl;
			}
		}

		setcolor(0,7);
		gotoxy(10,0);cout<<"                                      PEMINJAMAN MOBIL PT. XXXXX                                     "<<endl;
		gotoxy(10,1);cout<<"                                                                                                     "<<endl;
		gotoxy(10,2);cout<<"                                                                                                     "<<endl;
		gotoxy(10,3);cout<<"                                       === EDIT DATA STAFF ===                                       "<<endl;
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		setcolor(0,0);

		setcolor(0,7);
		gotoxy(10,5);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,7);cout<<"                                                                                                     "<<endl;
		gotoxy(10,6);cout<<"                            Ini Adalah Data Staff yang sudah di daftarkan                            "<<endl;
		setcolor(0,15);
		gotoxy(10,9);cout<<" ======================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =             NIP                 = "<<endl;
		gotoxy(10,11);cout<<" ======================================== "<<endl;
	
		setcolor(0,0);
		
		setcolor(15,12);
		gotoxy(62,15);cout<<"                                           "<<endl;
		gotoxy(62,16);cout<<"                EDIT-DATA                  "<<endl;
		gotoxy(62,17);cout<<"  Masukkan NIP yang tersedia pada tabel.   "<<endl;
		gotoxy(62,18);cout<<"                                           "<<endl;
		gotoxy(62,19);cout<<" ========================================= "<<endl;
		gotoxy(62,20);cout<<"                                           "<<endl;
		gotoxy(62,21);cout<<"                                           "<<endl;
		gotoxy(62,22);cout<<"                                           "<<endl;
		gotoxy(62,23);cout<<" ========================================= "<<endl;
		gotoxy(62,24);cout<<"                                           "<<endl;
		gotoxy(62,25);cout<<"                                           "<<endl;
		gotoxy(62,26);cout<<"                                           "<<endl;
		gotoxy(62,27);cout<<"                                           "<<endl;
		gotoxy(62,28);cout<<"                                           "<<endl;
		gotoxy(62,29);cout<<"                                           "<<endl;
		gotoxy(62,30);cout<<"                                           "<<endl;
		gotoxy(62,31);cout<<"                                           "<<endl;
		gotoxy(62,32);cout<<"                                           "<<endl;
		gotoxy(62,33);cout<<"                                           "<<endl;
		gotoxy(62,34);cout<<"                                           "<<endl;
		gotoxy(62,35);cout<<"                                           "<<endl;
		gotoxy(62,36);cout<<"                                           "<<endl;
		gotoxy(62,37);cout<<"                                           "<<endl;
		gotoxy(62,38);cout<<"                                           "<<endl;
		gotoxy(62,39);cout<<"                                           "<<endl;

		
		if(IsEmpty_Staff(S))
		{
			setcolor(0,15);
			gotoxy(28,22);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(pt!=NULL)
			{
				if(!isFound_Staff_onPinjam(P,pt->Data.NIP))
				{
					setcolor(0,15);
					gotoxy(x0-3,y0);cout<<" =    =                                 = "<<endl;
					gotoxy(x0,y0);cout<<i<<endl;
					gotoxy(x1,y1);cout<<pt->Data.NIP<<endl;
					i++;
					y0++;
					y1++;
					y2++;
				}
				pt=pt->Next;
			}
			do{
				setcolor(15,12);
				gotoxy(62,21);cout<<"  NIP : ";cin>>data.NIP;
				if(!isFound_Staff(S,data.NIP))
				{
					gotoxy(62,21);cout<<"          NIP tidak ditemukan            "<<endl;
					getch();
					gotoxy(62,21);cout<<"                                         "<<endl;
				}
				else if(isFound_Staff_onPinjam(P,data.NIP))
				{
					gotoxy(62,21);cout<<"        Staff sedang meminjam            "<<endl;
					getch();
					gotoxy(62,21);cout<<"                                         "<<endl;
				}
			}while(!isFound_Staff(S,data.NIP)||isFound_Staff_onPinjam(P,data.NIP));
			
			edit_staff(S,data.NIP);
			gotoxy(62,30);cout<<"          Data Berhasil diubah         "<<endl;

		}


}

void edit_mobil_display(ListMobil &M,int key,ListPinjam P)
{
	Mobil data;
	int x0=13,y0=12;
	int x1=20,y1=12;
	int x2=55,y2=12;
	int i=1;
	int kol=0,baris=0;
	address2 pt=M.First;
	address2 next=M.First;
	address2 prev=M.First;
		system("cls");
		for(kol=0;kol<120;kol++)
		{
			for(baris=0;baris<52-1;baris++)
			{
				
				gotoxy(kol,baris);
				setcolor(0,0);
				cout<<" "<<endl;
			}
		}

		setcolor(0,7);
		gotoxy(10,0);cout<<"                                      PEMINJAMAN MOBIL PT. XXXXX                                     "<<endl;
		gotoxy(10,1);cout<<"                                                                                                     "<<endl;
		gotoxy(10,2);cout<<"                                                                                                     "<<endl;
		gotoxy(10,3);cout<<"                                       === EDIT DATA MOBIL ===                                       "<<endl;
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		setcolor(0,0);

		setcolor(0,7);
		gotoxy(10,5);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,7);cout<<"                                                                                                     "<<endl;
		gotoxy(10,6);cout<<"                               Ini Adalah Data Staff yang dapat di edit                              "<<endl;
		setcolor(0,15);
		gotoxy(10,9);cout<<" ======================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =             NIP                 = "<<endl;
		gotoxy(10,11);cout<<" ======================================== "<<endl;
		setcolor(0,0);
		
		setcolor(15,12);
		gotoxy(62,15);cout<<"                                           "<<endl;
		gotoxy(62,16);cout<<"                EDIT-DATA                  "<<endl;
		gotoxy(62,17);cout<<"  Masukkan NIP yang tersedia pada tabel.   "<<endl;
		gotoxy(62,18);cout<<"                                           "<<endl;
		gotoxy(62,19);cout<<" ========================================= "<<endl;
		gotoxy(62,20);cout<<"                                           "<<endl;
		gotoxy(62,21);cout<<"                                           "<<endl;
		gotoxy(62,22);cout<<"                                           "<<endl;
		gotoxy(62,23);cout<<" ========================================= "<<endl;
		gotoxy(62,24);cout<<"                                           "<<endl;
		gotoxy(62,25);cout<<"                                           "<<endl;
		gotoxy(62,26);cout<<"                                           "<<endl;
		gotoxy(62,27);cout<<"                                           "<<endl;
		gotoxy(62,28);cout<<"                                           "<<endl;
		gotoxy(62,29);cout<<"                                           "<<endl;
		gotoxy(62,30);cout<<"                                           "<<endl;
		gotoxy(62,31);cout<<"                                           "<<endl;
		gotoxy(62,32);cout<<"                                           "<<endl;
		gotoxy(62,33);cout<<"                                           "<<endl;
		gotoxy(62,34);cout<<"                                           "<<endl;
		gotoxy(62,35);cout<<"                                           "<<endl;
		gotoxy(62,36);cout<<"                                           "<<endl;
		gotoxy(62,37);cout<<"                                           "<<endl;
		gotoxy(62,38);cout<<"                                           "<<endl;
		gotoxy(62,39);cout<<"                                           "<<endl;

		
		if(IsEmpty_Mobil(M))
		{
			setcolor(0,15);
			gotoxy(28,22);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(pt!=NULL)
			{
				if(!isFound_Mobil_onPinjam(P,pt->Data.No_Plat))
				{
					setcolor(0,15);
					gotoxy(x0-3,y0);cout<<" =    =                                 = "<<endl;
					gotoxy(x0,y0);cout<<i<<endl;
					gotoxy(x1,y1);cout<<pt->Data.No_Plat<<endl;
					i++;
					y0++;
					y1++;
					y2++;
				}
				pt=pt->Next;
			}
			do{
				setcolor(15,12);
				gotoxy(62,21);cout<<"  No Plat : ";cin>>data.No_Plat;
				if(!isFound_Mobil(M,data.No_Plat))
				{
					gotoxy(62,21);cout<<"          Mobil tidak ditemukan            "<<endl;
					getch();
					gotoxy(62,21);cout<<"                                         "<<endl;
				}
				else if(isFound_Mobil_onPinjam(P,data.No_Plat))
				{
					
				}
			}while(!isFound_Mobil(M,data.No_Plat)||isFound_Mobil_onPinjam(P,data.No_Plat));
			
			edit_mobil(M,data.No_Plat);
			gotoxy(62,30);cout<<"          Data Berhasil diubah         "<<endl;

		}


}