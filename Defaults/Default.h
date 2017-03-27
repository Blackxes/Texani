/*******************************************************************************************************************************
	
	Version: 1.0

	default declarations/includes/macros/etc.

	Autor: Alexander Bassov - 03.01.2016

*******************************************************************************************************************************/
#pragma once
//

// define dll export/import
#ifndef DEFAULT_API
	#define DEFAULT_API __declspec(dllexport)
#else
	#define DEFAULT_API __declspec(dllimport)
#endif

//_______________________________________________________________________________________________________________
// include sfml
#include <SFML/Graphics.hpp>
// #include <SFML/Config.hpp>
// #include <SFML/Audio.hpp>
// #include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//_______________________________________________________________________________________________________________
// default header
#include <time.h>
#include <assert.h>
#include <iostream>
#include <typeinfo>
#include <list>
#include <forward_list>
#include <string>
#include <fstream>
#include <memory>
#include <math.h>
// #include <vector>
// #include <sstream>
// #include <sys/stat.h>
// #include <tuple>
//#include <map>
#include <unordered_map>
// #include <algorithm>

//_______________________________________________________________________________________________________________
// general declarations and macros
#define MAX(a,b)			if (a < b) ? b : a
#define MIN(a,b)			if (a < b) ? a : b
#define PI					3.1415926535897932384626433832795
#define SAFE_DELETE(x)		delete (x); if (x != nullptr) (x) = nullptr

// simplification
#define and &&
#define or ||

// unsigned datatypes
typedef bool			BOOL;
typedef unsigned int	UINT;
typedef unsigned short	USHORT;
typedef unsigned char	UCHAR;

// default values for rendering and updates
#define DEFAULT_UPDATE_FPS		0.25	// updates every x second
#define DEFAULT_RENDER_FPS		60		// render fps

//_______________________________________________________________________________________________________________
// states
enum stState
{
	ST_NONE,			// no state
	ST_OK,
	ST_FAIL,
	ST_NOT_FOUND,
	ST_INCORRECT,		// when something went almost nice but something still messed up
	ST_OUT_OF_RANGE,	// when the id is out of range
	ST_CANCEL,
	ST_COUNTER,			// enum item counter

}; // stState
//

//-------------------------------------------------------
// files state
enum stDatastate
{
	DS_NONE,			// no state
	DS_OK,
	DS_DAMAGED,
	DS_FAULTY,			// file was found and is actually fine but something is still bad
	DS_EMPTY,
	DS_NOT_FOUND,
	DS_NOT_GIVEN,		// filename is not given
	DS_COUNTER,			// enum item counter

}; // stDatastate
//

//-------------------------------------------------------
// files content state
enum stDataContentState
{
	DCS_NONE,			// Kein Status
	DCS_OK,				// contains content
	DCS_EMPTY,			// empty as my cup of tea :(
	DCS_COUNTER,		// enum item counter
};

//-------------------------------------------------------
// collection of some information about a file
//
// example: "path/to/my/file.txt"
//
struct stFileinfo
{
	std::string			sFilerel		= "";								// full filename / relativer Dateipfad		- "file.txt"
	std::string			sFileabs		= "";								// absolute filename / absoluter Dateipfad	- "file"
	std::string			sDatatype		= "";								// datatype									- ".txt"
	std::string			sPathabs		= "";								// full path								- "path/to/my/file.txt"
	std::string			sPathrel		= "";								// path to file								- "path/to/my/"
	stDatastate			State			= stDatastate::DS_NONE;				// files state
	stDataContentState	ContentState	= stDataContentState::DCS_NONE;		// files content state
};

//_______________________________________________________________________________________________________________
// methods
/* ... */

//_______________________________________________________________________________________________________________
// variables/instances
/* ... */

//_______________________________________________________________________________________________________________
// forward declared constants
// const std::string			g_PathToRes					= "res/";

//_______________________________________________________________________________________________________________
// include files
/* ... */

//_______________________________________________________________________________________________________________
//