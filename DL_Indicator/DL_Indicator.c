#include "DL_Indicator.h"

const uint8_t ASCII_7SEG[96] = {
	0x00, /* (space) */
	0x86, /* ! */
	0x22, /* " */
	0x7E, /* # */
	0x6D, /* $ */
	0xD2, /* % */
	0x46, /* & */
	0x20, /* ' */
	0x29, /* ( */
	0x0B, /* ) */
	0x21, /* * */
	0x70, /* + */
	0x10, /* , */
	0x40, /* - */
	0x80, /* . */
	0x52, /* / */
	0x3F, /* 0 */
	0x06, /* 1 */
	0x5B, /* 2 */
	0x4F, /* 3 */
	0x66, /* 4 */
	0x6D, /* 5 */
	0x7D, /* 6 */
	0x07, /* 7 */
	0x7F, /* 8 */
	0x6F, /* 9 */
	0x09, /* : */
	0x0D, /* ; */
	0x61, /* < */
	0x48, /* = */
	0x43, /* > */
	0xD3, /* ? */
	0x5F, /* @ */
	0x77, /* A */
	0x7C, /* B */
	0x39, /* C */
	0x5E, /* D */
	0x79, /* E */
	0x71, /* F */
	0x3D, /* G */
	0x76, /* H */
	0x30, /* I */
	0x1E, /* J */
	0x75, /* K */
	0x38, /* L */
	0x15, /* M */
	0x37, /* N */
	0x3F, /* O */
	0x73, /* P */
	0x6B, /* Q */
	0x33, /* R */
	0x6D, /* S */
	0x78, /* T */
	0x3E, /* U */
	0x3E, /* V */
	0x2A, /* W */
	0x76, /* X */
	0x6E, /* Y */
	0x5B, /* Z */
	0x39, /* [ */
	0x64, /* \ */
	0x0F, /* ] */
	0x23, /* ^ */
	0x08, /* _ */
	0x02, /* ` */
	0x5F, /* a */
	0x7C, /* b */
	0x58, /* c */
	0x5E, /* d */
	0x7B, /* e */
	0x71, /* f */
	0x6F, /* g */
	0x74, /* h */
	0x10, /* i */
	0x0C, /* j */
	0x75, /* k */
	0x30, /* l */
	0x14, /* m */
	0x54, /* n */
	0x5C, /* o */
	0x73, /* p */
	0x67, /* q */
	0x50, /* r */
	0x6D, /* s */
	0x78, /* t */
	0x1C, /* u */
	0x1C, /* v */
	0x14, /* w */
	0x76, /* x */
	0x6E, /* y */
	0x5B, /* z */
	0x46, /* { */
	0x30, /* | */
	0x70, /* } */
	0x01, /* ~ */
	0x00, /* (del) */
};
const uint16_t ASCII_14SEG[96] = {
	0x0000, /* (space) */
	0x4006, /* ! */
	0x0202, /* " */
	0x12CE, /* # */
	0x12ED, /* $ */
	0x3FE4, /* % */
	0x2359, /* & */
	0x0200, /* ' */
	0x2400, /* ( */
	0x0900, /* ) */
	0x3FC0, /* * */
	0x12C0, /* + */
	0x0800, /* , */
	0x00C0, /* - */
	0x4000, /* . */
	0x0C00, /* / */
	0x0C3F, /* 0 */
	0x0406, /* 1 */
	0x00DB, /* 2 */
	0x008F, /* 3 */
	0x00E6, /* 4 */
	0x2069, /* 5 */
	0x00FD, /* 6 */
	0x0007, /* 7 */
	0x00FF, /* 8 */
	0x00EF, /* 9 */
	0x1200, /* : */
	0x0A00, /* ; */
	0x2440, /* < */
	0x00C8, /* = */
	0x0980, /* > */
	0x5083, /* ? */
	0x02BB, /* @ */
	0x00F7, /* A */
	0x128F, /* B */
	0x0039, /* C */
	0x120F, /* D */
	0x0079, /* E */
	0x0071, /* F */
	0x00BD, /* G */
	0x00F6, /* H */
	0x1209, /* I */
	0x001E, /* J */
	0x2470, /* K */
	0x0038, /* L */
	0x0536, /* M */
	0x2136, /* N */
	0x003F, /* O */
	0x00F3, /* P */
	0x203F, /* Q */
	0x20F3, /* R */
	0x00ED, /* S */
	0x1201, /* T */
	0x003E, /* U */
	0x0C30, /* V */
	0x2836, /* W */
	0x2D00, /* X */
	0x00EE, /* Y */
	0x0C09, /* Z */
	0x0039, /* [ */
	0x2100, /* \ */
	0x000F, /* ] */
	0x2800, /* ^ */
	0x0008, /* _ */
	0x0100, /* ` */
	0x1058, /* a */
	0x2078, /* b */
	0x00D8, /* c */
	0x088E, /* d */
	0x0858, /* e */
	0x14C0, /* f */
	0x048E, /* g */
	0x1070, /* h */
	0x1000, /* i */
	0x0A10, /* j */
	0x3600, /* k */
	0x0030, /* l */
	0x10D4, /* m */
	0x1050, /* n */
	0x00DC, /* o */
	0x0170, /* p */
	0x0486, /* q */
	0x0050, /* r */
	0x2088, /* s */
	0x0078, /* t */
	0x001C, /* u */
	0x0810, /* v */
	0x2814, /* w */
	0x2D00, /* x */
	0x028E, /* y */
	0x0848, /* z */
	0x0949, /* { */
	0x1200, /* | */
	0x2489, /* } */
	0x0CC0, /* ~ */
	0x0000, /* (del) */
};
const uint16_t ASCII_16SEG[96] = {
	0x0000, /* (space) */
	0x000C, /* ! */
	0x0204, /* " */
	0xAA3C, /* # */
	0xAABB, /* $ */
	0xEE99, /* % */
	0x9371, /* & */
	0x0200, /* ' */
	0x1400, /* ( */
	0x4100, /* ) */
	0xFF00, /* * */
	0xAA00, /* + */
	0x4000, /* , */
	0x8800, /* - */
	0x1000, /* . */
	0x4400, /* / */
	0x44FF, /* 0 */
	0x040C, /* 1 */
	0x8877, /* 2 */
	0x083F, /* 3 */
	0x888C, /* 4 */
	0x90B3, /* 5 */
	0x88FB, /* 6 */
	0x000F, /* 7 */
	0x88FF, /* 8 */
	0x88BF, /* 9 */
	0x2200, /* : */
	0x4200, /* ; */
	0x9400, /* < */
	0x8830, /* = */
	0x4900, /* > */
	0x2807, /* ? */
	0x0AF7, /* @ */
	0x88CF, /* A */
	0x2A3F, /* B */
	0x00F3, /* C */
	0x223F, /* D */
	0x80F3, /* E */
	0x80C3, /* F */
	0x08FB, /* G */
	0x88CC, /* H */
	0x2233, /* I */
	0x007C, /* J */
	0x94C0, /* K */
	0x00F0, /* L */
	0x05CC, /* M */
	0x11CC, /* N */
	0x00FF, /* O */
	0x88C7, /* P */
	0x10FF, /* Q */
	0x98C7, /* R */
	0x88BB, /* S */
	0x2203, /* T */
	0x00FC, /* U */
	0x44C0, /* V */
	0x50CC, /* W */
	0x5500, /* X */
	0x88BC, /* Y */
	0x4433, /* Z */
	0x2212, /* [ */
	0x1100, /* \ */
	0x2221, /* ] */
	0x5000, /* ^ */
	0x0030, /* _ */
	0x0100, /* ` */
	0xA070, /* a */
	0xA0E0, /* b */
	0x8060, /* c */
	0x281C, /* d */
	0xC060, /* e */
	0xAA02, /* f */
	0xA2A1, /* g */
	0xA0C0, /* h */
	0x2000, /* i */
	0x2260, /* j */
	0x3600, /* k */
	0x00C0, /* l */
	0xA848, /* m */
	0xA040, /* n */
	0xA060, /* o */
	0x82C1, /* p */
	0xA281, /* q */
	0x8040, /* r */
	0xA0A1, /* s */
	0x80E0, /* t */
	0x2060, /* u */
	0x4040, /* v */
	0x5048, /* w */
	0x5500, /* x */
	0x0A1C, /* y */
	0xC020, /* z */
	0xA212, /* { */
	0x2200, /* | */
	0x2A21, /* } */
	0xCC00, /* ~ */
	0x0000, /* (del) */
};

