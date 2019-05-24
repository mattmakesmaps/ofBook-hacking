#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	//ofSetupOpenGL(1080, 724, OF_WINDOW); //library 01
	//ofSetupOpenGL(2160, 1448, OF_WINDOW); //library 01
	ofSetupOpenGL(2160, 1080, OF_WINDOW); //library 01

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
