#include "geometry.h"

namespace geometry {

	//big ups to andreas kahler for the icosphere generator
	const float sphereVerts[126]{
		-0.5257311f, 0.8506508f, 0.f,
		0.5257311f, 0.8506508f, 0.f,
		-0.5257311f, -0.8506508f, 0.f,
		0.5257311f, -0.8506508f, 0.f,
		0.f, -0.5257311f, 0.8506508f,
		0.f, 0.5257311f, 0.8506508f,
		0.f, -0.5257311f, -0.8506508f,
		0.f, 0.5257311f, -0.8506508f,
		0.8506508f, 0.f, -0.5257311f,
		0.8506508f, 0.f, 0.5257311f,
		-0.8506508f, 0.f, -0.5257311f,
		-0.8506508f, 0.f, 0.5257311f,
		-0.809017f, 0.5f, 0.309017f,
		-0.5f, 0.309017f, 0.809017f,
		-0.309017f, 0.809017f, 0.5f,
		0.309017f, 0.809017f, 0.5f,
		0.f, 1.f, 0.f,
		0.309017f, 0.809017f, -0.5f,
		-0.309017f, 0.809017f, -0.5f,
		-0.5f, 0.309017f, -0.809017f,
		-0.809017f, 0.5f, -0.309017f,
		-1.f, 0.f, 0.f,
		0.5f, 0.309017f, 0.809017f,
		0.809017f, 0.5f, 0.309017f,
		-0.5f, -0.309017f, 0.809017f,
		0.f, 0.f, 1.f,
		-0.809017f, -0.5f, -0.309017f,
		-0.809017f, -0.5f, 0.309017f,
		0.f, 0.f, -1.f,
		-0.5f, -0.309017f, -0.809017f,
		0.809017f, 0.5f, -0.309017f,
		0.5f, 0.309017f, -0.809017f,
		0.809017f, -0.5f, 0.309017f,
		0.5f, -0.309017f, 0.809017f,
		0.309017f, -0.809017f, 0.5f,
		-0.309017f, -0.809017f, 0.5f,
		0.f, -1.f, 0.f,
		-0.309017f, -0.809017f, -0.5f,
		0.309017f, -0.809017f, -0.5f,
		0.5f, -0.309017f, -0.809017f,
		0.809017f, -0.5f, -0.309017f,
		1.f, 0.f, 0.f
	};

	const unsigned char sphereTris[240]{
		0, 12, 14,
		11, 13, 12,
		5, 14, 13,
		12, 13, 14,
		0, 14, 16,
		5, 15, 14,
		1, 16, 15,
		14, 15, 16,
		0, 16, 18,
		1, 17, 16,
		7, 18, 17,
		16, 17, 18,
		0, 18, 20,
		7, 19, 18,
		10, 20, 19,
		18, 19, 20,
		0, 20, 12,
		10, 21, 20,
		11, 12, 21,
		20, 21, 12,
		1, 15, 23,
		5, 22, 15,
		9, 23, 22,
		15, 22, 23,
		5, 13, 25,
		11, 24, 13,
		4, 25, 24,
		13, 24, 25,
		11, 21, 27,
		10, 26, 21,
		2, 27, 26,
		21, 26, 27,
		10, 19, 29,
		7, 28, 19,
		6, 29, 28,
		19, 28, 29,
		7, 17, 31,
		1, 30, 17,
		8, 31, 30,
		17, 30, 31,
		3, 32, 34,
		9, 33, 32,
		4, 34, 33,
		32, 33, 34,
		3, 34, 36,
		4, 35, 34,
		2, 36, 35,
		34, 35, 36,
		3, 36, 38,
		2, 37, 36,
		6, 38, 37,
		36, 37, 38,
		3, 38, 40,
		6, 39, 38,
		8, 40, 39,
		38, 39, 40,
		3, 40, 32,
		8, 41, 40,
		9, 32, 41,
		40, 41, 32,
		4, 33, 25,
		9, 22, 33,
		5, 25, 22,
		33, 22, 25,
		2, 35, 27,
		4, 24, 35,
		11, 27, 24,
		35, 24, 27,
		6, 37, 29,
		2, 26, 37,
		10, 29, 26,
		37, 26, 29,
		8, 39, 31,
		6, 28, 39,
		7, 31, 28,
		39, 28, 31,
		9, 41, 23,
		8, 30, 41,
		1, 23, 30,
		41, 30, 23,
	};

