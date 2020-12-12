/*
Member 1: Name : Harsh Patel Rno: AU1841075
Member 2: Name : Sanket Shah Rno: AU1841120
*/

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

void printpattern();
void setxy (int x, int y);
void fontcolor(int n);
int colormenu();
int compare(int x[57],int y[57],int a[7][2], int count,int n);
void MinesGenerator(int x[120],int y[120],int a[7][2], int n);
void menu();
void gmenu(int n);
void instructions();
int MinesCalc(int x,int y,int a[7][2],int n);
void printsquare(int x[120], int y[120], int nmines[120], int count);
void printmines(int mines[7][2],int n);
void loading();
void getscore(int ttaken,int lev);
void displayscore();
void freenum(int wincount,int n);
void nommines(int nummines[9][9],int mines[7][2], int n);
void surrounding(int x[120],int y[120],int *pcount,int nmines[120],int nummines[9][9]);
void checkwincount(int x[120], int y[120], int *pwincount);
void levscreen();

int main(){
	int x[120],y[120],color,test=0,menuc,i,count=0,k=0,nmines[120],p,ttaken,nummines[9][9],wincount=0,lev,n;
	int *pcount=&count;
	int *pwincount=&wincount;
	time_t stime,etime;
	cstart:
	color = colormenu();
	fontcolor(color);//Change color
	loading();
	mstart:
	system("cls");
	menu();
	printf("\n\t\t\t");
	fflush(stdin);
	scanf("%d", &menuc);
	gmenu(menuc);
	if(menuc==4){
		goto cstart;
	}
	if(menuc==2 || menuc==3 || menuc>5 || menuc<=0){
		goto mstart;
	}
	if(menuc==1){
		strlev:
		levscreen();
		scanf("%d", &lev);
		if(lev==0||lev>3){
			goto strlev;
		}
		else{
		if(lev==1){
			n=7;
		}
		else if(lev==2){
			n=9;
		}
		else if(lev==3){
			n=11;
		}
	  }
	}
	int mines[n][2];
	for(i=0;i<120;i++){
		x[i]=0;
		y[i]=0;
		count=0;
		wincount=0;
	}
	time(&stime);
	gstart:
	system("cls");
	printf("\n\t\t\t\t\t\t\t\tMine-Sweeper");
	printpattern();//Print Pattern
	setxy(4,10);
	freenum(wincount,n);
	printf("\n\tEnter co-ordinates:\n");//Get co ordinates
	printf("\tx = ");
	fflush(stdin);
	scanf("%d", &x[count]);
	printf("\n\ty = ");
	fflush(stdin);
	scanf("%d", &y[count]);
	if(x[count]==66||y[count]==66){
		goto mstart;
	}
	if(x[count]==0 || x[count]>8 || y[count]==0 || y[count]>8 || x[count]<0 || y[count]<0){
		printf("\n Enter only 1-8");
		sleep(2);
		goto gstart;
	}
	
	MinesGenerator(x,y,mines,n);
	nommines(nummines,mines,n);
	nmines[count]=MinesCalc(x[count],y[count],mines,n);
		if(nmines[count]==0){
			surrounding(x,y,pcount,nmines,nummines);
			count++;
		}else{
	count++;
	wincount++;
}

	start:
	system("cls");
	
	fontcolor(color);//Change color
	
	printf("\n\t\t\t\t\t\t\t\tMine-Sweeper");
	printpattern();//Print Pattern
	printsquare(x,y,nmines,count);
	setxy(4,10);
	
	checkwincount(x,y,pwincount);
	freenum(wincount,n);
	printf("\n\tEnter co-ordinates:\n");//Get co ordinates
	printf("\tx = ");
	fflush(stdin);
	scanf("%d", &x[count]);
	printf("\n\ty = ");
	fflush(stdin);
	scanf("%d", &y[count]);
	if(x[count]==66||y[count]==66){
		goto mstart;
	}
	if(x[count]==6969){
		goto win;
	}
	if(x[count]=='b'||x[count]=='B'||y[count]=='b'||y[count]=='B'){
		goto mstart;
	}
	if(x[count]==0 || x[count]>8 || y[count]==0 || y[count]>8 || x[count]<0 || y[count]<0){
		printf("\n Enter only 1-8");
		sleep(2);
		goto start;
	}
	for(i=0;i<count;i++){
		if(x[count]==x[i] && y[count]==y[i]){
			printf("Entered coordinates already exist. Enter new coordinates.\n");
			sleep(2);
			goto start;
		}
	}
	
	nmines[count]=MinesCalc(x[count],y[count],mines,n);
	if(nmines[count]==0){
	surrounding(x,y,pcount,nmines,nummines);
	count++;
}
else{
	count++;
	wincount++;
}
test = compare(x,y,mines,count,n); 
if(test==1){
	goto lose;
}
	if((wincount+1)==64-n+1){
		win:
		time(&etime);
		ttaken=etime-stime;
		system("cls");
		printf("\a");
		sleep(1);
		printpattern();
		printsquare(x,y,nmines,count);
		printmines(mines,n);
		setxy(55,2);
		printf("You Win!!!!!!!\n");
		if(ttaken<60){
			printf("Your time taken = %d seconds\n", ttaken);
		}else{
		printf("Your time taken = %.2f minutes\n", (float)ttaken/(float)60);
	    }
		getscore(ttaken,lev);
		printf("Press any key to go to main menu...\n");
		getch();
		goto mstart;
	}
	system("cls");
	test = compare(x,y,mines,count,n);
		if(test==1)
	{
		lose:
		system("cls");
		printf("\a");
		sleep(1);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\tGAME OVER!!!!\nOOPS!!!YOU STEPPED ON A MINE!!!!\n");
		printf("Press any key to go to main menu...\n");
		printpattern();
		printsquare(x,y,nmines,count);
		printmines(mines,n);
		getch();
		goto mstart;
	}else
	{
		goto start;
	}
	
	printf("Press any key to continue.\n");
	getch();
	return 0;
}

