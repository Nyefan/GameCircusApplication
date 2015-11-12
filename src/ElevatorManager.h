//============================================================================
// Name        : ElevatorManager.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description :
// Notes       : Floors are assumed to be 0-indexed
//============================================================================

#pragma once

#include "Elevator.h"

class ElevatorManager : public GameObject {

public:
	const int numFloors = 5;
private:
	int lastFloor;
	int nextFloor;
	int nextAvailableFloor;
	bool directionIsUp = false;
	int floorCalls[5] = {false, false, false, false, false};
	Elevator* myElevator = new Elevator();

public:
	~ElevatorManager();
	void Init();
	void Update();
	void OnAction();
private:
	int RequestFloor();
	bool QueueIsEmpty();
	bool QueueAboveIsEmpty();
	bool QueueBelowIsEmpty();
};

