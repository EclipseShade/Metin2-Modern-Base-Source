junction -s "d:\ymir work" ..\..\data 
mkdir patch\metin2_patch_kr3
mkdir patch\metin2_patch_kr3\pack
cd ..\..\data\bin
..\..\tools\pack\MakePack.exe ..\..\tools\pack\metin2_patch_kr3.txt
cd ..\..\tools\pack
junction -d "d:\ymir work"
pause
