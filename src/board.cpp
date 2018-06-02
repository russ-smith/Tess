#include "board.h"
#include "geometry.h"
#include <iostream>
#include <cmath>

#define HALF_PI 1.57079632679

#define ROT_XZ 1
#define ROT_YW 2
#define MOVE_TILES 4

Board::Board() {

}

void Board::beginRotateXZ(int dir) {
	updateFlags |= ROT_XZ;
	moveStartTime = currTime;
	stateXZ[1] += dir;
}

void Board::beginRotateYW(int dir) {
	updateFlags |= ROT_YW;
	moveStartTime = currTime;
	stateYW[1] += dir;
}

void Board::beginMoveTiles(int dir){
	int moveNum = 0;
	
	//map input dir to real dir depending on board rotation state
	int isYW = dir > 3 ? 1 : 0;
	dir = (dir + (isYW ? stateYW[0] : stateXZ[0])) & 3;
	int dirArray = 2 * (dir & 1) + isYW;
	int e = dir >> 1;
	int s = 1 - e;

	std::cout << "AXIS: " << dirArray << "   START: " << s << '\n';
	////check for possible movements along dir 
	//for (size_t i = 0; i < 16; i+=2) {
	//	int start = geometry::edges[dirArray][i + s];
	//	int end = geometry::edges[dirArray][i + e];
	//	if (values[start]) {
	//		if (values[end]==values[start] || values[end] == 0) {
	//			targets[start] = end;
	//			isMerging[start] = values[end];
	//			moveNum++;
	//		}
	//	} 
	//}
	//if (moveNum) {
	//	updateFlags |= MOVE_TILES;
	//	moveStartTime = currTime;
	//}
}

void Board::update() {
	//do board rotation
	if (updateFlags & ROT_XZ) {
		double t = (currTime - moveStartTime) * 2;
		if (t >= 1) {
			updateFlags ^= ROT_XZ;
			stateXZ[1] &= 3;
			stateXZ[0] = stateXZ[1];
			t = 1;
			std::cout << "XZ: " << stateXZ[0] << '\n';
		}
		else {
			t = t * t * (3 - 2 * t);
		}
		float angle = static_cast<float>(HALF_PI*((1 - t) * stateXZ[0] + t * stateXZ[1]));
		angles[0] = std::cosf(angle);
		angles[1] = std::sinf(angle);
	}
	else if (updateFlags & ROT_YW) {
		double t = (currTime - moveStartTime) * 2;
		if (t >= 1) {
			updateFlags ^= ROT_YW;
			stateYW[1] &= 3;
			stateYW[0] = stateYW[1];
			t = 1;
			std::cout << "YW: " << stateYW[0] << '\n';
		}
		else {
			t = t * t * (3 - 2 * t);
		}
		float angle = static_cast<float>(HALF_PI*((1 - t) * stateYW[0] + t * stateYW[1]));
		angles[2] = std::cosf(angle);
		angles[3] = std::sinf(angle);
	}

	//do tile movement
	else if (updateFlags & MOVE_TILES) {
		double t = (currTime - moveStartTime) * 2;
		//TODO TILE LOGIC
	}
}

void Board::reset() {
}

void Board::addTile() {

}

void Board::resetTile(int index) {
}
