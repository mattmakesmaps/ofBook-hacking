#pragma once
#include "ofMain.h"

using namespace glm;

class MKSquare
{
public:
	MKSquare() = default;
	~MKSquare();

	void setup(int length = 250, ofPrimitiveMode = OF_PRIMITIVE_TRIANGLE_FAN);

	void update();
	void draw();

	bool pip_wn1(vec3 point);

	ofMesh mesh;
	vector<vec3> offsets;
	float displacementScale;


private:
	int m_length;
	int _is_left(vec3 p, vec3 p1, vec3 p2);
};