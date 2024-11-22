//
// Copyright 2010 Ymir Entertainment. All rights reserved.
//
#pragma once

#include <YmirNetwork/NetPacket.h>

enum IFN_NetHeaders
{
    IFN_HEADER_GC_LOGIN = 1,
    IFN_HEADER_GC_CHAT = 2,
};

struct IFN_NetPacketGCLogin : EL_NetPacket
{
    char login[32];
    char password[32];

    EL_DECLARE_PACKET(IFN_HEADER_GC_LOGIN, IFN_NetPacketGCLogin);
};

struct IFN_NetPacketGCChat : EL_NetPacket
{
    char msg[256];

    EL_DECLARE_PACKET(IFN_HEADER_GC_CHAT, IFN_NetPacketGCChat);
};

