#include "harmonograph.h"



harmonograph::harmonograph()
{
}


harmonograph::~harmonograph()
{
}

void harmonograph::setup(ofColor color)
{
	_color = color;
	_scale = 400;
	// P is the phase factor.
	_p1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
	_p2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
	_p3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
	_p4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
	// D is dampining factor.
	_d1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
	_d2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
	_d3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
	_d4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
	// F is the frequency?
	_f1 = (rand() % 10) + 1;
	_f2 = (rand() % 10) + 1;
	_f3 = (rand() % 10) + 1;
	_f4 = (rand() % 10) + 1;
}

void harmonograph::update()
{
	// See: https://stackoverflow.com/questions/686353/random-float-number-generation
	// See: http://www.walkingrandomly.com/?p=151
	// See: https://fronkonstin.com/tag/harmonograph/

	auto t = ofGetElapsedTimef();

	auto posX = exp(-_d1 * t)*sin(t*_f1 + _p1) + exp(-_d2 * t)*sin(t*_f2 + _p2);
	auto posY = exp(-_d3 * t)*sin(t*_f3 + _p3) + exp(-_d4 * t)*sin(t*_f4 + _p4);

	ofPoint tempP = ofPoint(posX * _scale, posY * _scale);
	verts.push_back(tempP);
}

void harmonograph::draw()
{
	ofNoFill(); 
	ofSetColor(_color);

	auto clipping_Vert = 300;

	if (verts.size() >= clipping_Vert)
	{
		ofBeginShape();
		for (int i = clipping_Vert; i < verts.size(); i++) {
			ofVertex(verts[i].x, verts[i].y);
		}
		ofEndShape();
	}
}
