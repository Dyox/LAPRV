﻿
// File generated by Wsutil Compiler version 1.0092 
// This file defines C/C++ functions, callbacks, types that correspond to operations,
// and types specified in WSDL and XSD files processed by WsUtil compiler. The generated 
// type definitions, function and callback declarations can be used with various 
// Web Services APIs either in applications that send and receive requests to and 
// from a running web service, or in the implementation of web services, or in both. 
//
// If Wsutil has generated this file from a WSDL file, the file may contain up to three 
// sets of C/C++ definitions. The first set consists of function declarations that can be 
// used in calling operations on a running web service from client applications. 
// The second set consists of callback declarations that can be used in the 
// implementation of web services.  
// The third set contains definitions C/C++ structures that are used for serialization of 
// C/C++ types to schema types defined in the WSDL file.
//
// The set of function declarations for web services clients may contain the 
// following declaration: 
//
//    HRESULT WINAPI DefaultBinding_ICalculator_Add(
//       __in WS_SERVICE_PROXY* _serviceProxy,
//       __in int a, 
//       __in int b, 
//       __out int* result, 
//       __in WS_HEAP* _heap,
//       __in_opt WS_CALL_PROPERTY* _callProperties,
//       __in const ULONG _callPropertyCount,
//       __in_opt const WS_ASYNC_CONTEXT*_asyncContext,
//       __in_opt WS_ERROR* _error);
//
// This function can be called from an application code to request ICalculator web 
// service to perform operation Add using two integers a and b as input data.
// Once the web service processes this request and sends the result back,
// the result is returned to the caller of this function in the "result" parameter.
// A WS_SERVICE_PROXY must be created using WsCreateServiceProxy() function
// before this proxy function can be invoked.
//
// The set of callbacks for implementation of web services may contain the following 
// definition of a callback: 
//
//    typedef HRESULT (CALLBACK* DefaultBinding_ICalculator_AddCallback) (
//       __in const WS_OPERATION_CONTEXT* _context,
//       __in int a, 
//       __in int b, 
//       __out int* result, 
//       __in const WS_ASYNC_CONTEXT* _asyncContext,
//       __in WS_ERROR* _error); 
//
//    typedef struct DefaultBinding_ICalculatorFunctionTable 
//    {
//         DefaultBinding_ICalculator_AddCallback DefaultBinding_ICalculator_Add;
//    } DefaultBinding_ICalculatorFunctionTable;
//
// This definition can be used to implement a function that defines the Add operation 
// as a part of an ICalculator web service. Once this callback is implemented and 
// the web service is deployed and running, if a client applications attempts to 
// execute the operation Add, the implementation of this callback is called and 
// it receives two integers a and b as input data and it returns a third integer 
// that is the result of the operation. A WS_SERVICE_ENDPOINT must be filled out, 
// and its contract field set to instance of such a function table.  
// WsCreateServiceHost may then be used to register the endpoint as a service.
// 
// The set with definitions of C/C++ structures may contain a definition of the following 
// structure:
//    typedef struct ContactInfo 
//    {
//			WCHAR*  name;
//			WCHAR*  email;
//			__int64 contactID;
//	  } ContactInfo;
//
// This structure corresponds to the following complex type defined in the WSDL file:
//    <s:complexType name="ContactInfo">
//      <s:sequence>
//        <s:element minOccurs="1" maxOccurs="1" name="name" type="s:string" />
//        <s:element minOccurs="1" maxOccurs="1" name="email" type="s:string" />
//        <s:element minOccurs="1" maxOccurs="1" name="contactID" type="s:long" />
//      </s:sequence>
//    </s:complexType>
//
// For more information about content of this file, please see the documentation for
// Wsutil compiler.
// If Wsutil generates this file from a WSDL file and policy processing is enabled using
// policy switch, the file may contain declaration of functions that can be used 
// for creating a proxy to a web service or an endpoint of a web service. 
// For example, the file may contain declaration of the following function:
//
//    HRESULT DefaultBinding_ICalculator_CreateServiceProxy(
//    __in WS_HTTP_SSL_BINDING_TEMPLATE* templateValue,
//    __in_ecount_opt(proxyPropertyCount) const WS_PROXY_PROPERTY* proxyProperties,
//    __in const ULONG proxyPropertyCount,
//    __deref_out_opt WS_SERVICE_PROXY** proxy,
//    __in_opt WS_ERROR* error);
//
// This function can be called from application code to create a service
// proxy object. A service proxy must be created before any request can be sent 
// to the web service.
//
// Also, the file may contain declaration of the following function :
//
//    HRESULT DefaultBinding_ICalculator_CreateServiceEndpoint(
//    __in WS_HTTP_SSL_BINDING_TEMPLATE* templateValue,
//    __in_opt WS_STRING address,
//    __in_opt struct DefaultBinding_ICalculatorFunctionTable* functionTable,
//    __in_opt WS_SERVICE_SECURITY_CALLBACK authorizationCallback,
//    __in_ecount_opt(endpointPropertyCount) WS_SERVICE_ENDPOINT_PROPERTY* endpointProperties,
//    __in const ULONG endpointPropertyCount,
//    __in WS_HEAP* heap,
//    __deref_out_opt WS_SERVICE_ENDPOINT** serviceEndpoint,
//    __in_opt WS_ERROR* error);
//
// This function can be used to create a Service Host object, which has to be 
// created before a web services starts receiving requests from its clients.
//
// For more information about content of this file, please see the documentation for
// Wsutil compiler.
#if _MSC_VER > 1000 
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

