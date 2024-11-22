#ifndef __REDUCIO_API_H__
#define __REDUCIO_API_H__

namespace Reducio 
{
	typedef unsigned char U8;

	struct  TImageStream;
	typedef TImageStream*	ImageHandle;

	enum eReturnCode
	{
		eSuccess				=  0, 
		eErrFail				= -1,
		eFail_UnSupportedFormat = -2,
		eFail_errFileIO			= -3,
		eFail_InvalidArgument	= -4,
	};

	enum
	{
		//CQ means compress quality
		eCQ_Loseless = 0x00,
		eCQ_VeryHigh = 0x14,
		eCQ_High	 = 0x28,
		eCQ_Medium	 = 0x32,
		eCQ_Low		 = 0x3C,
	};

	enum eSourceImageType
	{
		eSrcImg_BMP = 0,
		eSrcImg_DDS = 1,
	};

	//Image Handle Related Functions
	ImageHandle CreateImageStreamHandle();
	void		GetImageStreamInfo( ImageHandle h, U8** ppb, int& rlen, int& rMipLevel );
	void		DestroyImageStreamHandle( ImageHandle h );

	//Compress Image
	//Currently Supported DDS Format( DXT1 for opaque, DXT5 for alpha )

	//Make WMP( Window Media Photo ) MemStream From BMP or DDS file
	eReturnCode CompressWMPImageFromFile(ImageHandle wmpHandle, const char* pFileName, int nCompressQuality);  

	//Make WMP( Window Media Photo ) MemStream From BMP or DDS Memory Layout
	eReturnCode CompressWMPImageFromMemory(ImageHandle wmpHandle, const U8* pbSrcStream, int nSrcStreamLen, eSourceImageType eSrcImageType, int nCompressQuality);

	//Write WMP file from WMP MemStream
	eReturnCode DumpWMPImageToFile(ImageHandle wmpHandle, const char* pWMPOutFileName);

	//WMP Stream To DDS Stream
	eReturnCode DecompressToDDSFromWMPStream(ImageHandle ddsHandle, const U8* pbSrcStream, int nSrcStreamLen, int nAutoGenMipMap = 0 );

	//WMP File To DDS Stream
	eReturnCode DecompressToDDSFromWMPFile(ImageHandle ddsHandle, const char* pWMPFileName, int nAutoGenMipMap = 0 );

	//Dump Stream to DDS File
	eReturnCode DumpDDSImageToFile( ImageHandle ddsHandle, const char* pDDSOutFileName);

} // namespace Reducio


#endif //__REDUCIO_API_H__