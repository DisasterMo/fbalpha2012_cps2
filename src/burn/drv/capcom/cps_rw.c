#include "cps.h"
#include <retro_inline.h>
// CPS - Read/Write

// Input bits
#define INP(nnn) UINT8 CpsInp##nnn[8];
CPSINPSET
#undef  INP

// Bytes to return from ports
#define INP(nnn) UINT8 Inp##nnn;
CPSINPSET
#undef  INP

UINT16 CpsInp055 = 0;
UINT16 CpsInp05d = 0;
UINT16 CpsInpPaddle1 = 0;
UINT16 CpsInpPaddle2 = 0;
static INT32 ReadPaddle = 0;
INT32 CpsPaddle1Value = 0;
INT32 CpsPaddle2Value = 0;
INT32 CpsPaddle1 = 0;
INT32 CpsPaddle2 = 0;
static INT32 nDial055, nDial05d;

INT32 Kodh = 0;
INT32 Cawingb = 0;
INT32 Wofh = 0;
INT32 Pzloop2 = 0;
INT32 Ssf2tb = 0;
INT32 Port6SoundWrite = 0;
INT32 CpsBootlegEEPROM = 0;

CpsRWSoundCommandCallback CpsRWSoundCommandCallbackFunction = NULL;

static INT32 nCalc[2] = {0, 0};

static const BOOL nCPSExtraNVRAM = FALSE;
static INT32 n664001;

#define INP(nnnn) UINT8 CpsInp##nnnn[8];
CPSINPEX
#undef  INP

#define INP(nnnn) static UINT8 Inp##nnnn;
CPSINPEX
#undef  INP


// Read input port 0x000-0x1ff
static UINT8 CpsReadPort(const UINT32 ia)
{
   UINT8 d = 0xFF;

   switch (ia)
   {
      case 0x000:
         d = (UINT8)~Inp000;
         if (Pzloop2)
         {
            if (ReadPaddle)
               d -= CpsPaddle2Value;
            else
               d = CpsPaddle2;
         }
         return d;
      case 0x001:
         d = (UINT8)~Inp001;
         if (Pzloop2)
         {
            if (ReadPaddle)
               d -= CpsPaddle1Value;
            else
               d = CpsPaddle1;
         }
         return d;
      case 0x010:
         d = (UINT8)~Inp010;
         return d;
      case 0x011:
         d = (UINT8)~Inp011;
         return d;
      case 0x012:
         d = (UINT8)~Inp012;
         return d;
      case 0x018:
         d = (UINT8)~Inp018;
         return d;
      case 0x019:
         d = (UINT8)~Inp019;
         return d;
      case 0x01B:
         d = (UINT8)~Inp01B;
         return d;
      case 0x01A:
         d = (UINT8)~Cpi01A;
         return d;
      case 0x01C:
         d = (UINT8)~Cpi01C;
         return d;
      case 0x01E:
         d = (UINT8)~Cpi01E;
         return d;
      case 0x020:
         /* Used on CPS2 only I think */
         d = (UINT8)~Inp020;
         return d;
      case 0x021:
         d = (UINT8)~Inp021;
         d &= 0xFE;
         d |= EEPROMRead();
         return d;
      case 0x030:
         /* CPS2 Volume control */
         if (Ssf2tb)
            d = 0x20;
         else
         {
            d = Cps2VolumeStates[Cps2Volume] >> 8;
            if (Cps2DisableDigitalVolume) d = 0xd0;
         }
         return d;
      case 0x031:
         d = Cps2VolumeStates[Cps2Volume] & 0xff;
         return d;
   }

   if (ia >= 0x0100 && ia < 0x0200)
   {
      static INT32 nRasterLine;

      // The linecounters seem to return the line at which the last IRQ triggered by this counter is scheduled minus the current line
      if ((ia & 0x0FE) == 0x50)
      {
         if ((ia & 1) == 0)
         {
            nRasterLine = nIrqLine50 - SekCurrentScanline();
            return nRasterLine >> 8;
         }
         return nRasterLine & 0xFF;
      }

      if ((ia & 0x0FE) == 0x52)
      {
         if ((ia & 1) == 0)
         {
            nRasterLine = nIrqLine52 - SekCurrentScanline();
            return nRasterLine >> 8;
         }
         return nRasterLine & 0xFF;
      }
   }

   return d;
}

// Write output port 0x000-0x1ff
void CpsWritePort(const UINT32 ia, UINT8 d)
{
   // CPS registers
   if (ia >= 0x100 && ia < 0x200)
   {
      CpsReg[(ia ^ 1) & 0xFF] = d;

      if (ia == 0x10b)
      {
         GetPalette(0, 6);
         CpsPalUpdate(CpsSavePal);
      }
      return;
   }

   if (ia == 0x40)
   {
      EEPROMWrite(d & 0x20, d& 0x40, d & 0x10);
      return;
   }

   // CPS2 object bank select
   if ((ia & 0x1FF) == 0x0E1)
   {
      CpsMapObjectBanks(d & 1);
      return;
   }

   if (ia == 0x41 && Pzloop2)
      ReadPaddle = d & 0x02;
}

