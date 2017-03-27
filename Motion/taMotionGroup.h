/*******************************************************************************************************************************
	manages a group of motions in order to define a specific behaviour

	Eg:
		In order to define an animation which goes from the far left to the far right frame
		on the x axis you have to have 2 motions

		first motion would be taMotion(stVector2Di(1, 0))
			this motion has a movement of +1 on the x axis / forwards

		second motion would be taMotion(stVector2Di(-1, 0))
			this motion has a movement of -1 on the x axis / backwards

		these 2 motions define the "there and back" behaviour
			this is just a name i kind of invented right now here
			you may be calling this one "shield"
			where the shield animates kinda pulse like

	Author: Alexander Bassov - 12.01.2017
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
class taMotionGroup :
	public sf::Texture,				// motion group specific texture
	public sf::Sprite				// motion group specific sprite
{
	//===========================================================================================================
	private:

		//=======================================================================================================
		// basic variables
		//
		static UINT										m_uiInstanceCount;								// counts the instances

		std::string										m_sLabel;										// designation of this motion group

		stVector2Di										m_vecStartFrame;
		std::forward_list<taMotion>						m_liMotionList;									// list of the motions
		std::forward_list<taMotion>::iterator			m_itCurrMotion;									// current selected motion

		std::unordered_map<int, taMotion*>				m_mMotionListRegister;							// contains the assigned iterator with the motion id

		const taConfiguration*							m_Configuration;								// a constant pointer to the configuration


		//=======================================================================================================
		// status variables
		//
		bool											m_bDone;										// done status of this motion group
		bool											m_bInternPermAnimate;							// internal permission to animate

		//=======================================================================================================
		// private intern functions
		//

		// resets the whole instance
		//
		void											reset();

		// checks the initialization state
		//
		// return true - when initialized
		// return false - when not initialized
		//
		bool											checkInitialization();


		// check if the motion id is valid
		//
		// param1	-	(const int) expects the motion id
		//
		// return ST_OK - the id is valid
		// return ST_CANCEL - when the id is negative
		// return ST_NOT_FOUND - when the id is not in the register
		//
		stState											checkMotionId(const int iMotionId);

		// defines the configuration
		//
		// param1	-	(const taConfiguration*) expects a pointer to the configuration of the motion controller
		//
		// return ST_OK - when the configuration has been set
		// return ST_FAIL - when the configuration is null
		//
		stState											setConfiguration(const taConfiguration* Configuration);

		// returns a usable id for a motion
		//
		// return int - usable motion id
		//
		int												getFreeMotionId();

		// returns a pointer to a motion
		//
		// param1	-	(const int) expects the motion id
		//
		// return taMotion* - when the motion has been found
		// return nullptr - when the motion has not been found
		//
		taMotion*										getMotionPtr(const int iMotion);


		// adds an entity into the register
		//
		// param1	-	(const taMotion*) expects the pointer to the entity in the list
		//									(or the one which will be inserted in to the list)
		//
		// return true - when the registration was successful
		// return false - when the id already exists
		//
		bool											addRegister(taMotion* MotionEntity);


	//===========================================================================================================
	public:

		//=======================================================================================================
		// initial methods - constructor/copy constructor/destructor
		//

		// constructor
		//
		// param1	-	(const std::string&) expects the designation for this group
		// param2	-	(optional) (const std::string&) expects the path to the motion group specific texture
		// param3	-	(optional) (const stVector2Di&) expects the startframe of this group
		//
														taMotionGroup(const std::string&			sLabel,
																	  const std::string&			sTexturePath = std::string(""),
																	  const stVector2Di&			vecStartFrame = stVector2Di(0));

		// destructor
		//
														~taMotionGroup();

		// copy constructor
		//
														taMotionGroup(const taMotionGroup& rhs);

		//=======================================================================================================
		// management
		//

		// assignment operator
		taMotionGroup&									operator=(const taMotionGroup& rhs);

		// comparisson operator
		bool											operator==(const taMotionGroup& rhs);

		// adds a motion to the motion list via instance
		//
		// param1	-	(const taMotion&) expects the motion as an instance
		//
		// return true - when the motion has been added
		// return false - when the motion is not initialized
		//
		bool											addMotion(const taMotion& Motion);

		// adds a motion to the motion list via separate definition
		//
		// param1	-	(const stVector2Di&) expects the movement of this motion
		// param2	-	(optional) (const int) expects the frame duration of this motion
		// param3	-	(optional) (const int) expects the position within the list
		//
		// return true - when the motion has been added
		// return false - when the motion has thrown a fail while initializing
		//
		bool											addMotion(const stVector2Di&		vecMovement,
																  const int					iDuration = -1,
																  const int					iListPosition = -1);

		// resets the current selected motion via position
		//
		// param1	-	(const int) expects the position of the motion in the list
		//
		// return true - when the current motion has been reselected
		// return false - when the position is out of range or the motion is invalid
		//
		bool											setCurrMotion(const int iPosition);


		//=======================================================================================================
		// set-functions
		//

		// defines the designation of this motion group
		//
		// param1	-	(const std::string) expects the designation
		//
		// return true - when the designation has been set
		// return false - when designation is empty
		//
		bool											setLabel(const std::string& sLabel);

		// defines the start frame
		//
		// param1	-	(const stVector2Di&) expects the start frame
		//
		// return true - when the start frame has been set
		// return false - when the start frame contains a negative value
		//
		bool											setStartFrame(const stVector2Di& vecStartFrame);

		// defines the motion list completely / the eventually existing motion list will be overwritten
		//
		// param1	-	(const std::list<taMotion>&) expects the motion list
		//
		// return true - when the motion list has been overwritten
		// return false - when the given motion list is empty (the existing one wont be touched)
		//
		bool											setMotionList(const std::forward_list<taMotion>& liMotionList);


		//=======================================================================================================
		// get-functions
		//

		// returns the label of this motion group
		//
		// return std::string() - the designation
		//
		std::string										getDesignation() const { return m_sLabel; }

		// returns the motion list
		//
		// return (const std::list<taMotion>) - the motion list
		//
		const std::forward_list<taMotion>				getMotionList() const { return m_liMotionList; }

		// returns a constant
		// when there is no motion in the list it returns a default constructed const iterator
		//
		// return std::list<taMotion>::const_iterator - current selected motion
		// return std::list<taMotion>::const_iterator() - default constructed const iterator
		//
		const taMotion									getCurrMotion() const { return *m_itCurrMotion; }

		// returns the done state whether this groups motion are animation or not
		//
		// return true/false - done/not done
		//
		bool											getDone() const { return m_bDone; }

		// returns the internal permission to animate
		//
		// return true/false - initialized/not initialized
		//
		bool											getInternPermAnimate() const { return m_bInternPermAnimate; }

}; // taConfiguration
//

//_______________________________________________________________________________________________________________




