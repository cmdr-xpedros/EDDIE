// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define _WIN32_WINNT 0x0500
    #include <windows.h>
#else
    #include <stdio.h>
#endif // _WIN32

#include <iostream>
#include <fstream>
