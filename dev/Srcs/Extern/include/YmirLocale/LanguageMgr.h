#pragma once

#include <map>

#include "LanguageCodePage.h"

EL_BOOST_PTR(EL_Language);

class EL_LanguageMgr
{
public:
	static EL_LanguageMgr& GetLanguageMgr();

public:
	EL_VOID SetDefaultCodePage(EL_CODE_PAGE cp);

	EL_LanguagePtr GetDefaultLanguage();

	EL_LanguagePtr FindLanguageByCodePage(EL_CODE_PAGE cp);

protected:
	EL_LanguageMgr();

private:
	typedef std::map<EL_CODE_PAGE, EL_LanguagePtr> EL_LanguagePtrd;

private:
	EL_LanguagePtrd m_regLangPtrd;
	EL_LanguagePtr  m_defLangPtr;
};