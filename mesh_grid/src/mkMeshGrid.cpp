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
	m_mesh.setMode(OF_PRIMITIVE_LINES);
	m_mesh.enableIndices();
	m_mesh.enableColors();

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

	m_mesh.addColors(m_colors);
	m_mesh.addVertices(m_verts);

	// Adding connections 
	float connectionDistance = width/m_numColumns;
	int numVerts = m_mesh.getNumVertices();
	for (int a = 0; a < numVerts; ++a) {
		ofVec3f verta = m_mesh.getVertex(a);
		for (int b = a + 1; b < numVerts; ++b) {
			ofVec3f vertb = m_mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				m_mesh.addIndex(a);
				m_mesh.addIndex(b);
			}
		}
	}
}

void mkMeshGrid::update()
{
}

void mkMeshGrid::draw()
{
	m_mesh.draw();
}
