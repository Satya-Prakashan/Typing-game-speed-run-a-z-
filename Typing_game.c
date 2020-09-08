#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>

//.......................................................................................................................................................................
 COORD coord={0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//.......................................................................................................................................................................
//.............................................................................................................................................................................
void setcolor(int ForgC) //function to change setcolor
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }

//.................................................................................................................................................................................
void sett();//sets time limit for playing game
int t=30;

char name[15];
void getscore(int score,int speed,int level);
void startgame();  //to start the game
void scorecard();  //to update high score
void About_me();
void help();

//................................................................................................................................................................................
//			main function
int main()
{       int ch;
	system("color F2");
	time_t t;
	time(&t);
	system("cls");gotoxy(33,1);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,2);
			printf("|  Welcome to a-z Speed Typing Game  |\n");gotoxy(33,3);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,4);
			printf(" %s                                  ",ctime(&t));gotoxy(33,5);
			printf("|                                    |\n");gotoxy(33,6);
			printf("|  ENTER YOUR NAME                   |\n");gotoxy(33,7);
			printf("|                                    |\n");gotoxy(33,8);
			printf("|                                    |\n");gotoxy(33,9);
			printf("|                                    |\n");gotoxy(33,10);
			printf("|                                    |\n");gotoxy(33,11);
			printf("|                                    |\n");gotoxy(33,12);
			printf("|                                    |\n");gotoxy(33,13);
			printf("|                                    |\n");gotoxy(33,14);
			printf("|                                    |\n");gotoxy(33,15);
			printf("|                                    |\n");gotoxy(33,16);
			printf("|                                    |\n");gotoxy(33,17);
			printf("|                                    |\n");gotoxy(33,18);
			printf("|                                    |\n");gotoxy(33,19);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,20);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,21);
		printf("|         This Small Game developed by @SP          |\n");gotoxy(25,22);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		gotoxy(54,6);
		gets(name);
		
		gotoxy(36,8);
		printf("       Main Menu");
		gotoxy(37,10);
		printf("1. Start the Game");
		gotoxy(37,11);
		printf("2. Scorecard");
		 gotoxy(37,12);
		printf("3. Set the time limit");
		 gotoxy(37,13);
		printf("4. Help");
		 gotoxy(37,14);
		printf("5. About me");
		 gotoxy(37,15);
		printf("0. Exit");
		 gotoxy(37,17);
		printf("Select the Any Option ");
		scanf("%d",&ch);
		switch(ch)
		{       case 1:startgame();break;
			case 2:scorecard();break;
			case 3:sett();main();
			case 4:help();break;
			case 5:About_me();break;
			case 0:system("cls");gotoxy(17,10);exit(1);
			default:main();
		}

getch();
}
//.....................end of main function.................................

			   //startgame
