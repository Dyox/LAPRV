﻿
// File generated by Wsutil Compiler version 1.0092 
#include <WebServices.h>
#include "schema.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"

typedef struct _tempuri_org_wsdlLocalDefinitions 
{
    struct // messages
    {
        WS_MESSAGE_DESCRIPTION IService_Add_InputMessage;
        WS_MESSAGE_DESCRIPTION IService_Add_OutputMessage;
        WS_MESSAGE_DESCRIPTION IService_GetAllXY_InputMessage;
        WS_MESSAGE_DESCRIPTION IService_GetAllXY_OutputMessage;
        WS_MESSAGE_DESCRIPTION IService_GetAllArcoBD_InputMessage;
        WS_MESSAGE_DESCRIPTION IService_GetAllArcoBD_OutputMessage;
        WS_MESSAGE_DESCRIPTION IService_DoWork_InputMessage;
        WS_MESSAGE_DESCRIPTION IService_DoWork_OutputMessage;
    } messages; // end of messages
    struct // contracts
    {
        struct // BasicHttpBinding_IService
        {
            struct // BasicHttpBinding_IService_Add
            {
                WS_PARAMETER_DESCRIPTION params[3];
                WS_OPERATION_DESCRIPTION BasicHttpBinding_IService_Add;
            } BasicHttpBinding_IService_Add;
            struct // BasicHttpBinding_IService_GetAllXY
            {
                WS_PARAMETER_DESCRIPTION params[2];
                WS_OPERATION_DESCRIPTION BasicHttpBinding_IService_GetAllXY;
            } BasicHttpBinding_IService_GetAllXY;
            struct // BasicHttpBinding_IService_GetAllArcoBD
            {
                WS_PARAMETER_DESCRIPTION params[2];
                WS_OPERATION_DESCRIPTION BasicHttpBinding_IService_GetAllArcoBD;
            } BasicHttpBinding_IService_GetAllArcoBD;
            struct // BasicHttpBinding_IService_DoWork
            {
                WS_OPERATION_DESCRIPTION BasicHttpBinding_IService_DoWork;
            } BasicHttpBinding_IService_DoWork;
            WS_OPERATION_DESCRIPTION* operations[4];
            WS_CONTRACT_DESCRIPTION contractDesc;
        } BasicHttpBinding_IService;
    } contracts;  // endof contracts 
    struct // policies
    {
        struct // BasicHttpBinding_IService
        {
            WS_ENCODING encoding;
            WS_ADDRESSING_VERSION addressingVersion;
            WS_ENVELOPE_VERSION envelopeVersion;
            WS_CHANNEL_PROPERTY channelPropertiesArray[3];
        } BasicHttpBinding_IService;
    } policies;
    struct // XML dictionary
    {
        struct // XML string list
        {
            WS_XML_STRING IService_Add_InputMessageactionName;  // http://tempuri.org/IService/Add
            WS_XML_STRING IService_Add_OutputMessageactionName;  // http://tempuri.org/IService/AddResponse
            WS_XML_STRING IService_GetAllXY_InputMessageactionName;  // http://tempuri.org/IService/GetAllXY
            WS_XML_STRING IService_GetAllXY_OutputMessageactionName;  // http://tempuri.org/IService/GetAllXYResponse
            WS_XML_STRING IService_GetAllArcoBD_InputMessageactionName;  // http://tempuri.org/IService/GetAllArcoBD
            WS_XML_STRING IService_GetAllArcoBD_OutputMessageactionName;  // http://tempuri.org/IService/GetAllArcoBDResponse
            WS_XML_STRING IService_DoWork_InputMessageactionName;  // http://tempuri.org/IService/DoWork
            WS_XML_STRING IService_DoWork_OutputMessageactionName;  // http://tempuri.org/IService/DoWorkResponse
        } xmlStrings; // end of XML string list
        WS_XML_DICTIONARY dict;  
    } dictionary;  // end of XML dictionary
} _tempuri_org_wsdlLocalDefinitions;


typedef struct BasicHttpBinding_IService_AddParamStruct 
{
    int* x;
    int* y;
    int* AddResult;
} BasicHttpBinding_IService_AddParamStruct;

