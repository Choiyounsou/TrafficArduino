#define __AVR_ATemga2560__

#include <MsTimer2.h>
#include "FndControl.h"

#define WEST    0
#define SOUTH   1
#define EAST    2
#define NORTH   3

#define WEST_LED_1	0
#define WEST_LED_2	1
#define WEST_LED_3	2
#define WEST_LED_4	3
#define WEST_LED_5	4
#define WEST_LED_6	5
#define WEST_LED_7	6
#define WEST_LED_8	7

#define SOUTH_LED_1	14
#define SOUTH_LED_2	15
#define SOUTH_LED_3	16
#define SOUTH_LED_4	17
#define SOUTH_LED_5	18
#define SOUTH_LED_6	19
#define SOUTH_LED_7	20	
#define SOUTH_LED_8	21

#define EAST_LED_1	22
#define EAST_LED_2	23
#define EAST_LED_3	24
#define EAST_LED_4	25
#define EAST_LED_5	26
#define EAST_LED_6	27
#define EAST_LED_7	28
#define EAST_LED_8	29

#define NORTH_LED_1	30
#define NORTH_LED_2	31
#define NORTH_LED_3	32
#define NORTH_LED_4	33
#define NORTH_LED_5	34
#define NORTH_LED_6	35
#define NORTH_LED_7	36
#define NORTH_LED_8	37

#define RED_LIGHT		0x01
#define YELLOW_LIGHT		0x02
#define LEFT_GREEN_LIGHT	0x04
#define GREEN_LIGHT		0x08
#define WALK_GREEN_LIGHT	0x10 | 0x40
#define WALK_RED_LIGHT		0x20 | 0x80

#define LED_NO_12  A3
#define LED_NO_13  A4
#define LED_NO_14  A5
#define LED_NO_15  A6
#define LED_NO_16  A7

const byte LedPinTable[5] = 
{
  LED_NO_12,
  LED_NO_13,
  LED_NO_14,
  LED_NO_15,
  LED_NO_16
};

const int Fndtable[6] = {
    FND_1_SEL,
    FND_2_SEL,
    FND_3_SEL,
    FND_4_SEL,
    FND_5_SEL,
    FND_6_SEL
};

char u_cText[8] = {'5','4','3','2','1','0','0','0'};

const int WestLedTable[8] = 
{
	WEST_LED_1,
	WEST_LED_2,
	WEST_LED_3,
	WEST_LED_4,
	WEST_LED_5,
	WEST_LED_6,
	WEST_LED_7,
	WEST_LED_8
};

const int SouthLedTable[8] =
{
	SOUTH_LED_1,
	SOUTH_LED_2,
	SOUTH_LED_3,
	SOUTH_LED_4,
	SOUTH_LED_5,
	SOUTH_LED_6,
	SOUTH_LED_7,
	SOUTH_LED_8,
};

const int EastLedTable[8] = 
{
	EAST_LED_1,
	EAST_LED_2,
	EAST_LED_3,
	EAST_LED_4,
	EAST_LED_5,
	EAST_LED_6,
	EAST_LED_7,
	EAST_LED_8,
};

const int NorthLedTable[8] = 
{
	NORTH_LED_1,
	NORTH_LED_2,
	NORTH_LED_3,
	NORTH_LED_4,
	NORTH_LED_5,
	NORTH_LED_6,
	NORTH_LED_7,
	NORTH_LED_8,
};

unsigned int g_unActionCounter = 0;
unsigned int g_unSelDir = 0;

void setup()
{
    int k1;
    for(k1 = 0; k1<5 ; k1++)
    {
        pinMode(LedPinTable[k1],OUTPUT);  //LED PORT SET
    }
    FndInit();
    LedInit();
    MsTimer2::set(1000,timerflag);
    MsTimer2::start();
}

void timerflag()
{
    g_unActionCounter++;
}

#define MAX_LED_NUM    8

