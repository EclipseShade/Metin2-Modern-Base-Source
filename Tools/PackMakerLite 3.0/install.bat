@copy /Y "%~dp0\PackMakerLite.exe" "c:\windows\system32\"
@copy /Y "%~dp0\PackMakerLite_p.bat" "c:\windows\system32\"
@copy /Y "%~dp0\PackMakerLite_u.bat" "c:\windows\system32\"
@regedit.exe /S "%~dp0\menu-integration\PML_Pack.add.reg"
@regedit.exe /S "%~dp0\menu-integration\PML_Unpack.add.reg"
@echo PML installed
@pause
