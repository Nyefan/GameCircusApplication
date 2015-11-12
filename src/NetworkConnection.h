//============================================================================
// Name        : NetworkConnection.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Spoof class for testing PacketManager
//============================================================================

#pragma once

class NetworkConnection {

public:
	static void TransmitData(unsigned char* data, int dataSize);
};
