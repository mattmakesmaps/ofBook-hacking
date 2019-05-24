#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	image.load("calder.png");
	float intensityThreshold = 50.0; // Calder
	//image.load("central_library_01.png");
	//float intensityThreshold = 150.0;
	image.resize(270, 180); // shrink image to reduce processing
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableIndices();
	mesh.enableColors();

	int w = image.getWidth();
	int h = image.getHeight();
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -100, 100);
				glm::vec3 pos(x*8, y*8, z);
				//glm::vec3 pos(x, y, z);
				mesh.addVertex(pos);
				mesh.addColor(c);

				offsets.push_back(glm::vec3(
					ofRandom(0, 100000),
					ofRandom(0, 100000),
					ofRandom(0, 100000)));
			}
		}
	}

	float connectionDistance = 15;
	int numVerts = mesh.getNumVertices();
	for (int a = 0; a < numVerts; ++a) {
		ofVec3f verta = mesh.getVertex(a);
		for (int b = a + 1; b < numVerts; ++b) {
			ofVec3f vertb = mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				mesh.addIndex(a);
				mesh.addIndex(b);
			}
		}
	}

	// Orbital Example
	meshCentroid = mesh.getCentroid();

	for (int i = 0; i < numVerts; i++) {
		ofVec3f vert = mesh.getVertex(i);
		float distance = vert.distance(meshCentroid);
		float angle = atan2(vert.y - meshCentroid.y, vert.x - meshCentroid.x);
		distances.push_back(distance);
		angles.push_back(angle);
	}

	orbiting = false;
	startOrbitTime = 0.0;
	meshCopy = mesh;


}

//--------------------------------------------------------------
void ofApp::update(){
	// all of this has to do with noise
	/*
	int numVerts = mesh.getNumVertices();
	for (int i = 0; i < numVerts; i++) {
		glm::vec3 vert = mesh.getVertex(i);

		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		float displacementScale = 0.75;
		glm::vec3 timeOffsets = offsets[i];

		vert.x += (ofSignedNoise(time*timeScale + timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale + timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale + timeOffsets.z)) * displacementScale;
		mesh.setVertex(i, vert);
	}
	*/

	// Orbital Example
	if (orbiting) {
		int numVerts = mesh.getNumVertices();
		for (int i = 0; i < numVerts; ++i) {
			ofVec3f vert = mesh.getVertex(i);
			float distance = distances[i];
			float angle = angles[i];
			float elapsedTime = ofGetElapsedTimef() - startOrbitTime;

			float speed = ofMap(distance, 0, 200, 1, 0.25, true);
			float rotatedAngle = elapsedTime * speed + angle;

			vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
			vert.y = distance * sin(rotatedAngle) + meshCentroid.y;

			mesh.setVertex(i, vert);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofColor centerColor = ofColor(85, 78, 68);
	ofColor edgeColor = ofColor(0,0,0);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	easyCam.begin();
		ofPushMatrix();
		ofScale(1, -1, 1);
		//glm::vec3 center(ofGetWidth() / 2, ofGetWidth() / 2, 0.0);
		// (half of scene width or height) - (half of image width or height * scale factor)
		//ofTranslate((ofGetWidth() / 2) - (135 * 4), (ofGetHeight() / 2) - (90 * 4));
		ofTranslate((-ofGetWindowWidth() / 2), (-ofGetWindowHeight() / 2) - 200);
		//easyCam.setTarget(center);
		mesh.draw();
		ofPopMatrix();
	easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'o') {
		orbiting = !orbiting; // This inverts the boolean
		startOrbitTime = ofGetElapsedTimef();
		mesh = meshCopy; // This restores the mesh to its original values
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
