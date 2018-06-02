#pragma once

#include "glm/vec4.hpp"


class Board {
public:
	Board();
	void beginRotateXZ(int dir);
	void beginRotateYW(int dir);
	void beginMoveTiles(int dir);
	void update();
	void reset();

	//tile data, one tile per corner
	int values[16];
	int targets[16];
	bool isMerging[16];

	float angles[4]{ 1,0,1,0 };
	double currTime;
	int updateFlags = 0;

private:
	void addTile();
	void resetTile(int index);
	int stateXZ[2]{ 0,0 };
	int stateYW[2]{ 0,0 };
	double moveStartTime;
};