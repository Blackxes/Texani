/*******************************************************************************************************************************
	configuration of one texture animation

	Author: Alexander Bassov - 08.01.2017
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
/* ... */

//_______________________________________________________________________________________________________________
// makros/defines
#define TA_DEFAULT_FRAME_DURATION int(30)			// in frames
#define TA_DEFAULT_RENDER_UPDATE float(60)			// in frames
#define TA_DEFAULT_UPDATE float(0.025)				// in seconds

//_______________________________________________________________________________________________________________
// global variables/extern declaration
/* ... */

//_______________________________________________________________________________________________________________
// forwarddeclaration
/* ... */

//_______________________________________________________________________________________________________________
// structs/enums/etc.
//





//_______________________________________________________________________________________________________________
// declaration and definition
class taConfiguration
{
	// friends
	friend class taMotionController;

	//===========================================================================================================
	private:

		//=======================================================================================================
		// basic variables
		//
		static UINT										m_uiInstanceCount;								// counts the instances

		int												m_iFPS;											// general fps
		float											m_fRenderUpdate;								// when happens the render update
		float											m_fRenderUpdateTimer;							// render timer
		float											m_fUpdate;										// when happens a regular update
		float											m_fUpdateTimer;									// update timer

		float											m_fVelocity;									// speed of animation
		stVector2Di										m_vecFrames;									// frames on both axises
		stVector2Di										m_vecFrameSize;									// size of each frame
		stVector2Di										m_vecCurrFrame;									// current frame

		std::string										m_sTexturePath;									// defines the path of the texture

		//=======================================================================================================
		// status variables
		//
		bool											m_bPermAnimate;									// permission to be allowed to animate

		//=======================================================================================================
		// private functions
		//

		// defines the current frame
		//
		// param1	-	(const stVector2D) expects the current frame as vector
		//
		// return true - when the frame has been set
		// return false - when on of the values is negative
		//
		bool											setCurrFrame(const stVector2Di& vecCurrFrame);


	//===========================================================================================================
	public:

		//=======================================================================================================
		// initial methods - constructor/copy constructor/destructor
		//
														taConfiguration();
														~taConfiguration();
														taConfiguration(const taConfiguration& rhs);

		//=======================================================================================================
		// management
		//
		taConfiguration									operator=(const taConfiguration& rhs);

		//=======================================================================================================
		// set-functions
		//

		// defines the speed of the animation
		//
		// param1	-	(const float) expects the speed of animation
		//
		void											setVelocity(const float fVelocity);

		// defines the frames of the axises (Eg. X 2 Frames Y 3 Frames | stVector2Di(2, 3);
		//
		// param1	-	(const stVector2Di) expects the frames of each axis as a vector
		//
		// return true - when the frames have been set
		// return false - when the frames are negative (or one of them)
		//
		bool											setFrames(const stVector2Di& vecFrames);

		// defines the frames of each axis (x/y) separatly
		//
		// param1	-	(const int) expects the frames on the x axis
		// param2	-	(const int) expects the frames on the y axis
		//
		// return true - when the frames have been set
		// return false - when one of the value has a negative value	
		//
		bool											setFrames(const int iX, const int iY);

		// defines the framesize via vector
		//
		// param1	-	(const stVector2Di) expects the framesize
		//
		// return true - when the framesize has been set
		// return false - when the framesize is on one side negative
		//
		bool											setFramesize(const stVector2Di& iFramesize);

		// defines the framesize separatly
		//
		// param1	-	(const int) expects the framesize
		//
		// return true - when the framesize has been set
		// return false - when one of the values are negative
		//
		bool											setFramesize(const int iWidth, const int iLength);

		// defines the permission to animate
		//
		// param1	-	(const bool) expects the permission
		//
		void											setPermAnimate(const bool bPermission);

}; // taConfiguration
//

//_______________________________________________________________________________________________________________




