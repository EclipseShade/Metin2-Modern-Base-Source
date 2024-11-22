# -*- coding:cp949 -*-
import urlimport_metin2

from P4 import P4
from metin2perforce import P4_GetRevisionLocalFilePaths

PROPERTY = "property"
TEXTURESET = "textureset"

p4 = P4()
p4.connect()
for filePath in P4_GetRevisionLocalFilePaths(p4, [12185, 12186, 12187, 12245, 12325, 12327]):
    if filePath[:len(PROPERTY)] == PROPERTY or filePath[:len(TEXTURESET)] == TEXTURESET: # 665 프로퍼티 문제로 인해 프로퍼티, 텍스쳐 셋 제외
        continue
    print "\t\"%s\"" % filePath
