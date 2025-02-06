#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;
struct Questions
{
	string cauhoi;
	string traloi;
	char dapan;
	char userdapan;
};
int main()
{
	ifstream file("questions.txt", ios::out);
	if (!file.is_open())
	{
		cout << "Cannot open file ";
	}
	time_t startTime = time(0);
	tm startTm;
	localtime_s(&startTm, &startTime);
	cout << "Start time: "
		<< 1900 + startTm.tm_year << '-'
		<< setw(2) << setfill('0') << 1 + startTm.tm_mon << '-'
		<< setw(2) << setfill('0') << startTm.tm_mday << ' '
		<< setw(2) << setfill('0') << startTm.tm_hour << ':'
		<< setw(2) << setfill('0') << startTm.tm_min << ':'
		<< setw(2) << setfill('0') << startTm.tm_sec << endl;
	cout << endl;
	string line;
	vector<string> questions;
	vector<Questions> ques;
	while (getline(file,line))
	{
		questions.push_back(line);
	}
	for (int i = 0; i < questions.size(); i+=6)
	{
		Questions q;
		q.cauhoi = questions[i];
		q.traloi = questions[i + 1] + "\n" + questions[i + 2] +  "\n" + questions[i + 3] + "\n"
		+ questions[i + 4];
		q.dapan = questions[i + 5][0];
		ques.push_back(q);
	}
	int cnt = 0;
	for (int i = 0; i < ques.size(); i++)
	{
		cout << ques[i].cauhoi << endl;
		cout << ques[i].traloi << endl;
		cout << "Your choice : ";
		cin >> ques[i].userdapan;
		if (toupper(ques[i].userdapan) == toupper(ques[i].dapan))
		{
			cnt++;
		}
		cout << endl;
	}
	time_t endTime = time(0);
	tm endTm;
	localtime_s(&endTm, &endTime);
	cout << "End time: "
		<< 1900 + endTm.tm_year << '-'
		<< setw(2) << setfill('0') << 1 + endTm.tm_mon << '-'
		<< setw(2) << setfill('0') << endTm.tm_mday << ' '
		<< setw(2) << setfill('0') << endTm.tm_hour << ':'
		<< setw(2) << setfill('0') << endTm.tm_min << ':'
		<< setw(2) << setfill('0') << endTm.tm_sec << endl;
	double elapsedSeconds = difftime(endTime, startTime);
	cout << "Elapsed time: " << elapsedSeconds << " seconds" << endl;
	cout << "YOUR GRADES : " << cnt << "/" << ques.size() << endl;
	file.close();
}
