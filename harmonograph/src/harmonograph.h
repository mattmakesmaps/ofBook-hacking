#pragma once
#include "ofMain.h"

class harmonograph
{
public:
	harmonograph();
	~harmonograph();

	void setup(ofColor color = ofColor::green);
	void update();
	void draw();

	vector<ofPoint> verts;

private:
	ofColor _color;
	int _scale;
	// P is the phase factor.
	float _p1;
	float _p2;
	float _p3;
	float _p4;
	// D is dampining factor.
	float _d1;
	float _d2;
	float _d3;
	float _d4;
	// F is the frequency?
	int _f1;
	int _f2;
	int _f3;
	int _f4;
};