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
      - this needs to be a lot better, sucks currently
*/
#ifndef __TICKERH__
#define __TICKERH__

#pragma comment(lib, "winmm.lib") // blah, but it works...

#include "utility.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>

struct ticker_t
{  
   void Reset(void)    {start = timeGetTime();}
   uint PassedI(void)  {return (timeGetTime() - start);}
   double Passed(void) {return ((timeGetTime() - start) / 1000.0);}

protected:
   DWORD start;
};

#endif