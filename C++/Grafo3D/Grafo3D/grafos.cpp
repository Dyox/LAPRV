#include <string>
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include "schema.xsd.h"
#include "webservice.h"
#include "grafos.h"

#define __GRAFO__FILE__ "exemplo.grafo"

No nos[_MAX_NOS_GRAFO];
Arco arcos[_MAX_ARCOS_GRAFO];
int numNos=0, numArcos=0;

using namespace std;

void addNo(No no){
	if(numNos<_MAX_NOS_GRAFO){
		nos[numNos]=no;
		numNos++;
	}else{
		cout << "Número de nós chegou ao limite" << endl;
	}
}

void deleteNo(int indNo){
	if(indNo>=0 && indNo<numNos){
		for(int i=indNo; i<numNos; nos[i++]=nos[i+i]);
		numNos--;
	}else{
		cout << "Indíce de nó inválido" << endl;
	}
}

void imprimeNo(No no){
	cout << "X:" << no.x << "Y:" << no.y << "Z:" << no.z <<endl;
}

void listNos(){
	for(int i=0; i<numNos; imprimeNo(nos[i++]));
}

No criaNo(float x, float y, float z){
	No no;
	no.x=x;
	no.y=y;
	no.z=z;
	return no;
}

void addArco(Arco arco){
	if(numArcos<_MAX_ARCOS_GRAFO){
		arcos[numArcos]=arco;
		numArcos++;
	}else{
		cout << "Número de arcos chegou ao limite" << endl;
	}
}

void deleteArco(int indArco){
	if(indArco>=0 && indArco<numArcos){
		for(int i=indArco; i<numArcos; arcos[i++]=arcos[i+i]);
		numArcos--;
	}else{
		cout << "Indíce de arco inválido" << endl;
	}
}

void imprimeArco(Arco arco){
	cout << "No início:" << arco.noi << "Nó final:" << arco.nof << "Peso:" << arco.peso << "Largura:" << arco.largura << endl;
}

void listArcos(){
	for(int i=0; i<numArcos; imprimeArco(arcos[i++]));
}

Arco criaArco(int noi, int nof, float peso, float largura){
	Arco arco;
	arco.noi=noi;
	arco.nof=nof;
	arco.peso=peso;
	arco.largura=largura;
	return arco;
}

