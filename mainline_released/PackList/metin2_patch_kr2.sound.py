# -*- coding:cp949 -*-
import sys
sys.path.append("pycache")

from P4 import P4
from metin2perforce import P4_GetRevisionLocalFilePaths

PROPERTY = "property"
TEXTURESET = "textureset"

p4 = P4()
p4.connect()
for filePath in P4_GetRevisionLocalFilePaths(p4, [12461, 12462, 12568, 12572, 12576, 12580, 12592, 12639, 12724, 12787, 12794]):
    if filePath == "SoundScript.txt":
        continue
    if filePath[:len(PROPERTY)] == PROPERTY or filePath[:len(TEXTURESET)] == TEXTURESET: # 665 프로퍼티 문제로 인해 프로퍼티, 텍스쳐 셋 제외
        continue
    print "\t\"%s\"" % filePath
