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

int MKSquare::_is_left(vec3 p, vec3 p1, vec3 p2)
{
	/****
	From GIS Algorithms:
	Tests if point P is to the left of a line segment between p1 and p2
	Output:
		0 the point is on the line
		> 0 p is to the left of the line
		< 0 p is to the right of the line
	****/
	return (p2.x - p1.x) * (p.y - p1.y) - (p.x - p1.x) * (p2.y - p1.y);
}

bool MKSquare::pip_wn1(vec3 point)
{
	// Create a copy of the verticies and add a
	// closing point.
	auto verts = this->mesh.getVertices();
	verts.push_back(vec3(0.0, 0.0, 0.0));

	auto wn = 0;
	auto n = verts.size();

	for (int i = 0; i < n; ++i)
	{
		if (verts[i].y <= point.y)
		{
			if (verts[i + 1].y > point.y)
			{
				if (this->_is_left(point, verts[i], verts[i + 1]) > 0)
					wn += 1;
			}
		}
		else
		{
			if (verts[i + 1].y <= point.y)
			{
				if (this->_is_left(point, verts[i], verts[i + 1]) < 0)
					wn -= 1;
			}
		}
	}

	return wn != 0;
}
