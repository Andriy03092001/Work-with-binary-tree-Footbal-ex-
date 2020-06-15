#include<iostream>
#include "Tree.h"
#include<ctime>
using namespace std;



Tree game;

void Game(char Commands[][20], int N)
{
	int p1 = 0;
	int p2 = 0;

	Element* temp;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < N-1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				temp = new Element;
				if (k == 0) {
					strcpy(temp->name, Commands[i]);
					strcpy(temp->opponent, Commands[j]);
				}
				else {
					strcpy(temp->name, Commands[i]);
					strcpy(temp->opponent, Commands[j]);
				}

				p1 = rand() % 6;
				p2 = rand() % 6;

				if (p1 > p2) {
					temp->ownerPoints = 3;
					temp->oppPoints = 0;
				}
				else if (p1 == p2) {
					temp->ownerPoints = 1;
					temp->oppPoints = 1;
				}
				else {
					temp->ownerPoints = 0;
					temp->oppPoints = 3;
				}
				game.Insert(temp);

			}
		}
	}
}



int main() {

	srand(time(NULL));

	const int N = 4;
	char Commands[4][20] = {
		"Arsenal",
		"Shahtar",
		"Liverpul",
		"la la la la"
	};

	Game(Commands, N);
	game.Print(game.getRoot());



	return 0;
}