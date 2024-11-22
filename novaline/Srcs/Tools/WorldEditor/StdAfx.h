// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__5B1D1F45_CAA4_43E6_AB3A_B375F8FE4624__INCLUDED_)
#define AFX_STDAFX_H__5B1D1F45_CAA4_43E6_AB3A_B375F8FE4624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxpriv.h>    // for CDockContext
#include <afxtempl.h>   // for CArray

#pragma warning(disable:4786)	// character 255 넘어가는거 끄기
#pragma warning(disable:4100)	// parameter 안쓰인거 경고 끄기
#pragma warning(disable:4710)	// inline 이 안됐다고 워닝나오는거 끄기

#include <il/il.h>

#include "../../Client/EterLib/StdAfx.h"
#include "../../Client/EterBase/StdAfx.h"
#include "../../Client/EterGrnLib/StdAfx.h"
#include "../../Client/EterImageLib/StdAfx.h"
#include "../../Client/PRTerrainLib/StdAfx.h"
#include "../../Client/GameLib/StdAfx.h"
#include "../../Client/EffectLib/StdAfx.h"
#include "../../Client/MilesLib/StdAfx.h"
#include "../../Client/ScriptLib/Resource.h"
#include "../../Client/SpeedTreeLib/StdAfx.h"

#include "Type.h"
#include "Util.h"

// UI
#include "./UI/SimpleUI.h"
#include "./UI/XBrowseForFolder.h"

// Data
#include "./DataCtrl/ActorInstanceAccessor.h"
#include "./DataCtrl/ModelInstanceAccessor.h"
#include "./DataCtrl/EffectAccessor.h"

#include "./DataCtrl/UndoBuffer.h"
#include "./DataCtrl/MapAccessorArea.h"

#include "./DataCtrl/ObjectData.h"

// Control Bar
//#include "./DockingBar/SizeCBar.h"
#include "./DockingBar/PageCtrl.h"
// Control Bar - Object

// Scene
#include "./Scene/PickingArrow.h"
#include "./Scene/SceneBase.h"
#include "./Scene/SceneMap.h"
#include "./Scene/SceneObject.h"
#include "./Scene/SceneEffect.h"
#include "./Scene/SceneFly.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5B1D1F45_CAA4_43E6_AB3A_B375F8FE4624__INCLUDED_)
