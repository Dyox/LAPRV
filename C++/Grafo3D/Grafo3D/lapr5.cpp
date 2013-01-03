#define _USE_MATH_DEFINES
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL\glut.h>
#include <gl\GLAux.h>
#include <iostream>
//#include <cstring>
//#include <limits>
#include "mathlib.h"
//#include "mathlib2.h"
//#include <sstream>
#include "studio.h"
//#include "mdlviewer.h"
//#include "Model_3DS.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "TextureLoader.h"
#include <algorithm>
#include "grafos.h"
#include "glfont.h"
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include "schema.xsd.h"

/*//musica
#include <al.h>
#include <alut.h>
*/
#include "atlstr.h"

//Ceu
#include "SkyDome.h"
/*
//Neve
#include "Neve.h"

//chuva
#include "rain.h"
*/
//texto
//#include "font.h"

using namespace std;

#pragma comment (lib, "glaux.lib")    /* link with Win32 GLAUX lib usada para ler bitmaps */
#pragma comment (lib, "OpenAL32.lib")
#pragma comment (lib, "alut.lib")
#pragma comment (user, "Compiled on " __DATE__ " at " __TIME__)
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

// função para ler jpegs do ficheiro readjpeg.c
extern "C" int read_JPEG_file(char *, char **, int *, int *, int *);

#define DEBUG_PICKING true
#define DEBUG_CAMERA true
#define graus(X) (double)((X)*180/M_PI)
#define rad(X)   (double)((X)*M_PI/180)
#define AVATAR "http://imagens.filmes3d.com/2009/setembro/av6.jpg"
#define CONTENTE "Texturas/contente.bmp"
#define ESTRELAS "Texturas/stars.jpg"
#define TEXT_LOGIN "Texturas/login.jpg"
#define NUM_TEXTURAS 80
#define CENA_LOGIN 1
#define CENA_LOADING 2
#define CENA_GRAFO 3
//#define DIMENSAO_CAMARA 500

// luzes e materiais
const GLfloat mat_ambient[][4] = {{0.33, 0.22, 0.03, 1.0},	// brass
								  {0.0, 0.0, 0.0},			// red plastic
								  {0.0215, 0.1745, 0.0215},	// emerald
								  {0.02, 0.02, 0.02},		// slate
								  {0.0, 0.0, 0.1745},		// azul
								  {0.02, 0.02, 0.02},		// preto
								  {0.1745, 0.1745, 0.1745}};// cinza

const GLfloat mat_diffuse[][4] = {{0.78, 0.57, 0.11, 1.0},		// brass
								  {0.5, 0.0, 0.0},				// red plastic
								  {0.07568, 0.61424, 0.07568},	// emerald
								  {0.78, 0.78, 0.78},			// slate
								  {0.0, 0.0,  0.61424},			// azul
								  {0.08, 0.08, 0.08},			// preto
								  {0.61424, 0.61424, 0.61424}};	// cinza

const GLfloat mat_specular[][4] = {{0.99, 0.91, 0.81, 1.0},			// brass
								   {0.7, 0.6, 0.6},					// red plastic
								   {0.633, 0.727811, 0.633},		// emerald
								   {0.14, 0.14, 0.14},				// slate
								   {0.0, 0.0, 0.727811},			// azul
								   {0.03, 0.03, 0.03},				// preto
								   {0.727811, 0.727811, 0.727811}};	// cinza

const GLfloat mat_shininess[] = {27.8,	// brass
								 32.0,	// red plastic
								 76.8,	// emerald
								 18.78,	// slate
								 30.0,	// azul
								 75.0,	// preto
								 60.0};	// cinza

enum tipo_material {brass, red_plastic, emerald, slate, azul, preto, cinza};

#ifdef __cplusplus
	inline tipo_material operator++(tipo_material &rs, int ) {
		return rs = (tipo_material)(rs + 1);
	}
#endif

typedef	GLdouble Vertice[3];
typedef	GLdouble Vector[4];


typedef struct Camera{
	GLfloat fov;
	GLdouble dir_lat;
	GLdouble dir_long;
	GLfloat dist;
	Vertice center;

}Camera;

typedef struct Estado{
	Camera		camera;
	int			xMouse,yMouse;
	GLboolean	light;
	GLboolean	apresentaNormais;
	GLint		lightViewer;
	GLint		eixoTranslaccao;
	GLdouble	eixo[3];
	GLint		itemSeleccionado;
	GLint		itemCursor;
	GLint		tempo;
	GLint		cena;
}Estado;

typedef struct Modelo {
	#ifdef __cplusplus
		tipo_material cor_cubo;
	#else
		enum tipo_material cor_cubo;
	#endif

	GLfloat g_pos_luz1[4];
	GLfloat g_pos_luz2[4];

	GLfloat escala;
	GLUquadric *quad;
}Modelo;

Estado estado;
Modelo modelo;
TextureLoader *apTexLoad = new TextureLoader();
glTexture avatar;
glTexture contente;
glTexture estrelas;
glTexture text_login;
GLuint        texID[NUM_TEXTURAS];

