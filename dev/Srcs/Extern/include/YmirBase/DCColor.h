#pragma once

union EL_DCColorUnion
{
	EL_RGBA rgba;
	EL_ARGB argb;
	EL_BGRA bgra;
	EL_UINT32 v32;
};

class EL_DCColor
{
public:
	EL_DCColor(EL_UINT32 value);
	EL_DCColor(EL_UINT r, EL_UINT g, EL_UINT b);

	const EL_DCColorUnion& GetUnion();

	EL_UINT32 GetValue32() const;

	EL_UINT   GetRed();
	EL_UINT   GetGreen();
	EL_UINT   GetBlue();

private:
	EL_DCColorUnion m_colorUnion;
};
