@echo off
for /D %%i in (*.*) do (
	PackMakerLite_p.bat %%i
)
pause
