#pragma once

#include <plugin/plugin.h>

class PLUGIN_API CVector2D
{
public:
    float x, y;
    
	CVector2D();
	CVector2D(float x, float y);

	// Returns length of vector
	float Magnitude();

	void operator=(const CVector2D& right);
};