#include "StdAfx.h"
#include <process.h>

GlobalStore GlobalData;

void main()
{
	AudioStore.SetCacheDuration( 10 );
//	AudioStore.DebugForceStopRecordSeconds = 20;

	ServerNetwork NetworkSender( "127.0.0.1", "6969" );

	printf("Waiting for connection\n");
	while( NetworkSender.HasConnections() == 0 )
	{
		Sleep( 10 );
	}
	printf("Started record\n");
//	RecordAudioStream( );
	_beginthread( RecordAudioStream, 0, (void*)NULL );
//	_beginthread( SendAudioStream, 0, (void*)NULL );
	Sleep( 1000 );	//infinite echo incoming if tested on same PC
	printf("Done record\n");
	printf("Started playback\n");
	PlayAudioStream( NULL );
	printf("Done playback\n");
}