#include <reg51.h>
  
#define uchar unsigned char
#define uint unsigned int

sbit WEI = P2^7;
sbit DUAN = P2^6;//

//数码显示的段位。

//const unsigned char code wei[8] = { 0X7F, 0XBF, 0XDF, 0XEF, 0XF7, 0XFB, 0XFD, 0XFE };



const unsigned char code duan[17] = { 0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F, 0X77, 0X7C, 0X39, 0X5E, 0X79, 0X71, 0X00 };//要显示的数字。


uchar table[]={0,0,0,0,0,0,0,0};
//键盘的4x4+4个独立按键。
uchar key[] = {0xEE,0xDE,0xBE,0x7E,0xED,0xDD,0xBD,0x7D,0xEB,0xDB,0xBB,0x7B,0xE7,0xD7,0xB7,0x77,0xEF,0xDF,0xBF,0x7F};


//seat(下标加1)
uint seat[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


uchar buf;//缓存数据。
uchar rec;

uchar sending;//sening数据



//延时韩式，延时参数的ms单位。
void delay(unsigned int xms){
  unsigned char i, j;
  for (i = xms; i > 0; i--)
   for (j = 112; j > 0; j--) ;
 }

 
 /*
 
void display(unsigned char * displayStr){
  unsigned char i;
  for (i = 0; i < 8; i++){
    DUAN = 0;
    P0 = *(duan + *(displayStr + i));
    DUAN = 1;
    DUAN = 0;
    WEI = 0;
    P0 = *(wei + i);
    WEI = 1;
    WEI = 0;
    delay(2);
  }
}
*/

void display()
{
	int k,i;
	table[7]=duan[rec%10];
	table[6]=duan[rec/10];
	for(k=1,i=0;i<8;i++)
	{
		
		P0=~k;
		WEI=1;
		WEI=0;
		
		
		P0=table[i];
		DUAN=1;
		DUAN=0;
	
		k=k<<1;
		delay(1);
	}
		

}

void send(uchar num) 
{
 
  SBUF = num; 
  sending = 1; 
  while(sending); 
}
void main(void) 
{
  uint i,j=0;                                               //11110111
  uchar row,queen,result;
  
    SCON = 0x50;           
    PCON = 0x00;         
    TMOD = 0x20;          
    ES = 1;              
    TL1 = 0xfd;
    TH1 = 0xfd;             
    TR1 = 1;
  while(1)
  { 
    EA = 0;
    P3 = 0xF0;
    row = P3;
    if(row != 0xF0)
    {
      row = P3;
      
    }
    P3 = 0x0F;
    queen = P3;
    if(queen != 0x0F)
    {
      queen = P3;
      
    }
    result = row | queen;
    for(i = 0;i < 20;i++)
    {
      if(key[i] == result)
        break;
    }
    if(i<16)
    {
      P3 = 0xF0;
      row = P3;
      if(row != 0xF0)
      {
        row = P3;
        
      }
      P3 = 0x0F;
      queen = P3;
      if(queen != 0x0F)
      {
        queen = P3;
        
      }
      result = row | queen;   
      if(result==key[i])
      {     
        while(1)
        {
          if(P3==0x0f)
            delay(22);
          if(P3==0x0f)
            break;
        }  
      }
          
    }
    EA = 1;
    if((i >= 0)&&(i < 16)&&(seat[i]!=0x00)&&(seat[i]!=0xFF)&&(seat[i]!=0xF8))
      send(seat[i]);
	display();
  }
}
void  serial() interrupt 4 
{
  ES = 0;            
   
  if(RI == 1)
  {
    RI = 0;
	rec=SBUF;
  }
  if(TI == 1)
  {
    TI = 0;
    sending=0;  
  }
  ES = 1;    
}