AUX_RGBImageRec *LoadBMP(char *Filename)				// Loads A Bitmap Image
{
	FILE *File=NULL;									// File Handle

	if (!Filename)										// Make Sure A Filename Was Given
	{
		return NULL;									// If Not Return NULL
	}

	File=fopen(Filename,"r");							// Check To See If The File Exists

	if (File)											// Does The File Exist?
	{
		fclose(File);									// Close The Handle
		return auxDIBImageLoad(Filename);				// Load The Bitmap And Return A Pointer
	}

	return NULL;										// If Load Failed Return NULL
}
void createTextures(GLuint texID[])
{
	AUX_RGBImageRec *TextureImage[1];					// Create Storage Space For The Texture
	char *image;
	int w, h, bpp;

	glGenTextures(NUM_TEXTURAS,texID);

	memset(TextureImage,0,sizeof(void *)*1);           	// Set The Pointer To NULL
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	apTexLoad->SetHighQualityTextures(TRUE);
	apTexLoad->SetTextureFilter(txTrilinear);

	apTexLoad->LoadTextureFromDisk(AVATAR,&avatar);
	apTexLoad->LoadTextureFromDisk(CONTENTE,&contente);
	apTexLoad->LoadTextureFromDisk(ESTRELAS,&estrelas);
	apTexLoad->LoadTextureFromDisk(TEXT_LOGIN,&text_login);
	/*
	//relva
	if(	read_JPEG_file(TEXTURA_RELVA, &image, &w, &h, &bpp))
	{
		glBindTexture(GL_TEXTURE_2D, texID[ID_TEXTURA_RELVA]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST );
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, h, GL_RGB, GL_UNSIGNED_BYTE, image);
	}else{
		printf("Textura %s not Found\n",TEXTURA_RELVA);
		exit(0);
	}*/
	glBindTexture(GL_TEXTURE_2D, NULL);
	
}

void initEstado(){
	estado.camera.dir_lat=0/*M_PI/8*/;
	estado.camera.dir_long=0/*-M_PI/4*/;
	estado.camera.fov=60;
	estado.camera.dist=1;
	estado.eixo[0]=0;
	estado.eixo[1]=0;
	estado.eixo[2]=0;
	estado.camera.center[0]=0;
	estado.camera.center[1]=0;
	estado.camera.center[2]=0;
	estado.light=GL_FALSE;
	estado.apresentaNormais=GL_FALSE;
	estado.lightViewer=1;
}

void initModelo(){
	modelo.escala=0.2;

	modelo.cor_cubo = brass;
	modelo.g_pos_luz1[0]=-5.0;
	modelo.g_pos_luz1[1]= 5.0;
	modelo.g_pos_luz1[2]= 5.0;
	modelo.g_pos_luz1[3]= 0.0;
	modelo.g_pos_luz2[0]= 5.0;
	modelo.g_pos_luz2[1]= -15.0;
	modelo.g_pos_luz2[2]= 5.0;
	modelo.g_pos_luz2[3]= 0.0;
}

void setProjection(int x, int y, GLboolean picking){
    glLoadIdentity();
	if (picking) { // se está no modo picking, lê viewport e define zona de picking
		GLint vport[4];
		glGetIntegerv(GL_VIEWPORT, vport);
		gluPickMatrix(x, glutGet(GLUT_WINDOW_HEIGHT)  - y, 4, 4, vport); // Inverte o y do rato para corresponder à jana
	}
	    
	gluPerspective(estado.camera.fov,(GLfloat)glutGet(GLUT_WINDOW_WIDTH) /glutGet(GLUT_WINDOW_HEIGHT) ,0.1,500);
	//glOrtho(-DIMENSAO_CAMARA / 2.0, DIMENSAO_CAMARA / 2.0,-DIMENSAO_CAMARA / 2.0, DIMENSAO_CAMARA / 2.0,0.0, DIMENSAO_CAMARA / 2.0 + 1);

}

void myReshape(int w, int h){	
	glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	setProjection(0,0,GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
}

void myInit()
{
	makeRasterFont();
	GLfloat LuzAmbiente[]={0.5,0.5,0.5, 0.0};

	glClearColor (0.0, 0.0, 0.0, 0.0);

	glEnable(GL_SMOOTH); /*enable smooth shading */
	glEnable(GL_LIGHTING); /* enable lighting */
	glEnable(GL_DEPTH_TEST); /* enable z buffer */
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE); 

	glDepthFunc(GL_LESS);

	estado.lightViewer=1;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente); 
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado.lightViewer); 
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); 

	initModelo();
	initEstado();
	modelo.quad=gluNewQuadric();
	gluQuadricDrawStyle(modelo.quad, GLU_FILL);
	gluQuadricNormals(modelo.quad, GLU_OUTSIDE);

	estado.cena=CENA_LOGIN;
	estado.itemSeleccionado=-1;

	leGrafo();
}

void imprime_ajuda(void)
{
  printf("\n\nDesenho de um labirinto a partir de um grafo\n");
  printf("h,H - Ajuda \n");
  printf("i,I - Reset dos Valores \n");
  printf("******* Diversos ******* \n");
  printf("l,L - Alterna o calculo luz entre Z e eye (GL_LIGHT_MODEL_LOCAL_VIEWER)\n");
  printf("k,K - Alerna luz de camera com luz global \n");
  printf("s,S - PolygonMode Fill \n");
  printf("w,W - PolygonMode Wireframe \n");
  printf("p,P - PolygonMode Point \n");
  printf("c,C - Liga/Desliga Cull Face \n");
  printf("n,N - Liga/Desliga apresentação das normais \n");
  printf("******* grafos ******* \n");
  printf("F1  - Grava grafo do ficheiro \n");
  printf("F2  - Lê grafo para ficheiro \n");
  printf("F6  - Cria novo grafo\n");
  printf("******* Camera ******* \n");
  printf("Botão esquerdo - Arrastar os eixos (centro da camera)\n");
  printf("Botão direito  - Rodar camera\n");
  printf("Botão direito com CTRL - Zoom-in/out\n");
  printf("PAGE_UP, PAGE_DOWN - Altera distância da camara \n");
  printf("ESC - Sair\n");
}


