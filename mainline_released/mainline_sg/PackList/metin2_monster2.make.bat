rem junction -s "d:\ymir work" ..\..\data 
mkdir main\metin2_monster2
mkdir main\metin2_monster2\pack
cd ..\..\data\bin
..\..\tools\pack\MakePackFiles.exe ..\..\tools\pack\metin2_monster2.txt
cd ..\..\tools\pack
rem junction -d "d:\ymir work"
