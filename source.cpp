#include "header.h"

address alokasi_jumlah(JumPinjam data)
{
	address input;
	input=new(NodeJumPinjam);
	input->Data=data;
	input->Next=NULL;
	return input;
}

address2 alokasi_mobil(Mobil data)
{
	address2 input;
	input=new(NodeMobil);
	input->Data=data;
	input->Next=NULL;
	return input;
}

address1 alokasi_staff(Staff data)
{
	address1 input;
	input=new(NodeStaff);
	input->Data=data;
	input->Next=NULL;
	return input;
}

address3 alokasi_pinjam(Pinjam data)
{
	address3 input;
	input=new(NodePinjam);
	input->data=data;
	input->Next=NULL;
	return input;
}



address1 search_staff(ListStaff S,Staff data)
{
	while(S.First!=NULL)
	{
		if(strcmpi(S.First->Data.Nama,data.Nama)==0||S.First->Data.NIP==data.NIP)
			return S.First;
	}
	return NULL;
}

address2 search_mobil(ListMobil M,Mobil data)
{
	while(M.First!=NULL)
	{
		if(strcmpi(M.First->Data.Merk,data.Merk)==0||strcmpi(M.First->Data.No_Plat,data.No_Plat)==0)
			return M.First;
	}
	return NULL;
}

bool IsEmpty_Mobil(ListMobil M)
{
	if(M.First==NULL)
		return true;
	return false;
}

bool IsEmpty_Staff(ListStaff S)
{
	if(S.First==NULL)
		return true;
	return false;
}

bool IsEmpty_Peminjaman(ListPinjam P)
{
	if(P.First==NULL)
		return true;
	return false;
}

bool isLessData_Peminjaman(ListPinjam P,ListMobil M)
{
	while(M.First!=NULL)
	{
		if(!isFound_Mobil_onPinjam(P,M.First->Data.No_Plat))
			return false;
		M.First=M.First->Next;
	}
	return true;
}

bool CekMerkLolos(Mobil data)
{	
	if(strcmpi(data.Merk,"toyota")==0||strcmpi(data.Merk,"honda")==0||strcmpi(data.Merk,"daihatsu")==0
		||strcmpi(data.Merk,"nissan")==0||strcmpi(data.Merk,"suzuki")==0||strcmpi(data.Merk,"kia")==0
		||strcmpi(data.Merk,"mitsubishi")==0||strcmpi(data.Merk,"bmw")==0||strcmpi(data.Merk,"isuzu")==0
		||strcmpi(data.Merk,"datsun")==0)
		return true;
	return false;
}

void create_empty_jumlah(ListJumlah &J)
{
	J.First=NULL;
}

void create_empty_mobil(ListMobil &M)
{
	M.First=NULL;

}

void create_empty_staff(ListStaff &S)
{
	S.First=NULL;
}

void create_empty_pinjam(ListPinjam &P)
{
	P.First=NULL;
}

void entri_mobil(ListMobil &M,Mobil data)
{	
	address2 input=alokasi_mobil(data);
	if(M.First==NULL)
	{
		M.First=input;
	}
	else
	{
		input->Next=M.First;
		M.First=input;
	}
}

void entri_staff(ListStaff &S,Staff data)
{	
	address1 input=alokasi_staff(data);
	if(S.First==NULL)
	{
		S.First=input;
	}
	else
	{
		input->Next=S.First;
		S.First=input;
	}
}


void show_mobil(ListMobil M)
{
	if(IsEmpty_Mobil(M))
	{
		cout<<"Kosong"<<endl;
	}
	else
	{
		while(M.First!=NULL)
		{
			cout<<"\nDataMobil"<<endl;
			cout<<"Merk Mobil	: "<<M.First->Data.Merk<<endl;
			cout<<"Plat Mobil	: "<<M.First->Data.No_Plat<<endl;
			M.First=M.First->Next;
		}
	}
}

void show_staff(ListStaff S)
{
	if(IsEmpty_Staff(S))
	{
		cout<<"Kosong"<<endl;
	}
	else
	{
		while(S.First!=NULL)
		{
			cout<<"\nDataStaff"<<endl;
			cout<<"NIP Staff	: "<<S.First->Data.NIP<<endl;
			cout<<"Nama Staff	: "<<S.First->Data.Nama<<endl;
			S.First=S.First->Next;
		}
	}
}