void material(enum tipo_material mat)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient[mat]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse[mat]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular[mat]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess[mat]);
}

const GLfloat red_light[] = {1.0, 0.0, 0.0, 1.0};
const GLfloat green_light[] = {0.0, 1.0, 0.0, 1.0};
const GLfloat blue_light[] = {0.0, 0.0, 1.0, 1.0};
const GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};


void putLights(GLfloat* diffuse)
{
	const GLfloat white_amb[] = {0.2, 0.2, 0.2, 1.0};

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT0, GL_POSITION, modelo.g_pos_luz1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT1, GL_POSITION, modelo.g_pos_luz2);

	/* desenhar luz */
	//material(red_plastic);
	//glPushMatrix();
	//	glTranslatef(modelo.g_pos_luz1[0], modelo.g_pos_luz1[1], modelo.g_pos_luz1[2]);
	//	glDisable(GL_LIGHTING);
	//	glColor3f(1.0, 1.0, 1.0);
	//	glutSolidCube(0.1);
	//	glEnable(GL_LIGHTING);
	//glPopMatrix();
	//glPushMatrix();
	//	glTranslatef(modelo.g_pos_luz2[0], modelo.g_pos_luz2[1], modelo.g_pos_luz2[2]);
	//	glDisable(GL_LIGHTING);
	//	glColor3f(1.0, 1.0, 1.0);
	//	glutSolidCube(0.1);
	//	glEnable(GL_LIGHTING);
	//glPopMatrix();

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void desenhaSolo(){
#define STEP 10
	glPushMatrix();
		glTranslated(0,0,-2.0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			material(preto);
			for(int i=-300;i<300;i+=STEP)
				for(int j=-300;j<300;j+=STEP){
					glVertex2f(i,j);
					glVertex2f(i+STEP,j);
					glVertex2f(i+STEP,j+STEP);
					glVertex2f(i,j+STEP);
				}
		glEnd();
	glPopMatrix();
}

void CrossProduct (GLdouble v1[], GLdouble v2[], GLdouble cross[])
{
	cross[0] = v1[1]*v2[2] - v1[2]*v2[1];
	cross[1] = v1[2]*v2[0] - v1[0]*v2[2];
	cross[2] = v1[0]*v2[1] - v1[1]*v2[0];
}

GLdouble VectorNormalize (GLdouble v[])
{
	int		i;
	GLdouble	length;

	if ( fabs(v[1] - 0.000215956) < 0.0001)
		i=1;

	length = 0;
	for (i=0 ; i< 3 ; i++)
		length += v[i]*v[i];
	length = sqrt (length);
	if (length == 0)
		return 0;
		
	for (i=0 ; i< 3 ; i++)
		v[i] /= length;	

	return length;
}

void desenhaNormal(GLdouble x, GLdouble y, GLdouble z, GLdouble normal[], tipo_material mat){

	switch (mat){
		case red_plastic:
				glColor3f(1,0,0);
			break;
		case azul:
				glColor3f(0,0,1);
			break;
		case emerald:
				glColor3f(0,1,0);
			break;
		default:
				glColor3f(1,1,0);
	}
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslated(x,y,z);
		glScaled(0.4,0.4,0.4);
		glBegin(GL_LINES);
			glVertex3d(0,0,0);
			glVertex3dv(normal);
		glEnd();
		glPopMatrix();
	glEnable(GL_LIGHTING);
}

void desenhaLigacao(GLfloat xi, GLfloat yi, GLfloat zi, GLfloat xf, GLfloat yf, GLfloat zf, GLfloat largura)
{
	GLdouble v1[3],v2[3],cross[3];
	GLdouble length;
	v1[0]=xf-xi;
	v1[1]=0;
	v2[0]=0;
	v2[1]=yf-yi;

	v1[2]=zf-zi;
	v2[2]=0;
	CrossProduct(v1,v2,cross);
	//printf("cross x=%lf y=%lf z=%lf",cross[0],cross[1],cross[2]);
	length=VectorNormalize(cross);
	//printf("Normal x=%lf y=%lf z=%lf length=%lf\n",cross[0],cross[1],cross[2]);
	GLfloat catx=xf-xi;
	GLfloat caty=yf-yi;
	GLfloat catz=zf-zi;
	GLfloat hipo=sqrt(pow(catx,2)+pow(caty,2));
	GLfloat ang=(acos(caty/hipo)*180)/M_PI;
	GLfloat dist=sqrt(pow(hipo,2)+pow(catz,2));
	GLfloat angz=(atan(catz/hipo)*180)/M_PI;
	glPushMatrix();
		//material(red_plastic);
		glTranslatef(xi,yi,zi+0.2);
		glRotatef(270,1,0,0);
		glRotatef(ang,0,1,0);
		glRotatef(angz,1,0,0);
		gluCylinder(modelo.quad,largura,largura,dist,10,1);
	glPopMatrix();
	if(estado.apresentaNormais) {
		desenhaNormal(xi,yi,zi,cross,red_plastic);
		desenhaNormal(xf,yf-largura,zf,cross,red_plastic);
		desenhaNormal(xf,yf,zf,cross,red_plastic);
		desenhaNormal(xi,yi+largura,zi,cross,red_plastic);
	}
}

void desenhaArco(Arco arco){
	No *noi,*nof;

	if(nos[arco.noi].x==nos[arco.nof].x){
		// arco vertical
		if(nos[arco.noi].y<nos[arco.nof].y){
			if (nos[arco.noi].z>nos[arco.nof].z)
			{
				nof=&nos[arco.noi];
				noi=&nos[arco.nof];
			}
			else
			{
				noi=&nos[arco.noi];
				nof=&nos[arco.nof];
			}
		}else{
			if (nos[arco.noi].z<nos[arco.nof].z)
			{
				noi=&nos[arco.noi];
				nof=&nos[arco.nof];
			}
			else
			{
				nof=&nos[arco.noi];
				noi=&nos[arco.nof];
			}
		}

		desenhaLigacao(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z, arco.largura);
	}else{
		if(nos[arco.noi].y==nos[arco.nof].y){
			//arco horizontal
			if(nos[arco.noi].x<nos[arco.nof].x){
				noi=&nos[arco.noi];
				nof=&nos[arco.nof];
			}else{
				nof=&nos[arco.noi];
				noi=&nos[arco.nof];
			}
			desenhaLigacao(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z, arco.largura);
		}
		else
		{
			if(nos[arco.noi].x<nos[arco.nof].x)
			{
				noi=&nos[arco.noi];
				nof=&nos[arco.nof];
			}
			else
			{
				nof=&nos[arco.noi];
				noi=&nos[arco.nof];
			}
			desenhaLigacao(noi->x,noi->y,noi->z,nof->x,nof->y,nof->z,arco.largura);
		}
	}
}

void desenhaLabirinto(){
	glPushMatrix();
		glTranslatef(0,0,0);
		glScalef(2,2,2);
		material(red_plastic);
		for(int i=0; i<numNos; i++){
			glPushMatrix();
				if (estado.itemSeleccionado==i+1)
				{
					material(emerald);
				}
				else
				{
					material(cinza);
				}
				glTranslatef(nos[i].x,nos[i].y,nos[i].z);
				glPushName(i+1);
					glutSolidSphere(nos[i].largura,10,10);
				glPopName();
			glPopMatrix();
			//desenhaNo(i);
		}
		/*glPushMatrix();
			glTranslatef(0,0,0);
			glScalef(2,2,2);
			glPushMatrix();
				Vertice eye;
				eye[0]=estado.camera.center[0]+estado.camera.dist*cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				eye[1]=estado.camera.center[1]+estado.camera.dist*sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				eye[2]=estado.camera.center[2]+estado.camera.dist*sin(estado.camera.dir_lat);
				material(emerald);
				glTranslatef(estado.camera.center[0],estado.camera.center[1],estado.camera.center[2]);
				glutSolidSphere(5.8,10,10);
			glPopMatrix();
		glPopMatrix();*/
		//material(emerald);
		for(int i=0; i<numArcos; i++)
		{
			if (estado.itemSeleccionado==numNos+1+i)
			{
				material(emerald);
			}
			else
			{
				material(red_plastic);
			}
			glPushName(numNos+1+i);
				desenhaArco(arcos[i]);
			glPopName();
		}
		
	glPopMatrix();
}

void desenhaEixo(){
	gluCylinder(modelo.quad,0.5,0.5,20,16,15);
	glPushMatrix();
		glTranslatef(0,0,20);
		glPushMatrix();
			glRotatef(180,0,1,0);
			gluDisk(modelo.quad,0.5,2,16,6);
		glPopMatrix();
		gluCylinder(modelo.quad,2,0,5,16,15);
	glPopMatrix();
}

#define EIXO_X		1
#define EIXO_Y		2
#define EIXO_Z		3

void desenhaPlanoDrag(int eixo){
	glPushMatrix();
		glTranslated(estado.eixo[0],estado.eixo[1],estado.eixo[2]);
		switch (eixo) {
			case EIXO_Y :
					if(abs(estado.camera.dir_lat)<M_PI/4)
						glRotatef(-90,0,0,1);
					else
						glRotatef(90,1,0,0);
					material(red_plastic);
				break;
			case EIXO_X :
					if(abs(estado.camera.dir_lat)>M_PI/6)
						glRotatef(90,1,0,0);
					material(azul);
				break;
			case EIXO_Z :
					if(abs(cos(estado.camera.dir_long))>0.5)
						glRotatef(90,0,0,1);

					material(emerald);
				break;
		}
		glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glVertex3f(-100,0,-100);
			glVertex3f(100,0,-100);
			glVertex3f(100,0,100);
			glVertex3f(-100,0,100);
		glEnd();
	glPopMatrix();
}

void desenhaEixos(){
	/*
	estado.eixo[0]=estado.camera.center[0];
	estado.eixo[1]=estado.camera.center[1];
	estado.eixo[2]=estado.camera.center[2];
	glPushMatrix();
		glTranslated(estado.eixo[0],estado.eixo[1],estado.eixo[2]);
		material(emerald);
		glPushName(EIXO_Z);
			desenhaEixo();
		glPopName();
		glPushName(EIXO_Y);
			glPushMatrix();
				glRotatef(-90,1,0,0);
				material(red_plastic);
				desenhaEixo();
			glPopMatrix();
		glPopName();
		glPushName(EIXO_X);
			glPushMatrix();
				glRotatef(90,0,1,0);
				material(azul);
				desenhaEixo();
			glPopMatrix();
		glPopName();
	glPopMatrix();
	*/
}

void desenhaHUD(int width, int height){

	if (DEBUG_PICKING)
	{
		//Altera viewport e projecção
		glViewport(0, 0, (GLint) width, (GLint) height);
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluOrtho2D(0,100,100,0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.0,0.0,0.8);
			glRasterPos2i(80, 90);
			char strobj[50]="ID obj sel:";
			char idobj[30];
			itoa(estado.itemSeleccionado,idobj,10);
			strcat(strobj,idobj);
			printString(strobj);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		myReshape((GLint) width, (GLint) height);
	}

	if (DEBUG_CAMERA)
	{
		Vertice eye;
		eye[0]=estado.camera.center[0]+estado.camera.dist*cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
		eye[1]=estado.camera.center[1]+estado.camera.dist*sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
		eye[2]=estado.camera.center[2]+estado.camera.dist*sin(estado.camera.dir_lat);

		//Altera viewport e projecção
		glViewport(0, 0, (GLint) width, (GLint) height);
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluOrtho2D(0,100,100,0);
		glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.0,0.0,0.8);
			glRasterPos2i(5, 90);
			char strobj[50]="eye.x=";
			string coord;          // string which will contain the result
			ostringstream xpto;   // stream used for the conversion
			xpto << eye[0];      // insert the textual representation of 'Number' in the characters in the stream
			coord = xpto.str(); // set 'Result' to the contents of the stream
			char *c=new char[coord.size()+1];
			c[coord.size()]=0;
			memcpy(c,coord.c_str(),coord.size());
			strcat(strobj,c);
			printString(strobj);

			glRasterPos2i(5, 92);
			char strobj2[50]="eye.y=";
			//string coord;          // string which will contain the result
			ostringstream xpto2;   // stream used for the conversion
			xpto2 << eye[1];      // insert the textual representation of 'Number' in the characters in the stream
			coord = xpto2.str(); // set 'Result' to the contents of the stream
			c=new char[coord.size()+1];
			c[coord.size()]=0;
			memcpy(c,coord.c_str(),coord.size());
			strcat(strobj2,c);
			printString(strobj2);

			glRasterPos2i(5, 94);
			char strobj3[50]="eye.z=";
			//string coord;          // string which will contain the result
			ostringstream xpto3;   // stream used for the conversion
			xpto3 << eye[2];      // insert the textual representation of 'Number' in the characters in the stream
			coord = xpto3.str(); // set 'Result' to the contents of the stream
			c=new char[coord.size()+1];
			c[coord.size()]=0;
			memcpy(c,coord.c_str(),coord.size());
			strcat(strobj3,c);
			printString(strobj3);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		myReshape((GLint) width, (GLint) height);
	}

	if ((estado.itemCursor<=numNos) && (estado.itemCursor>0))
	{
		//Altera viewport e projecção
		glViewport(0, 0, (GLint) width, (GLint) height);
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluOrtho2D(0,width,height,0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.0,0.0,0.8);
			glRasterPos2i(estado.xMouse, estado.yMouse);
			printString("Nome");
			glEnable(GL_LIGHTING);
		glPopMatrix();
		myReshape((GLint) width, (GLint) height);
	}

	if (estado.itemSeleccionado>numNos)
	{
		//Altera viewport e projecção
		glViewport(0, 0, (GLint) width, (GLint) height);
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluOrtho2D(0,100,100,0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.0,0.0,0.8);
			glRasterPos2i(80, 3);
			printString("Relacao:");
			glRasterPos2i(80, 10);
			printString("De:");
			glColor3f(0.0,0.0,1.0);
			glRasterPos2i(80, 12);
			printString("Utilizador1");
			glColor3f(0.0,0.0,0.8);
			glRasterPos2i(80, 15);
			printString("Para:");
			glColor3f(0.0,0.0,1.0);
			glRasterPos2i(80, 17);
			printString("Utilizador2");
			glColor3f(0.0,0.0,0.8);
			glRasterPos2i(80, 20);
			printString("Tags:");
			int lastTagPos=20;
			lastTagPos+=2;
			glColor3f(0.0,0.0,1.0);
			glRasterPos2i(80, lastTagPos);
			printString("Tag1");
			lastTagPos+=2;
			glColor3f(0.0,0.0,1.0);
			glRasterPos2i(80, lastTagPos);
			printString("Tag2");

			glEnable(GL_LIGHTING);
		glPopMatrix();
		myReshape((GLint) width, (GLint) height);
	}
	else
	{
		if(estado.itemSeleccionado>0)
		{
			//Altera viewport e projecção
			glViewport(0, 0, (GLint) width, (GLint) height);
			glMatrixMode(GL_PROJECTION);

			glLoadIdentity();
			gluOrtho2D(0,100,100,0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glColor3f(0.0,0.0,0.8);
				glRasterPos2i(80, 3);
				printString("Avatar:");
				/*glColor3f(0.0,0.0,1.0);
				glRasterPos2i(80, 5);
				printString("Colocar aki o avatar");*/
	
				//carregar avatar
				glPushMatrix();
					glColor3f(1.0,1.0,1.0);
					glEnable(GL_BLEND);
					glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, avatar.TextureID);  
					glBegin(GL_QUADS);
						glTexCoord2f(0,1);
						glVertex2f(80,4);
						glTexCoord2f(0,0);
						glVertex2f(80,18);
						glTexCoord2f(1,0);
						glVertex2f(94,18);
						glTexCoord2f(1,1);
						glVertex2f(94,4);
					glEnd();
					glBindTexture(GL_TEXTURE_2D, NULL);  
					glDisable(GL_BLEND);
				glPopMatrix();

				glColor3f(0.0,0.0,0.8);
				glRasterPos2i(80, 21);
				printString("Nome:");
				glColor3f(0.0,0.0,1.0);
				glRasterPos2i(80, 23);
				printString("Xpto Otpx");

				glColor3f(0.0,0.0,0.8);
				glRasterPos2i(80, 26);
				printString("Data Nascimento:");
				glColor3f(0.0,0.0,1.0);
				glRasterPos2i(80, 28);
				printString("01-01-9999");

				glColor3f(0.0,0.0,0.8);
				glRasterPos2i(80, 31);
				printString("Morada:");
				glColor3f(0.0,0.0,1.0);
				glRasterPos2i(80, 33);
				printString("Rua xpto, 666, qwerty");

				glEnable(GL_LIGHTING);
			glPopMatrix();

			myReshape((GLint) width, (GLint) height);
		}
	}
}

