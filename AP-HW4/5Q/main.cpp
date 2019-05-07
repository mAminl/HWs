#include<iostream>
#include<memory>
#include<cstring>
#include"Stack.h"
#include"CText.h"

int main()
{
Stack<std::shared_ptr<CText>> stack;
std::string base{"TEXT"};

for(char a{'A'}; a <= 'Z'; a++)
stack.push(std::make_shared<CText>(base + a));

//Pop everything out
int N{stack.getCount()};
if(stack.isEmpty())
{
	std::cout << "Stack is empty" << std::endl;
	return -1;
}

for(int i{}; i < N; i++)
	std::cout << stack.pop()->getText() << std::endl;

if(stack.isEmpty())
	std::cout << "Stack is empty" << std::endl;

return 0; }