// The following client functions were generated:

//     BasicHttpBinding_IService_Add
//     BasicHttpBinding_IService_GetAllXY
//     BasicHttpBinding_IService_GetAllArcoBD
//     BasicHttpBinding_IService_GetUtilizadorByID
//     BasicHttpBinding_IService_GetTagsByUserID
//     BasicHttpBinding_IService_GetHumorByUserID
//     BasicHttpBinding_IService_getMenorCaminho
//     BasicHttpBinding_IService_getCaminhoForte
//     BasicHttpBinding_IService_DoWork
//     BasicHttpBinding_IService_validateLogin
//     BasicHttpBinding_IService_xTagsEmComum
//     BasicHttpBinding_IService_tamanhoRedeUtilizador
//     BasicHttpBinding_IService_sugereAmigos

// The following server function tables were generated:

//     struct BasicHttpBinding_IServiceFunctionTable

// the following policy helpers were generated:

//  BasicHttpBinding_IService_CreateServiceProxy;
//  BasicHttpBinding_IService_CreateServiceEndpoint;

// The following header files must be included in this order before this one

// #include <WebServices.h>
// #include "schema.xsd.h"
// #include "schemas.microsoft.com.2003.10.Serialization.Arrays.xsd.h"
// #include "tempuri.org.xsd.h"

////////////////////////////////////////////////
// Policy helper routines
////////////////////////////////////////////////

//  WS_CHANNEL_PROPERTY_ENCODING = WS_ENCODING_XML_UTF8,
//  WS_CHANNEL_PROPERTY_ADDRESSING_VERSION = WS_ADDRESSING_VERSION_TRANSPORT,
//  WS_ENVELOPE_VERSION = WS_ENVELOPE_VERSION_SOAP_1_1,
// client channel type: WS_CHANNEL_TYPE_REQUEST, service endpoint channel type: WS_CHANNEL_TYPE_REPLY

HRESULT BasicHttpBinding_IService_CreateServiceProxy(
    __in_opt WS_HTTP_BINDING_TEMPLATE* templateValue,
    __in_ecount_opt(proxyPropertyCount) const WS_PROXY_PROPERTY* proxyProperties,
    __in const ULONG proxyPropertyCount,
    __deref_out_opt WS_SERVICE_PROXY** _serviceProxy,
    __in_opt WS_ERROR* error);

struct BasicHttpBinding_IServiceFunctionTable;
HRESULT BasicHttpBinding_IService_CreateServiceEndpoint(
    __in_opt WS_HTTP_BINDING_TEMPLATE* templateValue,
    __in_opt CONST WS_STRING* address,
    __in_opt struct BasicHttpBinding_IServiceFunctionTable* functionTable,
    __in_opt WS_SERVICE_SECURITY_CALLBACK authorizationCallback,
    __in_ecount_opt(endpointPropertyCount) WS_SERVICE_ENDPOINT_PROPERTY* endpointProperties,
    __in const ULONG endpointPropertyCount,
    __in WS_HEAP* heap,
    __deref_out_opt WS_SERVICE_ENDPOINT** serviceEndpoint,
    __in_opt WS_ERROR* error);

////////////////////////////////////////////////
// Client functions definitions
////////////////////////////////////////////////

