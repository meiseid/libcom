/*
GPS 座標操作関係
日本測地系<->世界測地系 相互変換(近似値)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 世界測地系->日本測地系変換 */
/* double lat,lon=度単位10進数 例=35.910722,139.459500 */
extern void com_wgs84_to_tokyo( double lat_w,double lon_w,double *lat_t,double *lon_t )
{
	*lat_t = (lat_w + 0.00010696 * lat_w - 0.000017467 * lon_w - 0.0046020);
	*lon_t = (lon_w + 0.000046047 * lat_w + 0.000083049 * lon_w - 0.010041);
}

/* 日本測地系->世界測地系変換 */
extern void com_tokyo_to_wgs84( double lat_t,double lon_t,double *lat_w,double *lon_w )
{
	*lat_w = (lat_t - 0.00010695 * lat_t + 0.000017464 * lon_t + 0.0046017);
	*lon_w = (lon_t - 0.000046038 * lat_t - 0.000083043 * lon_t + 0.010040);
}

/* TEST MAIN
gcc -D_COM_GEO_MAIN geo.c
*/
#ifdef _COM_GEO_MAIN
extern int main(int argc, char **argv) {
	double lat_t_houya = 35.744686; //保谷駅南口(日本測地)
	double lon_t_houya = 139.570373; //保谷駅南口(日本測地)
	double lat_w_houya;
	double lon_w_houya;
	double lat_t_inari = 35.721528; //東伏見稲荷神社(日本測地)
	double lon_t_inari = 139.560722; //東伏見稲荷神社(日本測地)
	double lat_w_inari; //
	double lon_w_inari;

	com_tokyo_to_wgs84(lat_t_houya, lon_t_houya, &lat_w_houya, &lon_w_houya);
	fprintf(stdout,"保谷駅南口 日本測地: %.6lf,%.6lf 世界測地: %.6lf,%.6lf\n",
		lat_t_houya, lon_t_houya, lat_w_houya, lon_w_houya);

	com_wgs84_to_tokyo(lat_w_houya, lon_w_houya, &lat_t_houya, &lon_t_houya);
	fprintf(stdout,"保谷駅南口 世界測地: %.6lf,%.6lf 日本測地: %.6lf,%.6lf\n",
		lat_w_houya, lon_w_houya, lat_t_houya, lon_t_houya );

	com_tokyo_to_wgs84(lat_t_inari, lon_t_inari, &lat_w_inari, &lon_w_inari);
	fprintf(stdout,"東伏見稲荷神社 日本測地: %.6lf,%.6lf 世界測地: %.6lf,%.6lf\n",
		lat_t_inari, lon_t_inari, lat_w_inari, lon_w_inari);

	com_wgs84_to_tokyo(lat_w_inari, lon_w_inari, &lat_t_inari, &lon_t_inari);
	fprintf(stdout,"東伏見稲荷神社 世界測地: %.6lf,%.6lf 日本測地: %.6lf,%.6lf\n",
		lat_w_inari, lon_w_inari, lat_t_inari, lon_t_inari );

  return 0;
}
#endif /* _COM_GEO_MAIN */
