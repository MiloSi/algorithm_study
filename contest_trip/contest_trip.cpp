#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#define DEPART "Departure"
#define ARRIV "Arrival"
int tc, c, t, ti;
using namespace std;
typedef struct TABLE {
	string name;
	int start, end;
}Table;

typedef struct CITY {
	string name;
	vector<Table> times_table;
}City;
int dest_dp[100];
pair<int, int> back_track[100];

string city, time;
string start, dest;
int start_time, dest_time;
map<string, int> cities;
vector<City> timeTable;

typedef struct _NODE {
	int start, end, idx;
}Node;


//pair<int, int> first is dest time, second is node index
struct myrule {
	bool operator()(Node a, Node b) {
		if (a.end == b.end) {
			return a.start < b.start;
		}
		return a.end > b.end;
	}
};


int string_to_int(string s) {
	int t_h = s[0] - '0';
	int h = s[1] - '0';
	int t_m = s[2] - '0';
	int m = s[3] - '0';
	return (t_h * 10 + h) * 60 + (t_m * 10 + m);
}
string int_to_string(int i) {
	char t_h = '0' + (i / 600);
	i = i % 600;
	char h = '0' + (i / 60);
	i = i % 60;
	char t_m = '0' + (i / 10);
	i = i % 10;
	char m = '0' + i;

	string s;
	s.resize(4);
	s[0] = t_h;
	s[1] = h;
	s[2] = t_m;
	s[3] = m;
	return s;
}

#define MAX_NUM 0x1ffffff

void dijkstra(int idx1, int idx2) {
	dest_time = MAX_NUM;
	int num_size = c;
	for (int i = 0; i < c; i++) {
		dest_dp[i] = MAX_NUM;
	}
	priority_queue<Node, vector<Node>, myrule> pq;
	Node nd = { 0, start_time, idx1 };
	pq.push(nd);
	while (pq.size() > 0 && num_size > 0) {
		int startTime = pq.top().start;
		int destTime = pq.top().end;
		int index = pq.top().idx;
		pq.pop();
		if (dest_dp[index] != MAX_NUM) continue;
		dest_dp[index] = destTime;
		num_size--;
		for (auto tb : timeTable[index].times_table) {
			if (tb.start < destTime) continue;
			int dest_index = cities.find(tb.name)->second;
			if (dest_dp[dest_index] > tb.end) {
				Node nd1 = { tb.start, tb.end, dest_index };
				back_track[dest_index] = { index, tb.start };
				pq.push(nd1);
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> tc;
	cerr << tc << endl;
	for (int ts = 1; ts <= tc; ts++) {
		cin >> c;
		cerr << c << endl;
		timeTable.resize(c);
		for (int i = 0; i < c; i++) {
			cin >> city;
			cerr << city << endl;
			timeTable[i].name = city;
			cities.insert(make_pair(city, i));
		}		
		cin >> t;
		for (int i = 0; i < t; i++) {
			string time_1, city_1, time_2, city_2;
			int idx1, idx2;
			cin >> ti;
			cerr << ti << endl;
			cin >> time_1 >> city_1;
			cerr << time_1 << " " << city_1 << endl;
			int _Time = string_to_int(time_1);
			for (int j = 1; j < ti; j++) {
				idx1 = cities.find(city_1)->second;
				Table tb;
				cin >> time_2 >> city_2;
				cerr << time_2 << " " << city_2 << endl;
				int _Time2 = string_to_int(time_2);
				idx2 = cities.find(city_2)->second;

				tb = { city_2, _Time, _Time2 };
				timeTable[idx1].times_table.push_back(tb);
				city_1 = city_2;
				idx1 = idx2;
				_Time = _Time2;
			}
		}
		cin >> time >> start >> dest;
		cerr << time << endl << start << endl << dest << endl << endl;
		
		start_time = string_to_int(time);
		int idx1, idx2;
		idx1 = cities.find(start)->second;
		idx2 = cities.find(dest)->second;

		dijkstra(idx1, idx2);
		if (dest_dp[idx2] != MAX_NUM) {
			int temp = idx2; 

			while (temp != idx1) {
				if (back_track[temp].first == idx1) break;
				temp = back_track[temp].first;
			}
			start_time = back_track[temp].second;

			// show result
			cerr.width(10);
			cerr << DEPART;
			cerr.width(10);
			cerr << start;
			cerr.width(10);
			cerr << int_to_string(start_time) << endl;
			cerr.width(10);
			cerr << ARRIV;
			cerr.width(10);
			cerr << start;
			cerr.width(10);
			cerr << int_to_string(dest_dp[idx2]) << endl << endl;

			cout << DEPART << " " << start << " " << int_to_string(start_time) <<  endl;
			cout << ARRIV << " " << dest << " " <<int_to_string(dest_dp[idx2]) << endl;
		}
		else {
			cout << "No connection" << endl; 
			cerr << "No connection" << endl;
		}

		//clear
		for (int i = 0; i < c; i++) {
			back_track[i].first = back_track[i].second = 0;
		}
		cities.clear();
		timeTable.clear();
	}
	return 0;
}