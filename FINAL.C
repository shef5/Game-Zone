#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<graphics.h>
int amount=0;
struct node
{
char name[20];
struct node *right;
struct node *down;
}*start,*ptr;

struct abc
{
    int score;
    int bet;
    struct abc *next;
}*ptrabc,*startabc;


struct nodesps
{ int a;
  int b;
  struct node *next;
}*startsps,*ptrsps;

void initilze()
{
FILE *fp;
int i,j;
char word[20],aux[200];
fp=fopen("W_G_DATA.txt","r");
randomize();
if(fp==NULL)
{
printf("cant open file");
getch();
return;
}
i=random(5);
for(j=0;j<i;j++)
fgets(aux,200,fp);
ptr=start=(struct node *)malloc(sizeof(struct node));
fscanf(fp,"%s ",word);
//printf("\t%s",word);
strcpy(start->name,word);
fscanf(fp,"%s ",word);
while(strcmp(word,"E_N_D"))
{
ptr->right=(struct node *)malloc(sizeof(struct node));
ptr=ptr->right;
fscanf(fp,"%s ",word);
strcpy(ptr->name,word);
//printf("\t%s",word);
}
ptr->right=NULL;
}

int check(char test[],int t,char ans[][20])
{
int j;
ptr=start->right;
while(ptr!=NULL)
{
  if(!stricmp(test,ptr->name))
  {
  for(j=0;j<t;j++)
     {
	if(!stricmp(test,ans[j]))
	{
	textcolor(YELLOW);
	cprintf("repeated\n");
	return 0;
	}
      }
      textcolor(5);
  cprintf("correct\n");
  return (strlen(test));
  }
ptr=ptr->right;
}
textcolor(RED);
cprintf("wrong\n");
return 0;
}

Word_find()
{
clock_t startc,endc;
int t=0,marks=0,m;
char test[20],ans[20][20];
clrscr();
initilze();
startc=clock();
printf("\t----WELCOME----\n\t**WORD FINDER**\nmake relevant words with this alphabets %s\t",start->name);
printf("\n you have only 30 secs \n\t");
while(1)
{
endc=clock();

if((endc-startc)/CLK_TCK>30)
break;

scanf("%s",test);
    if(m=check(test,t,ans))
    { marks+=m;
    strcpy(ans[t++],test);
     }
}

textcolor(BLUE+BLINK);
cprintf("\n\n Marks are %d",marks);
getch();
}

Tic()
{
    int i;
    int player = 0;
    int winner = 0;
    int choice = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    char board [3][3] = {
		 {'1','2','3'},
		{'4','5','6'},
		 {'7','8','9'}
			};

	clrscr();
	textbackground(RED);
	textcolor(GREEN);
	textmode(C40);
	gotoxy(14,1);
	cprintf("TIC");
	delay(700);
	gotoxy(18,1);
	cprintf("TAC");
	delay(1000);

    for (i = 0; i<9 && winner==0; i++)
    {
	clrscr();

	//textcolor(3);
	textmode(C40);
	textbackground(BLUE);
	printf("\n\n");
	cprintf(" %c Û %c Û %c", board[0][0], board[0][1], board[0][2]);
	printf("\n");
	cprintf("ÜÜÜÛÜÜÜÛÜÜ");
	printf("\n");

	cprintf(" %c Û %c Û %c", board[1][0], board[1][1], board[1][2]);
	printf("\n");
	cprintf("ÜÜÜÛÜÜÜÛÜÜ");
	printf("\n");
	cprintf(" %c Û %c Û %c", board[2][0], board[2][1], board[2][2]);
	printf("\n");
	player = i%2 + 1;
	do
	{
	    printf("\nPlayer %d, please enter the number of the square "
		"where you want to place your %c: ",
		player,(player==1)?'X':'O');
	 scanf("%d", &choice);
	    row = --choice/3;
	    column = choice%3;
	}while(choice<0 || choice>9 || board [row][column]>'9');
	board[row][column] = (player == 1) ? 'X' : 'O';

	if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
	   (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
	   winner = player;

	else

	    for(line = 0; line <=2; line++)
		if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
		    (board[0][line]==board[1][line] && board[0][line]==board[2][line]))
		    winner = player;


    }
	 textcolor(GREEN+BLINK);

	printf("\n\n");
	cprintf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("\n") ;
	cprintf("---|---|---\n");
	printf("\n") ;
	cprintf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("\n") ;
	cprintf("---|---|---\n");
	printf("\n") ;
	cprintf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
	printf("\n") ;
	textcolor(RED+BLINK);
	if(winner==0)
	    cprintf("The game is a draw");
	else
	    cprintf("Player %d has won", winner);
      getch();
    return 0;
}


