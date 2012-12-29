/*
   Copyright (C) 2000 Nate Miller nkmiller@calpoly.edu

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

   See gpl.txt for more information regarding the GNU General Public License.
*/
/*
   WORKLOG

   TODO  
      - make this code not suck
*/
#ifndef __RANDH__
#define __RANDH__

#include "utility.h"
#include <time.h>

struct random_t
{
   static void Init(void) {srand(time(0));}
   static int Random(void) {return rand();}
   static inline float RandomRange(float lo, float hi);
};

inline float random_t::RandomRange(float lo, float hi)
{
   int r = rand();
   float	x = (float)(r & 0x7fff) / (float)0x7fff;
   return (x * (hi - lo) + lo);
}

#endif