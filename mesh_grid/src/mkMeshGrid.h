#pragma once
#include "ofMain.h"

class mkMeshGrid
{
public:
	mkMeshGrid() = default;
	~mkMeshGrid();

	void setup(int numColumn = 20, int numRows = 20, ofColor color = ofColor::green);

	void update();
	void draw();

	ofMesh mesh;
	vector<glm::vec3> m_verts;
	vector<ofDefaultColorType> m_colors;
	vector<ofMesh> mesh_vect;

	int m_numColumns;
	int m_numRows;

private:
};