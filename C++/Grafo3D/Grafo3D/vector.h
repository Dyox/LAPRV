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
      (10/02/00)  
         - took out the vec4_t, i never use it
      (09/27/00)
         - misc cleaning
      (09/26/00)
         - started to add non-vec3_t returning stuff for + - / * etc
      (09/09/00)
         - added invert, need to clean up this code
      (08/11/00)
         - added Set(vec3_t &p)
      (07/15/00)
         - now return ref on += -= *= etc, ok?
   TODO
      - clean up
*/
#ifndef __VEC3T__
#define __VEC3T__

#include <math.h>

// i doubt i need anymore than this
typedef float vec2_t[2];

struct vec3_t
{
   // constructors
   vec3_t() {v[0] = v[1] = v[2] = 0;}
   vec3_t(float px, float py, float pz) {v[0] = px; v[1] = py; v[2] = pz;}
   vec3_t(const vec3_t &pVec)
    {v[0] = pVec.v[0]; v[1] = pVec.v[1]; v[2] = pVec.v[2];}
   vec3_t(const float *pVec) {v[0] = pVec[0]; v[1] = pVec[1]; v[2] = pVec[2];}

   // assign / equality / greater / less / etc
   vec3_t operator=(const vec3_t &pVec)
    {return vec3_t(v[0] = pVec.v[0], v[1] = pVec.v[1], v[2] = pVec.v[2]);}
   vec3_t operator=(const float *ptr)
    {return vec3_t(v[0] = ptr[0], v[1] = ptr[1], v[2] = ptr[2]);}
   bool operator==(const vec3_t &pVec)
    {return (v[0] == pVec.v[0] && v[1] == pVec.v[1] && v[2] == pVec.v[2]);}
   bool operator==(const float *pVec)
    {return (v[0] == pVec[0] && v[1] == pVec[1] && v[2] == pVec[2]);}
   inline bool operator!=(const vec3_t &pVec)
    {return !((*this) == pVec);}
   inline bool operator!=(const float *pVec)
    {return !(pVec == (*this));}
   bool operator<(const vec3_t vec)
    {return ((v[0] < vec[0]) && (v[1] < vec[1]) && (v[2] < vec[2]));}
   bool operator<=(const vec3_t vec)
    {return ((v[0] <= vec[0]) && (v[1] <= vec[1]) && (v[2] <= vec[2]));}
   bool operator>(const vec3_t vec)
    {return ((v[0] > vec[0]) && (v[1] > vec[1]) && (v[2] > vec[2]));}
   bool operator>=(const vec3_t vec)
    {return ((v[0] >= vec[0]) && (v[1] >= vec[1]) && (v[2] >= vec[2]));}

   // indexing into the array, no bound checks
   const float &operator[](int ndx) const {return v[ndx];}
   float &operator[](int ndx)             {return v[ndx];}
   operator float*(void)                  {return v;}

   // + - / * operations
   vec3_t &operator+=(const vec3_t &pVec) {*this = *this + pVec; return *this;}
   vec3_t &operator-=(const vec3_t &pVec) {*this = *this - pVec; return *this;}
   vec3_t &operator*=(const vec3_t &pVec) {*this = *this * pVec; return *this;}
   vec3_t &operator*=(float val)          {*this = *this * val; return *this;}
   vec3_t &operator/=(const vec3_t &pVec) {*this = *this / pVec; return *this;}
   vec3_t &operator/=(float val)          {*this = *this / val; return *this;}

   vec3_t operator+(const vec3_t &pVec)
    {return vec3_t(v[0] + pVec.v[0], v[1] + pVec.v[1], v[2] + pVec.v[2]);}
   vec3_t operator-(const vec3_t &pVec)
    {return vec3_t(v[0] - pVec.v[0], v[1] - pVec.v[1], v[2] - pVec.v[2]);}
   vec3_t operator*(const vec3_t &pVec)
    {return vec3_t(v[0] * pVec.v[0], v[1] * pVec.v[1], v[2] * pVec.v[2]);}
   vec3_t operator*(float val)
    {return vec3_t(v[0] * val, v[1] * val, v[2] * val);}
   friend vec3_t operator*(float val, const vec3_t &v)
    {return vec3_t(v[0] * val, v[1] * val, v[2] * val);}
   vec3_t operator/(const vec3_t &pVec)  
    {return vec3_t(v[0] / pVec.v[0], v[1] / pVec.v[1], v[2] / pVec.v[2]);}
   vec3_t operator/(float val)
    {return vec3_t(v[0] / val, v[1] / val, v[2] / val);}
   vec3_t operator-(void) {return vec3_t(-v[0], -v[1], -v[2]);}