	const float buttonVerts[96]{
		//move x and z buttons
		0.54f, 0.2f,	0.66f, 0.2f,	0.54f, 0.36f,	0.66f, 0.36f,
		0.84f, 0.2f,	0.96f, 0.2f,	0.84f, 0.36f,	0.96f, 0.36f,
		0.84f, -0.2f,	0.96f, -0.2f,	0.84f, -0.04f,	0.96f, -0.04f,
		0.54f, -0.2f,	0.66f, -0.2f,	0.54f, -0.04f,	0.66f, -0.04f,

		//move w and y buttons
		0.69f, -0.2f,	0.81f, -0.2f,	0.69f, -0.04f,	0.81f, -0.04f,
		0.6f, 0.f,		0.72f, 0.f,		0.6f, 0.16f,	0.72f, 0.16f,
		0.69f, 0.2f,	0.81f, 0.2f,	0.69f, 0.36f,	0.81f, 0.36f,
		0.78f, 0.f,		0.9f, 0.f,		0.78f, 0.16f,	0.9f, 0.16f,

		
		//rotate board buttons
		0.55f, -0.6f,	0.7f, -0.6f,	0.55f, -0.4f,	0.7f, -0.4f,
		0.8f, -0.6f,	0.95f, -0.6f,	0.8f, -0.4f,	0.95f, -0.4f,
		0.55f, -0.9f,	0.7f, -0.9f,	0.55f, -0.7f,	0.7f, -0.7f,
		0.8f,  -0.9f,	0.95f, -0.9f,	0.8f, -0.7f,	0.95f, -0.7f,		
	};

	const unsigned char buttonTris[72]{
		0,1,2,3,2,1,
		4,5,6,7,6,5,
		8,9,10,11,10,9,
		12,13,14,15,14,13,
		16,17,18,19,18,17,
		20,21,22,23,22,21,
		24,25,26,27,26,25,
		28,29,30,31,30,29,
		32,33,34,35,34,33,
		36,37,38,39,38,37,
		40,41,42,43,42,41,
		44,45,46,47,46,45
	};

	const float corners[64]{
		-2.f,-2.f,-2.f,-2.f,
		 2.f,-2.f,-2.f,-2.f,
		-2.f, 2.f,-2.f,-2.f,
		 2.f, 2.f,-2.f,-2.f,
		-2.f,-2.f, 2.f,-2.f,
		 2.f,-2.f, 2.f,-2.f,
		-2.f, 2.f, 2.f,-2.f,
		 2.f, 2.f, 2.f,-2.f,
		-2.f,-2.f,-2.f, 2.f,
		 2.f,-2.f,-2.f, 2.f,
		-2.f, 2.f,-2.f, 2.f,
		 2.f, 2.f,-2.f, 2.f,
		-2.f,-2.f, 2.f, 2.f,
		 2.f,-2.f, 2.f, 2.f,
		-2.f, 2.f, 2.f, 2.f,
		 2.f, 2.f, 2.f, 2.f,
	};

	const unsigned char edges[4][16]{
		{	0,1,	2,3,	4,5,	6,7,	8,9,	10,11,	12,13,	14,15	},
		{	0,2,	1,3,	4,6,	5,7,	8,10,	9,11,	12,14,	13,15	},
		{	0,4,	1,5,	2,6,	3,7,	8,12,	9,13,	10,14,	11,15	},
		{	0,8,	1,9,	2,10,	3,11,	4,12,	5,13,	6,14,	7,15	}
	};
}