/*******************************************************************************************************************************
	defines a specific behaviour of a defined frame range

	Example:
		forwards on the same axis from the beginning

	Author: Alexander Bassov - 08.01.2017
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
//





//_______________________________________________________________________________________________________________
// declaration and definition
class taMotion
{
	// friends
	friend class taMotionGroup;
	friend inline bool operator==(const taMotion& a, const taMotion& b);

	//===========================================================================================================
	private:

		//=======================================================================================================
		// basic variables
		//
		static UINT										m_uiInstanceCount;								// counts the instances

		int												m_iMotionId;									// identification of this motion / cant be negative
		int												m_iDuration;									// frames this motion will take / cant be negative
		stVector2Di										m_vecMovement;									// movement of this motion (Example (1 / 0) x positivly / y neutral) 

		//=======================================================================================================
		// status variables
		//
		bool											m_bInitialized;										// state of initialization

		//=======================================================================================================
		// private set-functions
		//

		// resets the object
		//
		void											reset();

		// defines the motion id
		//
		// param1	-	(int) expects the identification number
		//
		// return true - when the id has been set
		// return false - when the id is negative
		//
		bool											setMotionId(int iMotionId);


	//===========================================================================================================
	public:

		//=======================================================================================================
		// initial methods - constructor/copy constructor/destructor
		//

		// constructor
														taMotion();
	
		// constructor
		//
		// param1	-	(const stVector2Db) expects the movement for this motion
		// param2	-	(optional) (const int) expects the duration in frames for this motion
		//										
														taMotion(const stVector2Di		vecMovement, 
															 const int				iDuration = -1);

														//
														~taMotion();
														taMotion(const taMotion& rhs);

		//=======================================================================================================
		// management
		//

		// assignment Operator 
		taMotion&										operator=(const taMotion& rhs);

		// initialization
		//
		// param1	-	(const stVector2Di&) expects the movement of this motion
		// param2	-	(optional) (const int) expects the frame duration of this motion
		//
		// return true - when the initialization was successful
		// return false - when the duration was negative
		//
		bool											Init(const stVector2Di& vecMovement, const int iDuration = -1);


		//=======================================================================================================
		// manipulations

		//=======================================================================================================
		// set-functions
		//

		// defines the duration of this motion
		//
		// param1	-	(int) expects the duration of this motion in frames
		//
		// return true - when the duration has been set
		// return false - when the duration is negative
		//
		bool											setDuration(const int iDuration);

		// defines the movement of this motion
		//
		// param1	-	(stVector2Db) expects the movement of this motion as a vector of the type stVector2Di
		//
		void											setMovement(const stVector2Di vecMovement);


		//=======================================================================================================
		// get-functions
		//

		// returns the identification number of this motion
		//
		// return int() - the identification number
		//
		int												getMotionId() const { return m_iMotionId; }

		// returns the duration in frames of this motion
		//
		// return int() - the frame duration of this motion
		//
		int												getDuration() const { return m_iDuration; }

		// returns the movement of this motion
		//
		// return stVector2Db - the movement of this motion
		//
		stVector2Di										getMovement() const { return m_vecMovement; }

		// returns the state of the initialization
		//
		// return true - initialized
		// return false - not inititialized
		//
		bool											getInitialized() const { return m_bInitialized; }


}; // taConfiguration
//

//_______________________________________________________________________________________________________________
// after class header
#include <Core/Motion/taMotion.inl>

//_______________________________________________________________________________________________________________
//




