/*******************************************************************************************************************************
	controlls and manages a list of motions group

	Author: Alexander Bassov - 13.01.2017
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
class taMotionController :
	public sf::Texture,				// global texture
	public sf::Sprite,				// global sprite
	public taConfiguration			// configuration
{
	//===========================================================================================================
	private:

		//=======================================================================================================
		// basic variables
		//
		static UINT										m_uiInstanceCount;								// counts the instances

		std::forward_list<taMotionGroup>				m_liMotionGroups;								// list of the motions
		std::forward_list<taMotionGroup>::iterator		m_itCurrMotionGroup;							// current motion

		taMotionGroup*									m_DefaultMotionGroup;							// default motion group
																										// this will be used when no motion group is requested
																										// but the animation is called to be started

		std::unordered_map<std::string, taMotionGroup*>	m_mMotionGroupRegister;							// list of the motion groups position within the motion group list

		//=======================================================================================================
		// status variables
		/* ... */

		//=======================================================================================================
		// private functions
		//

		// resets the object
		//
		void											reset();

	//===========================================================================================================
	public:

		//=======================================================================================================
		// initial methods - constructor/copy constructor/destructor
		//
														taMotionController();
														taMotionController(std::string sTexturePath);
														~taMotionController();
														taMotionController(const taMotionController& rhs) = delete;

		//=======================================================================================================
		// management
		//
		taMotionController&								operator=(const taMotionController& rhs) = delete;

		// adds motion group
		//
		// param1	-	(const taMotionGroup&) expects the motion group
		//
		// return true - when the motion group has been added
		// return false -	when the designation is empty
		//					when the motionlist is empty
		//					when the startframe is negative (well one of the two values)
		//
		bool											addMotionGroup(const taMotionGroup&			MotionGroup);

		// starts the animation
		//
		// param1	-	(optional) (const std::string&) expects the designation of the motion group
		//
		stState											start(const std::string sMotionGroup);

		// ends the current animation
		//
		// return ST_OK - when the animation has been stop
		// return ST_CANCEL - when there is nothing to stop
		//
		stState											stop();

		// updates the current running motion group
		//
		// param1	-	(const float) expects the passed time
		//
		// return ST_OK - when the update was successful
		// return ST_FAIL - when the update was not successful
		//
		stState											Update(const float fTime);

		// renders the texture
		//
		// param1	-	(const float) expects the passed time
		// param2	-	(const sf::RenderWindow&) expects the renderwindow of sfml
		//

		

		//=======================================================================================================
		// set/get-functions
		/* ... */

}; // Class
//

//_______________________________________________________________________________________________________________