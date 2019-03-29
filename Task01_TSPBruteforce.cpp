#include<bits/stdc++.h>
using namespace std;

#define pb push_back

/*
	Nuril Kaunaini Rofiatunnajah
	1301180117
*/

int awal=18, akhir=6;
vector<int> tetangga[100];
int dist[100][100];
bool masukPath[100];
vector<int> ansPath;
int ans=1000;
int n;
void visit(vector<int> path, int now){ // path : rute sampai saat ini, now : node sekarang

	path.pb(now); // node now dimasukan ke rute

	if (path.size()==n){ //semua kota udah di kunjungi

		int totalDist=0; //total jarak menggunakan rute ini
		for (int i=1;i<path.size();i++){
			int A = path[i];
			int B = path[i-1];
			totalDist+= ( dist[A][B] );
		}

		if (totalDist<ans){ //jika total jarak sekarang lebih kecil dari jawaban, maka jarak total sekaranglah jawabannya
			ans=totalDist;
			ansPath=path;
		}

		masukPath[akhir]=false;
		return;

	}
		for (int i=0;i<tetangga[now].size();i++){

			int next=tetangga[now][i];
			if (!masukPath[next]){ //jika node selanjutnya belum ada di path,
				masukPath[next]=true;
				visit(path,next); //visit node selanjutnya
			}

		}
	

	masukPath[now]=false;
	return;
}

int main (){
	memset(masukPath, 0, sizeof(masukPath));
	cin>>n;
	for (int i=1;i<=n;i++){
		char A, B;
		int cost;
		cin>>A>>B>>cost;

		int P=int(A-'A'), Q=int(B-'A');

		tetangga[P].pb(Q);
		tetangga[Q].pb(P);

		dist[P][Q]=cost;
		dist[Q][P]=cost;
	}


	masukPath[awal]=true;

	visit(ansPath,18);

	cout<<"Jarak Terpendek : "<<ans<<endl;
	cout<<"Dengan Rute : S";
	for (int i=1;i<ansPath.size();i++){
		cout<<" -> "<<char(ansPath[i]+'A');
	}
	cout<<endl;
}
