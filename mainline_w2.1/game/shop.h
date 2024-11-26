#ifndef __INC_METIN_II_GAME_SHOP_H__
#define __INC_METIN_II_GAME_SHOP_H__

enum
{
	SHOP_MAX_DISTANCE = 1000
};

class CGrid;

/* ---------------------------------------------------------------------------------- */
class CShop
{
	public:
		typedef struct shop_item
		{
			DWORD	vnum;		// ������ ��ȣ
			long	price;		// ����
			BYTE	count;		// ������ ����

			LPITEM	pkItem;
			int		itemid;		// ������ �������̵�

			shop_item()
			{
				vnum = 0;
				price = 0;
				count = 0;
				itemid = 0;
				pkItem = NULL;
			}
		} SHOP_ITEM;

		CShop();
		~CShop();

		bool	Create(DWORD dwVnum, DWORD dwNPCVnum, TShopItemTable * pItemTable);
		void	SetShopItems(TShopItemTable * pItemTable, BYTE bItemCount);

		virtual void	SetPCShop(LPCHARACTER ch);
		virtual bool	IsPCShop()	{ return m_pkPC ? true : false; }

		// �Խ�Ʈ �߰�/����
		virtual bool	AddGuest(LPCHARACTER ch,DWORD owner_vid, bool bOtherEmpire);
		void	RemoveGuest(LPCHARACTER ch);

		// ���� ����
		virtual int	Buy(LPCHARACTER ch, BYTE pos);

		// �Խ�Ʈ���� ��Ŷ�� ����
		void	BroadcastUpdateItem(BYTE pos);

		// �Ǹ����� �������� ������ �˷��ش�.
		int		GetNumberByVnum(DWORD dwVnum);

		// �������� ������ ��ϵǾ� �ִ��� �˷��ش�.
		virtual bool	IsSellingItem(DWORD itemID);

		DWORD	GetVnum() { return m_dwVnum; }
		DWORD	GetNPCVnum() { return m_dwNPCVnum; }

	protected:
		void	Broadcast(const void * data, int bytes);

	protected:
		DWORD				m_dwVnum;
		DWORD				m_dwNPCVnum;

		CGrid *				m_pGrid;

		typedef TR1_NS::unordered_map<LPCHARACTER, bool> GuestMapType;
		GuestMapType m_map_guest;
		std::vector<SHOP_ITEM>		m_itemVector;	// �� �������� ����ϴ� ���ǵ�

		LPCHARACTER			m_pkPC;
};

typedef class CShop * LPSHOP;

class CShopManager : public singleton<CShopManager>
{
	public:
		typedef std::map<DWORD, CShop *> TShopMap;

	public:
		CShopManager();
		virtual ~CShopManager();

		bool	Initialize(TShopTable * table, int size);
		void	Destroy();

		LPSHOP	Get(DWORD dwVnum);
		LPSHOP	GetByNPCVnum(DWORD dwVnum);

		bool	StartShopping(LPCHARACTER pkChr, LPCHARACTER pkShopKeeper, int iShopVnum = 0);
		void	StopShopping(LPCHARACTER ch);

		void	Buy(LPCHARACTER ch, BYTE pos);
		void	Sell(LPCHARACTER ch, BYTE bCell, BYTE bCount=0);

		LPSHOP	CreatePCShop(LPCHARACTER ch, TShopItemTable * pTable, BYTE bItemCount);
		LPSHOP	FindPCShop(DWORD dwVID);
		void	DestroyPCShop(LPCHARACTER ch);

	private:
		TShopMap	m_map_pkShop;
		TShopMap	m_map_pkShopByNPCVnum;
		TShopMap	m_map_pkShopByPC;
};

#endif 
