#include "stdafx.h"
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include "schema.xsd.h"
void getAllXY(NoBD **&no);
void GetAllArcoBD(ArcoBD **&arco);
void GetUtilizadorByID(int uid,Utilizador *&utilizador);
void GetTagsByUserID(int uid,unsigned int &numN,WCHAR **&tags);
void getMenorCaminho(int uid1,int uid2,WCHAR *&nos);
void getCaminhoForte(int uid1,int uid2,WCHAR *&nos);
void validateLogin(WCHAR *&user,WCHAR *&pw,int &res);
void getLigacao(int ulog,int u1,int u2,Ligacao *&tags);
void grafoAmigosComuns(int u1,int u2,WCHAR *&grafo);
void getNosGrafo(int uid,NoBD **&no);