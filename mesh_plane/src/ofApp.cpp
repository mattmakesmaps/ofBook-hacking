#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	auto p1 = ofMesh::plane(500, 500, 4,4, OF_PRIMITIVE_TRIANGLES);

	for (int i = 0; i < p1.getNumVertices(); ++i)
	{
		p1.addColor(ofColor::blue);
	}
	vec_mesh.push_back(p1);

	auto p2 = p1.getMeshForIndices(0, 8);
	vec_mesh.push_back(p2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	easy_cam.begin();
	vec_mesh[0].draw();
	//vec_mesh[1].draw();
	easy_cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