void edit_staff(ListStaff &S, int NIP)
{
	Staff data;
	address1 pt=S.First;
	setcolor(15,12);
	do{
				gotoxy(62,25);cout<<"  NIP baru  : ";cin>>data.NIP;
				if(isFound_Staff(S,data.NIP))
				{
					gotoxy(62,25);cout<<"         NIP sudah ada!!               "<<endl;
					getch();
					gotoxy(62,25);cout<<"                                       "<<endl;
				}
			}while(isFound_Staff(S,data.NIP));
			gotoxy(62,27);cout<<"  Nama baru : ";cin>>data.Nama;

	while(pt!=NULL)
	{
		if((pt->Data.NIP==NIP))
		{
			strcpy(pt->Data.Nama,data.Nama);
			pt->Data.NIP=data.NIP;
			break;
		}
		pt=pt->Next;
	}
	
}

void edit_mobil(ListMobil &M,string plat)
{
	Mobil data;
	address2 pt=M.First;

	setcolor(15,12);
	do{
				gotoxy(62,25);cout<<"  No Plat Baru  : ";cin>>data.No_Plat;
				if(isFound_Mobil(M,data.No_Plat))
				{
					gotoxy(62,25);cout<<"         Plat Sudah Ada!               "<<endl;
					getch();
					gotoxy(62,25);cout<<"                                       "<<endl;
				}
				else if(!CekPlatLolos(data.No_Plat))
				{
					gotoxy(62,25);cout<<"Plat: ABxxxx,ABxxx,ABxx,ABx. x=angka   "<<endl;
					getch();
					gotoxy(62,25);cout<<"                                       "<<endl;
				}
	}while(isFound_Mobil(M,data.No_Plat)||!CekPlatLolos(data.No_Plat));

	do{
		gotoxy(62,27);cout<<"  Merk Baru  : ";cin>>data.Merk;
		if(!CekMerkLolos(data))
		{
			gotoxy(62,27);cout<<"Honda,Nissan,Toyota,Daihatsu,Kia,BMW,"<<endl;
			gotoxy(62,28);cout<<"Mitsubishi,Suzuki,Datsun,Isuzu"<<endl;
			getch();
			gotoxy(62,27);cout<<"                                       "<<endl;
			gotoxy(62,28);cout<<"                                       "<<endl;
		}
	}while(!CekMerkLolos(data));

	while(pt!=NULL)
	{
		if(strcmpi(pt->Data.No_Plat,plat)==0)
		{
			strcpy(pt->Data.Merk,data.Merk);
			strcpy(pt->Data.No_Plat,data.No_Plat);
			break;
		}
		pt=pt->Next;
	}
	
}

void del_staff(ListStaff &S,int NIP)
{
	address1 hapus;
	address1 prev=S.First;
	address1 pt=S.First;
	if(pt->Next==NULL)
	{
		if((pt->Data.NIP==NIP))
		{
			hapus=pt;
			dealokasi_staff(hapus);
			create_empty_staff(S);
		}
	}
	else
	{
		while(pt!=NULL)
		{
			if((pt->Data.NIP==NIP)&&pt==S.First)
			{
				hapus=pt;
				S.First=hapus->Next;
				dealokasi_staff(hapus);
				break;
			}
			else if((pt->Data.NIP==NIP)&&pt!=S.First)
			{
				hapus=pt;
				prev->Next=hapus->Next;
				dealokasi_staff(hapus);
				break;
			}
			else if((pt->Data.NIP==NIP)&&pt->Next==NULL)
			{
				hapus=pt;
				prev->Next=NULL;
				dealokasi_staff(hapus);
				break;
			}
			prev=pt;
			pt=pt->Next;
		}
		
	}

}

void del_mobil(ListMobil &M,string plat)
{
	address2 hapus;
	address2 pt=M.First;
	address2 prev=M.First;

	if(pt->Next==NULL)
		{
			if(strcmpi(pt->Data.No_Plat,plat)==0)
			{
				hapus=pt;
				dealokasi_mobil(hapus);
				create_empty_mobil(M);
			}
		}
		else
		{
			while(pt!=NULL)
			{
				if(strcmpi(pt->Data.No_Plat,plat)==0&&pt==M.First)
				{
					hapus=pt;
					M.First=hapus->Next;
					dealokasi_mobil(hapus);
					break;
				}
				else if(strcmpi(pt->Data.No_Plat,plat)==0&&pt!=M.First)
				{
					hapus=pt;
					prev->Next=hapus->Next;
					dealokasi_mobil(hapus);
					break;
				}
				else if(strcmpi(pt->Data.No_Plat,plat)==0&&pt->Next==NULL)
				{
					hapus=pt;
					prev->Next=NULL;
					dealokasi_mobil(hapus);
					break;
				}
				prev=pt;
				pt=pt->Next;
			}
			
		}

}

