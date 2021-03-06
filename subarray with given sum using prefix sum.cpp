Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left
if sum equals to subarray, else print -1.

User Task:
The task is to complete the function subarraySum() which finds starting and ending positions(1 indexing) of first such occuring
subarray from the left if sum equals to subarray, else -1 is printed. The driver code automatically appends a new line


Input:
Input:
3
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
4 15
5 7 1 2
Output:
2 4
1 5
1 4


void subarraySum(int arr[], int n, int s){
    
    // Your code here
    int pre[n];
    pre[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+arr[i];
    }
    int j=-1;
    int i=1;
    int flag=0;
    pre[-1]=0;
    while(true)
    {
      if(pre[i]-pre[j]==s)
       {
           cout<<j+2<<" "<<i+1;
           flag=1;
           break;
       }
      else if(pre[i]-pre[j]<s)
       {
           i++;
       }
     else
     {
         j++;
     }
     
     if(i==n|| j==n)
      break;
    }
    
 if(pre[n-1]==s && flag==0)
     cout<<"1"<<" "<<n;
 else if(flag==0)
  cout<<"-1";
}

approach 2 :
we need to use Sliding window Method to solve this Problem.

Add the elements, to currsum till it is less than S. If it becomes more than S, start deleting elements from start in the cuusum. 
    if the currsum again becomes less than S, again start adding elements to it. In between also check, if the currsum becomes equal
    to S.
If yes, then output start and end index, else after traversing array no such solution is found, output -1.

The complete solution is in next hint.





void subarraySum(int ar[], int n, int s){
    // Your code he 
    int i=0;
    int j=0;
    int cursum=0;
    int flag=0;
    while(true)
    {
        if(cursum+ar[j]==s)
        {
            cout<<i+1<<" "<<j+1;
            flag=1;
            break;
        }
       else if(cursum+ar[j]>s)
       {
           
           cursum=cursum-ar[i];
           i++;
       }
      else
      {
          cursum=cursum+ar[j];
          j++;
      }
      
    if(i==n || j==n)
     break;
    }
    if(flag==0)
     cout<<"-1";
}

