//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct note{
	int x;
	int y;
};

struct ene{
    int x;
    int nx;
    int y;
    int ny;
    int d;
};

int map[100][100];
int visit[100][100];
int en_visit[100][100];
int ans;

queue<struct note> que;
vector<struct note> dis;
vector<struct ene> en;

bool en_walk(int x, int y)
{
    return (map[x][y]!=0 && x>=0 && y>=0 && x<100 && y<100);
}

void up_dis()
{
    vector<struct note>::iterator it = dis.begin();
    for(it; it != dis.end(); ++it)
    {
    	if(map[it->x][it->y] == 1)
    	{
    		map[it->x][it->y] = 3;
		}
    }
}

void up_en(int time)
{
    vector<struct ene>::iterator it = en.begin();
    for(it; it != en.end(); ++it)
    {
    	if(en_visit[it->x][it->y] < time)
        {
           	map[it->x][it->y] = 1;
		}
        
        if(it->nx == -1)
        {
            it->d++;
            if(it->d > 7)
            {
                it->d = 4;
            }
        }
        else
        {
            it->x = it->nx;
            it->y = it->ny;
        }
        

        if(it->d ==4) //up
        {
            if(en_walk(it->x, it->y-1))
            {
                it->nx = it->x;
                it->ny = it->y-1;
            }
            else
            {
                it->nx = -1;
            }
        }
        else if(it->d ==5) //right
        {
            if(en_walk(it->x+1, it->y))
            {
                it->nx = it->x+1;
                it->ny = it->y;
            }
            else
            {
                it->nx = -1;
            }
        }
        else if(it->d ==6) //down
        {
            if(en_walk(it->x, it->y+1))
            {
                it->nx = it->x;
                it->ny = it->y+1;
            }
            else
            {
            	//cout << "ppp" << it->x << " " << it->y+1 << " " << map[it->x][it->y+1] << "\n";
                it->nx = -1;
                
            }
        }
        else //left
        {
            if(en_walk(it->x-1, it->y))
            {
                it->nx = it->x-1;
                it->ny = it->y;
            }
            else
            {
                it->nx = -1;
            }
        }
        
        map[it->x][it->y] = it->d;
        en_visit[it->x][it->y] = time;
        if(it->nx != -1)
        {
            map[it->nx][it->ny] = it->d;
            en_visit[it->nx][it->ny] = time;
        }
    }
}

bool walk(int x, int y)
{
    return (map[x][y]==1 && x>=0 && y>=0 && x<100 && y < 100);
}

void bfs(int time)
{
    int size = que.size();
    for (int i = 1; i <= size; i++)
    {
        struct note f, tf;
        f = que.front();
        int x = f.x;
        int y = f.y;
        que.pop();
        if(map[x+1][y] == 3 || map[x-1][y] == 3 || map[x][y+1] == 3 || map[x][y-1] == 3)
        {
            ans = time;
        }

        if(visit[x][y] < time)
        {
            if(walk(x, y))
            {
                visit[x][y] = time;
                que.push(f);
            }
        }
        if(visit[x+1][y] < time)
        {
            if(walk(x+1, y))
            {
                tf = f;
                tf.x++;
                que.push(tf);
                visit[x+1][y] = time;
            }
        }
        if(visit[x-1][y] < time)
        {
            if(walk(x-1, y))
            {
                tf = f;
                tf.x--;
                que.push(tf);
                visit[x-1][y] = time;
            }
        }
        if(visit[x][y+1] < time)
        {
            if(walk(x, y+1))
            {
                tf = f;
                tf.y++;
                que.push(tf);
                visit[x][y+1] = time;
            }
        }
        if(visit[x][y-1] < time)
        {
            if(walk(x, y-1))
            {
                tf = f;
                tf.y--;
                que.push(tf);
                visit[x][y-1] = time;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m, t;
    struct note p;
    struct ene e;
    cin >> n >> m >> t;
    ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[j][i];
            if(map[j][i] == 2)
            {
                map[j][i] = 1;
                p.x = j;
                p.y = i;
                que.push(p);
            }
            if(map[j][i] == 3)
            {
                map[j][i] = 3;
                p.x = j;
                p.y = i;
                dis.push_back(p);
            }
            else if(map[j][i] >= 4)
            {
                e.x = j;
                e.y = i;
                e.nx = j;
                e.ny = i;
                e.d = map[j][i];
                en.push_back(e);
            }
		}
	}
//	cout << "\n";
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << map[j][i] << " ";
//		}
//		cout << "\n";
//	}

//    vector<struct ene>::iterator it = en.begin();
//	for(it; it != en.end(); ++it)
//	{
//		cout << it->x << ", " << it->y << ", " << it->nx << ", " << it->ny << ", " << it->d << "\n";
//	}
    for(int ti = 1; ti <= t; ti++)
    {
        up_en(ti);
		up_dis();
		
//        cout << "\n" << "------------------------" << "\n";
//        for (int i = 0; i < n; i++)
//	    {
//		    for (int j = 0; j < m; j++)
//            {
//                cout << map[j][i] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//        for (int i = 0; i < n; i++)
//	    {
//		    for (int j = 0; j < m; j++)
//            {
//                cout << en_visit[j][i] << " ";
//            }
//            cout << "\n";
//        }
//        vector<struct ene>::iterator it = en.begin();
//    	for(it; it != en.end(); ++it)
//    	{
//    		cout << it->x << ", " << it->y << ", " << it->nx << ", " << it->ny << ", " << it->d << "\n";
//    	}
        
        
        
        bfs(ti);
        
//        cout << "\n";
//        for (int i = 0; i < n; i++)
//	    {
//		    for (int j = 0; j < m; j++)
//            {
//                cout << visit[j][i] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n" << "------------------------" << "\n";
        
        
        if(ans != -1)
        {
            break;
        }
        if(que.size() <= 0)
        {
            break;
        }
    }
    
    cout << ans << "\n";


	return 0;
}