#if (_MSC_VER >=1400) 
#pragma warning(push)
#endif
#pragma warning(disable: 4055) // conversion from data pointer to function pointer
HRESULT CALLBACK BasicHttpBinding_IService_AddOperationStub(
    __in const WS_OPERATION_CONTEXT* _context,
    __in void* _stackStruct,
    __in const void* _callback,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    BasicHttpBinding_IService_AddCallback _operation = (BasicHttpBinding_IService_AddCallback)_callback;
    BasicHttpBinding_IService_AddParamStruct *_stack =(BasicHttpBinding_IService_AddParamStruct*)_stackStruct;
    return _operation( 
        _context,
        *(_stack->x),
        *(_stack->y),
        (_stack->AddResult),
        (WS_ASYNC_CONTEXT*)_asyncContext,
        _error);
}
#pragma warning(default: 4055)  // conversion from data pointer to function pointer
#if (_MSC_VER >=1400) 
#pragma warning(pop)
#endif

typedef struct BasicHttpBinding_IService_GetAllXYParamStruct 
{
    unsigned int* GetAllXYResultCount;
    NoBD*** GetAllXYResult;
} BasicHttpBinding_IService_GetAllXYParamStruct;

#if (_MSC_VER >=1400) 
#pragma warning(push)
#endif
#pragma warning(disable: 4055) // conversion from data pointer to function pointer
HRESULT CALLBACK BasicHttpBinding_IService_GetAllXYOperationStub(
    __in const WS_OPERATION_CONTEXT* _context,
    __in void* _stackStruct,
    __in const void* _callback,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    BasicHttpBinding_IService_GetAllXYCallback _operation = (BasicHttpBinding_IService_GetAllXYCallback)_callback;
    BasicHttpBinding_IService_GetAllXYParamStruct *_stack =(BasicHttpBinding_IService_GetAllXYParamStruct*)_stackStruct;
    return _operation( 
        _context,
        _stack->GetAllXYResultCount,
        (_stack->GetAllXYResult),
        (WS_ASYNC_CONTEXT*)_asyncContext,
        _error);
}
#pragma warning(default: 4055)  // conversion from data pointer to function pointer
#if (_MSC_VER >=1400) 
#pragma warning(pop)
#endif

typedef struct BasicHttpBinding_IService_GetAllArcoBDParamStruct 
{
    unsigned int* GetAllArcoBDResultCount;
    ArcoBD*** GetAllArcoBDResult;
} BasicHttpBinding_IService_GetAllArcoBDParamStruct;

#if (_MSC_VER >=1400) 
#pragma warning(push)
#endif
#pragma warning(disable: 4055) // conversion from data pointer to function pointer
HRESULT CALLBACK BasicHttpBinding_IService_GetAllArcoBDOperationStub(
    __in const WS_OPERATION_CONTEXT* _context,
    __in void* _stackStruct,
    __in const void* _callback,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    BasicHttpBinding_IService_GetAllArcoBDCallback _operation = (BasicHttpBinding_IService_GetAllArcoBDCallback)_callback;
    BasicHttpBinding_IService_GetAllArcoBDParamStruct *_stack =(BasicHttpBinding_IService_GetAllArcoBDParamStruct*)_stackStruct;
    return _operation( 
        _context,
        _stack->GetAllArcoBDResultCount,
        (_stack->GetAllArcoBDResult),
        (WS_ASYNC_CONTEXT*)_asyncContext,
        _error);
}
#pragma warning(default: 4055)  // conversion from data pointer to function pointer
#if (_MSC_VER >=1400) 
#pragma warning(pop)
#endif