int cal(int a,int p,int s)
{

int sum=0;
	 switch(a)
	    {
		case 1:if((p>(s+20))&&(p<(s+40)))
		{
		    amount=amount+(ptrabc->bet*3);
		}
		else
		{
		    amount=amount-(ptrabc->bet);
		}
		break;

		    case 2:if(p>s+40)
		{
		    amount=amount+(ptrabc->bet*3);
		}
		else
		{
		    amount=amount-(ptrabc->bet);
		}
		break;
		case 3:
		    if(p<s+20)
		{
		    amount=amount+(ptrabc->bet*3);
		}
		else
		{
		    amount=amount-(ptrabc->bet);
		}
		break;
	    }
	    return(sum=sum+amount);
		}
Cricket()
{

  //  system(cls);
    int ch,s,a,p,i=0;
    static int amount;
    char b;
    int gd=DETECT,gm,x=50,y=50,font=0;
    initgraph(&gd,&gm," ");
     startabc=(struct abc*)malloc(sizeof(struct abc));
	 ptrabc=startabc;
    settextstyle(font,HORIZ_DIR,2);
    outtextxy(x,y,"\t\t\tWELCOME TO THE CRICKET GAMBLE");
   delay(1000);

    printf("\n\n ******************************************************************************");
    printf("\n\n\n ****************************************************************************");
    delay(1000);
    while(ch!=4)
    {

    clrscr();
    textmode(C40);
    printf("\n\n\n\n\n\n\t\tENTER YOUR CHOICE");
    printf("\n\n\n \t\t1.place new beat");
    printf("\n\t\t2.previous record");
    printf("\n\t\t3.total money earned");
    printf("\n\t\t4.exit");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
	{
	    do
	    {
		 clrscr();
		 textmode(C40);
	       printf("\t\tPLACING YOUR BEAT");

	    srand(time(NULL));
	    s=(rand()%(200-1))+1;

	    printf("\t\t\t\t\t\n\n\n\n\SCORE IS %d\n",s);
	    printf("\n\nwhat will be the range of score after this over");
	    printf("\n more den %d:  press 1",s+20);
	    printf("\n more den %d:  press 2",s+40);
	    printf("\n less den %d:  press 3",s+20);
	    scanf("%d",&a);
	    clrscr();
	    textmode(C40);
	    printf("enter d amount you want to bet");

	    fflush(stdin);
	    scanf("%d",&ptrabc->bet);

	    srand(time(NULL));
	    p=(rand()%(250-s))+s;
	    clrscr();
	    printf("\t\t\t\t\n\n\nTHE SCORE NOW IS: %d",p);
	       amount=cal(a,p,s);
	       printf("\n\n\nyour total amount is %d",amount);
	       printf("\n\n\n\t\t wana bet more");
	       fflush(stdin);
	       scanf("%c",&b);
	       if(b=='y')
	       {
		   ptrabc->next=(struct abc*)malloc(sizeof(struct abc));
		   ptrabc=ptrabc->next;
	       }
	    }while(b=='y');
	    ptrabc->next=NULL;

	}
	break;
    case 2:
	{
	  clrscr();
	  textmode(C40);
	    printf("\t\tYOUR LAST BEAT WERE.......");
	    ptrabc=startabc;
	    while(ptrabc!=NULL)
	    {
	    i++;
	    printf("\n\namount you beated in beat %d was %d\n" ,i,ptrabc->bet);
	    ptrabc=ptrabc->next;
	}
getch();
    }
    break;
    case 3:
    clrscr();
    textmode(C40);
	printf("\t\t\t\t\n\n\n\n\n\nYOUR TOTAL AMOUNT IS %d",amount);
	getch();
	break;
	case 4:
     //	 	clrscr();
	 //      textcolor(RED);
	 printf("\n\n\n\nexiting the game");

	}
	}

	}