void desenhaBillboards()
{
	for(int i=0;i<numNos;i++)
	{
		GLfloat x=nos[i].x;
		GLfloat yi=nos[i].y-0.4;
		GLfloat yf=nos[i].y+0.4;
		GLfloat zi=nos[i].z+nos[i].largura;
		GLfloat zf=nos[i].z+nos[i].largura+0.4;
		glPushMatrix();
			glScalef(2,2,2);
			glTranslated(nos[i].x,nos[i].y,nos[i].z+nos[i].largura+0.2);
			glRotatef(graus(estado.camera.dir_long),0,0,1);
			glDisable(GL_LIGHTING);
			glColor3f(1.0,1.0,1.0);
			glEnable(GL_BLEND);
			glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, contente.TextureID);  
			glBegin(GL_QUADS);
				glTexCoord2f(1,0);
				glVertex3f(0,-0.4,-0.2);
				glTexCoord2f(0,0);
				glVertex3f(0,0.4,-0.2);
				glTexCoord2f(0,1);
				glVertex3f(0,0.4,0.2);
				glTexCoord2f(1,1);
				glVertex3f(0,-0.4,0.2);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, NULL);  
			glDisable(GL_BLEND);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	}
}

void minimapacam(){
	Vertice eye;
	eye[0]=estado.camera.center[0]+200*cos(M_PI/2);
	eye[1]=estado.camera.center[1];
	eye[2]=250;

	if(estado.light){
		gluLookAt(eye[0],eye[1],eye[2],estado.camera.center[0],estado.camera.center[1],estado.camera.center[2],0,0,1);
		putLights((GLfloat*)white_light);
	}else{
		putLights((GLfloat*)white_light);
		gluLookAt(eye[0],eye[1],eye[2],estado.camera.center[0],estado.camera.center[1],estado.camera.center[2],0,0,1);
	}
}

