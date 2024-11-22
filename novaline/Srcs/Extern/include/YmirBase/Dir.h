#pragma once 

struct EL_DIR
{
	float w, h;
	EL_DIR(float w, float h) : w(w), h(h) {}

	float Dot(const EL_DIR& dst)
	{
		return w * dst.w + h * dst.h;
	}
};