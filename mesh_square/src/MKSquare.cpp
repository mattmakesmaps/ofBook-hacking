#include "MKSquare.h"

MKSquare::~MKSquare()
{
}

void MKSquare::setup(int length, ofPrimitiveMode mode)
{
	// Mesh Setup 
	m_length= length;
	mesh.setMode(mode);
	mesh.enableIndices();
	mesh.enableColors();

	// Add Vertexes
	mesh.addVertex(glm::vec3(0.0, 0.0, 0.0));
	mesh.addVertex(glm::vec3(length, 0.0, 0.0));
	mesh.addVertex(glm::vec3(length, length, 0.0));
	mesh.addVertex(glm::vec3(0.0, length, 0.0));

	// Add Offsets for Jitter
	for (int i = 0; i < mesh.getNumVertices(); ++i) {
		offsets.push_back(glm::vec3(
			ofRandom(0, 10000),
			ofRandom(0, 10000),
			ofRandom(0, 10000)));
	}

	displacementScale = 0;

	// Add Color and Indexes for Rendering
	std::vector<ofColor> color_lookup = {
		ofColor::black,
		ofColor::white,
		ofColor::blueViolet,
		ofColor::green,
	};

	for (int cnt = 0; cnt < mesh.getNumVertices(); ++cnt)
	{
		mesh.addIndex(cnt);
		mesh.addColor(color_lookup[cnt]);
	}
}

void MKSquare::update()
{
	// Jitter Example from ofBook
	int numVerts = mesh.getNumVertices();
	for (int i = 0; i < numVerts; i++) {
		glm::vec3 vert = mesh.getVertex(i);
		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		glm::vec3 timeOffsets = offsets[i];
		vert.x += (ofSignedNoise(time*timeScale + timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale + timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale + timeOffsets.z)) * displacementScale;
		mesh.setVertex(i, vert);
	}
}

void MKSquare::draw()
{
	mesh.draw();
}