void desenhaMinimapa()
{
	int wh;
	wh=glutGet(GLUT_WINDOW_HEIGHT);
	glViewport(1, wh-172, (GLint) 180, (GLint) 170);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,100,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_LINE_LOOP);
			glVertex2i(1,1);
			glVertex2i(99,1);
			glVertex2i(99,99);
			glVertex2i(1,99);
		glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(50, (float)(glutGet(GLUT_WINDOW_WIDTH)/(float)(glutGet(GLUT_WINDOW_HEIGHT))), 0.1, 1000 );
	glOrtho(-100,100,-100,100,1,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_DEPTH_BUFFER_BIT);
	minimapacam();

	desenhaLabirinto();

	glFlush();
	myReshape(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
}

void desenhaSkydome()
{
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, estrelas.TextureID);
		glTranslatef(0.0,0.0,50.0);
		glRotatef(90.0,1,0,0);
		GenerateDome(300.0f, 5.0f, 5.0f, 1.0f, 1.0f);
		RenderSkyDome();
		glBindTexture(GL_TEXTURE_2D, NULL);
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void desenhaLogin()
{
	int w,h;
	w=glutGet(GLUT_WINDOW_WIDTH);
	h=glutGet(GLUT_WINDOW_HEIGHT);
	//Altera viewport e projecção
	glViewport(0, 0, (GLint) w, (GLint) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,100,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, text_login.TextureID);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0,1);
			glVertex3f(0,0,0);
			glTexCoord2f(1,1);
			glVertex3f(100,0,0);
			glTexCoord2f(1,0);
			glVertex3f(100,100,0);
			glTexCoord2f(0,0);
			glVertex3f(0,100,0);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, NULL);
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

