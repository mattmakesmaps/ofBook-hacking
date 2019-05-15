#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// P is the phase factor.
		float p1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
		float p2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
		float p3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
		float p4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TWO_PI));
		// D is dampining factor.
		float d1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
		float d2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
		float d3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
		float d4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.1));
		// F is the frequency?
		int f1 = (rand() % 10) + 1;
		int f2 = (rand() % 10) + 1;
		int f3 = (rand() % 10) + 1;
		int f4 = (rand() % 10) + 1;

		float calcX(float t);
		float calcy(float t);

		vector<ofPoint> points;
};
