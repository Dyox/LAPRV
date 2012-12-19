#include <windows.h>
#include <gl\gl.h>		
#include <math.h>
#include "Neve.h"

void IniciarNeve(NEVE &snow, int numflocos)
{
	snow.x=100;
	snow.y=50;
	snow.z=100;
	snow.xg=0.0f;
	snow.yg=-0.002f;
	snow.zg=0.0f;
	snow.fade=snow.yg*-10;
	snow.longitud=-snow.yg*500;
	snow.flocos=new FLOCO[numflocos];
	for (int i=0; i<numflocos;i++)
	{
		snow.flocos[i].visib=0.0f;
		snow.flocos[i].xd=float(((rand()%(snow.x*20))-snow.x*10.0f)/10.0f);
		snow.flocos[i].yd=1.0;
		snow.flocos[i].zd=float(((rand()%(snow.z*20))-(snow.z)*10.0f)/10.0f);
		snow.flocos[i].xt=snow.flocos[i].xd;
		snow.flocos[i].yt=1.0;
		snow.flocos[i].zt=snow.flocos[i].zd;
		snow.flocos[i].xv=0.0f;
		snow.flocos[i].yv=(rand()%1000)/-10000.0f;
		snow.flocos[i].zv=0.0f;
	}							
}

void CairNeve(NEVE &snow, int numflocos)
{
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

		for(int i=0;i<numflocos;i++)
		{
			glBegin(GL_POINTS);
				glVertex3f(snow.flocos[i].xd,snow.flocos[i].yd,snow.flocos[i].zd);
				glVertex3f(snow.flocos[i].xt,snow.flocos[i].yt,snow.flocos[i].zt);
			glEnd();
			snow.flocos[i].visib+=snow.fade;
			snow.flocos[i].xd+=snow.flocos[i].xv;
			snow.flocos[i].xt+=snow.flocos[i].xv-snow.flocos[i].xv*0.01f;
			snow.flocos[i].xv+=snow.xg;
			snow.flocos[i].yd+=snow.flocos[i].yv;
			snow.flocos[i].yt+=snow.flocos[i].yv;
			snow.flocos[i].yv+=snow.yg;
			snow.flocos[i].zd+=snow.flocos[i].zv;
			snow.flocos[i].zt+=snow.flocos[i].zv-snow.flocos[i].zv*0.01f;
			snow.flocos[i].zv+=snow.zg;

			if (snow.flocos[i].yt<-1)
			{	snow.flocos[i].visib=0.0f;
				snow.flocos[i].xd=float(((rand()%(snow.x*20))-snow.x*10.0f)*0.1f);
				snow.flocos[i].yd=float(snow.y);
				snow.flocos[i].zd=float(((rand()%(snow.z*20))-(snow.z)*10.0f)*0.1f);
				snow.flocos[i].xt=snow.flocos[i].xd;
				snow.flocos[i].yt=snow.flocos[i].yd+snow.longitud;
				snow.flocos[i].zt=snow.flocos[i].zd;
				snow.flocos[i].xv=0.0f;
				snow.flocos[i].yv=(rand()%1000)*(-0.001f);
				snow.flocos[i].zv=0.0f;
			}
		}
	glDisable(GL_BLEND);
}
