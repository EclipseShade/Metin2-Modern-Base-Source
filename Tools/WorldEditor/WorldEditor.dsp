# Microsoft Developer Studio Project File - Name="WorldEditor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WorldEditor - Win32 MfcDebug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WorldEditor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WorldEditor.mak" CFG="WorldEditor - Win32 MfcDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WorldEditor - Win32 MfcDebug" (based on "Win32 (x86) Application")
!MESSAGE "WorldEditor - Win32 MfcRelease" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WorldEditor - Win32 MfcDebug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WorldEditor___Win32_MfcDebug"
# PROP BASE Intermediate_Dir "WorldEditor___Win32_MfcDebug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WorldEditor___Win32_MfcDebug"
# PROP Intermediate_Dir "WorldEditor___Win32_MfcDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G6 /MTd /W3 /Gm /GR /GX /ZI /Od /I "../../extern/include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "DOUBLE_BUFFER" /D "WORLD_EDITOR" /Fr /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 granny2.lib mss32.lib SpeedTreeRT_static.lib lzo.lib ijl15.lib version.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"../../extern/lib"
# SUBTRACT LINK32 /map
# Begin Special Build Tool
TargetPath=.\WorldEditor___Win32_MfcDebug\WorldEditor.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=COPY $(TARGETPATH) "../bin"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WorldEditor - Win32 MfcRelease"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WorldEditor___Win32_MfcRelease"
# PROP BASE Intermediate_Dir "WorldEditor___Win32_MfcRelease"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WorldEditor___Win32_MfcRelease"
# PROP Intermediate_Dir "WorldEditor___Win32_MfcRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G6 /MT /W3 /GR /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "DOUBLE_BUFFER" /D "WORLD_EDITOR" /FAcs /Fr /Yu"StdAfx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 granny2.lib mss32.lib SpeedTreeRT_static.lib lzo.lib ijl15.lib version.lib /nologo /subsystem:windows /incremental:yes /machine:I386
# SUBTRACT LINK32 /map /debug /nodefaultlib
# Begin Special Build Tool
TargetPath=.\WorldEditor___Win32_MfcRelease\WorldEditor.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=COPY $(TARGETPATH) "../bin"	COPY $(TARGETPATH) "D:/ymir work/bin"
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "WorldEditor - Win32 MfcDebug"
# Name "WorldEditor - Win32 MfcRelease"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "WorldEditor - Win32 MfcDebug"

# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "WorldEditor - Win32 MfcRelease"

# ADD CPP /Yc"StdAfx.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Type.cpp
# End Source File
# Begin Source File

SOURCE=.\Type.h
# End Source File
# Begin Source File

SOURCE=.\Util.cpp
# End Source File
# Begin Source File

SOURCE=.\Util.h
# End Source File
# Begin Source File

SOURCE=.\ViewportManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewportManager.h
# End Source File
# Begin Source File

SOURCE=.\WorldEditor.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldEditor.h
# End Source File
# Begin Source File

SOURCE=.\WorldEditor.rc
# End Source File
# Begin Source File

SOURCE=.\WorldEditorDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldEditorDoc.h
# End Source File
# Begin Source File

SOURCE=.\WorldEditorView.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldEditorView.h
# End Source File
# End Group
# Begin Group "DataCtrl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DataCtrl\ActorInstanceAccessor.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ActorInstanceAccessor.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\EffectAccessor.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\EffectAccessor.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\EffectData.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectTranslationDialog.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorArea.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorArea.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorOutdoor.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorOutdoor.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorTerrain.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorTerrain.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapAccessorUndo.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapManagerAccessor.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapManagerAccessor.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapManagerEnvironment.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MapManagerUndo.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MiniMapRenderHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\MiniMapRenderHelper.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ModelInstanceAccessor.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ModelInstanceAccessor.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\NonPlayerCharacterInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\NonPlayerCharacterInfo.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ObjectAnimationAccessor.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ObjectAnimationAccessor.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ObjectData.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ObjectData.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ObjectDataFile.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ObjectDataLight.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ShadowRenderHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\ShadowRenderHelper.h
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\UndoBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\DataCtrl\UndoBuffer.h
# End Source File
# End Group
# Begin Group "DockingBar"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DockingBar\EffectCtrlBar.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectCtrlBar.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectLightPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectLightPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectMeshPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectMeshPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectParticlePage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectParticlePage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectParticleTexturePreview.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\effectparticletexturepreview.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectTabPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectTabPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectTexturePage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectTexturePage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectUI.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\EffectUI.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\FlyCtrlBar.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\FlyCtrlBar.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\FlyTabPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\FlyTabPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapAttributePage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\mapattributepage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapCtrlBar.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapCtrlBar.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapEnvironmentPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapEnvironmentPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapFilePage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapFilePage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapObjectPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapObjectPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageDungeonBlock.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageDungeonBlock.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapTabPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapTabPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapTerrainPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapTerrainPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\mapterraintexlistctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\mapterraintexlistctrl.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\mapterraintexturepreview.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\mapterraintexturepreview.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapTreeLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\MapTreeLoader.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventFly.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectAnimationEventGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectAnimationEventGraph.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectAnimationPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectAnimationPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectCtrlBar.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectCtrlBar.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelAttachEffectSubPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\objectmodelattacheffectsubpage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelAttachObjectSubPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelAttachObjectSubPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelCollisionSubPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelCollisionSubPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelTypeCharacterSubPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelTypeCharacterSubPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelTypeEquipmentSubPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectModelTypeEquipmentSubPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectTabPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\ObjectTabPage.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\PageCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\PageCtrl.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\SizeCBar.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\SizeCBar.h
# End Source File
# Begin Source File

