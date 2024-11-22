import sys
import os
import glob
import binascii
import ctypes
from zipfile import ZipFile
from zipfile import ZIP_DEFLATED

def MakeSfx(srcExePath, locale_name, certPass=""):
	skinDir = "LauncherSkin_" + locale_name
	dstExeDir = "Output_" + locale_name
	dstExeName = "metin2_patcher.exe"
	dstExePath = dstExeDir + "\\" + dstExeName
	if os.access(dstExeDir, os.R_OK):
		if os.access(dstExePath, os.W_OK):
			os.remove(dstExePath)
	else:
		os.makedirs(dstExeDir)

	tmpDataPath = "%s/TorrentPatchData.zip" % (dstExeDir)

	z = ZipFile(tmpDataPath, "w", ZIP_DEFLATED)
	skinPaths = glob.glob("%s/*.*" % skinDir)
	for skinPath in skinPaths:
		skinName = os.path.split(skinPath)[1]
		if skinName[0] != "_":
			z.write(skinPath, skinName)
	z.close()

	bin = open(srcExePath, "rb").read()
	dat = open(tmpDataPath, "rb").read()
	out = bin + dat

	open(dstExePath, "wb").write(out)
	os.system("reshacker.exe -modify %(dstExePath)s, %(dstExePath)s, %(skinDir)s/TorrentPatch.ico, icongroup, 101, 0" % locals())

	signtoolExeName = "signtool.exe"
	pfxFileName = "Ymir.pfx"

	if certPass:
		os.system("%(signtoolExeName)s sign /f %(pfxFileName)s /p %(certPass)s /t http://timestamp.verisign.com/scripts/timestamp.dll /d \"Metin2 Patcher\" %(dstExePath)s" % locals())

	crcValue = ctypes.c_ulong(binascii.crc32(open(dstExePath, "rb").read())).value
	print "0x%x" % crcValue
	crcFile = open ("crc_"+locale_name+".txt", "w")
	crcFile.write ('new_patcher_crc32="0x%x"' % crcValue)

	os.remove(tmpDataPath)

if __name__ == "__main__":
	if len(sys.argv) < 3:
		print "USAGE:"
		print "\t%s [source exe path] [destination exe path] [skin] [certpass]" % sys.argv[0]
	elif len(sys.argv) == 3:
		MakeSfx(sys.argv[1], sys.argv[2])
	elif len(sys.argv) == 4:
		MakeSfx(sys.argv[1], sys.argv[2], sys.argv[3])
	elif len(sys.argv) == 5:
		MakeSfx(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
	elif len(sys.argv) == 6:
		MakeSfx(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
