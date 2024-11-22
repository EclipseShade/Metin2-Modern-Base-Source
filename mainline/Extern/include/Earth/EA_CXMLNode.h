#ifndef _EA_CXMLNODE_H_
#define _EA_CXMLNODE_H_

_EA_NAMESPACE_BEGIN

class EA_CXMLNode
{
public:
	EA_CXMLNode( EA_CXMLNode* pcParent, LPCTSTR tszName );
	~EA_CXMLNode();
	TCHAR*			GetName()										{ return m_tszName; }
	TCHAR*			GetBody()										{ return m_tszBody; }
	EA_CXMLNode*	GetParent()										{ return m_pcParent; }
	EA_CXMLNode*	GetChild()										{ return m_pcChild; }
	EA_CXMLNode*	GetSibling()									{ return m_pcNext; }
	int				GetNumAttributes()								{ return m_nAttributes; }
	TCHAR*			GetAttributeNameByIndex( int iIndex )			{ return m_apstAttributes[iIndex].tszName; }
	TCHAR*			GetAttributeValueByIndex( int iIndex )			{ return m_apstAttributes[iIndex].tszValue; }
	TCHAR*			GetAttributeByName( TCHAR* tszAttributeName );
	EA_BOOL			SetAttributes( LPCTSTR* tszAttributes );
	int				GetParentBodyOffset();
	EA_CXMLNode*	GetChildByName( TCHAR* tszChildName );
	void			SetNext( EA_CXMLNode* pcNext )					{ m_pcNext = pcNext; }
	void			SetChild( EA_CXMLNode* pcChild )				{ m_pcChild = pcChild; }
	void			SetParent( EA_CXMLNode* pcParent )				{ m_pcParent = pcParent; }
	void			SetBody( LPCTSTR tszBody, size_t sizeLen );
	void			AddBody( LPCTSTR tszBody, size_t sizeLen );
//	void			AddChild( EA_CXMLNode* pcChild );

public:
	struct XMLAttribute {
		TCHAR*	tszName;
		TCHAR*	tszValue;
	};

	EA_CXMLNode*			m_pcParent;
	EA_CXMLNode*			m_pcChild;
	EA_CXMLNode*			m_pcNext;
	TCHAR*					m_tszName;
	TCHAR*					m_tszBody;
	int						m_nAttributes;
	struct XMLAttribute*	m_apstAttributes;
	int						m_iOffset;
};

_EA_NAMESPACE_END

#endif /* !_EA_CXMLNODE_H_ */