//..........................................................................
void startgame()
{       
char alphabets[26]="abcdefghijklmnopqrstuvwxyz";
time_t t;
	time(&t);
int score=0,level=1,mode=100,count=0,i=-1,index=39;
	clock_t begin;int time_spent,speed;
char r;
	int letter,ch;
	system("cls");
	srand(time(NULL)) ; //initilizes random function and seed with time
	if(level==1)
	{
	 begin=clock();
		while(1&&i<26)			// infinity loop
		{
		 system("cls");
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

			if(time_spent>=t)
			break;
			i++;
			if(i==26)
			{
				break;
			}
			r=alphabets[i];
			gotoxy(33,1);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,2);
			printf("|....Type a-z as fast as you can!....|\n");gotoxy(33,3);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,4);
			printf(" %s                                  ",ctime(&t));gotoxy(33,5);
			printf("|                                    |\n");gotoxy(33,6);
			printf("| Time spent                sec      |\n");gotoxy(33,7);
			printf("| Score                     lpm      |\n");gotoxy(33,8);
			printf("|                                    |\n");gotoxy(33,9);
			printf("|     abcdefghijklmnopqrstuvwxyz     |\n");gotoxy(33,10);
			printf("|                     ++++++++++     |\n");gotoxy(33,11);
			printf("| Current letter      |        |     |\n");gotoxy(33,12);
			printf("|                     ++++++++++     |\n");gotoxy(33,13);
			printf("|                                    |\n");gotoxy(33,14);
			printf("|                                    |\n");gotoxy(33,15);
			printf("|                                    |\n");gotoxy(33,16);
			printf("|                                    |\n");gotoxy(33,17);
			printf("|                                    |\n");gotoxy(33,18);
			printf("|                                    |\n");gotoxy(33,19);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,20);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,21);
		printf("|          This Small Game developed by @SP         |\n");gotoxy(25,22);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			gotoxy(58,11);
			printf(" %c",r); 
			gotoxy(index,9);
			letter=getch();
			index++;
			if(letter!=r)
			{	
			break;
			}
			else
			{       count++;
				score=score+10;
				gotoxy(58,7);
				printf("%d",score);//prints score
				gotoxy(58,6);
				printf("%d",time_spent);	//prints time spent during game
			}
		}
			gotoxy(33,1);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,2);
			printf("|............Game Over!!!!...........|\n");gotoxy(33,3);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,4);
			printf(" %s                                  ",ctime(&t));gotoxy(33,5);
			printf("|                                    |\n");gotoxy(33,6);
			printf("|                                    |\n");gotoxy(33,7);
			printf("|                                    |\n");gotoxy(33,8);
			printf("|                                    |\n");gotoxy(33,9);
			printf("|                                    |\n");gotoxy(33,10);
			printf("|                                    |\n");gotoxy(33,11);
			printf("|                                    |\n");gotoxy(33,12);
			printf("|                                    |\n");gotoxy(33,13);
			printf("|                                    |\n");gotoxy(33,14);
			printf("|                                    |\n");gotoxy(33,15);
			printf("|                                    |\n");gotoxy(33,16);
			printf("|                                    |\n");gotoxy(33,17);
			printf("|                                    |\n");gotoxy(33,18);
			printf("|                                    |\n");gotoxy(33,19);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,20);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,21);
		printf("|          This Small Game developed by @SP         |\n");gotoxy(25,22);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		speed=(count)/time_spent;
		if(time_spent<t-1&&i<26)
		{
			gotoxy(35,7);
		printf("You loose! Try again");gotoxy(35,8);
		printf("Time spent : %d seconds",time_spent);
	}
		else
		{
			gotoxy(40,7);
		printf("Congratulations You Won!");gotoxy(35,8);
		printf("Time spent : %d seconds",time_spent);
			if((time_spent>=20)&&(time_spent<=40))
			{	gotoxy(48,6);
			printf("Well done.!!");
			}
			else if((time_spent>=5)&&(time_spent<=20))
			{
			gotoxy(48,6);
			printf("Fantastic!!!");	
			}
			else if((time_spent>=0)&&(time_spent<=5))
			{
				gotoxy(35,6);
				printf("You are Exception like 'H'");
			}
		}
		gotoxy(35,9);
		printf("Total score : %d",score);
		gotoxy(35,10);
		printf("Net speed : %d letter per second",speed);
		getscore(score,speed,level);		//saves data to file
		gotoxy(35,13);
		printf("1. Play Again");gotoxy(35,14);
		printf("2. Main Menu");gotoxy(35,15);
		printf("3. Exit");gotoxy(35,17);
		printf("Select the Any Option ");gotoxy(59,17);
		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:startgame();break;    //recursive call
		      case 2:main();break;
		      case 3:gotoxy(17,10);system("cls");exit(1);break;
		      default:printf("Wrong Choice!");
				main();
		}
	}
	else
	{	gotoxy(37,17);
		printf("Enter the Correct Option");
		getch();
		startgame();
	}

}
//......................end of start game function..........................


//...........................sett function starts..........................
void sett()  //set time limit
{
	int ch;
	system("cls");
	setcolor(11);
	time_t t;
	time(&t);
	printf("Set the time limit for game in minute::");
	gotoxy(33,1);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,2);
			printf("|.........Set the time limit.........|\n");gotoxy(33,3);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,4);
			printf(" %s                                  ",ctime(&t));gotoxy(33,5);
			printf("|                                    |\n");gotoxy(33,6);
			printf("|                                    |\n");gotoxy(33,7);
			printf("|      Enter 0 for 40 seconds        |\n");gotoxy(33,8);
			printf("|      Enter 1 for 20 seconds        |\n");gotoxy(33,9);
			printf("|      Enter 2 for 05 seconds        |\n");gotoxy(33,10);
			printf("|                                    |\n");gotoxy(33,11);
			printf("|                                    |\n");gotoxy(33,12);
			printf("|   Select Any Option                |\n");gotoxy(33,13);
			printf("|                                    |\n");gotoxy(33,14);
			printf("|                                    |\n");gotoxy(33,15);
			printf("|                                    |\n");gotoxy(33,16);
			printf("|                                    |\n");gotoxy(33,17);
			printf("|                                    |\n");gotoxy(33,18);
			printf("|                                    |\n");gotoxy(33,19);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,20);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,21);
		printf("|         This Small Game developed by @SP          |\n");gotoxy(25,22);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	 gotoxy(56,12);
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=40;break;
		case 1:t=20;break;
		case 2:t=5;break;
		default:main();
	}
}
//....................sett function ends....................................

