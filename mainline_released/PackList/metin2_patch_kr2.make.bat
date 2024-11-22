junction -s "d:\ymir work" ..\..\data 
mkdir patch\metin2_patch_kr2
mkdir patch\metin2_patch_kr2\pack
cd ..\..\data\bin
..\..\tools\pack\MakePack.exe ..\..\tools\pack\metin2_patch_kr2.txt
cd ..\..\tools\pack
junction -d "d:\ymir work"
