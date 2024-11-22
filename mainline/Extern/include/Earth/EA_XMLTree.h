#ifndef _EA_XMLTREE_H_
#define _EA_XMLTREE_H_

#include "EA_CXMLNode.h"
#include "EA_CStatus.h"

_EA_NAMESPACE_BEGIN

#define EA_XMLDEST_NONE		0x00
#define EA_XMLDEST_SUB		0x01
#define EA_XMLDEST_NEXT		0x02

struct EA_XMLTree {
	EA_CXMLNode*	pcRoot;
	EA_CXMLNode*	pcCurrent;
	UINT			iNextPlace;
};

typedef struct EA_XMLTree		EA_XMLTree;

EA_XMLTree*		EA_XMLTree_Load( LPCSTR szBuffer, int nBufferSize, EA_CStatus* pcStatus );
EA_CXMLNode*	EA_XMLTree_GetRoot( EA_XMLTree* pcXMLTree );

_EA_NAMESPACE_END

#endif /* !_EA_XMLTREE_H_ */