//........................................................................
void help()
{
	system("cls");
	time_t t;
	time(&t);
	gotoxy(7,5);
	setcolor(6);
	gotoxy(33,1);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,2);
			printf("|................HELP................|\n");gotoxy(33,3);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,4);
			printf(" %s                                  ",ctime(&t));gotoxy(33,5);
			printf("|                                    |\n");gotoxy(33,6);
			printf("|        How This Game Works!        |\n");gotoxy(33,7);
			printf("|  Enter your name as player name    |\n");gotoxy(33,8);
			printf("|                                    |\n");gotoxy(33,9);
			printf("| Set the time limit under option 3  |\n");gotoxy(33,10);
			printf("|           in main menu             |\n");gotoxy(33,11);
			printf("|     (default limit is 30 sec)      |\n");gotoxy(33,12);
			printf("|                                    |\n");gotoxy(33,13);
			printf("|  This Game is Simple just type     |\n");gotoxy(33,14);
			printf("|   a-z as fast as you can!!         |\n");gotoxy(33,15);
			printf("|                                    |\n");gotoxy(33,16);
			printf("|     Avoid incorrect typing         |\n");gotoxy(33,17);
			printf("|   Otherwise game will be over..    |\n");gotoxy(33,18);
			printf("|                                    |\n");gotoxy(33,19);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,20);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,21);
		printf("|           This Small Game developed by @SP        |\n");gotoxy(25,22);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	getch();main();
}
void About_me()
{       system("cls");
    time_t t;
	time(&t);
			gotoxy(33,1);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,2);
			printf("|............About Me!!!!...........|\n");gotoxy(33,3);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(33,4);
			printf(" %s                                  ",ctime(&t));gotoxy(33,5);
			printf("|                                    |\n");gotoxy(33,6);
			printf("|          Hello everyone            |\n");gotoxy(33,7);
			printf("|         I'm a programmer.          |\n");gotoxy(33,8);
			printf("|  I really enjoy solving problems   |\n");gotoxy(33,9);
			printf("| as well as making things pretty    |\n");gotoxy(33,10);
			printf("|          and easy to use.          |\n");gotoxy(33,11);
			printf("|                                    |\n");gotoxy(33,12);
			printf("|                                    |\n");gotoxy(33,13);
			printf("|    For more such application       |\n");gotoxy(33,14);
			printf("|    Please follow this Website      |\n");gotoxy(33,15);
			printf("|       www.spyronation.com          |\n");gotoxy(33,16);
			printf("|                                    |\n");gotoxy(33,17);
			printf("|                                    |\n");gotoxy(33,18);
			printf("|                                    |\n");gotoxy(33,19);
			printf("++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,20);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(25,21);
		printf("|    This Small Game developed by @SATYA PRAKASH    |\n");gotoxy(25,22);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
       getch();
       main();
}
//.........................................................................
void getscore(int score,int speed,int level)
{
	FILE *fp;
	fp=fopen("file.txt","a");
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\t\t     %s\t\t%d\t\t%d\t\t%d\n",name,score,speed,level);
	fclose(fp);
	gotoxy(35,11);
	printf("Scorecard Updated");
}
void scorecard()
{       int ch;
	FILE *fp;
	system("cls");

gotoxy(21,1);
printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(21,2);
printf("|.............................Scorecard!!!!............................|\n");gotoxy(21,3);
printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");gotoxy(21,4);
printf("\tNames\t\tScore\t\tSpeed\t\tLevel\n");
	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	printf("%c",ch);
	}
	getch();
	main();
}
