// MiniMapRenderHelper.h: interface for the CMiniMapRenderHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINIMAPRENDERHELPER_H__D778645A_A305_4414_955D_69D08C9A943B__INCLUDED_)
#define AFX_MINIMAPRENDERHELPER_H__D778645A_A305_4414_955D_69D08C9A943B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMiniMapRenderHelper : public CScreen, public CSingleton<CMiniMapRenderHelper>
{
public:
	CMiniMapRenderHelper();
	~CMiniMapRenderHelper();

	bool CreateTextures();
	void ReleaseTextures();

	// Assign
	void SetMapOutdoorAccssorPointer(CMapOutdoorAccessor * pMapOutdoorAccessor) { m_pMapOutdoorAccessor = pMapOutdoorAccessor;	}
	void SetTargetTerrainCoord(WORD wCoordX, WORD wCoordY) { m_wCurCoordX = wCoordX; m_wCurCoordY = wCoordY; }

	void SetMiniMapPower(BYTE byMiniMapPower);
	void SetMiniMapFilter(D3DTEXTUREFILTERTYPE eTextureFilter);

	LPDIRECT3DTEXTURE8 GetMiniMapTexture() { return m_lpMiniMapRenderTargetTexture; }

	bool StartRendering();
	void EndRendering();

private:
	// Backup
	bool SaveRenderTarget();
	void RestoreRenderTarget();
	
	// CMapOutdoorAccessor Pointer
	CMapOutdoorAccessor *	m_pMapOutdoorAccessor;
	
	// ·£´õ¸µÇÒ ¶¥ ÁÂÇ¥
	WORD					m_wCurCoordX;
	WORD					m_wCurCoordY;

	// Size
	BYTE					m_byMiniMapPower;
	DWORD					m_dwMiniMapSize;
	
	// Shadow Map
	LPDIRECT3DSURFACE8		m_lpMiniMapRenderTargetSurface;
	LPDIRECT3DSURFACE8		m_lpMiniMapDepthSurface;
	LPDIRECT3DTEXTURE8		m_lpMiniMapRenderTargetTexture;
	D3DVIEWPORT8			m_MiniMapViewport;
	
	D3DTEXTUREFILTERTYPE	m_eMiniMapTextureFilter;
	
	// Backup
	LPDIRECT3DSURFACE8		m_lpBackupRenderTargetSurface;
	LPDIRECT3DSURFACE8		m_lpBackupDepthSurface;
	D3DVIEWPORT8			m_BackupViewport;
	D3DXMATRIX				m_matBackupProj;
	
};

#endif // !defined(AFX_MINIMAPRENDERHELPER_H__D778645A_A305_4414_955D_69D08C9A943B__INCLUDED_)
