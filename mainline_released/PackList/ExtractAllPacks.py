import os
lines = open("pack/index").read().splitlines()
for dir, pack in zip(lines[1::2], lines[2::2]):
	os.system("ExtractPack.exe pack\\%s" % pack)
