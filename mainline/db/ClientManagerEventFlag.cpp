#include "stdafx.h"

#include "ClientManager.h"
#include "Main.h"
#include "Config.h"
#include "DBManager.h"
#include "QID.h"

void CClientManager::LoadEventFlag() {
    std::ostringstream queryStream;
    queryStream << "SELECT szName, lValue FROM quest" << GetTablePostfix() << " WHERE dwPID = 0";
    
    std::auto_ptr<SQLMsg> pmsg(CDBManager::instance().DirectQuery(queryStream.str().c_str()));

    SQLResult* pRes = pmsg->Get();
    if (pRes->uiNumRows) {
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(pRes->pSQLResult))) {
            TPacketSetEventFlag p;
            strlcpy(p.szFlagName, row[0], sizeof(p.szFlagName));
            str_to_number(p.lValue, row[1]);
            
            std::ostringstream logStream;
            logStream << "EventFlag Load " << p.szFlagName << " " << p.lValue;
            sys_log(0, logStream.str().c_str());
            
            m_map_lEventFlag.insert(std::make_pair(std::string(p.szFlagName), p.lValue));
            ForwardPacket(HEADER_DG_SET_EVENT_FLAG, &p, sizeof(TPacketSetEventFlag));
        }
    }
}

void CClientManager::SetEventFlag(TPacketSetEventFlag* p) {
    ForwardPacket(HEADER_DG_SET_EVENT_FLAG, p, sizeof(TPacketSetEventFlag));

    bool bChanged = false;

    auto it = m_map_lEventFlag.find(p->szFlagName);
    if (it == m_map_lEventFlag.end()) {
        bChanged = true;
        m_map_lEventFlag.insert(std::make_pair(std::string(p->szFlagName), p->lValue));
    } else if (it->second != p->lValue) {
        bChanged = true;
        it->second = p->lValue;
    }

    if (bChanged) {
        std::ostringstream query;
        query << "REPLACE INTO quest" << GetTablePostfix()
            << " (dwPID, szName, szState, lValue) VALUES(0, '"
            << p->szFlagName << "', '', " << p->lValue << ")";

        CDBManager::instance().AsyncQueryPrepare(query.str());

        std::ostringstream logOss;
        logOss << "HEADER_GD_SET_EVENT_FLAG : Changed CClientmanager::SetEventFlag("
               << p->szFlagName << " " << p->lValue << ") ";
        sys_log(0, logOss.str().c_str());
        return;
    }

    std::ostringstream logOss;
    logOss << "HEADER_GD_SET_EVENT_FLAG : No Changed CClientmanager::SetEventFlag("
           << p->szFlagName << " " << p->lValue << ") ";
    sys_log(0, logOss.str().c_str());
}

void CClientManager::SendEventFlagsOnSetup(CPeer* peer) {
	decltype(m_map_lEventFlag.begin()) it;

	for (it = m_map_lEventFlag.begin(); it != m_map_lEventFlag.end(); ++it) {
		TPacketSetEventFlag p;
		strlcpy(p.szFlagName, it->first.c_str(), sizeof(p.szFlagName));
		p.lValue = it->second;
		peer->EncodeHeader(HEADER_DG_SET_EVENT_FLAG, 0, sizeof(TPacketSetEventFlag));
		peer->Encode(&p, sizeof(TPacketSetEventFlag));
	}
}