void inlize(struct nodesps *ptrsps)
{
   ptrsps->a=1;
   ptrsps->b=0;

   ptrsps->next=(struct nodesps *)malloc(sizeof(struct nodesps));
   ptrsps=ptrsps->next;

   ptrsps->a=0;
   ptrsps->b=2;

   ptrsps->next=(struct nodesps *)malloc(sizeof(struct nodesps));
   ptrsps=ptrsps->next;

   ptrsps->a=2;
   ptrsps->b=1;

   ptrsps->next=NULL;
}


SPS()
{ char ch;
  int i,j,f,y,computer,player,x;
  clrscr();

   textcolor(BLUE);
  cprintf("\t\tROCK , PAPER  AND  SCISSORS");
  printf("\n\n\n This game is a 3 point game");


  startsps=(struct nodesps *)malloc(sizeof(struct nodesps));

  inlize(start);

  do
  { x=0;
    i=0;
    j=0;
    while(x==0)
    {  f=0;
       y=0;

       computer=random(3);

       printf("\n\n\n enter your choice : rock=0 , paper=1 , scissors=2\n");
       scanf("%d",&player);
       ptrsps=startsps;

       while(ptr!=NULL)
       {
	 if(player==computer)
	  {
	    printf("\n game tie");
	    f=2;
	    break;
	  }
	 else
	 {
	   if(ptrsps->a==player && ptrsps->b==computer)
	    {
	      printf("\n you won");
	      f=1;
	      i=i+1;
	      break;
	    }
	 }
	  ptrsps=ptrsps->next;

       }

       if((f==0) && (player>=0 && player<=2))
       {
	  printf("\n you loss");
	  j=j+1;

       }

      switch(player)
      {
	case 0 : printf("\nPlayer = ROCK");
		 break;

	case 1 : printf("\nPlayer = PAPER");
		 break;

	case 2 : printf("\nPlayer = SCISSORS");
		 break;

	default : printf("\nWRONG CHOICE ");
		  y=1;

      }

      if(y==0)
      {
	switch(computer)
	{
	   case 0 : printf("\nComputer = ROCK");
		    break;

	   case 1 : printf("\nComputer = PAPER");
		    break;

	   case 2 : printf("\nComputer = SCISSORS");
		    break;

	}
      }

	 printf("\nplayer points = %d  computer points = %d",i,j);


      if(i==3)
       {
	 printf("\n YOU WON THE GAME");
	 x=1;
       }

      else
       { if(j==3)
	 {
	 textcolor(BLUE);
	   cprintf("\n YOU LOSS THE GAME");
	   x=1;
	 }
       }
    }
      printf("\n do you want to play again");
      fflush(stdin);
      scanf("%c",&ch);

 }while(ch=='y' || ch=='Y');
return 0;

}




void main()
{
int choice;
char c='y';
clrscr();
while(c=='y')
{
//textmode(BW80);
textcolor(3+BLINK);
cprintf("\n\n\nWelcome To Game Zone");
textcolor(YELLOW);
cprintf("\n\nTic Tac press 1");
cprintf("\n\nWord Finder press 2");
cprintf("\n\nStone Paper Scisor press 3");
cprintf("\n\nCricket Gamble press 4 ");



scanf("%d",&choice);
switch(choice)
{
case 1: Tic();break;
case 2: Word_find();break;
case 3: SPS();break;
case 4: Cricket();break;
default:main();
}
textmode(C40);
textcolor(RED);
clrscr();
cprintf("\n\n\nDo you want to play more games ");
fflush(stdin);
scanf("%c",&c);
clrscr();
}
getch();
}
