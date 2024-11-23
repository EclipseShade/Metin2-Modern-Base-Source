@echo off
if "%~1"=="" (
	echo "drag n drop the .eix on this .bat"
) else (
	if not exist "%~1\nul" (
		echo Unpacking %~n1...
		PackMakerLite --nolog --parallel -u "%~n1"
	) else (
		echo "%~1 not a .eix/epk to unpack"
	)
)
pause
