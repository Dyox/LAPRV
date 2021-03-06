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

//     struct ArrayOfNo;
//     struct No;
//     struct ArrayOfNo;
//     struct No;

// The following header files must be included in this order before this one

// #include <WebServices.h>

////////////////////////////////////////////////
// C structure definitions for generated types
////////////////////////////////////////////////

// typeDescription: schema_xsd.globalTypes.ArrayOfNo
typedef struct ArrayOfNo 
{
    unsigned int NoCount;
    __field_ecount(NoCount)struct No** No; // optional
} ArrayOfNo;

// typeDescription: schema_xsd.globalTypes.No
typedef struct No 
{
    int id;
    int numNo;
    int x;
    int y;
} No;

////////////////////////////////////////////////
// Global web service descriptions.
////////////////////////////////////////////////

typedef struct _schema_xsd
{
    struct // globalTypes
    {
        // xml type: ArrayOfNo ("http://schemas.datacontract.org/2004/07/")
        // c type: ArrayOfNo
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: schema_xsd.globalTypes.ArrayOfNo
        WS_STRUCT_DESCRIPTION ArrayOfNo;
        
        // xml type: No ("http://schemas.datacontract.org/2004/07/")
        // c type: No
        // WS_TYPE: WS_STRUCT_TYPE
        // typeDescription: schema_xsd.globalTypes.No
        WS_STRUCT_DESCRIPTION No;
        
    } globalTypes;
    struct // globalElements
    {
        // xml element: ArrayOfNo ("http://schemas.datacontract.org/2004/07/")
        // c type: ArrayOfNo
        // elementDescription: schema_xsd.globalElements.ArrayOfNo
        WS_ELEMENT_DESCRIPTION ArrayOfNo;
        
        // xml element: No ("http://schemas.datacontract.org/2004/07/")
        // c type: No
        // elementDescription: schema_xsd.globalElements.No
        WS_ELEMENT_DESCRIPTION No;
        
    } globalElements;
} _schema_xsd;

extern const _schema_xsd schema_xsd;

#ifdef __cplusplus
}
#endif

