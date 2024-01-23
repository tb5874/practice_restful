//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// [ notice ]
// 
// indent :  4 space
// integer : int64_t
// floating point : float32
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////////////

// dll - export, import
#if ( defined(_WIN32) || defined(_WIN64) )

#ifdef EXPORT_FLAG
#define DLL_FLAG __declspec(dllexport)
#else
#define DLL_FLAG __declspec(dllimport)
#endif

#elif ( defined(__unix__) || defined(__linux__) )

#ifdef EXPORT_FLAG
#define DLL_FLAG __attribute__((__visibility__("default")))
#else
#define DLL_FLAG __attribute__((__visibility__("default")))
#endif

#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

//////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" DLL_FLAG void empty_lib(void);

//////////////////////////////////////////////////////////////////////////////////////////////////////
