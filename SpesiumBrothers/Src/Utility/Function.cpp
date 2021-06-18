#include "Function.h"

#include "../Definition.h"

Function::Function() :
    progressTime( 0.0 ) {
    timeFreq.QuadPart = 0;
    timeStart.QuadPart = 0;
    timeEnd.QuadPart = 0;
}

void Function::LockFPSHead() {
    QueryPerformanceFrequency( &timeFreq );
    QueryPerformanceCounter( &timeStart );
}

void Function::LockFPSTail() {
    QueryPerformanceCounter( &timeEnd );
    progressTime = static_cast<double>( timeEnd.QuadPart - timeStart.QuadPart ) / static_cast<double>( timeFreq.QuadPart );
    if ( progressTime < 1 / FPS ) {
        DWORD sleepTime = static_cast<DWORD>( ( 1 / FPS - progressTime ) * 1000 );
        WaitTimer( sleepTime );
    }
}
