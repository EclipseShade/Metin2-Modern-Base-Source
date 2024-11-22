junction -s "d:\ymir work" ..\..\data 
mkdir patch\metin2_patch_eu2
mkdir patch\metin2_patch_eu2\pack
cd ..\..\data\bin
..\..\tools\pack\MakePackFiles.exe ..\..\tools\pack\metin2_patch_eu2.txt
..\..\tools\pack\MakePack.exe ..\..\tools\pack\metin2_common.txt
cd ..\..\tools\pack
copy common\*.eix patch\metin2_patch_eu2\pack 
copy common\*.epk patch\metin2_patch_eu2\pack
junction -d "d:\ymir work"
