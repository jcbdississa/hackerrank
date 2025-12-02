/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/cpp-sets/problem?isFullScreen=true
 * 
 * Problem : Coming to the problem, you will be given Q queries. Each query is of one of the following
 *           three types:
 *           1 x : Add an element x to the set
 *           2 x : Delete an element x x from the set. If the number x is not present in the set,
 *                 then do nothing.
 *           3 x : If the number x is present in the set, then print "Yes"(without quotes) else print
 *                 "No"(without quotes).
 *****************************************************************************************************/

#include <iostream>
#include <deque>
#include <algorithm> 
using namespace std;

void printKMax_v0(int arr[], int n, int k){
	//Write your code here.
    deque<int> my_q;
    for (int i = 0; i < n; i++) {
        if (i >= (k - 1)) {
            my_q.push_back(arr[i]);
            cout<<*(max_element(my_q.begin(), my_q.end()))<<" ";
            my_q.pop_front();
        } else {
            my_q.push_back(arr[i]);
        }
    }
    cout<<endl;
}

void printKMax_v1(int arr[], int n, int k){
	//Write your code here.
	deque<int> my_q;
	for (int i = 0; i < n; i++) {
		if (i >= (k - 1)) {
			my_q.push_back(arr[i]);
			printf("%d ", *(max_element(my_q.begin(), my_q.end())));
			my_q.pop_front();
		} else {
			my_q.push_back(arr[i]);
		}
	}
	printf("\n");
}

void printKMax_v2(int arr[], int n, int k){
	//Write your code here.
    deque<int> my_q;
    int max_val = 1;
    int cur_val = 0;
    for (int i = 0; i < n; i++) {
        cur_val = arr[i];    
        my_q.push_back(arr[i]);
        if (max_val < cur_val)
            max_val = cur_val;

        if (i >= (k - 1)) {
            if (find(my_q.begin(), my_q.end(), max_val) == my_q.end()) {
                max_val = *max_element(my_q.begin(), my_q.end());
            }
            my_q.pop_front();
            cout<<max_val<<" ";
        }
    }
    cout<<endl;
}

void printKMax(int arr[], int n, int k){
	//Write your code here.
	// Source of this code : https://www.hackerrank.com/rest/contests/master/challenges/deque-stl/hackers/akshat91/download_solution?primary=true
    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int>  Qi(k);
 
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();  // Remove from rear
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
 
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
         // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    cout << arr[Qi.front()] << endl;
}

int main(){
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

/*
Sample input
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
Expected output
4 6 6 4
8 8 8 10
*/