void setxy (int x, int y){
 COORD c = {0, 0};
 c.X = x; c.Y = y; 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void printpattern(){
	int i,j;
	for(i=0;i<28;i++){
		setxy(60,7+i);
		if(i%3==1){
			printf("_");
		}
		else if(i%3==2){
			printf(" ");
		}
		else{
		if(i!=0 && i!=27){
			printf("%d", i/3);
		   }
	    }
		for(j=0;j<28;j++){
			if(j%3==1){
				printf("| ");
			}
			else if(j%3==2){
				if(i%3!=1){
					printf(" ");
				}else{
				printf("_");
			    }
			}
			else{
			if(i==0 || i==27){
				if(j!=27){
				printf("%d ", j/3);
			    }else{
			      printf("0");
				}
			}
			else if(j==27){
				   if(i%3==1){
				   	printf("_");
				   }
				   else if(i%3==2){
				   	printf(" ");
				   }
				   else{
			      printf("%d", i/3);
	              }
	          }
			else if (j!=0){
				printf("  ");
			}
			else{
				printf(" ");
			}
		}
	}
		printf("\n");
	}
}

void fontcolor(int n){
	switch(n){
		case 1 : system("color 02");
		         break;
		case 2 : system("color 03");
		         break;
		case 3 : system("color 06");
		         break;
		case 4 : system("color 05");
		         break;
		case 5 : system("color F");
		         break;
	    default : printf("Enter number from 1-5\n");
	              break;
	}
}

int colormenu(){
	int color;
		cstart:
	printf("Enter the font color:\n1.Green\n2.Blue\n3.Yellow\n4.Thanos color\n5.White\n(Enter only 1,2,3 or 5.)\n");
	fflush(stdin);
	scanf("%d", &color);
	if(color>5 || color==0){
		printf("Enter number from 1-5\n");
		goto cstart;
	}
	system("cls");
	return color;
}

void MinesGenerator(int x[120],int y[120],int mines[7][2],int n)
{
  	int i,j,temp[9][9],bcount;
  		startgen:
  		bcount=0;
  	for(i=0;i<9;i++){
  		for(j=0;j<9;j++){
  			temp[i][j]=0;
		  }
	  }
  		srand(time(0));
  		for(i=0;i<n;i++)
	{
		
		for(j=0;j<2;j++)
		{
			mines[i][j]=(rand()%8+1);
		}
		if(x[0]==mines[i][0]&&y[0]==mines[i][1])
		{
			bcount++;
			break;
		}	
	}
	if(bcount>0){
	  	goto startgen;
	  }
	for(i=0;i<n;i++){
		temp[mines[i][0]][mines[i][1]]++;
	}
	for(i=1;i<9;i++){
  		for(j=1;j<9;j++){
  			if(temp[i][j]>1){
  				bcount++;
  				break;
			  }
		  }
	  }
	  if(bcount>0){
	  	goto startgen;
	  }
}

int compare(int x[57],int y[57],int mines[7][2], int count,int n)
{
	int i,j,flag=0;
	 
    for(j=0;j<count;j++){
	for(i=0;i<n;i++)
	{
	    if(x[j]==mines[i][0]&&y[j]==mines[i][1])
			{   flag++;
				break;
			}else{
			
			}
	
	}
  }
	
	return flag;
}

void menu()
{
	int choice,c=219,e=61,i,j;
	for(i=0;i<5;i++)
	{
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		printf("\t");
	}
	for(i=0;i<33;i++)
	{
		printf("%c",c);
	}
	
	printf("\n") ;
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
	printf("\t\t\t%c\t%c%c%c%c1. New Game\t\t%c\n",c,c,c,c,c,c);
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
	printf("\t\t\t%c\t%c%c%c%c2. Instructions\t%c\n",c,c,c,c,c);
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
	printf("\t\t\t%c\t%c%c%c%c3. High Score\t%c\n",c,c,c,c,c,c);
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
	printf("\t\t\t%c\t%c%c%c%c4. Change Color\t%c\n",c,c,c,c,c,c);
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
	printf("\t\t\t%c\t%c%c%c%c5. Exit\t\t%c\n",c,c,c,c,c,c);
	printf("\t\t\t%c\t\t\t\t%c\n",c,c);
		for(i=0;i<3;i++)
	{
		printf("\t");
	}
	for(i=0;i<33;i++)
	{
		printf("%c",c);
	}
}

void gmenu(int n){
	int ne;
	  switch(n){
	  	case 1 : break;
	  	case 2 : instructions();
	  	         break;
	  	case 3 : system("cls");
	  	         str:
	             printf("Difficulty:\n1.Easy\n2.Normal\n3.Hard\n");
	             scanf("%d", &ne);
	             if(ne==0||ne>3){
	             	goto str;
				 }
		         displayscore(ne);
	  	         system("cls");
	  	         displayscore(ne);
	  	         getch();
	  	         break;
	  	case 4 : break;
	  	case 5 : exit(1);
	  	         break;
	  	default : printf("Enter 1-4\n");
	  	          break;
	}
}
void instructions()
{
	system("cls");
	printf("Detailed Instructions:\n1.A squares neighbours are the squares adjacent above, below, left, right, and all 4 diagonals. \nSquares on the sides of the board or in a corner have fewer neighbors. The board does not wrap around the edges.");	
	printf("\n\n2.Enter Coordinates to open the respective squares.");
	printf("If the number of surrounding mines = 0(only for entered Coordinates), then the surrounding squares will open automatically.\n");
	printf("\n\n3.The first square you open is never a bomb.\n\n");
	printf("4.The number which is printed shows the number of mines in its adjacent squares .\n\n");
	printf("5.There are 64 squares out of which 7 are mines.\n\n");
	printf("6.You just need to open all non-bomb squares to win.\n\n");
	printf("Press any key to continue.\n");
	getch();
		
}
int MinesCalc(int x,int y,int a[7][2],int n)
{
	int i,j,flag=0;
	for(i=0;i<n;i++)
	{
	  if(x-1==a[i][0]&&y+1==a[i][1])
	  {
	  	flag++;
	  }
	  if(x==a[i][0]&&y+1==a[i][1])
	  {
	  	flag++;
	  }
	  if(x+1==a[i][0]&&y+1==a[i][1])
	  {
	  	flag++;
	  }
	  if(x-1==a[i][0]&&y==a[i][1])
	  {
	  	flag++;
	  }
	  if(x+1==a[i][0]&&y==a[i][1])
	  {
	  	flag++;
	  }
	  if(x-1==a[i][0]&&y-1==a[i][1])
	  {
	  	flag++;
	  }
	  if(x==a[i][0]&&y-1==a[i][1])
	  {
	  	flag++;
	  }
	  if(x+1==a[i][0]&&y-1==a[i][1])
	  {
	  	flag++;
	  }
	}
	return flag;
}
void loading()
{
	int i,j;
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWelcome to MineSweeper!!\n");
    sleep(2);
	for(i=0;i<100;i++)
	{
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tloading...%d %%\n",i);
		printf("\t");
		for(j=0;j<i;j++)
		{
			printf(")");
		}
		system("cls");
	}
	
}
void printsquare(int x[120], int y[120], int nmines[120], int count){
	int i;
	setxy(65,10);
	for(i=0;i<count;i++){
		setxy(60+x[i]*5,7+y[i]*3);
		printf("%d", nmines[i]);
	}
}
void printmines(int mines[7][2],int n){
	int i;
	setxy(65,10);
	for(i=0;i<n;i++){
		setxy(60+mines[i][0]*5,7+mines[i][1]*3);
		printf("M");
	}
}
void getscore(int ttaken,int lev){
	struct score
	{
	   int time;
	   char name[40];	
	};
	struct score user;
	printf("Enter your name: \n");
	fflush(stdin);
	gets(user.name);
	user.time=ttaken;
	FILE *fp;
    if(lev==1){
	fp=fopen("scorese.txt","a");
	fprintf(fp,"\n%.2f  minutes- %s", (float)user.time/60,user.name);
    }
    if(lev==2){
	fp=fopen("scoresn.txt","a");
	fprintf(fp,"\n%.2f  minutes- %s", (float)user.time/60,user.name);
    }
    if(lev==3){
	fp=fopen("scoresh.txt","a");
	fprintf(fp,"\n%.2f  minutes- %s", (float)user.time/60,user.name);
    }
	fclose(fp);
}
void displayscore(int n){
	system("cls");
	int i=0,j,k,l;
	FILE *fp;
	if(n==1){
		fp=fopen("scorese.txt","r");
	}
	else if(n==2){
		fp=fopen("scoresn.txt","r");
	}
	else if(n==3){
		fp=fopen("scoresh.txt","r");
	}
	if(fp==NULL){
		printf("No record found.");
	}
	else{
	char singleline[100][150];
	char swap;
	while(!feof(fp)){
		fgets(singleline[i], 150, fp);
		i++;
	}
	fclose(fp);
		for(j=0;j<i;j++)
	{
   	  for(l=0;l<i;l++)
		{
   	  	  if(strncmp(singleline[l],singleline[l+1],3)>0)
			   {
   	  	  	    for(k=0;k<150;k++)
				{
	   	  	  	    swap = singleline[l][k];
	   	  	  	    singleline[l][k]=singleline[l+1][k];
	   	  	  	    singleline[l+1][k]=swap;
				}
		    }
				else{
				}
			}
		 }
   for(k=1;k<i;k++){
   	  
      printf("%s\n", singleline[k]);	
}
}
}

void freenum(int wincount,int n){
	setxy(120,10);
	printf("Free squares = %d", 64-n-wincount);
	setxy(120,12);
	printf("Mines = %d",n);
	setxy(120,14);
	printf("Enter 66 in x or y to leave the game and go back to main menu.");
}

void nommines(int nummines[9][9],int mines[7][2],int n){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			nummines[i][j]=MinesCalc(i,j,mines,n);
		}
	}
}

