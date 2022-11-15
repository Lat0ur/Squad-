#pragma once

struct vec2
{
	float x, y;
};

struct vec3
{
	float x, y, z;

	inline vec3& operator=  (const vec3& other) { x = other.x; y = other.y; z = other.z; return *this; }
};
struct vec4
{
	float x, y, z, w;
};