void LedInit()
{
    int i;
    for(i = 0; i<MAX_LED_NUM; i++)
    {
        pinMode(WestLedTable[i], OUTPUT);
        pinMode(SouthLedTable[i], OUTPUT);
        pinMode(EastLedTable[i], OUTPUT);
        pinMode(NorthLedTable[i], OUTPUT);
        
    }
}
void WestLedDisplay(unsigned char data)
{
    int i;
    
    for(i = 0; i < MAX_LED_NUM ;i++)
    {
        if(data & (1 << i ))
        {
            digitalWrite(WestLedTable[i], HIGH);
        }
        else
        {
            digitalWrite(WestLedTable[i], LOW);
        }
    }
}
void SouthLedDisplay(unsigned char data)
{
    int i;
    
    for(i = 0; i < MAX_LED_NUM ;i++)
    {
        if(data & (1 << i ))
        {
            digitalWrite(SouthLedTable[i], HIGH);
        }
        else
        {
            digitalWrite(SouthLedTable[i], LOW);
        }
    }    
}
void EastLedDisplay(unsigned char data)
{
    int i;
    
    for(i = 0; i < MAX_LED_NUM ;i++)
    {
        if(data & (1 << i ))
        {
            digitalWrite(EastLedTable[i], HIGH);
        }
        else
        {
            digitalWrite(EastLedTable[i], LOW);
        }
    }    
}
void NorthLedDisplay(unsigned char data)
{
    int i;
    
    for(i = 0; i < MAX_LED_NUM ;i++)
    {
        if(data & (1 << i ))
        {
            digitalWrite(NorthLedTable[i], HIGH);
        }
        else
        {
            digitalWrite(NorthLedTable[i], LOW);
        }
    }    
}
void selectDirectioin (unsigned char sel_dir, unsigned char data)
{
	switch (sel_dir)
	{
		case WEST:
			WestLedDisplay(data);
			break;			
		case SOUTH:
			SouthLedDisplay(data);
			break;
		case EAST:
			EastLedDisplay(data);
			break;
		case NORTH:
			NorthLedDisplay(data);
			break;
		default:
			break;
	}			
}
void changeDirection (unsigned char sel_dir)
{
	if (g_unActionCounter == 0)		// 1초(5초동안)
	{
		selectDirectioin(sel_dir, GREEN_LIGHT | LEFT_GREEN_LIGHT | WALK_RED_LIGHT);	// 기준 신호등
		selectDirectioin((sel_dir+3)%4, RED_LIGHT | WALK_GREEN_LIGHT);			// 좌측 신호등
		selectDirectioin((sel_dir+2)%4, RED_LIGHT | WALK_RED_LIGHT);			// 반대편 신호등
		selectDirectioin((sel_dir+1)%4, RED_LIGHT | WALK_RED_LIGHT);			// 우측 신호등
    for(int j = 0; j<5 ; j++)
    {
        digitalWrite(LedPinTable[j],HIGH);  //LED ON
    }
	}
  if (g_unActionCounter == 1)    // 2초
  {
    digitalWrite(LedPinTable[0],LOW);  //LED OFF
  }
  if (g_unActionCounter == 2)    // 3초
  {
    digitalWrite(LedPinTable[1],LOW);  //LED OFF
  }
  if (g_unActionCounter == 3)    // 4초
  {
    digitalWrite(LedPinTable[2],LOW);  //LED OFF
  }
  if (g_unActionCounter == 4)    // 4초
  {
    digitalWrite(LedPinTable[3],LOW);  //LED OFF
  }
	if (g_unActionCounter == 5)		// 5초(1초동안)
	{
    digitalWrite(LedPinTable[4],LOW);  //LED OFF
		selectDirectioin(sel_dir, YELLOW_LIGHT | WALK_RED_LIGHT);			// 기준 신호등
		selectDirectioin((sel_dir+3)%4, RED_LIGHT | WALK_RED_LIGHT);		// 좌측 신호등
	}
	if (g_unActionCounter == 6)		// 7초(1초동안)
	{
		selectDirectioin(sel_dir, RED_LIGHT | WALK_RED_LIGHT);				// 기준 신호등
	}
  if (g_unActionCounter == 7){
		g_unSelDir++;
		if (g_unSelDir > 3)
			g_unSelDir = 0;
		g_unActionCounter = 0;
	}
  DrawTextFnd(Fndtable[0],u_cText[g_unActionCounter]);
}


void loop()
{
    changeDirection (g_unSelDir);
}
