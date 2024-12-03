#ifndef __INC_DB_CACHE_H__
#define __INC_DB_CACHE_H__

#include "../common/cache.h"
#include "../common/auction_table.h"

class CItemCache : public cache<TPlayerItem>
{
    public:
	CItemCache();
	virtual ~CItemCache();

	void Delete();
	virtual void OnFlush();
};

class CPlayerTableCache : public cache<TPlayerTable>
{
    public:
	CPlayerTableCache();
	virtual ~CPlayerTableCache();

	virtual void OnFlush();

	DWORD GetLastUpdateTime() { return m_lastUpdateTime; }
};

// MYSHOP_PRICE_LIST

class CItemPriceListTableCache : public cache< TItemPriceListTable >
{
    public:

	/// Constructor

	CItemPriceListTableCache(void);
	virtual ~CItemPriceListTableCache();

	void	UpdateList(const TItemPriceListTable* pUpdateList);

	virtual void	OnFlush(void);

    private:

	static const int	s_nMinFlushSec;		///< Minimum cache expire time
};
// END_OF_MYSHOP_PRICE_LIST
#ifdef __AUCTION__

class CAuctionItemInfoCache : public cache <TAuctionItemInfo>
{
public:
	typedef TWishItemInfo value_type;
	CAuctionItemInfoCache();
	virtual ~CAuctionItemInfoCache();

	void Delete();
	virtual void OnFlush();
};

class CSaleItemInfoCache : public cache <TSaleItemInfo>
{
public:
	typedef TWishItemInfo value_type;
	CSaleItemInfoCache();
	virtual ~CSaleItemInfoCache();

	void Delete();
	virtual void OnFlush();
};

class CWishItemInfoCache : public cache <TWishItemInfo>
{
public:
	typedef TWishItemInfo value_type;
	CWishItemInfoCache();
	virtual ~CWishItemInfoCache();

	void Delete();
	virtual void OnFlush();
};
#endif
#endif