void dealokasi_staff(address1 staff)
{
	delete(staff);
}

void dealokasi_mobil(address2 mobil)
{
	delete(mobil);
}

void pinjam(ListPinjam &P,ListStaff S,ListMobil M,int NIP,string plat)
{
	Pinjam Data;
	address3 input;
	address3 pt_pinjam=P.First;
	address2 pt_mobil=M.First;
	address1 pt_staff=S.First;
	if(P.First==NULL)
	{ 
		while(pt_staff!=NULL)
		{
			if(pt_staff->Data.NIP==NIP)
			{
				while(pt_mobil!=NULL)
				{
				
					if(strcmpi(pt_mobil->Data.No_Plat,plat)==0)
					{
						if(P.First==NULL)
						{
							strcpy(Data.Merk_Pinjam,pt_mobil->Data.Merk);
							strcpy(Data.No_Plat_Pinjam,pt_mobil->Data.No_Plat);
							strcpy(Data.Nama_Pinjam,pt_staff->Data.Nama);
							(Data.NIP_Pinjam=pt_staff->Data.NIP);
							input=alokasi_pinjam(Data);
							P.First=input;
							break;
						}
						else if(P.First!=NULL)
						{
							strcpy(Data.Merk_Pinjam,pt_mobil->Data.Merk);
							strcpy(Data.No_Plat_Pinjam,pt_mobil->Data.No_Plat);
							strcpy(Data.Nama_Pinjam,pt_staff->Data.Nama);
							(Data.NIP_Pinjam=pt_staff->Data.NIP);
							input=alokasi_pinjam(Data);
							input->Next=P.First;
							P.First=input;
							break;
						}
					}
					pt_mobil=pt_mobil->Next;
				}
			}
			pt_staff=pt_staff->Next;
		}
	}

	else
	{
		while(pt_pinjam!=NULL)
		{
			while(pt_staff!=NULL)
			{
				if(pt_staff->Data.NIP==NIP)
				{
					while(pt_mobil!=NULL)
					{
						if(strcmpi(pt_mobil->Data.No_Plat,plat)==0)
						{
							strcpy(Data.Merk_Pinjam,pt_mobil->Data.Merk);
							strcpy(Data.No_Plat_Pinjam,pt_mobil->Data.No_Plat);
							strcpy(Data.Nama_Pinjam,pt_staff->Data.Nama);
							(Data.NIP_Pinjam=pt_staff->Data.NIP);
							input=alokasi_pinjam(Data);
							input->Next=P.First;
							P.First=input;
							break;
						}
						pt_mobil=pt_mobil->Next;
					}
				}
				pt_staff=pt_staff->Next;
			}
			pt_pinjam=pt_pinjam->Next;
		}
	}
}

void show_pinjam(ListPinjam P)
{	
	int i=1;
	address3 pt_pinjam=P.First;
	while(pt_pinjam!=NULL)
	{
		cout<<"Staff Peminjam - "<<i<<" : "<<endl;
		cout<<"\tNIP	: "<<pt_pinjam->data.NIP_Pinjam<<endl;
		cout<<"\tNama	: "<<pt_pinjam->data.Nama_Pinjam<<endl;
		cout<<"Mobil yang dipinjam :"<<endl;
		cout<<"\tMerk	: "<<pt_pinjam->data.Merk_Pinjam<<endl;
		cout<<"\tNo-Plat	: "<<pt_pinjam->data.No_Plat_Pinjam<<endl;
		cout<<endl;
		i++;
		pt_pinjam=pt_pinjam->Next;
	}
}

