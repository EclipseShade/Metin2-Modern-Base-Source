from P4 import P4

def P4_GetRevisionFilePaths(p4, revisions):
    filePaths = set()
    for revision in revisions:
        results = p4.run("describe", "-s", str(revision))
        for result in results:
            filePaths.update(result["depotFile"])

    return filePaths

def P4_GetSortedRevisionFilePaths(p4, revisions):
    filePaths = list(P4_GetRevisionFilePaths(p4, revisions))
    filePaths.sort()
    return filePaths

