#include<iostream.h>
#include<graphics.h>
#include<fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<process.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
ofstream fout("project.txt",ios::app);
float determinant(float a[5][5],int k)
{
	float s=1,det=0,b[5][5];
	int i,j,m,n,c;
	if (k==1)
	{
		return (a[0][0]);
	}
	else
	{
		det=0;
		for (c=0;c<k;c++)
		{
			m=0;
			n=0;
			for (i=0;i<k;i++)
			{
				for (j=0;j<k;j++)
				{
					b[i][j]=0;
					if (i != 0 && j != c)
					{
						b[m][n]=a[i][j];
						if (n<(k-2))
							n++;
						else
						{
							n=0;
							m++;
						}
					}
				}
			}
			int sode=determinant(b,k-1);
			det=det + s * (a[0][c] * sode);
			s=-1 * s;
		}
	}
	return (det);
}
class unaryop
{
	public:
		float r1,c1,k,f_mat[5][5],resultant[5][5];
		void jrdeterminant();
		void adjoint();
		void adjointoo();
		void transpose();
		int inverse();
		void display();
		void display1();

};
void unaryop::jrdeterminant()
{
	fout<<" f DET ( MATRIX ) k : k ";
	float e=determinant(f_mat,k);
	cout<<endl<<endl<<"DETERMINANT OF THE MATRIX YOU ENTERED IS : "<<e;
	fout<<e<<" f ";
}
void unaryop::adjointoo()
{
	float b[5][5],fac[5][5];
	int p,q,m,n,i,j;
	for (q=0;q<k;q++)
	{
		for (p=0;p<k;p++)
		{
			m=0;
			n=0;
			for (i=0;i<k;i++)
			{
				for (j=0;j<k;j++)
				{
					if (i != q && j != p)
					{
						b[m][n]=f_mat[i][j];
						if (n<(k-2))
							n++;
						else
						{
							n=0;
							m++;
						}
					}
				}
			}
			fac[q][p]=pow(-1,q + p) * determinant(b,k-1);
		}
	}
	for(int zz=0;zz<k;zz++)
	{
		for(int zz1=0;zz1<k;zz1++)
		{
			resultant[zz][zz1]=fac[zz1][zz];
		}
	}
}
void unaryop::adjoint()
{
	fout<<"ADJ ( MATRIX ) k : k ";
	float b[5][5],fac[5][5];
	int p,q,m,n,i,j;
	for (q=0;q<k;q++)
	{
		for (p=0;p<k;p++)
		{
			m=0;
			n=0;
			for (i=0;i<k;i++)
			{
				for (j=0;j<k;j++)
				{
					if (i != q && j != p)
					{
						b[m][n]=f_mat[i][j];
						if (n<(k-2))
							n++;
						else
						{
							n=0;
							m++;
						}
					}
				}
			}
			fac[q][p]=pow(-1,q + p) * determinant(b,k-1);
		}
	}
	for(int zz=0;zz<k;zz++)
	{
		for(int zz1=0;zz1<k;zz1++)
		{
			resultant[zz][zz1]=fac[zz1][zz];
			fout<<resultant[zz][zz1]<<" k k k k k ";
			if(zz1==k-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k ";
		if(zz==k-1)
		{
			fout<<"f ";
		}
	}
}
void unaryop::transpose()
{
	fout<<"TRANS ( MATRIX ) k : k ";
	for(int i=0;i<c1;i++)
	{
		for(int j=0;j<r1;j++)
		{
			resultant[i][j]=f_mat[j][i];
			fout<<resultant[i][j]<<" k k k k k ";
			if(j==r1-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k k k ";
		if(i==c1-1)
		{
			fout<<"f ";
		}
	 }
}
int unaryop::inverse()
{
	float f;
	f=determinant(f_mat,k);
	if(f==0)
	{
		int a12;
		cout<<endl<<endl<<setw(45)<<"INVERSE NOT POSSIBLE";
		fout<<"INVERSE k NOT k POSSIBLE f ";
		return(-1);
	}
	else
	{
		fout<<"INV ( MATRIX ) k : k ";
		adjointoo();
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
			{
				resultant[i][j]=resultant[i][j]/f;
				fout<<resultant[i][j]<<" k k k k k ";
				if(j==c1-1)
				{
					fout<<"e ";
				}
			}
			fout<<"k k k k k k k k k k k k k k ";
			if(i==r1-1)
			{
				fout<<"f ";
			}
		}
		return(0);
	}
}
void unaryop::display()
{
	cout<<endl<<endl;
	cout<<"-------------------------RESULTANT----------------------"<<endl<<endl;
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			cout<<resultant[i][j]<<"\t\t";
		}
		cout<<endl;
	}
}
void unaryop::display1()
{
	cout<<endl<<endl;
	cout<<"-------------------------RESULTANT----------------------"<<endl<<endl;
	for(int i=0;i<c1;i++)
	{
		for(int j=0;j<r1;j++)
		{
			cout<<resultant[i][j]<<"\t\t";
		}
		cout<<endl;
	}
}
class binaryop
{

	public :
		float f_mat[5][5],s_mat[5][5],resultant[5][5],r1,r2,c1,c2;
		void add();
		void sub1();
		void sub2();
		void multiply1();
		void multiply2();
		void display();
};
void binaryop::add()
{
	fout<<"MATRIX k 1 k + k MATRIX k 2 k : k ";
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			resultant[i][j]=f_mat[i][j]+s_mat[i][j];
			fout<<resultant[i][j]<<" k ";
			if(j==c1-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k k k k k k k k k ";
		if(i==r1-1)
		{
			fout<<"f ";
		}
	 }
}
void binaryop::sub1()
{
	fout<<"MATRIX k 1 k - k MATRIX k 2 k : k ";
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			resultant[i][j]=f_mat[i][j]-s_mat[i][j];
			fout<<resultant[i][j]<<" k ";
			if(j==c1-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k k k k k k k k k ";
		if(i==r1-1)
		{
			fout<<"f ";
		}
	}
	cout<<"\n\n\t\t\tMATRIX 1 - MATRIX 2"<<endl;
}
void binaryop::sub2()
{
	fout<<"MATRIX k 2 k - k MATRIX k 1 k : k ";
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			resultant[i][j]=s_mat[i][j]-f_mat[i][j];
			fout<<resultant[i][j]<<" k ";
			if(j==c1-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k k k k k k k k k ";
		if(i==r1-1)
		{
			fout<<"f ";
		}
	}
	cout<<"\n\n\t\t\tMATRIX 2 - MATRIX 1"<<endl;
}
void binaryop::multiply1()
{
	fout<<"MATRIX k 1 k * k MATRIX k 2 k : k ";
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			resultant[i][j]=0;
			for(int k=0;k<c1;k++)
			{
				resultant[i][j]+=f_mat[i][k]*s_mat[k][j];
			}
		}
	}
	for(int i1=0;i1<r1;i1++)
	{
		for(int j1=0;j1<c2;j1++)
		{
			fout<<resultant[i1][j1]<<" k ";
			if(j1==c2-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k k k k k k k k k ";
		if(i1==r1-1)
		{
			fout<<"e ";
		}
	}
	cout<<endl<<endl;
	cout<<"\t---------------------------RESULTANT--------------------------"<<endl;
	cout<<"\t----------------------MATRIX 1 * MATRIX 2---------------------"<<endl<<endl;
	for(int i19=0;i19<r1;i19++)
	{
		for(int j19=0;j19<c2;j19++)
		{
			cout<<resultant[i19][j19]<<"\t";
		}
		cout<<endl;
	}
}
void binaryop::multiply2()
{
	fout<<"MATRIX k 2 k * k MATRIX k 1 k : k ";
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c1;j++)
		{       resultant[i][j]=0;
			for(int k=0;k<c2;k++)
			{
				resultant[i][j]+=s_mat[i][k]*f_mat[k][j];
			}
		}
	}
	cout<<endl<<endl;
	for(int i112=0;i112<r1;i112++)
	{
		for(int j112=0;j112<c2;j112++)
		{
			fout<<resultant[i112][j112]<<" k ";
			if(j112==c2-1)
			{
				fout<<"e ";
			}
		}
		fout<<"k k k k k k k k k k k k k k k k k k k k k k ";
		if(i112==r1-1)
		{
			fout<<"e ";
		}
	}
	cout<<"\t---------------------------RESULTANT--------------------------"<<endl;
	cout<<"\t----------------------MATRIX 2 * MATRIX 1---------------------"<<endl<<endl;
	for(int i1=0;i1<r1;i1++)
	{
		for(int j1=0;j1<c2;j1++)
		{
			cout<<resultant[i1][j1]<<"\t";
		}
		cout<<endl;
	}
}
void binaryop::display()
{
	cout<<endl<<endl;
	cout<<"---------------------RESULTANT--------------------"<<endl<<endl;
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			cout<<resultant[i][j]<<"\t";
		}
		cout<<endl;
	}
}
class specialop
{
	public:
		int n,n1;
		specialop()
		{
			n=3;
			n1=2;
		}
		unaryop d;
		float f_mat[5][5],s[5][5],t[5][5],f[5][5],fo[5][5],f1[5][5],s1[5][5],t1[5][5];
		void areaoftri();
		void crossproduct();
		void equasol2();
		void equasol3();
};
void specialop::areaoftri()
{
	fout<<"AREA k OF k TRIANGLE k : k ";
	float e;
	f_mat[0][2]=1;
	f_mat[1][2]=1;
	f_mat[2][2]=1;
	e=(f_mat[0][0]*((f_mat[1][1]*f_mat[2][2])-(f_mat[1][2]*f_mat[2][1])))-(f_mat[0][1]*((f_mat[1][0]*f_mat[2][2])-(f_mat[1][2]*f_mat[2][0])))+(f_mat[0][2]*((f_mat[1][0]*f_mat[2][1])-(f_mat[1][1]*f_mat[2][0])));
	cout<<endl<<endl<<"AREA OF TRIANGLE PQR IS : ";
	float ex;
	if(e/2<0)
	{
		ex=0-(e/2);
		cout<<ex;
	}
	else
	{
		ex=e/2;
		cout<<ex;
	}
	fout<<ex<<" f f ";
}
void specialop::crossproduct()
{
	fout<<"CROSS k PRODUCT k : k ";
	f_mat[0][0]=1;
	f_mat[0][1]=1;
	f_mat[0][2]=1;
	cout<<"THE CROSS PRODUCT OF GIVEN VECTORS IS : "<<f_mat[1][1]*f_mat[2][2]-f_mat[1][2]*f_mat[2][1]<<"i + "<<"("<<f_mat[1][2]*f_mat[2][0]-f_mat[1][0]*f_mat[2][2]<<")"<<"j + "<<"("<<f_mat[1][0]*f_mat[2][1]-f_mat[1][1]*f_mat[2][0]<<")"<<"k";
	fout<<f_mat[1][1]*f_mat[2][2]-f_mat[1][2]*f_mat[2][1]<<"i + "<<"( "<<f_mat[1][2]*f_mat[2][0]-f_mat[1][0]*f_mat[2][2]<<" ) "<<"j + "<<" ( "<<f_mat[1][0]*f_mat[2][1]-f_mat[1][1]*f_mat[2][0]<<" )k "<<"k f f ";
}
void specialop::equasol2()
{
	float g,h,w;
	g=determinant(f1,n1);
	h=determinant(s1,n1);
	w=determinant(t1,n1);
	if(g==0)
	{
		if(h==0 && w==0)
		{
			cout<<endl<<endl;
			cout<<"INFINETELY MANY SOLUTION";
			fout<<"INFINETELY k MANY k SOLUTION f f ";
		}
		else
		{
			cout<<endl<<endl;
			cout<<"NO SOLUTION , NON - CONSISTENT EQUATION";
			fout<<"NO k SOLUTION k , k NON k - k CONSISTENT k EQUATION f f ";
		}
	}
	else
	{
		float x,y;
		x=h/g;
		y=w/g;
		cout<<endl<<endl;
		cout<<"VALUES OF X,Y AFTER SOLVING THE EQUATION IS"<<endl<<endl;
		cout<<"    X = "<<x<<endl;
		cout<<"    Y = "<<y<<endl;
		fout<<"X k = k "<<x<<" k k k k k k k ";
		fout<<"Y k = k "<<y<<" f f ";
	}
}
void specialop::equasol3()
{
	float qqq,rrr,sss,ttt;
	qqq=determinant(f,n);
	rrr=determinant(s,n);
	sss=determinant(t,n);
	ttt=determinant(fo,n);
	if(qqq==0)
	{
		if(rrr==0 && sss==0 && ttt==0)
		{
			cout<<endl<<endl;
			cout<<"INFINETELY MANY SOLUTION";
			fout<<"INFINETELY k MANY k SOLUTION f f ";
		}
		else
		{
			cout<<endl<<endl;
			cout<<"NO SOLUTION , NON - CONSISTENT EQUATION";
			fout<<"NO k SOLUTION k , k NON k - k CONSISTENT k EQUATION f f ";
		}
	}
	else
	{
		float x,y,z;
		x=rrr/qqq;
		y=sss/qqq;
		z=ttt/qqq;
		cout<<endl<<endl;
		cout<<"VALUES OF X,Y,Z AFTER SOLVING THE EQUATION IS"<<endl<<endl;
		cout<<"    X = "<<x<<endl;
		cout<<"    Y = "<<y<<endl;
		cout<<"    Z = "<<z<<endl;
		fout<<"X k = k "<<x<<" k k k k ";
		fout<<"Y k = k "<<y<<" k k k k ";
		fout<<"Z k = k "<<z<<" f f ";
	}
}
void main()
{
	int choice,choice1,choice2,choice3,choice4,choice5,count=1,smo;
	unaryop a;
	binaryop b;
	specialop c;
	char str[30];
	while(1)
	{
		clrscr();
		label1 :
		cout<<endl;
		cout<<setw(45)<<"WELCOME TO MATIX ZONE"<<endl;
		cout<<"================================================================================";
		cout<<endl<<endl;
		cout<<"1.UNARY OPERATIONS(i.e TRANSPOSE,ADJOINT,INVERSE,DETERMINANT)"<<endl;
		cout<<"2.BINARY OPERATIONS(i.e ADDITION,SUBSTRACTION,MULTIPLICATION)"<<endl;
		cout<<"3.SPECIALS OPERATION(i.e AREA OF TRIANGLE,CROSS PRODUCT,EQUATION SOLVER)"<<endl;
		cout<<"4.HISTORY"<<endl;
		cout<<"5.EXIT"<<endl<<endl;
		cout<<"================================================================================";
		cout<<endl<<endl;
		cout<<"WHAT YOU WANT TO DO ??? ENTER  ---->  ";
		cin>>choice;
		switch(choice)
		{
			case 1: clrscr();
				cout<<endl;
				cout<<setw(40)<<"        @@@@@@@@@@@@@@@@ YOU CHOOSE UNARY OPERATIONS @@@@@@@@@@@@@@@@@@       "<<endl<<endl;
				cout<<endl<<endl<<"\t\t\t    PRESS ENTER TO CONTINUE";
				getch();
				clrscr();
				label2 :
				while(1)
				{
					clrscr();
					cout<<endl;
					cout<<setw(47)<<"CHOOSE WHAT TO DO"<<endl;
					cout<<"================================================================================"<<endl;
					cout<<"1.TRANSPOSE"<<endl;
					cout<<"2.ADJOINT"<<endl;
					cout<<"3.INVERSE"<<endl;
					cout<<"4.DETERMINANT"<<endl;
					cout<<"5.HISTORY"<<endl;
					cout<<"6.GO TO MAIN MENU"<<endl;
					cout<<"7.EXIT"<<endl<<endl;
					cout<<"================================================================================"<<endl;
					cout<<"ENTER WHAT YOU WANT TO DO --------> ";
					cin>>choice1;
					switch(choice1)
					{
						case 1: clrscr();
							cout<<endl<<endl<<setw(54)<<"@@@@@@@ YOU CHOOSE TRANSPOSE @@@@@@@"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							fout<<count<<" "<<".TRANSPOSE f ";
							clrscr();
							cout<<"ENTER SIZE OF SQUARE MATRIX YOU WANT TRANSPOSE OF : "<<endl;
							cin>>a.r1>>a.c1;
							cout<<endl<<"ENTER ELEMENT OF MATRIX : ";
							fout<<"MATRIX k = k ";
							for(int i=0;i<a.r1;i++)
							{
								for(int j=0;j<a.c1;j++)
								{
									cin>>a.f_mat[i][j];
									fout<<a.f_mat[i][j]<<" k k k k k ";
									if(j==a.c1-1)
									{
									       fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k ";
								if(i==a.r1-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<endl<<endl;
							cout<<"------------------------------------TRANSPOSE-----------------------------------"<<endl<<endl;
							cout<<"MATRIX YOU ENTERED IS :";
							for(int ii=0;ii<a.r1;ii++)
							{
								for(int jj=0;jj<a.c1;jj++)
								{
									cout<<a.f_mat[ii][jj]<<"\t";
								}
								cout<<endl<<setw(24);
							}
							a.transpose();
							a.display1();
							getch();
							count++;clrscr();
							if(count==3)
							{
								label101113296:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label101113296;
								}
							}
							break;
						case 2 :clrscr();
							cout<<endl<<endl<<setw(54)<<"@@@@@@@ YOU CHOOSE ADJOINT @@@@@@@"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<"ENTER ORDER OF SQUARE MATRIX YOU WANT ADJOINT OF : ";
							cin>>a.k;
							a.r1=a.k;
							a.c1=a.k;
							fout<<count<<" "<<".ADJOINT f "<<"MATRIX k = k ";
							cout<<endl<<"ENTER ELEMENT OF MATRIX : ";
							for(int i1=0;i1<a.k;i1++)
							{
								for(int j1=0;j1<a.k;j1++)
								{
									cin>>a.f_mat[i1][j1];
									fout<<a.f_mat[i1][j1]<<" k k k k k ";
									if(j1==a.k-1)
									{
										fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k ";
								if(i1==a.k-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<endl<<endl;
							cout<<"------------------------------------ADJOINT-----------------------------------"<<endl<<endl;
							cout<<"MATRIX YOU ENTERED IS :";
							for(int ii1=0;ii1<a.r1;ii1++)
							{
								for(int jj1=0;jj1<a.c1;jj1++)
								{
									cout<<a.f_mat[ii1][jj1]<<"\t\t";
								}
								cout<<endl<<setw(24);
							}
							a.adjoint();
							a.display();
							getch();
							count++;clrscr();
							if(count==3)
							{
								label102:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label102;
								}
							}
							break;
						case 3 :clrscr();
							cout<<endl<<endl<<setw(54)<<"@@@@@@@ YOU CHOOSE INVERSE @@@@@@@"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							fout<<count<<" "<<".INVERSE f "<<"MATRIX k = k ";
							cout<<"ENTER SIZE OF SQUARE MATRIX YOU WANT INVERSE OF : ";
							cin>>a.k;
							a.r1=a.k;
							a.c1=a.k;
							cout<<endl<<"ENTER ELEMENT OF MATRIX : ";
							for(int i2=0;i2<a.r1;i2++)
							{
								for(int j2=0;j2<a.c1;j2++)
								{
									cin>>a.f_mat[i2][j2];
									fout<<a.f_mat[i2][j2]<<" k k k k k ";
									if(j2==a.c1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k ";
								if(i2==a.r1-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<endl<<endl;
							cout<<"------------------------------------INVERSE------------------------------------"<<endl<<endl;
							cout<<"MATRIX YOU ENTERED IS :";
							for(int ii2=0;ii2<a.r1;ii2++)
							{
								for(int jj2=0;jj2<a.c1;jj2++)
								{
									cout<<a.f_mat[ii2][jj2]<<"\t\t";
								}
								cout<<endl<<setw(24);
							}
							int you=a.inverse();
							if(you==0)
							{
								a.display();
							}
							getch();
							count++;clrscr();
							if(count==3)
							{
								label103:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label103;
								}
							}
							break;
						case 4 :clrscr();
							cout<<endl<<endl<<setw(54)<<"@@@@@@@ YOU CHOOSE DETERMINANT @@@@@@@"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<"ENTER ORDER OF MATRIX YOU WANT DETERMINANT VALUE OF : ";
							cin>>a.k;
							fout<<count<<" "<<".DETERMINANT f "<<"MATRIX k = k ";
							cout<<"ENTER ELEMENT OF MATRIX : ";
							for(int i3=0;i3<a.k;i3++)
							{
								for(int j3=0;j3<a.k;j3++)
								{
									cin>>a.f_mat[i3][j3];
									fout<<a.f_mat[i3][j3]<<" k k k k k ";
									if(j3==a.k-1)
									{
										fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k ";
								if(13==a.k-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<endl<<endl;
							cout<<"------------------------------------DETERMINANT---------------------------------"<<endl<<endl;
							cout<<"MATRIX YOU ENTERED IS :";
							for(int ii3=0;ii3<a.k;ii3++)
							{
								for(int jj3=0;jj3<a.k;jj3++)
								{
									cout<<a.f_mat[ii3][jj3]<<"\t\t";
								}
								cout<<endl<<setw(24);
							}
							a.jrdeterminant();
							getch();
							count++;clrscr();
							if(count==3)
							{
								label104:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label104;
								}
							}
							break;
						case 5 :clrscr();
							fout.close();
							ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
							while(fin)
							{
								fin.getline(str,30,' ');
								if(strcmp(str,"e")==0)
								{
									cout<<endl;
								}
								else if(strcmp(str,"f")==0)
								{
									cout<<endl;
								}
								else if(strcmp(str,"k")==0)
								{
									cout<<" ";
								}
								else
								{
									cout<<str;
								}
							}
							fin.close();
							getch();
							fout.open("project.txt",ios::app);
							break;
						case 6 :clrscr();
							cout<<endl;
							cout<<setw(48)<<"SURE WANT TO GO TO MAIN MENU"<<endl<<endl<<setw(45)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							goto label1;
						case 7 :fout.close();
							fout.open("project.txt",ios::out);
							fout.close();
							exit(0);
						default :cout<<endl<<endl<<setw(45)<<"ENTER CORRECT CHOICE"<<endl<<endl<<setw(47)<<"PRESS ENTER TO CONTINUE";
							 getch();
							 clrscr();
							 goto label2;
					}
				}
			case 2: clrscr();
				cout<<endl;
				cout<<setw(40)<<"YOU CHOOSE BINARY OPERATIONS"<<endl<<"PRESS ENTER TO CONTINUE";
				clrscr();
				cout<<"       @@@@@@@@@@@@@@@@ YOU CHOOSE BINARY OPERATION @@@@@@@@@@@@@@@@@@@      "<<endl;
				cout<<endl<<endl<<"\t\t\t    PRESS ENTER TO CONTINUE";
				getch();
				clrscr();
				label5 :
				while(1)
				{
					clrscr();
					cout<<endl;
					cout<<setw(40)<<"CHOOSE WHAT TO DO"<<endl;
					cout<<"================================================================================"<<endl;
					cout<<"1.ADDITION"<<endl;
					cout<<"2.SUBSTRACTION"<<endl;
					cout<<"3.MULTIPLICATION"<<endl;
					cout<<"4.HISTORY"<<endl;
					cout<<"5.GO TO MAIN MENU "<<endl;
					cout<<"6.EXIT"<<endl<<endl;
					cout<<"================================================================================"<<endl;
					cout<<"ENTER WHAT YOU WANT TO DO --------> ";
					cin>>choice2;
					switch(choice2)
					{
						case 1: clrscr();
							cout<<endl;
							cout<<setw(47)<<"YOU CHOOSE ADDITION"<<endl<<endl<<setw(50)<<"PRESS ENTER TO CONTINUE";
							getch();
							label10 :
							clrscr();
							cout<<"ENTER SIZE OF MATRIX 1 : ";
							cin>>b.r1>>b.c1;
							fout<<count<<" "<<".ADDITION f ";
							cout<<"ENTER ELEMENT OF MATRIX 1 : ";
							for(int i4=0;i4<b.r1;i4++)
							{
								for(int j4=0;j4<b.c1;j4++)
								{
									cin>>b.f_mat[i4][j4];
								}
							}
							cout<<endl;
							label099 :
							cout<<"ENTER SIZE OF MATRIX 2 : ";
							cin>>b.r2>>b.c2;
							cout<<endl<<endl;
							if(b.r1==b.r2&&b.c1==b.c2)
							{
								fout<<"MATRIX k 1= k ";
								cout<<"MATRIX COMPATIBLE FOR ADDITION"<<endl<<endl<<endl;
								if(b.r1>=3)
								{count++;}
								for(int i4=0;i4<b.r1;i4++)
								{
									for(int j4=0;j4<b.c1;j4++)
									{
										fout<<b.f_mat[i4][j4]<<" k ";
										if(j4==b.c1-1)
										{
											fout<<"e ";
										}
									}
									fout<<"k k k k k k k k k k ";
									if(i4==b.r1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"MATRIX k 2= k ";
							}
							else
							{
								clrscr();
								cout<<"\t\t#@#@#@      MATRIX SIZE MISMATCH       #@#@#@"<<endl<<endl;
								cout<<"WHAT DO YOU WANT ???"<<endl;
								cout<<"1.ENTER VALUES FROM STARTING"<<endl;
								cout<<"2.MODIFY MATRIX 2 VALUE"<<endl<<endl;
								cout<<"ENTER YOUR CHOICE HERE -----------> ";
								int rot;
								cin>>rot;
								if(rot==1)
								{
									clrscr();
									goto label10;
								}
								else
								{
									clrscr();
									goto label099;
								}
							}
							cout<<"ENTER ELEMENT OF MATRIX 2 : ";
							for(int i5=0;i5<b.r1;i5++)
							{
								for(int j5=0;j5<b.c1;j5++)
								{
									cin>>b.s_mat[i5][j5];
									fout<<b.s_mat[i5][j5]<<" k ";
									if(j5==b.c1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k k ";
								if(i5==b.r1-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							cout<<endl<<endl;
							cout<<"------------------------------------ADDITION---------------------------------"<<endl<<endl;
							cout<<"FIRST MATRIX YOU ENTERED IS :";
							for(int iiii3=0;iiii3<b.r1;iiii3++)
							{
								for(int jjjj3=0;jjjj3<b.c1;jjjj3++)
								{
									cout<<b.f_mat[iiii3][jjjj3]<<"\t  ";
								}
								cout<<endl<<setw(30);
							}
							cout<<endl<<endl;
							cout<<"SECOND MATRIX YOU ENTERED IS :";
							for(int iii3=0;iii3<b.r2;iii3++)
							{
								for(int jjj3=0;jjj3<b.c2;jjj3++)
								{
									cout<<b.s_mat[iii3][jjj3]<<"\t  ";
								}
								cout<<endl<<setw(31);
							}
							b.add();
							b.display();
							getch();
							count++;clrscr();
							if(count==3)
							{
								label105:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label105;
								}
							}
							break;
						case 2 :clrscr();
							cout<<endl;
							cout<<setw(48)<<"YOU CHOOSE SUBSTRACTION"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							label101:
							clrscr();
							fout<<count<<" "<<".SUBSTRACTION f ";
							label10113:
							cout<<"ENTER SIZE OF MATRIX 1 : ";
							cin>>b.r1>>b.c1;
							cout<<"ENTER ELEMENT OF MATRIX 1 : ";
							for(int i6=0;i6<b.r1;i6++)
							{
								for(int j6=0;j6<b.c1;j6++)
								{
									cin>>b.f_mat[i6][j6];
								}
							}
							cout<<endl;
							label09911 :
							cout<<"ENTER SIZE OF MATRIX 2 : ";
							cin>>b.r2>>b.c2;
							cout<<endl<<endl;
							if(b.r1==b.r2&&b.c1==b.c2)
							{
								fout<<"MATRIX k 1= k ";
								cout<<"MATRIX COMPATIBLE FOR SUBSTRACTION"<<endl<<endl<<endl;
								if(b.r1>=3)
								{count++;}
								for(int i6=0;i6<b.r1;i6++)
								{
									for(int j6=0;j6<b.c1;j6++)
									{
										fout<<b.f_mat[i6][j6]<<" k ";
										if(j6==b.c1-1)
										{
											fout<<"e ";
										}
									}
									fout<<"k k k k k k k k k k ";
									if(i6==b.r1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"MATRIX k 2= k ";
							}
							else
							{
								clrscr();
								cout<<"\t\t#@#@#@      MATRIX SIZE MISMATCH       #@#@#@"<<endl<<endl;
								cout<<"WHAT DO YOU WANT ???"<<endl;
								cout<<"1.ENTER VALUES FROM STARTING"<<endl;
								cout<<"2.MODIFY MATRIX 2 VALUE"<<endl<<endl;
								cout<<"ENTER YOUR CHOICE HERE -----------> ";
								int rot;
								cin>>rot;
								if(rot==1)
								{
									clrscr();
									goto label10113;
								}
								else
								{
									clrscr();
									goto label09911;
								}
							}
							cout<<"ENTER ELEMENT OF MATRIX 2 : ";
							for(int i7=0;i7<b.r1;i7++)
							{
								for(int j7=0;j7<b.c1;j7++)
								{
									cin>>b.s_mat[i7][j7];
									fout<<b.s_mat[i7][j7]<<" k ";
									if(j7==b.c1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k k ";
								if(i7==b.r1-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl;
							cout<<"PRESS ENTER TO CONTINUE";
							getch();
							label3 :
							clrscr();
							cout<<"ENTER WHAT YOU WANT : ";
							cout<<"1. a-b "<<endl;
							cout<<setw(29)<<"2. b-a "<<endl<<endl;
							cout<<"ENTER YOUR CHOICE HERE --------->  ";
							cin>>choice3;
							if(choice3==1)
							{
								cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
								getch();
								clrscr();
								cout<<endl<<endl;
								cout<<"-----------------------------------SUBSTRACTION---------------------------------"<<endl<<endl;
								cout<<"FIRST MATRIX YOU ENTERED IS :";
								for(int iiii31=0;iiii31<b.r1;iiii31++)
								{
									for(int jjjj31=0;jjjj31<b.c1;jjjj31++)
									{
										cout<<b.f_mat[iiii31][jjjj31]<<"\t\t";
									}
									cout<<endl<<setw(30);
								}
								cout<<endl<<endl;
								cout<<"SECOND MATRIX YOU ENTERED IS :";
								for(int iii31=0;iii31<b.r2;iii31++)
								{
									for(int jjj31=0;jjj31<b.c2;jjj31++)
									{
										cout<<b.s_mat[iii31][jjj31]<<"\t\t";
									}
									cout<<endl<<setw(31);
								}
								b.sub1();
								b.display();
								getch();
							}
							else if(choice3==2)
							{
								cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
								getch();
								clrscr();
								cout<<endl<<endl;
								cout<<"-----------------------------------SUBSTRACTION---------------------------------"<<endl<<endl;
								cout<<"FIRST MATRIX YOU ENTERED IS :";
								for(int iiii31=0;iiii31<b.r1;iiii31++)
								{
									for(int jjjj31=0;jjjj31<b.c1;jjjj31++)
									{
										cout<<b.f_mat[iiii31][jjjj31]<<"\t  ";
									}
									cout<<endl<<setw(30);
								}
								cout<<endl<<endl;
								cout<<"SECOND MATRIX YOU ENTERED IS :";
								for(int iii31=0;iii31<b.r2;iii31++)
								{
									for(int jjj31=0;jjj31<b.c2;jjj31++)
									{
										cout<<b.s_mat[iii31][jjj31]<<"\t  ";
									}
									cout<<endl<<setw(31);
								}
								b.sub2();
								b.display();
								getch();
							}
							else
							{
								cout<<setw(40)<<"ENTER CORRECT CHOICE";
								getch();
								clrscr();
								goto label3;
							}
							count++;clrscr();
							if(count==3)
							{
								label106:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label106;
								}
							}
							break;
						case 3 :clrscr();
							cout<<endl;
							cout<<setw(49)<<"YOU CHOOSE MULTIPLICATION"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							label10111 :
							clrscr();
							fout<<count<<" "<<".MULTIPLICATION f ";
							label1011323 :
							cout<<"ENTER SIZE OF MATRIX 1 : ";
							cin>>b.r1>>b.c1;
							cout<<"ENTER ELEMENT OF MATRIX : ";
							for(int i8=0;i8<b.r1;i8++)
							{
								for(int j8=0;j8<b.c1;j8++)
								{
									cin>>b.f_mat[i8][j8];
								}
							}
							cout<<endl<<endl;
							label0991123 :
							cout<<"ENTER SIZE OF MATRIX 2 : ";
							cin>>b.r2>>b.c2;
							cout<<endl<<endl;
							if(b.c1==b.r2)
							{
								fout<<"MATRIX k 1= k ";
								cout<<"MATRIX COMPATIBLE FOR MULTIPLICATION"<<endl<<endl<<endl;
								if(b.r1>=3)
								{count++;}
								for(int i8=0;i8<b.r1;i8++)
								{
									for(int j8=0;j8<b.c1;j8++)
									{
										fout<<b.f_mat[i8][j8]<<" k ";
										if(j8==b.c1-1)
										{
											fout<<"e ";
										}
									}
									fout<<"k k k k k k k k k k ";
									if(i8==b.r1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"MATRIX k 2= k ";
							}
							else
							{
								clrscr();
								cout<<"\t\t#@#@#@      MATRIX SIZE MISMATCH       #@#@#@"<<endl<<endl;
								cout<<"WHAT DO YOU WANT ???"<<endl;
								cout<<"1.ENTER VALUES FROM STARTING"<<endl;
								cout<<"2.MODIFY MATRIX 2 VALUE"<<endl<<endl;
								cout<<"ENTER YOUR CHOICE HERE -----------> ";
								int rot;
								cin>>rot;
								if(rot==1)
								{
									clrscr();
									goto label1011323;
								}
								else
								{
									clrscr();
									goto label0991123;
								}
							}
							cout<<"ENTER ELEMENT OF MATRIX 2 : ";
							for(int i9=0;i9<b.r1;i9++)
							{
								for(int j9=0;j9<b.c1;j9++)
								{
									cin>>b.s_mat[i9][j9];
									fout<<b.s_mat[i9][j9]<<" k ";
									if(j9==b.c1-1)
									{
										fout<<"e ";
									}
								}
								fout<<"k k k k k k k k k k ";
								if(i9==b.r1-1)
								{
									fout<<"f ";
								}
							}
							cout<<endl<<endl;
							cout<<"PRESS ENTER TO CONTINUE";
							getch();
							label4 :
							clrscr();
							cout<<"ENTER WHAT YOU WANT : ";
							cout<<"1. a*b "<<endl;
							cout<<setw(29)<<"2. b*a "<<endl<<endl;
							cout<<"ENTER YOUR CHOICE HERE --------> ";
							cin>>choice4;
							if(choice4==1)
							{
								cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
								getch();
								clrscr();
								cout<<endl<<endl;
								cout<<"----------------------------------MULTIPLICATION--------------------------------"<<endl<<endl;
								cout<<"FIRST MATRIX YOU ENTERED IS :";
								for(int iiii311=0;iiii311<b.r1;iiii311++)
								{
									for(int jjjj311=0;jjjj311<b.c1;jjjj311++)
									{
										cout<<b.f_mat[iiii311][jjjj311]<<"\t\t";
									}
									cout<<endl<<setw(30);
								}
								cout<<endl<<endl;
								cout<<"SECOND MATRIX YOU ENTERED IS :";
								for(int iii313=0;iii313<b.r2;iii313++)
								{
									for(int jjj313=0;jjj313<b.c2;jjj313++)
									{
										cout<<b.s_mat[iii313][jjj313]<<"\t\t";
									}
									cout<<endl<<setw(31);
								}
								b.multiply1();
								getch();
							}
							else if(choice4==2)
							{
								cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
								getch();
								clrscr();
								cout<<endl<<endl;
								cout<<"----------------------------------MULTIPLICATION--------------------------------"<<endl<<endl;
								cout<<"FIRST MATRIX YOU ENTERED IS :";
								for(int iiii311=0;iiii311<b.r1;iiii311++)
								{
									for(int jjjj311=0;jjjj311<b.c1;jjjj311++)
									{
										cout<<b.f_mat[iiii311][jjjj311]<<"\t\t";
									}
									cout<<endl<<setw(30);
								}
								cout<<endl<<endl;
								cout<<"SECOND MATRIX YOU ENTERED IS :";
								for(int iii313=0;iii313<b.r2;iii313++)
								{
									for(int jjj313=0;jjj313<b.c2;jjj313++)
									{
										cout<<b.s_mat[iii313][jjj313]<<"\t\t";
									}
									cout<<endl<<setw(31);
								}
								b.multiply2();
								getch();
							}
							else
							{
								cout<<setw(40)<<"ENTER CORRECT CHOICE";
								getch();
								clrscr();
								goto label4;
							}
							count++;clrscr();
							if(count==3)
							{
								label107:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label107;
								}
							}
							break;
						case 4 :clrscr();
							fout.close();
							ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
							while(fin)
							{
								fin.getline(str,30,' ');
								if(strcmp(str,"e")==0)
								{
									cout<<endl;
								}
								else if(strcmp(str,"f")==0)
								{
									cout<<endl;
								}
								else if(strcmp(str,"k")==0)
								{
									cout<<" ";
								}
								else
								{
									cout<<str;
								}
							}
							fin.close();
							fout.open("project.txt",ios::app);
							getch();
							break;
						case 5 :clrscr();
							cout<<endl;
							cout<<setw(48)<<"SURE WANT TO GO TO MAIN MENU"<<endl<<endl<<setw(45)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							goto label1;
						case 6 : fout.close();
							 fout.open("project.txt",ios::out);
							 fout.close();
							 exit(0);
							 break;
						default :cout<<endl<<endl<<setw(45)<<"ENTER CORRECT CHOICE"<<endl<<endl<<setw(47)<<"PRESS ENTER TO CONTINUE";
							 getch();
							 clrscr();
							 goto label5;
					}
				}
			case 3 :clrscr();
				cout<<endl;
				cout<<"\t@@@@@@@@@@@@@@@@ YOU CHOOSE SPECIAL OPERATION @@@@@@@@@@@@@@@@@@@"<<endl;
				cout<<endl<<"\t\t\t    PRESS ENTER TO CONTINUE";
				getch();
				clrscr();
				label6 :
				while(1)
				{
					clrscr();
					label3333 :
					cout<<endl;
					cout<<setw(48)<<"CHOOSE WHAT TO DO"<<endl;
					cout<<"================================================================================"<<endl;
					cout<<"1.AREA OF TRIANGLE"<<endl;
					cout<<"2.CROSS PRODUCT"<<endl;
					cout<<"3.EQUATION SOLVER"<<endl;
					cout<<"4.HISTORY"<<endl;
					cout<<"5.GO TO MAIN MENU "<<endl;
					cout<<"6.EXIT"<<endl<<endl;
					cout<<"================================================================================"<<endl;
					cout<<"ENTER WHAT YOU WANT TO DO -------->  ";
					cin>>choice5;
					switch(choice5)
					{
						case 1: clrscr();
							cout<<endl;
							cout<<endl<<endl<<setw(54)<<"@@@@@@@ YOU CHOOSE AREA OF TRIANGLE @@@@@@@"<<endl<<endl<<setw(44)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							fout<<count<<" "<<".AREA k OF k TRIANGLE f ";
							cout<<"ENTER CO-ORDINATE OF POINT 1(i.e IN ORDER X,Y) : ";
							cin>>c.f_mat[0][0]>>c.f_mat[0][1];
							cout<<"ENTER CO-ORDINATE OF POINT 2(i.e IN ORDER X,Y) : ";
							cin>>c.f_mat[1][0]>>c.f_mat[1][1];
							cout<<"ENTER CO-ORDINATE OF POINT 3(i.e IN ORDER X,Y) : ";
							cin>>c.f_mat[2][0]>>c.f_mat[2][1];
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							fout<<"CO-ORDINATES k ENTERED k : k "<<"{ "<<"k ( "<<c.f_mat[0][0]<<" , "<<c.f_mat[0][1]<<" ) k "<<", "<<"k ( "<<c.f_mat[1][0]<<" , "<<c.f_mat[1][1]<<" ) k "<<", "<<"k ( "<<c.f_mat[2][0]<<" , "<<c.f_mat[2][1]<<" ) k } "<<"f ";
							getch();
							clrscr();
							cout<<endl<<endl;
							cout<<"--------------------------------AREA OF TRIANGLE--------------------------------"<<endl<<endl;
							cout<<"POINTS YOU ENTERED IS : P ("<<c.f_mat[0][0]<<","<<c.f_mat[0][1]<<")"<<endl;
							cout<<setw(27)<<"Q ("<<c.f_mat[1][0]<<","<<c.f_mat[1][1]<<")"<<endl;
							cout<<setw(27)<<"R ("<<c.f_mat[2][0]<<","<<c.f_mat[2][1]<<")"<<endl;
							c.areaoftri();
							getch();
							count++;clrscr();
							if(count==3)
							{
								label108:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label108;
								}
							}
							break;
						case 2 :clrscr();
							cout<<endl;
							cout<<endl<<endl<<setw(56)<<"@@@@@@@ YOU CHOOSE CROSS PRODUCT @@@@@@@"<<endl<<endl<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							fout<<count<<" "<<".CROSS k PRODUCT f ";
							clrscr();
							cout<<"ENTER VECTOR 1 COMPONENT IN ORDER(i.e X,Y,Z) : ";
							cin>>c.f_mat[1][0]>>c.f_mat[1][1]>>c.f_mat[1][2];
							cout<<"ENTER VECTOR 2 COMPONENT IN OEDER(i.e X,Y,Z) : ";
							cin>>c.f_mat[2][0]>>c.f_mat[2][1]>>c.f_mat[2][2];
							cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
							getch();
							fout<<"VECTOR k 1 k : k "<<"( "<<c.f_mat[1][0]<<" ) i+ ( "<<c.f_mat[1][1]<<" ) j+ ( "<<c.f_mat[1][2]<<" )k k k k k k ";
							fout<<"VECTOR k 2 k : k "<<"( "<<c.f_mat[2][0]<<" ) i+ ( "<<c.f_mat[2][1]<<" ) j+ ( "<<c.f_mat[2][2]<<" )k f ";
							clrscr();
							cout<<endl<<endl;
							cout<<"----------------------------------CROSS PRODUCT---------------------------------"<<endl<<endl;
							cout<<"THE VECTORS YOU ENTERED IS : A ="<<c.f_mat[1][0]<<"i + ("<<c.f_mat[1][1]<<")j + ("<<c.f_mat[1][2]<<")k"<<endl;
							cout<<setw(32)<<"B ="<<c.f_mat[2][0]<<"i + ("<<c.f_mat[2][1]<<")j + ("<<c.f_mat[2][2]<<")k"<<endl<<endl<<endl;
							c.crossproduct();
							getch();
							count++;clrscr();
							if(count==3)
							{
								label109:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label109;
								}
							}
							break;
						case 3 :clrscr();
							cout<<endl;
							cout<<endl<<endl<<setw(56)<<"@@@@@@@ YOU CHOOSE EQUATION SOLVER @@@@@@@"<<endl<<endl<<setw(47)<<"PRESS ENTER TO CONTINUE";
							getch();
							label3232 :
							clrscr();
							cout<<"WHAT YOU WANT ??????"<<endl<<endl;
							cout<<"1.)  2 VARIABLE 2 EQUATION"<<endl;
							cout<<"2.)  3 VARIABLE 3 EQUATION"<<endl;
							cout<<"3.)  BACK TO MENU"<<endl<<endl<<endl;
							cout<<"ENTER YOUR CHOICE HERE --------->   ";
							int chhhh;
							cin>>chhhh;
							cout<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							if(chhhh==1)
							{
								fout<<count<<" "<<".EQUATION k SOLVER ( TWO k VARIABLE ) f ";
								cout<<"ENTER COFFICIENT OF X,Y OF FIRST EQUATION AND THEN RHS i.e CONSTANT: ";
								cin>>c.f_mat[0][0]>>c.f_mat[0][1]>>c.f_mat[0][2];
								cout<<"ENTER COFFICIENT OF X,Y OF SECOND EQUATION AND THEN RHS i.e CONSTANT: ";
								cin>>c.f_mat[1][0]>>c.f_mat[1][1]>>c.f_mat[1][2];
								fout<<"EQUATION k 1 k : k ( "<<c.f_mat[0][0]<<" ) x k + k ( "<<c.f_mat[0][1]<<" ) y k = k "<<c.f_mat[0][2]<<" e ";
								fout<<"EQUATION k 2 k : k ( "<<c.f_mat[1][0]<<" ) x k + k ( "<<c.f_mat[1][1]<<" ) y k = k "<<c.f_mat[1][2]<<" f ";
								cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
								getch();
								clrscr();
								cout<<endl<<endl;
								cout<<"----------------------------EQUATIONS SOLVER( 2 VAR.)---------------------------"<<endl<<endl;
								cout<<"THE EQUATION YOU ENTERED IS : "<<c.f_mat[0][0]<<"x + ("<<c.f_mat[0][1]<<")y = "<<c.f_mat[0][2]<<endl;
								cout<<setw(31)<<c.f_mat[1][0]<<"x + ("<<c.f_mat[1][1]<<")y = "<<c.f_mat[1][2]<<endl;
								for(int ops=0;ops<2;ops++)
								{
									for(int ops1=0;ops1<2;ops1++)
									{
										c.f1[ops][ops1]=c.f_mat[ops][ops1];
									}
								}
								for(int ops2=0;ops2<2;ops2++)
								{
									for(int ops3=0;ops3<2;ops3++)
									{
										if(ops3==0)
										{
										c.s1[ops2][ops3]=c.f_mat[ops2][2];
										}
										else
										{
											c.s1[ops2][ops3]=c.f_mat[ops2][ops3];
										}
									}
								}
								for(int ops4=0;ops4<2;ops4++)
								{
									for(int ops5=0;ops5<2;ops5++)
									{
										if(ops5==1)
										{
											c.t1[ops4][ops5]=c.f_mat[ops4][2];
										}
										else
										{
											c.t1[ops4][ops5]=c.f_mat[ops4][ops5];
										}
									}
								}
								c.equasol2();
								getch();
								count++;clrscr();
								if(count==3)
								{
								label110:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label110;								}
								}
							}
							else if(chhhh==2)
							{
								fout<<count<<" "<<".EQUATION k SOLVER ( THREE k VARIABLE ) f ";
								cout<<"ENTER COFFICIENT OF X,Y,Z OF FIRST EQUATION AND THEN RHS i.e CONSTANT: ";
								cin>>c.f_mat[0][0]>>c.f_mat[0][1]>>c.f_mat[0][2]>>c.f_mat[0][3];
								cout<<"ENTER COFFICIENT OF X,Y,Z OF SECOND EQUATION AND THEN RHS i.e CONSTANT: ";
								cin>>c.f_mat[1][0]>>c.f_mat[1][1]>>c.f_mat[1][2]>>c.f_mat[1][3];
								cout<<"ENTER COFFICIENT OF X,Y,Z OF THIRD EQUATION AND THEN RHS i.e CONSTANT: ";
								cin>>c.f_mat[2][0]>>c.f_mat[2][1]>>c.f_mat[2][2]>>c.f_mat[2][3];
								cout<<endl<<endl<<"PRESS ENTER TO CONTINUE";
								fout<<"EQUATION k 1 k : k ( "<<c.f_mat[0][0]<<" ) x k + k ( "<<c.f_mat[0][1]<<" ) y k + k ( "<<c.f_mat[0][2]<<" ) z k = k "<<c.f_mat[0][3]<<" e ";
								fout<<"EQUATION k 2 k : k ( "<<c.f_mat[1][0]<<" ) x k + k ( "<<c.f_mat[1][1]<<" ) y k + k ( "<<c.f_mat[1][2]<<" ) z k = k "<<c.f_mat[1][3]<<" e ";
								fout<<"EQUATION k 3 k : k ( "<<c.f_mat[2][0]<<" ) x k + k ( "<<c.f_mat[2][1]<<" ) y k + k ( "<<c.f_mat[2][2]<<" ) z k = k "<<c.f_mat[2][3]<<" f ";
								getch();
								clrscr();
								cout<<endl<<endl;
								cout<<"----------------------------EQUATIONS SOLVER( 3 VAR.)---------------------------"<<endl<<endl;
								cout<<"THE EQUATION YOU ENTERED IS : "<<c.f_mat[0][0]<<"x + ("<<c.f_mat[0][1]<<")y + ("<<c.f_mat[0][2]<<")z = "<<c.f_mat[0][3]<<endl;
								cout<<setw(31)<<c.f_mat[1][0]<<"x + ("<<c.f_mat[1][1]<<")y + ("<<c.f_mat[1][2]<<")z = "<<c.f_mat[1][3]<<endl;
								cout<<setw(31)<<c.f_mat[2][0]<<"x + ("<<c.f_mat[2][1]<<")y + ("<<c.f_mat[2][2]<<")z = "<<c.f_mat[2][3]<<endl<<endl;
								for(int op=0;op<3;op++)
								{
									for(int op1=0;op1<3;op1++)
									{
										c.f[op][op1]=c.f_mat[op][op1];
									}
								}
								for(int op2=0;op2<3;op2++)
								{
									for(int op3=0;op3<3;op3++)
									{
										if(op3==0)
										{
										c.s[op2][op3]=c.f_mat[op2][3];
										}
										else
										{
											c.s[op2][op3]=c.f_mat[op2][op3];
										}
									}
								}
								for(int op4=0;op4<3;op4++)
								{
									for(int op5=0;op5<3;op5++)
									{
										if(op5==1)
										{
										c.t[op4][op5]=c.f_mat[op4][3];
										}
										else
										{
											c.t[op4][op5]=c.f_mat[op4][op5];
										}
									}
								}
								for(int op6=0;op6<3;op6++)
								{
									for(int op7=0;op7<3;op7++)
									{
										if(op7==2)
										{
											c.fo[op6][op7]=c.f_mat[op6][3];
										}
										else
										{
											c.fo[op6][op7]=c.f_mat[op6][op7];
										}
									}
								}
								c.equasol3();
								getch();
								count++;clrscr();
								if(count==3)
								{
								label111:
								clrscr();
								cout<<"HISTORY FULL TRUNCATING.......";count=1;
								cout<<"\n\n\t\t\t1.)CONTINUE   OR   2.)YOU WANT TO SEE HISTORY\n\n";
								cout<<"ENTER YOUR CHOICE HERE-------->";cin>>smo;
								getch();
								switch(smo)
								{
									case 1: fout.close();
										fout.open("project.txt",ios::out);
										fout.close();
										clrscr();
										break;
									case 2: clrscr();
										fout.close();
										ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
										while(fin)
										{
											fin.getline(str,30,' ');
											if(strcmp(str,"e")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"f")==0)
											{
												cout<<endl;
											}
											else if(strcmp(str,"k")==0)
											{
												cout<<" ";
											}
											else
											{
												cout<<str;
											}
										}
										fin.close();
										cout<<"PRESS ENTER TO CONTINUE\nTHIS DATA WILL BE TRUNCATED AFTER YOU PRESS ENTER";
										getch();
										fout.open("project.txt",ios::out);
										fout.close();
										fout.open("project.txt",ios::app);
										clrscr();
										break;
									default:goto label111;
								}
								}

							}
							else if(chhhh==3)
							{
								goto label3333;
							}
							else
							{
								cout<<endl<<endl;
								cout<<"ENTER CORRECT CHOICE";
								goto label3232;
							}
							break;
						case 4 :clrscr();
							fout.close();
							ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
							while(fin)
							{
								fin.getline(str,30,' ');
								if(strcmp(str,"e")==0)
								{
									cout<<endl;
								}
								else if(strcmp(str,"f")==0)
								{
									cout<<endl;
								}
								else if(strcmp(str,"k")==0)
								{
									cout<<" ";
								}
								else
								{
									cout<<str;
								}
							}
							fin.close();
							fout.open("project.txt",ios::app);
							getch();
							break;
						case 5 :clrscr();
							cout<<endl;
							cout<<setw(51)<<"SURE WANT TO GO TO MAIN MENU"<<endl<<endl;
							cout<<setw(48)<<"PRESS ENTER TO CONTINUE";
							getch();
							clrscr();
							goto label1;
						case 6 :fout.close();
							fout.open("project.txt",ios::out);
							fout.close();
							exit(0);
							break;
						default :cout<<endl<<endl<<setw(45)<<"ENTER CORRECT CHOICE"<<endl<<endl<<setw(47)<<"PRESS ENTER TO CONTINUE"<<endl<<endl;
							 getch();
							 clrscr();
							 goto label6;
					}
				}
			case 4 :clrscr();
				fout.close();
				ifstream fin("project.txt");cout<<"\t\t\tYOUR PREVIOUS CALCULATION\n";
				while(fin)
				{
					fin.getline(str,30,' ');
					if(strcmp(str,"e")==0)
					{
						cout<<endl;
					}
					else if(strcmp(str,"f")==0)
					{
						cout<<endl;
					}
					else if(strcmp(str,"k")==0)
					{
						cout<<" ";
					}
					else
					{
						cout<<str;
					}
				}
				getch();
				fin.close();
				fout.open("project.txt",ios::app);
				break;
			case 5 :fout.close();
				fout.open("project.txt",ios::out);
				fout.close();
				exit(0);
				break;
			default :cout<<endl<<endl<<setw(45)<<"ENTER CORRECT CHOICE";
				 cout<<endl<<endl<<setw(47)<<"PRESS ENTER TO CONTINUE";
				 getch();
				 clrscr();
				 goto label1;
		}
	}
}
