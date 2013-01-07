#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "webservice.h"
/*#include "stdafx.h"
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include "schema.xsd.h"*/

void getAllXY(NoBD **&no)
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
	//NoBD **no1;
	unsigned int numN;
	//chamada de uma operação do service – getMusica. O resultado vem no parâmetro //musica
	hr = BasicHttpBinding_IService_GetAllXY(proxy,&numN, &no, heap, NULL, 0, NULL, error);
	/*if (proxy){
		WsCloseServiceProxy(proxy, NULL, NULL);
		WsFreeServiceProxy(proxy);
	}
	if (heap){WsFreeHeap(heap);}
	if (error){ WsFreeError(error);}*/
	//no=no1;
	//return **no1;
}

void GetAllArcoBD(ArcoBD **&arco)
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
	//NoBD **no1;
	unsigned int numN;
	//chamada de uma operação do service – getMusica. O resultado vem no parâmetro //musica
	hr = BasicHttpBinding_IService_GetAllArcoBD(proxy,&numN, &arco, heap, NULL, 0, NULL, error);
}

void GetUtilizadorByID(int uid,Utilizador *&utilizador)
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
	//NoBD **no1;
	//unsigned int numN;
	//chamada de uma operação do service – getMusica. O resultado vem no parâmetro //musica
	hr = BasicHttpBinding_IService_GetUtilizadorByID(proxy,uid,&utilizador, heap, NULL, 0, NULL, error);
}

void GetTagsByUserID(int uid,WS_XML_BUFFER **&tags)
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
	//NoBD **no1;
	unsigned int numN;
	//chamada de uma operação do service – getMusica. O resultado vem no parâmetro //musica
	hr = BasicHttpBinding_IService_GetTagsByUserID(proxy,uid,&numN,&tags, heap, NULL, 0, NULL, error);
}