void pengembalian(ListPinjam &P,int NIP,string plat)
{
	address3 hapus;
	address3 prev=P.First;
	address3 pt_pinjam=P.First;
	if(P.First->Next==NULL)
	{	if((pt_pinjam->data.NIP_Pinjam==NIP)&&strcmpi(pt_pinjam->data.No_Plat_Pinjam,plat)==0)
		{
			hapus=P.First;
			delete hapus;
			create_empty_pinjam(P);
		}
	}
	else
	{
		while(pt_pinjam!=NULL)
		{
			if(pt_pinjam==P.First&&(pt_pinjam->data.NIP_Pinjam==NIP)&&strcmpi(pt_pinjam->data.No_Plat_Pinjam,plat)==0)
			{
				hapus=P.First;
				P.First=P.First->Next;
				delete hapus;
			}
			else if(pt_pinjam->Next==NULL&&(pt_pinjam->data.NIP_Pinjam==NIP)&&strcmpi(pt_pinjam->data.No_Plat_Pinjam,plat)==0)
			{
				hapus=pt_pinjam;
				prev->Next=NULL;
				delete hapus;
			}
			else if(pt_pinjam!=P.First&&pt_pinjam->Next!=NULL&&(pt_pinjam->data.NIP_Pinjam==NIP)&&strcmpi(pt_pinjam->data.No_Plat_Pinjam,plat)==0)
			{
				hapus=pt_pinjam;
				prev->Next=hapus->Next;
				delete hapus;
			}
			prev=pt_pinjam;
			pt_pinjam=pt_pinjam->Next;
		}
	}
}

bool isOne_pinjam(ListPinjam P)
{
	if(P.First->Next==NULL)
		return true;
	return false;
}

void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setcolor(char text,char latar)  
{  
	unsigned short color=latar*16+text;  
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsoleOutput,color);  
} 

bool CekPlatLolos(string plat)
{
	if(
		(plat[0]=='a'&&plat[1]=='b'||plat[0]=='A'&&plat[1]=='B')
		&&
		(
			(plat[2]=='0'||plat[2]=='1'||plat[2]=='2'||plat[2]=='3'||plat[2]=='4'||plat[2]=='5'||plat[2]=='6'||plat[2]=='7'||plat[2]=='8'||plat[2]=='9')
				||
			(plat[3]=='0'||plat[3]=='1'||plat[3]=='2'||plat[3]=='3'||plat[3]=='4'||plat[3]=='5'||plat[3]=='6'||plat[3]=='7'||plat[3]=='8'||plat[3]=='9')
				||
			(plat[4]=='0'||plat[4]=='1'||plat[4]=='2'||plat[4]=='3'||plat[4]=='4'||plat[4]=='5'||plat[4]=='6'||plat[4]=='7'||plat[4]=='8'||plat[4]=='9')
				||
			(plat[5]=='0'||plat[5]=='1'||plat[5]=='2'||plat[5]=='3'||plat[5]=='4'||plat[5]=='5'||plat[5]=='6'||plat[5]=='7'||plat[5]=='8'||plat[5]=='9')
		)
	)
		return true;
	else
		return false;
}

bool isFound_Staff(ListStaff S,int NIP)
{
	while(S.First!=NULL)
	{
		if((S.First->Data.NIP==NIP))
		{
			return true;
		}
		S.First=S.First->Next;
	}
	return false;
}

bool isFound_Mobil(ListMobil M,string plat)
{
	while(M.First!=NULL)
	{
		if(strcmpi(M.First->Data.No_Plat,plat)==0)
			return true;
		M.First=M.First->Next;
	}
	return false;
}

bool isFound_Staff_onPinjam(ListPinjam P,int NIP)
{
	while(P.First!=NULL)
	{
		if((NIP==P.First->data.NIP_Pinjam))
			return true;
		P.First=P.First->Next;
	}
	return false;
}

bool isFound_Mobil_onPinjam(ListPinjam P,string plat)
{
	while(P.First!=NULL)
	{
		if(strcmpi(plat,P.First->data.No_Plat_Pinjam)==0)
			return true;
		P.First=P.First->Next;
	}
	return false;
}

void fungsi_tolong();
void footer();

void laporan_mobil_urut_merk(ListMobil &M)//ascending
{
	Mobil temp;
	address2 j;
	address2 pt=M.First;
	while(pt->Next!=NULL)
	{
		j=pt->Next;
		while(j!=NULL)
		{
			if(strcmpi(pt->Data.Merk,j->Data.Merk)>0)
			{
				temp=pt->Data;
				pt->Data=j->Data;
				j->Data=temp;
			}
			j=j->Next;
		}
		pt=pt->Next;
	}
}

void laporan_mobil_urut_plat(ListMobil &M)//ascending
{
	Mobil temp;
	address2 j;
	address2 pt=M.First;
	while(pt->Next!=NULL)
	{
		j=pt->Next;
		while(j!=NULL)
		{
			if(strcmpi(pt->Data.No_Plat,j->Data.No_Plat)>0)
			{
				temp=pt->Data;
				pt->Data=j->Data;
				j->Data=temp;
			}
			j=j->Next;
		}
		pt=pt->Next;
	}
}

