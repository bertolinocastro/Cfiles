#ifdef linux
	#define KNRM  "\x1B[0m"
	#define KRED  "\x1B[31m"
	#define KGRN  "\x1B[32m"
	#define KYEL  "\x1B[33m"
	#define KBLU  "\x1B[34m"
	#define KMAG  "\x1B[35m"
	#define KCYN  "\x1B[36m"
	#define KWHT  "\x1B[37m"
#else
	#define KNRM  system( "color 70" )
	#define KRED  system( "color 40" )
	#define KGRN  system( "color 20" )
	#define KYEL  system( "color 60" )
	#define KBLU  system( "color 10" )
	#define KMAG  system( "color D0" )
	#define KCYN  system( "color 90" )
	#define KWHT  system( "color F0" )
#endif