// operation: BasicHttpBinding_IService_Add
HRESULT WINAPI BasicHttpBinding_IService_Add(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int x, 
    __in int y, 
    __out int* AddResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_GetAllXY
HRESULT WINAPI BasicHttpBinding_IService_GetAllXY(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __out unsigned int* GetAllXYResultCount, 
    __deref_out_ecount_opt(*GetAllXYResultCount) NoBD*** GetAllXYResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_GetAllArcoBD
HRESULT WINAPI BasicHttpBinding_IService_GetAllArcoBD(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __out unsigned int* GetAllArcoBDResultCount, 
    __deref_out_ecount_opt(*GetAllArcoBDResultCount) ArcoBD*** GetAllArcoBDResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_GetUtilizadorByID
HRESULT WINAPI BasicHttpBinding_IService_GetUtilizadorByID(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int uid, 
    __deref_out_opt Utilizador** GetUtilizadorByIDResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_GetTagsByUserID
HRESULT WINAPI BasicHttpBinding_IService_GetTagsByUserID(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int uid, 
    __out unsigned int* GetTagsByUserIDResultCount, 
    __deref_out_ecount_opt(*GetTagsByUserIDResultCount) __deref __nullterminated WCHAR*** GetTagsByUserIDResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_GetHumorByUserID
HRESULT WINAPI BasicHttpBinding_IService_GetHumorByUserID(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int uid, 
    __out_opt __deref __nullterminated WCHAR** GetHumorByUserIDResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_getMenorCaminho
HRESULT WINAPI BasicHttpBinding_IService_getMenorCaminho(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int no1, 
    __in int no2, 
    __out_opt __deref __nullterminated WCHAR** getMenorCaminhoResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_getCaminhoForte
HRESULT WINAPI BasicHttpBinding_IService_getCaminhoForte(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int no1, 
    __in int no2, 
    __out_opt __deref __nullterminated WCHAR** getCaminhoForteResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_DoWork
HRESULT WINAPI BasicHttpBinding_IService_DoWork(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_validateLogin
HRESULT WINAPI BasicHttpBinding_IService_validateLogin(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in_opt __nullterminated WCHAR* userName, 
    __in_opt __nullterminated WCHAR* password, 
    __out int* validateLoginResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_xTagsEmComum
HRESULT WINAPI BasicHttpBinding_IService_xTagsEmComum(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int id, 
    __in int n, 
    __out_opt __deref __nullterminated WCHAR** xTagsEmComumResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_tamanhoRedeUtilizador
HRESULT WINAPI BasicHttpBinding_IService_tamanhoRedeUtilizador(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int id, 
    __out int* tamanhoRedeUtilizadorResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// operation: BasicHttpBinding_IService_sugereAmigos
HRESULT WINAPI BasicHttpBinding_IService_sugereAmigos(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in int id, 
    __out_opt __deref __nullterminated WCHAR** sugereAmigosResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

////////////////////////////////////////////////
// Service functions definitions
////////////////////////////////////////////////

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_AddCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int x, 
    __in int y, 
    __out int* AddResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_GetAllXYCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __out unsigned int* GetAllXYResultCount, 
    __deref_out_ecount_opt(*GetAllXYResultCount) NoBD*** GetAllXYResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_GetAllArcoBDCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __out unsigned int* GetAllArcoBDResultCount, 
    __deref_out_ecount_opt(*GetAllArcoBDResultCount) ArcoBD*** GetAllArcoBDResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_GetUtilizadorByIDCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int uid, 
    __deref_out_opt Utilizador** GetUtilizadorByIDResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_GetTagsByUserIDCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int uid, 
    __out unsigned int* GetTagsByUserIDResultCount, 
    __deref_out_ecount_opt(*GetTagsByUserIDResultCount) __deref __nullterminated WCHAR*** GetTagsByUserIDResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_GetHumorByUserIDCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int uid, 
    __out_opt __deref __nullterminated WCHAR** GetHumorByUserIDResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_getMenorCaminhoCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int no1, 
    __in int no2, 
    __out_opt __deref __nullterminated WCHAR** getMenorCaminhoResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_getCaminhoForteCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int no1, 
    __in int no2, 
    __out_opt __deref __nullterminated WCHAR** getCaminhoForteResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_DoWorkCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_validateLoginCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in_opt __nullterminated WCHAR* userName, 
    __in_opt __nullterminated WCHAR* password, 
    __out int* validateLoginResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_xTagsEmComumCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int id, 
    __in int n, 
    __out_opt __deref __nullterminated WCHAR** xTagsEmComumResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_tamanhoRedeUtilizadorCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int id, 
    __out int* tamanhoRedeUtilizadorResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

typedef HRESULT (CALLBACK* BasicHttpBinding_IService_sugereAmigosCallback) (
    __in const WS_OPERATION_CONTEXT* _context,
    __in int id, 
    __out_opt __deref __nullterminated WCHAR** sugereAmigosResult, 
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error);

// binding: BasicHttpBinding_IService
typedef struct BasicHttpBinding_IServiceFunctionTable 
{
    BasicHttpBinding_IService_AddCallback BasicHttpBinding_IService_Add;
    BasicHttpBinding_IService_GetAllXYCallback BasicHttpBinding_IService_GetAllXY;
    BasicHttpBinding_IService_GetAllArcoBDCallback BasicHttpBinding_IService_GetAllArcoBD;
    BasicHttpBinding_IService_GetUtilizadorByIDCallback BasicHttpBinding_IService_GetUtilizadorByID;
    BasicHttpBinding_IService_GetTagsByUserIDCallback BasicHttpBinding_IService_GetTagsByUserID;
    BasicHttpBinding_IService_GetHumorByUserIDCallback BasicHttpBinding_IService_GetHumorByUserID;
    BasicHttpBinding_IService_getMenorCaminhoCallback BasicHttpBinding_IService_getMenorCaminho;
    BasicHttpBinding_IService_getCaminhoForteCallback BasicHttpBinding_IService_getCaminhoForte;
    BasicHttpBinding_IService_DoWorkCallback BasicHttpBinding_IService_DoWork;
    BasicHttpBinding_IService_validateLoginCallback BasicHttpBinding_IService_validateLogin;
    BasicHttpBinding_IService_xTagsEmComumCallback BasicHttpBinding_IService_xTagsEmComum;
    BasicHttpBinding_IService_tamanhoRedeUtilizadorCallback BasicHttpBinding_IService_tamanhoRedeUtilizador;
    BasicHttpBinding_IService_sugereAmigosCallback BasicHttpBinding_IService_sugereAmigos;
} BasicHttpBinding_IServiceFunctionTable;

////////////////////////////////////////////////
// Global web service descriptions.
////////////////////////////////////////////////

typedef struct _tempuri_org_wsdl
{
    struct // messages
    {
        // message: IService_Add_InputMessage
        // c type: _Add
        // action: "http://tempuri.org/IService/Add"
        // messageDescription: tempuri_org_wsdl.messages.IService_Add_InputMessage
        WS_MESSAGE_DESCRIPTION IService_Add_InputMessage;
        
        // message: IService_Add_OutputMessage
        // c type: _AddResponse
        // action: "http://tempuri.org/IService/AddResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_Add_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_Add_OutputMessage;
        
        // message: IService_GetAllXY_InputMessage
        // c type: _GetAllXY
        // action: "http://tempuri.org/IService/GetAllXY"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetAllXY_InputMessage
        WS_MESSAGE_DESCRIPTION IService_GetAllXY_InputMessage;
        
        // message: IService_GetAllXY_OutputMessage
        // c type: _GetAllXYResponse
        // action: "http://tempuri.org/IService/GetAllXYResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetAllXY_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_GetAllXY_OutputMessage;
        
        // message: IService_GetAllArcoBD_InputMessage
        // c type: _GetAllArcoBD
        // action: "http://tempuri.org/IService/GetAllArcoBD"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetAllArcoBD_InputMessage
        WS_MESSAGE_DESCRIPTION IService_GetAllArcoBD_InputMessage;
        
        // message: IService_GetAllArcoBD_OutputMessage
        // c type: _GetAllArcoBDResponse
        // action: "http://tempuri.org/IService/GetAllArcoBDResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetAllArcoBD_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_GetAllArcoBD_OutputMessage;
        
        // message: IService_GetUtilizadorByID_InputMessage
        // c type: _GetUtilizadorByID
        // action: "http://tempuri.org/IService/GetUtilizadorByID"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetUtilizadorByID_InputMessage
        WS_MESSAGE_DESCRIPTION IService_GetUtilizadorByID_InputMessage;
        
        // message: IService_GetUtilizadorByID_OutputMessage
        // c type: _GetUtilizadorByIDResponse
        // action: "http://tempuri.org/IService/GetUtilizadorByIDResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetUtilizadorByID_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_GetUtilizadorByID_OutputMessage;
        
        // message: IService_GetTagsByUserID_InputMessage
        // c type: _GetTagsByUserID
        // action: "http://tempuri.org/IService/GetTagsByUserID"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetTagsByUserID_InputMessage
        WS_MESSAGE_DESCRIPTION IService_GetTagsByUserID_InputMessage;
        
        // message: IService_GetTagsByUserID_OutputMessage
        // c type: _GetTagsByUserIDResponse
        // action: "http://tempuri.org/IService/GetTagsByUserIDResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetTagsByUserID_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_GetTagsByUserID_OutputMessage;
        
        // message: IService_GetHumorByUserID_InputMessage
        // c type: _GetHumorByUserID
        // action: "http://tempuri.org/IService/GetHumorByUserID"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetHumorByUserID_InputMessage
        WS_MESSAGE_DESCRIPTION IService_GetHumorByUserID_InputMessage;
        
        // message: IService_GetHumorByUserID_OutputMessage
        // c type: _GetHumorByUserIDResponse
        // action: "http://tempuri.org/IService/GetHumorByUserIDResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_GetHumorByUserID_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_GetHumorByUserID_OutputMessage;
        
        // message: IService_getMenorCaminho_InputMessage
        // c type: _getMenorCaminho
        // action: "http://tempuri.org/IService/getMenorCaminho"
        // messageDescription: tempuri_org_wsdl.messages.IService_getMenorCaminho_InputMessage
        WS_MESSAGE_DESCRIPTION IService_getMenorCaminho_InputMessage;
        
        // message: IService_getMenorCaminho_OutputMessage
        // c type: _getMenorCaminhoResponse
        // action: "http://tempuri.org/IService/getMenorCaminhoResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_getMenorCaminho_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_getMenorCaminho_OutputMessage;
        
        // message: IService_getCaminhoForte_InputMessage
        // c type: _getCaminhoForte
        // action: "http://tempuri.org/IService/getCaminhoForte"
        // messageDescription: tempuri_org_wsdl.messages.IService_getCaminhoForte_InputMessage
        WS_MESSAGE_DESCRIPTION IService_getCaminhoForte_InputMessage;
        
        // message: IService_getCaminhoForte_OutputMessage
        // c type: _getCaminhoForteResponse
        // action: "http://tempuri.org/IService/getCaminhoForteResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_getCaminhoForte_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_getCaminhoForte_OutputMessage;
        
        // message: IService_DoWork_InputMessage
        // c type: _DoWork
        // action: "http://tempuri.org/IService/DoWork"
        // messageDescription: tempuri_org_wsdl.messages.IService_DoWork_InputMessage
        WS_MESSAGE_DESCRIPTION IService_DoWork_InputMessage;
        
        // message: IService_DoWork_OutputMessage
        // c type: _DoWorkResponse
        // action: "http://tempuri.org/IService/DoWorkResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_DoWork_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_DoWork_OutputMessage;
        
        // message: IService_validateLogin_InputMessage
        // c type: _validateLogin
        // action: "http://tempuri.org/IService/validateLogin"
        // messageDescription: tempuri_org_wsdl.messages.IService_validateLogin_InputMessage
        WS_MESSAGE_DESCRIPTION IService_validateLogin_InputMessage;
        
        // message: IService_validateLogin_OutputMessage
        // c type: _validateLoginResponse
        // action: "http://tempuri.org/IService/validateLoginResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_validateLogin_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_validateLogin_OutputMessage;
        
        // message: IService_xTagsEmComum_InputMessage
        // c type: _xTagsEmComum
        // action: "http://tempuri.org/IService/xTagsEmComum"
        // messageDescription: tempuri_org_wsdl.messages.IService_xTagsEmComum_InputMessage
        WS_MESSAGE_DESCRIPTION IService_xTagsEmComum_InputMessage;
        
        // message: IService_xTagsEmComum_OutputMessage
        // c type: _xTagsEmComumResponse
        // action: "http://tempuri.org/IService/xTagsEmComumResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_xTagsEmComum_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_xTagsEmComum_OutputMessage;
        
        // message: IService_tamanhoRedeUtilizador_InputMessage
        // c type: _tamanhoRedeUtilizador
        // action: "http://tempuri.org/IService/tamanhoRedeUtilizador"
        // messageDescription: tempuri_org_wsdl.messages.IService_tamanhoRedeUtilizador_InputMessage
        WS_MESSAGE_DESCRIPTION IService_tamanhoRedeUtilizador_InputMessage;
        
        // message: IService_tamanhoRedeUtilizador_OutputMessage
        // c type: _tamanhoRedeUtilizadorResponse
        // action: "http://tempuri.org/IService/tamanhoRedeUtilizadorResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_tamanhoRedeUtilizador_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_tamanhoRedeUtilizador_OutputMessage;
        
        // message: IService_sugereAmigos_InputMessage
        // c type: _sugereAmigos
        // action: "http://tempuri.org/IService/sugereAmigos"
        // messageDescription: tempuri_org_wsdl.messages.IService_sugereAmigos_InputMessage
        WS_MESSAGE_DESCRIPTION IService_sugereAmigos_InputMessage;
        
        // message: IService_sugereAmigos_OutputMessage
        // c type: _sugereAmigosResponse
        // action: "http://tempuri.org/IService/sugereAmigosResponse"
        // messageDescription: tempuri_org_wsdl.messages.IService_sugereAmigos_OutputMessage
        WS_MESSAGE_DESCRIPTION IService_sugereAmigos_OutputMessage;
        
    } messages;
    struct // contracts
    {
        // binding: BasicHttpBinding_IService
        // portType: IService
        // operation: BasicHttpBinding_IService_Add
        //     input message: IService_Add_InputMessage
        //     output message: IService_Add_OutputMessage
        // operation: BasicHttpBinding_IService_GetAllXY
        //     input message: IService_GetAllXY_InputMessage
        //     output message: IService_GetAllXY_OutputMessage
        // operation: BasicHttpBinding_IService_GetAllArcoBD
        //     input message: IService_GetAllArcoBD_InputMessage
        //     output message: IService_GetAllArcoBD_OutputMessage
        // operation: BasicHttpBinding_IService_GetUtilizadorByID
        //     input message: IService_GetUtilizadorByID_InputMessage
        //     output message: IService_GetUtilizadorByID_OutputMessage
        // operation: BasicHttpBinding_IService_GetTagsByUserID
        //     input message: IService_GetTagsByUserID_InputMessage
        //     output message: IService_GetTagsByUserID_OutputMessage
        // operation: BasicHttpBinding_IService_GetHumorByUserID
        //     input message: IService_GetHumorByUserID_InputMessage
        //     output message: IService_GetHumorByUserID_OutputMessage
        // operation: BasicHttpBinding_IService_getMenorCaminho
        //     input message: IService_getMenorCaminho_InputMessage
        //     output message: IService_getMenorCaminho_OutputMessage
        // operation: BasicHttpBinding_IService_getCaminhoForte
        //     input message: IService_getCaminhoForte_InputMessage
        //     output message: IService_getCaminhoForte_OutputMessage
        // operation: BasicHttpBinding_IService_DoWork
        //     input message: IService_DoWork_InputMessage
        //     output message: IService_DoWork_OutputMessage
        // operation: BasicHttpBinding_IService_validateLogin
        //     input message: IService_validateLogin_InputMessage
        //     output message: IService_validateLogin_OutputMessage
        // operation: BasicHttpBinding_IService_xTagsEmComum
        //     input message: IService_xTagsEmComum_InputMessage
        //     output message: IService_xTagsEmComum_OutputMessage
        // operation: BasicHttpBinding_IService_tamanhoRedeUtilizador
        //     input message: IService_tamanhoRedeUtilizador_InputMessage
        //     output message: IService_tamanhoRedeUtilizador_OutputMessage
        // operation: BasicHttpBinding_IService_sugereAmigos
        //     input message: IService_sugereAmigos_InputMessage
        //     output message: IService_sugereAmigos_OutputMessage
        // contractDescription: tempuri_org_wsdl.contracts.BasicHttpBinding_IService
        WS_CONTRACT_DESCRIPTION BasicHttpBinding_IService;
        
    } contracts;
    struct // policies
    {
        // policy for binding: BasicHttpBinding_IService
        // port name: BasicHttpBinding_IService, binding: BasicHttpBinding_IService, namespace: http://tempuri.org/
        WS_HTTP_POLICY_DESCRIPTION BasicHttpBinding_IService;
    } policies;
} _tempuri_org_wsdl;

extern const _tempuri_org_wsdl tempuri_org_wsdl;

#ifdef __cplusplus
}
#endif

