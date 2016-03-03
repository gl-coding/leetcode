#include "convert.h"

int mySqrt(int x) {
	int begin = 0;
	int end = x;
	int mid = 0;
	long tmp = 0;
	while (begin < end){
		mid = begin + (end - begin)/2;
		tmp = mid*mid;
		if (tmp == x){
			return mid;
		}
		else if (tmp > x){
			end = mid-1;
		}
		else {
			begin = mid+1;
		}
	}
		tmp = end*end;  
    if(tmp > x)  
        return end-1;        
    else  
          return end; 
}

int main()
{
    cout<<"asdfas"<<endl;
    cout << mySqrt(2147395599);
    return 1;
}
