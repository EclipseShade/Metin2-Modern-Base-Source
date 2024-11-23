@echo off
if "%~1"=="" (
	echo "drag n drop the folder on this .bat"
) else (
	if exist "%~1" (
		echo Packing %~n1...
		PackMakerLite --nolog --parallel -p "%~n1"
	) else (
		echo "%~1 not a folder to pack"
	)
)
pause
