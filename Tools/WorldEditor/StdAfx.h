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

#pragma warning(disable:4786)	// character 255 �Ѿ�°� ����
#pragma warning(disable:4100)	// parameter �Ⱦ��ΰ� ��� ����
#pragma warning(disable:4710)	// inline �� �ȵƴٰ� ���׳����°� ����

#include <il/il.h>

#include "../ClientSource/EterLib/StdAfx.h"
#include "../ClientSource/EterBase/StdAfx.h"
#include "../ClientSource/EterGrnLib/StdAfx.h"
#include "../ClientSource/EterImageLib/StdAfx.h"
#include "../ClientSource/PRTerrainLib/StdAfx.h"
#include "../ClientSource/GameLib/StdAfx.h"
#include "../ClientSource/EffectLib/StdAfx.h"
#include "../ClientSource/MilesLib/StdAfx.h"
#include "../ClientSource/ScriptLib/Resource.h"
#include "../ClientSource/SpeedTreeLib/StdAfx.h"

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
