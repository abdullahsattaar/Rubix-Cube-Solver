//       19L-1243, 19L-1248 Artificial Intelligence-6D Assignment1

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void takeInput(int*** initialstate, int*** finalState) {
	ifstream file("input.txt");
	if (file.is_open()) {
		int value = 0;
		while (!file.eof()) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						file >> value;
						initialstate[i][j][k] = value;
					}
				}
			}
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						file >> value;
						finalState[i][j][k] = value;
					}
				}
			}
		}
	}
	else cout << "Cannot open file" << endl;
}
void print(int*** arr)
{
	cout << "Printing " << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				cout << arr[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}
int*** rightAntiClock(int*** cube) {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[1][0][1] = cube[1][1][0];
	temp[1][1][0] = cube[1][2][1];
	temp[1][2][1] = cube[1][1][2];
	temp[1][1][2] = cube[1][0][1];

	temp[1][0][0] = cube[1][2][0];
	temp[1][2][0] = cube[1][2][2];
	temp[1][2][2] = cube[1][0][2];
	temp[1][0][2] = cube[1][0][0];

	temp[4][0][2] = cube[2][0][2];
	temp[4][1][2] = cube[2][1][2];
	temp[4][2][2] = cube[2][2][2];

	temp[2][0][2] = cube[5][0][2];
	temp[2][1][2] = cube[5][1][2];
	temp[2][2][2] = cube[5][2][2];

	temp[5][0][2] = cube[0][0][2];
	temp[5][1][2] = cube[0][1][2];
	temp[5][2][2] = cube[0][2][2];

	temp[0][0][2] = cube[4][0][2];
	temp[0][1][2] = cube[4][1][2];
	temp[0][2][2] = cube[4][2][2];

	return temp;
}
int*** upAntiClock(int*** cube) {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[4][0][1] = cube[4][1][0];
	temp[4][1][0] = cube[4][2][1];
	temp[4][2][1] = cube[4][1][2];
	temp[4][1][2] = cube[4][0][1];

	temp[4][0][0] = cube[4][2][0];
	temp[4][2][0] = cube[4][2][2];
	temp[4][2][2] = cube[4][0][2];
	temp[4][0][2] = cube[4][0][0];

	temp[3][0][0] = cube[2][0][0];
	temp[3][1][0] = cube[2][1][0];
	temp[3][2][0] = cube[2][2][0];

	temp[2][0][0] = cube[1][0][0];
	temp[2][1][0] = cube[1][1][0];
	temp[2][2][0] = cube[1][2][0];

	temp[1][0][0] = cube[0][0][0];
	temp[1][1][0] = cube[0][1][0];
	temp[1][2][0] = cube[0][2][0];

	temp[0][0][0] = cube[3][0][0];
	temp[0][1][0] = cube[3][1][0];
	temp[0][2][0] = cube[3][2][0];

	return temp;
}
int*** leftAntiClock(int*** cube)
{
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[3][0][1] = cube[3][1][2];
	temp[3][1][0] = cube[3][0][1];
	temp[3][2][1] = cube[3][1][0];
	temp[3][1][2] = cube[3][2][1];

	temp[3][0][0] = cube[3][0][2];
	temp[3][2][0] = cube[3][0][0];
	temp[3][2][2] = cube[3][2][0];
	temp[3][0][2] = cube[3][2][2];

	temp[4][0][0] = cube[0][0][0];
	temp[4][1][0] = cube[0][1][0];
	temp[4][2][0] = cube[0][2][0];

	temp[2][0][0] = cube[4][0][0];
	temp[2][1][0] = cube[4][1][0];
	temp[2][2][0] = cube[4][2][0];

	temp[5][0][0] = cube[2][0][0];
	temp[5][1][0] = cube[2][1][0];
	temp[5][2][0] = cube[2][2][0];

	temp[0][0][0] = cube[5][0][0];
	temp[0][1][0] = cube[5][1][0];
	temp[0][2][0] = cube[5][2][0];

	return temp;
}
int*** downAntiClock(int*** cube) {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[5][0][1] = cube[5][1][2];
	temp[5][1][0] = cube[5][0][1];
	temp[5][2][1] = cube[5][1][0];
	temp[5][1][2] = cube[5][2][1];

	temp[5][0][0] = cube[5][0][2];
	temp[5][2][0] = cube[5][0][0];
	temp[5][2][2] = cube[5][2][0];
	temp[5][0][2] = cube[5][2][2];

	temp[3][0][2] = cube[0][0][2];
	temp[3][1][2] = cube[0][1][2];
	temp[3][2][2] = cube[0][2][2];

	temp[2][0][2] = cube[3][0][2];
	temp[2][1][2] = cube[3][1][2];
	temp[2][2][2] = cube[3][2][2];

	temp[1][0][2] = cube[2][0][2];
	temp[1][1][2] = cube[2][1][2];
	temp[1][2][2] = cube[2][2][2];

	temp[0][0][2] = cube[1][0][2];
	temp[0][1][2] = cube[1][1][2];
	temp[0][2][2] = cube[1][2][2];

	return temp;
}
int*** frontAntiClock(int*** cube) {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[0][0][1] = cube[0][1][0];
	temp[0][1][0] = cube[0][2][1];
	temp[0][2][1] = cube[0][1][2];
	temp[0][1][2] = cube[0][0][1];

	temp[0][0][0] = cube[0][2][0];
	temp[0][2][0] = cube[0][2][2];
	temp[0][2][2] = cube[0][0][2];
	temp[0][0][2] = cube[0][0][0];

	temp[5][0][2] = cube[3][0][2];
	temp[5][1][2] = cube[3][1][2];
	temp[5][2][2] = cube[3][2][2];

	temp[3][0][2] = cube[4][0][2];
	temp[3][1][2] = cube[4][1][2];
	temp[3][2][2] = cube[4][2][2];

	temp[4][0][2] = cube[1][0][2];
	temp[4][1][2] = cube[1][1][2];
	temp[4][2][2] = cube[1][2][2];

	temp[1][0][2] = cube[5][0][2];
	temp[1][1][2] = cube[5][1][2];
	temp[1][2][2] = cube[5][2][2];

	return temp;
}
int*** backAntiClock(int*** cube) {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[2][0][1] = cube[2][1][2];
	temp[2][1][0] = cube[2][0][1];
	temp[2][2][1] = cube[2][1][0];
	temp[2][1][2] = cube[2][2][1];

	temp[2][0][0] = cube[2][0][2];
	temp[2][2][0] = cube[2][0][0];
	temp[2][2][2] = cube[2][2][0];
	temp[2][0][2] = cube[2][2][2];

	temp[4][0][0] = cube[3][0][0];
	temp[4][1][0] = cube[3][1][0];
	temp[4][2][0] = cube[3][2][0];

	temp[1][0][0] = cube[4][0][0];
	temp[1][1][0] = cube[4][1][0];
	temp[1][2][0] = cube[4][2][0];

	temp[5][0][0] = cube[1][0][0];
	temp[5][1][0] = cube[1][1][0];
	temp[5][2][0] = cube[1][2][0];

	temp[3][0][0] = cube[5][0][0];
	temp[3][1][0] = cube[5][1][0];
	temp[3][2][0] = cube[5][2][0];

	return temp;
}

void printStack(stack<int> s)
{
	
	while (!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << endl;
}
void printStackMoves(stack<int> s) 
{
	// rightAntiClock    1
	// leftAntiClock     2
	// frontAntiClock    3
	// backAntiClock     4
	// upAntiClock       5
	// downAntiClock     6

	if (s.empty() == true)
		cout << "Zero moves made cube is already 'Solved'.";
	while (!s.empty())
	{
		int p = s.top();
		if (p == 0)
		{
			cout << "Cube is already Solve kindly shuffle.";
		}
		else if (p == 1) {
			cout << "move Right Anti-ClockWise" << endl;
		}
		else if (p == 2) {
			cout << "move Left Anti-ClockWise" << endl;
		}
		else if (p == 3) {
			cout << "move Front Anti-ClockWise" << endl;
		}
		else if (p == 4) {
			cout << "move Back Anti-ClockWise" << endl;
		}
		else if (p == 5) {
			cout << "move Up Anti-ClockWise" << endl;
		}
		else if (p == 6) {
			cout << "move Down Anti-ClockWise" << endl;
		}

		s.pop();
	}
	cout << endl;


}


bool compareState(int*** currentState, int*** finalState)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (currentState[i][j][k] != finalState[i][j][k])
					return false;
			}
		}
	}
	return true;
}