void laporan_staff_urut_NIP(ListStaff &S)
{
	Staff temp;
	for(address1 i=S.First;i->Next!=NULL;i=i->Next)
	{
		for(address1 j=i->Next;j!=NULL;j=j->Next)
		{
			if((i->Data.NIP>j->Data.NIP))
			{
				temp=i->Data;
				i->Data=j->Data;
				j->Data=temp;
			}
		}
	}
}

void laporan_staff_urut_nama(ListStaff &S)
{
	Staff temp;
	address1 j;
	address1 pt=S.First;
	while(pt->Next!=NULL)
	{
		j=pt->Next;
		while(j!=NULL)
		{
			if(strcmpi(pt->Data.Nama,j->Data.Nama)>0)
			{
				temp=pt->Data;
				pt->Data=j->Data;
				j->Data=temp;
			}
			j=j->Next;
		}
		pt=pt->Next;
	}
}

void laporan_pinjam_urut_NIP(ListPinjam &P)
{
	Pinjam temp;
	address3 i=P.First;
	address3 j;
	for(i=P.First;i->Next!=NULL;i=i->Next)
	{
		for(j=i->Next;j!=NULL;j=j->Next)
		{
			if(j->data.NIP_Pinjam<i->data.NIP_Pinjam)
			{
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}	
		}
	}
}

void laporan_peminjaman_perstaff_urut_plat(ListPinjam &P)
{
	Pinjam temp;
	address3 i=P.First;
	address3 j;
	for(i=P.First;i->Next!=NULL;i=i->Next)
	{
		for(j=i->Next;j!=NULL;j=j->Next)
		{
			if(strcmpi(j->data.No_Plat_Pinjam,i->data.No_Plat_Pinjam)>0&&j->data.NIP_Pinjam<i->data.NIP_Pinjam)
			{
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}	
		}
	}
}

void tampil_laporanPinjam_perStaff(ListPinjam P,int NIP)
{
	address3 i=P.First;
	address3 j=P.First;
	while(i!=NULL)
	{
			if(i->data.NIP_Pinjam==NIP)
			{
				cout<<i->data.NIP_Pinjam<<endl;
				cout<<i->data.Nama_Pinjam<<endl;
				cout<<endl;
				
				while(j!=NULL)
				{
					if(j->data.NIP_Pinjam==NIP)
					{
						cout<<"\t Merk Mobil : "<<j->data.Merk_Pinjam<<endl;
						cout<<"\t Plat Mobil : "<<j->data.No_Plat_Pinjam<<endl;
						cout<<endl;
					}
					j=j->Next;
				}
				j=P.First;
				break;
			}
		i=i->Next;
	}
}

void laporan_jumlah_peminjaman_tiap_staff_urut_terbesar(ListPinjam P,ListJumlah &J)
{
	create_empty_jumlah(J);
	address help=J.First;
	address input;
	address pt1=J.First;
	address pt2=J.First;

	JumPinjam data;
	JumPinjam penampung;

	address3 i=P.First;
	address3 j=P.First;

	int nilai=0;
	int temp=0;



	for(i=P.First;i!=NULL;i=i->Next)
	{
		if(i->data.NIP_Pinjam!=temp)
		{
				temp=i->data.NIP_Pinjam;
				data.NIP=i->data.NIP_Pinjam;
					for(j=P.First;j!=NULL;j=j->Next)
					{
						if(j->data.NIP_Pinjam==temp)
						{
							nilai=nilai+1;
							data.jumlah=nilai;
						}
					}
			nilai=0;
			input=alokasi_jumlah(data);

			if(J.First==NULL)
			{
				J.First=input;
			}

			else if(J.First!=NULL)
			{
				input->Next=J.First;
				J.First=input;
			}
		}
	}

	for(pt1=J.First;pt1->Next!=NULL;pt1=pt1->Next)
	{
		for(pt2=pt1->Next;pt2!=NULL;pt2=pt2->Next)
		{
			if(pt2->Data.jumlah>pt1->Data.jumlah)
			{
				penampung=pt1->Data;
				pt1->Data=pt2->Data;
				pt2->Data=penampung;
			}

		}
	}

}

