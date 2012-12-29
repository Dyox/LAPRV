﻿
// File generated by Wsutil Compiler version 1.0092 
// This file defines C/C++ functions, callbacks, types that correspond to operations,
// and types specified in WSDL and XSD files processed by WsUtil compiler. The generated 
// type definitions, function and callback declarations can be used with various 
// Web Services APIs either in applications that send and receive requests to and 
// from a running web service, or in the implementation of web services, or in both. 
//
// If Wsutil has generated this file from an XSD file, the file contains definition of 
// C/C++ structures types that correspond to types defined in the XSD file. 
// For example, if the following XSD complexType is defined in the XSD file
//
//      <xsd:complexType name="AddRequest">
//          <xsd:sequence>
//              <xsd:element minOccurs="0" name="a" type="xsd:int" />
//              <xsd:element minOccurs="0" name="b" type="xsd:int" />
//          </xsd:sequence>
//      </xsd:complexType>
// 
// this file contains the following definitions of the structure 
//      // AddRequest (xsd:complexType)
//      // <AddRequest xmlns='http://tempuri.org'>
//      // WS_STRUCT_DESCRIPTION* = &calculator_xsd.globalTypes.AddRequest
//      struct AddRequest
//      {
//          int a;
//          int b;
//      };
//
// For more information on how to use the C/C++ types generated in this file to read or write elements of XML documents that conform to 
// this XSD, please see the documentation for 
// WsReadType() and WsWriteType() functions.
// 
#if _MSC_VER > 1000 
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

// The following types were generated:

//     struct _Add;
//     struct _AddResponse;
//     struct _GetAllXY;
//     struct _GetAllXYResponse;
//     struct _GetAllArcoBD;
//     struct _GetAllArcoBDResponse;
//     struct _DoWork;
//     struct _DoWorkResponse;

// The following header files must be included in this order before this one

// #include <WebServices.h>
// #include "schema.xsd.h"

////////////////////////////////////////////////
// C structure definitions for generated types
////////////////////////////////////////////////

// typeDescription: n/a
typedef struct _Add 
{
    int x;
    int y;
} _Add;

// typeDescription: n/a
typedef struct _AddResponse 
{
    int AddResult;
} _AddResponse;

typedef struct _GetAllXY _GetAllXY;

// typeDescription: n/a
typedef struct _GetAllXYResponse 
{
    unsigned int GetAllXYResultCount;
    __field_ecount_opt(GetAllXYResultCount)struct NoBD** GetAllXYResult; // optional
} _GetAllXYResponse;

typedef struct _GetAllArcoBD _GetAllArcoBD;

// typeDescription: n/a
typedef struct _GetAllArcoBDResponse 
{
    unsigned int GetAllArcoBDResultCount;
    __field_ecount_opt(GetAllArcoBDResultCount)struct ArcoBD** GetAllArcoBDResult; // optional
} _GetAllArcoBDResponse;

typedef struct _DoWork _DoWork;

typedef struct _DoWorkResponse _DoWorkResponse;

////////////////////////////////////////////////
// Global web service descriptions.
////////////////////////////////////////////////

typedef struct _tempuri_org_xsd
{
    struct // globalElements
    {
        // xml element: Add ("http://tempuri.org/")
        // c type: _Add
        // elementDescription: tempuri_org_xsd.globalElements.Add
        WS_ELEMENT_DESCRIPTION Add;
        
        // xml element: AddResponse ("http://tempuri.org/")
        // c type: _AddResponse
        // elementDescription: tempuri_org_xsd.globalElements.AddResponse
        WS_ELEMENT_DESCRIPTION AddResponse;
        
        // xml element: GetAllXY ("http://tempuri.org/")
        // c type: _GetAllXY
        // elementDescription: tempuri_org_xsd.globalElements.GetAllXY
        WS_ELEMENT_DESCRIPTION GetAllXY;
        
        // xml element: GetAllXYResponse ("http://tempuri.org/")
        // c type: _GetAllXYResponse
        // elementDescription: tempuri_org_xsd.globalElements.GetAllXYResponse
        WS_ELEMENT_DESCRIPTION GetAllXYResponse;
        
        // xml element: GetAllArcoBD ("http://tempuri.org/")
        // c type: _GetAllArcoBD
        // elementDescription: tempuri_org_xsd.globalElements.GetAllArcoBD
        WS_ELEMENT_DESCRIPTION GetAllArcoBD;
        
        // xml element: GetAllArcoBDResponse ("http://tempuri.org/")
        // c type: _GetAllArcoBDResponse
        // elementDescription: tempuri_org_xsd.globalElements.GetAllArcoBDResponse
        WS_ELEMENT_DESCRIPTION GetAllArcoBDResponse;
        
        // xml element: DoWork ("http://tempuri.org/")
        // c type: _DoWork
        // elementDescription: tempuri_org_xsd.globalElements.DoWork
        WS_ELEMENT_DESCRIPTION DoWork;
        
        // xml element: DoWorkResponse ("http://tempuri.org/")
        // c type: _DoWorkResponse
        // elementDescription: tempuri_org_xsd.globalElements.DoWorkResponse
        WS_ELEMENT_DESCRIPTION DoWorkResponse;
        
    } globalElements;
    struct // externallyReferencedTypes
    {
        WS_STRUCT_DESCRIPTION Add;
        WS_STRUCT_DESCRIPTION AddResponse;
        WS_STRUCT_DESCRIPTION GetAllXY;
        WS_STRUCT_DESCRIPTION GetAllXYResponse;
        WS_STRUCT_DESCRIPTION GetAllArcoBD;
        WS_STRUCT_DESCRIPTION GetAllArcoBDResponse;
        WS_STRUCT_DESCRIPTION DoWork;
        WS_STRUCT_DESCRIPTION DoWorkResponse;
    } externallyReferencedTypes;
} _tempuri_org_xsd;

extern const _tempuri_org_xsd tempuri_org_xsd;

#ifdef __cplusplus
}
#endif
