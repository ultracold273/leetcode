
#include <stdio.h>

class Solution {
	public:
		int reverse(int x) {
			int idx = 0;
			int i, pos_flag;
			int res = 0;
			int prevRes = 1;
			char a_c[100];
			char * a;
			if(x > 0) {
				pos_flag = 0;
			}else if (x < 0) {
				pos_flag = 1;
				x = -x;
			}else{
				return 0;
			}

			while(x != 0) {
				a_c[idx] = x % 10;
				x = x / 10;
				idx++;
			}

			i = 0;
			while(a_c[i] == 0) {
				idx--;
				i++;
			}
			
			a = &a_c[i];
//			for (i = 0;i < idx;i++)
//				printf("%d ", a[i]);
//			printf("\n");
			
			if (idx >= 1) {
				res = a[0];
				prevRes = res;
				for (i = 1;i < idx;i++) {
					res = res * 10 + a[i];
					// Overflow detection
					printf("%d %d\n", res, prevRes);
					if (res / 10 != prevRes) return 0;
					prevRes = res;
				}
			}else{
				for (i = 0;i < idx; i++) {
					res = res * 10 + a[i];
				}
			}
			if (pos_flag == 1)
				res = -res;
			return res;
		}
};


int main(void) {
	Solution * a = new Solution();
	int i = 8192;
//	for(i = -500;i < -400;i++) {
//		printf("%d %d\n", i, a->reverse(i));
//	}
	printf("%d %d\n", i, a->reverse(i));
	return 0;
}