/*
void RenderParticles(void)
{
   vec3_t x;
   vec3_t y;
   vec3_t a, b, c, d;
   GLfloat *modelView;
   float size = 0;

   for (int i = 0; i < numParticles; i++)
   {
      //particles[i].Frame(passed);

      glPushMatrix();
      glRotatef(particles[i].GetRot()[0], 1.0f, 0.0f, 0.0f);
      glRotatef(particles[i].GetRot()[1], 0.0f, 1.0f, 0.0f);
      glRotatef(particles[i].GetRot()[2], 0.0f, 0.0f, 1.0f);
                  
      // We need to billboard this particle
      if (particles[i].GetBillboard())
      {
         glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
         x[0]=modelView[0];
		 x[1]=modelView[4];
		 x[2]=modelView[8];
         y[0]=modelView[1];
		 y[1]=modelView[5];
		 y[2]=modelView[9];
      }
      else
      {
         x.Set(1.0f, 0.0f, 0.0f);
         y.Set(0.0f, 1.0f, 0.0f);
      }   
      
      size = particles[i].GetSize();

      /*
         Remember x and y are vectors. *not* points.  There is a lot going on in
         the background thanks to the vec3_t class.  This stuff can be made
         a lot faster, but that isn't important now.  
      */
/*
      a = particles[i].GetPos() + ((-x - y) * size);
      b = particles[i].GetPos() + ((x - y) * size);
      c = particles[i].GetPos() + ((x + y) * size);
      d = particles[i].GetPos() + ((-x + y) * size);

      glBindTexture(GL_TEXTURE_2D, particles[i].GetTexId());
      glBegin(GL_QUADS);
         glTexCoord2f(0.0f, 0.0f);
         glVertex3fv(a);
         glTexCoord2f(1.0f, 0.0f);
         glVertex3fv(b);
         glTexCoord2f(1.0f, 1.0f);
         glVertex3fv(c);
         glTexCoord2f(0.0f, 1.0f);
         glVertex3fv(d);
      glEnd();

      glPopMatrix();
   }
}
*/
bool detectacolisao()
{
	Vertice eye;
	eye[0]=estado.camera.center[0]+estado.camera.dist*cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
	eye[1]=estado.camera.center[1]+estado.camera.dist*sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
	eye[2]=estado.camera.center[2]+estado.camera.dist*sin(estado.camera.dir_lat);
	
	for (int i=0;i<numNos;i++)
	{
		float range=nos[i].largura+0.2;
		if ((eye[0]<nos[i].x+range) && (eye[0]>nos[i].x-range))
		{
			if ((eye[1]<nos[i].y+range) && (eye[1]>nos[i].y-range))
			{
				if((eye[2]<nos[i].z+range) && (eye[2]>nos[i].z-range))
				{
					return true;
				}
			}
		}
	}
	return false;
}

