#include<bits/stdc++.h>
using namespace std;
int fifo();
int LRU();
int optimal();
int main()
{
	int ch;
	cout<<"Choose algorithm\n";
	cout<<"\n1. LRU\n2. FIFO\n3. Optimal\n4. Exit\n";
	cout<<"\nEnter your choice=";
	cin>>ch;
	switch(ch)
	{
		case 1:
			LRU();
			break;
		case 2:
			  fifo();
			break;
		case 3:
			optimal();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"\nInvalid Choice";
			break;
	}
}

int fifo()
{
	int reference_string[25], page_faults = 0, m, n, s, pages, frames;
		      cout<<"\nEnter Total Number of Pages:\t";
		      cin>>pages;
		      cout<<"\nEnter values of Reference String:\n";
		      for(m = 0; m < pages; m++)
		      {
		            cout<<"Value No. ["<<m+1<<"]:\t";
		            cin>>reference_string[m];
		      }
		      cout<<"\nEnter Total Number of Frames:\t";
		      {
		            cin>>frames;
		      }
		      int temp[frames];
		      for(m = 0; m < frames; m++)
		      {
		            temp[m] = -1;
		      }
		      for(m = 0; m < pages; m++)
		      {
		            s = 0;
		            for(n = 0; n < frames; n++)
		            {
		                  if(reference_string[m] == temp[n])
		                  {
		                        s++;
		                        page_faults--;
		                  }
		            }     
		            page_faults++;
		            if((page_faults <= frames) && (s == 0))
		            {
		                  temp[m] = reference_string[m];
		            }   
		            else if(s == 0)
		            {
		                  temp[(page_faults - 1) % frames] = reference_string[m];
		            }
		            cout<<"\n";
		            for(n = 0; n < frames; n++)
		            {     
		                  cout<<temp[n]<<"\t";
		            }
		      } 
		      cout<<"\nTotal Page Faults:\t"<<page_faults<<"\n";	
}
int LRU()
{
	int frames[25], temp[25], pages[25];
      int total_pages, m, n, position, k, l, total_frames;
      int a = 0, b = 0, page_fault = 0;
      cout<<"\nEnter Total Number of Frames:\t";
      cin>>total_frames;
      for(m = 0; m < total_frames; m++)
      {
            frames[m] = -1;
      }
      cout<<"Enter Total Number of Pages:\t";
      cin>>total_pages;
      cout<<"Enter Values for Reference String:\n";
      for(m = 0; m < total_pages; m++)
      {
            cout<<"Value No.["<<m+1<<"]:\t";
            cin>>pages[m];
      }
      for(n = 0; n < total_pages; n++)
      {
            a = 0, b = 0;
            for(m = 0; m < total_frames; m++)
            {
                  if(frames[m] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        break;
                  }
            }
            if(a == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        if(frames[m] == -1)
                        {
                              frames[m] = pages[n];
                              b = 1;
                              page_fault++;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        temp[m] = 0;
                  }
                  for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                  {
                        for(m = 0; m < total_frames; m++)
                        {
                              if(frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                              }
                        }
                  }
                  for(m = 0; m < total_frames; m++)
                  {
                        if(temp[m] == 0)
                        position = m;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }
            cout<<"\n";
            for(m = 0; m < total_frames; m++)
            {
                  cout<<frames[m]<<"\t";
            }
      }
      cout<<"\nTotal Number of Page Faults:\t"<<page_fault<<"\n";
}
int optimal()
{
	int reference_string[25], frames[25], interval[25];
      int pages, total_frames, page_faults = 0;
      int m, n, temp, flag, found;
      int position, maximum_interval, previous_frame = -1;
      cout<<"\nEnter Total Number of Pages:\t";
      cin>>pages;
      cout<<"\nEnter Values of Reference String\n";
      for(m = 0; m < pages; m++)
      { 
            cout<<"Value No.["<<m+1<<"]:\t";
            cin>>reference_string[m];
      }
      cout<<"\nEnter Total Number of Frames:\t";
      cin>>total_frames;
      for(m = 0; m < total_frames; m++) 
      {
            frames[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            flag = 0;
            for(n = 0; n < total_frames; n++)
            {
                  if(frames[n] == reference_string[m])
                  {
                        flag = 1;
                        cout<<"\t";
                        break;
                  }
            }
            if(flag == 0) 
            {
                  if (previous_frame == total_frames - 1)
                  {
                        for(n = 0; n < total_frames; n++)
                        {      
                              for(temp = m + 1; temp < pages; temp++)
                              {      
                                    interval[n] = 0;
                                    if (frames[n] == reference_string[temp])
                                    {      
                                          interval[n] = temp - m;
                                          break;
                                    }
                              }
                        }
                        found = 0;
                        for(n = 0; n < total_frames; n++)
                        {
                              if(interval[n] == 0)
                              {                 
                                    position = n;
                                    found = 1;
                                    break;
                              }            
                        }
                  }
                  else
                  {
                        position = ++previous_frame;
                        found = 1;
                  }
                  if(found == 0)
                  {
                        maximum_interval = interval[0];
                        position = 0;
                        for(n = 1; n < total_frames; n++)
                        {
                              if(maximum_interval < interval[n])
                              {
                                    maximum_interval = interval[n];
                                    position = n;
                              }
                        }
                   }     
                   frames[position] = reference_string[m];
                   cout<<"FAULT\t";
                   page_faults++;
            }
            for(n = 0; n < total_frames; n++)
            {
                  if(frames[n] != -1) 
                  {
                        cout<<frames[n]<<"\t";
                  }
            }
            cout<<"\n";
      }
      cout<<"\nTotal Number of Page Faults:\t"<<page_faults<<"\n";
}



/*
OUTPUT FOR FIFO:
	
	
Choose algorithm

1. LRU
2. FIFO
3. Optimal
4. Exit

Enter your choice=2

Enter Total Number of Pages:    13

Enter values of Reference String:
Value No. [1]:  7
Value No. [2]:  0
Value No. [3]:  1
Value No. [4]:  2
Value No. [5]:  0
Value No. [6]:  3
Value No. [7]:  0
Value No. [8]:  4
Value No. [9]:  2
Value No. [10]: 3
Value No. [11]: 0
Value No. [12]: 3
Value No. [13]: 2

Enter Total Number of Frames:   4

7       -1      -1      -1
7       0       -1      -1
7       0       1       -1
7       0       1       2
7       0       1       2
3       0       1       2
3       0       1       2
3       4       1       2
3       4       1       2
3       4       1       2
3       4       0       2
3       4       0       2
3       4       0       2
Total Page Faults:      7

--------------------------------*/



/*
OUTPUT FOR OPTIMAL:



Choose algorithm

1. LRU
2. FIFO
3. Optimal
4. Exit

Enter your choice=3

Enter Total Number of Pages:    13

Enter Values of Reference String
Value No.[1]:   7
Value No.[2]:   0
Value No.[3]:   1
Value No.[4]:   2
Value No.[5]:   0
Value No.[6]:   3
Value No.[7]:   0
Value No.[8]:   4
Value No.[9]:   2
Value No.[10]:  3
Value No.[11]:  0
Value No.[12]:  3
Value No.[13]:  2

Enter Total Number of Frames:   4
FAULT   7
FAULT   7       0
FAULT   7       0       1
FAULT   7       0       1       2
        7       0       1       2
FAULT   3       0       1       2
        3       0       1       2
FAULT   3       0       4       2
        3       0       4       2
        3       0       4       2
        3       0       4       2
        3       0       4       2
        3       0       4       2

Total Number of Page Faults:    6

--------------------------------*/



/*
OUTPUT FOR LRU:
	
	
Choose algorithm

1. LRU
2. FIFO
3. Optimal
4. Exit

Enter your choice=1

Enter Total Number of Frames:
3
Enter Total Number of Pages:    12
Enter Values for Reference String:
Value No.[1]:   1
Value No.[2]:   2
Value No.[3]:   3
Value No.[4]:   4
Value No.[5]:   1
Value No.[6]:   2
Value No.[7]:   5
Value No.[8]:   1
Value No.[9]:   2
Value No.[10]:  3
Value No.[11]:  4
Value No.[12]:  5

1       -1      -1
1       2       -1
1       2       3
4       2       3
4       1       3
4       1       2
5       1       2
5       1       2
5       1       2
3       1       2
3       4       2
3       4       5
Total Number of Page Faults:    10

--------------------------------*/
