// Int386w.cpp: implementation of the Int386w class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "INT386W.hpp"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Int386w::Int386w(LPSTR Command, UINT bufferSize, UINT encryption, UINT tickle )
{
	id = 0;
	loadError = 0;
	int temp = LoadProlog( Command, bufferSize, encryption, tickle );

	if( temp > 0 )
	{
		id = temp;
		loadError = 0;
	} else
	{ 
		id = 0;
		loadError = temp;
	}

}

Int386w::~Int386w()
{
	if( id ) HaltProlog( id );
	id = 0;
}


// Setup a goal for this instance
LPSTR Int386w::initGoal( LPSTR Goal )
{
	return InitGoal( id, Goal );
}

// Call a previously setup goal for this instances
LPSTR Int386w::callGoal()
{
	return CallGoal( id );
}


// Exit a goal, bringing the previous goal to the top of the goal stack
BOOL Int386w::exitGoal()
{
	return ExitGoal(id);
}


// Tell a goal
LPSTR Int386w::tellGoal( LPSTR Goal )
{
	return TellGoal( id, Goal );
}


// Call a goal once only
LPSTR Int386w::callOneGoal(LPSTR Goal)
{
	strcpy_s( m_text, InitGoal( id, Goal ) );
	strcpy_s( m_text, CallGoal( id ) );
	ExitGoal( id );

	return( m_text );
}


