//============================================================================
// Name        : GameObject.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description :
//============================================================================

#pragma once

#include "GameObject.h"

class Elevator : public GameObject {
public:
	Elevator() {};
	virtual ~Elevator();
	int IsMoving() {}; /// Returns 0 if the elevator car is stopped at a floor, 1 if the elevator car is moving.
	int GetFloor() {}; /// Gets the current floor that the elevator car is on.  If the elevator is moving, this returns the floor the elevator most recently passed or stopped at.
	void MoveUp(int numberOfFloors) {}; /// Tells the elevator car to move up numberOfFloors.  Multiple calls will add to the previously requested floor movement.
	void MoveDown(int numberOfFloors) {}; /// Tells the elevator car to move down numberOfFloors.  Multiple calls will add to the previously requested floor movement.
	void Stop() {}; /// Tells the elevator car to stop at the next floor, discarding any additional move requests added by the MoveUp () or MoveDown () calls.
	void OpenDoor() {}; /// Opens the elevator door.
	void CloseDoor() {}; /// Closes the elevator door.
	int IsDoorClosed() {}; /// Returns 0 if the elevator door is open, 1 if the elevator door is closed.
	void Init() {};
	void OnAction() {};
	void Update() {};
};