int readKey()
{  
	int tampung;  
	tampung=getch();  
	if(tampung ==0 || tampung ==224)tampung =256+getch(); 
	return tampung; 
}

void setScreenSize(int x, int y)
{
	SMALL_RECT r = {0, 0, x, y};

	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &r);
}

void getMenu(char &status_menu,int &key)
{
	do{
			key=readKey();
			if(status_menu=='0')
			{
				if(key==BAWAH||key==ATAS||key==KANAN||key==KIRI)
				{
					main_menu_selected1();
					status_menu='I';
				}
			}
			else
			{
				if((status_menu=='I'))
				{
					if(key==BAWAH)
					{
						main_menu_selected4();
						(status_menu='L');
					}
					else if(key==KANAN)
					{
						main_menu_selected4();
						(status_menu='L');
					}
					else
					{
						main_menu_selected1();
					}
				}

				
				else if((status_menu=='L'))
				{
					if(key==ATAS)
					{
						main_menu_selected1();
						(status_menu='I');
					}
					else if(key==KIRI)
					{
						main_menu_selected1();
						(status_menu='I');
					}
					else
					{
						main_menu_selected4();
					}
				}
			}

		}while(key!=ENTER&&key!=ESC);
}

void getSubMenu_Entri(string &status_menu, int &key)
{
	do{
			key=readKey();
			if(strcmpi(status_menu,"NULL")==0)
			{
				if(key==BAWAH||key==ATAS||key==KANAN||key==KIRI)
				{
					sub_menu_entri_selected1();
					strcpy(status_menu,"staff");
				}
				else if(key==ENTER)
				{
					getSubMenu_Entri(status_menu,key);
				}
			}
			else
			{
				if(strcmpi(status_menu,"staff")==0)
				{
					if(key==BAWAH)
					{
						sub_menu_entri_selected2();
						strcpy(status_menu,"mobil");
					}
					else if(key==ATAS)
					{
						sub_menu_entri_selected3();
						strcpy(status_menu,"peminjaman");
					}
					else
					{
						sub_menu_entri_selected1();
					}
				}

				else if(strcmpi(status_menu,"mobil")==0)
				{
					if(key==ATAS)
					{
						sub_menu_entri_selected1();
						strcpy(status_menu,"staff");
					}
					else if(key==BAWAH)
					{
						sub_menu_entri_selected3();
						strcpy(status_menu,"peminjaman");
					}
					else
					{
						sub_menu_entri_selected2();
					}
				}
				
				else if(strcmpi(status_menu,"peminjaman")==0)
				{
					if(key==BAWAH)
					{
						sub_menu_entri_selected1();
						strcpy(status_menu,"staff");
					}
					else if(key==ATAS)
					{
						sub_menu_entri_selected2();
						strcpy(status_menu,"mobil");
					}
					else
					{
						sub_menu_entri_selected3();
					}
				}
			}

		}while(key!=ESC&&key!=ENTER);
}

void getSubMenu_Laporan(string &status_menu, int &key)
{
	do{
			key=readKey();
			if(strcmpi(status_menu,"NULL")==0)
			{
				if(key==BAWAH||key==ATAS||key==KANAN||key==KIRI)
				{
					sub_menu_laporan_selected1();
					strcpy(status_menu,"staff");
				}
				else if(key==ENTER)
				{
					getSubMenu_Laporan(status_menu,key);
				}
			}
			else
			{
				if(strcmpi(status_menu,"staff")==0)
				{
					if(key==BAWAH)
					{
						sub_menu_laporan_selected2();
						strcpy(status_menu,"mobil");
					}
					else if(key==ATAS)
					{
						sub_menu_laporan_selected3();
						strcpy(status_menu,"peminjaman");
					}
					else
					{
						sub_menu_laporan_selected1();
					}
				}

				else if(strcmpi(status_menu,"mobil")==0)
				{
					if(key==ATAS)
					{
						sub_menu_laporan_selected1();
						strcpy(status_menu,"staff");
					}
					else if(key==BAWAH)
					{
						sub_menu_laporan_selected3();
						strcpy(status_menu,"peminjaman");
					}
					else
					{
						sub_menu_laporan_selected2();
					}
				}
				
				else if(strcmpi(status_menu,"peminjaman")==0)
				{
					if(key==BAWAH)
					{
						sub_menu_laporan_selected1();
						strcpy(status_menu,"staff");
					}
					else if(key==ATAS)
					{
						sub_menu_laporan_selected2();
						strcpy(status_menu,"mobil");
					}
					else
					{
						sub_menu_laporan_selected3();
					}
				}
			}

		}while(key!=ESC&&key!=ENTER);
}

