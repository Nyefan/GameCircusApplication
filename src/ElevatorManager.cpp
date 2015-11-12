//============================================================================
// Name        : ElevatorManager.cpp
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description :
// Notes       : Floors are assumed to be 0-indexed
//============================================================================

#include "ElevatorManager.h"

ElevatorManager::~ElevatorManager() {
	delete myElevator;
}

void ElevatorManager::Init() {
	lastFloor = myElevator->GetFloor();
	nextFloor = -1;
	nextAvailableFloor = -1;
}

void ElevatorManager::Update() {
	// This should probably be a switch statement

	// if the door is open, close the door end
	// if the elevator is stopped,
	//   and the elevator has been requested to this floor, open the door and register a call complete end
	//   and the elevator has been requested on a floor in the direction it's traveling, move to that floor end
	//   and the elevator has been requested on a floor not in the direction it's traveling, move to that floor end
	// end
	// if the elevator is moving,
	//   and the elevator has been requested on the next floor in the direction it's traveling, stop end
	// end

	if(!myElevator->IsDoorClosed()) {
		myElevator->CloseDoor();
	} else if (!myElevator->IsMoving()) {
		lastFloor = myElevator->GetFloor();
		if(floorCalls[lastFloor]) {
			myElevator->OpenDoor();
			floorCalls[lastFloor] = false;
		} else if(directionIsUp) {
			if(!QueueAboveIsEmpty()) {
				nextFloor = nextAvailableFloor;
				myElevator->MoveUp(nextFloor-lastFloor);
			} else if(!QueueBelowIsEmpty()) {
				directionIsUp = false;
				nextFloor = nextAvailableFloor;
				myElevator->MoveDown(lastFloor-nextFloor);
			} else { // if(QueueIsEmpty)
				nextFloor = -1; //nextAvailableFloor is already set to -1 by QAIE and QBIE
			}
		} else { // if(!directionIsUp)
			if(!QueueBelowIsEmpty()) {
				nextFloor = nextAvailableFloor;
				myElevator->MoveDown(lastFloor-nextFloor);
			} else if(!QueueAboveIsEmpty()) {
				directionIsUp = true;
				nextFloor = nextAvailableFloor;
				myElevator->MoveUp(nextFloor-lastFloor);
			}
		}
	} else { // if(DoorIsClosed&&ElevatorIsMoving)
		lastFloor = myElevator->GetFloor();
		if(directionIsUp) {
			if(!QueueAboveIsEmpty()) {
				if(nextFloor!=nextAvailableFloor && nextAvailableFloor==lastFloor+1) {
					myElevator->Stop();
				} // else {continue;}
			} else {
				// this should never happen unless the elevator is given the ability to cancel calls
				myElevator->Stop();
			}
		} else { // if(!directionisUp)
			if(!QueueBelowIsEmpty()) {
				if(nextFloor!=nextAvailableFloor && nextAvailableFloor!=lastFloor-1) {
					myElevator->Stop();
				}
			} else {
				// this should never happen unless the elevator is given the ability to cancel calls
				myElevator->Stop();
			}
		}
	}
}

void ElevatorManager::OnAction() {
	int temp = RequestFloor();
	if(temp > -1 && temp < 5) {
		floorCalls[temp] = true;
	}
}

int ElevatorManager::RequestFloor() {
	// interact with whatever gameObject made the OnAction call
}

bool ElevatorManager::QueueIsEmpty() {
	for (int i = 0; i < numFloors; i++) {
		if(floorCalls[i]) {return false;}
	} nextAvailableFloor = -1; return true;
}

bool ElevatorManager::QueueAboveIsEmpty() {
	for (int i = lastFloor; i < numFloors; i++) {
		if(floorCalls[i]) {nextAvailableFloor = i; return false;}
	} return true;
}

bool ElevatorManager::QueueBelowIsEmpty() {
	for (int i = lastFloor; i >= 0; i--) {
		if(floorCalls[i]) {nextAvailableFloor = i; return false;}
	} return true;
}