#if (_MSC_VER >=1400) 
#pragma warning(push)
#endif
#pragma warning(disable: 4055) // conversion from data pointer to function pointer
HRESULT CALLBACK BasicHttpBinding_IService_DoWorkOperationStub(
    __in const WS_OPERATION_CONTEXT* _context,
    __in void* _stackStruct,
    __in const void* _callback,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    BasicHttpBinding_IService_DoWorkCallback _operation = (BasicHttpBinding_IService_DoWorkCallback)_callback;
    _stackStruct;
    return _operation( 
        _context,
        (WS_ASYNC_CONTEXT*)_asyncContext,
        _error);
}
#pragma warning(default: 4055)  // conversion from data pointer to function pointer
#if (_MSC_VER >=1400) 
#pragma warning(pop)
#endif
const static _tempuri_org_wsdlLocalDefinitions tempuri_org_wsdlLocalDefinitions =
{
    { // messages
        {    // message description for IService_Add_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_Add_InputMessageactionName, // http://tempuri.org/IService/Add
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.Add, 
        },    // message description for IService_Add_InputMessage
        {    // message description for IService_Add_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_Add_OutputMessageactionName, // http://tempuri.org/IService/AddResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.AddResponse, 
        },    // message description for IService_Add_OutputMessage
        {    // message description for IService_GetAllXY_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllXY_InputMessageactionName, // http://tempuri.org/IService/GetAllXY
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllXY, 
        },    // message description for IService_GetAllXY_InputMessage
        {    // message description for IService_GetAllXY_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllXY_OutputMessageactionName, // http://tempuri.org/IService/GetAllXYResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllXYResponse, 
        },    // message description for IService_GetAllXY_OutputMessage
        {    // message description for IService_GetAllArcoBD_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllArcoBD_InputMessageactionName, // http://tempuri.org/IService/GetAllArcoBD
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllArcoBD, 
        },    // message description for IService_GetAllArcoBD_InputMessage
        {    // message description for IService_GetAllArcoBD_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllArcoBD_OutputMessageactionName, // http://tempuri.org/IService/GetAllArcoBDResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllArcoBDResponse, 
        },    // message description for IService_GetAllArcoBD_OutputMessage
        {    // message description for IService_DoWork_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_DoWork_InputMessageactionName, // http://tempuri.org/IService/DoWork
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.DoWork, 
        },    // message description for IService_DoWork_InputMessage
        {    // message description for IService_DoWork_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_DoWork_OutputMessageactionName, // http://tempuri.org/IService/DoWorkResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.DoWorkResponse, 
        },    // message description for IService_DoWork_OutputMessage
    }, // end of messages 
    { // contracts
        {    // BasicHttpBinding_IService,
            { // BasicHttpBinding_IService_Add
                { // parameter descriptions for BasicHttpBinding_IService_Add
                    { WS_PARAMETER_TYPE_NORMAL, (USHORT)0, (USHORT)-1 },
                    { WS_PARAMETER_TYPE_NORMAL, (USHORT)1, (USHORT)-1 },
                    { WS_PARAMETER_TYPE_NORMAL, (USHORT)-1, (USHORT)0 },
                },    // parameter descriptions for BasicHttpBinding_IService_Add
                {    // operation description for BasicHttpBinding_IService_Add
                    1,
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_Add_InputMessage, 
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_Add_OutputMessage, 
                    0,
                    0,
                    3,
                    (WS_PARAMETER_DESCRIPTION*)tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_Add.params,
                    BasicHttpBinding_IService_AddOperationStub,
                    WS_NON_RPC_LITERAL_OPERATION
                }, //operation description for BasicHttpBinding_IService_Add
            },  // BasicHttpBinding_IService_Add
            { // BasicHttpBinding_IService_GetAllXY
                { // parameter descriptions for BasicHttpBinding_IService_GetAllXY
                    { WS_PARAMETER_TYPE_ARRAY_COUNT, (USHORT)-1, (USHORT)0 },
                    { WS_PARAMETER_TYPE_ARRAY, (USHORT)-1, (USHORT)0 },
                },    // parameter descriptions for BasicHttpBinding_IService_GetAllXY
                {    // operation description for BasicHttpBinding_IService_GetAllXY
                    1,
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_GetAllXY_InputMessage, 
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_GetAllXY_OutputMessage, 
                    0,
                    0,
                    2,
                    (WS_PARAMETER_DESCRIPTION*)tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_GetAllXY.params,
                    BasicHttpBinding_IService_GetAllXYOperationStub,
                    WS_NON_RPC_LITERAL_OPERATION
                }, //operation description for BasicHttpBinding_IService_GetAllXY
            },  // BasicHttpBinding_IService_GetAllXY
            { // BasicHttpBinding_IService_GetAllArcoBD
                { // parameter descriptions for BasicHttpBinding_IService_GetAllArcoBD
                    { WS_PARAMETER_TYPE_ARRAY_COUNT, (USHORT)-1, (USHORT)0 },
                    { WS_PARAMETER_TYPE_ARRAY, (USHORT)-1, (USHORT)0 },
                },    // parameter descriptions for BasicHttpBinding_IService_GetAllArcoBD
                {    // operation description for BasicHttpBinding_IService_GetAllArcoBD
                    1,
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_GetAllArcoBD_InputMessage, 
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_GetAllArcoBD_OutputMessage, 
                    0,
                    0,
                    2,
                    (WS_PARAMETER_DESCRIPTION*)tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_GetAllArcoBD.params,
                    BasicHttpBinding_IService_GetAllArcoBDOperationStub,
                    WS_NON_RPC_LITERAL_OPERATION
                }, //operation description for BasicHttpBinding_IService_GetAllArcoBD
            },  // BasicHttpBinding_IService_GetAllArcoBD
            { // BasicHttpBinding_IService_DoWork
                {    // operation description for BasicHttpBinding_IService_DoWork
                    1,
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_DoWork_InputMessage, 
                    (WS_MESSAGE_DESCRIPTION*)&tempuri_org_wsdl.messages.IService_DoWork_OutputMessage, 
                    0,
                    0,
                    0,
                    0,
                    BasicHttpBinding_IService_DoWorkOperationStub,
                    WS_NON_RPC_LITERAL_OPERATION
                }, //operation description for BasicHttpBinding_IService_DoWork
            },  // BasicHttpBinding_IService_DoWork
            {    // array of operations for BasicHttpBinding_IService
                (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_Add.BasicHttpBinding_IService_Add,
                (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_GetAllXY.BasicHttpBinding_IService_GetAllXY,
                (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_GetAllArcoBD.BasicHttpBinding_IService_GetAllArcoBD,
                (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_DoWork.BasicHttpBinding_IService_DoWork,
            },    // array of operations for BasicHttpBinding_IService
            {    // contract description for BasicHttpBinding_IService
            4,
            (WS_OPERATION_DESCRIPTION**)tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.operations,
            },  // end of contract description for BasicHttpBinding_IService
        },    // BasicHttpBinding_IService
    }, //  end of contracts 
    {// policies
        {
            WS_ENCODING_XML_UTF8,
            WS_ADDRESSING_VERSION_TRANSPORT,
            WS_ENVELOPE_VERSION_SOAP_1_1,
            { // channelPropertiesArray
                {
                    WS_CHANNEL_PROPERTY_ENCODING,
                    (void*)&tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.encoding,
                    sizeof(tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.encoding),
                },
                {
                    WS_CHANNEL_PROPERTY_ADDRESSING_VERSION,
                    (void*)&tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.addressingVersion,
                    sizeof(tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.addressingVersion),
                },
                {
                    WS_CHANNEL_PROPERTY_ENVELOPE_VERSION,
                    (void*)&tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.envelopeVersion,
                    sizeof(tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.envelopeVersion),
                },
            },
        },   // end of BasicHttpBinding_IService,
    }, // policies
    {    // dictionary 
        { // xmlStrings
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/Add",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 0),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/AddResponse",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 1),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/GetAllXY",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 2),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/GetAllXYResponse",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 3),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/GetAllArcoBD",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 4),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/GetAllArcoBDResponse",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 5),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/DoWork",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 6),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/IService/DoWorkResponse",&tempuri_org_wsdlLocalDefinitions.dictionary.dict, 7),
        },  // end of xmlStrings
        
        {   // tempuri_org_wsdldictionary
        // 2b98b5c9-9005-4869-b836-76a329b2ac73 
        { 0x2b98b5c9, 0x9005, 0x4869, { 0xb8, 0x36, 0x76,0xa3, 0x29, 0xb2, 0xac, 0x73 } },
        (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings,
        8,
        TRUE,
        },
    },   //  end of dictionary
}; //  end of tempuri_org_wsdlLocalDefinitions


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
    __in_opt WS_ERROR* _error)
{
    void* _argList[3]; 
    _argList[0] = &x;
    _argList[1] = &y;
    _argList[2] = &AddResult;
    return WsCall(_serviceProxy,
        (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_Add.BasicHttpBinding_IService_Add,
        (const void **)&_argList,
        _heap,
        _callProperties,
        _callPropertyCount,
        _asyncContext,
        _error);
}

// operation: BasicHttpBinding_IService_GetAllXY
HRESULT WINAPI BasicHttpBinding_IService_GetAllXY(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __out unsigned int* GetAllXYResultCount, 
    __deref_out_ecount_opt(*GetAllXYResultCount) NoBD*** GetAllXYResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    void* _argList[2]; 
    _argList[0] = &GetAllXYResultCount;
    _argList[1] = &GetAllXYResult;
    return WsCall(_serviceProxy,
        (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_GetAllXY.BasicHttpBinding_IService_GetAllXY,
        (const void **)&_argList,
        _heap,
        _callProperties,
        _callPropertyCount,
        _asyncContext,
        _error);
}

// operation: BasicHttpBinding_IService_GetAllArcoBD
HRESULT WINAPI BasicHttpBinding_IService_GetAllArcoBD(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __out unsigned int* GetAllArcoBDResultCount, 
    __deref_out_ecount_opt(*GetAllArcoBDResultCount) ArcoBD*** GetAllArcoBDResult, 
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    void* _argList[2]; 
    _argList[0] = &GetAllArcoBDResultCount;
    _argList[1] = &GetAllArcoBDResult;
    return WsCall(_serviceProxy,
        (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_GetAllArcoBD.BasicHttpBinding_IService_GetAllArcoBD,
        (const void **)&_argList,
        _heap,
        _callProperties,
        _callPropertyCount,
        _asyncContext,
        _error);
}

// operation: BasicHttpBinding_IService_DoWork
HRESULT WINAPI BasicHttpBinding_IService_DoWork(
    __in WS_SERVICE_PROXY* _serviceProxy,
    __in WS_HEAP* _heap,
    __in_ecount_opt(_callPropertyCount) const WS_CALL_PROPERTY* _callProperties,
    __in const ULONG _callPropertyCount,
    __in_opt const WS_ASYNC_CONTEXT* _asyncContext,
    __in_opt WS_ERROR* _error)
{
    return WsCall(_serviceProxy,
        (WS_OPERATION_DESCRIPTION*)&tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.BasicHttpBinding_IService_DoWork.BasicHttpBinding_IService_DoWork,
        0,
        _heap,
        _callProperties,
        _callPropertyCount,
        _asyncContext,
        _error);
}
const _tempuri_org_wsdl tempuri_org_wsdl =
{
    {// messages
        {    // message description for IService_Add_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_Add_InputMessageactionName, // http://tempuri.org/IService/Add
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.Add, 
        },    // message description for IService_Add_InputMessage
        {    // message description for IService_Add_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_Add_OutputMessageactionName, // http://tempuri.org/IService/AddResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.AddResponse, 
        },    // message description for IService_Add_OutputMessage
        {    // message description for IService_GetAllXY_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllXY_InputMessageactionName, // http://tempuri.org/IService/GetAllXY
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllXY, 
        },    // message description for IService_GetAllXY_InputMessage
        {    // message description for IService_GetAllXY_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllXY_OutputMessageactionName, // http://tempuri.org/IService/GetAllXYResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllXYResponse, 
        },    // message description for IService_GetAllXY_OutputMessage
        {    // message description for IService_GetAllArcoBD_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllArcoBD_InputMessageactionName, // http://tempuri.org/IService/GetAllArcoBD
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllArcoBD, 
        },    // message description for IService_GetAllArcoBD_InputMessage
        {    // message description for IService_GetAllArcoBD_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_GetAllArcoBD_OutputMessageactionName, // http://tempuri.org/IService/GetAllArcoBDResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.GetAllArcoBDResponse, 
        },    // message description for IService_GetAllArcoBD_OutputMessage
        {    // message description for IService_DoWork_InputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_DoWork_InputMessageactionName, // http://tempuri.org/IService/DoWork
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.DoWork, 
        },    // message description for IService_DoWork_InputMessage
        {    // message description for IService_DoWork_OutputMessage
            (WS_XML_STRING*)&tempuri_org_wsdlLocalDefinitions.dictionary.xmlStrings.IService_DoWork_OutputMessageactionName, // http://tempuri.org/IService/DoWorkResponse
            (WS_ELEMENT_DESCRIPTION*)&tempuri_org_xsd.globalElements.DoWorkResponse, 
        },    // message description for IService_DoWork_OutputMessage
    }, // messages
    {// contracts
        {   // BasicHttpBinding_IService
            4,
            (WS_OPERATION_DESCRIPTION**)tempuri_org_wsdlLocalDefinitions.contracts.BasicHttpBinding_IService.operations,
        },    // end of BasicHttpBinding_IService
    }, // contracts
    { // policies
        {  // template description for BasicHttpBinding_IService
            {  // channel properties
                (WS_CHANNEL_PROPERTY*)&tempuri_org_wsdlLocalDefinitions.policies.BasicHttpBinding_IService.channelPropertiesArray,
                3,
            },
        },  // end of template description
    },  // policies
}; // end of _tempuri_org_wsdl

HRESULT BasicHttpBinding_IService_CreateServiceProxy(
    __in_opt WS_HTTP_BINDING_TEMPLATE* templateValue,
    __in_ecount_opt(proxyPropertyCount) const WS_PROXY_PROPERTY* proxyProperties,
    __in const ULONG proxyPropertyCount,
    __deref_out_opt WS_SERVICE_PROXY** _serviceProxy,
    __in_opt WS_ERROR* error)
{
    return WsCreateServiceProxyFromTemplate(
        WS_CHANNEL_TYPE_REQUEST,
        proxyProperties,
        proxyPropertyCount,
        WS_HTTP_BINDING_TEMPLATE_TYPE,
        templateValue,
        templateValue == NULL ? 0 : sizeof(WS_HTTP_BINDING_TEMPLATE),
        &tempuri_org_wsdl.policies.BasicHttpBinding_IService,
        sizeof(tempuri_org_wsdl.policies.BasicHttpBinding_IService),
        _serviceProxy,
        error);
}

HRESULT BasicHttpBinding_IService_CreateServiceEndpoint(
    __in_opt WS_HTTP_BINDING_TEMPLATE* templateValue,
    __in_opt CONST WS_STRING* address,
    __in_opt struct BasicHttpBinding_IServiceFunctionTable* functionTable,
    __in_opt WS_SERVICE_SECURITY_CALLBACK authorizationCallback,
    __in_ecount_opt(endpointPropertyCount) WS_SERVICE_ENDPOINT_PROPERTY* endpointProperties,
    __in const ULONG endpointPropertyCount,
    __in WS_HEAP* heap,
    __deref_out_opt WS_SERVICE_ENDPOINT** serviceEndpoint,
    __in_opt WS_ERROR* error)
{
    WS_SERVICE_CONTRACT serviceContract;
    serviceContract.contractDescription = &tempuri_org_wsdl.contracts.BasicHttpBinding_IService;
    serviceContract.defaultMessageHandlerCallback = 0;
    serviceContract.methodTable = (const void*)functionTable;
    
    return WsCreateServiceEndpointFromTemplate(
        WS_CHANNEL_TYPE_REPLY,
        endpointProperties,
        endpointPropertyCount,
        address,
        &serviceContract,
        authorizationCallback,
        heap,
        WS_HTTP_BINDING_TEMPLATE_TYPE,
        templateValue,
        templateValue == NULL ? 0 : sizeof(WS_HTTP_BINDING_TEMPLATE),
        &tempuri_org_wsdl.policies.BasicHttpBinding_IService,
        sizeof(tempuri_org_wsdl.policies.BasicHttpBinding_IService),
        serviceEndpoint,
        error);
}