void surrounding(int x[120],int y[120],int *pcount,int nmines[120],int nummines[9][9]){
	int ncnt=0;
	    if((x[*pcount]-1)!=0 && (y[*pcount]-1)!=0 && (x[*pcount]-1)<9 && (y[*pcount]-1)<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount]-1][y[*pcount]-1];
		x[*pcount+1]=(x[*pcount]-1);
		y[*pcount+1]=(y[*pcount]-1);
		*pcount=*pcount+1;
		ncnt++;
	}
	if((x[*pcount-ncnt])!=0 && (y[*pcount-ncnt]-1)!=0 && (x[*pcount-ncnt])<9 && (y[*pcount-ncnt]-1)<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]][y[*pcount-ncnt]-1];
		x[*pcount+1]=(x[*pcount-ncnt]);
		y[*pcount+1]=(y[*pcount-ncnt]-1);
		*pcount=*pcount+1;
		ncnt++;
	}
    if((x[*pcount-ncnt]+1)!=0 && (y[*pcount-ncnt]-1)!=0 && (x[*pcount-ncnt]+1)<9 && (y[*pcount-ncnt]-1)<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]+1][y[*pcount-ncnt]-1];
		x[*pcount+1]=(x[*pcount-ncnt]+1);
		y[*pcount+1]=(y[*pcount-ncnt]-1);
		*pcount=*pcount+1;
		ncnt++;
	}
	if((x[*pcount-ncnt]-1)!=0 && (y[*pcount-ncnt])!=0 && (x[*pcount-ncnt]-1)<9 && (y[*pcount-ncnt])<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]-1][y[*pcount-ncnt]];
		x[*pcount+1]=(x[*pcount-ncnt]-1);
		y[*pcount+1]=(y[*pcount-ncnt]);
		*pcount=*pcount+1;
		ncnt++;
	}
	if((x[*pcount-ncnt]+1)!=0 && (y[*pcount-ncnt])!=0 && (x[*pcount-ncnt]+1)<9 && (y[*pcount-ncnt])<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]+1][y[*pcount-ncnt]];
		x[*pcount+1]=(x[*pcount-ncnt]+1);
		y[*pcount+1]=(y[*pcount-ncnt]);
		*pcount=*pcount+1;
		ncnt++;
	}
	if((x[*pcount-ncnt]-1)!=0 && (y[*pcount-ncnt]+1)!=0 && (x[*pcount-ncnt]-1)<9 && (y[*pcount-ncnt]+1)<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]-1][y[*pcount-ncnt]+1];
		x[*pcount+1]=(x[*pcount-ncnt]-1);
		y[*pcount+1]=(y[*pcount-ncnt]+1);
		*pcount=*pcount+1;
		ncnt++;
	}
	if((x[*pcount]-ncnt)!=0 && (y[*pcount-ncnt]+1)!=0 && (x[*pcount]-ncnt)<9 && (y[*pcount-ncnt]+1)<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]][y[*pcount-ncnt]+1];
		x[*pcount+1]=(x[*pcount-ncnt]);
		y[*pcount+1]=(y[*pcount-ncnt]+1);
		*pcount=*pcount+1;
		ncnt++;
	}
	if((x[*pcount-ncnt]+1)!=0 && (y[*pcount-ncnt]+1)!=0 && (x[*pcount-ncnt]+1)<9 && (y[*pcount-ncnt]+1)<9)
	{
		nmines[*pcount+1]=nummines[x[*pcount-ncnt]+1][y[*pcount-ncnt]+1];
		x[*pcount+1]=(x[*pcount-ncnt]+1);
		y[*pcount+1]=(y[*pcount-ncnt]+1);
		*pcount=*pcount+1;
		ncnt++;
	}
}
void checkwincount(int x[120], int y[120], int *pwincount){
	int hashing[9][9];
	int i,j,repflag=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			hashing[i][j]=0;
		}
	}
	for(i=0;i<120;i++){
		hashing[x[i]][y[i]]++;
	}
	for(i=1;i<9;i++){
		for(j=1;j<9;j++){
			if(hashing[i][j]>0){
				repflag+=1;
			}
		}
	}
	*pwincount=repflag;
}
void levscreen(){
	system("cls");
	printf("Choose the difficulty level:\n");
	printf("1. Easy\n");
	printf("2. Normal\n");
	printf("3. Hard\n");
}
