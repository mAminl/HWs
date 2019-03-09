#ifndef MAP_H
#define MAP_H


class MAP {
public:

	MAP(int n);
	void showmap();
	void AllRoutes();
	void FindBest();
	long long factorial(int n);
	void showroute();
	~MAP();

private:
	int N; // size of map
	int F; // answer of n!
	int ** main_map;
	char ** all_route;


};

#endif