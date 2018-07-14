#include "geometry.h"

namespace geometry {

	//big ups to andreas kahler for the icosphere generator
	//http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html
	const float sphereVerts[486]{
		-0.5257311, 0.8506508, 0,
		0.5257311, 0.8506508, 0,
		-0.5257311, -0.8506508, 0,
		0.5257311, -0.8506508, 0,
		0, -0.5257311, 0.8506508,
		0, 0.5257311, 0.8506508,
		0, -0.5257311, -0.8506508,
		0, 0.5257311, -0.8506508,
		0.8506508, 0, -0.5257311,
		0.8506508, 0, 0.5257311,
		-0.8506508, 0, -0.5257311,
		-0.8506508, 0, 0.5257311,
		-0.809017, 0.5, 0.309017,
		-0.5, 0.309017, 0.809017,
		-0.309017, 0.809017, 0.5,
		0.309017, 0.809017, 0.5,
		0, 1, 0,
		0.309017, 0.809017, -0.5,
		-0.309017, 0.809017, -0.5,
		-0.5, 0.309017, -0.809017,
		-0.809017, 0.5, -0.309017,
		-1, 0, 0,
		0.5, 0.309017, 0.809017,
		0.809017, 0.5, 0.309017,
		-0.5, -0.309017, 0.809017,
		0, 0, 1,
		-0.809017, -0.5, -0.309017,
		-0.809017, -0.5, 0.309017,
		0, 0, -1,
		-0.5, -0.309017, -0.809017,
		0.809017, 0.5, -0.309017,
		0.5, 0.309017, -0.809017,
		0.809017, -0.5, 0.309017,
		0.5, -0.309017, 0.809017,
		0.309017, -0.809017, 0.5,
		-0.309017, -0.809017, 0.5,
		0, -1, 0,
		-0.309017, -0.809017, -0.5,
		0.309017, -0.809017, -0.5,
		0.5, -0.309017, -0.809017,
		0.809017, -0.5, -0.309017,
		1, 0, 0,
		-0.6937805, 0.7020465, 0.160622,
		-0.5877852, 0.6881909, 0.4253254,
		-0.4338886, 0.8626685, 0.2598919,
		-0.7020465, 0.160622, 0.6937805,
		-0.6881909, 0.4253254, 0.5877852,
		-0.8626685, 0.2598919, 0.4338886,
		-0.160622, 0.6937805, 0.7020465,
		-0.4253254, 0.5877852, 0.6881909,
		-0.2598919, 0.4338886, 0.8626685,
		-0.1624599, 0.9510565, 0.2628655,
		-0.2732665, 0.9619384, 0,
		0.160622, 0.6937805, 0.7020465,
		0, 0.8506508, 0.5257311,
		0.2732665, 0.9619384, 0,
		0.1624599, 0.9510565, 0.2628655,
		0.4338886, 0.8626685, 0.2598919,
		-0.1624599, 0.9510565, -0.2628655,
		-0.4338886, 0.8626685, -0.2598919,
		0.4338886, 0.8626685, -0.2598919,
		0.1624599, 0.9510565, -0.2628655,
		-0.160622, 0.6937805, -0.7020465,
		0, 0.8506508, -0.5257311,
		0.160622, 0.6937805, -0.7020465,
		-0.5877852, 0.6881909, -0.4253254,
		-0.6937805, 0.7020465, -0.160622,
		-0.2598919, 0.4338886, -0.8626685,
		-0.4253254, 0.5877852, -0.6881909,
		-0.8626685, 0.2598919, -0.4338886,
		-0.6881909, 0.4253254, -0.5877852,
		-0.7020465, 0.160622, -0.6937805,
		-0.8506508, 0.5257311, 0,
		-0.9619384, 0, -0.2732665,
		-0.9510565, 0.2628655, -0.1624599,
		-0.9510565, 0.2628655, 0.1624599,
		-0.9619384, 0, 0.2732665,
		0.5877852, 0.6881909, 0.4253254,
		0.6937805, 0.7020465, 0.160622,
		0.2598919, 0.4338886, 0.8626685,
		0.4253254, 0.5877852, 0.6881909,
		0.8626685, 0.2598919, 0.4338886,
		0.6881909, 0.4253254, 0.5877852,
		0.7020465, 0.160622, 0.6937805,
		-0.2628655, 0.1624599, 0.9510565,
		0, 0.2732665, 0.9619384,
		-0.7020465, -0.160622, 0.6937805,
		-0.5257311, 0, 0.8506508,
		0, -0.2732665, 0.9619384,
		-0.2628655, -0.1624599, 0.9510565,
		-0.2598919, -0.4338886, 0.8626685,
		-0.9510565, -0.2628655, 0.1624599,
		-0.8626685, -0.2598919, 0.4338886,
		-0.8626685, -0.2598919, -0.4338886,
		-0.9510565, -0.2628655, -0.1624599,
		-0.6937805, -0.7020465, 0.160622,
		-0.8506508, -0.5257311, 0,
		-0.6937805, -0.7020465, -0.160622,
		-0.5257311, 0, -0.8506508,
		-0.7020465, -0.160622, -0.6937805,
		0, 0.2732665, -0.9619384,
		-0.2628655, 0.1624599, -0.9510565,
		-0.2598919, -0.4338886, -0.8626685,
		-0.2628655, -0.1624599, -0.9510565,
		0, -0.2732665, -0.9619384,
		0.4253254, 0.5877852, -0.6881909,
		0.2598919, 0.4338886, -0.8626685,
		0.6937805, 0.7020465, -0.160622,
		0.5877852, 0.6881909, -0.4253254,
		0.7020465, 0.160622, -0.6937805,
		0.6881909, 0.4253254, -0.5877852,
		0.8626685, 0.2598919, -0.4338886,
		0.6937805, -0.7020465, 0.160622,
		0.5877852, -0.6881909, 0.4253254,
		0.4338886, -0.8626685, 0.2598919,
		0.7020465, -0.160622, 0.6937805,
		0.6881909, -0.4253254, 0.5877852,
		0.8626685, -0.2598919, 0.4338886,
		0.160622, -0.6937805, 0.7020465,
		0.4253254, -0.5877852, 0.6881909,
		0.2598919, -0.4338886, 0.8626685,
		0.1624599, -0.9510565, 0.2628655,
		0.2732665, -0.9619384, 0,
		-0.160622, -0.6937805, 0.7020465,
		0, -0.8506508, 0.5257311,
		-0.2732665, -0.9619384, 0,
		-0.1624599, -0.9510565, 0.2628655,
		-0.4338886, -0.8626685, 0.2598919,
		0.1624599, -0.9510565, -0.2628655,
		0.4338886, -0.8626685, -0.2598919,
		-0.4338886, -0.8626685, -0.2598919,
		-0.1624599, -0.9510565, -0.2628655,
		0.160622, -0.6937805, -0.7020465,
		0, -0.8506508, -0.5257311,
		-0.160622, -0.6937805, -0.7020465,
		0.5877852, -0.6881909, -0.4253254,
		0.6937805, -0.7020465, -0.160622,
		0.2598919, -0.4338886, -0.8626685,
		0.4253254, -0.5877852, -0.6881909,
		0.8626685, -0.2598919, -0.4338886,
		0.6881909, -0.4253254, -0.5877852,
		0.7020465, -0.160622, -0.6937805,
		0.8506508, -0.5257311, 0,
		0.9619384, 0, -0.2732665,
		0.9510565, -0.2628655, -0.1624599,
		0.9510565, -0.2628655, 0.1624599,
		0.9619384, 0, 0.2732665,
		0.2628655, -0.1624599, 0.9510565,
		0.5257311, 0, 0.8506508,
		0.2628655, 0.1624599, 0.9510565,
		-0.5877852, -0.6881909, 0.4253254,
		-0.4253254, -0.5877852, 0.6881909,
		-0.6881909, -0.4253254, 0.5877852,
		-0.4253254, -0.5877852, -0.6881909,
		-0.5877852, -0.6881909, -0.4253254,
		-0.6881909, -0.4253254, -0.5877852,
		0.5257311, 0, -0.8506508,
		0.2628655, -0.1624599, -0.9510565,
		0.2628655, 0.1624599, -0.9510565,
		0.9510565, 0.2628655, 0.1624599,
		0.9510565, 0.2628655, -0.1624599,
		0.8506508, 0.5257311, 0,
	};