void setCamera(){
	if (!detectacolisao())
	{
		Vertice eye;
		eye[0]=estado.camera.center[0]+estado.camera.dist*cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
		eye[1]=estado.camera.center[1]+estado.camera.dist*sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
		eye[2]=estado.camera.center[2]+estado.camera.dist*sin(estado.camera.dir_lat);

		if(estado.light){
			gluLookAt(eye[0],eye[1],eye[2],estado.camera.center[0],estado.camera.center[1],estado.camera.center[2],0,0,1);
			putLights((GLfloat*)white_light);
		}else{
			putLights((GLfloat*)white_light);
			gluLookAt(eye[0],eye[1],eye[2],estado.camera.center[0],estado.camera.center[1],estado.camera.center[2],0,0,1);
		}
	}
}

void display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	setCamera();
	//desenhaLogin();
	
	material(slate);
	desenhaSolo();

	desenhaEixos();
	
	desenhaLabirinto();

	desenhaBillboards();

	desenhaSkydome();

	desenhaHUD(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));

	desenhaMinimapa();
 
	if(estado.eixoTranslaccao) {
		// desenha plano de translacção
		cout << "Translate... " << estado.eixoTranslaccao << endl; 
		desenhaPlanoDrag(estado.eixoTranslaccao);

	}
	
	glFlush();
	glutSwapBuffers();

}



void keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {
		case 27 :
				exit(0);
			break;
		case 'h':
		case 'H':
				imprime_ajuda();
			break;
		case 'l':
		case 'L':
				if(estado.lightViewer)
					estado.lightViewer=0;
				else
					estado.lightViewer=1;
				glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado.lightViewer);
				glutPostRedisplay();
			break;
		case 'k':
		case 'K':
				estado.light=!estado.light;
				glutPostRedisplay();
			break;
		case 'w':
		case 'W':
				glDisable(GL_LIGHTING);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glutPostRedisplay();
			break;
		case 'p':
		case 'P':
				glDisable(GL_LIGHTING);
				glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
				glutPostRedisplay();
			break;
		case 's':
		case 'S':
				glEnable(GL_LIGHTING);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glutPostRedisplay();
			break;
		case 'c':
		case 'C':
				if(glIsEnabled(GL_CULL_FACE))
					glDisable(GL_CULL_FACE);
				else
					glEnable(GL_CULL_FACE);
				glutPostRedisplay();
			break;    
		case 'n':
		case 'N':
				estado.apresentaNormais=!estado.apresentaNormais;
				glutPostRedisplay();
			break;    		
		case 'i':
		case 'I':
				initEstado();
				initModelo();
				glutPostRedisplay();
			break;    
		case 'q':
		case 'Q':
				//estado.camera.dist-=1;
				estado.itemCursor=0;
				estado.camera.center[2]+=1;
				desenhaEixos();
				glutPostRedisplay();
			break;
		case 'a':
		case 'A':
				//estado.camera.dist+=1;
				estado.itemCursor=0;
				estado.camera.center[2]-=1;
				desenhaEixos();
				glutPostRedisplay();
			break;
	}
}

void Special(int key, int x, int y){

	switch(key){
		case GLUT_KEY_F1 :
				gravaGrafo();
			break;
		case GLUT_KEY_F2 :
				leGrafo();
				glutPostRedisplay();
			break;	

		case GLUT_KEY_F6 :
				numNos=numArcos=0;
				addNo(criaNo( 0, 10,0));  // 0
				addNo(criaNo( 0,  5,0));  // 1
				addNo(criaNo(-5,  5,0));  // 2
				addNo(criaNo( 5,  5,0));  // 3
				addNo(criaNo(-5,  0,0));  // 4
				addNo(criaNo( 5,  0,0));  // 5
				addNo(criaNo(-5, -5,0));  // 6
				addArco(criaArco(0,1,1,1));  // 0 - 1
				addArco(criaArco(1,2,1,1));  // 1 - 2
				addArco(criaArco(1,3,1,1));  // 1 - 3
				addArco(criaArco(2,4,1,1));  // 2 - 4
				addArco(criaArco(3,5,1,1));  // 3 - 5
				addArco(criaArco(4,5,1,1));  // 4 - 5
				addArco(criaArco(4,6,1,1));  // 4 - 6
				glutPostRedisplay();
			break;	
		case GLUT_KEY_UP:
				//estado.camera.dist-=1;
				estado.camera.center[0]-=0.5*cos(estado.camera.dir_long);
				estado.camera.center[1]-=0.5*sin(estado.camera.dir_long);
				estado.itemCursor=0;
				desenhaEixos();
				glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
				//estado.camera.dist+=1;
				estado.camera.center[0]+=0.5*cos(estado.camera.dir_long);
				estado.camera.center[1]+=0.5*sin(estado.camera.dir_long);
				estado.itemCursor=0;
				desenhaEixos();
				glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
				estado.camera.dir_long+=0.05;
				estado.itemCursor=0;
				glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
				estado.camera.dir_long-=0.05;
				estado.itemCursor=0;
				glutPostRedisplay();
			break;	}
		
}


