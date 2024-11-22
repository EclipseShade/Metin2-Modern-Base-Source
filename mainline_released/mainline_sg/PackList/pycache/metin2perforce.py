import urlimport_myevan

from P4 import P4
from P4_utils import P4_GetSortedRevisionFilePaths

remoteBasePath = "//metin2/main/data/"
remoteBinPath = "//metin2/main/data/bin/"
localBasePath = "d:/ymir work/"

def P4_GetRevisionLocalFilePaths(p4, revisions):
    for filePath in P4_GetSortedRevisionFilePaths(p4, revisions):
        yield filePath[len(remoteBinPath):] if filePath[:len(remoteBinPath)].lower() == remoteBinPath else localBasePath + filePath[len(remoteBasePath):]


if __name__ == "__main__":
    p4 = P4()
    p4.connect()
    for filePath in P4_GetRevisionLocalFilePaths(p4, [12185, 12186, 12187, 12245]):
        print filePath
