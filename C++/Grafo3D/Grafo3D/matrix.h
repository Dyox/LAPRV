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
#ifndef __MATRIXH__
#define __MATRIXH__

#define MATRIX
#include "mathlib.h"
#include <memory.h>

struct matrix_t
{
   matrix_t() {Identity();}
   float *Get(void) {return m;}
   void Set(float *src) {memcpy(m, src, sizeof(float) * 16);}
   void Clear(void) {memset(m, 0, sizeof(float) * 16);}
   inline void Identity(void);
   inline void Transpose(matrix_t &dest);
   inline matrix_t operator=(const matrix_t &src);
   inline matrix_t operator+(const matrix_t &src);  
   inline matrix_t operator-(const matrix_t &src);
   inline void operator+=(const matrix_t &src);  
   inline void operator-=(const matrix_t &src);   
   matrix_t operator*(const matrix_t &src);
   void operator*=(const matrix_t &src);  
   float &operator[](const int ndx) {return m[ndx];}
   void Rotate(float angle, vec3_t vec);
   inline void Translate(vec3_t vec);
   inline void Translate(float x, float y, float z);
   inline vec3_t operator*(vec3_t vec);
   inline friend vec3_t operator*(vec3_t vec, matrix_t &mat);
   void RotateX(float angle);
   void RotateY(float angle);
   void RotateZ(float angle);
   operator float*(void) {return m;}
   // test
   bool Inverse(matrix_t &inv);
protected:
   float m[16];
};

inline void matrix_t::Identity(void)
{
   m[0] = m[5] = m[10] = m[15] = 1.0f;
   m[1] = m[2] = m[3] = m[4] = m[6] = m[7] = m[8] = m[9] = 
    m[11] = m[12] = m[13] = m[14] = 0.0f;
}

inline void matrix_t::Transpose(matrix_t &dest)
{
   dest.m[0] = m[0]; dest.m[1] = m[4]; dest.m[2] = m[8]; dest.m[3] = m[12];
   dest.m[4] = m[1]; dest.m[5] = m[5]; dest.m[6] = m[9]; dest.m[7] = m[13];
   dest.m[8] = m[2]; dest.m[9] = m[6]; dest.m[10] = m[10]; dest.m[11] = m[14];
   dest.m[12] = m[3]; dest.m[13] = m[7]; dest.m[14] = m[11]; dest.m[15] = m[15];
}

inline matrix_t matrix_t::operator=(const matrix_t &src)
{
   for (int i = 0; i < 16; i++)
      m[i] = src.m[i];
   return (*this);
}

inline matrix_t matrix_t::operator+(const matrix_t &src)
{
   matrix_t ret;

   ret.m[0] = m[0] + src.m[0]; ret.m[1] = m[1] + src.m[1];
   ret.m[2] = m[2] + src.m[2]; ret.m[3] = m[3] + src.m[3];
   ret.m[4] = m[4] + src.m[4]; ret.m[5] = m[5] + src.m[5];
   ret.m[6] = m[6] + src.m[6]; ret.m[7] = m[7] + src.m[7];
   ret.m[8] = m[8] + src.m[8]; ret.m[9] = m[9] + src.m[9];
   ret.m[10] = m[10] + src.m[10]; ret.m[11] = m[11] + src.m[11];
   ret.m[12] = m[12] + src.m[12]; ret.m[13] = m[13] + src.m[13];
   ret.m[14] = m[14] + src.m[14]; ret.m[15] = m[15] + src.m[15];

   return ret;
}

inline matrix_t matrix_t::operator-(const matrix_t &src)
{
   matrix_t ret;

   ret.m[0] = m[0] - src.m[0]; ret.m[1] = m[1] - src.m[1];
   ret.m[2] = m[2] - src.m[2]; ret.m[3] = m[3] - src.m[3];
   ret.m[4] = m[4] - src.m[4]; ret.m[5] = m[5] - src.m[5];
   ret.m[6] = m[6] - src.m[6]; ret.m[7] = m[7] - src.m[7];
   ret.m[8] = m[8] - src.m[8]; ret.m[9] = m[9] - src.m[9];
   ret.m[10] = m[10] - src.m[10]; ret.m[11] = m[11] - src.m[11];
   ret.m[12] = m[12] - src.m[12]; ret.m[13] = m[13] - src.m[13];
   ret.m[14] = m[14] - src.m[14]; ret.m[15] = m[15] - src.m[15];

   return ret;
}

inline void matrix_t::operator+=(const matrix_t &src)
{
   (*this) = (*this) + src;
}

inline void matrix_t::operator-=(const matrix_t &src)
{
   (*this) = (*this) - src;
}

inline void matrix_t::Translate(vec3_t vec)
{
   m[12] = m[0] * vec[0] + m[4] * vec[1] + m[8]  * vec[2] + m[12];
   m[13] = m[1] * vec[0] + m[5] * vec[1] + m[9]  * vec[2] + m[13];
   m[14] = m[2] * vec[0] + m[6] * vec[1] + m[10] * vec[2] + m[14];
   m[15] = m[3] * vec[0] + m[7] * vec[1] + m[11] * vec[2] + m[15];
}

inline void matrix_t::Translate(float x, float y, float z)
{
   m[12] = m[0] * x + m[4] * y + m[8]  * z + m[12];
   m[13] = m[1] * x + m[5] * y + m[9]  * z + m[13];
   m[14] = m[2] * x + m[6] * y + m[10] * z + m[14];
   m[15] = m[3] * x + m[7] * y + m[11] * z + m[15];
}

// 0  4  8  12
// 1  5  9  13
// 2  6  10 14
// 3  7  11 15
inline vec3_t matrix_t::operator*(vec3_t vec)
{
   return vec3_t(
    vec[0] * m[0] + vec[1] * m[4] + vec[2] * m[8] + m[12],
    vec[0] * m[1] + vec[1] * m[5] + vec[2] * m[9] + m[13],
    vec[0] * m[2] + vec[1] * m[6] + vec[2] * m[10] + m[14]);
}

inline vec3_t operator*(vec3_t vec, matrix_t &mat)
{
   return vec3_t(mat * vec);
}

#endif