#include <iostream>
using namespace std;
int main()
{
	unsigned int a=0x00000011;
	printf("%X\n", a);
	_asm
	{
		ror a,1;
	}
	printf("%X\n",a);

	a=0x00000011;
	//a=a>>1<<1;
	printf("%X\n",a&0x1);


	system("pause");
	return 0;
}