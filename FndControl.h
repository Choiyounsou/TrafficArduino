#define FND1	38
#define FND2	39
#define FND3	40
#define FND4	41
#define FND5	42
#define FND6	43
#define FND7	44
#define FND8	45

#define FND_A	A8
#define FND_B	A9
#define FND_C	A10
#define FND_D	A11
#define FND_E	A12
#define FND_F	A13
#define FND_G	A14
#define FND_DP  A15

#define  A_BIT  0x01
#define  B_BIT  0x02
#define  C_BIT  0x04
#define  D_BIT  0x08
#define  E_BIT  0x10
#define  F_BIT  0x20
#define  G_BIT  0x40
#define  DP_BIT 0x80

#define FND_1_SEL    0x01
#define FND_2_SEL    0x02
#define FND_3_SEL    0x04
#define FND_4_SEL    0x08
#define FND_5_SEL    0x10
#define FND_6_SEL    0x20

#define MAX_FND_NUM 6
#define MAX_FND	8

void FndInit();
void FndSelect(int Position);
void DrawTextFnd(int Position, char text);
void FndOff();
