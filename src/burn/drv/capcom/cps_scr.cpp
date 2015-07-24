#include "cps.h"

// CPS Scroll (Background Layers)

// Base = 0x4000 long tile map
// sx=Scroll X value, sy=Scroll Y value,
INT32 Ghouls=0;
INT32 Ssf2t=0;
INT32 Xmcota=0;

INT32 Scroll1TileMask = 0;
INT32 Scroll2TileMask = 0;
INT32 Scroll3TileMask = 0;

INT32 Cps2Scr1Draw(UINT8 *Base, INT32 sx, INT32 sy)
{
	INT32 x, y;
	INT32 iy;
	INT32 nFirstY, nLastY;
	INT32 nKnowBlank = -1; // The tile we know is blank
	INT32 ix = (sx >> 3) + 1;
	sx &= 7;
	sx = 8 - sx;

	iy = (sy >> 3) + 1;
	sy &= 7;

	nLastY = (nEndline + sy) >> 3;
	nFirstY = (nStartline + sy) >> 3;

	sy = 8 - sy;

	for (y = nFirstY - 1; y < nLastY; y++)
   {
      INT32 nClipY = ((y << 3) < nStartline) | (((y << 3) + 8) >= nEndline);
      for (x = -1; x < 48; x++)
      {
         INT32 a;
         INT32 fx = ix + x;
         INT32 fy = iy + y;								// 0 <= fx/fy <= 63

         // Find tile address
         INT32     p = (((fy & 0x20) << 8) | ((fx & 0x3F) << 7) | ((fy & 0x1F) << 2)) & 0x3FFF;
         UINT16 *pst = (UINT16 *)(Base + p);
         INT32     t = (BURN_ENDIAN_SWAP_INT16(pst[0])) << 6; /* Get real tile address */

         t += nCpsGfxScroll[1];							// add on offset to scroll tiles

         /* Draw tile */
         if (t == nKnowBlank)
            continue;

         a = BURN_ENDIAN_SWAP_INT16(pst[1]);

         CpstSetPal(0x20 | (a & 0x1F));

         nCpstX    = sx + (x << 3);
         nCpstY    = sy + (y << 3);
         nCpstTile = t;
         nCpstFlip = (a >> 5) & 3;

         nCpstType = CTT_8X8;

         // Don't need to clip except around the border
         if (x < 0 || x >= 48 - 1 || nClipY)
            nCpstType |= CTT_CARE;

         if (CpstOneDoX[2]())
            nKnowBlank = t;
      }
   }
	return 0;
}

INT32 Cps2Scr3Draw(UINT8 *Base, INT32 sx, INT32 sy)
{
	INT32 x, y;
	INT32 iy;
	INT32 nFirstY, nLastY;
	INT32 nKnowBlank = -1; // The tile we know is blank
	INT32 ix = (sx >> 5) + 1;
	sx &= 31;
	sx = 32 - sx;

	iy = (sy >> 5) + 1;
	sy &= 31;

	nLastY = (nEndline + sy) >> 5;
	nFirstY = (nStartline + sy) >> 5;

	sy = 32 - sy;

	for (y = nFirstY - 1; y < nLastY; y++)
   {
      INT32 nClipY = ((y << 5) < nStartline) | (((y << 5) + 32) >= nEndline);
      for (x = -1; x < 12; x++)
      {
         INT32 t, a;
         UINT16 *pst;
         INT32 fx, fy, p;
         fx = ix + x;
         fy = iy + y;									// 0 <= fx/fy <= 63

         // Find tile address
         p = ((fy & 0x38) << 8) | ((fx & 0x3F) << 5) | ((fy & 0x07) << 2);
         p &= 0x3FFF;
         pst = (UINT16 *)(Base + p);

         t = BURN_ENDIAN_SWAP_INT16(pst[0]);

         if(Xmcota && t>=0x5800)      t-=0x4000;
         else if(Ssf2t && t<0x5600)   t+=0x4000;
         t <<= 9;										// Get real tile address
         t += nCpsGfxScroll[3];							// add on offset to scroll tiles

         if (t == nKnowBlank) 
            continue;

         /* Draw tile */

         a = BURN_ENDIAN_SWAP_INT16(pst[1]);

         CpstSetPal(0x60 | (a & 0x1F));

         nCpstX    = sx + (x << 5);
         nCpstY    = sy + (y << 5);
         nCpstTile = t;
         nCpstFlip = (a >> 5) & 3;
         nCpstType = CTT_32X32;

         // Don't need to clip except around the border
         if (x < 0 || x >= 12 - 1 || nClipY)
            nCpstType |= CTT_CARE;

         if (CpstOneDoX[2]())
            nKnowBlank = t;
      }
   }
	return 0;
}