	const unsigned char sphereTris[960]{
		0, 42, 44, 		12, 43, 42, 	14, 44, 43, 	42, 43, 44,
		11, 45, 47, 	13, 46, 45, 	12, 47, 46, 	45, 46, 47,
		5, 48, 50, 		14, 49, 48, 	13, 50, 49, 	48, 49, 50,
		12, 46, 43, 	13, 49, 46, 	14, 43, 49, 	46, 49, 43,
		0, 44, 52, 		14, 51, 44, 	16, 52, 51, 	44, 51, 52,
		5, 53, 48, 		15, 54, 53, 	14, 48, 54, 	53, 54, 48,
		1, 55, 57, 		16, 56, 55, 	15, 57, 56, 	55, 56, 57,
		14, 54, 51, 	15, 56, 54, 	16, 51, 56, 	54, 56, 51,
		0, 52, 59, 		16, 58, 52, 	18, 59, 58, 	52, 58, 59,
		1, 60, 55, 		17, 61, 60, 	16, 55, 61, 	60, 61, 55,
		7, 62, 64, 		18, 63, 62, 	17, 64, 63, 	62, 63, 64,
		16, 61, 58, 	17, 63, 61, 	18, 58, 63, 	61, 63, 58,
		0, 59, 66, 		18, 65, 59, 	20, 66, 65, 	59, 65, 66,
		7, 67, 62, 		19, 68, 67, 	18, 62, 68, 	67, 68, 62,
		10, 69, 71, 	20, 70, 69, 	19, 71, 70, 	69, 70, 71,
		18, 68, 65, 	19, 70, 68, 	20, 65, 70, 	68, 70, 65,
		0, 66, 42, 		20, 72, 66, 	12, 42, 72, 	66, 72, 42,
		10, 73, 69, 	21, 74, 73, 	20, 69, 74, 	73, 74, 69,
		11, 47, 76, 	12, 75, 47, 	21, 76, 75, 	47, 75, 76,
		20, 74, 72, 	21, 75, 74, 	12, 72, 75, 	74, 75, 72,
		1, 57, 78, 		15, 77, 57, 	23, 78, 77, 	57, 77, 78,
		5, 79, 53, 		22, 80, 79, 	15, 53, 80, 	79, 80, 53,
		9, 81, 83, 		23, 82, 81, 	22, 83, 82, 	81, 82, 83,
		15, 80, 77, 	22, 82, 80, 	23, 77, 82, 	80, 82, 77,
		5, 50, 85, 		13, 84, 50, 	25, 85, 84, 	50, 84, 85,
		11, 86, 45, 	24, 87, 86, 	13, 45, 87, 	86, 87, 45,
		4, 88, 90, 		25, 89, 88, 	24, 90, 89, 	88, 89, 90,
		13, 87, 84, 	24, 89, 87, 	25, 84, 89, 	87, 89, 84,
		11, 76, 92, 	21, 91, 76, 	27, 92, 91, 	76, 91, 92,
		10, 93, 73, 	26, 94, 93, 	21, 73, 94, 	93, 94, 73,
		2, 95, 97, 		27, 96, 95, 	26, 97, 96, 	95, 96, 97,
		21, 94, 91, 	26, 96, 94, 	27, 91, 96, 	94, 96, 91,
		10, 71, 99, 	19, 98, 71, 	29, 99, 98, 	71, 98, 99,
		7, 100, 67, 	28, 101, 100, 	19, 67, 101, 	100, 101, 67,
		6, 102, 104, 	29, 103, 102, 	28, 104, 103, 	102, 103, 104,
		19, 101, 98, 	28, 103, 101, 	29, 98, 103, 	101, 103, 98,
		7, 64, 106, 	17, 105, 64, 	31, 106, 105, 	64, 105, 106,
		1, 107, 60, 	30, 108, 107, 	17, 60, 108, 	107, 108, 60,
		8, 109, 111, 	31, 110, 109, 	30, 111, 110, 	109, 110, 111,
		17, 108, 105, 	30, 110, 108, 	31, 105, 110, 	108, 110, 105,
		3, 112, 114, 	32, 113, 112, 	34, 114, 113, 	112, 113, 114,
		9, 115, 117, 	33, 116, 115, 	32, 117, 116, 	115, 116, 117,
		4, 118, 120, 	34, 119, 118, 	33, 120, 119, 	118, 119, 120,
		32, 116, 113, 	33, 119, 116, 	34, 113, 119, 	116, 119, 113,
		3, 114, 122, 	34, 121, 114, 	36, 122, 121, 	114, 121, 122,
		4, 123, 118, 	35, 124, 123, 	34, 118, 124, 	123, 124, 118,
		2, 125, 127, 	36, 126, 125, 	35, 127, 126, 	125, 126, 127,
		34, 124, 121, 	35, 126, 124, 	36, 121, 126, 	124, 126, 121,
		3, 122, 129, 	36, 128, 122, 	38, 129, 128, 	122, 128, 129,
		2, 130, 125, 	37, 131, 130, 	36, 125, 131, 	130, 131, 125,
		6, 132, 134, 	38, 133, 132, 	37, 134, 133, 	132, 133, 134,
		36, 131, 128, 	37, 133, 131, 	38, 128, 133, 	131, 133, 128,
		3, 129, 136, 	38, 135, 129, 	40, 136, 135, 	129, 135, 136,
		6, 137, 132, 	39, 138, 137, 	38, 132, 138, 	137, 138, 132,
		8, 139, 141, 	40, 140, 139, 	39, 141, 140, 	139, 140, 141,
		38, 138, 135, 	39, 140, 138, 	40, 135, 140, 	138, 140, 135,
		3, 136, 112, 	40, 142, 136, 	32, 112, 142, 	136, 142, 112,
		8, 143, 139, 	41, 144, 143, 	40, 139, 144, 	143, 144, 139,
		9, 117, 146, 	32, 145, 117, 	41, 146, 145, 	117, 145, 146,
		40, 144, 142, 	41, 145, 144, 	32, 142, 145, 	144, 145, 142,
		4, 120, 88, 	33, 147, 120, 	25, 88, 147, 	120, 147, 88,
		9, 83, 115, 	22, 148, 83, 	33, 115, 148, 	83, 148, 115,
		5, 85, 79, 		25, 149, 85, 	22, 79, 149, 	85, 149, 79,
		33, 148, 147, 	22, 149, 148, 	25, 147, 149, 	148, 149, 147,
		2, 127, 95, 	35, 150, 127, 	27, 95, 150, 	127, 150, 95,
		4, 90, 123, 	24, 151, 90, 	35, 123, 151, 	90, 151, 123,
		11, 92, 86, 	27, 152, 92, 	24, 86, 152, 	92, 152, 86,
		35, 151, 150, 	24, 152, 151, 	27, 150, 152, 	151, 152, 150,
		6, 134, 102, 	37, 153, 134, 	29, 102, 153, 	134, 153, 102,
		2, 97, 130, 	26, 154, 97, 	37, 130, 154, 	97, 154, 130,
		10, 99, 93, 	29, 155, 99, 	26, 93, 155, 	99, 155, 93,
		37, 154, 153, 	26, 155, 154, 	29, 153, 155, 	154, 155, 153,
		8, 141, 109, 	39, 156, 141, 	31, 109, 156, 	141, 156, 109,
		6, 104, 137, 	28, 157, 104, 	39, 137, 157, 	104, 157, 137,
		7, 106, 100, 	31, 158, 106, 	28, 100, 158, 	106, 158, 100,
		39, 157, 156, 	28, 158, 157, 	31, 156, 158, 	157, 158, 156,
		9, 146, 81, 	41, 159, 146, 	23, 81, 159, 	146, 159, 81,
		8, 111, 143, 	30, 160, 111, 	41, 143, 160, 	111, 160, 143,
		1, 78, 107, 	23, 161, 78, 	30, 107, 161, 	78, 161, 107,
		41, 160, 159, 	30, 161, 160, 	23, 159, 161, 	160, 161, 159,
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

	const float buttonUVs[96]{
		0.5f, 0.5f,		0.25f, 0.5f,	0.5f, 0.f,		0.25f, 0.f,
		0.25f, 0.5f,	0.5f, 0.5f,		0.25f, 0.f,		0.5f, 0.f,
		0.25f, 0.f,		0.5f, 0.f,		0.25f, 0.5f,	0.5f, 0.5f,
		0.5f, 0.f,		0.25f, 0.f,		0.5f, 0.5f,		0.25f, 0.5f,

		0.25f, 0.5f,	0.5f, 0.5f,		0.25f, 1.f,		0.5f, 1.f,
		0.5f, 0.5f,		0.75f, 0.5f,	0.5f, 0.f,		0.75f, 0.f,
		0.25f, 1.f,		0.5f, 1.f,		0.25f, 0.5f,	0.5f, 0.5f,
		0.5f, 1.f,		0.75f, 1.f,		0.5f, 0.5f,		0.75f, 0.5f,

		0.25f, 1.f,		0.f, 1.f,		0.25f, 0.5f,	0.f, 0.5f,
		0.f, 1.f,		0.25f, 1.f,		0.f, 0.5f,		0.25f, 0.5f,
		0.f, 0.5f,		0.25f, 0.5f,	0.f, 0.f,		0.25f, 0.f,
		0.f, 0.f,		0.25f, 0.f,		0.f, 0.5f,		0.25f, 0.5f
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