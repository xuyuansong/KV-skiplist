#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "./src/SkipList.h"

#define MAX_NUM 10000
SkipList<int, std::string> skiplist(18);

using namespace std;

int main()
{
	for(int i = 0;i<MAX_NUM ; i++)
	{
		skiplist.insert_node(i,"张三");
	}
	skiplist.select_node(100);
	skiplist.delete_node(100);
	skiplist.select_node(100);
	
	return 0;
}
