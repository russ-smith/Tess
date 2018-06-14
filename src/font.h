#pragma once
#include <unordered_map>
#include <utility>

struct Character {
	int id;
	short x;
	short y;
	short width;
	short height;
	short xoffset;
	short yoffset;
	short xadvance;
};

struct pair_hash {
	size_t operator () (const std::pair<int, int> &p) const {
		auto h1 = std::hash<int>{}(p.first);
		auto h2 = std::hash<int>{}(p.second);
		return h1 ^ (h2 << 2);
	}
};

class Font {
public:
	Font(std::unordered_map<int, Character>& chars, std::unordered_map<std::pair<int, int>, int, pair_hash>& kerns,
							int w, int h, unsigned int tex): 
							characters(std::move(chars)), kernings(std::move(kerns)), texWInv(1.f/w), texHInv(1.f/h), texID(tex) {};

	unsigned int texID;
	void makeText(int x, int y, std::string text, std::vector<float>& outPos, std::vector<float>& outUV);

private:
	std::unordered_map<int, Character> characters;
	std::unordered_map<std::pair<int, int>, int, pair_hash> kernings;
	float texWInv;
	float texHInv;
};