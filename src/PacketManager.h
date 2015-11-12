//============================================================================
// Name        : PacketManager.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Client-side throttler to prevent server overload
// Notes       : This should be compiled using c++11 or higher
//============================================================================

#pragma once

#include <queue>
#include <cstring>
#include "NetworkConnection.h"

class PacketManager {

public:
	static const int MAX_SIZE = 1024; //bytes
	static constexpr float PACKET_RATE = 1./30.; //seconds
private:
	static unsigned int packetNumber; //this should be initialized to 0 since it's static, but some implementations are inconsistent with the standard
	const unsigned char* prependStr = reinterpret_cast<const unsigned char*>("PKT_");
	struct packet {
		packet(unsigned char* p, unsigned int ps) {packetData = p; packetSize = ps;}
		unsigned char* packetData;
		unsigned int packetSize;
	};
	std::queue<packet*> packetQueue;

public:
	PacketManager();
	PacketManager(bool resetPacketCount); // Call this with false to create a new instance without resetting the packet number
	void Update (float secondsSinceLastUpdate);
	void Send (unsigned char* packetData, unsigned int packetSize);
private:
	void AffixHeader(unsigned char* newPacketData, unsigned char* packetData, unsigned int packetSize);
	void ConcatPackets(unsigned char* first, unsigned int firstSize, unsigned char* second, unsigned int secondSize);
};
