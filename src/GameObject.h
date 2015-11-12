//============================================================================
// Name        : GameObject.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description :
//============================================================================

#pragma once

class GameObject {

public:
	GameObject() {};
	virtual ~GameObject() {};
	int Identifier() {}; /// returns a number that uniquely identifies an instance of a GameObject.  This identifier is generated in the constructor.
	static GameObject * FirstObject() {}; /// Used to iterate through the world's GameObjects.  This returns the first object in the world. A null is returned if there are no objects in the world.
	static GameObject * NextObject() {}; /// Used to iterate through the world's GameObjects.  This returns the next object in the world.  A call to FirstObject() resets the internal iterator to the start of the object list.  A null is returned if there are no more objects to iterate through.
	virtual void Init() {}; /// Called once all objects in the scene have been loaded.  Called from the GameObject's constructor for objects created after scene load.
	virtual void Update() {}; /// Called once per frame.  The GameObject's Init() method is guaranteed to have been called before the first call to Update ();
	virtual void OnAction() {}; /// Called once when a player or other entity interacts with the object.
};
