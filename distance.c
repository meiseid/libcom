/*
GPS 座標操作関係
2座標間の直線距離(M)を求める
math.h/sqrtを使うためライブラリリンク-lmをつける
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* double lat,lon=度単位10進数 例=35.910722,139.459500 */
extern double com_get_distance( double lat_fr, double lon_fr, double lat_to, double lon_to ) {

	/* ミリ秒表記に変換 */
	int xfr = (int)(lon_fr * 3600000.0);
	int yfr = (int)(lat_fr * 3600000.0);
	int xto = (int)(lon_to * 3600000.0);
	int yto = (int)(lat_to * 3600000.0);

	double xof = xto - xfr;
	double yof = yto - yfr;

	if( xof < 0 ) xof *= (-1);
	if( yof < 0 ) yof *= (-1);

	xof *= 2.5; xof /= 100; yof *= 3.0; yof /= 100;

	return sqrt( xof * xof + yof * yof );
}

/* TEST MAIN
gcc -D_COM_DISTANCE_MAIN distance.c -lm
*/
#ifdef _COM_DISTANCE_MAIN
extern int main(int argc, char **argv) {

	double lat_fr = 35.721421, lon_fr = 139.706520; //目白駅
	double lat_to = 35.726476, lon_to = 139.694641; //椎名町駅
	double lat_fr2 = 35.733193, lon_fr2 = 139.698789; //要町駅
	double lat_to2 = 35.743295, lon_to2 = 139.678404; //小竹向原駅

	double distance = com_get_distance(lat_fr, lon_fr, lat_to, lon_to);
	double distance2 = com_get_distance(lat_fr2, lon_fr2, lat_to2, lon_to2);

	fprintf(stdout,"目白駅～椎名町駅 約 %.lf M\n",distance);
	fprintf(stdout,"要町駅～小竹向原駅 約 %.lf M\n",distance2);

  return 0;
}
#endif /* _COM_DISTANCE_MAIN */
