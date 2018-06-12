#include "board.h"
#include "geometry.h"
#include <iostream>
#include <cmath>
#include <cstdlib>


#define HALF_PI 1.57079632679

Board::Board(double time) {
	currTime = time;
	unsigned int* seedptr = reinterpret_cast<unsigned int*>(&time);
	srand(seedptr[0] ^ seedptr[1]);
	score = 0;
	addTile();
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

	//check for possible movements along dir 
	for (size_t i = 0; i < 16; i+=2) {
		int start = geometry::edges[dirArray][i + s];
		int end = geometry::edges[dirArray][i + e];
		if (values[start]) {
			if (values[end]==values[start] || values[end] == 0) {
				targets[start] = end;
				//isMerging[start] = (values[end] > 0);
				moveNum++;
			}
		} 
	}
	if (moveNum) {
		updateFlags |= MOVE_TILES;
		moveStartTime = currTime;
	}
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
		}
		else {
			t = t * t * (3 - 2 * t);
		}
		float angle = (HALF_PI*((1 - t) * stateXZ[0] + t * stateXZ[1]));
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
		}
		else {
			t = t * t * (3 - 2 * t);
		}
		float angle = (HALF_PI*((1 - t) * stateYW[0] + t * stateYW[1]));
		angles[2] = std::cosf(angle);
		angles[3] = std::sinf(angle);
	}

	//do tile movement
	else if (updateFlags & MOVE_TILES) {
		double t = (currTime - moveStartTime) * 2;
		if (t >= 1) {
			for (size_t i = 0; i < 16; i++) {
				if (targets[i] != -1) {
					if (values[targets[i]]) {
						values[targets[i]]++;
						isMerging[targets[i]] = true;
						score += 1 << values[targets[i]] ;
					}
					else {
						values[targets[i]] = values[i];
						scales[targets[i]] = 1;
					}
					values[i] = 0;
					targets[i] = -1;
				}
			}
			addTile();
			updateFlags ^= MOVE_TILES;
			std::cout << "SCORE : " << score;
		}
		else 
			t = t * t * (3 - 2 * t);

		int tileNum = 0;
		for (size_t i = 0; i < 16; i++) {
			if (values[i]) {
				drawValues[tileNum] = values[i];
				drawScales[tileNum] = scales[i];
				if (targets[i] != -1) {
					for (size_t j = 0; j < 4; j++) {
						drawPositions[4 * tileNum + j] = geometry::corners[4 * i + j] * (1 - t)
														+geometry::corners[4 * targets[i] + j] * t;
					}
				}
				else {
					for (size_t j = 0; j < 4; j++) {
						drawPositions[4 * tileNum + j] = geometry::corners[4 * i + j];
					}
				}
				tileNum++;
			}
		}
		numActive = tileNum;
	}

	if (updateFlags & GROW) {
		double t = (currTime - growStartTime) * 3;
		if (t >= 1) {
			t = 1;
			for (size_t i = 0; i < 16; i++) {
				isMerging[i] = false;
				scales[i] = 1;
			}
			updateFlags ^= GROW;
		}
		scales[newTile] = t*(2-t);
		int tileNum = 0;
		for (size_t i = 0; i < 16; i++) {
			if (values[i]) {				
				if (isMerging[i]) {
					scales[i] = (1.25 - (t - 0.5)*(t - 0.5));
					drawValues[tileNum] = values[i] - (1-t);
				}
				else {
					drawValues[tileNum] = values[i];
				}
				drawScales[tileNum] = scales[i];
				for (size_t j = 0; j < 4; j++) {
					drawPositions[4 * tileNum + j] = geometry::corners[4 * i + j];
				}
				tileNum++;
			}
		}
		numActive = tileNum;
	}	
}

void Board::reset() {
}

void Board::addTile() {
	int freeTiles[16];
	int numFree = 0;
	for (size_t i = 0; i < 16; i++) {
		if (values[i] == 0) {
			freeTiles[numFree] = i;
			numFree++;
		}
	}
	int tileIndex = freeTiles[rand() % numFree];
	values[tileIndex] = (rand() % 10) == 9 ? 2 : 1;
	scales[tileIndex] = 0.f;
	targets[tileIndex] = -1;
	newTile = tileIndex;
	growStartTime = currTime;
	updateFlags |= GROW;
}

void Board::resetTile(int index) {
}
