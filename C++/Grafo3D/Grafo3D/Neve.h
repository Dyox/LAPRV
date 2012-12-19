typedef struct
{
	float xt,yt,zt;
	float xd,yd,zd;
	float xv,yv,zv;
	float visib;
}FLOCO;

typedef struct
{   
	float fade;		
	int   x,y,z;
	float longitud;
	float xg,yg,zg;
	FLOCO *flocos; 
}NEVE;

void IniciarNeve(NEVE &snow, int numflocos);

void CairNeve(NEVE &snow, int numflocos);