uint8_t DL_intToStr(char* str, int32_t num)
{
    uint8_t start = 0;
    uint8_t end = 0;

    if(num < 0)
    {
        str[0] = '-';

        num = -num;

        start = 1;
        end = 1;
    }

    do
    {
        str[end] = (char)(num % 10) + '0';
        end++;
        num /= 10;
    }
    while(num != 0);

    uint8_t len = end;

    str[end] = '\0';

    end--;

    for(; start < end; start++, end--)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }

    return len;
}

uint8_t DL_floatToStr(char* str, float num, uint8_t precision)
{
    if(precision > 6) precision = 6;

    float addition = 0.51;
    
    for(uint8_t i = 0; i < precision; i++) 
        addition /= 10;
    
    num += addition;

    uint8_t len = 0;
    int32_t whole_part = 0;

    if(num < 0)
    {
        str[0] = '-';
        num = -num;
        whole_part = (int32_t)num;
        len = DL_intToStr(str + 1, whole_part) + 1;
    }
    else
    {
        whole_part = (int32_t)num;
        len = DL_intToStr(str, whole_part);
    }

    if(precision > 0)
    {
        str[len] = '.';
        len++;
    }
    else
    {
        str[len] = '\0';
        return len;
    }

    float temp = num - whole_part;

    for(uint8_t i = 0; i < precision; i++, len++)
    {
        temp *= 10;
        int32_t frac_part = (int32_t)temp;
        DL_intToStr(str + len, frac_part);
        temp -= frac_part;
    }

    str[len] = '\0';

    return len;
}

