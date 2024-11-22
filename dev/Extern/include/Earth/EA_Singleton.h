/**
 * @file	EA_Singleton.h
 * @brief	Singleton definition for Earth
 * @author	Standil (cpascal@cpascal.net)
 * 
 * @version	2007/06/10 cpascal - First Release
 *
 * (start code)
 *
 * :in header
 *
 * class CSampleClass
 * {
 *	'''
 *	EA_DECLARE_SINGLETON( CSampleClass );
 * };
 *
 * :in source
 *	EA_DEFINE_SINGLETON( CSampleClass );
 *
 * (end)
 */

#ifndef _EA_SINGLETON_H_
#define _EA_SINGLETON_H_

/**
 * @brief	Default Singleton Declaration
 */
#define EA_DECLARE_SINGLETON( ClassType )	\
public: \
	static EA_BOOL		sCreateActive( void ) \
	{ \
		ms_pActive = new ClassType; \
		return (ms_pActive != EA_NULL)? EA_TRUE: EA_FALSE; \
	} \
	\
	static ClassType*	sGetActive( void ) \
	{ \
		if( EA_NULL == ms_pActive ) { \
			if( FALSE == sCreateActive() ) { \
				/* error: failed to create instance */ \
			} \
		} \
		return ms_pActive; \
	} \
	\
	static void		sDestroyActive( void ) \
	{ \
		EA_SAFE_DELETE( ms_pActive ); \
	} \
private: \
	static ClassType*	ms_pActive; \

/**
 * @brief	Default Singleton Definition
 */
#define EA_DEFINE_SINGLETON( ClassType )	\
ClassType* ClassType::ms_pActive = EA_NULL;


/**
 * @brief	Explicit Creation/Deletion Singleton Declaration
 */
#define EA_DECLARE_EXPLICITSINGLETON( ClassType )	\
public: \
	static EA_BOOL		sCreateActive( void ) \
	{ \
		ms_pActive = new ClassType; \
		return (ms_pActive != EA_NULL)? EA_TRUE: EA_FALSE; \
	} \
	\
	static void sSetActive( ClassType* pcNewClass ) \
	{ \
		ms_pActive = pcNewClass; \
	} \
	\
	static ClassType*	sGetActive( void ) \
	{ \
		return ms_pActive; \
	} \
	\
	static void		sDestroyActive( void ) \
	{ \
		EA_SAFE_DELETE( ms_pActive ); \
	} \
private: \
	static ClassType*	ms_pActive;

/**
 * @brief	Explicit Creation/Deletion Singleton Definition
 */
#define EA_DEFINE_EXPLICITSINGLETON( ClassType )	ClassType* ClassType::ms_pActive = EA_NULL;

#endif //!_EA_SINGLETON_H_
