#include "grafos.h"
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include "schema.xsd.h"
#include "webservice.h"

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
void leGrafo(){
	
	NoBD **nosbd=NULL;
	getAllXY(nosbd);
	numNos=(*(nosbd))->id;
	for (int i=1;i<=numNos;i++)
	{
		nos[i-1].x=(*(nosbd+i))->x;
		nos[i-1].y=(*(nosbd+i))->y;
		nos[i-1].z=0.0;
		nos[i-1].iduser=(*(nosbd+i))->id;
		nos[i-1].largura=1.0;
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
		arcos[i-1].largura=arcos[i-1].peso*0.1;
		//arcos[i-1].largura=(*(arcosbd+i))->idRel;
		nos[arcos[i-1].noi].z+=2;
		nos[arcos[i-1].nof].z+=2;
	}
	WS_XML_BUFFER **tags=NULL;
	GetTagsByUserID(1,tags);

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