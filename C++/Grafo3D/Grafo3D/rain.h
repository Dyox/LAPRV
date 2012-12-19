typedef struct
{
	float xt,yt,zt;  //coordenadas extremo superior
	float xd,yd,zd;  //coordenadas extremo inferior
	float xv,yv,zv;  //velocidad en cada eje
	float visib;     //visibilidad para el canal alpha
}GOTA;

typedef struct
{   
	float fade;		
	int   x,y,z;    //coordenadas del cubo que va a contener la lluvia
	float grosor;   //grosor de la lluvia
	float longitud; //longitud de las gotas
	float xg,yg,zg;  //gravedad en cada eje
	GOTA *gotas; 
}LLUVIA;

void InicializarLLuvia(LLUVIA &rain, int numgotas);

void DibujarLLuvia(LLUVIA &rain, int numgotas);