   // + - * / operations that don't return a vec3_t
   void Clear(void)                    {v[0] = v[1] = v[2] = 0;}
   void Set(float x, float y, float z) {v[0] = x; v[1] = y; v[2] = z;}
   void Set(vec3_t &p)                 {v[0] = p[0]; v[1] = p[1]; v[2] = p[2];}
   void Add(vec3_t &a, vec3_t &b)
    {v[0] = a.v[0] + b.v[0]; v[1] = a.v[1] + b.v[1]; v[2] = a.v[2] + b.v[2];}
   void Add(vec3_t &a)
    {v[0] += a.v[0]; v[1] += a.v[1]; v[2] += a.v[2];}
   void Subtract(vec3_t &a, vec3_t &b)
    {v[0] = a.v[0] - b.v[0]; v[1] = a.v[1] - b.v[1]; v[2] = a.v[2] - b.v[2];}
   void Subtract(vec3_t &a)
    {v[0] -= a.v[0]; v[1] -= a.v[1]; v[2] -= a.v[2];}
   void Multiply(vec3_t &a, vec3_t &b)
    {v[0] = a.v[0] * b.v[0]; v[1] = a.v[1] * b.v[1]; v[2] = a.v[2] * b.v[2];}
   void Multiply(vec3_t &a)
    {v[0] *= a.v[0]; v[1] *= a.v[1]; v[2] *= a.v[2];}
   void Divide(vec3_t &a, vec3_t &b)
    {v[0] = a.v[0] / b.v[0]; v[1] = a.v[1] / b.v[1]; v[2] = a.v[2] / b.v[2];}
   void Divide(vec3_t &a)
    {v[0] /= a.v[0]; v[1] /= a.v[1]; v[2] /= a.v[2];}
   void Scale(float val)
    {v[0] *= val; v[1] *= val; v[2] *= val;}
   void Fabs(vec3_t &src) {v[0] = (float) fabs(src.v[0]);
    v[1] = (float) fabs(src.v[1]); v[2] = (float) fabs(src.v[2]);}
   void Fabs(void) {v[0] = (float) fabs(v[0]); v[1] = (float) fabs(v[1]);
    v[2] = (float) fabs(v[2]);}

   // misc garbage
   void Normalize(void);
   float Length(void);
   float Dot(const vec3_t &pVec)
    {return v[0] * pVec.v[0] + v[1] * pVec.v[1] + v[2] * pVec.v[2];}
   void Cross(const vec3_t &p, const vec3_t &q);
   void Clamp(float min, float max);

   float GetDistance(const vec3_t &dest);

   void RotateX(float amnt, vec3_t &dest);
   void RotateY(float amnt, vec3_t &dest);
   void RotateZ(float amnt, vec3_t &dest);

protected:
   float v[3];
};

inline void vec3_t::Normalize(void) 
{
	float length, len = 0;

	length = Length();

	if (length == 0)
		return;

	len = 1.0f / length;

	v[0] *= len;
	v[1] *= len;
	v[2] *= len;
}

inline float vec3_t::Length(void) 
{
   double length = (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]);
	
	return (float) sqrt(length);
}

inline void vec3_t::Cross(const vec3_t &p, const vec3_t &q)
{
	v[0] = (p.v[1] * q.v[2]) - (p.v[2] * q.v[1]);
	v[1] = (p.v[2] * q.v[0]) - (p.v[0] * q.v[2]);
	v[2] = (p.v[0] * q.v[1]) - (p.v[1] * q.v[0]);
}

// !!TODO this sucks, fix it
inline void vec3_t::Clamp(float min, float max)
{
   if (v[0] > max)
      v[0] = v[0] - max;
   if (v[0] < min)
      v[0] = min - v[0];
   if (v[1] > max)
      v[1] = v[1] - max;
   if (v[1] < min)
      v[1] = min - v[1];
   if (v[2] > max)
      v[2] = v[2] - max;
   if (v[2] < min)
      v[2] = min - v[2];
}

inline float vec3_t::GetDistance(const vec3_t &dest)
{
   float d1 = dest[0] - v[0];
   float d2 = dest[1] - v[1];
   float d3 = dest[2] - v[2];
   
   return (float) sqrt((d1 * d1) + (d2 * d2) + (d3 * d3));
}

inline void vec3_t::RotateX(float amnt, vec3_t &dest)
{
   float s = mLibSin(amnt);
   float c = mLibCos(amnt);
   float y = v[1];
   float z = v[2];

   dest[0] = v[0];
   dest[1] = (y * c) - (z * s);
   dest[2] = (y * s) + (z * c);
}

inline void vec3_t::RotateY(float amnt, vec3_t &dest)
{
   float s = mLibSin(amnt);
   float c = mLibCos(amnt);
   float x = v[0];
   float z = v[2];

   dest[0] = (x * c) + (z * s);
   dest[1] = v[1];
   dest[2] = (z * c) - (x * s);
}

inline void vec3_t::RotateZ(float amnt, vec3_t &dest)
{
   float s = mLibSin(amnt);
   float c = mLibCos(amnt);
   float x = v[0];
   float y = v[1];

   dest[0] = (x * c) - (y * s);
   dest[1] = (y * c) + (x * s);
   dest[2] = v[2];
}

#endif