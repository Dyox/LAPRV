// GetGrafo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include "schema.xsd.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
HRESULT hr = ERROR_SUCCESS;
WS_ERROR* error = NULL;
WS_HEAP* heap = NULL;
WS_SERVICE_PROXY* proxy = NULL;
WS_ENDPOINT_ADDRESS address = {};
//endereço do serviço
WS_STRING url= WS_STRING_VALUE(L"http://wvm022.dei.isep.ipp.pt/TesteWebService/Service.svc");
//WS_STRING url=WS_STRING_VALUE(L"http://localhost:27388/WCFServicewithWebSite/ServiceDemo.svc");
address.url = url;
hr = WsCreateHeap(2048, 512, NULL, 0, &heap, error);
WS_HTTP_BINDING_TEMPLATE templ = {};
//criação do proxy para o serviço
hr = BasicHttpBinding_IService_CreateServiceProxy(&templ, NULL, 0, &proxy, error);
hr = WsOpenServiceProxy(proxy, &address, NULL, error);
int result;
//chamada de uma operação do serviço – Add. O resultado vem no parâmetro result
hr = BasicHttpBinding_IService_Add(proxy, 3,14, &result,heap, NULL, 0, NULL, error);
printf( "%d\n", result);
No **no1;
unsigned int numN;
//chamada de uma operação do service – getMusica. O resultado vem no parâmetro //musica
hr = BasicHttpBinding_IService_GetAllXY(proxy,&numN, &no1, heap, NULL, 0, NULL, error);
//wprintf(L"%s\n", musica->Artist);
//wprintf(L"%s\n", musica->Title);
//converter de WCHAR* para std::wstring object
for(int i =0;i<4;i++){
	printf("%d",(*(no1+i))->x);
}

//wstring artista1( musica->Artist);
//wstring test( artista1.begin(), artista1.end() );
//wcout << artista1;
//converter de wide char para char array
//int size=wcslen(musica->Artist);
//char *artista2=(char *)malloc(size);
//char DefChar = ' ';
//WideCharToMultiByte(CP_ACP,0,musica->Artist,-1, artista2,260,&DefChar, NULL);
printf("\n");
//printf(artista2);
if (proxy){
WsCloseServiceProxy(proxy, NULL, NULL);
WsFreeServiceProxy(proxy);
}
if (heap){WsFreeHeap(heap);}
if (error){ WsFreeError(error);}

string filename;
    cout << "Fim";
    getline(cin, filename);
	return 0;
}

