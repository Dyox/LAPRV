/**************************************
*                                     *
*          Demo Realizada por:        *
*          Javier Barandiaran         *
*   www.geocities.com/opengladiator/  *
*                2002                 *
*                                     *
**************************************/

#include <windows.h>
#include <gl\gl.h>		
#include <math.h>
#include "rain.h"

void InicializarLLuvia(LLUVIA &rain, int numgotas)
{
	rain.grosor=0.4f;
	rain.x=100;
	rain.y=50;
	rain.z=100;
	rain.xg=0.0f;
	rain.yg=-0.002f;
	rain.zg=0.0f;
	rain.fade=rain.yg*-10;
	rain.longitud=-rain.yg*500;
	rain.gotas=new GOTA[numgotas];
	for (int i=0; i<numgotas;i++)
	{
		rain.gotas[i].visib=0.0f;
		rain.gotas[i].xd=float(((rand()%(rain.x*20))-rain.x*10.0f)/10.0f);
		rain.gotas[i].yd=1.0;
		rain.gotas[i].zd=float(((rand()%(rain.z*20))-(rain.z)*10.0f)/10.0f);
		rain.gotas[i].xt=rain.gotas[i].xd;
		rain.gotas[i].yt=1.0;
		rain.gotas[i].zt=rain.gotas[i].zd;
		rain.gotas[i].xv=0.0f;
		rain.gotas[i].yv=(rand()%1000)/-10000.0f;
		rain.gotas[i].zv=0.0f;
	}
}

void DibujarLLuvia(LLUVIA &rain, int numgotas)
{
	glDisable(GL_LIGHTING);
	glLineWidth(rain.grosor);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
		for(int i=0;i<numgotas;i++)
		{	glBegin(GL_LINES);
				//glColor4f(0.2f,0.2f,0.2f,rain.gotas[i].visib);
				glVertex3f(rain.gotas[i].xd,rain.gotas[i].yd,rain.gotas[i].zd);
				//glColor4f(0.1f,0.1f,0.2f,rain.gotas[i].visib-0.1f);
				glVertex3f(rain.gotas[i].xt,rain.gotas[i].yt,rain.gotas[i].zt);
			
			glEnd();
			
			rain.gotas[i].visib+=rain.fade;
			rain.gotas[i].xd+=rain.gotas[i].xv;
			rain.gotas[i].xt+=rain.gotas[i].xv-rain.gotas[i].xv*0.01f;
			rain.gotas[i].xv+=rain.xg;
			rain.gotas[i].yd+=rain.gotas[i].yv;
			rain.gotas[i].yt+=rain.gotas[i].yv;
			rain.gotas[i].yv+=rain.yg;
			rain.gotas[i].zd+=rain.gotas[i].zv;
			rain.gotas[i].zt+=rain.gotas[i].zv-rain.gotas[i].zv*0.01f;
			rain.gotas[i].zv+=rain.zg;

			if (rain.gotas[i].yt<-1)
			{	rain.gotas[i].visib=0.0f;
				rain.gotas[i].xd=float(((rand()%(rain.x*20))-rain.x*10.0f)*0.1f);
				rain.gotas[i].yd=float(rain.y);
				rain.gotas[i].zd=float(((rand()%(rain.z*20))-(rain.z)*10.0f)*0.1f);
				rain.gotas[i].xt=rain.gotas[i].xd;
				rain.gotas[i].yt=rain.gotas[i].yd+rain.longitud;
				rain.gotas[i].zt=rain.gotas[i].zd;
				rain.gotas[i].xv=0.0f;
				rain.gotas[i].yv=(rand()%1000)*(-0.001f);
				rain.gotas[i].zv=0.0f;
			}

		}
	glDisable(GL_BLEND);
}
