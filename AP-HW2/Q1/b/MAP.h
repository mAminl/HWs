#ifndef MAP_H
#define MAP_H


class MAP {
public:

	MAP(int n);
	void showmap();
	void findroute();
	void showroute();
	~MAP();
private:

	int N;
	int ** main_map;

};

#endif