int*** getfinalstate() {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}
	int value = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				temp[i][j][k] = value;
			}
		}
		value++;
	}
	return temp;
}
int*** getCube() {
	int*** temp;
	temp = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}
	return temp;
}

class node {
public:
	int*** curr;
	int prevMove;
	node* parent;
	vector<node*> child;

	node() {
		prevMove = 0;
		parent = nullptr;
		curr = new int**[6];
		for (int i = 0; i < 6; i++)
		{
			curr[i] = new int*[3];
			for (int j = 0; j < 3; j++)
			{
				curr[i][j] = new int[3];
			}
		}
	}

	void generateChild() {

		node* temp = new node[1];
		temp->curr = leftAntiClock(this->curr);
		temp->prevMove = 2;
		this->child.push_back(temp);

		temp->curr = rightAntiClock(this->curr);
		temp->prevMove = 2;
		this->child.push_back(temp);

		temp->curr = frontAntiClock(this->curr);
		temp->prevMove = 3;
		this->child.push_back(temp);

		temp->curr = backAntiClock(this->curr);
		temp->prevMove = 4;
		this->child.push_back(temp);

		temp->curr = upAntiClock(this->curr);
		temp->prevMove = 5;
		this->child.push_back(temp);

		temp->curr = downAntiClock(this->curr);
		temp->prevMove = 6;
		this->child.push_back(temp);	

	}
	void setCurrState(int*** c)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					this->curr[i][j][k] = c[i][j][k];
				}
			}
		}
	}

	int*** getCurrState() {
		return this->curr;
	}

	void setprevMove(int move) {
		this->prevMove = move;
	}

	int getprevMove() {
		return this->prevMove;
	}

	void setParent(node* p) {
		this->parent = p;
	}
	node* getParent() {
		return parent;
	}

	void addChild(node* c)
	{
		this->child.push_back(c);
	}

};