void gravaGrafo(){
	ofstream myfile;

	myfile.open (__GRAFO__FILE__, ios::out);
	if (!myfile.is_open()) {
		cout << "Erro ao abrir " << __GRAFO__FILE__ << "para escrever" <<endl;
		exit(1);
	}
	myfile << numNos << endl;
	for(int i=0; i<numNos;i++)
		myfile << nos[i].x << " " << nos[i].y << " " << nos[i].z <<endl;
	myfile << numArcos << endl;
	for(int i=0; i<numArcos;i++)
		myfile << arcos[i].noi << " " << arcos[i].nof << " " << arcos[i].peso << " " << arcos[i].largura << endl;
	myfile.close();
}
void leGrafo(int uid){
	NoBD **nosbd=NULL;
	getAllXY(nosbd);
	//getNosGrafo(uid,nosbd);
	numNos=(*(nosbd))->id;
	char ch[260];
	char DefChar = ' ';
	for (int i=1;i<=numNos;i++)
	{
		nos[i-1].x=(*(nosbd+i))->x;
		nos[i-1].y=(*(nosbd+i))->y;
		nos[i-1].z=0.0;
		nos[i-1].iduser=(*(nosbd+i))->id;
		int ntags=(*(nosbd+i))->ntag;
		nos[i-1].largura=1.0+ntags*0.1;
		//convert from wide char to narrow char array
		WideCharToMultiByte(CP_ACP,0,(*(nosbd+i))->nome,-1, ch,260,&DefChar, NULL);
		std::string ss(ch);
		nos[i-1].nome=ss;
		WideCharToMultiByte(CP_ACP,0,(*(nosbd+i))->humor,-1, ch,260,&DefChar, NULL);
		std::string ss2(ch);
		nos[i-1].humor=ss2;
		WideCharToMultiByte(CP_ACP,0,(*(nosbd+i))->avatar3d,-1, ch,260,&DefChar, NULL);
		std::string ss3(ch);
		nos[i-1].avatar3d=ss3;
	}
	ArcoBD **arcosbd=NULL;
	GetAllArcoBD(arcosbd);
	numArcos=(*(arcosbd))->idRel;
	for (int i=1;i<=numArcos;i++)
	{
		for (int j=0;j<numNos;j++)
		{
			if (nos[j].iduser==(*(arcosbd+i))->idPrim)
			{
				arcos[i-1].noi=j;
			}
			if (nos[j].iduser==(*(arcosbd+i))->idSec)
			{
				arcos[i-1].nof=j;
			}
		}
		//arcos[i-1].noi=(*(arcosbd+i))->idPrim;
		//arcos[i-1].nof=(*(arcosbd+i))->idSec;
		arcos[i-1].peso=(*(arcosbd+i))->forca;
		arcos[i-1].largura=arcos[i-1].peso*0.07;
		//arcos[i-1].largura=(*(arcosbd+i))->idRel;
		nos[arcos[i-1].noi].z+=1;
		nos[arcos[i-1].nof].z+=1;
	}

	WCHAR *g;
	grafoAmigosComuns(1,7,g);

	/*
	ifstream myfile;
	myfile.open (__GRAFO__FILE__, ios::in);
	if (!myfile.is_open()) {
		cout << "Erro ao abrir " << __GRAFO__FILE__ << "para ler" <<endl;
		exit(1);
	}
	myfile >> numNos;
	for(int i=0; i<numNos;i++)
	{
		myfile >> nos[i].x >> nos[i].y >> nos[i].z;
		nos[i].z=0.0;
		nos[i].largura=1.0;
	}
	myfile >> numArcos ;
	for(int i=0; i<numArcos;i++)
	{
		myfile >> arcos[i].noi >> arcos[i].nof >> arcos[i].peso >> arcos[i].largura ;
		//calculo da cota conforme o nº de ligações de cada nó
		arcos[i].largura=0.2;
		nos[arcos[i].noi].z+=2;
		nos[arcos[i].nof].z+=2;
	}
	myfile.close();
	*/
}

void caminhoCurto(int uid1,int uid2,int &count,int nos[])
{
	WCHAR *strnosmenor;
	getMenorCaminho(uid1,uid2,strnosmenor);
	char ch[260];
	char DefChar = ' ';
	WideCharToMultiByte(CP_ACP,0,strnosmenor,-1, ch,260,&DefChar, NULL);
	std::string ss(ch);
	if (ss.compare(0,2,"Ne")!=0)
	{
		ss.erase(0,1);
		int i=0;
		int virg=ss.find(",",0);
		while(virg>=0)
		{
			string no=ss.substr(0,ss.find(",",0));
			ss.erase(0,ss.find(",",0)+1);
			nos[i]=atoi(no.c_str());
			virg=ss.find(",",0);
			i++;
		}
		string no=ss.substr(0,ss.find("]",0));
		nos[i]=atoi(no.c_str());
		virg=ss.find(",",0);
		i++;
		//nos=caminho;
		count=i;
	}
	else
	{
		nos=NULL;
		count=0;
	}
}

void caminhoForte(int uid1,int uid2,int &count,int nos[])
{
	WCHAR *strnosforte;
	getCaminhoForte(uid1,uid2,strnosforte);
	char ch[260];
	char DefChar = ' ';
	WideCharToMultiByte(CP_ACP,0,strnosforte,-1, ch,260,&DefChar, NULL);
	std::string ss(ch);
	if (ss.compare(0,2,"Ne")!=0)
	{
		ss.erase(0,1);
		int i=0;
		int virg=ss.find(",",0);
		while(virg>=0)
		{
			string no=ss.substr(0,ss.find(",",0));
			ss.erase(0,ss.find(",",0)+1);
			nos[i]=atoi(no.c_str());
			virg=ss.find(",",0);
			i++;
		}
		string no=ss.substr(0,ss.find("]",0));
		nos[i]=atoi(no.c_str());
		virg=ss.find(",",0);
		i++;
		//nos=caminho;
		count=i;
	}
	else
	{
		nos=NULL;
		count=0;
	}
}