#include "font.h"

using namespace std;

void Font::makeText(int x, int y, string text, vector<float>& outPos, vector<float>& outUV) {
	int len = text.length();
	outPos.clear();
	outUV.clear();
	outPos.reserve(8 * len);
	outUV.reserve(8 * len);
	Character c;
	int lastID  = 0;
	for (size_t i = 0; i < len; i++) {
		c = characters[text[i]];
		float luv = c.x * texWInv;
		float ruv = (c.x + c.width) * texWInv;
		float tuv = c.y * texHInv;
		float buv = (c.y + c.height) * texHInv;
		auto iter = kernings.find(pair<int, int>{lastID, c.id});
		if (iter != kernings.end()) {
			x += iter->second;
		}
		float lpos = x + c.xoffset;
		float rpos = lpos + c.width;
		float tpos = y + c.yoffset;
		float bpos = tpos + c.height;
		outPos.insert(end(outPos), { lpos, bpos, rpos, bpos, lpos, tpos, rpos, tpos });
		outUV.insert(end(outUV), { luv, buv, ruv, buv, luv, tuv, ruv, tuv });
		x += c.xadvance;
		lastID = c.id;
	}
}