void addChilds(node* p, stack<node*>& s)
{
	// rightAntiClock    1
	// leftAntiClock     2
	// frontAntiClock    3
	// backAntiClock     4
	// upAntiClock       5
	// downAntiClock     6
	

	node* temp1 = new node[1];
	temp1->curr = rightAntiClock(p->curr);
	temp1->parent = p;
	temp1->prevMove = 1;
	p->addChild(temp1);
	s.push(temp1);

	node* temp2 = new node[1];
	temp2->curr = leftAntiClock(p->curr);
	temp2->parent = p;
	temp2->prevMove = 2;
	p->addChild(temp2);
	s.push(temp2);

	node* temp3 = new node[1];
	temp3->curr = frontAntiClock(p->curr);
	temp3->parent = p;
	temp3->prevMove = 3;
	p->addChild(temp3);
	s.push(temp3);

	node* temp4 = new node[1];
	temp4->curr = backAntiClock(p->curr);
	temp4->parent = p;
	temp4->prevMove = 4;
	p->addChild(temp4);
	s.push(temp4);

	node* temp5 = new node[1];
	temp5->curr = upAntiClock(p->curr);
	temp5->parent = p;
	temp5->prevMove = 5;
	p->addChild(temp5);
	s.push(temp5);

	node* temp6 = new node[1];
	temp6->curr = downAntiClock(p->curr);
	temp6->parent = p;
	temp6->prevMove = 6;
	p->addChild(temp6);
	s.push(temp6);
}

stack<int> bfsearch(node* current) {
	stack<node*> stk;
	stack<int> moves;
	queue<node*> visited;
	queue<node*> temp;
	stk.push(current);
	bool flag = true;
	bool flagvisited = false;
	while (flag == true) {
		while (stk.top() != 0) {
			if (compareState(stk.top()->getCurrState(), getfinalstate()) == false) {
				current->generateChild();
				while (visited.empty() != true)
				{
					if (visited.front() == current){
						flagvisited = true;
					}
					else
					{
						temp.push(visited.front());
						visited.pop();
						flagvisited = false;
					}
				}
				visited = temp;
				if (flagvisited == false)
					addChilds(current, stk);
			}
			else {
				flag = false;
				while (stk.empty() != true)
				{
					moves.push(stk.top()->getprevMove());
					stk.pop();
				}
				break;
			}
			stk.pop();
		}
	}
	return moves;
}
int main() {
	int*** initialstate;
	initialstate = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		initialstate[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			initialstate[i][j] = new int[3];
		}
	}
	int*** finalState;
	finalState = new int**[6];
	for (int i = 0; i < 6; i++)
	{
		finalState[i] = new int*[3];
		for (int j = 0; j < 3; j++)
		{
			finalState[i][j] = new int[3];
		}
	}
	takeInput(initialstate, finalState);

	node* initial = new node();
	initial->setCurrState(initialstate);
	printStackMoves(bfsearch(initial));

	system("pause");
	return 0;
}





//4 4 4 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5
//0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5