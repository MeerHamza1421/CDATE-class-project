#include "CDATE.h"
using namespace std;
int main()
{
	CDATE obj;
	obj.readfromKB().print(3);
	obj.setMindate(1,2,2020);
	obj.print(3);

}