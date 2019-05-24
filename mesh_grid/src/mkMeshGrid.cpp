#include "mkMeshGrid.h"

mkMeshGrid::~mkMeshGrid()
{
}

void mkMeshGrid::setup(int numColumns, int numRows, ofColor color)
{
	// instance setup
	m_numRows = numRows;
	m_numColumns = numColumns;

	// Mesh Setup
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableIndices();
	mesh.enableColors();

	auto width = ofGetWidth();
	auto height = ofGetHeight();

	for (int c = 0; c < m_numColumns; ++c) {
		for (int r = 0; r < m_numRows; ++r) {
			auto x_cord = r * (width / m_numRows);
			auto y_cord = c * (height / m_numColumns);
			m_verts.push_back(glm::vec3(x_cord, y_cord, 0.0));
			m_colors.push_back(color);
		}
	}

	mesh.addColors(m_colors);
	mesh.addVertices(m_verts);

	// Adding connections 
	float connectionDistance = width/m_numColumns;
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
}

void mkMeshGrid::update()
{
}

void mkMeshGrid::draw()
{
	mesh.draw();
}
