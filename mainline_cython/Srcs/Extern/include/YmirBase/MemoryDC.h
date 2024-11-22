#pragma once

#include "SmartPointer.h"
#include "DC.h"
#include "DCDIB32.h"

EL_BOOST_PTR(EL_MemoryDC);

class EL_MemoryDC : public EL_DC
{
public:
	virtual ~EL_MemoryDC();

public:	
	EL_BOOST_NEW_SHARED_PTR2(EL_MemoryDC, const EL_DC&, const EL_DCSIZE&);
	
	EL_VOID Clear();
	EL_VOID Draw(EL_DC& dcDst);

	EL_VOID Resize(const EL_DCSIZE& size);

	EL_UINT GetWidth();
	EL_UINT GetHeight();

	EL_DCDIB32& GetDIB32();
	
protected:
	EL_MemoryDC(const EL_DC& dc, const EL_DCSIZE& size);	

private:
	EL_DCDIB32	m_dib;

private:
	HGDIOBJ m_hOldObj;
};
