#define MAX_INT 2147483647
#define MIN_INT -2147483648

int reverse (int x) {
	 int result = 0;
	 int yushu;

	 while (x != 0) {
		  yushu %= x;

		  if (result > MAX_INT / 10 || (result == MAX_INT/10 && yushu > 7))
			  return 0;
		  /*
		   * 分析：1 为什么只要result 一大于 MAX_INT/10 就溢出呢？
		   * 	     因为下面result*10 还要加余数就会超过MAX_INT，所以会溢出
		   * 	   2 result == MAX_INT/10 && yushu 一样，下面 25行一执行result
		   * 	     就会超过MAX_INT的，
		   * 	   ** 以下也是一样的，
		   * */
		  if (result < MIN_INT / 10 || (result == MIN_INT/10 && yushu < -8))
			  return 0;

		  result = result*10 + yushu;
		  x /= 10;
	 }
	 return x;
}
