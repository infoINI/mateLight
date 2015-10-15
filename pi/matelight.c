#include <wiringPi.h>
#include <wiringShift.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "charmaps.h"

#define ROW_CLK 2
#define ROW_CLR 1
#define ROW_DAT 0
#define COL_CLK 14
#define COL_CLR 13
#define R_DAT 8
#define G_DAT 9
#define B_DAT 7

void draw(int col, int row, int holdtime, int color);
void drawMulti(int col, int row, int holdtime, int r, int g, int b);
static void exitHandler(int sig);
void displayChar(char* charmap,int disptime,int color,int shiftmod);
void marquee(char* charmap,int color, int disptime);

int rowarr[5]={1,2,4,8,16};
int colarr[8]={1,2,4,8,16,32,64,128};
int starttime, reftime;

int main()
{
   int i, j, k;
   struct sigaction sa;
   
   sa.sa_handler = exitHandler;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = 0;
   sigaction(SIGINT,&sa,NULL);
   sigaction(SIGTERM,&sa,NULL);

   wiringPiSetup();

   pinMode(ROW_CLK,OUTPUT);
   pinMode(ROW_CLR,OUTPUT);
   pinMode(ROW_DAT,OUTPUT);
   pinMode(COL_CLK,OUTPUT);
   pinMode(COL_CLR,OUTPUT);
   pinMode(R_DAT,OUTPUT);
   pinMode(G_DAT,OUTPUT);
   pinMode(B_DAT,OUTPUT);
   digitalWrite(ROW_CLR,1);
   digitalWrite(COL_CLR,1);

   //Endlosschleife
   printf("Use Ctrl-C or kill %i to exit\n",getpid());
   while(1)
   {/*
      for(j = 0; j < 5; j++)
      {
         for(i = 0; i < 8; i++)
         {
            for(k = 7; k <= 9; k++)
            {
               draw(colarr[i],rowarr[j],100,k);
            }
         }
      }*//*
   for(k = 7; k <= 9; k++)
   {
      marquee(I,k,1000);
      marquee(N,k,1000);
      marquee(F,k,1000);
      marquee(O,k,1000);
      marquee(I,k,1000);
      marquee(N,k,1000);
      marquee(I,k,1000);
   }*/
      drawMulti(colarr[0],rowarr[0],1,0,5,2);
   }
   return 0;
}

void draw(int col, int row, int holdtime, int color){
  shiftOut(ROW_DAT,ROW_CLK,MSBFIRST,row);
  shiftOut(color,COL_CLK,MSBFIRST,col);
  delay(holdtime);
  shiftOut(ROW_DAT,ROW_CLK,MSBFIRST,0);
  shiftOut(color,COL_CLK,MSBFIRST,0);
}

static void exitHandler(int sig)
{
   printf("Caught SIGINT. Exiting.\n");
   shiftOut(ROW_DAT,ROW_CLK,MSBFIRST,0);
   shiftOut(R_DAT,COL_CLK,MSBFIRST,0);
   shiftOut(G_DAT,COL_CLK,MSBFIRST,0);
   shiftOut(B_DAT,COL_CLK,MSBFIRST,0);
   digitalWrite(ROW_CLR,0);
   digitalWrite(COL_CLR,0);
   exit(0);
}

void displayChar(char* charmap,int disptime,int color,int shiftmod){
  int index = 0;
  starttime = millis();
  while(reftime - starttime < disptime){
    index = 0;
    while(index < 8){
      if(shiftmod >= 0){
        draw(*(charmap + index)>>shiftmod,colarr[index],2,color);
      }else{
        draw(*(charmap + index)<<(shiftmod*-1),colarr[index],2,color);
      }
      index++;
    }
    reftime = millis();
  }
}

void marquee(char *charmap,int color, int disptime){
  int i = -8;//lower i means text starts further right
  for(i;i < 5;i++){//letters are at max 5 fields wide
    displayChar(charmap,disptime/10,color,i);//divisor equals total number of fields moved
  }
}

void drawMulti(int col, int row, int holdtime, int r, int g, int b)
{
 int i,j,k;

 shiftOut(ROW_DAT,ROW_CLK,MSBFIRST,row);
 for(i = 0; i < r; i++)
 {
  shiftOut(R_DAT,COL_CLK,MSBFIRST,col);
  delay(holdtime / 3);
  shiftOut(R_DAT,COL_CLK,MSBFIRST,0);
 }

 for(j = 0; j < g; j++)
 {
  shiftOut(G_DAT,COL_CLK,MSBFIRST,col);
  delay(holdtime / 3);
  shiftOut(G_DAT,COL_CLK,MSBFIRST,0);
 }

 for(k = 0; k < b; k++)
 {
  shiftOut(B_DAT,COL_CLK,MSBFIRST,col);
  delay(holdtime / 3);
  shiftOut(B_DAT,COL_CLK,MSBFIRST,0);
 }
 shiftOut(ROW_DAT,ROW_CLK,MSBFIRST,0);
}


