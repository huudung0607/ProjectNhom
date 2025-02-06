//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//using namespace std;
//struct Questions
//{
//	string cauhoi;
//	string traloi;
//	char dapan;
//};
//int main()
//{
//	ifstream file("questions.txt", ios::out);
//	if (!file.is_open())
//	{
//		cout << "Khong the mo tep cau hoi";
//	}
//	string line;
//	int cnt = 0;
//	vector <string> questions;
//	vector<char> answers;
//	while (getline(file, line))
//	{
//		cnt++;
//		if (cnt <= 5)
//		{
//			questions.push_back(line);
//		}
//		if (cnt == 6)
//		{
//			answers.push_back(line[0]);
//			cnt = 0;
//		}
//	}
//	Questions q;
//	vector<Questions> ques;
//	for (int i = 0; i < questions.size(); i++)
//	{
//		if (i % 5 == 0)
//		{
//			q.cauhoi = questions[i];
//		}
//		else
//		{
//			q.traloi = questions[i];
//		}
//		ques.push_back(q);
//	}
//	for (auto x : ques)
//	{
//		cout << x.cauhoi << endl;
//	}
//	file.close();
//}