UINT8 __fastcall CpsReadByte(UINT32 a)
{
	// Input ports mirrored between 0x800000 and 0x807fff
	if ((a & 0xFF8000) == 0x800000)
		return CpsReadPort(a & 0x1FF);

   if ((a & 0xFF8000) == 0x660000)
   {
      if (a == 0x664001)
         return n664001;
   }

   return 0x00;
}

void __fastcall CpsWriteByte(UINT32 a,UINT8 d)
{
   // Output ports mirrored between 0x800000 and 0x807fff
   if ((a & 0xFF8000) == 0x800000) {
      CpsWritePort(a & 0x1FF, d);
      return;
   }

   // 0x400000 registers
   if ((a & 0xFFFFF0) == 0x400000)
   {
      CpsFrg[a & 0x0F] = d;
      return;
   }

   if ((a & 0xFF8000) == 0x660000)
   {
      // bit 1 toggled on/off each frame
      if (a == 0x664001)
         n664001 = d;
   }
}

UINT16 __fastcall CpsReadWord(UINT32 a)
{
	if ((a & 0xFF8FFF) == 0x800100 + CpsMProt[3])
		return (UINT16)((nCalc[0] * nCalc[1]) >> 16);
	// ports mirrored between 0x800000 and 0x807fff
	if ((a & 0xFF8FFF) == 0x800100 + CpsMProt[2])
		return (UINT16)((nCalc[0] * nCalc[1]));
	
	SEK_DEF_READ_WORD(0, a);
}

void __fastcall CpsWriteWord(UINT32 a, UINT16 d)
{
	// ports mirrored between 0x800000 and 0x807fff
	if ((a & 0xFF8FFF) == 0x800100 + CpsMProt[0])
		nCalc[0] = d;
	if ((a & 0xFF8FFF) == 0x800100 + CpsMProt[1])
		nCalc[1] = d;

	if (a == 0x804040)
   {
		if ((d & 0x0008) == 0)
      {
			if (!Cps2DisableQSnd)
            ZetReset();
		}
	}
	
	SEK_DEF_WRITE_WORD(0, a, d);
}

// Reset all inputs to zero
static INT32 InpBlank(void)
{
#define INP(nnn) Inp##nnn = 0; memset(CpsInp##nnn, 0, sizeof(CpsInp##nnn));
	CPSINPSET
#undef INP

#define INP(nnnn) Inp##nnnn = 0; memset(CpsInp##nnnn, 0, sizeof(CpsInp##nnnn));
	CPSINPEX
#undef INP

	CpsInp055 = CpsInp05d = 0;

	return 0;
}

INT32 CpsRwInit(void)
{
	InpBlank();
	return 0;
}

INT32 CpsRwExit()
{
	InpBlank();
	CpsRWSoundCommandCallbackFunction = NULL;
	return 0;
}

static INLINE void StopOpposite(UINT8* pInput)
{
   if ((*pInput & 0x03) == 0x03)
      *pInput &= ~0x03;
   if ((*pInput & 0x0C) == 0x0C)
      *pInput &= ~0x0C;
}

INT32 CpsRwGetInp(void)
{
   // Compile separate buttons into Inpxxx
#define INP(nnn) \
   { INT32 i = 0; Inp##nnn = 0; \
      for (i = 0; i < 8; i++) { Inp##nnn |= (CpsInp##nnn[i] & 1) << i; }  }
   CPSINPSET
#undef INP


#define INP(nnnn) \
   { INT32 i = 0; Inp##nnnn = 0; \
      for (i = 0; i < 8; i++) { Inp##nnnn |= (CpsInp##nnnn[i] & 1) << i; }  }
      CPSINPEX
#undef INP

      if (Pzloop2)
      {
         if (ReadPaddle)
         {
            CpsPaddle1Value = 0;
            CpsPaddle2Value = 0;
            if (CpsInpPaddle1)
            {
               if (CpsInpPaddle1 > 0x8000)
                  CpsPaddle1Value = 2;

               if (CpsInpPaddle1 < 0x7fff)
                  CpsPaddle1Value = 1;
            }

            if (CpsInpPaddle2)
            {
               if (CpsInpPaddle2 > 0x8000)
                  CpsPaddle2Value = 2;

               if (CpsInpPaddle2 < 0x7fff)
                  CpsPaddle2Value = 1;
            }
         }

         CpsPaddle1 += (CpsInpPaddle1 >> 8) & 0xff;
         CpsPaddle2 += (CpsInpPaddle2 >> 8) & 0xff;
      }

   StopOpposite(&Inp000);
   StopOpposite(&Inp001);

   if (nMaxPlayers > 2)
   {
      StopOpposite(&Inp011);
      if (nMaxPlayers == 4)
         StopOpposite(&Inp010);
   }

   return 0;
}