void DL_indInit(DL_Indicator* ind, I2C_HandleTypeDef* i2c, DL_IndicatorType type, uint8_t adress)
{
	ind->i2c = i2c;
	ind->type = type;
	ind->adress = adress;

	ind->index = 0;
	ind->timer = 0;

	DL_indClkStart(ind);
	DL_indSetBrightness(ind, 20);
	DL_indClear(ind);
	DL_indDisplayON(ind);
}


void DL_indClkStart(DL_Indicator* ind)
{
	uint8_t command = 0x21;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}
void DL_indClkStop(DL_Indicator* ind)
{
	uint8_t command = 0x20;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}


void DL_indDisplayON(DL_Indicator* ind)
{
	uint8_t command = 0x81;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}
void DL_indDisplayOFF(DL_Indicator* ind)
{
	uint8_t command = 0x80;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}


void DL_indSetBrightness(DL_Indicator* ind, uint8_t duty)
{
	uint8_t command = 0xE0 | (0xF * duty / 100);
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}


void DL_indBlinkingStart2Hz(DL_Indicator* ind)
{
	uint8_t command = 0x83;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}
void DL_indBlinkingStart1Hz(DL_Indicator* ind)
{
	uint8_t command = 0x85;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}
void DL_indBlinkingStart05Hz(DL_Indicator* ind)
{
	uint8_t command = 0x87;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}
void DL_indBlinkingStop(DL_Indicator* ind)
{
	uint8_t command = 0x81;
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, &command, 1, 1000);
}


void DL_indPrintBitMap(DL_Indicator* ind, uint16_t* vals, uint8_t size)
{
	uint8_t codes[17] = {0};

	for(int i = 0; i < size; i++)
	{
		codes[2*i + 1] =  vals[i] & 0xFF;
		codes[2*i + 2] =  vals[i] >> 8;
	}

	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, codes, 17, 1000);
}
void DL_indClear(DL_Indicator* ind)
{
	uint8_t codes[17] = {0};
	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, codes, 17, 1000);
}


