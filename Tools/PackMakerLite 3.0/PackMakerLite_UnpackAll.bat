@echo off
    for /R "." %%f in (*.eix) do (
	echo processing %%~pf%%~nf
	PackMakerLite --nolog -u "%%~pf%%~nf"
)
pause