SOURCE=.\DockingBar\texturepropertydlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DockingBar\texturepropertydlg.h
# End Source File
# End Group
# Begin Group "Scene"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Scene\PickingArrow.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\PickingArrow.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneBase.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneBase.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneBaseLocalCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneEffect.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneEffectGizmo.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneFly.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneFly.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneMap.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneMap.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneMapCursor.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneMapCursor.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneObject.cpp
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneObject.h
# End Source File
# Begin Source File

SOURCE=.\Scene\SceneObjectModelInstance.cpp
# End Source File
# End Group
# Begin Group "Dialog"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Dialog\changebasexydlg.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\changebasexydlg.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ColorAnimationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ColorAnimationDlg.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DlgGoto.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DlgGoto.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\dlginitbasetexture.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\dlginitbasetexture.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DlgPerspective.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DlgPerspective.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectBoundingSphere.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectBoundingSphere.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectParticleTimeEventGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectParticleTimeEventGraph.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectTimeBar.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectTimeBar.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectTimeBarGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectTimeBarGraph.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\EffectTranslationDialog.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\FloatEditDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\FloatEditDialog.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\GraphCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\GraphCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\InputNumber.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\InputNumber.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\maparrangeheightprogressdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\maparrangeheightprogressdialog.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectDirectory.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectDirectory.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectProperty.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectProperty.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageAmbience.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageAmbience.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageBase.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageBase.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageBuilding.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageBuilding.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageEffect.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageEffect.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapObjectPropertyPageTree.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapPortalDialog.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\MapPortalDialog.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\NewMapDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\NewMapDlg.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEvent.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventAttack.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventAttack.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventBase.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventCharacterHide.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventCharacterHide.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventCharacterShow.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventCharacterShow.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventEffect.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventEffectToTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventEffectToTarget.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventFly.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventScreenFlashing.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventScreenFlashing.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventScreenWaving.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventScreenWaving.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventSound.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventSound.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventWarp.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ObjectAnimationEventWarp.h
# End Source File
# End Group
# Begin Group "UI"

# PROP Default_Filter ""
# Begin Group "GTColorDialog"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UI\GTColorDialogDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorDialogDlg.h
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorSelectorWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorSelectorWnd.h
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorSliderWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorSliderWnd.h
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorWellWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\GTColorWellWnd.h
# End Source File
# Begin Source File

SOURCE=.\UI\GTDrawHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\GTDrawHelper.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\UI\FOHyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\FOHyperLink.h
# End Source File
# Begin Source File

SOURCE=.\UI\SimpleUI.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\SimpleUI.h
# End Source File
# Begin Source File

SOURCE=.\UI\XBrowseForFolder.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\XBrowseForFolder.h
# End Source File
# End Group
# Begin Group "ToolBar"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ToolBar\ToolBar256.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolBar\ToolBar256.h
# End Source File
# Begin Source File

SOURCE=.\ToolBar\ToolBarFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolBar\ToolBarFile.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ambience_distance.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\effect_light.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_m.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_maximize.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_mesh.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_minimize.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_particle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_play.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_play_loop.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_simple_particle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_sound.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_stop.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_texture.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_texture_billboard.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_timebar_enable.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_xyyzzx.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_xyz.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_z.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_zoom_in_horizon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\effect_zoom_out_horizon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fly_effect.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fly_object.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fly_type_exp.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fly_type_line.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fly_type_multi_line.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fly_type_sine.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mainframe_large.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mainframe_small.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_attribute.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_edit.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_envi.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_environment.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_file.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_object.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_down.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_noise.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_plateau.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_shape_circle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_shape_square.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_smooth.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map_terrain_brush_up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\object_a.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Object_Animation.bmp
# End Source File
# Begin Source File

SOURCE=.\res\object_light.bmp
# End Source File
# Begin Source File

SOURCE=.\res\object_m.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Object_Model.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TreeItemImageList.bmp
# End Source File
# Begin Source File

SOURCE=.\res\WorldEditor.ico
# End Source File
# Begin Source File

SOURCE=.\res\WorldEditor.rc2
# End Source File
# Begin Source File

SOURCE=.\res\WorldEditorDoc.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\History.txt
# End Source File
# End Target
# End Project
