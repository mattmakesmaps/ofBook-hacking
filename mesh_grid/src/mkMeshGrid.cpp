#include "mkMeshGrid.h"

mkMeshGrid::~mkMeshGrid()
{
}

void mkMeshGrid::setup(int numColumns, int numRows, ofColor color)
{
	// instance setup
	m_numRows = numRows;
	m_numColumns = numColumns;

	// Setup of the "Grid Mesh" From with
	// "Cell Meshes" will be subset
	mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
	mesh.enableIndices();
	mesh.enableColors();

	auto width = ofGetWidth();
	auto height = ofGetHeight();

	for (int c = 0; c < m_numColumns; ++c) {
		for (int r = 0; r < m_numRows; ++r) {
			auto x_cord = r * (width / m_numRows);
			auto y_cord = c * (height / m_numColumns);
			glm::vec3 temp_vert = glm::vec3(x_cord, y_cord, 0.0);
			m_verts.push_back(temp_vert);
		}
	}

	mesh.addVertices(m_verts);

	// Adding connections using indexes.
	// The indexes define each "Cell Mesh"
	float connectionDistance = width/m_numColumns;
	int numVerts = mesh.getNumVertices();
	for (int a = 0; a < numVerts; ++a) {
		if (
			((a + 1) % numColumns == 0) || // rightmost column
			((a >= numVerts - numRows)) // bottom row
			)
			continue;
		ofVec3f verta = mesh.getVertex(a);
		// This essentially draws a clockwise line
		// grabbing verts forming a square cell.
		mesh.addIndex(a);
		mesh.addIndex(a+1);
		mesh.addIndex(a+5);
		mesh.addIndex(a+4);
		mesh.addIndex(a);
	}

	// Create a new "Cell Mesh" for every five indexes of the main mesh.
	for (int i = 0; i < mesh.getNumIndices(); ++i)
	{
		auto indexes = mesh.getIndices();
		if (i % 5 == 0)
		{
			ofMesh single_square;
			single_square.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

			single_square.enableIndices();
			single_square.enableColors();

			std::vector<ofColor> color_lookup = {
				ofColor::black,
				ofColor::white,
				ofColor::blueViolet,
				ofColor::green,
				ofColor::orangeRed
			};

			for (int cnt = 0; cnt <= 4; ++cnt)
			{

				single_square.addVertex(mesh.getVertex(indexes[i+cnt]));
				single_square.addIndex(cnt);
				single_square.addColor(color_lookup[cnt]);
			}

			mesh_vect.push_back(single_square);
		}
	}

}

void mkMeshGrid::update()
{
}

void mkMeshGrid::draw()
{
	//mesh.draw();
	for (auto& square : mesh_vect)
	{
		square.draw();
	}
}
