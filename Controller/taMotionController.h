/*******************************************************************************************************************************
	controlls a list of motions

	Author: Alexander Bassov - 10.01.2017
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
/* ... */

//_______________________________________________________________________________________________________________
// makros/defines
/* ... */

//_______________________________________________________________________________________________________________
// global variables/extern declaration
/* ... */

//_______________________________________________________________________________________________________________
// forwarddeclaration
/* ... */

//_______________________________________________________________________________________________________________
// structs/enums/etc.
/* ... */





//_______________________________________________________________________________________________________________
// declaration and definition
class taMotionController
{
	//===========================================================================================================
	private:

		//=======================================================================================================
		// basic variables
		//
		static UINT									m_uiInstanceCount;								// counts the instances

		std::list<taMotion*>						m_liMotions;									// list of the motions
		std::list<taMotion*>::iterator				m_currMotion;									// current motion

		std::map<std::string, int>					m_mMotionRegister;								// list of the motions position within the motionlist

		//=======================================================================================================
		// status variables
		//
		bool										m_bPermAnimate;

		//=======================================================================================================
		// management
		//

		// set the current 

	//===========================================================================================================
	public:

		//=======================================================================================================
		// initial methods - constructor/copy constructor/destructor
		//
													taMotionController();
													~taMotionController();
													taMotionController(const taMotionController& rhs) = delete;

		//=======================================================================================================
		// management
		//
		taMotionController							operator=(const taMotionController& rhs) = delete;

		// adds a motion to the current motion list via direct definition
		//
		// param1	-	(taMotion) expects an instance of the motion class
		//
		// return true - when the motion has been added
		// return false - when the motion couldnt be added
		//
		bool										addMotion(const taMotion& Motion);

		// adds a motion to the current motion list via absolute definition
		//
		// param1	-	(UINT) expects the frame duration for this motion
		// param2	-	(stVector2Di) expects the movement of this motion
		//
		// return true - when the motion has been added
		// return false - when the motion couldnt be added
		//
		//bool										addMotion(const UINT iFrames, const stVector2Di vecMovement);

		// removes a motion from the list
		//
		// param1	-	(std::string) expects the designation of the motion
		//
		// return true - when the motion has been removed
		// return false - when the motion couldnt be found
		//
		bool										removeMotion(const std::string sDesignation);

		// replaces a motion
		//
		// param1	-	(std::string) expects the motion which will be replaced
		// param2	-	(taMotion) expects the motion which will be placed onto the new spot
		//
		// return true - when the motion has been replaced
		// return false - when the motion couldnt be found
		//
		bool										replaceMotion(const std::string sDesignation, const taMotion& Motion);

		//=======================================================================================================
		// set/get-functions
		/* ... */

}; // Class
//

//_______________________________________________________________________________________________________________