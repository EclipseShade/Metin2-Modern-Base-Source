@REM @del "c:\windows\system32\PackMakerLite.exe"
@REM @del "c:\windows\system32\PackMakerLite_p.bat"
@REM @del "c:\windows\system32\PackMakerLite_u.bat"
@regedit.exe /S "%~dp0\menu-integration\PML_Pack.del.reg"
@regedit.exe /S "%~dp0\menu-integration\PML_Unpack.del.reg"
@echo PML uninstalled
@pause
