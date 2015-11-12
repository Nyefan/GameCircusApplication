//============================================================================
// Name        : PacketManager.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Client-side throttler to prevent server overload
// Notes       : This should be compiled using c++11 or higher
//============================================================================

#include "PacketManager.h"

unsigned int PacketManager::packetNumber;

PacketManager::PacketManager() {
	packetNumber = 0;
}

PacketManager::PacketManager(bool resetPacketCount) {
	if (resetPacketCount) {
		packetNumber = 0;
	}
}

void PacketManager::Update (float secondsSinceLastUpdate) {
	if (secondsSinceLastUpdate < PACKET_RATE) {
		return;
	} else if (packetQueue.empty()) {
		return;
	} else {
		unsigned char tempStr[MAX_SIZE];
		unsigned int currentSize = 0;
		packet* tempPacket;
		do {
			tempPacket = packetQueue.front();
			ConcatPackets(tempStr, currentSize, tempPacket->packetData, tempPacket->packetSize);
			currentSize+=tempPacket->packetSize;
			packetQueue.pop();
		} while (currentSize+MAX_SIZE < packetQueue.front()->packetSize);
		NetworkConnection::TransmitData(tempStr, currentSize);
	}
}

void PacketManager::Send (unsigned char* packetData, unsigned int packetSize) {
	unsigned char newPacketData[packetSize+8];
	AffixHeader(newPacketData, packetData, packetSize);
	packetNumber++;
	packet* wrapper = new packet(newPacketData, packetSize+8);
	packetQueue.push(wrapper);
}

void PacketManager::AffixHeader(unsigned char* newPacketData, unsigned char* packetData, unsigned int packetSize) {
	memcpy(newPacketData, prependStr, 4);
	memcpy(newPacketData+4, &packetSize, sizeof(packetSize));
	memcpy(newPacketData+8, packetData, packetSize);
}

void PacketManager::ConcatPackets(unsigned char* first, unsigned int firstSize, unsigned char* second, unsigned int secondSize) {
	memcpy(first+firstSize, second, secondSize);
}
