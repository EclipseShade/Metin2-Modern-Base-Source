//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#ifndef _YMIRNETWORK_NETPACKET_H
#define _YMIRNETWORK_NETPACKET_H

#pragma pack(1)

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4201)
#endif

union EL_NetHeader
{
	EL_NetHeader()
	{
		integers[0] = 0;
		integers[1] = 0;
	}

	explicit EL_NetHeader(unsigned int _type)
	{
		integers[0] = 0;
		integers[1] = 0;

		type = _type;
	}

	explicit EL_NetHeader(const char * buf)
	{
		unsigned int * i = (unsigned int *) buf;
		integers[0] = *i;
		integers[1] = *(i + 1);
	}

	unsigned int integers[2];

	struct
	{
		unsigned type : 14;
		unsigned encrypted : 1;
		unsigned compressed : 1;
		unsigned reserved : 16;
		unsigned size : 32;
	};
};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

struct EL_NetPacket
{
    EL_NetHeader m_header;

    explicit EL_NetPacket(unsigned int type) : m_header(type)
    {
    }

    const char* data() const
    {
        return reinterpret_cast<const char*>(this);
    }

    size_t size() const
    {
        return m_header.size;
    }

    unsigned int type() const
    {
        return m_header.type;
    }

    void size(size_t _len)
    {
        m_header.size = _len;
    }

    const char* body() const
    {
        return reinterpret_cast<const char*>(this) + sizeof(EL_NetPacket);
    }
};
#pragma pack()

#define EL_DECLARE_PACKET(header, structname)\
	structname() : EL_NetPacket(header)\
	{\
		size(sizeof(structname));\
	}

#endif  // _YMIRNETWORK_NETPACKET_H
