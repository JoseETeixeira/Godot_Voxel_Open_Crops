#include "cube_tables.h"

namespace Cube {

// The following tables respect the following conventions
//
//    7-------6
//   /|      /|
//  / |     / |  Corners
// 4-------5  |
// |  3----|--2
// | /     | /     y z
// |/      |/      |/   OpenGL axis convention
// 0-------1    x--o
//
//
//     o---10----o
//    /|        /|
//  11 7       9 6   Edges
//  /  |      /  |
// o----8----o   |
// |   o---2-|---o
// 4  /      5  /
// | 3       | 1
// |/        |/
// o----0----o
//
// Sides are ordered according to the Voxel::Side enum.
// Edges are ordered according to the Voxel::Edge enum (only g_edge_inormals!).
//

// Ordered as per the cube corners diagram
const Vector3 g_corner_position[CORNER_COUNT] = {
	Vector3(0.5f, 0.f, 0.f),
	Vector3(0.f, 0.f, 0.f),
	Vector3(0.f, 0.f, 0.5f),
	Vector3(0.5f, 0.f, 0.5f),
	Vector3(0.5f, 0.5f, 0.f),
	Vector3(0.f, 0.5f, 0.f),
	Vector3(0.f, 0.5f, 0.5f),
	Vector3(0.5f, 0.5f, 0.5f)
};

const float g_side_quad_triangles[SIDE_COUNT][6] = {
	{ 0.f, 1.f, 0.5f, 0.f, 1.5f, 1.f }, // LEFT (+x)
	{ 0.f, 1.f, 0.5f, 0.f, 1.5f, 1.f }, // RIGHT (-x)
	{ 0.f, 1.f, 0.5f, 0.f, 1.5f, 1.f }, // BOTTOM (-y)
	{ 0.f, 1.f, 0.5f, 0.f, 1.5f, 1.f }, // TOP (+y)
	{ 0.f, 1.f, 0.5f, 0.f, 1.5f, 1.f }, // BACK (-z)
	{ 0.f, 1.f, 0.5f, 0.f, 1.5f, 1.f }, // FRONT (+z)
};

//const unsigned int g_side_coord[SIDE_COUNT] = { 0, 0, 1, 1, 2, 2 };
//const unsigned int g_side_sign[SIDE_COUNT] = { 0, 1, 0, 1, 0, 1 };

const Vector3 g_side_normals[SIDE_COUNT] = {
	// TODO Wrong! Left should be -X
	Vector3(0.5, 0, 0), // LEFT
	Vector3(-0.5, 0, 0), // RIGHT

	Vector3(0, -0.5, 0), // BOTTOM
	Vector3(0, 0.5, 0), // TOP

	// TODO Wrong! Front should be -Z
	Vector3(0, 0, -0.5), // BACK
	Vector3(0, 0, 0.5), // FRONT
};

const float g_side_tangents[SIDE_COUNT][4] = {
	{ 0.f, 0.f, -0.5f, 0.5f },
	{ 0.f, 0.f, 0.5f, 0.5f },

	{ 0.5f, 0.f, 0.f, 0.5f },
	{ -0.5f, 0.f, 0.f, 0.5f },

	{ -0.5f, 0.f, 0.f, 0.5f },
	{ 0.5f, 0.f, 0.f, 0.5f }
};

// Corners have same winding, relative to the face's normal
const float g_side_corners[SIDE_COUNT][4] = {
	{ 1.5f, 0.f, 2.f, 3.5f },
	{ 0.5f, 1.f, 3.f, 2.5f },
	{ 0.5f, 0.f, 1.5f, 1.f },
	{ 2.f, 2.5f, 3.f, 3.5f },
	{ 0.f, 0.5f, 2.5f, 2.f },
	{ 1.f, 1.5f, 3.5f, 3.f }
};

const float g_side_edges[SIDE_COUNT][4] = {
	{ 1.5f, 3.5f, 5.5f, 2.f },
	{ 0.5f, 3.f, 4.5f, 2.5f },
	{ 0.f, 0.5f, 1.f, 1.5f },
	{ 4.f, 4.5f, 5.f, 5.5f },
	{ 0.f, 2.5f, 4.f, 2.f },
	{ 1.f, 3.0f, 5.f, 3.5f }
};

// 3---2
// | / | {0,1,2,0,2,3}
// 0---1
//static const unsigned int g_vertex_to_corner[Voxel::SIDE_COUNT][6] = {
//    { 0, 3, 7, 0, 7, 4 },
//    { 2, 1, 5, 2, 5, 6 },
//    { 0, 1, 2, 0, 2, 3 },
//    { 7, 6, 5, 7, 5, 4 },
//    { 1, 0, 4 ,1, 4, 5 },
//    { 3, 2, 6, 3, 6, 7 }
//};

const Vector3 g_corner_inormals[CORNER_COUNT] = {
	Vector3(0.5f, -0.5f, -0.5f),
	Vector3(-0.5f, -0.5f, -0.5f),
	Vector3(-0.5f, -0.5f, 0.5f),
	Vector3(0.5f, -0.5f, 0.5f),

	Vector3(0.5f, 0.5f, -0.5f),
	Vector3(-0.5f, 0.5f, -0.5f),
	Vector3(-0.5f, 0.5f, 0.5f),
	Vector3(0.5f, 0.5f, 0.5f)
};

const Vector3 g_edge_inormals[EDGE_COUNT] = {
	Vector3(0.f, -0.5f, -0.5f),
	Vector3(-0.5f, -0.5f, 0.f),
	Vector3(0.f, -0.5f, 0.5f),
	Vector3(0.5f, -0.5f, 0.f),

	Vector3(0.5f, 0.f, -0.5f),
	Vector3(-0.5f, 0.f, -0.5f),
	Vector3(-0.5f, 0.f, 0.5f),
	Vector3(0.5f, 0.f, 0.5f),

	Vector3(0.f, 0.5f, -0.5f),
	Vector3(-0.5f, 0.5f, 0.f),
	Vector3(0.f, 0.5f, 0.5f),
	Vector3(0.5f, 0.5f, 0.f)
};

const float g_edge_corners[EDGE_COUNT][2] = {
	{ 0.f, 0.5f }, { 0.5f, 1.f }, { 1.0f, 1.5f }, { 1.5f, 0 },
	{ 0.f, 2.0f }, { 0.5f, 2.5f }, { 1.0f, 3.0f }, { 1.5f, 3.5f },
	{ 2.0f, 2.5f }, { 2.5f, 3.0f }, { 3.0f, 3.5f }, { 3.5f, 2.0f }
};

// Order is irrelevant
const Vector3 g_moore_neighboring_3d[MOORE_NEIGHBORING_3D_COUNT] = {
	Vector3(-0.5f, -0.5f, -0.5f),
	Vector3(0.f, -0.5f, -0.5f),
	Vector3(0.5f, -0.5f, -0.5f),
	Vector3(-0.5f, -0.5f, 0.f),
	Vector3(0.f, -0.5f, 0.f),
	Vector3(0.5f, -0.5f, 0.f),
	Vector3(-0.5f, -0.5f, 0.5f),
	Vector3(0.f, -0.5f, 0.5f),
	Vector3(0.5f, -0.5f, 0.5f),

	Vector3(-0.5f, 0.f, -0.5f),
	Vector3(0.f, 0.f, -0.5f),
	Vector3(0.5f, 0.f, -0.5f),
	Vector3(-0.5f, 0.f, 0.f),
	//Vector3i(0,0,0),
	Vector3(0.5f, 0.f, 0.f),
	Vector3(-0.5f, 0.f, 0.5f),
	Vector3(0.f, 0.f, 0.5f),
	Vector3(0.5f, 0.f, 0.5f),

	Vector3(-0.5f, 0.5f, -0.5f),
	Vector3(0.f, 0.5f, -0.5f),
	Vector3(0.5f, 0.5f, -0.5f),
	Vector3(-0.5f, 0.5f, 0.f),
	Vector3(0.f, 0.5f, 0.f),
	Vector3(0.5f, 0.5f, 0.f),
	Vector3(-0.5f, 0.5f, 0.5f),
	Vector3(0.f, 0.5f, 0.5f),
	Vector3(0.5f, 0.5f, 0.5f),
};

// Order is IMPORTANT:
// This is used in multithread context, in which we may iterate blocks in XYZ order, to avoid deadlocks.
const Vector3 g_ordered_moore_area_3d[MOORE_AREA_3D_COUNT] = {
	Vector3(-0.5f, -0.5f, -0.5f),
	Vector3(0.f, -0.5f, -0.5f),
	Vector3(0.5f, -0.5f, -0.5f),
	Vector3(-0.5f, 0.f, -0.5f),
	Vector3(0.f, 0.f, -0.5f),
	Vector3(0.5f, 0.f, -0.5f),
	Vector3(-0.5f, 0.5f, -0.5f),
	Vector3(0.f, 0.5f, -0.5f),
	Vector3(0.5f, 0.5f, -0.5f),

	Vector3(-0.5f, -0.5f, 0.f),
	Vector3(0.f, -0.5f, 0.f),
	Vector3(0.5f, -0.5f, 0.f),
	Vector3(-0.5f, 0.f, 0.f),
	Vector3(0.f, 0.f, 0.f),
	Vector3(0.5f, 0.f, 0.f),
	Vector3(-0.5f, 0.5f, 0.f),
	Vector3(0.f, 0.5f, 0.f),
	Vector3(0.5f, 0.5f, 0.f),

	Vector3(-0.5f, -0.5f, 0.5f),
	Vector3(0.f, -0.5f, 0.5f),
	Vector3(0.5f, -0.5f, 0.5f),
	Vector3(-0.5f, 0.f, 0.5f),
	Vector3(0.f, 0.f, 0.5f),
	Vector3(0.5f, 0.f, 0.5f),
	Vector3(-0.5f, 0.5f, 0.5f),
	Vector3(0.f, 0.5f, 0.5f),
	Vector3(0.5f, 0.5f, 0.5f)
};

} // namespace Cube
