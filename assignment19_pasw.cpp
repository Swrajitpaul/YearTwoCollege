#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

string teams(string t){
	sort(t.begin(),t.end());
	auto s=unique(t.begin(),t.end());
	return string(t.begin(),s);;
};

bool valid(string t){
	int n=count(t.begin(), t.end(),t[0]);
	for(auto i:t)
		if(count(t.begin(), t.end(),i)!=n)
			return false;
	return true;
};

double score(char team, string race){
	double c=count(race.begin(),race.end(),team);
	double s=0;
	for(int i=0;i<race.length();i++)
		if(race[i]==team)
		s+=i+1;
	return s/c;
};

int main(){
	string race;
	while(cin>>race!="done"){
		if(!valid(race)){
			cout<<"Invalid input - try again"<<endl;
			cin>>race;
			continue;
		}

		if(race=="done")
			return 0;
	
		string t=teams(race);
		cout<<"the teams and scores are "<<endl;
		ostream_iterator<char> o(cout,",");
		copy(t.begin(), t.end(),o);
		cout<<endl;
		cout<<"Teams with score "<<endl;
		sort(t.begin(),t.end(),score);
		vector<double> m;
		for( auto i:t){
			double s =score(i,race);
			m.push_back(s);
			cout<<"Team: "<<i<<" "<<s<<endl;
		}
	cout<<"winning score= "<<max(m)<<endl;
	}
}