void SubMenu_Entri_Enter(ListPinjam &P,int entri_nip,string pil_entri,ListMobil &M,ListStaff &S,int &key,char status_menu,Staff DataStaff,Mobil DataMobil,int &pil,string &sub_menu_status)
{
	if(strcmpi(sub_menu_status,"staff")==0)
	{
		if(key==ENTER)
		{
			
			entri_staff_display(S);
			do{
				key=getch();
			}while(key!=ENTER&&key!=ESC&&key!=F1&&key!=F2&&key!=F3);

			if(key==F1)
			{
				pop_up_help_staff();
				key=getch();
				key=ENTER;
				SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
			}

			else if(key==F2)
			{
				if(IsEmpty_Staff(S))
				{
					pop_up_kosong_data();
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else
				{
					edit_staff_display(S,key,P);
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
			}

			else if(key==F3)
			{
				if(IsEmpty_Staff(S))
				{
					pop_up_kosong_data();
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else
				{
					hapus_staff_display(S,key,P);
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
			}

			else if(key==ESC)
			{
				strcpy(sub_menu_status,"NULL");
				setcolor(0,0);
				sub_menu_entri();
				getSubMenu_Entri(sub_menu_status,key);
				do{
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}while(key!=ESC);
			}
			
			else if(key==ENTER)
			{
				pop_up_entri_staff(S,DataStaff,key);
			}

		}
		
	}

	else if(strcmpi(sub_menu_status,"mobil")==0)
	{

		if(key==ENTER)
		{
			
			entri_mobil_display(M);
			do{
				key=getch();
			}while(key!=ENTER&&key!=ESC&&key!=F1&&key!=F2&&key!=F3);
			
			if(key==F1)
			{
				pop_up_help_mobil();
				key=getch();
				key=ENTER;
				SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
			}

			else if(key==F2)
			{
				if(IsEmpty_Mobil(M))
				{
					pop_up_kosong_data();
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else
				{
					edit_mobil_display(M,key,P);
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
			}

			else if(key==F3)
			{
				if(IsEmpty_Mobil(M))
				{
					pop_up_kosong_data();
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else
				{
					hapus_mobil_display(M,key,P);
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
			}

			else if(key==ESC)
			{
				strcpy(sub_menu_status,"NULL");
				setcolor(0,0);
				sub_menu_entri();
				getSubMenu_Entri(sub_menu_status,key);
				do{
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}while(key!=ESC);
			}
			
			else if(key==ENTER)
			{
				pop_up_ketentuan_mobil();
				pop_up_entri_Mobil(M,DataMobil,key);
			}
		}
		
	}

	else if(strcmpi(sub_menu_status,"peminjaman")==0)
	{

		if(key==ENTER)
		{
			
			entri_pinjam_display(P);
			do{
				key=getch();
			}while(key!=ENTER&&key!=ESC&&key!=F1&&key!=F3);
			
			if(key==F1)
			{
				pop_up_help_peminjaman();
				key=getch();
				key=ENTER;
				SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
			}

			else if(key==F3)
			{
				if(IsEmpty_Peminjaman(P))
				{
					pop_up_kosong_data();
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else
				{
					pengembalian_display(P,M,S,key);
					key=getch();
					if(key==ENTER)
					{
						pop_up_hapus_pinjam(P,S,M,pil_entri,entri_nip,key);
					}
					key=ENTER;
					setcolor(0,0);
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
			}

			else if(key==ESC)
			{
				strcpy(sub_menu_status,"NULL");
				setcolor(0,0);
				sub_menu_entri();
				getSubMenu_Entri(sub_menu_status,key);
				do{
					SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}while(key!=ESC);
			}
			
			else if(key==ENTER)
			{
				if(!IsEmpty_Mobil(M)&&!IsEmpty_Staff(S)&&!isLessData_Peminjaman(P,M))
				{
					pop_up_pinjam_list_tersedia(P,S,M,key);
				}
				pop_up_entri_pinjam(P,S,M,pil_entri,entri_nip,key);

			}

		}
		
	}
}

void switch_case_entri_staff(ListJumlah &J,ListPinjam &P,int entri_nip,string pil_entri,int &pil,string &sub_menu_status,int key,Staff DataStaff,Mobil DataMobil,ListStaff &S,ListMobil &M,char status_menu)
{
	switch(status_menu)
	{		
		case 'I'	:		if(key==ENTER)
							{
								sub_menu_entri();
								getSubMenu_Entri(sub_menu_status,key);
								do{
									SubMenu_Entri_Enter(P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
								}while(key!=ESC);	
							}
							else if(key==ESC)
							{
								pil=0;
							}
							break;


			case 'L'	:	if(key==ENTER)
							{
								sub_menu_laporan();
								getSubMenu_Laporan(sub_menu_status,key);
								do{
									SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
								}while(key!=ESC);	
							}
							else if(key==ESC)
							{
								pil=0;
							}
							break;


			default		:	if(key==ESC)
							{
								pil=0;
							}
							break;
		}

}

void SubMenu_Laporan_Enter(ListJumlah &J,ListPinjam &P,int entri_nip,string pil_entri,ListMobil &M,ListStaff &S,int &key,char status_menu,Staff DataStaff,Mobil DataMobil,int &pil,string &sub_menu_status)
{
	if(strcmpi(sub_menu_status,"staff")==0)
	{
		if(key==ENTER)
		{
			laporan_staff_display(S,key);
			do{
				key=getch();
			}while(key!=ENTER&&key!=ESC&&key!=F1&&key!=F3);

			if(key==F1)
			{
				if(!IsEmpty_Staff(S))
				{
					laporan_staff_urut_NIP(S);
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else if(IsEmpty_Staff(S))
				{
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				
				}
			}
			
			else if(key==F3)
			{
				if(!IsEmpty_Staff(S))
				{
					laporan_staff_urut_nama(S);
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else if(IsEmpty_Staff(S))
				{
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				
				}
			}

			else if(key==ESC)
			{
				strcpy(sub_menu_status,"NULL");
				setcolor(0,0);
				sub_menu_laporan();
				getSubMenu_Laporan(sub_menu_status,key);
				do{
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}while(key!=ESC);
			}

		}
	}

	else if(strcmpi(sub_menu_status,"mobil")==0)
	{
		if(key==ENTER)
		{
			laporan_mobil_display(M,key);
			do{
				key=getch();
			}while(key!=ENTER&&key!=ESC&&key!=F1&&key!=F3);

			if(key==F1)
			{
				if(!IsEmpty_Mobil(M))
				{
					laporan_mobil_urut_plat(M);
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else if(IsEmpty_Mobil(M))
				{
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				
				}
			}
			
			else if(key==F3)
			{
				if(!IsEmpty_Mobil(M))
				{
					laporan_mobil_urut_merk(M);
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else if(IsEmpty_Mobil(M))
				{
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				
				}
			}
	

			else if(key==ESC)
			{
				strcpy(sub_menu_status,"NULL");
				setcolor(0,0);
				sub_menu_laporan();
				getSubMenu_Laporan(sub_menu_status,key);
				do{
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}while(key!=ESC);
			}

		}
	}

	else if(strcmpi(sub_menu_status,"peminjaman")==0)
	{
		if(key==ENTER)
		{
			if(!IsEmpty_Peminjaman(P))
				laporan_pinjam_urut_NIP(P);
			laporan_peminjaman_display(P,key);
			do{
				key=getch();
			}while(key!=ENTER&&key!=ESC&&key!=F1);

			if(key==F1)
			{
				if(!IsEmpty_Peminjaman(P))
				{
					laporan_jumlah_peminjaman_tiap_staff_urut_terbesar(P,J);
					laporan_peminjaman_jumlah(J,key);
					getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else if(IsEmpty_Peminjaman(P))
				{
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				
				}
			}
	

			else if(key==ESC)
			{
					strcpy(sub_menu_status,"NULL");
					setcolor(0,0);
					sub_menu_laporan();
					getSubMenu_Laporan(sub_menu_status,key);
					do{
						SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
					}while(key!=ESC);
			}
			
			else if(key==ENTER)
			{	
				if(!IsEmpty_Peminjaman(P))
				{
					pop_up_peminjaman_staff(P,entri_nip,key);
					key=getch();
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				}
				else if(IsEmpty_Peminjaman(P))
				{
					key=ENTER;
					setcolor(0,0);
					SubMenu_Laporan_Enter(J,P,entri_nip,pil_entri,M,S,key,status_menu,DataStaff,DataMobil,pil,sub_menu_status);
				
				}
				
			}


		}
	}
}


