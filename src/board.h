#pragma once

#include "glm/vec4.hpp"

enum flags {
	ROT_XZ = 1,
	ROT_YW = 2,
	MOVE_TILES = 4,
	GROW = 8
};

class Board {
public:
	Board(double time);
	void beginRotateXZ(int dir);
	void beginRotateYW(int dir);
	void beginMoveTiles(int dir);
	void update();
	void reset();

	//compacted arrays for renderer
	float drawPositions[64];
	float drawValues[16];
	float drawScales[16];
	int numActive;

	float angles[4]{ 1,0,1,0 };
	double currTime;
	float moveTime;
	int updateFlags = 0;

private:

	void addTile();
	void resetTile(int index);
	int stateXZ[2]{ 0,0 };
	int stateYW[2]{ 0,0 };
	double moveStartTime;
	double growStartTime;
	int newTile;

	//tile data, one tile per corner
	int values[16]{ 0 };
	int targets[16]{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	float scales[16]{ 0 };
	bool isMerging[16]{ false };
};