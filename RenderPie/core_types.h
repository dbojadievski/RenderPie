#pragma once

typedef void * HANDLE;
typedef unsigned char BYTE;

typedef int BOOL;
typedef BYTE BOOLEAN;

typedef char CCHAR;
typedef char CHAR;

#define CONST const

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned int DWORD32;
typedef unsigned __int64 DWORDLONG;
typedef unsigned __int64 DWORD64;

#if defined(_WIN64)
typedef unsigned __int64 ULONG_PTR;
#else
typedef unsigned long ULONG_PTR;
#endif

typedef ULONG_PTR DWORD_PTR;
typedef unsigned __int64 * DWORDLONG_PTR;

typedef float FLOAT;
typedef FLOAT REAL;

typedef int INT;
#if defined(_WIN64) 
typedef __int64 INT_PTR;
#else 
typedef int INT_PTR;
#endif

typedef signed char INT8;
typedef signed short INT16;
typedef unsigned __int16 WORD;
typedef signed int INT32;
typedef signed __int64 INT64;

typedef unsigned short UINT16;

typedef INT32 LONG32;
typedef INT64 LONG64;
typedef LONG32 LONG;

typedef CHAR *LPSTR;
#if defined(_WIN64)
typedef __int64 LONG_PTR;
#else
typedef long LONG_PTR;
#endif


#ifdef _WIN64
typedef int HALF_PTR;
#else
typedef short HALF_PTR;
#endif

#define CALLBACK __stdcall

//#endif