void DL_indPrintStr(DL_Indicator* ind, const char* str, uint8_t pos)
{
	uint8_t codes[17] = {0};

	if(pos < 8)
		codes[0] = 2 * pos;
	else
		return;

	uint8_t seg = 0;

	switch(ind->type)
	{
		case DL_7SEGMENT :

			for(uint8_t i = 0; str[i] != '\0'; i++, seg++)
			{
				if(i > 0 && str[i] == '.' && str[i - 1] != '.')
				{
					seg--;
					codes[2*seg + 1] |= 0x80;
				}
				else
				{
					if(seg > (7 - pos) )
						break;
					else
						codes[2*seg + 1] = ASCII_7SEG[ str[i] - 32 ];
				}
			}

			break;

		case DL_14SEGMENT :

			for(uint8_t i = 0; str[i] != '\0'; i++, seg++)
			{
				if(i > 0 && str[i] == '.' && str[i - 1] != '.')
				{
					seg--;
					codes[2*seg + 2] |= 0x80;
				}
				else
				{
					if(seg > (7 - pos) )
						break;
					else
					{
						codes[2*seg + 1] = ASCII_14SEG[ str[i] - 32 ] & 0xFF;
						codes[2*seg + 2] = ASCII_14SEG[ str[i] - 32 ] >> 8;
					}
				}
			}

			break;

		case DL_16SEGMENT :

			for(int i = 0; str[i] != '\0' && i < (8 - pos); i++, seg++)
			{
				codes[2*i + 1] = ASCII_16SEG[ str[i] - 32 ] & 0xFF;
				codes[2*i + 2] = ASCII_16SEG[ str[i] - 32 ] >> 8;
			}

			break;

		default :
			return;
	}

	HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, codes, 1 + 2 * seg, 1000);
}
void DL_indPrintInt(DL_Indicator* ind, int32_t num, uint8_t pos)
{
	if(ind->type == DL_7SEGMENT || ind->type == DL_14SEGMENT || ind->type == DL_16SEGMENT)
	{
		char str[32] = "";

		DL_intToStr(str, num);

		DL_indPrintStr(ind, str, pos);
	}
}
void DL_indPrintFloat(DL_Indicator* ind, float num, uint8_t precision, uint8_t pos)
{
	if(ind->type == DL_7SEGMENT || ind->type == DL_14SEGMENT || ind->type == DL_16SEGMENT)
	{
		char str[32] = "";

		DL_floatToStr(str, num, precision);

		DL_indPrintStr(ind, str, pos);
	}
}
void DL_indPrintLeftRunningStr(DL_Indicator* ind, const char* str, uint8_t seg_amount, uint32_t step_time)
{
	if(ind->type == DL_7SEGMENT || ind->type == DL_14SEGMENT || ind->type == DL_16SEGMENT)
	{
		if(HAL_GetTick() - ind->timer > step_time)
		{
			ind->timer = HAL_GetTick();

			int8_t len = 0;
			for(;str[len] != '\0'; len++);

			DL_indClear(ind);
			DL_indPrintStr(ind, str + ind->index, 0);

			if(ind->index >= len - seg_amount)
				ind->index = 0;
			else
				ind->index++;
		}
	}
}
void DL_indPrintRightRunningStr(DL_Indicator* ind, const char* str, uint8_t seg_amount, uint32_t step_time)
{
	if(ind->type == DL_7SEGMENT || ind->type == DL_14SEGMENT || ind->type == DL_16SEGMENT)
	{
		if(HAL_GetTick() - ind->timer > step_time)
		{
			ind->timer = HAL_GetTick();

			int8_t len = 0;
			for(;str[len] != '\0'; len++);

			DL_indClear(ind);
			DL_indPrintStr(ind, str + ind->index, 0);

			if(ind->index == 0)
				ind->index = len - seg_amount;
			else
				ind->index--;
		}
	}
}

void DL_indPrintBars(DL_Indicator* ind, uint8_t* vals, uint8_t size)
{
	if(ind->type == DL_BAR)
	{
		uint8_t codes[17] = {0};

		for(int i = 0; i < size; i++)
		{
			codes[2*i + 1] = ~( 0xFFFF << vals[i] ) & 0xFF;
			codes[2*i + 2] = ~( 0xFFFF << vals[i] ) >> 8;
		}

		HAL_I2C_Master_Transmit(ind->i2c, ind->adress << 1, codes, 17, 1000);
	}
}

