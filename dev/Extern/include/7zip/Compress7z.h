#ifndef _COMPRESS7Z_
#define _COMPRESS7Z_


//comment
// arg : relative path & filename
//    ex) "./test/mytest.7z"
//return val : 0 - normally worked, 1 - problem occurred

int decompress7z (const char *archiveName);



#endif // _COMPRESS7Z_