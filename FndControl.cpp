#include <Arduino.h>
#include "FndControl.h"

const int FndSelectTable[6] =
{
	FND1 ,
	FND2 ,
	FND3 ,
	FND4 ,
	FND5 ,
	FND6 
};
const int FndPinTable[8] =
{
	FND_A ,
	FND_B ,
	FND_C ,
	FND_D ,
	FND_E ,
	FND_F ,
	FND_G ,
	FND_DP
};

const int FndNumberTable[10] =
{
    A_BIT | B_BIT | C_BIT | D_BIT | E_BIT | F_BIT , // '0'
    B_BIT | C_BIT , // '1'
    A_BIT | B_BIT | D_BIT | E_BIT | G_BIT,  // '2'
    A_BIT | B_BIT | C_BIT | D_BIT | G_BIT,
    B_BIT | C_BIT | F_BIT | G_BIT, // 4
    A_BIT | C_BIT | D_BIT | F_BIT | G_BIT,
    C_BIT | D_BIT | E_BIT | F_BIT | G_BIT,
    A_BIT | B_BIT | C_BIT ,
    A_BIT | B_BIT | C_BIT | D_BIT | E_BIT | F_BIT | G_BIT,
    A_BIT | B_BIT | C_BIT | F_BIT | G_BIT, // 9
};

void FndInit()
{
	int i;
	for(i = 0; i<MAX_FND ; i++)
	{
		pinMode(FndSelectTable[i], OUTPUT);    //Fnd Sel Pin OUTPUT Set
		pinMode(FndPinTable[i], OUTPUT);       //Fnd Data Pin OUTPUT Set
	}
	
}

void FndSelect(int Position)
{
	int i;
	
	for( i = 0; i<MAX_FND_NUM; i++)
	{
		if(Position & (1<<i))
		{
			digitalWrite(FndSelectTable[i], LOW);
		}
		else
		{
			digitalWrite(FndSelectTable[i], HIGH);
		}
	}
}
void FndOff()
{
	int i;
	
	for( i = 0; i<MAX_FND; i++)
	{
		{
			digitalWrite(FndSelectTable[i], HIGH);
		}
	}		
        delay(50);
}
void FndData(char text)
{
	int i;
    if(text == '0')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[0] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '1')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[1] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
        delay(1);
    }
    if(text == '2')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[2] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '3')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[3] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '4')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[4] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '5')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[5] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '6')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[6] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '7')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[7] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '8')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[8] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '9')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[9] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    if(text == '.')
    {
		for( i = 0; i<MAX_FND; i++)
		{
			if(FndNumberTable[10] & (1<<i))
			{
				digitalWrite(FndPinTable[i], HIGH);
			}
			else
			{
				digitalWrite(FndPinTable[i], LOW);
			}
		}
		delay(1);
    }
    delay(1);
}

void DrawTextFnd(int Position, char text)
{
   FndSelect(Position);
   FndData(text);  
}
