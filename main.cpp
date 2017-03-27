/*******************************************************************************************************************************
	main stuff

	Author: Alexander Bassov - 08.01.2017
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
#include <Core/Includer/taIncluder.h>

// prints out a line
void lOut(char lineChar = '=', int length = 15)
{
	std::string s = "";

	for (int i = 0; i < length; i++)
		s += lineChar;

	std::cout << s << std::endl;
}

// comment
void cOut(std::string s)
{
	std::cout << "# " << s << std::endl;
}

// comment
void sOut(int count = 1)
{
	std::string s = "";

	for (int i = 0; i < count; i++)
		s += "\n";

	std::cout << s;
}

// prints out tabed content
void tOut(std::string sContent)
{
	std::cout << "\t" << sContent << std::endl;
}

// prints out content
void Out(std::string sContent)
{
	std::cout << sContent << std::endl;
}



//_______________________________________________________________________________________________________________
// main
int main()
{



	
	taMotionGroup Move("move", "texture/move.png");
	Move.addMotion(stVector2Di(1, 0));

	//Texani Anitex;
	//Anitex.addMotionGroup(taMotionGroup("", stVector2Di());

	//Anitex.addMotionGroup();
















	//
	/*
	taMotionController* Controller = new taMotionController("path");

	{
		taMotion Motion1(stVector2Di(1, 0));

		taMotionGroup GroupMove("move", stVector2Di(0, 0));
		GroupMove.addMotion(Motion1);

		taMotionGroup GroupAttack("attack", stVector2Di(0, 1));
		GroupAttack.addMotion(stVector2Di(1, 0));
		GroupAttack.addMotion(stVector2Di(1, 1));

		//
		Controller->addMotionGroup(GroupMove);
		Controller->addMotionGroup(GroupAttack);
	}

	SAFE_DELETE(Controller);
	*/

	

	getchar();











	// intro
	/*
	cOut("taMotion test");
	lOut();
	sOut(2);

	// create instance and start defining
	{
		cOut("Creating Instance of taMotion");
		taMotion Motion1;
		sOut();

		cOut("Creating Instance of taMotion with parameter");
		taMotion Motion2(30, stVector2Di(0, 0));

		sOut();
		cOut("Leaving Scope");
	}

	cOut("Left Scope");
	lOut();
	sOut();

	cOut("Create Instance and define");
	taMotion testMotion;

	sOut();
	cOut("set duration");
	testMotion.setDuration(40);
	Out("new duration: " + std::to_string(testMotion.getDuration()));

	sOut();
	cOut("set movement");
	testMotion.setMovement(stVector2Di(40, 10));
	Out("new movement: " + std::to_string(testMotion.getMovement().x) + ":" + std::to_string(testMotion.getMovement().y));

	sOut();
	cOut("set motion id");
	testMotion.setMotionId(7);
	Out("new motion id: " + std::to_string(testMotion.getMotionId()));
	*/


	// motion group controller
	//taMotionGroup Attack;

	//Attack.addMotion()

	//Controller.addMotionGroup;

	/*
	taMotion motion(30, stVector2Di(1, 0));
	motion.setMovement(stVector2Di(-2, 4));
	motion.setDuration(40);
	motion.setMotionId(1);

	taMotionGroup group;
	group.addMotion(taMotion(2, stVector2Di(3)));
	group.addMotion(motion);
	


	taMotion motionCopy(motion);

	motion;
	motionCopy;
	*/

	/*
	// Hauptinstanz erzeugen
	Texani* Instance = new Texani;

	// Animationsgruppen
	//
	// Angriff
	taMotionGroup Attack("pfad/zur/angriffs_textur", "attack");
	Angriff.addMotion(15, stVector2Di(1, 0));
	Angriff.addMotion(15, stVector2Di(-1, 0));
	// Gruppe hinzufügen
	Instance->addMotionGroup(Attack);

	// Verteidigung
	taMotionGroup Defense("pfad/zur/verteidigungs_textur", "defense");
	Angriff.addMotion(30, stVector2Di(1, 0));
	// Gruppe hinzufügen
	Instance->addMotionGroup(Defense);

	// Standardanimation setzen
	// Die Standardanimation definiert sich selbst
	// indem sie die erste Animationsgruppe als Standard nimmt
	Instance->setDefaultMotionGroup("attack");

	// Animations starten
	Instance->startAnimation();

	// Beenden
	Instance->endAnimation();

	// Starte bestimme animation
	Instance->startAnimation("defense");

	// brutale zerstörung der Instanz
	delete Instance;
	Instance = nullptr;
	*/
		getchar();
	/*
	
	std::list<std::string> li;
	std::list<std::string>::iterator it;

	std::map<std::string, int> map;

	std::string des = "att";
	li.push_back(des);
	map.insert(std::make_pair<std::string, int>(des.data(), (int) li.size() - 1) );

	des = "def";
	li.push_back(des);
	map.insert(std::make_pair<std::string, int>(des.data(), (int) li.size() - 1) );

	it = li.begin();
	std::advance(it, map["def"]);

	std::cout << *it << std::endl;

	*/

	/*
	
	//
	int currentFrame = 1;

	// x +1
	taMotion Motion1 = taMotion(1, stVector2Di(1, 0));

	// x +5
	taMotion Motion2 = taMotion(1, stVector2Di(5, 0));

	// x -2
	taMotion Motion3 = taMotion(1, stVector2Di(-2, 0));

	Texani Tex;

	Tex.addMotion(Motion1);
	Tex.addMotion(Motion2);
	Tex.addMotion(Motion3);

	*/

	//
	return 0;

} // main
//

//_______________________________________________________________________________________________________________