void motionRotate(int x, int y){
#define DRAG_SCALE	0.01
	double lim=M_PI/2-0.1;
	estado.camera.dir_long+=(estado.xMouse-x)*DRAG_SCALE;
	estado.camera.dir_lat-=(estado.yMouse-y)*DRAG_SCALE*0.5;
	if(estado.camera.dir_lat>lim)
		estado.camera.dir_lat=lim;
	else 
		if(estado.camera.dir_lat<-lim)
			estado.camera.dir_lat=-lim;
	estado.xMouse=x;
	estado.yMouse=y;
	glutPostRedisplay();
}

void motionZoom(int x, int y){
#define ZOOM_SCALE	0.5
	estado.camera.dist-=(estado.yMouse-y)*ZOOM_SCALE;
	if(estado.camera.dist<5)
		estado.camera.dist=5;
	else 
		if(estado.camera.dist>200)
			estado.camera.dist=200;
	estado.yMouse=y;
	glutPostRedisplay();
}

void motionDrag(int x, int y){
	GLuint buffer[100];
	GLint vp[4];
	GLdouble proj[16], mv[16];
	int n;
	GLdouble newx, newy, newz;

	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
		glLoadIdentity();
		setProjection(x,y,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCamera();
	//desenhaPlanoDrag(estado.eixoTranslaccao);
	
	n = glRenderMode(GL_RENDER);
	if (n > 0) {
		glGetIntegerv(GL_VIEWPORT, vp);
		glGetDoublev(GL_PROJECTION_MATRIX, proj);
		glGetDoublev(GL_MODELVIEW_MATRIX, mv);
		gluUnProject(x, glutGet(GLUT_WINDOW_HEIGHT) - y, (double) buffer[2] / UINT_MAX, mv, proj, vp, &newx, &newy, &newz);
		printf("Novo x:%lf, y:%lf, z:%lf\n\n", newx, newy, newz);
		switch (estado.eixoTranslaccao) {
			case EIXO_X :
					estado.eixo[0]=newx;
					//estado.eixo[1]=newy;
				break;
			case EIXO_Y :
					estado.eixo[1]=newy;
					//estado.eixo[2]=newz;
				break;
			case EIXO_Z :
					//estado.eixo[0]=newx;
					estado.eixo[2]=newz;
				break;		
		}
		glutPostRedisplay();
	}


	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

int picking(int x, int y){
	int i, n, objid=0;
	double zmin = 10.0;
	GLuint buffer[100], *ptr;

	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
		glLoadIdentity();
		setProjection(x,y,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCamera();
	//desenhaEixos();
	desenhaLabirinto();
	
	n = glRenderMode(GL_RENDER);
	if (n > 0)
	{
		ptr = buffer;
		for (i = 0; i < n; i++)
		{
			if (zmin > (double) ptr[1] / UINT_MAX) {
				zmin = (double) ptr[1] / UINT_MAX;
				objid = ptr[3];
			}
			ptr += 3 + ptr[0]; // ptr[0] contem o número de nomes (normalmente 1); 3 corresponde a numnomes, zmin e zmax
		}
	}
	
	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	return objid;
}
void mouse(int btn, int state, int x, int y){
	int idobj;
	switch(btn) {
		case GLUT_RIGHT_BUTTON :
					if(state == GLUT_DOWN){
						estado.xMouse=x;
						estado.yMouse=y;
						if(glutGetModifiers() & GLUT_ACTIVE_CTRL)
							glutMotionFunc(motionZoom);
						else
							glutMotionFunc(motionRotate);
					}
					else{
						glutMotionFunc(NULL);
					}
				break;
		case GLUT_LEFT_BUTTON :
					if(state == GLUT_DOWN){
						idobj=picking(x,y);
						/*estado.eixoTranslaccao=idobj;
						if(estado.eixoTranslaccao)
							glutMotionFunc(motionDrag);
						*/
							estado.itemSeleccionado=idobj;
							//estado.itemSeleccionado=-1;
							
						glutPostRedisplay();
					}
					else{
						/*if(estado.eixoTranslaccao!=0) {
							estado.camera.center[0]=estado.eixo[0];
							estado.camera.center[1]=estado.eixo[1];
							estado.camera.center[2]=estado.eixo[2];
							glutMotionFunc(NULL);
							estado.eixoTranslaccao=0;
							glutPostRedisplay();
						}*/
					}
				break;
	}
}

void mousePassive(int x, int y)
{
	estado.itemCursor=picking(x,y);
	estado.xMouse=x;
	estado.yMouse=y;
	glutPostRedisplay();
}

void Timer(int value)
{
	estado.tempo++;
	glutTimerFunc(1000,Timer,0);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("OpenGL");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Special);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(mousePassive);
	glutTimerFunc(1000,Timer,0);

	myInit();

	createTextures(texID);   //carrega texturas

	imprime_ajuda();

    glutMainLoop();
}
