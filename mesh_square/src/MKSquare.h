#pragma once
#include "ofMain.h"

class MKSquare
{
public:
	MKSquare() = default;
	~MKSquare();

	void setup(int length = 250, ofPrimitiveMode = OF_PRIMITIVE_TRIANGLE_FAN);

	void update();
	void draw();

	ofMesh mesh;
	vector<glm::vec3> offsets;
	float displacementScale;

	int m_length;

private:
};